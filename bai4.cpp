/*B�i 4: Nh?p h? t�n, t�ch h? t�n ra l�m 2 ph?n h? v� t�n ri�ng*/
#include<iostream>
#include<string>

int main(){
	string hoten;
	cout<<"Nhap ho ten: ";
	getline (cin, hoten);
	string ho = " ";
	string ten = " ";
	int i = 0;
	while (i < hoten.length() && hoten[i] != ' '){
		ho += hoten[i];
		i++;
	}
	while(i < hoten.length() && hoten[i] != ' '){
		i++;
	}
	while(i < hoten.length()){
		ten += hoten[i];
		i++;
	}
	cout<<"Ho: "<<ho<<endl;
	cout<<"Ten: "<<ten<<endl;
}
