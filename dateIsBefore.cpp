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
	cout<<boolalpha;//boolalpha: L� m?t manipulator (m?t h�m ho?c �?i t�?ng �?c bi?t trong C++ ��?c s? d?ng �? �i?u khi?n �?nh d?ng ho?c tr?ng th�i c?a m?t lu?ng) ��?c cung c?p b?i th� vi?n chu?n c?a C++. Khi b?n s? d?ng std::boolalpha, n� l�m thay �?i c�ch m� c�c gi� tr? boolean ��?c hi?n th? ra m�n h?nh.
    cout<<"Test 1"<<dateIsBefore(6, 3, 9, 20);
	cout<<"Test 2"<<dateIsBefore(9, 3, 9, 20);
	cout<<"Test 3"<<dateIsBefore(10, 13, 10, 2);
	cout<<"Test 4"<<dateIsBefore(1, 3, 9, 1);
	
	return 0; 
} 
