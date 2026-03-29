# 📦 Courier Management System - OOP Showcase

![C++](https://img.shields.io/badge/c++-%2300599C.svg?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![OOP](https://img.shields.io/badge/OOP-Concepts-FFB74D?style=for-the-badge)
![Console App](https://img.shields.io/badge/Console-Application-lightgrey?style=for-the-badge)

A fast, lightweight console application designed to manage shipments and calculate transport costs. This project serves as a practical demonstration of core **Object-Oriented Programming (OOP)** principles in C++.

---

## 🚀 Features

* **Multiple Shipment Types:** Supports adding various types of mail and packages:
  * Standard Letter
  * Priority Letter
  * Standard Parcel
  * Oversized Parcel (includes dynamic surcharge calculation based on volume)
* **Automated Cost Calculation:** Dynamically calculates the total cost of all items currently in the user's "cart".
* **Robust Input Validation:** Prevents application crashes by securing `std::cin` against invalid inputs (e.g., typing text when a number is expected).
* **Dynamic Memory Management:** Efficient handling of objects created at runtime.

---

## 🛠️ OOP Techniques Demonstrated

This project was built specifically to showcase the four pillars of Object-Oriented Programming:

1. **Inheritance (Dziedziczenie):** * Implementation of a class hierarchy where specific shipment types inherit from a general base class.
2. **Polymorphism (Polimorfizm):** * Utilizing virtual methods (e.g., `ObliczKoszt()` / `CalculateCost()`, `WyswietlInfo()` / `DisplayInfo()`). This allows the system to store different shipment objects in a single `std::vector` and call the appropriate method for each specific type at runtime.
3. **Abstraction (Abstrakcja):** * The base `cPrzesylka` (Shipment) class acts as an abstract class, defining a strict interface that all derived classes must implement.
4. **Encapsulation (Hermetyzacja):** * Safe data handling using appropriate access modifiers (`public`, `protected`, `private`) to protect internal object states.

---

## 🖥️ How to Run

To run this project locally, clone the repository and compile the source files using your preferred C++ compiler (like GCC).

### Using Terminal (g++):

1. Clone the repository:
   ```bash
   git clone <your-repository-url>
   cd <repository-folder-name>
