/*B�i 2: Vi?t ch??ng tr�nh ??m s? l?n xu?t hi?n c?a t? trong m?t c�u*/
#include<iostream>
using namespace std;

int main(){
	string cau;
	char kitu;
	char tucantim;
	cout<<"Nhap cau vao: ";
	getline(cin, cau);
	cout<<"";
	cout<<"Tu can tim: ";
	cin>>tucantim;
	int dem = 0;
	for(int i = 0; i < cau.length(); ++i){
		kitu=cau[i];
		if(tucantim==kitu){
			kitu = cau[i];
			if(tucantim==kitu) dem++;
		}
	}
}
