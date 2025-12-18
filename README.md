# C++ Module 03 – Inheritance & Diamond Problem 🧬💎

✅ **Status**: Completed – all mandatory exercises
🏫 **School**: 42 – C++ Modules (Module 03)

> *Single inheritance, multiple inheritance, method overriding, base/derived behavior, and the classic “diamond” problem.*

---

## 📚 Table of Contents

* [Description](#-description)
* [Goals of the Module](#-goals-of-the-module)
* [Exercises Overview](#-exercises-overview)

  * [ex00 – ClapTrap](#ex00--claptrap)
  * [ex01 – ScavTrap](#ex01--scavtrap)
  * [ex02 – FragTrap](#ex02--fragtrap)
  * [ex03 – DiamondTrap](#ex03--diamondtrap)
* [Requirements](#-requirements)
* [Build & Run](#-build--run)
* [Repository Layout](#-repository-layout)
* [Testing Tips](#-testing-tips)
* [Quick Cheat Sheets](#-quick-cheat-sheets)

  * [C++ Inheritance Modes](#c-inheritance-modes--quick-cheat-sheet)
  * [C++ OOP Keywords](#c-oop-keywords-inheritance--polymorphism--quick-cheat-sheet)
* [42 Notes](#-42-notes)

---

## 📝 Description

This repository contains my solutions to **42’s C++ Module 03 (C++98)**.

The module focuses on **inheritance** and how base/derived classes interact:

* Single inheritance (`ClapTrap` → `ScavTrap` / `FragTrap`)
* Overriding behavior (e.g., redefining `attack()` in derived classes)
* Understanding constructor/destructor order
* Multiple inheritance and the **diamond problem** (`DiamondTrap`)
* Sharing a single base with **virtual inheritance**

All exercises are written in **C++98** and compiled with strict flags (`-Wall -Wextra -Werror -std=c++98`).

---

## 🎯 Goals of the Module

Concepts practiced in this module:

* **Inheritance** (`public` inheritance for “is-a”)
* **Overriding** methods and calling base implementations when needed
* **Constructor initialization lists** in an inheritance chain
* **Rule of Three** (copy constructor, assignment operator, destructor)
* **Multiple inheritance** and resolving ambiguity
* **Virtual inheritance** to solve the “diamond” (single shared base)

---

## 📦 Exercises Overview

### ex00 – ClapTrap

> A small combat-style class used as a base for the rest of the module.

**Goal:**
Implement `ClapTrap` with the canonical behavior:

* `attack(target)` consumes energy and prints an action
* `takeDamage(amount)` decreases hit points
* `beRepaired(amount)` consumes energy and restores hit points

**Concepts practiced:**

* Basic class design
* State management (HP/EP/AD)
* Copy / assignment / destructor (Rule of Three)

---

### ex01 – ScavTrap

> First derived class: specialized behavior + custom stats.

**Goal:**
Create `ScavTrap` inheriting from `ClapTrap`, with:

* Updated default stats (HP/EP/AD according to the subject)
* Overridden `attack()` (ScavTrap-style message)
* New ability: `guardGate()`

**Concepts practiced:**

* `public` inheritance and overriding
* Derived class constructors calling base constructors

---

### ex02 – FragTrap

> Second derived class: high energy, friendly vibes.

**Goal:**
Create `FragTrap` inheriting from `ClapTrap`, with:

* Updated default stats (HP/EP/AD)
* New ability: `highFivesGuys()`

**Concepts practiced:**

* More inheritance practice
* Consistent canonical form across classes

---

### ex03 – DiamondTrap

> Multiple inheritance + the “diamond” problem.

**Goal:**
Create `DiamondTrap` inheriting from both `FragTrap` and `ScavTrap`, while:

* Keeping **one** shared `ClapTrap` base (via **virtual inheritance**)
* Having its own `name` (DiamondTrap identity)
* Storing the base name as `DiamondTrapName_clap_name`
* Using `ScavTrap::attack()`
* Adding `whoAmI()` to print both names:

  * DiamondTrap’s own name
  * ClapTrap’s name

**Concepts practiced:**

* Multiple inheritance
* Ambiguity resolution (`Base::method()`)
* `virtual public Base` to ensure a single shared base

---

## 🛠 Requirements

From the subject (typical for 42 C++ modules):

* **Compiler**: `c++`
* **Flags**:

  * `-Wall -Wextra -Werror`
  * `-std=c++98`
* **OS**: any Unix-like system (Linux / macOS)
* **No external libraries** (no C++11+)

---

## ▶️ Build & Run

Clone the repository and build each exercise separately.

```bash
git clone <this-repo-url>
cd cpp-module-03
```

### ex00 – ClapTrap

```bash
cd ex00
make
./claptrap
```

### ex01 – ScavTrap

```bash
cd ex01
make
./scavtrap
```

### ex02 – FragTrap

```bash
cd ex02
make
./fragtrap
```

### ex03 – DiamondTrap

```bash
cd ex03
make
./diamondtrap
```

> Executable names may differ depending on your Makefiles / implementation.

---

## 📂 Repository Layout

```text
cpp-module-03/
├── ex00/
│   ├── Makefile
│   ├── ClapTrap.hpp
│   ├── ClapTrap.cpp
│   └── main.cpp
│
├── ex01/
│   ├── Makefile
│   ├── ClapTrap.hpp / ClapTrap.cpp
│   ├── ScavTrap.hpp / ScavTrap.cpp
│   └── main.cpp
│
├── ex02/
│   ├── Makefile
│   ├── ClapTrap.hpp / ClapTrap.cpp
│   ├── FragTrap.hpp / FragTrap.cpp
│   └── main.cpp
│
└── ex03/
    ├── Makefile
    ├── ClapTrap.hpp / ClapTrap.cpp
    ├── ScavTrap.hpp / ScavTrap.cpp
    ├── FragTrap.hpp / FragTrap.cpp
    ├── DiamondTrap.hpp / DiamondTrap.cpp
    └── main.cpp
```

---

## 🔍 Testing Tips

### General

* Check that **HP/EP/AD** values match the subject defaults in each class.
* Verify that **energy can run out** and actions stop when EP = 0.
* Verify that **dead traps** (HP = 0) cannot attack/repair.

### ex03 (DiamondTrap)

* Confirm `ClapTrap` constructor is called **once** (shared base).
* Confirm `DiamondTrap::attack()` uses **ScavTrap-style** output.
* Confirm `whoAmI()` prints:

  * `DiamondTrap name: Ruby`
  * `ClapTrap name: Ruby_clap_name`
* Confirm destructor order is reasonable (derived → bases, virtual base last).

---

## 🧠 Quick Cheat Sheets

## C++ Inheritance Modes — Quick Cheat Sheet

**Mental model:** `Human` = base, `Warrior` = derived

### 1) `public` — “Warrior **IS** a Human” ✅

```cpp
class Warrior : public Human {};
```

✅ Outside code can treat `Warrior` as `Human`:

```cpp
void greet(Human& h);
Warrior w;
greet(w);        // ✅ OK
Human* p = &w;   // ✅ OK
```

### 2) `protected` — “Outside: NOT Human; subclasses: yes”

```cpp
class Warrior : protected Human {};
```

❌ Outside code:

```cpp
void greet(Human& h);
Warrior w;
greet(w);      // ❌ ERROR
```

✅ Inside `Warrior` and its subclasses, base members stay accessible.

### 3) `private` — “Not IS-A; internal reuse only” 🔒

```cpp
class Warrior : private Human {};
// for class: default is private
class Warrior : Human {};
```

❌ Outside code cannot treat it as `Human`.
❌ Even subclasses of `Warrior` can’t access `Human` part.
✅ `Warrior` itself can use the base internally.

---

## C++ OOP Keywords (Inheritance & Polymorphism) — Quick Cheat Sheet

> A compact list of keywords/idioms that matter most around inheritance.

---

### 1) `virtual` (methods) — **polymorphism** 🎭

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

### 2) `override` — **compile-time check that you really override** ✅

```cpp
void speak() override;
```

If the signature doesn’t match exactly (params, `const`, refs, etc.), you get a compile error.

---

### 3) `final` — **prevent inheritance / prevent further overrides** 🧱

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

### 4) `virtual` destructor — **safe delete via base pointer** 🧨

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

### 5) `protected` — **visible to derived classes, hidden from outside** 🛡️

```cpp
class Base {
protected:
    int hp;
};
```

**Idea:** derived classes can access it; external code cannot.

---

### 6) `using Base::method;` — **keep overloads visible / selectively re-export** 🔎

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

### 7) `explicit` (constructors) — **block implicit conversions** 🚫

```cpp
class Money {
public:
    explicit Money(int cents);
};

Money m = 42;   // ❌ not allowed
Money m2(42);   // ✅ allowed
```

---

### 8) `= delete` / `= default` — **control copy/assignment** 🧰

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

### 9) `Base::method()` — **explicitly call the base version** 🎯

Useful with overriding / multiple inheritance.

```cpp
void Der::attack(const std::string& target)
{
    Base::attack(target); // call base implementation
}
```

---

### Tiny reminder: `virtual` has 2 different meanings in C++ ⚠️

* `virtual` **on methods** → polymorphism (`override` / `final`)
* `virtual` **in inheritance** (`class A : virtual public B`) → a single shared base in the “diamond”

---

## 🧾 42 Notes

* C++ modules at 42 generally target **C++98** (no modern features unless explicitly allowed).
* There is no Norminette for C++, but clean structure and readable output logs help a lot during evaluation.
* If your logs differ slightly, check:

  * Constructor/destructor order
  * Which class version of `attack()` is being called
  * Whether your base is truly shared in the diamond (`virtual public ClapTrap`)

---

If you’re a 42 student working on the same module: feel free to explore, get inspired, but **write your own implementation** — that’s where the learning happens. 🚀
