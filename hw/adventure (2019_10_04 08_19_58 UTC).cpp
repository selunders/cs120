
// Seth Lunders
// Section 1
// Assignment 5
// Octover 5th, 2019

// Everything works, also added time.h to give the games a more random srand() seed;

#include<iostream>
#include<cstdlib>
#include<time.h>
using namespace std;


// prototypes
int room1();
int room2();
int room3();
int room4();
int room5();
int room6();
int room7();
int gameOver();
int menu(int,int);
int water_level();
void nim();
void math_game();

// global variables
int turn = 0;
int lose = 0;
int player_keys;

int main() {
	int current_room = 1;
  do{
	if(lose == 1){
		current_room = 0;
	}
	if((player_keys == 1)&&(lose != 1)){
		cout << endl << "You have " << player_keys << " key.\n";
	} else if(lose != 1){cout << endl << "You have " << player_keys << " keys.\n";
	}
	if(current_room != 0){
		switch(current_room){
			case 1:
				current_room = room1();
				water_level();
				break;
			case 2: current_room = room2();
				water_level();
				break;
			case 3: current_room = room3();
				water_level();
				break;
			case 4: current_room = room4();
				water_level();
				break;
			case 5: current_room = room5();
				water_level();
				break;
			case 6: current_room = room6();
				water_level();
				break;

			case 7: if(lose == 1){
					current_room = gameOver();
				} else {
					current_room = room7();
				}
				break;
			default:
				cout << "Room: " << current_room << " is undefined.\n";	
		}
	}
  } while(current_room != 0); // loop forever
}



// function definitions *************
int room1(){
	int choice;
//	water_level();
	if(lose == 1) {
		return 0;
	}
	cout << "You are in a dark room.\n";
	cout << "Exits are West(1) and North(2).\n";
	cout << "Which way do you go?  ";
	cin >> choice;
	switch(choice){
		case 1: return 2;
			break;
		case 2: return 3;
			break;
		default: return 1;
	}	
}

int room2(){
	int choice;
  //      water_level();
//	static int keys_here = 1;
	if(lose == 1) {
		return 0;
	}
	cout << "You are in a brick room.\n";
	math_game();

	cout << "There is an exit to the East(1).\n";
	cout << "which way do you go?  ";
	cin >> choice;
	if(choice == 1){
		return 1;
	}
	return 2;
}

int room3(){
	int choice;
	static int keys_here = 0;
    //    water_level();
	if(lose == 1) {
		return 0;
	}
	cout << "You are in a sandy room.\n";
	if(keys_here > 0){
		cout << "You find " << keys_here << " key(s).\n";
		player_keys += keys_here;
		keys_here = 0;
	}

	cout << "There is an exit to the South(1), West(2), and North(3).\n";
	cout << "which way do you go?  ";
	cin >> choice;
	switch(choice){
		case 1: return 1;
			break;
		case 2: return 4;
			break;
		case 3: return 6;
			break;
		default: return 2;
	}
}
int room4(){
	int choice;
//	static int keys_here = 1;
//        water_level();
	if(lose == 1) {
		return 0;
	}
	cout << "You are in an icy room.\n";
	math_game();        
//	if(keys_here > 0){
//		cout << "You find " << keys_here << " key(s).\n";
//		player_keys += keys_here;
//		keys_here = 0;
//	}

	cout << "There is an exit to the East(1) and North (2).\n";
	cout << "which way do you go?  ";
	cin >> choice;
		switch(choice){
		case 1: return 3;
			break;
		case 2: return 5;
			break;
		default: return 4;
	}

}
int room5(){
	int choice;
//        water_level();        
	if(lose == 1) {
		return 0;
	}
	cout << "You enter an aquarium room with tropical fish tanks on the walls.\n";
	nim();
	cout << "There is an exit to the South(1) and East(2).\n";
	cout << "which way do you go?  ";
	cin >> choice;
	switch(choice){
		case 1: return 4;
			break;
		case 2: return 6;
			break;
		default: return 5;
	}

}
int room6(){
	int choice;
	static int keys_here = 0;
  //      water_level();
        
	if(lose == 1) {
		return 0;
	}
	cout << "You are in a bright room.\n";
	if(keys_here > 0){
		cout << "You find " << keys_here << " key(s).\n";
		player_keys += keys_here;
		keys_here = 0;
	}

	cout << "There is an exit to the West(1), South(2), and East(3).\n";
	cout << "To the East(3) there is a door with three locks.\n";
	cout << "which way do you go?  ";
	cin >> choice;
	do{
		switch(choice){
			case 1: return 5;
				break;
			case 2: return 3;
				break;
			case 3: return 7;
				break;
			default: return 6;
		}
	}while((choice == 3)&&(player_keys != 3));	
}

