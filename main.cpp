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
	int id;
	string username;
	string password;
	string nama;
	string kota;
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
	employee data;
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

int wherex(){
  	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO ccinfo;
   	GetConsoleScreenBufferInfo(hOut,&ccinfo);
	return ccinfo.dwCursorPosition.X+1;
}

int wherey(){
  	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO ccinfo;
   	GetConsoleScreenBufferInfo(hOut,&ccinfo);
	return ccinfo.dwCursorPosition.Y+1;
}

void SetWindow(int Width, int Height) 
{ 
    _COORD coord; 
    coord.X = Width; 
    coord.Y = Height; 

    _SMALL_RECT Rect; 
    Rect.Top = 0; 
    Rect.Left = 0; 
    Rect.Bottom = Height - 1; 
    Rect.Right = Width - 1;
    
    HANDLE Handle = GetStdHandle(STD_OUTPUT_HANDLE);      // Get Handle 
//	SetConsoleScreenBufferSize(Handle, coord);            // Set Buffer Size 
    SetConsoleWindowInfo(Handle, TRUE, &Rect);            // Set Window Size 
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
	for(int i=0; i<panjang; i++){
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
		gotoxy((81-lebar)/2,(24-tinggi)/2);   cout << char(201); for(int i=0; i<lebar-2; i++){ cout << char(205); } cout << char(187) << endl;
		gotoxy((81-lebar)/2,(24-tinggi)/2+1); cout << char(186); for(int i=0; i<lebar-2; i++){ cout << " "; } cout << char(186) << endl;
		gotoxy((81-lebar)/2,(24-tinggi)/2+tinggi+1); cout << char(200); for(int i=0; i<lebar-2; i++){ cout << char(205); } cout << char(188) << endl;
	}else{
		gotoxy((81-lebar)/2,(24-tinggi)/2);   cout << char(201); for(int i=0; i<lebar-2; i++){ cout << char(205); } cout << char(187) << endl;
		gotoxy((81-lebar)/2,(24-tinggi)/2+1); cout << char(186); for(int i=0; i<lebar-2; i++){ cout << " "; } cout << char(186) << endl;
		gotoxy((81-lebar)/2,(24-tinggi)/2+2); cout << char(204); for(int i=0; i<lebar-2; i++){ cout << char(205); } cout << char(185) << endl;
		for(int j=0; j<tinggi-1; j++){ gotoxy((81-lebar)/2,(24-tinggi)/2+3+j);cout << char(186); for(int i=0; i<lebar-2; i++){ cout << " "; } cout << char(186) << endl;}
		gotoxy((81-lebar)/2,(24-tinggi)/2+tinggi-1); cout << char(204); for(int i=0; i<lebar-2; i++){ cout << char(205); } cout << char(185) << endl;	
		gotoxy((81-lebar)/2,(24-tinggi)/2+tinggi);   cout << char(186); for(int i=0; i<lebar-2; i++){ cout << " "; } cout << char(186) << endl;
		gotoxy((81-lebar)/2,(24-tinggi)/2+tinggi+1); cout << char(200); for(int i=0; i<lebar-2; i++){ cout << char(205); } cout << char(188) << endl;
	}
	textcolor(7);
}

#include "dataKereta.h"
#include "dataPegawai.h"
#include "dataPembeli.h"
#include "dataPribadi.h" 

int main(int argc, char** argv) {
	srand(time(NULL));
	int menu;
	string kasir;
	tiket pembeli;
	employee pegawai;
	queue *root = NULL;
	queue *node = NULL;

	/*	opening matrix	*/
	opening();
	/*	load data pegawai from file 'dataPegawai.dat'	*/
	loadPegawai(&root,pegawai);
	/*	login pegawai as kasir	*/
	loginPegawai(root,kasir);
	/*	load data pembeli from file 'dataPembeli.dat	*/
	loadPembeli(&node,pembeli);
	
	do{
		do{
			system("cls");
			/*	create box for main menu	*/
			kotak(8,29);
			/*	main menu	*/
			gotoxy(30,9);  cout << "MENU TIKET KERETA API";
			gotoxy(31,11); cout << "{ 1 }  Data Kereta";
			gotoxy(31,12); cout << "{ 2 }  Data Pembeli";
			gotoxy(31,13); cout << "{ 3 }  Data Pegawai";
			gotoxy(31,14); cout << "{ 0 }  Keluar";
			gotoxy(31,16); type("    PILIHAN : "); menu = getche();
		}while(menu > '3');
		/*	show looklike loading	*/
		loading(29);
		system("cls");
		switch (menu){
			case '1' :	infoKereta();
						break;
			case '2' :	menuPembeli(&node,pembeli,kasir);
						break;
			case '3' : 	menuPegawai(&root,pegawai);
						break;
		}
	}while(menu != '0');
	
	/*	upload data pegawai to file 'dataPegawai.dat'	*/
	uploadPegawai(root);
	/*	upload data pembeli to file	'dataPembeli.dat'	*/
	uploadPembeli(node);
	/*	free memori	*/
	destroy(node);
	destroy(root);	
	closing();
}
