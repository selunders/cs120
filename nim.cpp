// Seth Lunders
// Section 1
// September 20th, 2019
// Assignment 3

// Completed all the requirements, also the min and max should be able to change to anything without the game crashing
// i.e. if there was 1 item left but the min_move was 2, the min_move would change to 1
// Also, there's a 1/3 chance of commentary per turn

/*  The game of NIM */

#include<iostream>
#include<cstdlib>
using namespace std;
int main()         
{
   // ---------------- Variable declarations ---------------------
   int num_objects = 23; 
   int current_player = 1; 
   int move;
   int min_move = 1; 
   int max_move = 3;
   char play_again = 'y';
   // ----------- Beginning of the main game loop ----------------
   // -- Game setup --
 
    cout << "Welcome to NIM. During your turn, you may take anywhere from " << min_move << " to " << max_move << " items." << endl;
    cout << "Win this game by making the computer take the last item!" << endl << endl;
    do {
    	cout << endl << "How many items would you like to start with? (10 to 30)" << endl << endl;
    	cin >> num_objects;
		while(num_objects > 30 || num_objects < 10){
			cout << "Choose a number from 10 to 30" << endl << endl;
			cin >> num_objects;
		}
	
  	  // -- Game itself -- 
    do {
       if (current_player == 1) {    // conditional: if
	if (num_objects < min_move){
            cout << "Player 1 enter your move (1-" << max_move << "): ";  // output
            cin >> move;                 // input
            while (move < 1 || move > max_move){
               cout << "Illegal move. \nEnter a new move (1-" << max_move << "): ";
               cin >> move;
	    }
	} else {
            cout << "Player 1 enter your move (" << min_move << "-" << max_move << "): ";  // output
            cin >> move;                 // input
            while (move < min_move || move > max_move || move > num_objects){
               cout << "Illegal move. \nEnter a new move (" << min_move << "-" << max_move << "): ";
               cin >> move;
            }
	}
       } else {                          // else part of conditional
		do {                         // make sure move is legal
             		if (num_objects == 4){
				move = (min_move + 2);
			} else if (num_objects == 3){
				move = (min_move + 1);
			} else if (num_objects == 2){
				move = min_move;
			} else if (num_objects == 1){
				move = 1;	
			} else {
				move =  min_move + rand() % max_move;    // random computer move
			}
           	} while ((move < min_move || move > max_move || move > num_objects)&&(num_objects != 1));
            cout << "Computer removed " << move << endl;
       }
       num_objects = num_objects - move;  // implement the move
       for (int i = 0; i < num_objects; i++){
		cout << "*";
       }
       cout << endl;
       // Moves have 1/3 chance of having commentary using this if statement:
       if ((rand() % 3) == 1) {
       		if (num_objects > 30){
			cout << "It's anyone's game!" << endl;
		} else if ((num_objects > 20)&&(num_objects <= 30)){
			cout << "The next player is up!" << endl;
		} else if ((num_objects > 10)&&(num_objects <= 20)){
			cout << "It's too close to call!" << endl;
		} else if ((current_player == 1)&&(num_objects == 1)){
			cout << "I'm predicting you will win!" << endl;
		} else if ((current_player == 0)&&(num_objects == 1)){
			cout << "I'm predicting the computer will win!" << endl;
		}
       }
       if (num_objects != 1){
	       cout << endl << num_objects << " objects remaining.\n";
       } else {
	       cout << endl << num_objects << " object remaining.\n";	
       }
	current_player = (current_player + 1) % 2;  // switch players
   } while (num_objects > 0);                    
   // ------------  end of the game --------------------------
   
   if(current_player == 1){
	cout << "Congratulations, you won!\n" << endl;
	cout << "Play again? (y/n)" << endl;
   }

   if(current_player == 0){
	cout << "Sorry, you lost. Try again? (y/n)\n" << endl;
   }
   cin >> play_again;
   while((play_again != 'y')&&(play_again != 'n')){
	cout << "Play again? (y/n)" << endl;
	cin >> play_again;
   }
   } while (play_again == 'y');
}
