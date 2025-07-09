#include "RoomReservation.h"

RoomReservation::RoomReservation() {
    // Initialize attributes if necessary
    roomType = "";
    roomName = "";
    dateAvailability = "";
    timeAvailability = "";
    roomChoice = 0;
    numDates = 0;
    numTimes = 0;
    timeChoice = 0;
    head = nullptr;
    
    // Initialize queue pointers
    front = nullptr;
    rear = nullptr;
    
    // Load existing reservations from file
    loadReservationsFromFile();
    
    // Load existing waitlist from file
    loadWaitlistFromFile();
}

RoomReservation::~RoomReservation() {
    // Clean up the linked list
    ReservationNode* current = head;
    while (current != nullptr) {
        ReservationNode* next = current->next;
        delete current;
        current = next;
    }
    
    // Clean up the waitlist queue
    WaitlistNode* waitlistCurrent = front;
    while (waitlistCurrent != nullptr) {
        WaitlistNode* next = waitlistCurrent->next;
        delete waitlistCurrent;
        waitlistCurrent = next;
    }
}

void RoomReservation::displayMenu() {
    cout << "\n  ****************************************************" << endl;			
    cout << "  ----------------------------------------------------" << endl;	
    cout << "\t==============================" << endl;
    cout << "\t|      RESERVATION MENU      |" << endl;
    cout << "\t==============================" << endl;
    cout << "\t|\t\t\t     |" << endl;
    cout << "\t|  [1] SEARCH ROOM           |" << endl;
    cout << "\t|  [2] RESERVE ROOM          |" << endl;
    cout << "\t|  [3] ADD ROOM              |" << endl;
    cout << "\t|  [4] EDIT ROOM/RESERVATION |" << endl;
    cout << "\t|  [5] DELETE ROOM           |" << endl;
    cout << "\t|  [6] CANCEL RESERVATION    |" << endl;
    cout << "\t|  [7] JOIN WAITLIST         |" << endl;
    cout << "\t|  [8] VIEW AVAILABLE ROOMS  |" << endl;
    cout << "\t|  [9] VIEW MY RESERVATIONS  |" << endl;
    cout << "\t|  [10] VIEW ALL ROOMS/      |" << endl;
    cout << "\t|       RESERVATIONS         |" << endl;
    cout << "\t|  [11] EXIT SYSTEM          |" << endl;
    cout << "\t|\t\t\t     |" << endl;
    cout << "\t==============================" << endl;

    cout << "\n  ****************************************************" << endl;			
	cout << "  ----------------------------------------------------" << endl;	
}

void RoomReservation::searchRoom() {
			cout << "  ----------------------------------------------------" << endl;	
			cout << "  ****************************************************" << endl;			
			cout << "\n  [RSYS: SEARCH A ROOM]" << endl;
			cout << "\n  [Enter COMPLETE room name]:"; //Add cin (For user input)
            //Follow the design for outputs in "display.cpp"
}

