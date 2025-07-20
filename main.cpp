#include "RoomReservation.h"
#include <iostream>
#include <fstream>
#include <string>
#include <limits>
using namespace std;

int main(){
    int choice;
    RoomReservation roomReservation;

    while (true){
        roomReservation.displayMenu();
        string inputStr;
        cout << "  [RSYS]: Enter your choice (1-11): ";
        cin >> inputStr;
        // Only accept if inputStr is all digits, no spaces, no special characters
        bool isNumber = !inputStr.empty() && inputStr.find_first_not_of("0123456789") == string::npos && inputStr.find(' ') == string::npos;
        if (!isNumber) {
            cout << "\n\t==========================================" << endl;
            cout << "\t|              INVALID INPUT!            |" << endl;
            cout << "\t|     PLEASE ENTER VALID INPUTS ONLY!    |" << endl;
            cout << "\t|      (No spaces or special chars)      |" << endl;
            cout << "\t==========================================" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        choice = stoi(inputStr);
        if (choice < 1 || choice > 11) {
            cout << "\n\t==========================================" << endl;
            cout << "\t|              INVALID INPUT!            |" << endl;
            cout << "\t|     PLEASE ENTER VALID INPUTS ONLY!    |" << endl;
            cout << "\t==========================================" << endl;
            continue;
        }

        // Handle menu choices
        switch (choice) {
            case 1:
                roomReservation.searchRoom();
                break;
            case 2:
                roomReservation.reserveRoom();
                break;
            case 3:
                roomReservation.addRoom();
                break;
            case 4:
                roomReservation.editRoomOrReservation();
                break;
            case 5:
                roomReservation.deleteRoom();
                break;
            case 6:
                roomReservation.cancelReservation();
                break;
            case 7:
                roomReservation.joinWaitlist();
                break;
            case 8:
                roomReservation.viewAvailableRooms();
                break;
            case 9:
                roomReservation.viewMyReservations();
                break;
            case 10:
                roomReservation.viewAllRoomsAndReservations();
                break;
            case 11:
                cout << "\n\t==========================================" << endl;
                cout << "\t|          EXITING SYSTEM...             |" << endl;
                cout << "\t|          THANK YOU FOR USING!          |" << endl;
                cout << "\t==========================================" << endl;
                return 0;
            default:
                cout << "\n\t==========================================" << endl;
                cout << "\t|              INVALID INPUT!            |" << endl;
                cout << "\t|     PLEASE ENTER VALID INPUTS ONLY!    |" << endl;
                cout << "\t==========================================" << endl;
                break;
        }
    }

}

