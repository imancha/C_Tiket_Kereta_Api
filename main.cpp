#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <cstring>
#include <ctime>
#include <sstream>
#include <windows.h>
#include <fstream>
#include <iomanip>
#define maxKursi 50

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

void loading(int panjang){
	textcolor(rand()%15+1);
	for(int i=0; i<panjang; i++){
		gotoxy(((81-panjang)/2)+i,23); cout << char(219);		
		gotoxy(((81-panjang)/2)+i,24); cout << char(219);
        Sleep(1);
    }
    textcolor(7);
}

void type(string x){
	for(int i=0; i<x.length(); i++){
		cout << x[i];
		Sleep(50);
	}
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
			gotoxy(31,9);  cout << "{ 1 }  Data Kereta";
			gotoxy(31,10); cout << "{ 2 }  Data Pembeli";
			gotoxy(31,11); cout << "{ 3 }  Data Pegawai";
			gotoxy(31,12); cout << "{ 0 }  Keluar";
			gotoxy(31,14); type("       Pilihan : "); menu = getche();
		}while(menu > '3');
		loading(19);
		system("cls");
		switch (menu){
			case '1' :	jadwal();
						break;
			case '2' :	menuPembeli(&node,pembeli);
						break;
		}
	}while(menu != '0');
	
	uploadPembeli(node,pembeli);
	destroy(node);	
}