void RoomReservation::reserveRoom() {
    cout << "  ----------------------------------------------------" << endl;	
    cout << "  ****************************************************" << endl;			
    
    ReservationNode newReservation;
    
    // Input Applicant Details
    cout << "\n  [RSYS: APPLICANT DETAILS]" << endl;
    cout << "\n  [Enter your name]: ";
    cin.ignore();
    getline(cin, newReservation.name);
    
    cout << "  [Enter student number]: ";
    while (!(cin >> newReservation.studentNum)) {
        cout << "  [Invalid input. Enter student number]: ";
        clearInput();
    }
    cin.ignore();
    
    cout << "  [Enter program]: ";
    getline(cin, newReservation.program);
    
    cout << "  [Enter section]: ";
    getline(cin, newReservation.section);
    
    cout << "\n  ----------------------------------------------------" << endl;	
    
    // Input Activity Details
    cout << "\n  [RSYS: ACTIVITY DETAILS]" << endl;
    cout << "\n  [Enter activity name]: ";
    getline(cin, newReservation.activityName);
    
    // Display all available rooms after activity name input
    displayAllAvailableRooms();
    
    cout << "\n  [Date (MM/DD/YYYY)]: ";
    getline(cin, newReservation.activityDate);
    
    cout << "  [Start time (0AM/0PM)]: ";
    getline(cin, newReservation.activityStart);
    
    cout << "  [End Time (0AM/0PM)]: ";
    getline(cin, newReservation.activityEnd);
    
    cout << "  [No. of Participants]: ";
    while (!(cin >> newReservation.numparticipants)) {
        cout << "  [Invalid input. Enter number of participants]: ";
        clearInput();
    }
    cin.ignore();
    
    cout << "\n  ----------------------------------------------------" << endl;	

    // Input Reservation Details
    cout << "\n  [RSYS: ROOM DETAILS]" << endl; 
    cout << "\n\t==============================" << endl;
    cout << "\t|        TYPE OF ROOM        |" << endl;
    cout << "\t==============================" << endl;
    cout << "\t|\t\t\t     |" << endl;
    cout << "\t|  [1] CLASSROOM             |" << endl;
    cout << "\t|  [2] ACTIVITY/EVENT ROOM   |" << endl;
    cout << "\t|  [3] CANCEL PROCESS        |" << endl;
    cout << "\t|\t\t\t     |" << endl;
    cout << "\t==============================" << endl;
    
    int roomTypeChoice;
    bool validChoice = false;
    while (!validChoice) {
        cout << "\n  [Enter your choice (1-3)]: ";
        if (cin >> roomTypeChoice) {
            if (roomTypeChoice >= 1 && roomTypeChoice <= 3) {
                validChoice = true;
                if (roomTypeChoice == 3) {
                    cout << "\n  [Process cancelled. Returning to main menu...]" << endl;
                    cin.ignore();
                    return;
                }
            }
        }
        if (!validChoice) {
            cout << "  [Invalid choice. Please enter 1, 2, or 3]" << endl;
            clearInput();
        }
    }
    cin.ignore();
    
    newReservation.roomType = getRoomTypeString(roomTypeChoice);
    cout << "\n  [RSYS: TYPE OF ROOM]: " << newReservation.roomType << endl;
    
    // Handle room selection based on type
    if (roomTypeChoice == 1) { // CLASSROOM
        bool roomSelected = false;
        while (!roomSelected) {
            // Display available classrooms
            displayAvailableClassrooms();
            
            cout << "\n  [Room Floor & Name]: ";
            getline(cin, newReservation.roomName);
            
            // Validate room selection with date and time compatibility
            string roomType, dateAvailability, timeAvailability;
            if (validateRoomSelectionWithDate(newReservation.roomName, newReservation.activityDate, 
                                            newReservation.activityStart, newReservation.activityEnd, 
                                            roomType, dateAvailability, timeAvailability)) {
                roomSelected = true;
                cout << "\n  [RSYS: Room selected successfully!]" << endl;
            } else {
                cout << "\n  [RSYS: ERROR - Room selection failed!]" << endl;
                cout << "  [The selected room either doesn't exist, is not available,]" << endl;
                cout << "  [doesn't match your activity date/time requirements.]" << endl;
                
                char tryAgain;
                cout << "\n  [Try another room? (Y/N)]: ";
                cin >> tryAgain;
                cin.ignore();
                
                if (tryAgain != 'Y' && tryAgain != 'y') {
                    cout << "\n  [Room selection cancelled. Returning to main menu...]" << endl;
                    return;
                }
            }
        }
    } else { // ACTIVITY/EVENT ROOM
        bool roomSelected = false;
        while (!roomSelected) {
            // Display available activity/event rooms
            displayAvailableActivityRooms();
            
            cout << "\n  [Room Floor & Name]: ";
            getline(cin, newReservation.roomName);
            
            // Validate room selection with date and time compatibility for activity rooms too
            string roomType, dateAvailability, timeAvailability;
            if (validateRoomSelectionWithDate(newReservation.roomName, newReservation.activityDate, 
                                            newReservation.activityStart, newReservation.activityEnd, 
                                            roomType, dateAvailability, timeAvailability)) {
                roomSelected = true;
                cout << "\n  [RSYS: Room selected successfully!]" << endl;
            } else {
                cout << "\n  [RSYS: ERROR - Room selection failed!]" << endl;
                cout << "  [The selected room either doesn't exist, is not available,]" << endl;
                cout << "  [or doesn't match your activity date/time requirements.]" << endl;
                
                char tryAgain;
                cout << "\n  [Try another room? (Y/N)]: ";
                cin >> tryAgain;
                cin.ignore();
                
                if (tryAgain != 'Y' && tryAgain != 'y') {
                    cout << "\n  [Room selection cancelled. Returning to main menu...]" << endl;
                    return;
                }
            }
        }
    }
    
    cout << "\n  ----------------------------------------------------" << endl;	
    
    // Display Reservation Summary
    cout << "\n  [RSYS: RESERVATION SUMMARY]" << endl;
    cout << "\n  ====================================================";
    cout << "\n   RESERVATION DETAILS ------------------------------";
    cout << "\n   [APPLICANT DETAILS]";
    cout << "\n   Name: " << newReservation.name;
    cout << "\n   Student Number: " << newReservation.studentNum;
    cout << "\n   Program: " << newReservation.program;
    cout << "\n   Section: " << newReservation.section;
    cout << "\n   -------------------------------------------------- ";
    cout << "\n   [ACTIVITY DETAILS]";
    cout << "\n   Activity Name: " << newReservation.activityName;
    cout << "\n   Date (MM/DD/YYYY): " << newReservation.activityDate;
    cout << "\n   [Start time (0AM/0PM)]: " << newReservation.activityStart;
    cout << "\n   [End Time (0AM/0PM)]: " << newReservation.activityEnd;
    cout << "\n   [No. of Participants]: " << newReservation.numparticipants;
    cout << "\n   -------------------------------------------------- ";
    cout << "\n   [ROOM DETAILS]";
    cout << "\n   Type of Room: " << newReservation.roomType;
    cout << "\n   Room Floor & Name: " << newReservation.roomName;
    cout << "\n   -------------------------------------------------- ";
    cout << "\n  ====================================================" << endl;
    
    // Confirmation
    cout << "\n  [RSYS: CONFIRMATION]" << endl;
    char confirm;
    cout << "\n  [Confirm reservation details? (Y/N)]: ";
    cin >> confirm;
    cin.ignore();
    
    if (confirm == 'Y' || confirm == 'y') {
        // Add to linked list and save to file
        addReservationToList(newReservation);
        saveReservationToFile(newReservation);
        
        cout << "\n  ====================================================";
        cout << "\n   ----------- RESERVATION CONFIRMED! --------------- ";
        cout << "\n   Your reservation has been successfully added!";
        cout << "\n   Reservation ID: RES" << newReservation.studentNum;
        cout << "\n   -------------------------------------------------- ";
        cout << "\n  ====================================================" << endl;
    } else {
        cout << "\n  [Reservation cancelled. Returning to main menu...]" << endl;
    }
}
void RoomReservation::addRoom() {
    char more = 'Y';
    while (toupper(more) == 'Y') {
        // reset any previous data
        dateList.clear();
        selectedTimes.clear();

        cout << "  ----------------------------------------------------\n";
        cout << "  ****************************************************\n";
        cout << "\n  [RSYS: ENTER ROOM DETAILS]\n\n";

        // 1) TYPE OF ROOM
        cout << "\t==============================\n";
        cout << "\t|        TYPE OF ROOM        |\n";
        cout << "\t==============================\n";
        cout << "\t|  [1] CLASSROOM             |\n";
        cout << "\t|  [2] ACTIVITY/EVENT ROOM   |\n";
        cout << "\t|  [3] CANCEL PROCESS        |\n";
        cout << "\t==============================\n\n";
        cout << "  [Enter your choice (1-3)]: ";
        cin >> roomChoice;
        if (roomChoice == 5) {
            cout << "\n  [RSYS: Process cancelled! Returning to main menu...]\n\n";
            return;
        }
        roomType = getRoomTypeString(roomChoice);

        // 2) ROOM FLOOR / NAME
        clearInput();
        cout << "  [Enter room floor/name]: ";
        getline(cin, roomName);

        // 3) DATE AVAILABILITY
        cout << "\n  ----------------------------------------------------\n";
        cout << "\n  [RSYS: DATE AVAILABILITY]\n";
        cout << "  [No. of availability?]: ";
        cin >> numDates;
        clearInput();
        for (int i = 0; i < numDates; ++i) {
            cout << "  [DATE #" << (i+1) << " (MM/DD/YYYY)]: ";
            string d;
            getline(cin, d);
            dateList.push_back(d);
        }

        // join dates into one string
        {
            ostringstream oss;
            for (int i = 0; i < numDates; ++i) {
                oss << dateList[i];
                if (i + 1 < numDates) oss << ", ";
            }
            dateAvailability = oss.str();
        }

        // 4) TIME AVAILABILITY
        cout << "\n  ----------------------------------------------------\n";
        cout << "\n  [RSYS: TIME AVAILABILITY]\n";
        cout << "  [No. of availability? (1-4)]: ";
        cin >> numTimes;

        cout << "\n\t==============================\n";
        cout << "\t|       TIME AVAILABLE       |\n";
        cout << "\t==============================\n";
        cout << "\t|  [1] 8:00AM-12:00PM        |\n";
        cout << "\t|  [2] 8:00AM-5:00PM         |\n";
        cout << "\t|  [3] 12:00PM-5:00PM        |\n";
        cout << "\t|  [4] 12:00PM-7:00PM        |\n";
        cout << "\t|  [5] CANCEL PROCESS        |\n";
        cout << "\t==============================\n\n";

        for (int i = 0; i < numTimes; ++i) {
            cout << "  [TIME #" << (i+1) << "]: ";
            cin >> timeChoice;
            if (timeChoice == 5) {
                cout << "\n  [RSYS: Process cancelled! Returning to main menu...]\n\n";
                return;
            }
            selectedTimes.push_back(getTimeSlot(timeChoice));
        }

        // join times into one string
        {
            ostringstream oss;
            for (int i = 0; i < numTimes; ++i) {
                oss << selectedTimes[i];
                if (i + 1 < numTimes) oss << ", ";
            }
            timeAvailability = oss.str();
        }

        // 5) DISPLAY SUMMARY & CONFIRM
        cout << "\n  ====================================================\n";
        cout << "   ROOM DETAILS -------------------------------------\n";
        cout << "   Type of Room: " << roomType << "\n";
        cout << "   Room Floor & Name: " << roomName << "\n";
        cout << "   Date Availability: \n   " << dateAvailability << "\n";
        cout << "   Time Availability: \n   " << timeAvailability << "\n";
        cout << "   --------------------------------------------------\n";
        cout << "  ====================================================\n\n";

        cout << "  [Confirm room details? (Y/N)]: ";
        cin >> confirm;

        if (toupper(confirm) == 'Y') {
            // append to rooms-data-list.txt file in the correct format
            ofstream ofs("rooms-data-list.txt", ios::app);
            ofs << roomType << endl;
            ofs << roomName << endl;
            ofs << dateAvailability << endl;
            ofs << timeAvailability << endl;
            ofs << endl; // Add empty line to separate room entries
            ofs.close();

            cout << "\n  ====================================================\n";
            cout << "   ---------------- NEW ROOM ADDED! -----------------\n";
            cout << "   Type of Room: " << roomType << "\n";
            cout << "   Room Floor & Name: " << roomName << "\n";
            cout << "   Date Availability: \n   " << dateAvailability << "\n";
            cout << "   Time Availability: \n   " << timeAvailability << "\n";
            cout << "   --------------------------------------------------\n";
            cout << "  ====================================================\n";
        } else {
            cout << "\n  [RSYS: Room not added! Returning to main menu...]\n";
        }

        cout << "\n  [Enter another room? (Y/N)]: ";
        cin >> more;
        cout << "\n";
    }
}


