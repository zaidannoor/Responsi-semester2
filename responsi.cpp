#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
int i,j; //digunakan pada loop for
fstream myfile;

struct game{
	string nama;
	int tahun;
	int harga;
}gim[5];
game temp;
game pesanan[5];

void Sorting_Abjad(){
	for(int i=0;i<5;i++){
		for(j=i+1;j<5;j++){
			if(gim[i].nama[0] > gim[j].nama[0]){
				temp.nama = gim[i].nama;
				temp.harga = gim[i].harga;
				temp.tahun = gim[i].tahun;
										
				gim[i].nama = gim[j].nama;
				gim[i].harga = gim[j].harga;
				gim[i].tahun = gim[j].tahun;
								
				gim[j].nama = temp.nama;
				gim[j].harga = temp.harga;
				gim[j].tahun = temp.tahun;
			}
		}
	}
}

void Sorting_Harga(){
	for(int i=0;i<5;i++){
		for(j=i+1;j<5;j++){
			if(gim[i].harga > gim[j].harga){
				temp.nama = gim[i].nama;
				temp.harga = gim[i].harga;
				temp.tahun = gim[i].tahun;
										
				gim[i].nama = gim[j].nama;
				gim[i].harga = gim[j].harga;
				gim[i].tahun = gim[j].tahun;
								
				gim[j].nama = temp.nama;
				gim[j].harga = temp.harga;
				gim[j].tahun = temp.tahun;
			}
		}
	}
}

void Sorting_Tahun(){
	for(int i=0;i<5;i++){
		for(j=i+1;j<5;j++){
			if(gim[i].tahun > gim[j].tahun){
				temp.nama = gim[i].nama;
				temp.harga = gim[i].harga;
				temp.tahun = gim[i].tahun;
										
				gim[i].nama = gim[j].nama;
				gim[i].harga = gim[j].harga;
				gim[i].tahun = gim[j].tahun;
								
				gim[j].nama = temp.nama;
				gim[j].harga = temp.harga;
				gim[j].tahun = temp.tahun;
			}
		}
	}
}

void Searching(){
	string cari;
	bool found = false;
	cout<<" Masukkan nama yang dicari : ";
	getline(cin,cari);
	for(i=0;i<5;i++){
		if(cari == gim[i].nama){
			for(j=0;j<63;j++){
				cout<<"="; }
			cout<<endl;
			cout<<"|"<<setw(7)<<left<<" NO"<<"|"<<setw(31)<<" Nama Game"<<"|";
			cout<<setw(8)<<" Tahun"<<"|"<<setw(12)<<" Harga"<<"|";
			cout<<endl;
			for(j=0;j<63;j++){
				cout<<"="; }
			cout<<endl;
			
			cout<<"|"<<setw(7)<<left<<i+1<<"|"<<setw(31)<<gim[i].nama<<"|";
			cout<<setw(8)<<gim[i].tahun<<"| Rp "<<setw(8)<<gim[i].harga<<"|";
			cout<<endl;
			
			for(j=0;j<63;j++){
				cout<<"="; }
			cout<<endl;
			found = true;
			break;
		}
	}
	
	if(found == false){
		for(int i=0;i<63;i++){
				cout<<"="; }
		cout<<endl;
		cout<<"|"<<setw(7)<<left<<" NO"<<"|"<<setw(31)<<" Nama Game"<<"|";
		cout<<setw(8)<<" Tahun"<<"|"<<setw(12)<<" Harga"<<"|";
		cout<<endl;
		for(i=0;i<63;i++){
			cout<<"="; }
		cout<<endl;
	}
}

void Tampil_Data(){
	for(int i=0;i<63;i++){
		cout<<"="; }
	cout<<endl;
	cout<<"|"<<setw(7)<<left<<" NO"<<"|"<<setw(31)<<" Nama Game"<<"|";
	cout<<setw(8)<<" Tahun"<<"|"<<setw(12)<<" Harga"<<"|";
	cout<<endl;
	
	for(i=0;i<63;i++){
		cout<<"="; }
	cout<<endl;
	
	for(i=0;i<5;i++){
		cout<<"|"<<setw(7)<<left<<i+1<<"|"<<setw(31)<<gim[i].nama<<"|";
		cout<<setw(8)<<gim[i].tahun<<"| Rp "<<setw(8)<<gim[i].harga<<"|";
		cout<<endl;
	}
	for(int i=0;i<63;i++){
		cout<<"="; }
	cout<<endl;
}

