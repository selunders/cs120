#include<iostream>
using namespace std;

double avg(double, double);

main(){
    int num1;
    int num2;
    int ave;
    cout << "Average two numbers\n"
    cout << "Num1\n";
    cin >> num1;
    cout << "Num2\n";
    cin >> num2;
    avg(num1, num2);
    cout << ave;
}

avg(double a, double b){
    double x = (a + b)/2.0;
    return x;
};