void RoomReservation::editRoomOrReservation() {
			cout << "  ----------------------------------------------------" << endl;	
			cout << "  ****************************************************" << endl;
			cout << "\n  [RSYS: EDIT ROOM/RESERVATION]" << endl;
			cout << "\n\t==============================" << endl;
			cout << "\t|        EDIT OPTIONS        |" << endl;
			cout << "\t==============================" << endl;
			cout << "\t|\t\t\t     |" << endl;
			cout << "\t|  [1] ROOM                  |" << endl;
			cout << "\t|  [2] RESERVATION           |" << endl;
			cout << "\t|  [3] CANCEL PROCESS        |" << endl; //After confirming to cancel, Return to Main Menu
			cout << "\t|\t\t\t     |" << endl;
			cout << "\t==============================" << endl;
			
			cout << "\n  [Enter your choice (1-3)]:" << endl; //Add cin (For user input)
            //Follow the design for outputs in "display.cpp"
}

void RoomReservation::deleteRoom() {
			cout << "  ----------------------------------------------------" << endl;	
			cout << "  ****************************************************" << endl;	
			cout << "\n  [RSYS: DELETE ROOM]" << endl;
			cout << "\n  [Enter COMPLETE room name]: "; //Add cin (For user input)
            //Follow the design for outputs in "display.cpp"
}

void RoomReservation::cancelReservation() {
    cout << "  ----------------------------------------------------" << endl;	
    cout << "  ****************************************************" << endl;	
    cout << "\n  [RSYS: CANCEL RESERVATION]" << endl;
    
    cin.ignore(); // Clear input buffer once at the beginning
    
    bool continueCancellation = true;
    while (continueCancellation) {
        string applicantName;
        cout << "\n  [Enter Applicant's Name]: ";
        getline(cin, applicantName);
        
        // Find reservations by name
        vector<ReservationNode*> userReservations = findReservationsByName(applicantName);
        
        if (userReservations.empty()) {
            cout << "\n  [RSYS: No reservations found for '" << applicantName << "' :C]" << endl;
            
            char tryAnother;
            cout << "\n  [Try another name? (Y/N)]: ";
            cin >> tryAnother;
            cin.ignore();
            
            if (tryAnother != 'Y' && tryAnother != 'y') {
                continueCancellation = false;
            }
            continue;
        }
        
        cout << "\n  [RSYS: Reservation Found: " << userReservations.size() << " :D]" << endl;
        
        // Display all reservations for this user
        for (int i = 0; i < userReservations.size(); i++) {
            displayReservationDetails(*userReservations[i], i + 1);
        }
        
        bool continueWithThisUser = true;
        while (continueWithThisUser) {
            int reservationChoice;
            bool validChoice = false;
            
            while (!validChoice) {
                cout << "\n  [Which reservation to cancel? (1-" << userReservations.size() << ")]: ";
                if (cin >> reservationChoice) {
                    if (reservationChoice >= 1 && reservationChoice <= userReservations.size()) {
                        validChoice = true;
                    }
                }
                if (!validChoice) {
                    cout << "  [Invalid choice. Please enter a number between 1-" << userReservations.size() << "]" << endl;
                    clearInput();
                }
            }
            cin.ignore();
            
            // Confirmation
            cout << "\n  [RSYS: CONFIRMATION]" << endl;
            char confirm;
            cout << "\n  [Confirm cancellation? (Y/N)]: ";
            cin >> confirm;
            cin.ignore();
            
            if (confirm == 'Y' || confirm == 'y') {
                // Get the reservation to be cancelled
                ReservationNode reservationToCancel = *userReservations[reservationChoice - 1];
                
                // Remove from linked list and update file
                if (removeReservationFromList(reservationChoice - 1, applicantName)) {
                    updateReservationFile();
                    
                    cout << "\n  ====================================================";
                    cout << "\n   ------ RESERVATION SUCCESSFULLY CANCELLED! -------";
                    cout << "\n   [APPLICANT DETAILS]";
                    cout << "\n   Name: " << reservationToCancel.name;
                    cout << "\n   Student Number: " << reservationToCancel.studentNum;
                    cout << "\n   Program: " << reservationToCancel.program;
                    cout << "\n   Section: " << reservationToCancel.section;
                    cout << "\n   -------------------------------------------------- ";
                    cout << "\n   [ACTIVITY DETAILS]";
                    cout << "\n   Activity Name: " << reservationToCancel.activityName;
                    cout << "\n   Date (MM/DD/YYYY): " << reservationToCancel.activityDate;
                    cout << "\n   [Start time (0AM/0PM)]: " << reservationToCancel.activityStart;
                    cout << "\n   [End Time (0AM/0PM)]: " << reservationToCancel.activityEnd;
                    cout << "\n   [No. of Participants]: " << reservationToCancel.numparticipants;
                    cout << "\n   -------------------------------------------------- ";
                    cout << "\n   [ROOM DETAILS]";
                    cout << "\n   Type of Room: " << reservationToCancel.roomType;
                    cout << "\n   Room Floor & Name: " << reservationToCancel.roomName;
                    cout << "\n   -------------------------------------------------- ";
                    cout << "\n  ====================================================" << endl;
                    
                    char cancelAnother;
                    cout << "\n  [Cancel another reservation? (Y/N)]: ";
                    cin >> cancelAnother;
                    cin.ignore();
                    
                    if (cancelAnother != 'Y' && cancelAnother != 'y') {
                        continueCancellation = false;
                        continueWithThisUser = false;
                    } else {
                        // Exit this user's session and ask for new applicant name
                        continueWithThisUser = false;
                    }
                } else {
                    cout << "\n  [Error: Failed to cancel reservation]" << endl;
                    continueWithThisUser = false;
                }
            } else {
                cout << "\n  [Cancellation aborted.]" << endl;
                // When cancellation is aborted, go back to asking for applicant name
                continueWithThisUser = false;
            }
        }
    }
}

