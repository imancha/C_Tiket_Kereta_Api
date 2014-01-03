#include <iostream>
#include <cstdlib>
#include <conio.h>		//	Untuk getche(), dll...
#include <cstring>
#include <ctime>		//	Untuk random angka, waktu
#include <sstream>		//	Untuk convert to string
#include <windows.h>	//	Untuk Sleep, gotoxy, dll...
#include <fstream>		//	Untuk file
#include <iomanip>		//	Untuk manipulasi tampilan
#define maxKursi 50		//	Maksimum nomor kursi
#define maxKasir 5		//	Maksimum kasir

using namespace std;

struct train{
	string kode;
	string nama;
	string berangkat;
	string tiba;
	int gerbong;
	string kursi;
	int harga;
};

struct employee{
	int nomor;
	string nama;
	string alamat;
};

struct date{
	int tanggal;
	string bulan;
	int tahun;
};

struct buyer{	
	string nama;
	date berangkat;
	string asal;
	string tujuan;
	string kelas;
	string waktu;
	int jumlah;
	int diskon;
	int subtotal;
	int total;
};

struct tiket{
	string kode;
	buyer pembeli;
	train kereta;
	employee kasir;
};

struct queue{
	tiket info;
	queue *next;
};

void gotoxy(int x, int y){
	COORD pos={x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}

void textcolor(int color){
	HANDLE hcolor;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),color);
}

int whereX(){
  	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO ccinfo;
   	GetConsoleScreenBufferInfo(hOut,&ccinfo);
	return ccinfo.dwCursorPosition.X+1;
}

int whereY(){
  	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO ccinfo;
   	GetConsoleScreenBufferInfo(hOut,&ccinfo);
	return ccinfo.dwCursorPosition.Y+1;
}

//	Konversi integer ke string
string convertInt(int number){
	stringstream convert;
	convert << number;
	return convert.str();
}

//	Merubah huruf kecil menjadi huruf besar
string uppercase(string x){
	string y;
	for(int i=0; i<x.length(); i++){
		y += toupper(x[i]);
	}
	return y;
}

//	Show look like loading
void loading(int panjang){
	textcolor(rand()%15+1);
	for(int i=0; i<panjang+2; i++){
		gotoxy(((81-panjang)/2)+i,23); cout << char(219);		
		gotoxy(((81-panjang)/2)+i,24); cout << char(219);
        Sleep(10);
    }
    textcolor(7);
}

//	Show kalimat per karakter
void type(string x){
	for(int i=0; i<x.length(); i++){
		cout << x[i];
		Sleep(50);
	}
}

//	Show kotak menu
void kotak(int tinggi, int lebar){
	textcolor(rand()%6+9);
	if(tinggi == 1){
		gotoxy((81-lebar)/2,(24-tinggi)/2);   cout << char(201); for(int i=0; i<lebar; i++){ cout << char(205); } cout << char(187) << endl;
		gotoxy((81-lebar)/2,(24-tinggi)/2+1); cout << char(186); for(int i=0; i<lebar; i++){ cout << " "; } cout << char(186) << endl;
		gotoxy((81-lebar)/2,(24-tinggi)/2+tinggi+1); cout << char(200); for(int i=0; i<lebar; i++){ cout << char(205); } cout << char(188) << endl;
	}else{
		gotoxy((81-lebar)/2,(24-tinggi)/2);   cout << char(201); for(int i=0; i<lebar; i++){ cout << char(205); } cout << char(187) << endl;
		gotoxy((81-lebar)/2,(24-tinggi)/2+1); cout << char(186); for(int i=0; i<lebar; i++){ cout << " "; } cout << char(186) << endl;
		gotoxy((81-lebar)/2,(24-tinggi)/2+2); cout << char(204); for(int i=0; i<lebar; i++){ cout << char(205); } cout << char(185) << endl;
		for(int j=0; j<tinggi-1; j++){ gotoxy((81-lebar)/2,(24-tinggi)/2+3+j);cout << char(186); for(int i=0; i<lebar; i++){ cout << " "; } cout << char(186) << endl;}
		gotoxy((81-lebar)/2,(24-tinggi)/2+tinggi-1); cout << char(204); for(int i=0; i<lebar; i++){ cout << char(205); } cout << char(185) << endl;	
		gotoxy((81-lebar)/2,(24-tinggi)/2+tinggi);   cout << char(186); for(int i=0; i<lebar; i++){ cout << " "; } cout << char(186) << endl;
		gotoxy((81-lebar)/2,(24-tinggi)/2+tinggi+1); cout << char(200); for(int i=0; i<lebar; i++){ cout << char(205); } cout << char(188) << endl;
	}
	textcolor(7);
}

#include "dataKereta.h"
#include "dataPegawai.h"
#include "dataPembeli.h"

int main(int argc, char** argv) {
	srand(time(NULL));
	int menu;
	tiket pembeli;
	queue *node = NULL;
	
	loadPembeli(&node,pembeli);	
	
	do{
		do{
			system("cls");	
			kotak(8,27);		
			gotoxy(31,9);  cout << "MENU TIKET KERETA API";
			gotoxy(32,11); cout << "{ 1 }  Data Kereta";
			gotoxy(32,12); cout << "{ 2 }  Data Pembeli";
			gotoxy(32,13); cout << "{ 3 }  Data Pegawai";
			gotoxy(32,14); cout << "{ 0 }  Keluar";
			gotoxy(32,16); type("    PILIHAN : "); menu = getche();
		}while(menu > '3');
		loading(27);
		system("cls");
		switch (menu){
			case '1' :	jadwal();
						break;
			case '2' :	menuPembeli(&node,pembeli);
						break;
			case '3' : 	pegawai();
						break;
		}
	}while(menu != '0');
	
	uploadPembeli(node);
	destroy(node);
}
