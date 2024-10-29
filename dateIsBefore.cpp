#include<iostream>
using namespace std;

bool dateIsBefore(int month1, int day1, int month2, int day2){
	if(month1 < month2){
		return true; 
	} 
	else if(month1 == month2 && day1 < day2){
		return true; 
	} 
	else {
        return false;
    }
} 
int main(){
	cout<<boolalpha;//boolalpha: Là m?t manipulator (m?t hàm ho?c ð?i tý?ng ð?c bi?t trong C++ ðý?c s? d?ng ð? ði?u khi?n ð?nh d?ng ho?c tr?ng thái c?a m?t lu?ng) ðý?c cung c?p b?i thý vi?n chu?n c?a C++. Khi b?n s? d?ng std::boolalpha, nó làm thay ð?i cách mà các giá tr? boolean ðý?c hi?n th? ra màn h?nh.
    cout<<"Test 1"<<dateIsBefore(6, 3, 9, 20);
	cout<<"Test 2"<<dateIsBefore(9, 3, 9, 20);
	cout<<"Test 3"<<dateIsBefore(10, 13, 10, 2);
	cout<<"Test 4"<<dateIsBefore(1, 3, 9, 1);
	
	return 0; 
} 
