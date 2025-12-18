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