void RoomReservation::joinWaitlist() {
    cout << "  ----------------------------------------------------" << endl;	
    cout << "  ****************************************************" << endl;
    cout << "\n  [RSYS: JOIN WAITLIST]" << endl;
    
    cin.ignore(); // Clear input buffer once at the beginning
    
    bool continueWaitlist = true;
    while (continueWaitlist) {
        string roomToWaitlist;
        cout << "\n  [Enter room floor & name to waitlist]: ";
        getline(cin, roomToWaitlist);
        
        // Check if room exists in the file
        string roomType, dateAvailability, timeAvailability;
        if (findRoomInFile(roomToWaitlist, roomType, dateAvailability, timeAvailability)) {
            cout << "\n  [RSYS: Room Found! :D]";
            cout << "\n  ====================================================";
            cout << "\n   ROOM DETAILS ------------------------------------- ";
            cout << "\n   Type of Room: " << roomType;
            cout << "\n   Room Floor & Name: " << roomToWaitlist;
            cout << "\n   Date Availability: \n   " << dateAvailability;
            cout << "\n   Time Availability: \n   " << timeAvailability;
            cout << "\n   -------------------------------------------------- ";
            cout << "\n  ====================================================" << endl;
        
            WaitlistNode newWaitlist;
        
        // Input Applicant Details
        cout << "\n  [RSYS: RESERVATION DETAILS]" << endl;
        cout << "\n  [Enter your name]: ";
        getline(cin, newWaitlist.name);
        
        cout << "  [Enter student number]: ";
        while (!(cin >> newWaitlist.studentNum)) {
            cout << "  [Invalid input. Enter student number]: ";
            clearInput();
        }
        cin.ignore();
        
        cout << "  [Enter program]: ";
        getline(cin, newWaitlist.program);
        
        cout << "  [Enter section]: ";
        getline(cin, newWaitlist.section);
        
        cout << "\n  ----------------------------------------------------" << endl;	
        
        // Input Activity Details
        cout << "\n  [RSYS: ACTIVITY DETAILS]" << endl;
        cout << "\n  [Enter activity name]: ";
        getline(cin, newWaitlist.activityName);
        
        cout << "  [Date (MM/DD/YYYY)]: ";
        getline(cin, newWaitlist.activityDate);
        
        cout << "  [Start time (0AM/0PM)]: ";
        getline(cin, newWaitlist.activityStart);
        
        cout << "  [End Time (0AM/0PM)]: ";
        getline(cin, newWaitlist.activityEnd);
        
        cout << "  [No. of Participants]: ";
        while (!(cin >> newWaitlist.numparticipants)) {
            cout << "  [Invalid input. Enter number of participants]: ";
            clearInput();
        }
        cin.ignore();
        
        cout << "\n  ----------------------------------------------------" << endl;	
        
        // Display Room Details (already entered room)
        cout << "\n  [RSYS: ROOM DETAILS]" << endl;
        cout << "\n  ====================================================";
        cout << "\n   ROOM DETAILS ------------------------------------- ";
        cout << "\n   Type of Room: " << roomType;
        cout << "\n   Room Floor & Name: " << roomToWaitlist;
        cout << "\n   Date Availability: \n   " << dateAvailability;
        cout << "\n   Time Availability: \n   " << timeAvailability;
        cout << "\n   -------------------------------------------------- ";
        cout << "\n  ====================================================" << endl;
        
        // Set room details for the waitlist entry
        newWaitlist.roomType = roomType;
        newWaitlist.roomName = roomToWaitlist;
        
        cout << "\n  ----------------------------------------------------" << endl;
        
        // Confirmation
        cout << "\n  [RSYS: CONFIRMATION]" << endl;
        char joinConfirm;
        cout << "\n  [Join waitlist? (Y/N)]: ";
        cin >> joinConfirm;
        cin.ignore();
        
        if (joinConfirm == 'Y' || joinConfirm == 'y') {
            // Add to queue and save to file
            enqueueWaitlist(newWaitlist);
            saveWaitlistToFile(newWaitlist);
            
            cout << "\n  ====================================================";
            cout << "\n   ----------- ADDED TO WAITLIST! ------------------- ";
            cout << "\n   Your waitlist request has been successfully added!";
            cout << "\n   Waitlist ID: WAIT" << newWaitlist.studentNum;
            cout << "\n   -------------------------------------------------- ";
            cout << "\n  ====================================================" << endl;
            
            // Display current waitlist
            displayWaitlistQueue();
            
            // Loop to view waitlist details by selecting entry number
            bool viewingDetails = true;
            while (viewingDetails) {
                char viewDetails;
                cout << "\n  [View waitlist applicant details? (Y/N)]: ";
                cin >> viewDetails;
                cin.ignore();
                
                if (viewDetails == 'Y' || viewDetails == 'y') {
                    // Count total waitlist entries
                    int totalEntries = 0;
                    WaitlistNode* current = front;
                    while (current != nullptr) {
                        totalEntries++;
                        current = current->next;
                    }
                    
                    if (totalEntries == 0) {
                        cout << "\n  [No waitlist entries available]" << endl;
                    } else {
                        int entryChoice;
                        bool validChoice = false;
                        
                        while (!validChoice) {
                            cout << "\n  [Enter waitlist entry number (1-" << totalEntries << ")]: ";
                            if (cin >> entryChoice) {
                                if (entryChoice >= 1 && entryChoice <= totalEntries) {
                                    validChoice = true;
                                }
                            }
                            if (!validChoice) {
                                cout << "  [Invalid choice. Please enter a number between 1-" << totalEntries << "]" << endl;
                                clearInput();
                            }
                        }
                        cin.ignore();
                        
                        // Find and display the selected waitlist entry
                        current = front;
                        for (int i = 1; i < entryChoice; i++) {
                            current = current->next;
                        }
                        
                        cout << "\n  ----------------------------------------------------" << endl;	
                        cout << "\n  [RSYS: WAITLIST ENTRY #" << entryChoice << " DETAILS]" << endl;
                        displayWaitlistDetails(*current, entryChoice);
                        
                        // Show waitlist again after viewing details
                        displayWaitlistQueue();
                    }
                } else {
                    // When user says N to viewing details, exit the viewing loop
                    viewingDetails = false;
                }
            }
        } else {
            cout << "\n  [Waitlist request cancelled.]" << endl;
        }
        
        } else {
            // Room not found
            cout << "\n  [RSYS: Room Not Found! :C]";
            cout << "\n  [The room '" << roomToWaitlist << "' does not exist in the system.]";
            cout << "\n  [Please check the room name and try again.]" << endl;
        }
        
        // Continue options
        char addAnother;
        cout << "\n  [Add another waitlist request? (Y/N)]: ";
        cin >> addAnother;
        cin.ignore();
        
        if (addAnother != 'Y' && addAnother != 'y') {
            continueWaitlist = false;
        }
    }
}

