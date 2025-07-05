#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string roomType, roomName, dateAvailability, timeAvailability;
    int roomChoice;
    int numDates, numTimes, timeChoice;
    vector<string> dateList;
    vector<string> selectedTimes;
    char confirm;

    // Time options menu
    string timeOptions[4] = {
        "8:00AM-12:00PM",
        "8:00AM-5:00PM",
        "12:00PM-5:00PM",
        "12:00PM-7:00PM"
    };

    ifstream roomFile("rooms-data-list.txt");

    if (!roomFile) {
        cout << "\n  [Error: Could not open rooms-data-list.txt]" << endl;
        return 1;
    }

    getline(roomFile, roomType);
    getline(roomFile, roomName);
    getline(roomFile, dateAvailability);
    getline(roomFile, timeAvailability);

    roomFile.close();

    // Display formatted output
    cout << "\n  ====================================================";
    cout << "\n   ROOM DETAILS ------------------------------------- ";
    cout << "\n   Type of Room: " << roomType;
    cout << "\n   Room Floor & Name: " << roomName;
    cout << "\n   Date Availability:";
    cout << "\n   " << dateAvailability;
    cout << "\n   Time Availability:";
    cout << "\n   " << timeAvailability;
    cout << "\n   -------------------------------------------------- ";


    cout << "  ----------------------------------------------------" << endl;	
	cout << "  ****************************************************" << endl;	
	cout << "\n  [RSYS: ENTER BOOK DETAILS]" << endl;
			
	cout << "\n\t==============================" << endl;
	cout << "\t|        TYPE OF ROOM        |" << endl;
	cout << "\t==============================" << endl;
	cout << "\t|\t\t\t     |" << endl;
	cout << "\t|  [1] CLASSROOM             |" << endl;
	cout << "\t|  [2] ACTIVITY/EVENT ROOM   |" << endl;
	cout << "\t|  [5] CANCEL PROCESS        |" << endl;  //After confirming to cancel, Return to Main Menu
	cout << "\t|\t\t\t     |" << endl;
	cout << "\t==============================" << endl;

    // Room type selection
    cout << "\n  [Enter your choice (1-3)]: ";
    cin >> roomChoice;
    cin.ignore();

    if (roomChoice == 1) roomType = "CLASSROOM";
    else if (roomChoice == 2) roomType = "ACTIVITY/EVENT ROOM";
    else {
        cout << "Cancelled or invalid choice." << endl;
        return 0;
    }

    // Room name
    cout << "  [Enter room floor/name]: ";
    getline(cin, roomName);

    // Dates
    cout << "\n  [No. of availability?]: ";
    cin >> numDates;
    cin.ignore();

    for (int i = 0; i < numDates; i++) {
        string date;
        cout << "  [DATE #" << (i + 1) << "]: ";
        getline(cin, date);
        dateList.push_back(date);
    }

    cout << "\n\t==============================" << endl;
	cout << "\t|       TIME AVAILABLE       |" << endl;
	cout << "\t==============================" << endl;
	cout << "\t|\t\t\t     |" << endl;
	cout << "\t|  [1] 8:00AM-12:00PM        |" << endl;
	cout << "\t|  [2] 8:00AM-5:00PM         |" << endl;
	cout << "\t|  [3] 12:00PM-5:00PM        |" << endl;
	cout << "\t|  [4] 12:00PM-7:00PM        |" << endl;
	cout << "\t|  [5] CANCEL PROCESS        |" << endl;  //After confirming to cancel, Return to Main Menu
	cout << "\t|\t\t\t     |" << endl;
	cout << "\t==============================" << endl;
    
    // Time slots
    cout << "\n  [No. of availability? (1-4)]: ";
    cin >> numTimes;

    for (int i = 0; i < numTimes; i++) {
        cout << "  [TIME #" << (i + 1) << "]: ";
        cin >> timeChoice;
        if (timeChoice >= 1 && timeChoice <= 4) {
            selectedTimes.push_back(timeOptions[timeChoice - 1]);
        } else {
            cout << "  Invalid time slot. Skipping..." << endl;
        }
    }

    // Confirmation
    cout << "\n  [Confirm room details? (Y/N)]: ";
    cin >> confirm;

    if (confirm == 'Y' || confirm == 'y') {
        ofstream outFile("rooms-data-list.txt", ios::app); // Append mode

        if (!outFile) {
            cerr << "Error opening file." << endl;
            return 1;
        }

        // Write room type
        outFile << roomType << endl;
        // Write room name
        outFile << roomName << endl;

        // Write date availability
        for (size_t i = 0; i < dateList.size(); i++) {
            outFile << dateList[i];
            if (i != dateList.size() - 1) outFile << ", ";
        }
        outFile << endl;
        
        // Write time availability
        for (size_t i = 0; i < selectedTimes.size(); i++) {
            outFile << selectedTimes[i];
            if (i != selectedTimes.size() - 1) outFile << ", ";
        }
        outFile << endl;
        outFile << endl;

        outFile.close();

        // Confirmation output
        cout << "\n  ====================================================";
        cout << "\n   ---------------- NEW ROOM ADDED! ----------------- ";
        cout << "\n   Type of Room: " << roomType;
        cout << "\n   Room Floor & Name: " << roomName;
        cout << "\n   Date Availability:";
        cout << "\n   ";
        for (size_t i = 0; i < dateList.size(); i++) {
            cout << dateList[i];
            if (i != dateList.size() - 1) cout << ", ";
        }
        cout << "\n   Time Availability:";
        cout << "\n   ";
        for (size_t i = 0; i < selectedTimes.size(); i++) {
            cout << selectedTimes[i];
            if (i != selectedTimes.size() - 1) cout << ", ";
        }
        cout << "\n   -------------------------------------------------- ";
        cout << "\n  ====================================================" << endl;
    } else {
        cout << "\n  Room not added. Returning to menu..." << endl;
    }

    return 0;
}
