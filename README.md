# cpp-module-03
This module is designed to help you understand inheritance in C++.

# C++ Inheritance Modes — Quick Cheat Sheet 🧬

**Mental model:**

* `Human` = base class
* `Warrior` = derived class

---

## 1) `public` — **“Warrior IS a Human”** ✅

```cpp
class Warrior : public Human {};
```

### ✅ What works (outside code)

```cpp
void greet(Human& h);

Warrior w;
greet(w);        // ✅ OK (is-a)
Human* p = &w;   // ✅ OK
Human& r = w;    // ✅ OK
```

### 🧠 When to use

* Classic OOP **is-a** relationship
* Typical for school exercises (`ScavTrap` is-a `ClapTrap`)

---

## 2) `protected` — **“Outside: NOT Human, but for subclasses: yes”**

```cpp
class Warrior : protected Human {};
```

### ❌ Forbidden (outside code)

```cpp
void greet(Human& h);

Warrior w;
greet(w);        // ❌ ERROR (outside can’t treat Warrior as Human)
Human* p = &w;   // ❌ ERROR
Human& r = w;    // ❌ ERROR
```

### ✅ What you *can* do

#### 1) Use `Warrior` as its own type

```cpp
void train(Warrior& w);

Warrior w;
train(w);        // ✅ OK
```

#### 2) Inside `Warrior` you can access base members

```cpp
class Warrior : protected Human
{
public:
    void demo()
    {
        attack();        // ✅ if attack() was public/protected in Human
        hitPoints = 10;  // ✅ if hitPoints was protected in Human
    }
};
```

#### 3) Inside a subclass of `Warrior` you can still access base members

```cpp
class EliteWarrior : public Warrior
{
public:
    void demo()
    {
        attack();        // ✅ base is visible as protected
        hitPoints = 99;  // ✅ if it was protected in Human
    }
};
```

### 🧠 When to use

* Rare
* You want to **hide “is-a” from outside**, but keep base доступным для наследников

---

## 3) `private` — **“Warrior is NOT Human; it just uses Human internally”** 🔒

```cpp
class Warrior : private Human {};
// For `class`, this is the default:
class Warrior : Human {}; // ❗ private inheritance by default
```

### ❌ Forbidden (outside code)

```cpp
void greet(Human& h);

Warrior w;
greet(w);        // ❌ ERROR
Human* p = &w;   // ❌ ERROR
Human& r = w;    // ❌ ERROR
```

### ❌ Forbidden (even for subclasses of `Warrior`)

```cpp
class EliteWarrior : public Warrior
{
public:
    void demo()
    {
        attack();        // ❌ ERROR (Human part became private inside Warrior)
        hitPoints = 99;  // ❌ ERROR
    }
};
```

### ✅ What you *can* do

#### 1) Inside `Warrior` you can use the base (implementation detail)

```cpp
class Warrior : private Human
{
public:
    void demo()
    {
        attack();        // ✅ OK inside Warrior
        hitPoints = 10;  // ✅ if protected in Human
    }
};
```

#### 2) Expose only what you want (wrapper / selective re-export)

```cpp
class Warrior : private Human
{
public:
    using Human::attack; // ✅ make only this base method public

    void specialMove();
};
```

Or forward manually:

```cpp
class Warrior : private Human
{
public:
    void attackPublic(const std::string& target)
    {
        attack(target);  // ✅ call base inside
    }
};
```

### 🧠 When to use

* Rare (often composition is better)
* When inheritance is **only for code reuse**, not for “is-a”

---

## Default rule (VERY IMPORTANT) ⚠️

```cpp
class A : B {};   // = private inheritance (default)
struct A : B {};  // = public inheritance (default)
```

---

## Ultra-short summary

* `public`    → **IS-A**
* `protected` → **IS-A only for subclasses**
* `private`   → **implementation detail (code reuse), not IS-A**


# C++ OOP Keywords (Inheritance & Polymorphism) — Quick Cheat Sheet 🧩

> A compact list of keywords/idioms that matter most around inheritance.

---

## 1) `virtual` (methods) — **polymorphism** 🎭

If a base method is `virtual`, a call through `Base&` / `Base*` will dispatch to the derived override.

```cpp
class Base {
public:
    virtual void speak();
};

class Der : public Base {
public:
    void speak() override;
};
```

**Why:** “one interface — multiple implementations”.

---

## 2) `override` — **compile-time check that you really override** ✅

```cpp
void speak() override;
```

If the signature doesn’t match exactly (params, `const`, refs, etc.), you get a compile error.

---

## 3) `final` — **prevent inheritance / prevent further overrides** 🧱

### Class can’t be inherited:

```cpp
class Boss final {};
```

### Method can’t be overridden further:

```cpp
class Base {
public:
    virtual void speak() final;
};
```

---

## 4) `virtual` destructor — **safe delete via base pointer** 🧨

If you have polymorphism (virtual methods) and you might do `delete basePtr;`, the base destructor should almost always be `virtual`.

```cpp
class Base {
public:
    virtual ~Base();
};

class Der : public Base {
public:
    ~Der();
};

Base* p = new Der();
delete p; // ✅ calls ~Der(), then ~Base()
```

Without `virtual ~Base()` you risk only `~Base()` being called.

---

## 5) `protected` — **visible to derived classes, hidden from outside** 🛡️

```cpp
class Base {
protected:
    int hp;
};
```

**Idea:** derived classes can access it; external code cannot.

---

## 6) `using Base::method;` — **keep overloads visible / selectively re-export** 🔎

A derived method with the same name can hide base overloads (name hiding).

```cpp
class Base {
public:
    void attack(int);
    void attack(double);
};

class Der : public Base {
public:
    using Base::attack; // ✅ bring base overloads back into scope

    void attack(const char*);
};
```

Also handy with `private` inheritance: you can expose only specific base methods.

---

## 7) `explicit` (constructors) — **block implicit conversions** 🚫

```cpp
class Money {
public:
    explicit Money(int cents);
};

Money m = 42;   // ❌ not allowed
Money m2(42);   // ✅ allowed
```

---

## 8) `= delete` / `= default` — **control copy/assignment** 🧰

```cpp
class Base {
public:
    Base() = default;
    Base(const Base&) = delete;
    Base& operator=(const Base&) = delete;
    virtual ~Base() = default;
};
```

**Why:** some bases must not be copyable (resources, ownership, etc.).

---

## 9) `Base::method()` — **explicitly call the base version** 🎯

Useful with overriding / multiple inheritance.

```cpp
void Der::attack(const std::string& target)
{
    Base::attack(target); // call base implementation
}
```

---

## Tiny reminder: `virtual` has 2 different meanings in C++ ⚠️

* `virtual` **on methods** → polymorphism (`override` / `final`)
* `virtual` **in inheritance** (`class A : virtual public B`) → a single shared base in the “diamond”
