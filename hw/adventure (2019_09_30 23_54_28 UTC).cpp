
// Seth Lunders
// Section 1
// Assignment 4
// September 30th, 2019

#include<iostream>
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
	static int keys_here = 1;
  //      water_level();
	if(lose == 1) {
		return 0;
	}
	cout << "You are in a brick room.\n";
	if(keys_here > 0){
		cout << "You find " << keys_here << " key(s).\n";
		player_keys += keys_here;
		keys_here = 0;
	}

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
	static int keys_here = 1;
//        water_level();
	if(lose == 1) {
		return 0;
	}
	cout << "You are in an icy room.\n";        
	if(keys_here > 0){
		cout << "You find " << keys_here << " key(s).\n";
		player_keys += keys_here;
		keys_here = 0;
	}

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
	static int keys_here = 1;
//        water_level();        
	if(lose == 1) {
		return 0;
	}
	cout << "You are in a room filled with houseplants.\n";
	if(keys_here > 0){
		cout << "You find " << keys_here << " key(s).\n";
		player_keys += keys_here;
		keys_here = 0;
	}

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
