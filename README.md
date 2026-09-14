# Terminal Monopoly: C++ Game Engine

A robust, terminal-based implementation of Monopoly built in C++17. This project was developed to demonstrate rigorous object-oriented design, dynamic memory management, and polymorphic state handling in a console environment.

## Architecture & Design Patterns

The engine is built with a focus on encapsulation and memory safety, avoiding raw arrays and global state in favor of structured OOP principles.

* **Polymorphic Tile System:** The board is an array of base `Space` pointers. Derived classes (`Property`, `Railroad`, `Utility`, `Tax`, `Chance`) override the virtual `handleLanding()` method, allowing the game loop to execute specific logic without relying on massive, brittle `switch` statements.
* **Lambda-Driven Event Handling:** The Chance and Community Chest decks utilize `std::function` and lambda expressions. Instead of complex function pointer queues, each card stores its text and its specific gameplay effect as an encapsulated executable block.
* **Encapsulated State Management:** Player financial transactions, property ownership, and building states (houses/hotels) are strictly controlled through getter/setter protocols to prevent invalid memory mutations.

## Memory & Systems Engineering

* **Deterministic Cleanup:** The `Board` and `Player` destructors ensure all dynamically allocated memory (Spaces, Players, Interface) is safely released back to the heap upon game completion or player bankruptcy.
* **Type Safety:** Extensive use of `const` qualifiers for immutable strings and member functions, alongside safe `dynamic_cast` operations for extracting specialized derived-class data (e.g., retrieving specific deed values from generic `Ownable` pointers).

## Build Instructions

This project includes a custom Windows batch script to automate the build process using the MinGW/GCC toolchain. 

**Prerequisites:**
* Windows OS
* `g++` installed and added to your system PATH.

**Compilation & Execution:**
1. Clone the repository and navigate to the root directory.
2. Run the build script by typing make into the terminal (with no spaces):
   make
