// Seth Lunders
// Section 1
// Assignment 8
// 10/25/19

// Everything works, added couts in a few of the functions to show they work.  Also made an attempt at the standard deviation formula, I think it works but I'm not 100% sure.
// Also used time in srand() to add a bit more randomness

#include<iostream>
#include<cstdlib>
#include<time.h>
#include<cmath>

using namespace std;

void generate(double[], int, double, int);
void print(double[], int, int);
double average(double[], int);
double min(double[], int);
double max(double[], int);
void addX(double[], int, double);
int num_less(double[], int);
int num_more(double[], int);
int num_less(double[], int, double);
double range(double[], int);
double stdDev(double[], int);


int main(){
	srand(time(NULL));
	double arr[100];
	generate(arr, 100, -10, 10);
	print(arr, 0, 100);
	average(arr, 100);
	min(arr, 100);
	max(arr, 100);
	num_less(arr, 100);
	num_more(arr, 100);
	num_less(arr, 100, 5);
	range(arr, 100);
	stdDev(arr, 100);
	addX(arr, 100, 2.5);
	print(arr, 0, 100);

}


void generate(double data[], int len, double min, int max){
	for(int i = 0; i < len; i++){
		data[i] = (rand()%(20*max+1)+(10*min))/10.0;
	}
}

void print(double data[], int min, int max){
	cout << endl;
	for(int i = min; i < max; i++){
		if(i < (max - 1)){
			cout << data[i] << ", ";
		} else {
			cout << data[i] << endl;
		}
	}
}

double average(double data[], int len){
	double sum = 0;
	for(int i = 0; i < len; i++){
		sum += data[i];
	}
	return (sum/len);
}

double min(double data[], int len){
	double min = 0;
	for(int i = 0; i < len; i++){
		if(data[i] < min){
			min = data[i];
		}
	}
	
//	cout << "Minimum is: " << min << endl;
	return min;
}

double max(double data[], int len){
	double max = 0;
	for(int i = 0; i < len; i++){
		if(data[i] > max){
			max = data[i];
		}
	}
	
//	cout << "Maximum is: " << max << endl;
	return max;
}

void addX(double data[], int len, double x){;
	for(int i = 0; i < len; i++){
		data[i] = data[i] + x;
	}
}

int num_less(double data[], int len){
	int count = 0;
	double ave = average(data, len);
	for(int i = 0; i < len; i++){
		if(data[i] < ave){
			count += 1;
		}
	}
	cout << "There are " << count << " values less than the average of " << ave << endl; 
	return count;
}

int num_less(double data[], int len, double threshhold){
	int count = 0;
	for(int i = 0; i < len; i++){
		if(data[i] < threshhold){
			count += 1;
		}
	}
	cout << "There are " << count << " values less than " << threshhold << endl; 
	return count;
}

int num_more(double data[], int len){
	int count = 0;
	double ave = average(data, len);
	for(int i = 0; i < len; i++){
		if(data[i] > ave){
			count += 1;
		}
	}
	cout << "There are " << count << " values more than the average of " << ave << endl; 
	return count;
}

double range(double data[], int len){
	double maximum = max(data, len);
	double minimum = min(data, len);
	cout << "Range of "<< (maximum-minimum) << endl;
	return (maximum-minimum);
}

double stdDev(double data[], int len){
	double sum = 0;
	double ave = average(data, len);
	double standardDev;
	for(int i = 0; i < len; i++){
		sum += ((data[i] - ave)*(data[i]-ave));
	} 
	standardDev = sqrt(sum/len);
	cout << "Standard deviation of " << standardDev << endl;
	return standardDev;	
}
