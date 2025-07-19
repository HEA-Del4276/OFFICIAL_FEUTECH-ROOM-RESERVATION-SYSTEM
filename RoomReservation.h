#ifndef ROOMRESERVATION_H
#define ROOMRESERVATION_H

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <fstream>
#include <limits>
#include <algorithm>
#include <sstream>
using namespace std;

// Reservation Data Structure
struct ReservationNode {
    string name;
    int studentNum;
    string program;
    string section;
    string activityName;
    string activityDate;
    string activityStart;
    string activityEnd;
    int numparticipants;
    string roomType;
    string roomName;
};

// Waitlist Data Structure
struct WaitlistNode {
    string name;
    int studentNum;
    string program;
    string section;
    string activityName;
    string activityDate;
    string activityStart;
    string activityEnd;
    int numparticipants;
    string roomType;
    string roomName;
};

// Room Node (for internal use only if needed)
struct RoomNode {
    string roomType;
    string roomName;
    string dateAvailability;
    string timeAvailability;
};

class RoomReservation {
private:
    // Room Details
    string roomType;
    string roomName;
    string dateAvailability;
    string timeAvailability;
    int roomChoice;
    int numDates;
    int numTimes;
    int timeChoice;
    vector<string> dateList;
    vector<string> selectedTimes;

    // Reservation Details
    string name;
    int studentNum;
    string program;
    string section;
    string activityName;
    string activityDate;
    string activityStart;
    string activityEnd;
    int numparticipants;

    // Others
    char confirm;
    int choice;
    int action;

    // STL Containers for Reservations and Waitlist
    vector<ReservationNode> reservations;   // Replaces linked list
    queue<WaitlistNode> waitlist;           // Replaces manual queue

    // Helper methods
    void loadReservationsFromFile();
    void saveReservationToFile(const ReservationNode& reservation);
    void clearInput();
    string getRoomTypeString(int choice);
    void displayReservationDetails(const ReservationNode& reservation, int index);
    vector<ReservationNode*> findReservationsByName(const string& name);
    bool removeReservationByIndex(int index, const string& name);
    void updateReservationFile();

    // Queue operations for waitlist
    void loadWaitlistFromFile();
    void saveWaitlistToFile(const WaitlistNode& waitlistEntry);
    void enqueueWaitlist(const WaitlistNode& waitlistEntry);
    void displayWaitlistQueue();
    void displayWaitlistDetails(const WaitlistNode& waitlistEntry, int index);
    vector<WaitlistNode> findWaitlistByName(const string& name);
    void updateWaitlistFile();

    // Room validation
    bool findRoomInFile(const string& roomName, string& roomType, string& dateAvailability, string& timeAvailability);
    void displayAvailableClassrooms();
    void displayAvailableActivityRooms();
    void displayAllAvailableRooms();
    bool isDateCompatible(const string& activityDate, const string& roomDateAvailability);
    bool isTimeCompatible(const string& activityStart, const string& activityEnd, const string& roomTimeAvailability);
    bool validateRoomSelection(const string& roomName, const string& activityStart, const string& activityEnd, string& roomType, string& dateAvailability, string& timeAvailability);
    bool validateRoomSelectionWithDate(const string& roomName, const string& activityDate, const string& activityStart, const string& activityEnd, string& roomType, string& dateAvailability, string& timeAvailability);

public:
    // Constructor
    RoomReservation();

    // Destructor
    ~RoomReservation();

    // Main Functions
    void displayMenu();
    void searchRoom();
    void reserveRoom();
    void addRoom();
    void editRoomOrReservation();
    void deleteRoom();
    void cancelReservation();
    void joinWaitlist();
    void viewAvailableRooms();
    void viewMyReservations();
    void viewAllRoomsAndReservations();

    // Getters and Setters
    string getRoomType() const;
    void setRoomType(const string& type);

    string getRoomName() const;
    void setRoomName(const string& name);

    string getTimeSlot(int choice);
};

#endif
