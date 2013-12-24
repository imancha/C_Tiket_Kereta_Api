//	Blueprint tiket
void print(queue *node){
	system("cls");
	cout << char(218);
	for(int i=0; i<78; i++) cout << char(196);
	cout << char(191);
	cout << char(179) << "  Nama :  " << setiosflags(ios::left) << setw(36) << node->info.pembeli.nama
		 << "  Kode Tiket :  " << setw(16) << node->info.kode << char(179);
	cout << char(195);
	for(int i=0; i<78; i++) cout << char(196);
	cout << char(180);
	cout << char(179) << "  Tanggal Berangkat :  " << setw(2) << node->info.pembeli.berangkat.tanggal << " " 
		 << setw(9) << node->info.pembeli.berangkat.bulan << " " 
		 << setw(42) << node->info.pembeli.berangkat.tahun << char(179);
	cout << char(179) << setw(48) << " " << "No. KA :  "
		 << setw(20) << noKA(node->info.kereta.kode) << char(179);
	cout << char(179) << "  Nama KA           :  " << setw(55) << node->info.kereta.nama << char(179);
	cout << char(195);
	for(int i=0; i<78; i++) cout << char(196);
	cout << char(180);
	cout << char(179) << "  Jadwal Berangkat  :  " << setw(23) << node->info.kereta.berangkat
		 << "  Jadwal Tiba :  " << setw(15) << node->info.kereta.tiba << char(179);
	cout << char(179) << setw(78) << " " << char(179);
	cout << char(179) << setiosflags(ios::right) 
		 << setw(20) << node->info.pembeli.asal
		 << setw(32) << " " << resetiosflags(ios::right) << setiosflags(ios::left) 
		 << setw(26) << node->info.pembeli.tujuan << char(179);
	cout << char(195);
	for(int i=0; i<78; i++) cout << char(196);
	cout << char(180);
	cout << char(179) << setw(24) << "  Kelas :  " << setw(25) << "  No. Gerbong :  " 
		 << setw(29) << "  Nomor Tempat Duduk :  " << char(179);
	cout << char(179) << setw(78) << " " << char(179);
	cout << char(179) << "     " << setw(26) << node->info.pembeli.kelas 
		 << setw(26) << node->info.kereta.gerbong
		 << setw(21) << node->info.kereta.kursi << char(179);
	cout << char(195);
	for(int i=0; i<78; i++) cout << char(196);
	cout << char(180);
	cout << char(179) << setw(16) << "  Jumlah :  " 
		 << setw(22) << "  Harga (Rp) : " 
		 << setw(18) << " Diskon : " 
		 << setw(22) << " Jumlah (Rp) : " << char(179);
	cout << char(179) << setiosflags(ios::right) 
		 << setw(6) << node->info.pembeli.jumlah
		 << setw(22) << node->info.kereta.harga
		 << setw(45) << node->info.pembeli.subtotal
		 << setw(6) << char(179);
	cout << char(179) << setw(45) << diskon(node->info.pembeli.jumlah)
		 << setw(28) << node->info.pembeli.diskon
		 << setw(6) << char(179);
	cout << char(195);
	for(int i=0; i<78; i++) cout << char(196);
	cout << char(180);
	cout << char(179) << "  Kasir :  " << resetiosflags(ios::right) << setiosflags(ios::left)
		 << setw(37) << node->info.kasir.nama << "  Total (Rp) :  " << setiosflags(ios::right) 
		 << setw(9) << node->info.pembeli.total
		 << setw(6) << char(179);
	cout << char(192);
	for(int i=0; i<78; i++) cout << char(196);
	cout << char(217) << resetiosflags(ios::right);
}

//	Header tabel
void header(){
	cout << char(218);
	for(int i=0; i<78; i++){
		if(i==7 || i==30 || i==44 || i==50 || i==56 || i==62 || i==68){
			cout << char(194);
		}else{
			cout << char(196);
		}
	}
	cout << char(191);
	
	for(int i=0; i<80; i++){
		if(i==0 || i==8 || i==31 || i==45 || i==51 || i==57 || i==63 || i==69 || i==79){
			cout << char(179);
		}else{
			cout << " ";
		}
	}			
	
	textcolor(11);
	gotoxy(2,1);  cout << "KODE";
	gotoxy(18,1); cout << "NAMA";
	gotoxy(35,1); cout << "TANGGAL";
	gotoxy(47,1); cout << "ASL";
	gotoxy(53,1); cout << "TJN";
	gotoxy(59,1); cout << "KLS";
	gotoxy(65,1); cout << "JML";
	gotoxy(72,1); cout << "TOTAL\n";
	textcolor(7);
}