int room7(){
	if(player_keys < 3){
		cout << "You don't have enough keys.\n";
		return 6;
	} else {
		cout << "You found the exit!\n";
	}
	return 0;
}

int gameOver(){
	cout << "You didn't make it out in time." << endl << endl << "Game Over";
	return 0;
}

int water_level(){
	switch(turn){
		case 0:
			cout << "You notice a trickle of water coming into the room.\n";
			break;
		case 1: 
			cout << "The water is starting to form puddles.\n";
			break;
		case 2: 
			cout << "The water is ankle-deep.\n";
			break;
		case 3: 
			cout << "The water is coming in faster now, it's up to your waist!\n";
			break;
		case 4: 
			cout << "The water is almost too deep to stand in.\n";
			break;
		case 5: 
			cout << "You have to start swimming, and the water is almost up to the ceiling.\n";
			break;
		case 6: 
			cout << "You take a deep breath and dive for a door.";
			break;
		case 7:
			cout << "You couldn't escape before the water filled up the room!\n";
			lose = 1;
			break;
		default:
			cout << "Error on line 118";	
	}
	turn += 1;	
}

int menu(int lower, int upper){
	int room_choice;
	cout << "What do you want to do?";
	do{
		cin >> room_choice;
		if ((room_choice < lower)||(room_choice > upper)){
			cout << "Choose a number from " << lower << " to " << upper << ".\n";
		}		
	}while((room_choice < lower)||(room_choice > upper));
}

void nim()             // main() starts the actual program 
{
   // ---------------- Variable declarations ---------------------
   int num_objects = 23; 
   int current_player = 1; 
   static int keys_here = 1;
   int move;
   int min_move = 1; 
   int max_move = 3;
   char play_again = 'y';
   // ----------- Beginning of the main game loop ----------------
   // -- Game setup --
    srand(time(NULL));
    cout << "You are challenged to a game of NIM by a dolphin." << endl;
    cout << "Win a key by making the dolphin take the last item!" << endl << endl;
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
	if(keys_here > 0){
		cout << "Congratulations, you won a key!\n" << endl;
		cout << "You found " << keys_here << " key(s).\n";
		player_keys += keys_here;
		keys_here = 0;
   	} else {
		cout << "Congratulations, you won!\n";
	}
	play_again = 'n';
   }

   if(current_player == 0){
	cout << "Sorry, you lost. Try again!\n" << endl;
   }
   while((play_again != 'y')&&(play_again != 'n')){
	cout << "Play again? (y/n)" << endl;
	cin >> play_again;
   }
   } while (play_again == 'y');
}

void math_game(){
	srand(time(NULL));
	static int keys_here = 2;
	if(keys_here > 0){
		cout << "You find " << keys_here << " key(s).\n";
		player_keys += 1;
		keys_here -= 1;
	}
	int num1 =  1 + rand() % 12;    // random computer move
	int num2 =  1 + rand() % 12;   // random computer move
	int answer = num1*num2;
	int player_answer = 170;
	cout << "There is a key in a locked box.\nTo open it you must find the right answer to this problem:\n";
	while(answer != player_answer){	
		cout << num1 << " * " << num2 << " = ";
		cin >> player_answer;
	}
	cout << "Correct! You opened the box and got a key!\n";
}
