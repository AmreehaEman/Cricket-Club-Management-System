# Cricket-Club-Management-System
A procedural C++ console application designed for a Cricket Club Record Management System. It features role-based access control (Admin/User), full CRUD operations (Create, View, Update, Delete) for player biodata, detailed player statistics tracking (average, strike rate, runs), and unique team selection logic for up to four teams.

# 🏏 Cricket Club Record Management System (CCRMS)

## ⭐ Project Overview

The Cricket Club Record Management System (CCRMS) is a robust, console-based C++ application designed to manage the critical data and statistics of a cricket club. It serves as a single source of truth for all player information, ensuring data integrity and streamlined operations for club management.

## 🚀 Key Features

This application goes beyond simple data entry, providing essential tools for club administration:

* **Secure Access Control:** Implements a layered security model with distinct **Admin** and **User** roles to control sensitive actions (like player deletion and data modification).
* **Comprehensive Data Validation:** Includes rigorous checks for unique player IDs, CNIC numbers, and ensures all statistical inputs are valid to prevent database corruption.
* **Full CRUD Functionality:** Supports creation, retrieval, updating, and deletion of player records and statistics.
* **Advanced Team Allocation Logic:** Features specific functionality to manage team membership for up to four distinct teams, ensuring a player cannot be assigned to multiple teams simultaneously.
* **Detailed Reporting:** Provides organized, tabular outputs to display the entire roster, individual player reports, and current team line-ups.

## ⚙️ Current Technical Structure

The CCRMS is currently built upon foundational programming concepts taught in early computer science:

| Component | Description | Technical Implementation |
| :--- | :--- | :--- |
| **Data Storage** | Stores all player attributes (name, runs, fees, etc.). | **Global Parallel Arrays** (e.g., separate arrays for `playerName[]`, `runs[]`, `fee[]`). |
| **Program Logic** | Handles user input, feature execution, and data modification. | **Modular Functions** (e.g., `registration()`, `searchData()`) utilizing procedural flow. |
| **Platform** | Optimized for running in a specific environment. | Relies on the `<windows.h>` library for specific console operations. |

## 💡 Future Implementations (OOP & Scalability)

The immediate roadmap for this application focuses on transitioning from a procedural design to a modern **Object-Oriented Programming (OOP)** structure for improved scalability and maintainability.

* **Object-Oriented Redesign:** **Classes and Structures** will be implemented to encapsulate player data and related methods into a single, cohesive unit (`Player` class), replacing the use of parallel arrays.
* **Dynamic Storage:** Migration from fixed-size arrays to the `std::vector` container to allow the club roster to grow dynamically without a fixed size limit.
* **Data Persistence:** Implementation of **File Handling** to ensure player data is saved and loaded, allowing the system to retain information after the program is closed.

---
# ▶️ How to Run the Application

This is a console-based C++ application requiring compilation via `g++` or a similar C++ compiler.

**Platform Note:**

* The program relies on the `<windows.h>` library for console manipulation features.
* **It is optimized and intended for use in a Windows environment.**
* Users on Linux or macOS environments must replace or abstract the `<windows.h>` calls (e.g., using platform-agnostic libraries like `unistd.h` for `sleep()` functionality) to successfully compile and execute the code.
---
