//	Show info kode input
void info(){
	cout << endl; textcolor(rand()%7+9);
	cout << "       " << char(218); for(int i=0; i<63; i++){ if(i==21 || i==44) cout << char(194); else cout << char(196); } cout << char(191) << endl;
	cout << "       " << char(179) << "     KODE STASIUN    " << char(179) << "      KODE KELAS      " << char(179) << "    KODE WAKTU    "  << char(179) << endl;
	cout << "       " << char(195); for(int i=0; i<63; i++){ if(i==21 || i==44) cout << char(197); else cout << char(196); } cout << char(180) << endl;
	cout << "       " << char(179) << "   ( 1 )  BANDUNG    " << char(179) << "   ( 1 )  EKSEKUTIF   " << char(179) << "   ( 1 )  PAGI    " << char(179) << endl;
	cout << "       " << char(195); for(int i=0; i<63; i++){ if(i==21 || i==44) cout << char(197); else cout << char(196); } cout << char(180) << endl;
	cout << "       " << char(179) << "   ( 2 )  CIREBON    " << char(179) << "   ( 2 )  BISNIS      " << char(179) << "   ( 2 )  SIANG   " << char(179) << endl;
	cout << "       " << char(195); for(int i=0; i<63; i++){ if(i==21 || i==44) cout << char(197); else cout << char(196); } cout << char(180) << endl;
	cout << "       " << char(179) << "   ( 3 )  JAKARTA    " << char(179) << "   ( 3 )  EKONOMI     " << char(179) << "   ( 3 )  MALAM   " << char(179) << endl;
	cout << "       " << char(195); for(int i=0; i<63; i++){ if(i==21 || i==44) cout << char(197); else cout << char(196); } cout << char(180) << endl;
	cout << "       " << char(179) << "   ( 4 )  SURABAYA   " << char(179) << "           -          " << char(179) << "         -        " << char(179) << endl;
	cout << "       " << char(192); for(int i=0; i<63; i++){ if(i==21 || i==44) cout << char(193); else cout << char(196); } cout << char(217) << endl;
	cout << endl << endl; textcolor(7);
}

//	Show jadwal kereta
void infoKereta(){
	ifstream fin("dataKereta.dat");
	
	string x;
	while(!fin.eof()){
		getline(fin,x);
		cout << x << endl;
	}
	getch();
}

//	Show diskon
string diskon(int jumlah){
	if(jumlah > 3) return "10%";
	else return "0%";
}

//	Show 3 huruf terakhir kode kereta
string noKA(string nama){
	string x;
	for(int i=3; i<nama.length(); i++){
		x += nama[i];
	}
	return x;
}

//	Get diskon
int diskon(int jumlah, int subt){
	if(jumlah > 3){
		return 10 * subt / 100;
	}else{
		return 0;
	}
}

//	Get harga tiket
int harga(int kodeA, int kodeT, int kodeK){
	switch(kodeA){
		case '1' : switch(kodeT){
					case '2' : switch(kodeK){
					   			case '1' : return 100000; break;
					   			case '2' : return 75000; break;
					   			case '3' : return 50000; break;
					   		   }
					case '3' : switch(kodeK){
					   			case '1' : return 85000; break;
					   			case '2' : return 60000; break;
					   			case '3' : return 45000; break;
					   		   }
					case '4' : switch(kodeK){
								case '1' : return 300000; break;
								case '2' : return 200000; break;
								case '3' : return 150000; break;
							   }
				   }
		case '2' : switch(kodeT){
					case '1' : switch(kodeK){
					   			case '1' : return 100000; break;
					   			case '2' : return 75000; break;
					   			case '3' : return 50000; break;
					   		   }
					case '3' : switch(kodeK){
					   			case '1' : return 125000; break;
					   			case '2' : return 100000; break;
					   			case '3' : return 75000; break;
					   		   }
					case '4' : switch(kodeK){
								case '1' : return 300000; break;
								case '2' : return 225000; break;
								case '3' : return 175000; break;
							   }
				   }
		case '3' : switch(kodeT){
					case '1' : switch(kodeK){
					   			case '1' : return 85000; break;
					   			case '2' : return 60000; break;
					   			case '3' : return 45000; break;
					   		   }
					case '2' : switch(kodeK){
					   			case '1' : return 125000; break;
					   			case '2' : return 100000; break;
					   			case '3' : return 75000; break;
					   		   }
					case '4' : switch(kodeK){
								case '1' : return 350000; break;
								case '2' : return 250000; break;
								case '3' : return 200000; break;
							   }					
				   }
		case '4' : switch(kodeT){
					case '1' : switch(kodeK){
					   			case '1' : return 300000; break;
					   			case '2' : return 200000; break;
					   			case '3' : return 150000; break;
					   		   }
					case '2' : switch(kodeK){
					   			case '1' : return 300000; break;
					   			case '2' : return 225000; break;
					   			case '3' : return 175000; break;
					   		   }
					case '3' : switch(kodeK){
								case '1' : return 350000; break;
								case '2' : return 250000; break;
								case '3' : return 200000; break;
							   }
				   }
	}
}

