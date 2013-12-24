void info(){
	ifstream fin("info.dat");
	string x;
	while(!fin.eof()){
		getline(fin,x);
		cout << x << endl;
	}
	putchar('\n');
}

string diskon(int jumlah){
	if(jumlah > 3) return "10%";
	else return "0%";
}

string noKA(string nama){
	string x;
	for(int i=3; i<nama.length(); i++){
		x += nama[i];
	}
	return x;
}

int diskon(int jumlah, int subt){
	if(jumlah > 3){
		return 0.1 * subt;
	}else{
		return 0.0;
	}
}

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

string kodeKA(int kodeA){
	switch(kodeA){
		case '1' : return "KA-111"; break;
		case '2' : return "KA-222"; break;
		case '3' : return "KA-333"; break;
		case '4' : return "KA-444"; break;
	}
}

string namaKA(int kodeA){
	switch(kodeA){
		case '1' : return "PARAHYANGAN"; break;
		case '2' : return "WALISONGO"; break;
		case '3' : return "METROPOLITAN"; break;
		case '4' : return "KERTASURA";
	}
}

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

string namaStasiun(int kode){
	switch(kode){
		case '1' : return "BANDUNG"; break;
		case '2' : return "CIREBON"; break;
		case '3' : return "JAKARTA"; break;
		case '4' : return "SURABAYA"; break;
	}		
}

string namaKelas(int kode){
	switch(kode){
		case '1' : return "EKSEKUTIF"; break;
		case '2' : return "BISNIS"; break;
		case '3' : return "EKONOMI"; break;
	}
}

string namaWaktu(int kode){
	switch(kode){
		case '1' : return "PAGI"; break;
		case '2' : return "SIANG"; break;
		case '3' : return "MALAM"; break;
	}
}

void jadwal(){
	ifstream fin("jadwal.dat");
	
	string x;
	while(!fin.eof()){
		getline(fin,x);
		cout << x << endl;
	}
	getch();
}
