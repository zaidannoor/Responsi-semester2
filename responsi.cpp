#include <iostream>
#include <iomanip>
using namespace std;
struct game{
	string nama;
	int tahun;
	int harga;
}gim[5];


int main(){
	int menu;
	gim[0].nama ="Among_us";
	gim[0].tahun = 2018;
	gim[0].harga = 40000;

	gim[1].nama ="House_Flipper";
	gim[1].tahun = 2018;
	gim[1].harga = 160000;

	gim[2].nama ="PlayerUnknown'S_Battlegrounds";
	gim[2].tahun = 2017;
	gim[2].harga = 300000;
	
	gim[3].nama ="Fall_Guys";
	gim[3].tahun = 2020;
	gim[3].harga = 260000;

	gim[4].nama ="Baker_Simulator";
	gim[4].tahun = 2019;
	gim[4].harga = 190000;
	
	while(true){
		cout<<" Welcome to Zaidan Game Store "<<endl<<endl;
		cout<<" 1.Beli Game"<<endl;
		cout<<" 2.Checkout"<<endl;
		cout<<" 3.Exit"<<endl;
	}
	
	return 0;
}