//	Get kode kereta
string kodeKA(int kodeA){
	switch(kodeA){
		case '1' : return "KA-111"; break;
		case '2' : return "KA-222"; break;
		case '3' : return "KA-333"; break;
		case '4' : return "KA-444"; break;
	}
}

//	Get nama kereta
string namaKA(int kodeA){
	switch(kodeA){
		case '1' : return "PARAHYANGAN"; break;
		case '2' : return "WALISONGO"; break;
		case '3' : return "METROPOLITAN"; break;
		case '4' : return "KERTASURA";
	}
}

//	Get jadwal berangkat kereta
string jBerangkat(int kodeA, int kodeT, int kodeW){
	switch(kodeA){
		case '1' : switch(kodeT){
					case '2' : switch(kodeW){
					   			case '1' : return "05.00"; break;
					   			case '2' : return "13.00"; break;
					   			case '3' : return "19.00"; break;
					   		   }
					case '3' : switch(kodeW){
					   			case '1' : return "05.15"; break;
					   			case '2' : return "13.15"; break;
					   			case '3' : return "19.15"; break;
					   		   }
					case '4' : switch(kodeW){
								case '1' : return "05.30"; break;
								case '2' : return "13.30"; break;
								case '3' : return "19.30"; break;
							   }
				   }
		case '2' : switch(kodeT){
					case '1' : switch(kodeW){
					   			case '1' : return "05.00"; break;
					   			case '2' : return "13.00"; break;
					   			case '3' : return "19.00"; break;
					   		   }
					case '3' : switch(kodeW){
					   			case '1' : return "05.15"; break;
					   			case '2' : return "13.15"; break;
					   			case '3' : return "19.15"; break;
					   		   }
					case '4' : switch(kodeW){
								case '1' : return "05.30"; break;
								case '2' : return "13.30"; break;
								case '3' : return "19.30"; break;
							   }
				   }
		case '3' : switch(kodeT){
					case '1' : switch(kodeW){
					   			case '1' : return "05.00"; break;
					   			case '2' : return "13.00"; break;
					   			case '3' : return "19.00"; break;
					   		   }
					case '2' : switch(kodeW){
					   			case '1' : return "05.15"; break;
					   			case '2' : return "13.15"; break;
					   			case '3' : return "19.15"; break;
					   		   }
					case '4' : switch(kodeW){
								case '1' : return "05.30"; break;
								case '2' : return "13.30"; break;
								case '3' : return "19.30"; break;
							   }					
				   }
		case '4' : switch(kodeT){
					case '1' : switch(kodeW){
					   			case '1' : return "05.00"; break;
					   			case '2' : return "13.00"; break;
					   			case '3' : return "19.00"; break;
					   		   }
					case '2' : switch(kodeW){
					   			case '1' : return "05.15"; break;
					   			case '2' : return "13.15"; break;
					   			case '3' : return "19.15"; break;
					   		   }
					case '3' : switch(kodeW){
								case '1' : return "05.30"; break;
								case '2' : return "13.30"; break;
								case '3' : return "19.30"; break;
							   }
				   }
	}
}