void import_pesanan(bool *terbayar ,string *pembeli ,int *jumlah){
	int num;
	int p=0;
	string ambil;
	int baris = 1;
	myfile.open("FormBeli.txt" , ios::in);
	// loop mengambil data pembeli dan jumlah pembelian
	while(getline(myfile,ambil)){
		if(baris%4 == 1){
			num = stoi(ambil);
			*terbayar = num;
			if(*terbayar == 1){
				break;
			}
		}
		else if(baris%4 == 2){
			*pembeli = ambil;
		}
		else if(baris%4 == 3){
			*jumlah = stoi(ambil);
		}
		else if(baris == 4){
			break;
		}
		baris++;
	}
	myfile.close();
	// loop mengambil data barang yang dibeli
	baris = 1;
	//num = 1;
	myfile.open("FormBeli.txt" , ios::in);
	while(getline(myfile,ambil)){
		if(baris > 3){
			if(baris %2 ==0){
				pesanan[p].nama = ambil;
			}
			else if(baris %2 == 1){
				pesanan[p].harga = stoi(ambil);
				p++;
			}
			
		}
		
		baris++;
	}
	myfile.close();
}

int main(){
	int menu; // memilih pada menu utama
	int pilih; // memilih pada sub menu utama
	int lagi; // mengulang pada menu sub menu sorting
	int beli;
	string pembeli;
	int jumlah;
	int no[5];
	bool terbayar;
	int total_harga,total_harga2; // digunakan pada menu checkout barang
	int total_bayar;
	gim[0].nama ="Among_Us";
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
		import_pesanan(&terbayar,&pembeli,&jumlah);
		//cout<<pesanan[1].harga<<endl;
		//cout<<pesanan[1].nama<<endl;
		cout<<" == Welcome to Zaidan Game Store =="<<endl<<endl;
		cout<<" menu awal"<<endl;
		cout<<" 1.Beli Game"<<endl;
		cout<<" 2.Checkout"<<endl;
		cout<<" 3.Exit"<<endl;
		cout<<" >> ";
		cin>>menu;
		cin.ignore();
		if(menu == 1){
			system("CLS");
			while(true){
				cout<<" == Welcome to Zaidan Game Store == "<<endl<<endl;
				cout<<setw(5)<<" "<<"KATALOG GAME"<<endl<<endl;
				cout<<setw(5)<<" "<<"1.Urutkan katalog & beli game"<<endl;
				cout<<setw(5)<<" "<<"2.Cari game "<<endl;
				cout<<setw(5)<<" "<<"3.Exit"<<endl;
				cout<<setw(5)<<" "<<">> ";
				cin>>pilih;
				cin.ignore();
				
				if(pilih == 1){
					system("CLS");
					cout<<" == Welcome to Zaidan Game Store == "<<endl<<endl;
					while(true){
						while(true){
							cout<<setw(5)<<" "<<"KATALOG GAME"<<endl<<endl;
							cout<<setw(5)<<" "<<"1.Berdasarkan Abjad"<<endl;
							cout<<setw(5)<<" "<<"2.Berdasarkan Tahun"<<endl;
							cout<<setw(5)<<" "<<"3.Berdasarkan Harga"<<endl;
							cout<<setw(5)<<" "<<">> ";
							cin>>pilih;
							cin.ignore();
							if(pilih == 1){
								Sorting_Abjad();
								Tampil_Data();
								break;
							}
							else if(pilih == 2){
								Sorting_Tahun();
								Tampil_Data();
								break;
							}
							else if(pilih == 3){
								Sorting_Harga();
								Tampil_Data();
								break;
							}
							else{
								cout<<" Masukkan angka 1,2,atau 3 saja !"<<endl;
								system("CLS");
							}
						}
						while(true){
							cout<<" Urutkan lagi? [1: yes | 2: no] >> ";
							cin>>lagi;
							cin.ignore();
							if(lagi == 1){
								system("CLS");
								break;
							}
							else if(lagi == 2){
								break;
							}
						}
						
						if(lagi == 2){
							break;
						}
					}
					
					while(true){
						
						cout<<" Apakah anda ingin membeli? [1: yes | 2: no] >> ";
						cin>>beli;
						cin.ignore();
						if(beli == 1){
							terbayar = false;
							cout<<"\n == Form Pembelian Game =="<<endl;
							cout<<" Nama Pembeli (tanpa spasi) : ";
							getline(cin,pembeli);
							cout<<" Jumlah Pembelian           : ";
							cin>>jumlah;
							for(i=0;i<jumlah;i++){
								cout<<"   "<<i+1<<". Nomor game yang dibeli : ";
								cin>>no[i];
							}
							cin.ignore();
							// memasukkkan data ke file eksternal
							myfile.open("FormBeli.txt" , ios::out);
							myfile<<terbayar<<endl;
							myfile<<pembeli<<endl;
							myfile<<jumlah<<endl;
							for(i=0;i<jumlah;i++){
								myfile<<gim[no[i] - 1].nama<<endl;
								myfile<<gim[no[i] - 1].harga<<endl;
							}
							myfile.close();
							
							
							cout<<" Form telah direkam. Harap membayar melalui";
							cout<<" menu Checkout !"<<endl<<endl;
							break;
						}
						else if(beli == 2){
							cout<<" Kembali ke menu awal "<<endl<<endl;
							break;
						}
					}
					system("pause");
					system("cls");
					break;
				}
				else if(pilih == 2){
					system("CLS");
					while(true){
						cout<<" == Welcome to Zaidan Game Store == "<<endl<<endl;
						cout<<setw(5)<<" "<<"KATALOG GAME"<<endl<<endl;
						Searching();
						while(true){
							cout<<" Cari game lagi? [1: yes | 2: no] >> ";
							cin>>lagi;
							cin.ignore();
							if(lagi == 1){
								break;
							}
							else if(lagi == 2){
								break;
							}
						}
						if(lagi == 2){
							system("cls");
							break;
						}
						system("cls");
					}
					
				}
				else if(pilih == 3){
					system("cls");
					break;
				}
				else{
					cout<<" Invalid input "<<endl;
					system("pause");
					system("CLS");
				}
		
			}
		}
		
		else if(menu == 2){
			system("CLS");
			cout<<" == Welcome to Zaidan Game Store == "<<endl<<endl;
			cout<<setw(5)<<left<<" "<<" Menu Checkout "<<endl;
			cout<<" 1.Checkout Barang"<<endl;
			cout<<" 2.Exit"<<endl;
			cout<<" >> ";
			cin>>pilih;
			cin.ignore();
			if(pilih == 1){
				system("cls");
				cout<<" == Welcome to Zaidan Game Store == "<<endl<<endl;
				
				cout<<setw(20)<<left<<" Nama Pembeli "<<": "<<pembeli<<endl;
				cout<<setw(20)<<left<<" Jumlah Pembelian "<<": "<<jumlah<<endl;
				
				for(int i=0;i<52;i++){
					cout<<"="; }
				cout<<endl;
				cout<<"|"<<setw(7)<<left<<" NO "<<"|"<<setw(30)<<" Pesanan";
				cout<<"|"<<setw(11)<<" Harga "<<"|"<<endl;
				for(int i=0;i<52;i++){
					cout<<"="; }
				cout<<endl;
				
				for(int i=0;i<jumlah;i++){
					cout<<"|"<<setw(7)<<left<<i+1<<"|"<<setw(30)<<pesanan[i].nama;
					cout<<"| Rp "<<setw(7)<<pesanan[i].harga<<"|"<<endl;
				}
				
				// hitung total harga
				for(i=0;i<jumlah;i++){
					total_harga = pesanan[i].harga;
					total_harga2 = total_harga2 + total_harga;
				}
				for(int i=0;i<52;i++){
					cout<<"="; }
				cout<<endl;
				cout<<"|"<<setw(38)<<left<<" Total Harga"<<"| Rp ";
				cout<<setw(7)<<total_harga2<<"|"<<endl;
				for(int i=0;i<52;i++){
					cout<<"="; }
				cout<<endl;
				do{
					cout<<setw(20)<<left<<" Uang yang dibayarkan"<<": Rp ";
					cin>>total_bayar;
					cin.ignore();
				}while(total_bayar < total_harga2);
				cout<<endl;
				cout<<setw(20)<<left<<" Kembalian"<<": Rp "<<total_bayar - total_harga2;
				cout<<"\n Checkout Berhasil"<<endl<<endl;
				terbayar = true;
				// mengupdate file eksternal
				myfile.open("FormBeli.txt" , ios::out);
				myfile << terbayar<<endl;
				myfile.close();
				system("pause");
				system("cls");
				
			}
			
		}
		
		else if(menu == 3){
			break;
		}
		else{
			cout<<" Invalid input "<<endl;
			system("pause");
			system("CLS");
		}
	}
	
	return 0;
}

