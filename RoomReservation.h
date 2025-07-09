#ifndef ROOMRESERVATION_H
#define ROOMRESERVATION_H
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <limits>
#include <algorithm>
#include <sstream>
using namespace std;

// Reservation Node for Linked List
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
    ReservationNode* next;
    
    ReservationNode() : next(nullptr) {}
};

// Waitlist Node for Queue
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
    WaitlistNode* next;
    
    WaitlistNode() : next(nullptr) {}
};

class RoomReservation{
    //Attributes
    private:
        //Room Details
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

        //Reservation Details
        string name;
        int studentNum;
        string program;
        string section;
        string activityName;
        string activityDate;
        string activityStart;
        string activityEnd;
        int numparticipants;

        //Others
        char confirm;
        int choice;
        int action;

        //Linked List for reservations
        ReservationNode* head;
        
        //Queue for waitlist (FIFO)
        WaitlistNode* front;
        WaitlistNode* rear;
        
        //Helper methods
        void loadReservationsFromFile();
        void saveReservationToFile(const ReservationNode& reservation);
        void addReservationToList(const ReservationNode& reservation);
        void clearInput();
        string getRoomTypeString(int choice);
        vector<ReservationNode*> findReservationsByName(const string& name);
        void displayReservationDetails(const ReservationNode& reservation, int index);
        bool removeReservationFromList(int index, const string& name);
        void updateReservationFile();
        
        // Queue operations for waitlist
        void loadWaitlistFromFile();
        void saveWaitlistToFile(const WaitlistNode& waitlist);
        void enqueueWaitlist(const WaitlistNode& waitlist);
        void displayWaitlistQueue();
        void displayWaitlistDetails(const WaitlistNode& waitlist, int index);
        vector<WaitlistNode*> findWaitlistByName(const string& name);
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
        //Constructor
        RoomReservation();
        
        //Destructor
        ~RoomReservation();

        //Methods
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

        //Getters and Setters
        string getRoomType() const;
        void setRoomType(const string& type);
        
        string getRoomName() const;
        void setRoomName(const string& name);

        string getTimeSlot(int choice);
        
        // Other getters and setters as needed...
    
};

#endif
