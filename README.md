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

```
OFFICIAL ROOM RESERVATION-FINALS CODE/
├── main.cpp          # Main program file
└── README.md         # This file
```

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

