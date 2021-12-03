// Seth Lunders
// September 13th, 2019
// Section 1
// Assignment 2

// -------- Comments --------

// Can do addition, subtraction, multiplication, and division. Division code checks for Divide by Zero
// Also checks to see if the operator is something the program can use (+,-,*,/)

// ------------ Program Start -------------

#include<iostream>
using namespace std;
int main()
{
	// -------------- Variable Declarations ------------------
	double firstNum;
	double secondNum;
	char operation = 0;
	double answer;
	// ------------- Get user input -------------------------
	cout << "This program is a simple calculator.  It can be used to do +,-,*, and /.\nFirst, enter in a number." << endl;
	cin >> firstNum;
	while ((operation != '+')&&(operation != '-')&&(operation != '*')&&(operation != '/')){
		cout << "+,-,*, or /?" << endl;
		cin >> operation;
	}
	cout << "Now enter the second number." << endl;
	cin >> secondNum;
	
	if (operation == '+'){	
		answer = firstNum + secondNum;
		cout << endl << answer << endl;
	} else if (operation == '-'){
		answer = firstNum - secondNum;
		cout << endl << answer << endl;
	} else if (operation == '*'){
		answer = firstNum * secondNum;
		cout << endl << answer << endl;
	} else if (operation == '/'){
		if(secondNum == 0) {
			cout << "Divide by Zero Error" << endl;
		} else {
			answer = firstNum / secondNum;
			cout << endl << answer << endl;
		}
	} else {
		cout << endl << "This calculation could not be performed by this program." << endl;
	}
}