void RoomReservation::viewAvailableRooms() {
			cout << "  ----------------------------------------------------" << endl;	
			cout << "  ****************************************************" << endl;	
			cout << "\n  [RSYS: VIEW AVAILABLE ROOMS]" << endl;
            //Follow the design for outputs in "display.cpp"
}

void RoomReservation::viewMyReservations() {
            cout << "  ----------------------------------------------------" << endl;	
            cout << "  ****************************************************" << endl;	
            cout << "\n  [RSYS: VIEW MY RESERVATIONS]" << endl;
            cout << "\n  [Enter your name]: "; //Add cin (For user input)
            //Follow the design for outputs in "display.cpp"
}

void RoomReservation::viewAllRoomsAndReservations() {
			cout << "  ----------------------------------------------------" << endl;	
			cout << "  ****************************************************" << endl;	
			cout << "\n  [RSYS: VIEW ALL ROOMS/RESERVATIONS]" << endl;
			cout << "\n\t==============================" << endl;
			cout << "\t|        VIEW OPTIONS        |" << endl;
			cout << "\t==============================" << endl;
			cout << "\t|\t\t\t     |" << endl;
			cout << "\t|  [1] ROOM                  |" << endl;
			cout << "\t|  [2] RESERVATION           |" << endl;
			cout << "\t|  [3] CANCEL PROCESS        |" << endl; //After confirming to cancel, Return to Main Menu
			cout << "\t|\t\t\t     |" << endl;
			cout << "\t==============================" << endl;
			
			cout << "\n  [Enter your choice (1-3)]: "; //Add cin (For user input)
            //Follow the design for outputs in "display.cpp"
}

string RoomReservation::getRoomType() const {
    return roomType;
}

void RoomReservation::setRoomType(const string& type) {
    roomType = type;
}

string RoomReservation::getRoomName() const {
    return roomName;
}

void RoomReservation::setRoomName(const string& name) {
    roomName = name;
}

// Helper Methods Implementation

// Returns the time slot string based on the user's choice
string RoomReservation::getTimeSlot(int choice) {
    switch (choice) {
        case 1: return "8:00AM-12:00PM";
        case 2: return "8:00AM-5:00PM";
        case 3: return "12:00PM-5:00PM";
        case 4: return "12:00PM-7:00PM";
        default: return "UNKNOWN";
    }
}

void RoomReservation::loadReservationsFromFile() {
    ifstream file("reservations-data-list.txt");
    if (!file.is_open()) {
        return; // File doesn't exist yet, that's okay
    }
    
    string line;
    ReservationNode temp;
    int lineCount = 0;
    
    while (getline(file, line)) {
        if (line.empty()) continue;
        
        switch (lineCount % 11) {
            case 0: temp.name = line; break;
            case 1: temp.studentNum = stoi(line); break;
            case 2: temp.program = line; break;
            case 3: temp.section = line; break;
            case 4: temp.activityName = line; break;
            case 5: temp.activityDate = line; break;
            case 6: temp.activityStart = line; break;
            case 7: temp.activityEnd = line; break;
            case 8: temp.numparticipants = stoi(line); break;
            case 9: temp.roomType = line; break;
            case 10: 
                temp.roomName = line;
                addReservationToList(temp);
                break;
        }
        lineCount++;
    }
    file.close();
}

void RoomReservation::saveReservationToFile(const ReservationNode& reservation) {
    ofstream file("reservations-data-list.txt", ios::app);
    if (file.is_open()) {
        file << reservation.name << endl;
        file << reservation.studentNum << endl;
        file << reservation.program << endl;
        file << reservation.section << endl;
        file << reservation.activityName << endl;
        file << reservation.activityDate << endl;
        file << reservation.activityStart << endl;
        file << reservation.activityEnd << endl;
        file << reservation.numparticipants << endl;
        file << reservation.roomType << endl;
        file << reservation.roomName << endl;
        file << endl; // Empty line to separate records
        file.close();
    }
}

