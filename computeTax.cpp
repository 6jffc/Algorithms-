#include<iostream>
using namespace std;

double  computeTax(double salary){
	double tax = 0.0;
	if(salary < 7150){
    tax =  salary*0.10; 
	} 
	else if(salary <= 29050){
	tax = 715 + (salary - 7150)*0.15; 
	} 
	else if(salary <= 70350){
	tax = 4000 + (salary - 29050)*0.25; 
	} 
	else{
	tax = 14325 + (salary - 70350)*0.28; 
	} 
	return tax; 
}

int main(){
	double salary;
	cout<<"Enter your salary: ";

	cin>>salary; 
	double tax = computeTax(salary);
	cout << "Tax owed: $" << tax;
	return 0; 
} 
