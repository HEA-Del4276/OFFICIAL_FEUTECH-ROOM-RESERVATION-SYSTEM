# OFFICIAL FEU TECH ROOM RESERVATION SYSTEM

A comprehensive room reservation system developed for FEU Tech students and faculty.

## Features

- Search for available rooms
- Reserve rooms for activities
- Add new rooms to the system
- Edit room details and reservations
- Delete rooms from the system
- Cancel existing reservations
- Join waitlist for fully booked rooms
- View available rooms
- View personal reservations
- View all rooms and reservations
- Complete system management

## Getting Started

### Prerequisites

- C++ compiler (GCC, MinGW, or Visual Studio)
- Basic knowledge of C++ programming
- Git installed on your system
- Visual Studio Code (recommended)

### 💡 AI Development Assistance
**Strongly Recommended**: Use **GitHub Copilot AI** directly inside Visual Studio Code instead of external AI tools. This provides:
- Better code context understanding
- Seamless integration with your development environment
- More accurate suggestions based on your project structure
- Real-time coding assistance without switching applications

### Setting Up the Repository in Visual Studio Code

#### 1. Clone the Repository
Open Visual Studio Code and follow these steps:

**Option A: Using VS Code's Built-in Git**
1. Press `Ctrl+Shift+P` (Windows) to open Command Palette
2. Type "Git: Clone" and select it
3. Enter the repository URL: `https://github.com/HEA-Del4276/OFFICIAL_FEUTECH-ROOM-RESERVATION-SYSTEM.git`
4. Choose a folder location on your computer
5. Click "Open" when prompted

**Option B: Using Terminal/Command Prompt**
```bash
git clone https://github.com/HEA-Del4276/OFFICIAL_FEUTECH-ROOM-RESERVATION-SYSTEM.git
cd OFFICIAL_FEUTECH-ROOM-RESERVATION-SYSTEM
code .
```

#### 2. Pulling Latest Changes
To get the latest updates from the repository:

**In VS Code:**
1. Open the Source Control panel (`Ctrl+Shift+G`)
2. Click the "..." menu and select "Pull"

**Or use Terminal:**
```bash
git pull origin main
```

#### 3. Important Notes
⚠️ **READ-ONLY ACCESS**: Team members can clone and pull from this repository, but **cannot push changes** unless given explicit permission by the repository owner.

- You can freely download and work with the code locally
- To contribute changes, contact the repository owner for push permissions
- Always pull latest changes before starting work to ensure you have the most recent version

### Compilation

```bash
g++ -o room_reservation main.cpp
```

### Running the Program

```bash
./room_reservation
```

## Usage

The system provides a menu-driven interface with the following options:

1. **SEARCH ROOM** - Find specific rooms by name
2. **RESERVE ROOM** - Book a room for your activity
3. **ADD ROOM** - Add new rooms to the system
4. **EDIT ROOM/RESERVATION** - Modify existing room details or reservations
5. **DELETE ROOM** - Remove rooms from the system
6. **CANCEL RESERVATION** - Cancel your existing reservations
7. **JOIN WAITLIST** - Join waitlist for unavailable rooms
8. **VIEW AVAILABLE ROOMS** - See all currently available rooms
9. **VIEW MY RESERVATIONS** - Check your personal reservations
10. **VIEW ALL ROOMS/RESERVATIONS** - Complete system overview
11. **EXIT SYSTEM** - Close the application

## Project Structure

### Core Files (Main Development)

### OFFICIAL ROOM RESERVATION-FINALS CODE/
├── main.cpp                     # Main program file - Entry point to run the application
├── display.cpp                  # Expected output guide - Shows what the program output should look like (used for reference)
├── RoomReservation.h            # Header file - Contains class declarations, function prototypes, and data structures
├── RoomReservation.cpp          # Implementation file - Contains the actual implementation of all class methods and functions
├── rooms-data-list.txt          # Room database - Stores all available rooms and their details
├── reservation-data-list.txt    # Reservation database - Stores all active room reservations
├── waitlist-data.txt            # Waitlist database - Stores users waiting for room availability
└── README.md                    # Project documentation

### Test Files (Sample Runs)
Files named with "sample" prefix are test runs that demonstrate different program functionalities and expected behaviors. These files help in testing and validation of the system features.

## Contributing

This is a final project for CCS0015. For any suggestions or improvements, please contact the development team.

## License

This project is developed as part of academic coursework at FEU Tech.

## Author

Student ID: 202410364@fit.edu.ph
Course: CCS0015
Institution: FEU Tech

## Required Concepts to Apply 
Your system must include and demonstrate the following:
1. Functions
    - Use modular functions for each major operation (e.g., addRecord(), deleteRecord(), searchRecord(), saveToFile(), loadFromFile(), etc.).
    - Avoid writing everything in the main() function.
2. Abstract Data Types (ADT)
    - Implement your own user-defined data structures using class. Apply 3-file structure.
3. Pointers
    - Use pointers for dynamic memory allocation, parameter passing, or navigating linked lists.
4. Linked List
    - Use a singly or doubly linked list to manage a dynamic collection of records.
5. Stack or Queue
    - Use either a stack (e.g., undo actions, navigation history) or a queue (e.g., customer waiting list, order queue).
6. File Handling
    - Your system must be able to:
        * Store data persistently in text files.
        * Retrieve and display data from the files when the program runs again.

## Main Menu Options and Programming constructs
[1] - SEARCH ROOMS (Linked List)
[2] - RESERVE ROOM (Linked List)
[3] - ADD ROOM (Linked List)
[4] - EDIT ROOM/RESERVATION (Linked List)
[5] - DELETE ROOM (Linked List)
[6] - CANCEL RESERVATION (Linked List)
[7] - JOIN WAITLIST (Queue)
[8] - VIEW AVAILABLE ROOMS (Linked List)
[9] - VIEW MY RESERVATIONS (File Handling)
[10] - VIEW ALL ROOMS/RESERVATIONS (File Handling)
[11] - EXIT SYSTEM

