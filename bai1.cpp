/*B�i 1: Vi?t ch??ng tr�nh nh?p s? th?p l?c ph�n in ra s? nh? ph�n, c? 4 s? th� c�ch m?t kho?ng tr?ng*/
#include<iostream>
#include<map>
#include<string>

using namespace std;
string doi(char thapluc){
	switch(toupper(thapluc)){
		case '0':
			return "0000";
		case '1':
			return "0001";
		case '2':
			return "0010";
		case '3':
			return "0011";
		case '4':
			return "0100";
		case '5':
			return "0101";
		case '6':
			return "0110";
		case '7':
			return "0111";
		case '8':
			return "1000";
		case '9':
			return "1001";
		case 'A':
			return "1010";
		case 'B':
			return "1011";
		case 'C':
			return "1100";
		case 'D':
			return "1101";
		case 'E':
			return "1110";
		case 'F':
			return "1111";
	}
}
int main()
{
	string thapluc;
	cin>>thapluc;
	string khoangcach = " ";
	for(int i = 0; i < thapluc.length(); i++){
		khoangcach += doi(thapluc[i]);
	}
	for(int i = 0; i<khoangcach.length(); i++){
		cout<<khoangcach[i];
		if((i+1)%4==0){
			cout<<" ";
		}
	}
}