//	Get jadwal tiba kereta
string jTiba(int kodeA, int kodeT, int kodeW){
	switch(kodeA){
		case '1' : switch(kodeT){
					case '2' : switch(kodeW){
					   			case '1' : return "09.00"; break;
					   			case '2' : return "17.00"; break;
					   			case '3' : return "23.00"; break;
					   		   }
					case '3' : switch(kodeW){
					   			case '1' : return "08.15"; break;
					   			case '2' : return "16.15"; break;
					   			case '3' : return "22.15"; break;
					   		   }
					case '4' : switch(kodeW){
								case '1' : return "14.00"; break;
								case '2' : return "22.00"; break;
								case '3' : return "04.00"; break;
							   }
				   }
		case '2' : switch(kodeT){
					case '1' : switch(kodeW){
					   			case '1' : return "09.00"; break;
					   			case '2' : return "17.00"; break;
					   			case '3' : return "23.00"; break;
					   		   }
					case '3' : switch(kodeW){
					   			case '1' : return "11.15"; break;
					   			case '2' : return "19.15"; break;
					   			case '3' : return "02.15"; break;
					   		   }
					case '4' : switch(kodeW){
								case '1' : return "15.00"; break;
								case '2' : return "23.00"; break;
								case '3' : return "05.00"; break;
							   }
				   }
		case '3' : switch(kodeT){
					case '1' : switch(kodeW){
					   			case '1' : return "08.00"; break;
					   			case '2' : return "16.00"; break;
					   			case '3' : return "22.00"; break;
					   		   }
					case '2' : switch(kodeW){
					   			case '1' : return "11.15"; break;
					   			case '2' : return "19.15"; break;
					   			case '3' : return "02.15"; break;
					   		   }
					case '4' : switch(kodeW){
								case '1' : return "17.00"; break;
								case '2' : return "01.00"; break;
								case '3' : return "07.00"; break;
							   }					
				   }
		case '4' : switch(kodeT){
					case '1' : switch(kodeW){
					   			case '1' : return "13.30"; break;
					   			case '2' : return "21.30"; break;
					   			case '3' : return "03.30"; break;
					   		   }
					case '2' : switch(kodeW){
					   			case '1' : return "14.45"; break;
					   			case '2' : return "22.45"; break;
					   			case '3' : return "04.45"; break;
					   		   }
					case '3' : switch(kodeW){
								case '1' : return "17.00"; break;
								case '2' : return "01.00"; break;
								case '3' : return "07.00"; break;
							   }
				   }
	}
}

//	Get nama stasiun
string namaStasiun(int kode){
	switch(kode){
		case '1' : return "BANDUNG"; break;
		case '2' : return "CIREBON"; break;
		case '3' : return "JAKARTA"; break;
		case '4' : return "SURABAYA"; break;
	}		
}

//	Get nama kelas kereta
string namaKelas(int kode){
	switch(kode){
		case '1' : return "EKSEKUTIF"; break;
		case '2' : return "BISNIS"; break;
		case '3' : return "EKONOMI"; break;
	}
}

//	Get waktu keberangkatan
string namaWaktu(int kode){
	switch(kode){
		case '1' : return "PAGI"; break;
		case '2' : return "SIANG"; break;
		case '3' : return "MALAM"; break;
	}
}

//	Fungsi untuk mendapatkan kode stasiun
int kodeStasiun(string nama){
	if(nama == "BANDUNG") return '1';
	else if(nama == "CIREBON") return '2';
	else if(nama == "JAKARTA") return '3';
	else if(nama == "SURABAYA") return '4';
}

//	Fungsi untuk mendapatkan kode kelas
int kodeKelas(string nama){
	if(nama == "EKSEKUTIF") return '1';
	else if(nama == "BISNIS") return '2';
	else if(nama == "EKONOMI") return '3';
}


//	Fungsi untuk mendapatkan kode waktu keberangkatan
int kodeWaktu(string nama){
	if(nama == "PAGI") return '1';
	else if(nama == "SIANG") return '2';
	else if(nama == "MALAM") return '3';
}
