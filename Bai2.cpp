/*Bài 2: Viết chương trình đếm số lần xuất hiện của từ trong một câu*/
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
/*
#include<iostream>
using namespace std;

int main(){
	std::string cau;
	char TuCanTim;

	std::cout << "Nhap cau vao: ";
	std::getline(std::cin, cau);

	std::cout << "Tu can tim: ";
	std::cin >> TuCanTim;

	int dem = 0;
	for (char kitu : cau){
		if (TuCanTim == kitu){
			dem++;
		}
	}
	std::cout << "So lan xuat hien cua tu '" << TuCanTim << "' la: " << dem << std::endl;
	return 0;
}
*/
