#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream file("reservations-data-list.txt");

    if (!file.is_open()) {
        cerr << "Error: Could not open file." << endl;
        return 1;
    }

    string line;
    while (getline(file, line)) {
        string name = line;
        string studentNumber, program, section;
        string activityName, date, startTime, endTime, participants;
        string roomType, roomName;

        getline(file, studentNumber);
        getline(file, program);
        getline(file, section);
        getline(file, activityName);
        getline(file, date);
        getline(file, startTime);
        getline(file, endTime);
        getline(file, participants);
        getline(file, roomType);
        getline(file, roomName);

        // Display in your format
        cout << "\n  ====================================================";
        cout << "\n   RESERVATION DETAILS ------------------------------";
        cout << "\n   [APPLICANT DETAILS]";
        cout << "\n   Name: " << name;
        cout << "\n   Student Number: " << studentNumber;
        cout << "\n   Program: " << program;
        cout << "\n   Section: " << section;
        cout << "\n   -------------------------------------------------- ";
        cout << "\n   [ACTIVITY DETAILS]";
        cout << "\n   Activity Name: " << activityName;
        cout << "\n   Date (MM/DD/YYYY): " << date;
        cout << "\n   [Start time (0AM/0PM)]: " << startTime;
        cout << "\n   [End Time (0AM/0PM)]: " << endTime;
        cout << "\n   [No. of Participants]: " << participants;
        cout << "\n   -------------------------------------------------- ";
        cout << "\n   [ROOM DETAILS]";
        cout << "\n   Type of Room: " << roomType;
        cout << "\n   Room Floor & Name: " << roomName;
        cout << "\n   -------------------------------------------------- ";
        cout << "\n  ====================================================" << endl;
    }

    file.close();
    return 0;
}
