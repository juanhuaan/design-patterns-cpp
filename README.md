# 🧠 Design Patterns in Modern C++

This repository is a practical exploration of **Gang of Four (GoF)** design patterns using **Modern C++ (C++11 and beyond)**.

> 💡 Goal: Reinforce understanding of classic design patterns by implementing them with clean, idiomatic C++ — leveraging smart pointers, lambdas, templates, and STL.

---

## 📦 Contents

The patterns are grouped by category, as originally classified in *"Design Patterns: Elements of Reusable Object-Oriented Software"*:

### Creational Patterns
- ✅ **Factory Method** – Virtual constructors with `createProduct()`, dynamic dispatch
- ✅ **Abstract Factory** – Families of related objects with shared interfaces
- ✅ **Builder** – Step-by-step construction of complex objects
- ✅ **Prototype** – (Planned) Cloning via polymorphic interfaces
- ✅ **Singleton** – (Planned) Controlled instance creation

### Structural Patterns
- ⚙️ (Coming soon)

### Behavioral Patterns
- ⚙️ (Coming soon)

---

## 🛠️ Modern C++ Features Used

- `std::shared_ptr` for safe memory management
- `std::function` and lambdas for flexible factory injection
- Template-based factory alternatives to reduce inheritance
- `constexpr`, `enum class`, and `std::array` for type safety
- Customizable builders with runtime configuration

---

## 🧪 Example Highlights

- **`Creator2<T>` / `Creator3<T>`** – Templated and lambda-injected factory methods
- **Maze Game** – Classical example recreated with `Room`, `Wall`, and `Door` hierarchies using Abstract Factory and Builder
- **Runtime-configurable factories** – `CreatorFlexible<T, Args...>` allows passing construction parameters at runtime

---


## 🚧 Work in Progress

This is a learning-focused repo. I'm gradually building it out pattern by pattern. Structural and Behavioral patterns will follow once the Creational set is complete.

---

## 🤝 Contribution

Suggestions, critiques, or pull requests are welcome — especially on how to make the implementations even more modern, elegant, or embedded-systems-friendly.

---

## 📚 References

- *Design Patterns: Elements of Reusable Object-Oriented Software*, Gamma et al.
- *Effective Modern C++*, Scott Meyers
- *C++ Design Patterns and Derivatives*, Andrei Alexandrescu
- Your own creativity and curiosity ✨

---

## 🧑‍💻 Author

Designed and maintained by **Juanhua An** 