void RoomReservation::addReservationToList(const ReservationNode& reservation) {
    ReservationNode* newNode = new ReservationNode(reservation);
    
    if (head == nullptr) {
        head = newNode;
    } else {
        ReservationNode* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void RoomReservation::clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

string RoomReservation::getRoomTypeString(int choice) {
    switch (choice) {
        case 1: return "CLASSROOM";
        case 2: return "ACTIVITY/EVENT ROOM";
        default: return "UNKNOWN";
    }
}

vector<ReservationNode*> RoomReservation::findReservationsByName(const string& name) {
    vector<ReservationNode*> foundReservations;
    ReservationNode* current = head;
    
    while (current != nullptr) {
        if (current->name == name) {
            foundReservations.push_back(current);
        }
        current = current->next;
    }
    
    return foundReservations;
}

void RoomReservation::displayReservationDetails(const ReservationNode& reservation, int index) {
    cout << "\n  [RESERVATION #" << index << "]:";
    cout << "\n  ====================================================";
    cout << "\n   RESERVATION DETAILS ------------------------------";
    cout << "\n   [APPLICANT DETAILS]";
    cout << "\n   Name: " << reservation.name;
    cout << "\n   Student Number: " << reservation.studentNum;
    cout << "\n   Program: " << reservation.program;
    cout << "\n   Section: " << reservation.section;
    cout << "\n   -------------------------------------------------- ";
    cout << "\n   [ACTIVITY DETAILS]";
    cout << "\n   Activity Name: " << reservation.activityName;
    cout << "\n   Date (MM/DD/YYYY): " << reservation.activityDate;
    cout << "\n   [Start time (0AM/0PM)]: " << reservation.activityStart;
    cout << "\n   [End Time (0AM/0PM)]: " << reservation.activityEnd;
    cout << "\n   [No. of Participants]: " << reservation.numparticipants;
    cout << "\n   -------------------------------------------------- ";
    cout << "\n   [ROOM DETAILS]";
    cout << "\n   Type of Room: " << reservation.roomType;
    cout << "\n   Room Floor & Name: " << reservation.roomName;
    cout << "\n   -------------------------------------------------- ";
    cout << "\n  ====================================================" << endl;
}

bool RoomReservation::removeReservationFromList(int index, const string& name) {
    vector<ReservationNode*> userReservations = findReservationsByName(name);
    
    if (index < 0 || index >= userReservations.size()) {
        return false;
    }
    
    ReservationNode* nodeToDelete = userReservations[index];
    
    // If it's the head node
    if (head == nodeToDelete) {
        head = head->next;
        delete nodeToDelete;
        return true;
    }
    
    // Find the previous node
    ReservationNode* current = head;
    while (current != nullptr && current->next != nodeToDelete) {
        current = current->next;
    }
    
    if (current != nullptr) {
        current->next = nodeToDelete->next;
        delete nodeToDelete;
        return true;
    }
    
    return false;
}

void RoomReservation::updateReservationFile() {
    ofstream file("reservations-data-list.txt");
    if (!file.is_open()) {
        return;
    }
    
    ReservationNode* current = head;
    while (current != nullptr) {
        file << current->name << endl;
        file << current->studentNum << endl;
        file << current->program << endl;
        file << current->section << endl;
        file << current->activityName << endl;
        file << current->activityDate << endl;
        file << current->activityStart << endl;
        file << current->activityEnd << endl;
        file << current->numparticipants << endl;
        file << current->roomType << endl;
        file << current->roomName << endl;
        file << endl; // Empty line to separate records
        current = current->next;
    }
    
    file.close();
}

// Queue operations for waitlist
void RoomReservation::loadWaitlistFromFile() {
    ifstream file("waitlist-data.txt");
    if (!file.is_open()) {
        return; // File doesn't exist yet, that's okay
    }
    
    string line;
    WaitlistNode temp;
    int lineCount = 0;
    
    while (getline(file, line)) {
        if (line.empty()) continue;
        
        switch (lineCount % 11) {
            case 0: temp.name = line; break;
            case 1: temp.studentNum = stoi(line); break;
            case 2: temp.program = line; break;
            case 3: temp.section = line; break;
            case 4: temp.activityName = line; break;
            case 5: temp.activityDate = line; break;
            case 6: temp.activityStart = line; break;
            case 7: temp.activityEnd = line; break;
            case 8: temp.numparticipants = stoi(line); break;
            case 9: temp.roomType = line; break;
            case 10: 
                temp.roomName = line;
                enqueueWaitlist(temp);
                break;
        }
        lineCount++;
    }
    file.close();
}

void RoomReservation::saveWaitlistToFile(const WaitlistNode& waitlist) {
    ofstream file("waitlist-data.txt", ios::app);
    if (file.is_open()) {
        file << waitlist.name << endl;
        file << waitlist.studentNum << endl;
        file << waitlist.program << endl;
        file << waitlist.section << endl;
        file << waitlist.activityName << endl;
        file << waitlist.activityDate << endl;
        file << waitlist.activityStart << endl;
        file << waitlist.activityEnd << endl;
        file << waitlist.numparticipants << endl;
        file << waitlist.roomType << endl;
        file << waitlist.roomName << endl;
        file << endl; // Empty line to separate records
        file.close();
    }
}

void RoomReservation::enqueueWaitlist(const WaitlistNode& waitlist) {
    WaitlistNode* newNode = new WaitlistNode(waitlist);
    
    // If queue is empty
    if (rear == nullptr) {
        front = rear = newNode;
    } else {
        // Add to rear of queue
        rear->next = newNode;
        rear = newNode;
    }
}

void RoomReservation::displayWaitlistQueue() {
    cout << "\n  ====================================================";
    cout << "\n   CURRENTLY ON WAITLIST ---------------------------- ";
    
    WaitlistNode* current = front;
    int position = 1;
    
    while (current != nullptr) {
        cout << "\n   " << position << ". " << current->name << " - " << current->roomName;
        current = current->next;
        position++;
    }
    
    if (position == 1) {
        cout << "\n   No one is currently on the waitlist.";
    }
    
    cout << "\n   -------------------------------------------------- ";
    cout << "\n  ====================================================" << endl;
}

void RoomReservation::displayWaitlistDetails(const WaitlistNode& waitlist, int index) {
    cout << "\n  [RESERVATION #" << index << "]:";
    cout << "\n  ====================================================";
    cout << "\n   RESERVATION DETAILS ------------------------------";
    cout << "\n   [APPLICANT DETAILS]";
    cout << "\n   Name: " << waitlist.name;
    cout << "\n   Student Number: " << waitlist.studentNum;
    cout << "\n   Program: " << waitlist.program;
    cout << "\n   Section: " << waitlist.section;
    cout << "\n   -------------------------------------------------- ";
    cout << "\n   [ACTIVITY DETAILS]";
    cout << "\n   Activity Name: " << waitlist.activityName;
    cout << "\n   Date (MM/DD/YYYY): " << waitlist.activityDate;
    cout << "\n   [Start time (0AM/0PM)]: " << waitlist.activityStart;
    cout << "\n   [End Time (0AM/0PM)]: " << waitlist.activityEnd;
    cout << "\n   [No. of Participants]: " << waitlist.numparticipants;
    cout << "\n   -------------------------------------------------- ";
    cout << "\n   [ROOM DETAILS]";
    cout << "\n   Type of Room: " << waitlist.roomType;
    cout << "\n   Room Floor & Name: " << waitlist.roomName;
    cout << "\n   -------------------------------------------------- ";
    cout << "\n  ====================================================" << endl;
}

vector<WaitlistNode*> RoomReservation::findWaitlistByName(const string& name) {
    vector<WaitlistNode*> foundWaitlists;
    WaitlistNode* current = front;
    
    while (current != nullptr) {
        if (current->name == name) {
            foundWaitlists.push_back(current);
        }
        current = current->next;
    }
    
    return foundWaitlists;
}

void RoomReservation::updateWaitlistFile() {
    ofstream file("waitlist-data.txt");
    if (!file.is_open()) {
        return;
    }
    
    WaitlistNode* current = front;
    while (current != nullptr) {
        file << current->name << endl;
        file << current->studentNum << endl;
        file << current->program << endl;
        file << current->section << endl;
        file << current->activityName << endl;
        file << current->activityDate << endl;
        file << current->activityStart << endl;
        file << current->activityEnd << endl;
        file << current->numparticipants << endl;
        file << current->roomType << endl;
        file << current->roomName << endl;
        file << endl; // Empty line to separate records
        current = current->next;
    }
    
    file.close();
}

// Room validation function
bool RoomReservation::findRoomInFile(const string& roomName, string& roomType, string& dateAvailability, string& timeAvailability) {
    ifstream file("rooms-data-list.txt");
    if (!file.is_open()) {
        return false; // File doesn't exist
    }
    
    string line;
    int lineCount = 0;
    string currentRoomType, currentRoomName, currentDateAvailability, currentTimeAvailability;
    
    while (getline(file, line)) {
        if (line.empty()) {
            lineCount = 0; // Reset for next room entry
            continue;
        }
        
        switch (lineCount % 4) {
            case 0: // Room Type
                currentRoomType = line;
                break;
            case 1: // Room Name
                currentRoomName = line;
                break;
            case 2: // Date Availability
                currentDateAvailability = line;
                break;
            case 3: // Time Availability
                currentTimeAvailability = line;
                // Check if this is the room we're looking for
                if (currentRoomName == roomName) {
                    roomType = currentRoomType;
                    dateAvailability = currentDateAvailability;
                    timeAvailability = currentTimeAvailability;
                    file.close();
                    return true;
                }
                break;
        }
        lineCount++;
    }
    
    file.close();
    return false; // Room not found
}

// Display available classrooms from the file
void RoomReservation::displayAvailableClassrooms() {
    ifstream file("rooms-data-list.txt");
    if (!file.is_open()) {
        cout << "\n  [ERROR: Cannot open rooms data file]" << endl;
        return;
    }
    
    cout << "\n  ====================================================";
    cout << "\n   AVAILABLE CLASSROOMS ----------------------------- ";
    
    string line;
    int lineCount = 0;
    string currentRoomType, currentRoomName, currentDateAvailability, currentTimeAvailability;
    int classroomCount = 0;
    
    while (getline(file, line)) {
        if (line.empty()) {
            lineCount = 0; // Reset for next room entry
            continue;
        }
        
        switch (lineCount % 4) {
            case 0: // Room Type
                currentRoomType = line;
                break;
            case 1: // Room Name
                currentRoomName = line;
                break;
            case 2: // Date Availability
                currentDateAvailability = line;
                break;
            case 3: // Time Availability
                currentTimeAvailability = line;
                // Display only classrooms that are not "TO BE ANNOUNCED"
                if (currentRoomType == "CLASSROOM" && 
                    currentDateAvailability != "TO BE ANNOUNCED" && 
                    currentTimeAvailability != "TO BE ANNOUNCED") {
                    classroomCount++;
                    cout << "\n   " << currentRoomName;
                    cout << "\n      Date Available: " << currentDateAvailability;
                    cout << "\n      Time Available: " << currentTimeAvailability;
                    cout << "\n      ----------------------------------------";
                }
                break;
        }
        lineCount++;
    }
    
    if (classroomCount == 0) {
        cout << "\n   No available classrooms found.";
    }
    
    cout << "\n   -------------------------------------------------- ";
    cout << "\n  ====================================================" << endl;
    
    file.close();
}

// Display available activity/event rooms from the file
void RoomReservation::displayAvailableActivityRooms() {
    ifstream file("rooms-data-list.txt");
    if (!file.is_open()) {
        cout << "\n  [ERROR: Cannot open rooms data file]" << endl;
        return;
    }
    
    cout << "\n  ====================================================";
    cout << "\n   AVAILABLE ACTIVITY/EVENT ROOMS ------------------- ";
    
    string line;
    int lineCount = 0;
    string currentRoomType, currentRoomName, currentDateAvailability, currentTimeAvailability;
    int activityRoomCount = 0;
    
    while (getline(file, line)) {
        if (line.empty()) {
            lineCount = 0; // Reset for next room entry
            continue;
        }
        
        switch (lineCount % 4) {
            case 0: // Room Type
                currentRoomType = line;
                break;
            case 1: // Room Name
                currentRoomName = line;
                break;
            case 2: // Date Availability
                currentDateAvailability = line;
                break;
            case 3: // Time Availability
                currentTimeAvailability = line;
                // Display only activity/event rooms that are not "TO BE ANNOUNCED"
                if (currentRoomType == "ACTIVITY/EVENT ROOM" && 
                    currentDateAvailability != "TO BE ANNOUNCED" && 
                    currentTimeAvailability != "TO BE ANNOUNCED") {
                    activityRoomCount++;
                    cout << "\n   " << currentRoomName;
                    cout << "\n      Date Available: " << currentDateAvailability;
                    cout << "\n      Time Available: " << currentTimeAvailability;
                    cout << "\n      ----------------------------------------";
                }
                break;
        }
        lineCount++;
    }
    
    if (activityRoomCount == 0) {
        cout << "\n   No available activity/event rooms found.";
    }
    
    cout << "\n   -------------------------------------------------- ";
    cout << "\n  ====================================================" << endl;
    
    file.close();
}

// Display all available rooms (both classrooms and activity/event rooms)
void RoomReservation::displayAllAvailableRooms() {
    ifstream file("rooms-data-list.txt");
    if (!file.is_open()) {
        cout << "\n  [ERROR: Cannot open rooms data file]" << endl;
        return;
    }
    
    cout << "\n  ====================================================";
    cout << "\n   ALL AVAILABLE ROOMS ------------------------------ ";
    
    string line;
    int lineCount = 0;
    string currentRoomType, currentRoomName, currentDateAvailability, currentTimeAvailability;
    int roomCount = 0;
    
    while (getline(file, line)) {
        if (line.empty()) {
            lineCount = 0; // Reset for next room entry
            continue;
        }
        
        switch (lineCount % 4) {
            case 0: // Room Type
                currentRoomType = line;
                break;
            case 1: // Room Name
                currentRoomName = line;
                break;
            case 2: // Date Availability
                currentDateAvailability = line;
                break;
            case 3: // Time Availability
                currentTimeAvailability = line;
                // Display all rooms that are not "TO BE ANNOUNCED"
                if (currentDateAvailability != "TO BE ANNOUNCED" && 
                    currentTimeAvailability != "TO BE ANNOUNCED") {
                    roomCount++;
                    cout << "\n   " << currentRoomName << " (" << currentRoomType << ")";
                    cout << "\n      Date Available: " << currentDateAvailability;
                    cout << "\n      Time Available: " << currentTimeAvailability;
                    cout << "\n      ----------------------------------------";
                }
                break;
        }
        lineCount++;
    }
    
    if (roomCount == 0) {
        cout << "\n   No available rooms found.";
    }
    
    cout << "\n   -------------------------------------------------- ";
    cout << "\n  ====================================================" << endl;
    
    file.close();
}

// Check if the activity date is compatible with room date availability
bool RoomReservation::isDateCompatible(const string& activityDate, const string& roomDateAvailability) {
    // If room date is "TO BE ANNOUNCED", it's not available
    if (roomDateAvailability == "TO BE ANNOUNCED") {
        return false;
    }
    
    // Handle multiple dates separated by commas
    if (roomDateAvailability.find(',') != string::npos) {
        // Split by comma and check each date
        stringstream ss(roomDateAvailability);
        string dateSlot;
        
        while (getline(ss, dateSlot, ',')) {
            // Remove leading/trailing spaces
            dateSlot.erase(0, dateSlot.find_first_not_of(" \t"));
            dateSlot.erase(dateSlot.find_last_not_of(" \t") + 1);
            
            if (dateSlot == activityDate) {
                return true; // If any date matches, it's compatible
            }
        }
        return false; // No date matched
    }
    
    // Single date comparison
    return (roomDateAvailability == activityDate);
}

// Check if the activity time is compatible with room time availability
bool RoomReservation::isTimeCompatible(const string& activityStart, const string& activityEnd, const string& roomTimeAvailability) {
    // If room time is "TO BE ANNOUNCED", it's not available
    if (roomTimeAvailability == "TO BE ANNOUNCED") {
        return false;
    }
    
    // Handle multiple time slots separated by commas
    if (roomTimeAvailability.find(',') != string::npos) {
        // Split by comma and check each time slot
        stringstream ss(roomTimeAvailability);
        string timeSlot;
        
        while (getline(ss, timeSlot, ',')) {
            // Remove leading/trailing spaces
            timeSlot.erase(0, timeSlot.find_first_not_of(" \t"));
            timeSlot.erase(timeSlot.find_last_not_of(" \t") + 1);
            
            if (isTimeCompatible(activityStart, activityEnd, timeSlot)) {
                return true; // If any slot matches, it's compatible
            }
        }
        return false; // No slot matched
    }
    
    // Extract room start and end times (assuming format like "8:00AM-12:00PM")
    size_t dashPos = roomTimeAvailability.find('-');
    if (dashPos == string::npos) {
        return false; // Invalid format
    }
    
    string roomStart = roomTimeAvailability.substr(0, dashPos);
    string roomEnd = roomTimeAvailability.substr(dashPos + 1);
    
    // Remove any spaces
    roomStart.erase(remove(roomStart.begin(), roomStart.end(), ' '), roomStart.end());
    roomEnd.erase(remove(roomEnd.begin(), roomEnd.end(), ' '), roomEnd.end());
    
    // Convert to 24-hour format for comparison
    auto convertTo24Hour = [](const string& time) -> int {
        try {
            // Handle formats like "8AM", "8:00AM", "12PM", "12:00PM"
            string timeStr = time;
            int hour = 0, minute = 0;
            
            // Find AM/PM
            bool isPM = (timeStr.find("PM") != string::npos);
            bool isAM = (timeStr.find("AM") != string::npos);
            
            if (!isPM && !isAM) return -1; // Invalid format
            
            // Remove AM/PM
            timeStr = timeStr.substr(0, timeStr.find(isPM ? "PM" : "AM"));
            
            // Parse hour and minute
            size_t colonPos = timeStr.find(':');
            if (colonPos != string::npos) {
                hour = stoi(timeStr.substr(0, colonPos));
                minute = stoi(timeStr.substr(colonPos + 1));
            } else {
                hour = stoi(timeStr);
                minute = 0;
            }
            
            // Convert to 24-hour format
            if (isPM && hour != 12) {
                hour += 12;
            } else if (isAM && hour == 12) {
                hour = 0;
            }
            
            return hour * 100 + minute; // Return as HHMM format for easy comparison
        } catch (...) {
            return -1; // Error in parsing
        }
    };
    
    int roomStartTime = convertTo24Hour(roomStart);
    int roomEndTime = convertTo24Hour(roomEnd);
    int activityStartTime = convertTo24Hour(activityStart);
    int activityEndTime = convertTo24Hour(activityEnd);
    
    // Check if parsing was successful
    if (roomStartTime == -1 || roomEndTime == -1 || activityStartTime == -1 || activityEndTime == -1) {
        return false;
    }
    
    // Check if activity time is within room availability
    return (activityStartTime >= roomStartTime && activityEndTime <= roomEndTime);
}

// Validate room selection and time compatibility
bool RoomReservation::validateRoomSelection(const string& roomName, const string& activityStart, 
                                           const string& activityEnd, string& roomType, 
                                           string& dateAvailability, string& timeAvailability) {
    // First check if room exists
    if (!findRoomInFile(roomName, roomType, dateAvailability, timeAvailability)) {
        cout << "\n  [ERROR: Room '" << roomName << "' not found in the system]" << endl;
        return false;
    }
    
    // Check if it's a classroom
    if (roomType != "CLASSROOM") {
        cout << "\n  [ERROR: '" << roomName << "' is not a classroom]" << endl;
        return false;
    }
    
    // Check if room has announced availability
    if (dateAvailability == "TO BE ANNOUNCED" || timeAvailability == "TO BE ANNOUNCED") {
        cout << "\n  [ERROR: Room '" << roomName << "' availability is not yet announced]" << endl;
        return false;
    }
    
    // Check time compatibility
    if (!isTimeCompatible(activityStart, activityEnd, timeAvailability)) {
        cout << "\n  [ERROR: Activity time (" << activityStart << " - " << activityEnd << ")]" << endl;
        cout << "  [does not match room availability (" << timeAvailability << ")]" << endl;
        return false;
    }
    
    return true;
}

// Validate room selection with date, time compatibility
bool RoomReservation::validateRoomSelectionWithDate(const string& roomName, const string& activityDate,
                                                   const string& activityStart, const string& activityEnd, 
                                                   string& roomType, string& dateAvailability, 
                                                   string& timeAvailability) {
    // First check if room exists
    if (!findRoomInFile(roomName, roomType, dateAvailability, timeAvailability)) {
        cout << "\n  [ERROR: Room '" << roomName << "' not found in the system]" << endl;
        return false;
    }
    
    // Check if room has announced availability
    if (dateAvailability == "TO BE ANNOUNCED" || timeAvailability == "TO BE ANNOUNCED") {
        cout << "\n  [ERROR: Room '" << roomName << "' availability is not yet announced]" << endl;
        return false;
    }
    
    // Check date compatibility
    if (!isDateCompatible(activityDate, dateAvailability)) {
        cout << "\n  [ERROR: Activity date (" << activityDate << ")]" << endl;
        cout << "  [does not match room date availability (" << dateAvailability << ")]" << endl;
        return false;
    }
    
    // Check time compatibility
    if (!isTimeCompatible(activityStart, activityEnd, timeAvailability)) {
        cout << "\n  [ERROR: Activity time (" << activityStart << " - " << activityEnd << ")]" << endl;
        cout << "  [does not match room time availability (" << timeAvailability << ")]" << endl;
        return false;
    }
    
    return true;
}