//	Body tabel
void body(){
	cout << char(195);
	for(int i=0; i<78; i++){
		if(i==7 || i==30 || i==44 || i==50 || i==56 || i==62 || i==68){
			cout << char(197);
		}else{
			cout << char(196);
		}
	}
	cout << char(180);
}

//	Footer tabel
void footer(){
	cout << char(192);
	for(int i=0; i<78; i++){
		if(i==7 || i==30 || i==44 || i==50 || i==56 || i==62 || i==68){
			cout << char(193);
		}else{
			cout << char(196);
		}
	}
	cout << char(217);
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

//	Menampilkan nama limit 20 karakter
string nama20(string x){
	if(x.length() > 20){
		string y;
		for(int i=0; i<20; i++){
			y += x[i];
		}
		return y;
	}else{
		return x;
	}
}

string bulan(string x){
	if(x == "JANUARI") return "JAN";
	else if(x == "FEBRUARI") return "FEB";
	else if(x == "MARET") return "MAR";
	else if(x == "APRIL") return "APR";
	else if(x == "MEI") return "MEI";
	else if(x == "JUNI") return "JUN";
	else if(x == "JULI") return "JUL";
	else if(x == "AGUSTUS") return "AGT";
	else if(x == "SEPTEMBER") return "SEP";
	else if(x == "OKTOBER") return "OKT";
	else if(x == "NOVEMBER") return "NOV";
	else return "DES";
}

string stasiun(string x){
	if(x == "BANDUNG") return "BDG";
	else if(x == "CIREBON") return "CRB";
	else if(x == "JAKARTA") return "JKT";
	else return "SBY";
}

string kelas(string x){
	if(x == "EKSEKUTIF") return "EKS";
	else if(x == "BISNIS") return "BIS";
	else return "EKO";
}

//	Fungsi untuk output data pembeli
void output(tiket data){
	body();
	cout << char(179) << " "
		 << setiosflags(ios::left) 
		 << setw(5) << data.kode 
		 << " " << char(179) << " "
		 << setw(20) << nama20(data.pembeli.nama) 
		 << " " << char(179) << " "
		 << setiosflags(ios::right) 
		 << setw(2) << data.pembeli.berangkat.tanggal 
		 << " " << bulan(data.pembeli.berangkat.bulan) << " "
		 << data.pembeli.berangkat.tahun 
		 << " " << char(179) << " "
		 << setw(3) << stasiun(data.pembeli.asal)
		 << " " << char(179) << " "
		 << setw(3) << stasiun(data.pembeli.tujuan)
		 << " " << char(179) << " "
		 << setw(3) << kelas(data.pembeli.kelas)
		 << " " << char(179) << "  "
		 << data.pembeli.jumlah 
		 << "  " << char(179) << " "
		 << setw(7) << data.pembeli.total 
		 << " " << char(179) 
		 << resetiosflags(ios::right);
}

//	Fungsi untuk memasukkan data pembeli pada queue
void enQueue(queue **node, tiket data){
	if(*node == NULL){
		*node = new queue;
		(*node)->info = data;
		(*node)->next = NULL;
	}else{
		enQueue(&((*node)->next), data);
	}
}

//	Fungsi untuk mengambil data pembeli pada queue
void deQueue(queue *node){
	if(node != NULL){
		output(node->info);
		deQueue(node->next);
	}	
}

//	Fungsi untuk mendapatkan nama bulan
string namaBulan(int bulan){
	switch(bulan){
		case 1  : return "JANUARI"; break;
		case 2  : return "FEBRUARI"; break;
		case 3  : return "MARET"; break;
		case 4  : return "APRIL"; break;
		case 5  : return "MEI"; break;
		case 6  : return "JUNI"; break;
		case 7  : return "JULI"; break;
		case 8  : return "AGUSTUS"; break;
		case 9  : return "SEPTEMBER"; break;
		case 10 : return "OKTOBER"; break;
		case 11 : return "NOVEMBER"; break;
		default : return "DESEMBER"; 
	}
}


//	Waktu sekarang
void waktu(){
	time_t now = time(0);
	char *dt = ctime(&now);	
	
	cout << endl << setiosflags(ios::right) << setw(53) << dt << resetiosflags(ios::right);
	getch();
}

//	Print tiket
void printTiket(queue *node){
	if(node->next == NULL){
		print(node);
	}else{
		printTiket(node->next);
	}
}

//	Lihat sebuah data pembeli
void lihat(queue *node){
	system("cls");
	header();
	output(node->info);
	footer();
}

//	Lihat data pembeli (tabel)
void lihatPembeli(queue *node){	
	system("cls");
	if(node != NULL){
		header();
		deQueue(node);
		footer();		
	}else{
		cout << "Data Kosong";
	}
}

//	Fungsi untuk random kode tiket
string kodeTiket(){
	string x;
	int y;	

	for(int i=0; i<2; i++){
		x += rand()%26 + 'A';		// random A-Z
	}

	y = rand()%900 + 100;			//	random 100-999

	return x+convertInt(y);
}

//	Cek kode tiket
bool cekKodeT(queue *node, string kode){
	while(node != NULL){
		if(node->info.kode == kode){		//	kode sudah ada
			return true;
			break;		
		}else{
			node = node->next;			
		}		
	}
}

//	Cek nama
bool cekNama(string nama){
	if(nama == ""){					// nama kosong
		return true;
	}
}

//	Fungsi untuk mengecek tanggal berangkat
bool cekTanggal(int d, int m, int y){
	if((d < 1) || (d > 30)) return true;			//	tanggal 1-30
	else if((m < 1) || (m > 12)) return true;		// 	bulan 1-12
	else if(y < 2013 || y > 2099) return true;		// 	tahun 2013-2099
	else return false;
}

int gerbong(int kodeK){
	switch(kodeK){
		case '1' : return (rand()%2+1); break;		// 	random 1-2 (Eks)
		case '2' : return (rand()%3+3); break;		// 	random 3-5 (Bis)
		case '3' : return (rand()%4+6); break;		// 	random 6-9 (Eko)
	}
}

bool cekKursi(queue *node, string a, int d, string m, int y, string w, int g, int k){
	string x = convertInt(k);
	while(node != NULL){
		if(node->info.pembeli.asal == a && 						// 	cekAsal
		   node->info.pembeli.berangkat.tanggal == d && 		// 	cekTanggal
		   node->info.pembeli.berangkat.bulan == m &&			// 	cekBulan
		   node->info.pembeli.berangkat.tahun == y &&			// 	cekTahun
		   node->info.pembeli.waktu == w &&						//	cekWaktu
		   node->info.kereta.gerbong == g && 					// 	cekGerbong
		   strstr(node->info.kereta.kursi.c_str(),x.c_str())){	//	cekKursi
			return true;
			break;
		}else{
			node = node->next;
		}
	}
}

//	Input data pembeli
void inputPembeli(queue *node, tiket &data){	
	int kodeSA, kodeST, kodeK, kodeW, bulan, kursi;
	data.pembeli.diskon = 0;
	data.pembeli.subtotal = 0;
	data.pembeli.total = 0;
	
	do{
		data.kode = kodeTiket();
	}while(cekKodeT(node,data.kode));

	cout << "Kode Tiket                     : " << data.kode << endl;
	
	do{
		cout << "Nama                           : "; fflush(stdin); getline(cin,data.pembeli.nama);
	}while(cekNama(data.pembeli.nama));
	
	data.pembeli.nama = uppercase(data.pembeli.nama);
	
	do{
	   printf("Tanggal Berangkat (dd mm yyyy) : "); scanf("%i %i %i",&data.pembeli.berangkat.tanggal,&bulan,&data.pembeli.berangkat.tahun);
	}while(cekTanggal(data.pembeli.berangkat.tanggal,bulan,data.pembeli.berangkat.tahun));		
	
	do{
		cout << "Kode Stasiun Asal              : "; kodeSA = getche();
		putchar('\n');
	}while((kodeSA < '1') || (kodeSA > '4'));

	do{
		cout << "Kode Stasiun Tujuan            : "; kodeST = getche();
		putchar('\n');
	}while((kodeST < '1') || (kodeST > '4') || (kodeSA == kodeST));

	do{
		cout << "Kode Kelas                     : "; kodeK = getche();
		putchar('\n');
	}while((kodeK < '1') || (kodeK > '3'));
	
	do{
		cout << "Kode Waktu Keberangkatan       : "; kodeW = getche();
		putchar('\n');
	}while(kodeW < '1' || kodeW > '3');

	do{
		cout << "Jumlah Tiket                   : "; cin >> data.pembeli.jumlah;
	}while(data.pembeli.jumlah < 1 || data.pembeli.jumlah > 5);
	
	data.pembeli.berangkat.bulan = namaBulan(bulan);
	data.pembeli.asal = namaStasiun(kodeSA);
	data.pembeli.tujuan = namaStasiun(kodeST);
	data.pembeli.kelas = namaKelas(kodeK);
	data.pembeli.waktu = namaWaktu(kodeW);
	data.kereta.kode = kodeKA(kodeSA);
	data.kereta.nama = namaKA(kodeSA);
	data.kereta.berangkat = jBerangkat(kodeSA,kodeST,kodeW);
	data.kereta.tiba = jTiba(kodeSA,kodeST,kodeW);
	
	a : 
		data.kereta.gerbong = gerbong(kodeK);
		b : 
			kursi = rand()%maxKursi+1;		//	random 1-50
			data.kereta.kursi = "";
			c :				
				if(kursi+data.pembeli.jumlah > maxKursi){
					goto b;
				}else{
					for(int i=0; i<data.pembeli.jumlah; i++){
						string k = convertInt(kursi);
						if(!cekKursi(node,
									 data.pembeli.asal,
									 data.pembeli.berangkat.tanggal,
									 data.pembeli.berangkat.bulan,
									 data.pembeli.berangkat.tahun,
									 data.pembeli.waktu,
									 data.kereta.gerbong,kursi)){
							if(i==0){
								data.kereta.kursi = k;
							}else{
								data.kereta.kursi += "_"+k;
							}
							++kursi;
						}else{
							goto a;
						}
					}					
				}			
	
	data.kereta.harga = harga(kodeSA,kodeST,kodeK);	
	data.pembeli.subtotal = data.pembeli.jumlah * data.kereta.harga;
	data.pembeli.diskon = diskon(data.pembeli.jumlah,data.pembeli.subtotal);
	data.pembeli.total = data.pembeli.subtotal - data.pembeli.diskon;
	data.kasir.nama = namaKasir(rand()%9 + 1);
}

//	Fungsi untuk mengecek kode tiket + posisi
bool cekKode(queue **node, string kode){
	while(*node != NULL){
		if((*node)->info.kode == kode){
			return true;
			break;
		}else{
			*node = (*node)->next;
		}
	}
}

//	Ubah data pembeli (Nama)
void ubahNama(queue *node){
	lihat(node);
	
	cout << "\n Nama       : "; fflush(stdin); getline(cin,node->info.pembeli.nama);
	node->info.pembeli.nama = uppercase(node->info.pembeli.nama);
	
	lihat(node);
	getch();
	print(node);
	getch();	
}

//	Ubah data pembeli (Tanggal Berangkat)
void ubahTanggal(queue *node){
	int bulan;
	lihat(node);
	
	do{
		printf("\n Tanggal Berangkat (dd mm yyyy) : "); 
		scanf("%i %i %i",&node->info.pembeli.berangkat.tanggal,&bulan,&node->info.pembeli.berangkat.tahun);
	}while(cekTanggal(node->info.pembeli.berangkat.tanggal,bulan,node->info.pembeli.berangkat.tahun));
			
	node->info.pembeli.berangkat.bulan = namaBulan(bulan);
	
	lihat(node);
	getch();
	print(node);
	getch();
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

int kodeWaktu(string nama){
	if(nama == "PAGI") return '1';
	else if(nama == "SIANG") return '2';
	else if(nama == "MALAM") return '3';
}

//	Ubah data pembeli (Stasiun Asal)
void ubahAsal(queue *node){
	int kodeSA, kodeST, kodeK, kodeW;
	lihat(node);
	
	kodeST = kodeStasiun(node->info.pembeli.tujuan);
	kodeK = kodeKelas(node->info.pembeli.kelas);
	kodeW = kodeWaktu(node->info.pembeli.waktu);
			
	do{
		cout << "\n Kode Stasiun Asal : "; kodeSA = getche();
	}while((kodeSA < '1') || (kodeSA > '4') || (kodeSA == kodeST));
	
	node->info.pembeli.asal = namaStasiun(kodeSA);
	node->info.kereta.kode = kodeKA(kodeSA);
	node->info.kereta.nama = namaKA(kodeSA);
	node->info.kereta.berangkat = jBerangkat(kodeSA,kodeST,kodeW);
	node->info.kereta.tiba = jTiba(kodeSA,kodeST,kodeW);
	node->info.kereta.harga = harga(kodeSA,kodeST,kodeK);	
	node->info.pembeli.subtotal = node->info.pembeli.jumlah * node->info.kereta.harga;
	node->info.pembeli.diskon = diskon(node->info.pembeli.jumlah,node->info.pembeli.subtotal);
	node->info.pembeli.total = node->info.pembeli.subtotal - node->info.pembeli.diskon;
	lihat(node);
	getch();
	print(node);
	getch();	
}

//	Ubah data pembeli (Stasiun Tujuan)
void ubahTujuan(queue *node){
	int kodeSA, kodeST, kodeK, kodeW;
	lihat(node);
	
	kodeSA = kodeStasiun(node->info.pembeli.asal);
	kodeK = kodeKelas(node->info.pembeli.kelas);
	kodeW = kodeWaktu(node->info.pembeli.waktu);
	
	do{
		cout << "\n Kode Stasiun Tujuan : "; kodeST = getche();
	}while((kodeST < '1') || (kodeST > '4') || (kodeSA == kodeST));
	
	node->info.pembeli.tujuan = namaStasiun(kodeST);
	node->info.kereta.kode = kodeKA(kodeSA);
	node->info.kereta.nama = namaKA(kodeSA);
	node->info.kereta.berangkat = jBerangkat(kodeSA,kodeST,kodeW);
	node->info.kereta.tiba = jTiba(kodeSA,kodeST,kodeW);
	node->info.kereta.harga = harga(kodeSA,kodeST,kodeK);
	node->info.pembeli.subtotal = node->info.pembeli.jumlah * node->info.kereta.harga;
	node->info.pembeli.diskon = diskon(node->info.pembeli.jumlah,node->info.pembeli.subtotal);
	node->info.pembeli.total = node->info.pembeli.subtotal - node->info.pembeli.diskon;
	
	lihat(node);
	getch();
	print(node);
	getch();	
}

//	Ubah data pembeli (Kelas)
void ubahKelas(queue *node){
	int kodeSA, kodeST, kodeK;
	lihat(node);
	
	kodeSA = kodeStasiun(node->info.pembeli.asal);
	kodeST = kodeStasiun(node->info.pembeli.tujuan);
	
	do{
		cout << "\n Kode Kelas : "; kodeK = getche();
	}while((kodeK < '1') || (kodeK > '3'));
	
	node->info.pembeli.kelas = namaKelas(kodeK);
	node->info.kereta.harga = harga(kodeSA,kodeST,kodeK);
	node->info.pembeli.subtotal = node->info.pembeli.jumlah * node->info.kereta.harga;
	node->info.pembeli.diskon = diskon(node->info.pembeli.jumlah,node->info.pembeli.subtotal);
	node->info.pembeli.total = node->info.pembeli.subtotal - node->info.pembeli.diskon;	
	
	lihat(node);
	getch();
	print(node);
	getch();		
}

//	Ubah data pembeli (Waktu Keberangkatan)
void ubahWaktu(queue *node){
	int kodeW, kodeSA, kodeST;
	lihat(node);
	
	kodeSA = kodeStasiun(node->info.pembeli.asal);
	kodeST = kodeStasiun(node->info.pembeli.tujuan);	
	
	do{
		cout << "\n Kode Waktu Keberangkatan : "; kodeW = getche();
	}while((kodeW < '1') || (kodeW > '3'));
	
	node->info.pembeli.waktu = namaWaktu(kodeW);
	node->info.kereta.berangkat = jBerangkat(kodeSA,kodeST,kodeW);
	node->info.kereta.tiba = jTiba(kodeSA,kodeST,kodeW);	
	
	lihat(node);
	getch();
	print(node);
	getch();
}

//	Ubah data pembeli (Jumlah)
void ubahJumlah(queue *node){
	lihat(node);
	
	do{
		cout << "\n Jumlah Tiket : "; fflush(stdin); cin >> node->info.pembeli.jumlah;
	}while(node->info.pembeli.jumlah < 1 || node->info.pembeli.jumlah > 5);
	
	node->info.pembeli.subtotal = node->info.pembeli.jumlah * node->info.kereta.harga;
	node->info.pembeli.diskon = diskon(node->info.pembeli.jumlah,node->info.pembeli.subtotal);
	node->info.pembeli.total = node->info.pembeli.subtotal - node->info.pembeli.diskon;	
	
	lihat(node);
	getch();
	print(node);
	getch();
}

//	Menu ubah data pembeli
void ubahPembeli(queue *node){
	string kode;
	
	if(node != NULL){
		lihatPembeli(node);
		cout << "\n Kode Tiket : "; fflush(stdin); getline(cin,kode);
		kode = uppercase(kode);
		
		if(cekKode(&node,kode) && kode != ""){
			system("cls");
			int menu;
			do{
				do{
					system("cls");
					gotoxy(27,7);  cout << "{ 1 }  Nama";
					gotoxy(27,8);  cout << "{ 2 }  Tanggal Berangkat";
					gotoxy(27,9);  cout << "{ 3 }  Stasiun Asal";
					gotoxy(27,10); cout << "{ 4 }  Stasiun Tujuan";
					gotoxy(27,11); cout << "{ 5 }  Kelas";
					gotoxy(27,12); cout << "{ 6 }  Waktu Keberangkatan";
					gotoxy(27,13); cout << "{ 7 }  Jumlah";
					gotoxy(27,14); cout << "{ 0 }  Menu Sebelumnya";
					gotoxy(27,16); type("       Pilihan : "); menu = getche();
				}while(menu > '7');
				loading(26);
				system("cls");
				switch(menu){
					case '1' : 	ubahNama(node);
								break;									
					case '2' :	ubahTanggal(node);
								break;
					case '3' :	ubahAsal(node);
								break;
					case '4' :	ubahTujuan(node);
								break;
					case '5' :	ubahKelas(node);
								break;
					case '6' : 	ubahWaktu(node);
								break;
					case '7' :	ubahJumlah(node);
								break;
				}								
			}while(menu != '0');				
		}else{
			cout << "\n Data Tidak Ada";
			getch();
		}		
	}else{
		gotoxy(35,12); textcolor(12); cout << "Data Kosong";
		textcolor(7);
		getch();		
	}
}

//	Cari kode tiket
void cariKode(queue *node){
	string kode;
	cout << "Kode Tiket : "; fflush(stdin); getline(cin,kode);
	
	if(cekKode(&node,kode) && kode != ""){
		lihat(node);
	}else{
		cout << "\nData tidak ditemukan.";		
	}
	
	getch();
}

//	Cari nama pembeli (substring applied)
void cariNama(queue *node){
	string nama;
	int x;
	cout << "Nama : "; fflush(stdin); getline(cin,nama);
	nama = uppercase(nama);
	
	system("cls");
	header();
	
	while(node != NULL){
		if(strstr(node->info.pembeli.nama.c_str(),nama.c_str()) && nama != ""){
			++x;
			output(node->info);
			node = node->next;
		}else{
			node = node->next;
		}
	}
	
	footer();
	
	if(x == 0){
		gotoxy(30,4); textcolor(12); cout << "Data tidak ditemukan";
		textcolor(7);
	}	
	getch();
}

//	Cari asal (substring applied)
void cariAsal(queue *node){
	int x;
	string nama;	
	cout << "Nama Stasiun : "; fflush(stdin); getline(cin,nama);
	nama = uppercase(nama);
	
	system("cls");
	header();
	
	while(node != NULL){
		if(strstr(node->info.pembeli.asal.c_str(),nama.c_str()) && nama != ""){
			++x;
			output(node->info);
			node = node->next;
		}else{
			node = node->next;
		}
	}
	
	footer();
	
	if(x == 0){
		gotoxy(30,4); textcolor(12); cout << "Data tidak ditemukan";
		textcolor(7);
	}	
	getch();	
}

//	Cari tujuan (substring applied)
void cariTujuan(queue *node){
	int x;
	string nama;	
	cout << "Nama Stasiun : "; fflush(stdin); getline(cin,nama);
	nama = uppercase(nama);
	
	system("cls");
	header();
	
	while(node != NULL){
		if(strstr(node->info.pembeli.tujuan.c_str(),nama.c_str()) && nama != ""){
			++x;
			output(node->info);
			node = node->next;
		}else{
			node = node->next;
		}
	}
	
	footer();
	
	if(x == 0){
		gotoxy(30,4); textcolor(12); cout << "Data tidak ditemukan";
		textcolor(7);
	}	
	getch();	
}

//	Cari kelas (substring apllied)
void cariKelas(queue *node){
	int x;
	string nama;	
	cout << "Nama Kelas : "; fflush(stdin); getline(cin,nama);
	nama = uppercase(nama);
	
	system("cls");
	header();
	
	while(node != NULL){
		if(strstr(node->info.pembeli.kelas.c_str(),nama.c_str()) && nama != ""){
			++x;
			output(node->info);
			node = node->next;
		}else{
			node = node->next;
		}
	}
	
	footer();
	
	if(x == 0){
		gotoxy(30,4); textcolor(12); cout << "Data tidak ditemukan";
		textcolor(7);
	}	
	getch();	
}

//	Menu cari data pembeli
void cariPembeli(queue *node){
	int menu;
	if(node != NULL){
		do{
			do{
				system("cls");
				gotoxy(29,8);  cout << "{ 1 }  Kode Tiket";
				gotoxy(29,9);  cout << "{ 2 }  Nama";
				gotoxy(29,10); cout << "{ 3 }  Stasiun Asal";
				gotoxy(29,11); cout << "{ 4 }  Stasiun Tujuan";
				gotoxy(29,12); cout << "{ 5 }  Kelas";
				gotoxy(29,13); cout << "{ 0 }  Menu Sebelumnya";
				gotoxy(29,15); type("       Pilihan : "); menu = getche();
			}while(menu > '6');
			loading(23);
			system("cls");
			switch(menu){
				case '1' :	cariKode(node);
							break;
				case '2' :	cariNama(node);
							break;
				case '3' :	cariAsal(node);
							break;
				case '4' :	cariTujuan(node);
							break;
				case '5' :	cariKelas(node);
							break;
			}
		}while(menu != '0');		
	}else{
		gotoxy(35,12); textcolor(12); cout << "Data Kosong";
		textcolor(7);
		getch();
	}
}

//	Fungsi untuk menghapus data pembeli
void deleteP(queue **node, string kode){
	queue *hapus;
	if(*node != NULL){
		if((*node)->info.kode == kode){
			hapus = *node;
			*node = hapus->next;
			hapus = NULL;		
		}else if((*node)->next->info.kode == kode){
			hapus = (*node)->next;
			(*node)->next = hapus->next;
			hapus = NULL;		
		}else{
			deleteP(&((*node)->next), kode);
		}
	}
}

//	Hapus data pembeli berdasarkan kode tiket
void hapusPembeli(queue **node){
	string kode;	
	
	if(node != NULL){
		lihatPembeli(*node);
		cout << "\n Kode Tiket : "; fflush(stdin); getline(cin,kode);
		kode = uppercase(kode);
		
		if(cekKodeT(*node,kode)){
			deleteP(&(*node),kode);	
			lihatPembeli(*node);			
		}else{
			cout << "\n Data tidak ada";
		}
	}else{
		gotoxy(35,12); textcolor(12); cout << "Data Kosong";
		textcolor(7);		
	}

	getch();
}

//	Ubah " " nama dengan "_" supaya bisa di load
string _Nama(string x){
	for(int i=0; i<x.length(); i++){
		if(x[i] == ' '){
			x[i] = '_';
		}
	}
	return x;
}

//	Ubah "_" nama dengan " "
string Nama(string x){
	for(int i=0; i<x.length(); i++){
		if(x[i] == '_'){
			x[i] = ' ';
		}
	}
	return x;
}

//	Load data pembeli pada file "dataPembeli.dat"
void loadPembeli(queue **node, tiket &data){
	ifstream fin("dataPembeli.dat");
	
	if(fin){
		while(!fin.eof()){
		fin	>> data.kode
			>> data.pembeli.nama;
			   data.pembeli.nama = Nama(data.pembeli.nama);
		fin >> data.pembeli.berangkat.tanggal
			>> data.pembeli.berangkat.bulan
			>> data.pembeli.berangkat.tahun
			>> data.pembeli.asal
			>> data.pembeli.tujuan
			>> data.pembeli.kelas
			>> data.pembeli.waktu
			>> data.kereta.kode
			>> data.kereta.nama
			>> data.kereta.berangkat
			>> data.kereta.tiba
			>> data.kereta.gerbong
			>> data.kereta.kursi
			>> data.kereta.harga
			>> data.pembeli.jumlah			
			>> data.pembeli.subtotal
			>> data.pembeli.diskon
			>> data.pembeli.total
			>> data.kasir.nama;
			
			enQueue(&(*node),data);
		}
	}
	
	fin.close();
}

// 	Upload data pembeli ke dataPembeli.dat
void uploadPembeli(queue *node, tiket data){
	ofstream fout("dataPembeli.dat",ios::trunc);
	
	while(node != NULL){		
		fout << "\n  "
			 << setiosflags(ios::left)
			 << setw(5) << node->info.kode << "  "
			 << setw(25) << _Nama(node->info.pembeli.nama) << "  "
			 << setiosflags(ios::right)
			 << setw(2) << node->info.pembeli.berangkat.tanggal << " "
			 << resetiosflags(ios::right)
			 << setiosflags(ios::left)
			 << setw(9) << node->info.pembeli.berangkat.bulan << " "
			 << setw(4) << node->info.pembeli.berangkat.tahun << "  "
			 << setw(8) << node->info.pembeli.asal << "  "
			 << setw(8) << node->info.pembeli.tujuan << "  "
			 << setw(9) << node->info.pembeli.kelas << "  "
			 << setw(5) << node->info.pembeli.waktu << "  "
			 << setw(6) << node->info.kereta.kode << "  "
			 << setw(12) << node->info.kereta.nama << "  "
			 << setw(5) << node->info.kereta.berangkat << "  "
			 << setw(5) << node->info.kereta.tiba << "  "
			 << node->info.kereta.gerbong << "  "
			 << setw(15) << node->info.kereta.kursi << "  "
			 << setw(6) << node->info.kereta.harga << "  "
			 << node->info.pembeli.jumlah << "  "			 
			 << setiosflags(ios::right)			 
			 << setw(8) << node->info.pembeli.subtotal << "  "
			 << setw(7) << node->info.pembeli.diskon << "  "
			 << setw(8) << node->info.pembeli.total << "  "
			 << resetiosflags(ios::right)
			 << setiosflags(ios::left)
			 << node->info.kasir.nama;
		node = node->next;
	}
	
	fout.close();
}

//	Membebaskan kembali memori
void destroy(queue *node){
	if(node != NULL){
		delete node;
		destroy(node->next);
	}
}

//	Menu data pembeli
void menuPembeli(queue **node, tiket data){
	int menu;
	char lagi;
	do{
		do{
			system("cls");
			gotoxy(28,8);  cout << "{ 1 }  Input Data Pembeli";
			gotoxy(28,9);  cout << "{ 2 }  Ubah  Data Pembeli";
			gotoxy(28,10); cout << "{ 3 }  Cari  Data Pembeli";
			gotoxy(28,11); cout << "{ 4 }  Hapus Data Pembeli";
			gotoxy(28,12); cout << "{ 5 }  Lihat Data Pembeli";
			gotoxy(28,13); cout << "{ 0 }  Menu Utama";
			gotoxy(28,15); type("       Pilihan : "); menu = getche();
		}while(menu > '5');
		loading(25);
		system("cls");
		switch(menu){								
			case '1' : 	do{
							system("cls");
							info();
							inputPembeli(*node,data);
							enQueue(&(*node),data);
							printTiket(*node);
							putchar('\n');
							do{
								putchar('\n');
								cout << setiosflags(ios::left)
									 << setw(33) << " ";
								type (" Input Lagi : "); lagi = getche();
								lagi = toupper(lagi);
							}while(!(lagi == 'Y' || lagi == 'T'));
						}while(lagi == 'Y');
						break;
			case '2' : 	ubahPembeli(*node);
						break;
			case '3' :	cariPembeli(*node);
						break;
			case '4' :	hapusPembeli(&(*node));
						break;
			case '5' : 	lihatPembeli(*node);
						waktu();
						break;			
		}
	}while(menu != '0');
}
