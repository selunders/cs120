#include<iostream>
#include<cstdlib>
using namespace std;

//	Modified a given file (http://www2.cs.uidaho.edu/~cs120/f19/code/pet.cpp) to add functions to the 'pet' class

class pet{
    private:
        string name;
        int hunger;
        int hygeine;
	int happy;
    public:
	pet();
	pet(int,int);
	void bathe();
        void play();
	void feed();
	void set_hygeine(int);
	void set_name();
        void set_hunger(int);
        void set_happy(int);
	int check_health();
        void print();
};

int rand();

int main(){
    pet pet1;
    int choice;
    int health_check;
    string name;
    do{
	pet1.print();
	cout << "What would you like to do with your pet?\n";
	cout << " Play (1) \n Feed (2) \n Bathe(3) \n Exit (0) \n";
	cin >> choice;
	switch(choice){
		case 1:
			pet1.play();
			break;
		case 2:
			pet1.feed();
			break;
		case 3:
			pet1.bathe();
			break;
		case 0:
			cout << "Come back soon!\n";
			break;
		default:
			break;
	}
	health_check = pet1.check_health();
    }while (choice != 0 && health_check != 1);
    cin.ignore();
    cout << "Press enter to exit." << endl;
    cin.ignore();
    return 0;
}

pet::pet(){
	set_hunger(50);
	set_happy(50);
	set_hygeine(50);
	set_name();
}


pet::pet(int hunger,int happy){
	set_hunger(hunger);
	set_happy(happy);
}

void pet::set_name(){
    cout << "What do you want to name your pet?\n";
    cin >> name;
    cout << endl;
}

void pet::set_hunger(int h){
    hunger = h;
}

void pet::set_happy(int h){
    happy = h;
}

void pet::set_hygeine(int h){
    hygeine = h;
}

void pet::print(){
    cout << name << " is: \n";

	switch(hunger){
		case 0 ... 30:
			cout << "Very full.\n";
			break;
		case 31 ... 70:
			cout << "Getting hungry.\n";
			break;
		case 71 ... 100:
			cout << "Starving.\n";
			break;
	}
	switch(happy){
		case 0 ... 30:
			cout << "Biting at you!\n";
			break;
		case 31 ... 70:
			cout << "Running around having fun.\n";
			break;
		case 71 ... 100:
			cout << "Smiling at you!.\n";
			break;
	}
	switch(hygeine){
		case 0 ... 30:
			cout << "Needs a bath.\n";
			break;
		case 31 ... 70:
			cout << "A bit dirty.\n";
			break;
		case 71 ... 100:
			cout << "Squeaky clean.\n";
			break;
	}
}



void pet::play(){
	cout << "You played with " << name << "." << endl;
	hygeine -= 10;
	hunger += 20;
	happy += 20;
}

void pet::feed(){
	cout << "You fed " << name << "." << endl;
	int random = rand() % 2;
	switch(random){
		case 0:
			cout << name << " didn't seem to like the food.\n";
			break;
		case 1: 
			cout << name << " loved the meal!\n";
			break;
		case 2:
			cout << name << " couldn't finish all of the the food.\n";
			break;
	}
	hunger -= 15;
	hygeine -= 5;
	happy += 5;
}

void pet::bathe(){
	if(hygeine < 85){
		hygeine += 15;
	} else {
		hygeine = 100;
	}
	hunger += 5;
	happy += 5;
}

int pet::check_health(){
	happy -= 10;
	if(hunger >= 100){
		cout << "\nYour pet has starved.\n";
		return 1;
	}
	if(happy <= 0){
		cout << "\nYour pet has died of a broken heart\n";
		return 1;
	}
	if(hygeine <= 0){
		cout << "\nYour pet got sick and died from not bathing for so long.\n";
		return 1;
	}
	if(hygeine >= 100){hygeine = 100;}
	if(hunger <= 0){hunger = 0;}
	if(happy >= 100){happy = 100;}
	return 0;
}
