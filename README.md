# 🏏 Cricket Club Record Management System (CCRMS)

A procedural C++ console application designed for a Cricket Club Record Management System. It features role-based access control, full CRUD operations for player biodata, and detailed statistics tracking.

## ⭐ Project Overview
The CCRMS is a robust, console-based C++ application designed to manage the critical data and statistics of a cricket club. It serves as a single source of truth for all player information, ensuring data integrity and streamlined operations for club management.

## 🚀 Key Features
* **Secure Access Control:** Layered security with Admin and User roles.
* **Data Validation:** Rigorous checks for unique IDs, CNICs, and password complexity.
* **Full CRUD Functionality:** Create, Read, Update, and Delete player records.
* **Advanced Team Allocation:** Logic to manage up to four teams without player duplication.
* **Detailed Reporting:** Tabular outputs for rosters and match history.

## 🛠 Development Evolution & Constraints
As a first-semester BSCS student, I built this project to master fundamental programming logic. The project underwent a significant structural evolution to improve code quality.

### **Phase 1: Global Logic (Original)**
* **Constraints:** Built using **Global Parallel Arrays**.
* **Learning Outcome:** Understood how data flows in a basic procedural program, but recognized that global variables make the code "fragile" and harder to maintain.

### **Phase 2: Refactored Modular Structure (Current)**
* **Constraints:** Strictly **No Classes**, and **No Vectors**.
* **Technical Improvements:**
    * **Local Scope:** All data is declared within `main()` for better memory safety.
    * **Pass-by-Reference:** Functions communicate using memory references (`&`), reducing overhead.
    * **Array Passing:** Data is passed to modular functions as parameters, making the code cleaner and more professional.

## ⚙️ Technical Specification
| Component | Implementation |
| :--- | :--- |
| **Data Storage** | Local Parallel Arrays (e.g., `playerName[]`, `id[]`) |
| **Data Flow** | **Pass-by-Reference** and Function Parameters |
| **UI/UX** | Console-based with `<windows.h>` for `gotoxy()` layout control |
| **Validation** | Custom logic for numeric and string data integrity |

## 💡 Future Roadmap (Leveling Up)
* **OOP Redesign:** Implementing **Classes and Structs** to encapsulate player data.
* **Dynamic Storage:** Moving from fixed arrays to `std::vector` for unlimited entries.
* **Data Persistence:** Adding **File Handling** (`fstream`) to save data permanently.

## ▶️ How to Run
1. Ensure you are on a **Windows** environment (required for `<windows.h>`).
2. Compile using a C++ compiler (like MinGW/g++):
   ```bash
   g++ cricketClubRecordManagement.cpp -o CCRMS.exe
