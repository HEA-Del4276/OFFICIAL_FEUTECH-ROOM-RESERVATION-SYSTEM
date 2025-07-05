#include <iostream>
#include <string.h>
using namespace std;

int main(){
	string name, program, section, daterequested,
	activityname, activitydate, activitystart, activityend;
	int choice, studentnum, numofparticipants;
	
	
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
	cout << "  [RSYS]: Enter your choice (1-11): ";
	cin >> choice;
	cin.ignore();
	
	switch(choice){
		
		case 1: //SEARCH ROOM
			//1st Test Search Room: Found Available
			cout << "  ----------------------------------------------------" << endl;	
			cout << "  ****************************************************" << endl;			
			cout << "\n  [RSYS: SEARCH A ROOM]" << endl;
			cout << "\n  [Enter COMPLETE room name]: E501 CCSMA Project Room" << endl;
			cout << "\n  [RSYS: Room Found! :D]";
			cout << "\n  ====================================================";
			cout << "\n   ROOM DETAILS ------------------------------------- ";
			cout << "\n   Type of Room: CLASSROOM";
			cout << "\n   Room Floor & Name: F402";
			cout << "\n   Date Availability:";
			cout << "\n   06/21/2025, 06/22/2025, 06/30/2025";
			cout << "\n   Time Availability:";
			cout << "\n   8:00AM-12:00PM, 12:00PM-5:00PM";
			cout << "\n   -------------------------------------------------- ";
			cout << "\n  ====================================================" << endl;

			//2nd Test Search Room: Found Unavailable
			cout << "\n  [Enter another room? (Y/N)]: Y";
			cout << "\n  [Enter COMPLETE room name]: F1603 AVR" << endl;
			cout << "\n  [RSYS: Room Found! :D]";
			cout << "\n  ====================================================";
			cout << "\n   ROOM DETAILS ------------------------------------- ";
			cout << "\n   Type of Room: ACTIVITY/EVENT ROOM";
			cout << "\n   Room Floor & Name: E502 Conference Room 1";
			cout << "\n   Date Availability: TO BE ANNOUNCED";
			cout << "\n   Time Availability: TO BE ANNOUNCED";
			cout << "\n   -------------------------------------------------- ";
			cout << "\n  ====================================================" << endl;
			
			//3rd Test Search Room: Not Found
			cout << "\n  [Enter another room? (Y/N)]: Y";
			cout << "\n  [Enter COMPLETE room name]: F1603" << endl;
			cout << "\n  [RSYS: Room Not Found! :C]";

			cout << "\n  [Enter another room? (Y/N)]:";
			break;
			
		case 2: //RESERVE ROOM
			cout << "  ----------------------------------------------------" << endl;	
			cout << "  ****************************************************" << endl;	
			//Input Booker Details
			cout << "\n  [RSYS: APPLICANT DETAILS]" << endl;
			cout << "\n  [Enter your name]: HANNAH ELISHA";
			cin.ignore();
			cout << "  [Enter student number]: ";
			cin >> studentnum;
			cout << "  [Enter program]: ";
			cin >> program;
			cout << "  [Enter section]: ";
			cin >> section;	
			
			cout << "\n  ----------------------------------------------------" << endl;	
			
			//Input Activity Details
			cout << "\n  [RSYS: ACTIVITY DETAILS]" << endl;
			cout << "\n  [Enter activity name]: ARTA AWAKENING";
			cout << "\n  [Date (MM/DD/YYYY)]: 06/19/2025";
			cout << "\n  [Start time (0AM/0PM)]: 11AM";
			cout << "\n  [End Time (0AM/0PM)]: 1PM";
			cout << "\n  [No. of Participants]: 5" << endl;
			
			cout << "\n  ----------------------------------------------------" << endl;	

			//Input Reservation Details
			cout << "\n  [RSYS: ROOM DETAILS]" << endl;
			cout << "\n  [Type of Room]: CLASSROOM";
			cout << "\n  [Room Floor & Name]: F402";
			
			cout << "\n  ----------------------------------------------------" << endl;	
			break;
		
		case 3: //ADD ROOM
			//1st Test Search Room: Found Available
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
			
			cout << "\n  [Enter your choice (1-3)]: 1";
			cout << "\n  [Enter room floor/name]: E501 CCSMA Project Room" << endl;
			
			cout << "\n  ----------------------------------------------------" << endl;	
			cout << "\n  [RSYS: DATE AVAILIBILITY]" << endl;
			cout << "\n  [No. of availability?]: 3";
			cout << "\n  [Enter dates (MM/DD/YYYY)]";
			cout << "\n  [DATE #1]: 06/21/2025";
			cout << "\n  [DATE #2]: 06/22/2025";
			cout << "\n  [DATE #3]: 06/30/2025" << endl;
			
			cout << "\n  ----------------------------------------------------" << endl;	
			cout << "\n  [RSYS: TIME AVAILIBILITY]" << endl;
			cout << "\n  [Hours of reservation (1-4)]: 2" << endl;

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

			cout << "\n  [No. of availability? (1-4)]: 2";
			cout << "\n  [TIME #1]: 1";
			cout << "\n  [TIME #2]: 3" << endl;
			cout << "\n  [TIME SELECTED]";
			cout << "\n  8:00AM-12:00PM, 12:00PM-5:00PM" << endl;
			
			cout << "\n  ====================================================";
			cout << "\n   ROOM DETAILS ------------------------------------- ";
			cout << "\n   Type of Room: CLASSROOM";
			cout << "\n   Room Floor & Name: F402";
			cout << "\n   Date Availability:";
			cout << "\n   06/21/2025, 06/22/2025, 06/30/2025";
			cout << "\n   Time Availability:";
			cout << "\n   8:00AM-12:00PM, 12:00PM-5:00PM";
			cout << "\n   -------------------------------------------------- ";
			cout << "\n  ====================================================" << endl;
			
			cout << "\n  [RSYS: CONFIRMATION]" << endl;
			cout << "\n  [Confirm room details? (Y/N)]: Y" << endl;
			
			cout << "\n  ====================================================";
			cout << "\n   ---------------- NEW ROOM ADDED! ----------------- ";
			cout << "\n   Type of Room: CLASSROOM";
			cout << "\n   Room Floor & Name: F402";
			cout << "\n   Date Availability:";
			cout << "\n   06/21/2025, 06/22/2025, 06/30/2025";
			cout << "\n   Time Availability:";
			cout << "\n   8:00AM-12:00PM, 12:00PM-5:00PM";
			cout << "\n   -------------------------------------------------- ";
			cout << "\n  ====================================================" << endl;

			//Put new room details in file
			
			cout << "\n  [Enter another room? (Y/N)]: N" << endl;

		break;
		
		case 4: //EDIT ROOM/RESERVATION
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
			
			cout << "\n  [Enter your choice (1-3)]: 1" << endl;
			
			//EDIT ROOM PROCESS=========================================================
			cout << "\n  ----------------------------------------------------" << endl;	
			cout << "\n  [RSYS: EDIT ROOM]" << endl;
			cout << "\n  [Enter COMPLETE room name]: F402" << endl;
			cout << "\n  [RSYS: Room Found! :D]";
			cout << "\n  ====================================================";
			cout << "\n   ROOM DETAILS ------------------------------------- ";
			cout << "\n   Type of Room: CLASSROOM";
			cout << "\n   Room Floor & Name: F402";
			cout << "\n   Date Availability:";
			cout << "\n   06/21/2025, 06/22/2025, 06/30/2025";
			cout << "\n   Time Availability:";
			cout << "\n   8:00AM-12:00PM, 12:00PM-5:00PM";
			cout << "\n   -------------------------------------------------- ";
			cout << "\n  ====================================================" << endl;
			
			cout << "\n\t==============================" << endl;
			cout << "\t|     EDIT ROOM OPTIONS      |" << endl;
			cout << "\t==============================" << endl;
			cout << "\t|\t\t\t     |" << endl;
			cout << "\t|  [1] TYPE OF ROOM          |" << endl;
			cout << "\t|  [2] ROOM FLOOR & NAME     |" << endl;
			cout << "\t|  [3] DATE AVAILABILITY     |" << endl;
			cout << "\t|  [4] TIME AVAILABILITY     |" << endl;
			cout << "\t|  [5] CANCEL PROCESS        |" << endl; //After confirming to cancel, Return to Main Menu
			cout << "\t|\t\t\t     |" << endl;
			cout << "\t==============================" << endl;
			
			cout << "\n  [Select action (1-5)]: 1" << endl;
			
			cout << "\n  ----------------------------------------------------" << endl;	
			cout << "\n  [RSYS: EDIT ROOM - TYPE OF ROOM]" << endl;
			cout << "\n\t==============================" << endl;
			cout << "\t|        TYPE OF ROOM        |" << endl;
			cout << "\t==============================" << endl;
			cout << "\t|\t\t\t     |" << endl;
			cout << "\t|  [1] CLASSROOM             |" << endl;
			cout << "\t|  [2] ACTIVITY/EVENT ROOM   |" << endl;
			cout << "\t|  [3] CANCEL PROCESS        |" << endl;  //After confirming to cancel, Return to Main Menu
			cout << "\t|\t\t\t     |" << endl;
			cout << "\t==============================" << endl;
			
			cout << "\n  [Enter your choice (1-3)]: 2" << endl;
			
			cout << "\n  ====================================================";
			cout << "\n   ------------- ROOM DETAILS UPDATED! -------------- ";
			cout << "\n   Type of Room: ACTIVITY/EVENT ROOM";
			cout << "\n   Room Floor & Name: F402";
			cout << "\n   Date Availability:";
			cout << "\n   06/21/2025, 06/22/2025, 06/30/2025";
			cout << "\n   Time Availability:";
			cout << "\n   8:00AM-12:00PM, 12:00PM-5:00PM";
			cout << "\n   -------------------------------------------------- ";
			cout << "\n  ====================================================" << endl;

			cout << "\n  [RSYS: CONFIRMATION]" << endl;
			cout << "\n  [Confirm updated room details? (Y/N)]: N";
			cout << "\n  [Update another detail? (Y/N)]: N";
			cout << "\n  [Confirm updated room details? (Y/N)]: Y"; //Update room details in file too
			cout << "\n  [Update another detail? (Y/N)]: Y" << endl;
			
			cout << "\n  ----------------------------------------------------" << endl;	
			cout << "\n\t==============================" << endl;
			cout << "\t|     EDIT ROOM OPTIONS      |" << endl;
			cout << "\t==============================" << endl;
			cout << "\t|\t\t\t     |" << endl;
			cout << "\t|  [1] TYPE OF ROOM          |" << endl;
			cout << "\t|  [2] ROOM FLOOR & NAME     |" << endl;
			cout << "\t|  [3] DATE AVAILABILITY     |" << endl;
			cout << "\t|  [4] TIME AVAILABILITY     |" << endl;
			cout << "\t|  [5] CANCEL PROCESS        |" << endl; //After confirming to cancel, Return to Main Menu
			cout << "\t|\t\t\t     |" << endl;
			cout << "\t==============================" << endl;
			
			cout << "\n  [Select action (1-5)]: 2" << endl;
			
			cout << "\n  ----------------------------------------------------" << endl;	
			cout << "\n  [RSYS: EDIT ROOM - ROOM FLOOR & NAME]" << endl;
			cout << "\n  [Enter new complete room name]: E506 Discussion Room 1" << endl;
			
			cout << "\n  ====================================================";
			cout << "\n   ------------- ROOM DETAILS UPDATED! -------------- ";
			cout << "\n   Type of Room: ACTIVITY/EVENT ROOM";
			cout << "\n   Room Floor & Name: E506 Discussion Room 1";
			cout << "\n   Date Availability:";
			cout << "\n   06/21/2025, 06/22/2025, 06/30/2025";
			cout << "\n   Time Availability:";
			cout << "\n   8:00AM-12:00PM, 12:00PM-5:00PM";
			cout << "\n   -------------------------------------------------- ";
			cout << "\n  ====================================================" << endl;
		
			cout << "\n  [RSYS: CONFIRMATION]" << endl;
			cout << "\n  [Confirm updated room details? (Y/N)]: N";
			cout << "\n  [Update another detail? (Y/N)]: N";
			cout << "\n  [Confirm updated room details? (Y/N)]: Y"; //Update room details in file too
			cout << "\n  [Update another detail? (Y/N)]: Y" << endl;

			cout << "\n  ----------------------------------------------------" << endl;	
			cout << "\n\t==============================" << endl;
			cout << "\t|     EDIT ROOM OPTIONS      |" << endl;
			cout << "\t==============================" << endl;
			cout << "\t|\t\t\t     |" << endl;
			cout << "\t|  [1] TYPE OF ROOM          |" << endl;
			cout << "\t|  [2] ROOM FLOOR & NAME     |" << endl;
			cout << "\t|  [3] DATE AVAILABILITY     |" << endl;
			cout << "\t|  [4] TIME AVAILABILITY     |" << endl;
			cout << "\t|  [5] CANCEL PROCESS        |" << endl; //After confirming to cancel, Return to Main Menu
			cout << "\t|\t\t\t     |" << endl;
			cout << "\t==============================" << endl;
			
			cout << "\n  [Select action (1-5)]: 3" << endl;
			
			cout << "\n  ----------------------------------------------------" << endl;	
			cout << "\n  [RSYS: EDIT A ROOM - DATE AVAILIBILITY]" << endl;
			cout << "\n  [No. of availability?]: 3";
			cout << "\n  [Enter dates (MM/DD/YYYY)]";
			cout << "\n  [DATE #1]: 06/29/2025";
			cout << "\n  [DATE #2]: 07/11/2025";
			cout << "\n  [DATE #3]: 07/20/2025" << endl;
			
			cout << "\n  ====================================================";
			cout << "\n   ------------- ROOM DETAILS UPDATED! -------------- ";
			cout << "\n   Type of Room: ACTIVITY/EVENT ROOM";
			cout << "\n   Room Floor & Name: E506 Discussion Room 1";
			cout << "\n   Date Availability:";
			cout << "\n   06/29/2025, 07/11/2025, 07/20/2025";
			cout << "\n   Time Availability:";
			cout << "\n   8:00AM-12:00PM, 12:00PM-5:00PM";
			cout << "\n   -------------------------------------------------- ";
			cout << "\n  ====================================================" << endl;
		
			cout << "\n  [RSYS: CONFIRMATION]" << endl;
			cout << "\n  [Confirm updated room details? (Y/N)]: N";
			cout << "\n  [Update another detail? (Y/N)]: N";
			cout << "\n  [Confirm updated room details? (Y/N)]: Y"; //Update room details in file too
			cout << "\n  [Update another detail? (Y/N)]: Y" << endl;
			
			cout << "\n  ----------------------------------------------------" << endl;	
			cout << "\n\t==============================" << endl;
			cout << "\t|     EDIT ROOM OPTIONS      |" << endl;
			cout << "\t==============================" << endl;
			cout << "\t|\t\t\t     |" << endl;
			cout << "\t|  [1] TYPE OF ROOM          |" << endl;
			cout << "\t|  [2] ROOM FLOOR & NAME     |" << endl;
			cout << "\t|  [3] DATE AVAILABILITY     |" << endl;
			cout << "\t|  [4] TIME AVAILABILITY     |" << endl;
			cout << "\t|  [5] CANCEL PROCESS        |" << endl; //After confirming to cancel, Return to Main Menu
			cout << "\t|\t\t\t     |" << endl;
			cout << "\t==============================" << endl;
			
			cout << "\n  [Select action (1-5)]: 3" << endl;
			
			cout << "\n  ----------------------------------------------------" << endl;	
			cout << "\n  [RSYS: TIME AVAILIBILITY]" << endl;
			cout << "\n  [No. of availability? (1-4)]: 2" << endl;

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

			cout << "\n  [Hours of reservation (1-4)]: 2";
			cout << "\n  [TIME #1]: 2";
			cout << "\n  [TIME #2]: 4" << endl;
			cout << "\n  [TIME SELECTED]";
			cout << "\n  8:00AM-5:00PM, 12:00PM-7:00PM" << endl;
			
			cout << "\n  ====================================================";
			cout << "\n   ------------- ROOM DETAILS UPDATED! -------------- ";
			cout << "\n   Type of Room: ACTIVITY/EVENT ROOM";
			cout << "\n   Room Floor & Name: E506 Discussion Room 1";
			cout << "\n   Date Availability:";
			cout << "\n   06/29/2025, 07/11/2025, 07/20/2025";
			cout << "\n   Time Availability:";
			cout << "\n   8:00AM-5:00PM, 12:00PM-7:00PM";
			cout << "\n   -------------------------------------------------- ";
			cout << "\n  ====================================================" << endl;
			
			cout << "\n  [RSYS: CONFIRMATION]" << endl;
			cout << "\n  [Confirm updated room details? (Y/N)]: N";
			cout << "\n  [Update another detail? (Y/N)]: N";
			cout << "\n  [Confirm updated room details? (Y/N)]: Y"; //Update room details in file too
			cout << "\n  [Update another detail? (Y/N)]: N" << endl;

			cout << "\n  ****************************************************" << endl;			
			cout << "\n  ----------------------------------------------------" << endl;	
			cout << "\n  [RSYS: EDIT A ROOM/RESERVATION]" << endl;
			cout << "\n\t==============================" << endl;
			cout << "\t|        EDIT OPTIONS        |" << endl;
			cout << "\t==============================" << endl;
			cout << "\t|\t\t\t     |" << endl;
			cout << "\t|  [1] ROOM                  |" << endl;
			cout << "\t|  [2] RESERVATION           |" << endl;
			cout << "\t|  [3] CANCEL PROCESS        |" << endl; //After confirming to cancel, Return to Main Menu
			cout << "\t|\t\t\t     |" << endl;
			cout << "\t==============================" << endl;
			
			cout << "\n  [Select action (1-3)]: 2" << endl;
			
			//EDIT RESERVATION PROCESS=========================================================	
					
			cout << "\n  ----------------------------------------------------" << endl;
			cout << "\n  [RSYS: EDIT RESERVATION]" << endl;
			cout << "\n  [Enter applicant's name]: HANNAH ELISHA" << endl;
			cout << "\n  [RSYS: Reservation found: 1 :D]";
			cout << "\n  ====================================================";
			cout << "\n   RESERVATION DETAILS ------------------------------";
			cout << "\n   [APPLICANT DETAILS]";
			cout << "\n   Name: HANNAH ELISHA";
			cout << "\n   Student Number: " << studentnum;
			cout << "\n   Program: " << program;
			cout << "\n   Section: " << section;
			cout << "\n   -------------------------------------------------- ";
			cout << "\n   [ACTIVITY DETAILS]";
			cout << "\n   Activity Name: ARTA AWAKENING";
			cout << "\n   Date (MM/DD/YYYY): 06/19/2025";
			cout << "\n   [Start time (0AM/0PM)]: 11AM";
			cout << "\n   [End Time (0AM/0PM)]: 1PM";
			cout << "\n   [No. of Participants]: 5" << endl;
			cout << "\n   -------------------------------------------------- ";
			cout << "\n   [ROOM DETAILS]";
			cout << "\n   Type of Room: CLASSROOM";
			cout << "\n   Room Floor & Name: F402";
			cout << "\n   -------------------------------------------------- ";
			cout << "\n  ====================================================" << endl;

			//Input Updated Booker Details
			cout << "\n\t==============================" << endl;
			cout << "\t|  EDIT RESERVATION OPTIONS  |" << endl;
			cout << "\t==============================" << endl;
			cout << "\t|\t\t\t     |" << endl;
			cout << "\t|  [1] APPLICANT DETAILS     |" << endl;
			cout << "\t|  [2] ACTIVITY DETAILS      |" << endl;
			cout << "\t|  [3] ROOM DETAILS          |" << endl;
			cout << "\t|  [4] CANCEL PROCESS        |" << endl; //After confirming to cancel, Return to Main Menu
			cout << "\t|\t\t\t     |" << endl;
			cout << "\t==============================" << endl;
			
			cout << "\n  [Select action (1-4)]: 1" << endl;
			
			cout << "\n  ----------------------------------------------------" << endl;	
			cout << "\n  [RSYS: UPDATE APPLICANT DETAILS]" << endl;			
			cout << "\n  [Enter your name]: ALEXANDER HAMILTON";
			cout << "\n  [Enter student number]: 202410343";
			cout << "\n  [Enter program]: BCSAMA";
			cout << "\n  [Enter section]: TX03" << endl;
			
			cout << "\n  ====================================================";
			cout << "\n   ---------- RESERVATION DETAILS UPDATED! ----------";
			cout << "\n   [APPLICANT DETAILS]";
			cout << "\n   Name: ALEXANDER HAMILTON";
			cout << "\n   Student Number: 202410343";
			cout << "\n   Program: BCSAMA";
			cout << "\n   Section: TX03";
			cout << "\n   -------------------------------------------------- ";
			cout << "\n   [ACTIVITY DETAILS]";
			cout << "\n   Activity Name: ARTA AWAKENING";
			cout << "\n   Date (MM/DD/YYYY): 06/19/2025";
			cout << "\n   [Start time (0AM/0PM)]: 11AM";
			cout << "\n   [End Time (0AM/0PM)]: 1PM";
			cout << "\n   [No. of Participants]: 5";
			cout << "\n   -------------------------------------------------- ";
			cout << "\n   [ROOM DETAILS]";
			cout << "\n   Type of Room: CLASSROOM";
			cout << "\n   Room Floor & Name: F402";
			cout << "\n   -------------------------------------------------- ";
			cout << "\n  ====================================================" << endl;
			
			cout << "\n  [RSYS: CONFIRMATION]" << endl;
			cout << "\n  [Confirm updated room details? (Y/N)]: N";
			cout << "\n  [Update another detail? (Y/N)]: N";
			cout << "\n  [Confirm updated room details? (Y/N)]: Y" << endl; //Update room details in file too
			
			//Update Activity Details
			cout << "\n  ----------------------------------------------------" << endl;	
			cout << "\n\t==============================" << endl;
			cout << "\t|  EDIT RESERVATION OPTIONS  |" << endl;
			cout << "\t==============================" << endl;
			cout << "\t|\t\t\t     |" << endl;
			cout << "\t|  [1] APPLICANT DETAILS     |" << endl;
			cout << "\t|  [2] ACTIVITY DETAILS      |" << endl;
			cout << "\t|  [3] ROOM DETAILS          |" << endl;
			cout << "\t|  [4] CANCEL PROCESS        |" << endl; //After confirming to cancel, Return to Main Menu
			cout << "\t|\t\t\t     |" << endl;
			cout << "\t==============================" << endl;
			
			cout << "\n  [Select action (1-4)]: 2" << endl;
			
			cout << "\n  ----------------------------------------------------" << endl;	
			cout << "\n  [RSYS: UPDATE ACTIVITY DETAILS]" << endl;
			cout << "\n  [Enter activity name]: PROJECT WAKENING";
			cout << "\n  [Date (MM/DD/YYYY)]: 07/20/2025";
			cout << "\n  [Start time (0AM/0PM)]: 8AM";
			cout << "\n  [End Time (0AM/0PM)]: 5PM";
			cout << "\n  [No. of Participants]: 10" << endl;
			
			cout << "\n  ====================================================";
			cout << "\n   ---------- RESERVATION DETAILS UPDATED! ----------";
			cout << "\n   [APPLICANT DETAILS]";
			cout << "\n   Name: ALEXANDER HAMILTON";
			cout << "\n   Student Number: 202410343";
			cout << "\n   Program: BCSAMA";
			cout << "\n   Section: TX03";
			cout << "\n   -------------------------------------------------- ";
			cout << "\n   [ACTIVITY DETAILS]";
			cout << "\n   Activity Name: PROJECT WAKENING";
			cout << "\n   Date (MM/DD/YYYY): 07/20/2025";
			cout << "\n   [Start time (0AM/0PM)]: 8AM";
			cout << "\n   [End Time (0AM/0PM)]: 5PM";
			cout << "\n   [No. of Participants]: 5";
			cout << "\n   -------------------------------------------------- ";
			cout << "\n   [ROOM DETAILS]";
			cout << "\n   Type of Room: CLASSROOM";
			cout << "\n   Room Floor & Name: F402";
			cout << "\n   -------------------------------------------------- ";
			cout << "\n  ====================================================" << endl;
			
			cout << "\n  [RSYS: CONFIRMATION]" << endl;
			cout << "\n  [Confirm updated room details? (Y/N)]: N";
			cout << "\n  [Update another detail? (Y/N)]: N";
			cout << "\n  [Confirm updated room details? (Y/N)]: Y" << endl; //Update room details in file too

			//Input Room Details
			cout << "\n  ----------------------------------------------------" << endl;	
			cout << "\n\t==============================" << endl;
			cout << "\t|  EDIT RESERVATION OPTIONS  |" << endl;
			cout << "\t==============================" << endl;
			cout << "\t|\t\t\t     |" << endl;
			cout << "\t|  [1] APPLICANT DETAILS     |" << endl;
			cout << "\t|  [2] ACTIVITY DETAILS      |" << endl;
			cout << "\t|  [3] ROOM DETAILS          |" << endl;
			cout << "\t|  [4] CANCEL PROCESS        |" << endl; //After confirming to cancel, Return to Main Menu
			cout << "\t|\t\t\t     |" << endl;
			cout << "\t==============================" << endl;
			
			cout << "\n  [Select action (1-4)]: 3" << endl;
			
			cout << "\n  ----------------------------------------------------" << endl;	
			cout << "\n  [RSYS: UPDATE ROOM DETAILS]" << endl;
			cout << "\n\t==============================" << endl;
			cout << "\t|        TYPE OF ROOM        |" << endl;
			cout << "\t==============================" << endl;
			cout << "\t|\t\t\t     |" << endl;
			cout << "\t|  [1] CLASSROOM             |" << endl;
			cout << "\t|  [2] ACTIVITY/EVENT ROOM   |" << endl;
			cout << "\t|  [3] CANCEL PROCESS        |" << endl;  //After confirming to cancel, Return to Main Menu
			cout << "\t|\t\t\t     |" << endl;
			cout << "\t==============================" << endl;
			
			cout << "\n  [Enter your choice (1-3)]: 1" << endl;
			cout << "\n  [RSYS: TYPE OF ROOM]: CLASSROOM";
			cout << "\n  [Room Floor & Name]: F605" << endl;
					
			cout << "\n  ====================================================";
			cout << "\n   ---------- RESERVATION DETAILS UPDATED! ----------";
			cout << "\n   [APPLICANT DETAILS]";
			cout << "\n   Name: ALEXANDER HAMILTON";
			cout << "\n   Student Number: 202410343";
			cout << "\n   Program: BCSAMA";
			cout << "\n   Section: TX03";
			cout << "\n   -------------------------------------------------- ";
			cout << "\n   [ACTIVITY DETAILS]";
			cout << "\n   Activity Name: PROJECT WAKENING";
			cout << "\n   Date (MM/DD/YYYY): 07/20/2025";
			cout << "\n   [Start time (0AM/0PM)]: 8AM";
			cout << "\n   [End Time (0AM/0PM)]: 5PM";
			cout << "\n   [No. of Participants]: 5";
			cout << "\n   -------------------------------------------------- ";
			cout << "\n   [ROOM DETAILS]";
			cout << "\n   Type of Room: CLASSROOM";
			cout << "\n   Room Floor & Name: F405";
			cout << "\n   -------------------------------------------------- ";
			cout << "\n  ====================================================" << endl;

			cout << "\n  [RSYS: CONFIRMATION]" << endl;
			cout << "\n  [Confirm updated room details? (Y/N)]: N";
			cout << "\n  [Update another detail? (Y/N)]: N";
			cout << "\n  [Confirm updated room details? (Y/N)]: Y"; //Update room details in file too
			cout << "\n  [Update another detail? (Y/N)]: N" << endl; //Return to main menu
		break;
		
		case 5: //Delete Room
			//1st Test Delete Room: Room Found
			cout << "  ----------------------------------------------------" << endl;	
			cout << "  ****************************************************" << endl;	
			cout << "\n  [RSYS: DELETE ROOM]" << endl;
			cout << "\n  [Enter COMPLETE room name]: E501 CCSMA Project Room" << endl;
			cout << "\n  [RSYS: Room Found! :D]";
			cout << "\n  ====================================================";
			cout << "\n   ROOM DETAILS ------------------------------------- ";
			cout << "\n   Type of Room: CLASSROOM";
			cout << "\n   Room Floor & Name: F402";
			cout << "\n   Date Availability:";
			cout << "\n   06/21/2025, 06/22/2025, 06/30/2025";
			cout << "\n   Time Availability:";
			cout << "\n   8:00AM-12:00PM, 12:00PM-5:00PM";
			cout << "\n   -------------------------------------------------- ";
			cout << "\n  ====================================================" << endl;

			cout << "\n  [RSYS: CONFIRMATION]" << endl;
			cout << "\n  [Confirm delete room? (Y/N)]: N";
			cout << "\n  [Delete another room? (Y/N)]: N";
			cout << "\n  [Confirm delete room? (Y/N)]: Y" << endl; //Delete the room in file
			
			cout << "\n  ====================================================";
			cout << "\n   ----------- ROOM SUCCESSFULLY DELETED! ----------- ";
			cout << "\n   Type of Room: CLASSROOM";
			cout << "\n   Room Floor & Name: F402";
			cout << "\n   Date Availability:";
			cout << "\n   06/21/2025, 06/22/2025, 06/30/2025";
			cout << "\n   Time Availability:";
			cout << "\n   8:00AM-12:00PM, 12:00PM-5:00PM";
			cout << "\n   -------------------------------------------------- ";
			cout << "\n  ====================================================" << endl;
			
			//2nd Test Search Room: Not Found
			cout << "\n  [Enter another room? (Y/N)]: Y";
			cout << "\n  [Enter COMPLETE room name]: F1603" << endl;
			cout << "\n  [RSYS: Room Not Found! :C]";

			cout << "\n  [Enter another room? (Y/N)]: N";
		break;
		
		case 6://Cancel Reservation
			cout << "  ----------------------------------------------------" << endl;	
			cout << "  ****************************************************" << endl;	
			cout << "\n  [RSYS: CANCEL RESERVATION]" << endl;
			cout << "\n  [Enter Applicant's Name]: HANNAH ELISHA" << endl;
			cout << "\n  [RSYS: Reservation Found: 2 :D]" << endl;
			
			//Reservation 1 Sample
			cout << "\n  [RESERVATION #1]:";
			cout << "\n  ====================================================";
			cout << "\n   RESERVATION DETAILS ------------------------------";
			cout << "\n   [APPLICANT DETAILS]";
			cout << "\n   Name: HANNAH ELISHA";
			cout << "\n   Student Number: 202410364";
			cout << "\n   Program: BSITWMA";
			cout << "\n   Section: TW01";
			cout << "\n   -------------------------------------------------- ";
			cout << "\n   [ACTIVITY DETAILS]";
			cout << "\n   Activity Name: ARTA AWAKENING";
			cout << "\n   Date (MM/DD/YYYY): 06/19/2025";
			cout << "\n   [Start time (0AM/0PM)]: 11AM";
			cout << "\n   [End Time (0AM/0PM)]: 1PM";
			cout << "\n   [No. of Participants]: 5" << endl;
			cout << "\n   -------------------------------------------------- ";
			cout << "\n   [ROOM DETAILS]";
			cout << "\n   Type of Room: CLASSROOM";
			cout << "\n   Room Floor & Name: F402";
			cout << "\n   -------------------------------------------------- ";
			cout << "\n  ====================================================" << endl;
			
			//Reservation 2 Sample
			cout << "\n  [RESERVATION #2]:";
			cout << "\n  ====================================================";
			cout << "\n   RESERVATION DETAILS ------------------------------";
			cout << "\n   [APPLICANT DETAILS]";
			cout << "\n   Name: HANNAH ELISHA";
			cout << "\n   Student Number: ";
			cout << "\n   Program: ";
			cout << "\n   Section: ";
			cout << "\n   -------------------------------------------------- ";
			cout << "\n   [ACTIVITY DETAILS]";
			cout << "\n   Activity Name: ARTA AWAKENING";
			cout << "\n   Date (MM/DD/YYYY): 06/19/2025";
			cout << "\n   [Start time (0AM/0PM)]: 11AM";
			cout << "\n   [End Time (0AM/0PM)]: 1PM";
			cout << "\n   [No. of Participants]: 5" << endl;
			cout << "\n   -------------------------------------------------- ";
			cout << "\n   [ROOM DETAILS]";
			cout << "\n   Type of Room: CLASSROOM";
			cout << "\n   Room Floor & Name: F605";
			cout << "\n   -------------------------------------------------- ";
			cout << "\n  ====================================================" << endl;
			
			cout << "\n  [Which reservation to cancel? (1-2)]: 1" << endl;
			cout << "\n  [RSYS: CONFIRMATION]" << endl;
			cout << "\n  [Confirm cancellation? (Y/N)]: N";
			cout << "\n  [Cancel another reservation? (Y/N)]: N";
			cout << "\n  [Confirm cancellation? (Y/N)]: Y" << endl; //Remove the reservation in file
			
			cout << "\n  ====================================================";
			cout << "\n   ------ RESERVATION SUCCESSFULLY CANCELLED! -------";
			cout << "\n   [APPLICANT DETAILS]";
			cout << "\n   Name: HANNAH ELISHA";
			cout << "\n   Student Number: 202410364";
			cout << "\n   Program: BSITWMA";
			cout << "\n   Section: TW01";
			cout << "\n   -------------------------------------------------- ";
			cout << "\n   [ACTIVITY DETAILS]";
			cout << "\n   Activity Name: ARTA AWAKENING";
			cout << "\n   Date (MM/DD/YYYY): 06/19/2025";
			cout << "\n   [Start time (0AM/0PM)]: 11AM";
			cout << "\n   [End Time (0AM/0PM)]: 1PM";
			cout << "\n   [No. of Participants]: 5";
			cout << "\n   -------------------------------------------------- ";
			cout << "\n   [ROOM DETAILS]";
			cout << "\n   Type of Room: CLASSROOM";
			cout << "\n   Room Floor & Name: F402";
			cout << "\n   -------------------------------------------------- ";
			cout << "\n  ====================================================" << endl;
			cout << "\n  [Cancel another reservation? (Y/N)]: N" << endl; //Return to Main Menu

		break;
		
		case 7: //Join Waitlist
			cout << "  ----------------------------------------------------" << endl;	
			cout << "  ****************************************************" << endl;
			//Input Booker Details
			cout << "\n  [RSYS: JOIN WAITLIST]" << endl;
			cout << "\n  [Enter room floor & name to waitlist]: F402" << endl;
			cout << "\n  [RSYS: Room Found! :D]";
			cout << "\n  ====================================================";
			cout << "\n   ROOM DETAILS ------------------------------------- ";
			cout << "\n   Type of Room: ACTIVITY/EVENT ROOM";
			cout << "\n   Room Floor & Name: E502 Conference Room 1";
			cout << "\n   Date Availability: TO BE ANNOUNCED";
			cout << "\n   Time Availability: TO BE ANNOUNCED";
			cout << "\n   -------------------------------------------------- ";
			cout << "\n  ====================================================" << endl;
		
			cout << "\n  [RSYS: RESERVATION DETAILS]" << endl;			
			cout << "\n  [Enter your name]: HANNAH ELISHA";
			cout << "\n  [Enter student number]: 202410432";
			cout << "\n  [Enter program]: BSCA";
			cout << "\n  [Enter section]: TX03";
			cout << "\n  ----------------------------------------------------";	
			//Input Activity Details
			cout << "\n  [RSYS: ACTIVITY DETAILS]" << endl;
			cout << "\n  [Enter activity name]: ARTA AWAKENING";
			cout << "\n  [Date (MM/DD/YYYY)]: 06/19/2025";
			cout << "\n  [Start time (0AM/0PM)]: 11AM";
			cout << "\n  [End Time (0AM/0PM)]: 1PM";
			cout << "\n  [No. of Participants]: 5";
			cout << "\n  ----------------------------------------------------";	
			//Input Reservation Details
			cout << "\n  [RSYS: ROOM DETAILS]" << endl;
			cout << "\n  [Type of Room]: CLASSROOM";
			cout << "\n  [Room Floor & Name]: F402";
			cout << "\n  ----------------------------------------------------" << endl;
			//Confirmation
			cout << "\n  [RSYS: CONFIRMATION]" << endl;
			cout << "\n  [Join waitlist? (Y/N)]: N";
			cout << "\n  [Select another room to waitlist? (Y/N)]: N";
			cout << "\n  [Return to main menu? (Y/N)]: N";
			cout << "\n  [Join waitlist? (Y/N)]: Y" << endl;
			//Display waitlist queue
			cout << "\n  ====================================================";
			cout << "\n   CURRENTLY ON WAITLIST ---------------------------- ";
			cout << "\n   1. HANNAH ELISHA - F402, F605";
			cout << "\n   2. ALEXANDER HAMILTON - F1202, F302";
			cout << "\n   -------------------------------------------------- ";
			cout << "\n  ====================================================" << endl;
			//Viewing waitlister's details
			cout << "\n  [View waitlist applicants details? (Y/N)]: Y";
			cout << "\n  [Enter waitlister's name]: HANNAH ELISHA" << endl;
			
			cout << "\n  ----------------------------------------------------" << endl;	
			cout << "\n  [RSYS: 2 RESERVATIONS OF]: HANNAH ELISHA" << endl;

			//Reservation 1 Sample
			cout << "\n  [RESERVATION #1]:";
			cout << "\n  ====================================================";
			cout << "\n   RESERVATION DETAILS ------------------------------";
			cout << "\n   [APPLICANT DETAILS]";
			cout << "\n   Name: ALEXANDER HAMILTON";
			cout << "\n   Student Number: 202410364";
			cout << "\n   Program: BSITWMA";
			cout << "\n   Section: TW01";
			cout << "\n   -------------------------------------------------- ";
			cout << "\n   [ACTIVITY DETAILS]";
			cout << "\n   Activity Name: ARTA AWAKENING";
			cout << "\n   Date (MM/DD/YYYY): 06/19/2025";
			cout << "\n   [Start time (0AM/0PM)]: 11AM";
			cout << "\n   [End Time (0AM/0PM)]: 1PM";
			cout << "\n   [No. of Participants]: 5";
			cout << "\n   -------------------------------------------------- ";
			cout << "\n   [ROOM DETAILS]";
			cout << "\n   Type of Room: CLASSROOM";
			cout << "\n   Room Floor & Name: F1202";
			cout << "\n   -------------------------------------------------- ";
			cout << "\n  ====================================================" << endl;
			
			//Reservation 2 Sample
			cout << "\n  [RESERVATION #2]:";
			cout << "\n  ====================================================";
			cout << "\n   RESERVATION DETAILS ------------------------------";
			cout << "\n   [APPLICANT DETAILS]";
			cout << "\n   Name: ALEXANDER HAMILTON";
			cout << "\n   Student Number: 202410364";
			cout << "\n   Program: BSITWMA";
			cout << "\n   Section: TX02";
			cout << "\n   -------------------------------------------------- ";
			cout << "\n   [ACTIVITY DETAILS]";
			cout << "\n   Activity Name: ARTA AWAKENING";
			cout << "\n   Date (MM/DD/YYYY): 06/19/2025";
			cout << "\n   [Start time (0AM/0PM)]: 11AM";
			cout << "\n   [End Time (0AM/0PM)]: 1PM";
			cout << "\n   [No. of Participants]: 5";
			cout << "\n   -------------------------------------------------- ";
			cout << "\n   [ROOM DETAILS]";
			cout << "\n   Type of Room: CLASSROOM";
			cout << "\n   Room Floor & Name: F302";
			cout << "\n   -------------------------------------------------- ";
			cout << "\n  ====================================================" << endl;

			//Confirmation
			cout << "\n  [RSYS: CONFIRMATION]" << endl;
			cout << "\n  [Add another? (Y/N)]: N";
			cout << "\n  [Select another room to waitlist? (Y/N)]: N";
			cout << "\n  [View other waitlisters? (Y/N)]: Y" << endl;
			//Display waitlist queue
			cout << "\n  ====================================================";
			cout << "\n   CURRENTLY ON WAITLIST ---------------------------- ";
			cout << "\n   1. HANNAH ELISHA - F402, F605";
			cout << "\n   2. ALEXANDER HAMILTON - F1202, F302";
			cout << "\n   -------------------------------------------------- ";
			cout << "\n  ====================================================" << endl;
			//Viewing waitlister's details
			cout << "\n  [View waitlist applicants details? (Y/N)]: N";
			cout << "\n  [Add another waitlist request? (Y/N)]: N";
			cout << "\n  [Return to main menu? (Y/N)]: Y" << endl;
			break;
		
		case 8: //View available rooms
		//Just display the available rooms
			cout << "  ----------------------------------------------------" << endl;	
			cout << "  ****************************************************" << endl;	
			cout << "\n  [RSYS: VIEW AVAILABLE ROOMS]" << endl;
			cout << "\n  [RSYS: Room Found: 2! :D]";

			cout << "\n  ====================================================";
			cout << "\n   ROOM DETAILS ------------------------------------- ";
			cout << "\n   Type of Room: CLASSROOM";
			cout << "\n   Room Floor & Name: F402";
			cout << "\n   Date Availability:";
			cout << "\n   06/21/2025, 06/22/2025, 06/30/2025";
			cout << "\n   Time Availability:";
			cout << "\n   8:00AM-12:00PM, 12:00PM-5:00PM";
			cout << "\n   -------------------------------------------------- ";
			cout << "\n  ====================================================" << endl;
			
			cout << "\n  ====================================================";
			cout << "\n   ROOM DETAILS ------------------------------------- ";
			cout << "\n   Type of Room: CLASSROOM";
			cout << "\n   Room Floor & Name: F402";
			cout << "\n   Date Availability:";
			cout << "\n   06/21/2025, 06/22/2025, 06/30/2025";
			cout << "\n   Time Availability:";
			cout << "\n   8:00AM-12:00PM, 12:00PM-5:00PM";
			cout << "\n   -------------------------------------------------- ";
			cout << "\n  ====================================================" << endl;
			
			//Return to main menu afterwards
			break;
			
		case 9: //View My Reservations
			cout << "  ----------------------------------------------------" << endl;	
			cout << "  ****************************************************" << endl;	
			cout << "\n  [RSYS: VIEW MY RESERVATIONS]" << endl;
			cout << "\n  [Enter your name]: HANNAH ELISHA" << endl;
			cout << "\n  [RSYS: Reservation found: 2 :D]" << endl;
			
			//Reservation 1 Sample
			cout << "\n  [RESERVATION #1]:";
			cout << "\n  ====================================================";
			cout << "\n   RESERVATION DETAILS ------------------------------";
			cout << "\n   [APPLICANT DETAILS]";
			cout << "\n   Name: HANNAH ELISHA";
			cout << "\n   Student Number: 202410364";
			cout << "\n   Program: BSITWMA";
			cout << "\n   Section: TW01";
			cout << "\n   -------------------------------------------------- ";
			cout << "\n   [ACTIVITY DETAILS]";
			cout << "\n   Activity Name: ARTA AWAKENING";
			cout << "\n   Date (MM/DD/YYYY): 06/19/2025";
			cout << "\n   [Start time (0AM/0PM)]: 11AM";
			cout << "\n   [End Time (0AM/0PM)]: 1PM";
			cout << "\n   [No. of Participants]: 5";
			cout << "\n   -------------------------------------------------- ";
			cout << "\n   [ROOM DETAILS]";
			cout << "\n   Type of Room: CLASSROOM";
			cout << "\n   Room Floor & Name: F402";
			cout << "\n   -------------------------------------------------- ";
			cout << "\n  ====================================================" << endl;
			
			//Reservation 2 Sample
			cout << "\n  [RESERVATION #2]:";
			cout << "\n  ====================================================";
			cout << "\n   RESERVATION DETAILS ------------------------------";
			cout << "\n   [APPLICANT DETAILS]";
			cout << "\n   Name: HANNAH ELISHA";
			cout << "\n   Student Number: 20251043";
			cout << "\n   Program: BCSA";
			cout << "\n   Section: TC03";
			cout << "\n   -------------------------------------------------- ";
			cout << "\n   [ACTIVITY DETAILS]";
			cout << "\n   Activity Name: ARTA AWAKENING";
			cout << "\n   Date (MM/DD/YYYY): 06/19/2025";
			cout << "\n   [Start time (0AM/0PM)]: 11AM";
			cout << "\n   [End Time (0AM/0PM)]: 1PM";
			cout << "\n   [No. of Participants]: 5";
			cout << "\n   -------------------------------------------------- ";
			cout << "\n   [ROOM DETAILS]";
			cout << "\n   Type of Room: CLASSROOM";
			cout << "\n   Room Floor & Name: F605";
			cout << "\n   -------------------------------------------------- ";
			cout << "\n  ====================================================" << endl;

			cout << "\n  [Enter another name? (Y/N)]: Y" << endl;
			cout << "\n  ----------------------------------------------------" << endl;	
			cout << "\n  [RSYS: VIEW MY RESERVATIONS]" << endl;
			cout << "\n  [Enter your name]: ZACK HOYT" << endl;
			cout << "\n  [RSYS: Reservation Found: 0 :C]" << endl;
			
			cout << "\n  [Enter another name? (Y/N)]: Y";
			cout << "\n  ----------------------------------------------------" << endl;	
			cout << "\n  [RSYS: VIEW MY RESERVATIONS]" << endl;
			cout << "\n  [Enter your name]: JEN TEODORO" << endl;
			
			cout << "\n\t==========================================" << endl;
			cout << "\t|          APPLICANT NOT FOUND!          |" << endl;
			cout << "\t|  PLEASER ENTER AN EXISTING APPLICANT   |" << endl;
			cout << "\t==========================================" << endl;

			cout << "\n  [Enter another name? (Y/N)]: N";
			cout << "\n  [Return to main menu? (Y/N)]: Y" << endl;

			//Returns to main menu
			break;
			
		case 10: //View All Rooms/Reservations
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
			
			cout << "\n  [Enter your choice (1-3)]: 1" << endl;
			
			cout << "\n  ----------------------------------------------------" << endl;	
			cout << "\n  [RSYS: VIEW ALL ROOMS]" << endl;
			
			cout << "\n  [RSYS: Room Found: 3! :D]";
			cout << "\n  ====================================================";
			cout << "\n   ROOM DETAILS ------------------------------------- ";
			cout << "\n   Type of Room: CLASSROOM";
			cout << "\n   Room Floor & Name: F402";
			cout << "\n   Date Availability:";
			cout << "\n   06/21/2025, 06/22/2025, 06/30/2025";
			cout << "\n   Time Availability:";
			cout << "\n   8:00AM-12:00PM, 12:00PM-5:00PM";
			cout << "\n   -------------------------------------------------- ";
			cout << "\n  ====================================================" << endl;

			cout << "\n  ====================================================";
			cout << "\n   ROOM DETAILS ------------------------------------- ";
			cout << "\n   Type of Room: ACTIVITY/EVENT ROOM";
			cout << "\n   Room Floor & Name: E502 Conference Room 1";
			cout << "\n   Date Availability: TO BE ANNOUNCED";
			cout << "\n   Time Availability: TO BE ANNOUNCED";
			cout << "\n   -------------------------------------------------- ";
			cout << "\n  ====================================================" << endl;

			cout << "\n  ====================================================";
			cout << "\n   ROOM DETAILS ------------------------------------- ";
			cout << "\n   Type of Room: ACTIVITY/EVENT ROOM";
			cout << "\n   Room Floor & Name: E506 Discussion Room 1";
			cout << "\n   Date Availability:";
			cout << "\n   06/29/2025, 07/11/2025, 07/20/2025";
			cout << "\n   Time Availability:";
			cout << "\n   8:00AM-5:00PM, 12:00PM-7:00PM";
			cout << "\n   -------------------------------------------------- ";
			cout << "\n  ====================================================" << endl;
			
			cout << "\n  ----------------------------------------------------" << endl;	
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
			
			cout << "\n  [Enter your choice (1-3)]: 2" << endl;

			cout << "\n  ----------------------------------------------------" << endl;	
			cout << "\n  [RSYS: VIEW ALL ROOMS]" << endl;
			
			cout << "\n  [RSYS: Reservation Found: 4! :D]" << endl;
			cout << "\n  [RESERVATION #1]:";
			cout << "\n  ====================================================";
			cout << "\n   RESERVATION DETAILS ------------------------------";
			cout << "\n   [APPLICANT DETAILS]";
			cout << "\n   Name: HANNAH ELISHA";
			cout << "\n   Student Number: 202410364";
			cout << "\n   Program: BSITWMA";
			cout << "\n   Section: TW01";
			cout << "\n   -------------------------------------------------- ";
			cout << "\n   [ACTIVITY DETAILS]";
			cout << "\n   Activity Name: ARTA AWAKENING";
			cout << "\n   Date (MM/DD/YYYY): 06/19/2025";
			cout << "\n   [Start time (0AM/0PM)]: 11AM";
			cout << "\n   [End Time (0AM/0PM)]: 1PM";
			cout << "\n   [No. of Participants]: 5";
			cout << "\n   -------------------------------------------------- ";
			cout << "\n   [ROOM DETAILS]";
			cout << "\n   Type of Room: CLASSROOM";
			cout << "\n   Room Floor & Name: F402";
			cout << "\n   -------------------------------------------------- ";
			cout << "\n  ====================================================" << endl;

			cout << "\n  [RESERVATION #2]:";
			cout << "\n  ====================================================";
			cout << "\n   RESERVATION DETAILS ------------------------------";
			cout << "\n   [APPLICANT DETAILS]";
			cout << "\n   Name: HANNAH ELISHA";
			cout << "\n   Student Number: 20251043";
			cout << "\n   Program: BCSA";
			cout << "\n   Section: TC03";
			cout << "\n   -------------------------------------------------- ";
			cout << "\n   [ACTIVITY DETAILS]";
			cout << "\n   Activity Name: ARTA AWAKENING";
			cout << "\n   Date (MM/DD/YYYY): 06/19/2025";
			cout << "\n   [Start time (0AM/0PM)]: 11AM";
			cout << "\n   [End Time (0AM/0PM)]: 1PM";
			cout << "\n   [No. of Participants]: 5";
			cout << "\n   -------------------------------------------------- ";
			cout << "\n   [ROOM DETAILS]";
			cout << "\n   Type of Room: CLASSROOM";
			cout << "\n   Room Floor & Name: F605";
			cout << "\n   -------------------------------------------------- ";
			cout << "\n  ====================================================" << endl;

			cout << "\n  [RESERVATION #3]:";
			cout << "\n  ====================================================";
			cout << "\n   RESERVATION DETAILS ------------------------------";
			cout << "\n   [APPLICANT DETAILS]";
			cout << "\n   Name: ALEXANDER HAMILTON";
			cout << "\n   Student Number: 202410364";
			cout << "\n   Program: BSITWMA";
			cout << "\n   Section: TW01";
			cout << "\n   -------------------------------------------------- ";
			cout << "\n   [ACTIVITY DETAILS]";
			cout << "\n   Activity Name: ARTA AWAKENING";
			cout << "\n   Date (MM/DD/YYYY): 06/19/2025";
			cout << "\n   [Start time (0AM/0PM)]: 11AM";
			cout << "\n   [End Time (0AM/0PM)]: 1PM";
			cout << "\n   [No. of Participants]: 5";
			cout << "\n   -------------------------------------------------- ";
			cout << "\n   [ROOM DETAILS]";
			cout << "\n   Type of Room: CLASSROOM";
			cout << "\n   Room Floor & Name: F1202";
			cout << "\n   -------------------------------------------------- ";
			cout << "\n  ====================================================" << endl;
			
			cout << "\n  [RESERVATION #4]:";
			cout << "\n  ====================================================";
			cout << "\n   RESERVATION DETAILS ------------------------------";
			cout << "\n   [APPLICANT DETAILS]";
			cout << "\n   Name: ALEXANDER HAMILTON";
			cout << "\n   Student Number: 202410364";
			cout << "\n   Program: BSITWMA";
			cout << "\n   Section: TX02";
			cout << "\n   -------------------------------------------------- ";
			cout << "\n   [ACTIVITY DETAILS]";
			cout << "\n   Activity Name: ARTA AWAKENING";
			cout << "\n   Date (MM/DD/YYYY): 06/19/2025";
			cout << "\n   [Start time (0AM/0PM)]: 11AM";
			cout << "\n   [End Time (0AM/0PM)]: 1PM";
			cout << "\n   [No. of Participants]: 5";
			cout << "\n   -------------------------------------------------- ";
			cout << "\n   [ROOM DETAILS]";
			cout << "\n   Type of Room: CLASSROOM";
			cout << "\n   Room Floor & Name: F302";
			cout << "\n   -------------------------------------------------- ";
			cout << "\n  ====================================================" << endl;
			
			cout << "\n  ----------------------------------------------------" << endl;	
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
			
			cout << "\n  [Enter your choice (1-3)]: 3" << endl; //Return to Main Menu
			break;
		
		case 11: //Exit System
			cout << "  ----------------------------------------------------" << endl;	
			cout << "  ****************************************************" << endl;
			cout << "\n  [RSYS: CONFIRMATION TO EXIT]" << endl;
			cout << "\n  [RSYS: All modifications will be saved, continue?]";
			cout << "\n  [Continue to exit the system? (Y/N)]: N";
			cout << "\n  [Return to Main Menu? (Y/N)]: N";
			cout << "\n  [RSYS: All modifications will be saved, continue?]";
			cout << "\n  [Continue to exit the system? (Y/N)]: Y";
			cout << "\n  ----------------------------------------------------" << endl;	
			
			cout << "\t==========================================" << endl;
			cout << "\t|             EXITING SYSTEM!            |" << endl;
			cout << "\t|     ALL MODIFICATIONS WILL BE SAVED    |" << endl;
			cout << "\t==========================================";
			break;
			
		default:
			cout << "\n\t==========================================" << endl;
			cout << "\t|              INVALID INPUT!            |" << endl;
			cout << "\t|     PLEASE ENTER VALID INPUTS ONLY!    |" << endl;
			cout << "\t==========================================" << endl;
		break;
			
	}

}



