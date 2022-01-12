// Seth Lunders
// Section 1
// Assignment 7
// 10/18/19

// Everything except the division seems to be working, I can't quite figure out what's wrong with it


#include <iostream>
using namespace std;

class fraction{
	private:
		int num;
		int den;
	public:
		fraction();
		fraction(int,int);
		void setNum(int);
		void setDen(int);
		void print();
		void printMixed();
		void printDecimal();
		fraction operator+(fraction);
		fraction operator-(fraction);
		fraction operator*(fraction);
		fraction operator/(fraction);
};

int main(){
	fraction f1(1,2), f2(2,3), f3(4,2), sum;
	cout << "Fraction 1: 1/2\n";
	f1.print();
	cout << "Fraction 2: 2/3\n";
	f2.print();
	cout << "Fraction 3: 4/2\n";
	f3.print();
	cout << "F1 + F2 = ";
	sum = f1+f2;
	sum.print();
	cout << "F1 + F2 Mixed: ";
	sum.printMixed();
	cout << "F1 + F2 Decimal: ";
	sum.printDecimal();
	cout << "F3 - F1 = ";
	sum = f1-f2;
	sum.print();
	cout << "F3 * F2 = ";
	sum = f1*f2;
	sum.print();
	cout << "F2 / F3 = ";
	sum = (f1/f2);
	sum.print();
}

fraction::fraction(){
	setNum(0);
	setDen(1);
}

fraction::fraction(int n, int d){
	setNum(n);
	setDen(d);
}

fraction fraction::operator+(fraction op) {
	fraction answer;
	answer.num = num*op.den + op.num*den;
	answer.den = den*op.den;
	return answer;
}

fraction fraction::operator-(fraction op) {
	fraction answer;
	answer.num = (num*op.den - op.num*den);
	answer.den = (den*op.den);
	return answer;
}

fraction fraction::operator*(fraction op) {
	fraction answer;
	answer.num = (num*op.num);
	answer.den = (den*op.den);
	return answer;
}

fraction fraction::operator/(fraction op) {
	fraction answer;
	answer.num = (num*op.den);
	answer.den = (den*op.num);
	return answer;
}


void fraction::setNum(int n){
	num = n;
}

void fraction::setDen(int d){
	if(d == 0){
		num = 0;
		den = 1;
	} else {
		den = d;
	}
}

void fraction::print(){
	cout << num << "/" << den << endl;
}

void fraction::printMixed(){
	int whole = num/den;
	int remainder = num % den;
	if(remainder != 0){
		cout << whole << " " << remainder << "/" << den << endl;
	} else {
		cout << whole << endl;
	}
}

void fraction::printDecimal(){
	double n = num;
	double d = den;
	cout << n/d << endl;
}
