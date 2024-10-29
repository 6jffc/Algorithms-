/*Bài 4: Nh?p h? tên, tách h? tên ra làm 2 ph?n h? và tên riêng*/
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
