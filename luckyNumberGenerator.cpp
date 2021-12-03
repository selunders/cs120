// Seth Lunders
// August 9th, 2019
// Section 1
// Assignment 1

// -------- Comments --------
/* I added two new variables, age and cupsWater. A cout asks how many glasses of water the person has drank that day,
   and if it is less than 5 cups, the program will add an additional cout that tells them to drink more water. */

// ------------ Program Start -------------

#include<iostream> // include a library
using namespace std;
int main()  // main() starts the program
{
	// -------------- Variable Declarations ------------------
 	int favorite;  // create a variable to store the favorite number
	int lucky;     // create a variable to store the lucky number
    int disliked;  // create a variable to store the disliked number
	int age;       // variable to store age number
	int cupsWater; // variable to store the estimated amount of water the use has drank so far today
	// ------------- Get user input -------------------------
	cout << "Enter your favorite number (no decimals): ";  // output
	cin >> favorite;  		// user input
	cout << "Enter a number you don't like (no decimals): ";
	cin >> disliked;
	cout << "Enter your age in years (no decimals): ";
	cin >> age;
	cout << "Enter about how many cups of water you have drank today (no decimals): ";
	cin >> cupsWater;
	lucky = ((favorite*disliked)+(age*cupsWater)) % 10;
	cout << endl << "Your secret, lucky number is: " << lucky << endl << endl;
	if(lucky < 0){  // conditional, values less than 0
		cout << "Try to be less negative." << endl;
	}
	if(lucky >= 0 && lucky < 5){ // 0 to 4 inclusive
		cout << "Think bigger!" << endl;
	}
	if(lucky >= 5 && lucky < 7){ // 5 to 6 inclusive
		cout << "Today you should embrace technology." << endl;
	}
        if(lucky == 7) {
		cout << "Today you should eat some Chick Fil-A" << endl;
	}
	if(lucky == 9){ // exactly 9
		cout << "Today is your lucky day!" << endl;
	}
	if(cupsWater < 5) {
		cout << "Also, drink more water!" << endl;
	}
	// ---------- Code to help the program exit "gracefully" -----
	cin.ignore();
 	cout << endl << "Press enter to quit." << endl << endl;
	cin.ignore();
	return 0;
}
