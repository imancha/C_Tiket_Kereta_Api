/*	Start of Input Data Pembeli	*/
//	Blueprint tiket
void print(queue *node){
	system("cls");
	textcolor(15);
	cout << char(218); for(int i=0; i<78; i++) cout << char(196); cout << char(191);
	cout << char(179) << "  Nama :  " << setiosflags(ios::left) << setw(36) << node->info.pembeli.nama << "  Kode Tiket :  " << setw(16) << node->info.kode << char(179);
	cout << char(195); for(int i=0; i<78; i++) cout << char(196); cout << char(180);
	cout << char(179) << "  Tanggal Berangkat :  " << setw(2) << node->info.pembeli.berangkat.tanggal << " " << setw(9) << node->info.pembeli.berangkat.bulan << " " << setw(42) << node->info.pembeli.berangkat.tahun << char(179);
	cout << char(179) << setw(48) << " " << "No. KA :  " << setw(20) << noKA(node->info.kereta.kode) << char(179);
	cout << char(179) << "  Nama KA           :  " << setw(55) << node->info.kereta.nama << char(179);
	cout << char(195); for(int i=0; i<78; i++) cout << char(196); cout << char(180);
	cout << char(179) << "  Jadwal Berangkat  :  " << setw(23) << node->info.kereta.berangkat << "  Jadwal Tiba :  " << setw(15) << node->info.kereta.tiba << char(179);
	cout << char(179) << setw(78) << " " << char(179);
	cout << char(179) << setiosflags(ios::right) << setw(20) << node->info.pembeli.asal << setw(32) << " " << resetiosflags(ios::right) << setiosflags(ios::left) << setw(26) << node->info.pembeli.tujuan << char(179);
	cout << char(195); for(int i=0; i<78; i++) cout << char(196); cout << char(180);
	cout << char(179) << setw(24) << "  Kelas :  " << setw(25) << "  No. Gerbong :  " << setw(29) << "  Nomor Tempat Duduk :  " << char(179);
	cout << char(179) << setw(78) << " " << char(179);
	cout << char(179) << "     " << setw(26) << node->info.pembeli.kelas << setw(26) << node->info.kereta.gerbong << setw(21) << node->info.kereta.kursi << char(179);
	cout << char(195); for(int i=0; i<78; i++) cout << char(196); cout << char(180);
	cout << char(179) << setw(16) << "  Jumlah :  " << setw(22) << "  Harga (Rp) : " << setw(18) << " Diskon : " << setw(22) << " Jumlah (Rp) : " << char(179);
	cout << char(179) << setiosflags(ios::right) << setw(6) << node->info.pembeli.jumlah << setw(22) << node->info.kereta.harga << setw(45) << node->info.pembeli.subtotal << setw(6) << char(179);
	cout << char(179) << setw(45) << diskon(node->info.pembeli.jumlah) << setw(28) << node->info.pembeli.diskon << setw(6) << char(179);
	cout << char(195); for(int i=0; i<78; i++) cout << char(196); cout << char(180);
	cout << char(179) << "  Kasir :  " << resetiosflags(ios::right) << setiosflags(ios::left) << setw(37) << uppercase(node->info.kasir.username) << "  Total (Rp) :  " << setiosflags(ios::right) << setw(9) << node->info.pembeli.total << setw(6) << char(179);
	cout << char(192);for(int i=0; i<78; i++) cout << char(196); cout << char(217) << resetiosflags(ios::right);
	textcolor(7);
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

//	Menampilkan nama maksimum 20 karakter
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
//	body();
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
	body();
	output(node->info);
	footer();
}

//	Lihat semua data pembeli (tabel)
void lihatPembeli(queue *node){	
	system("cls");
	if(node != NULL){
		header();
		body();
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
		gotoxy(47,whereY()-2); textcolor(12); printf("Nama tidak boleh kosong !\n"); textcolor(7);
		return true;
	}
}

//	Fungsi untuk mengecek tanggal berangkat
bool cekTanggal(int d, int m, int y){
	if((d < 1) || (d > 30)){
	 	gotoxy(58,whereY()-2); textcolor(12); printf("Tanggal 1-30 !\n"); textcolor(7);
		return true;			//	tanggal 1-30
	}
	if((m < 1) || (m > 12)){
	 	gotoxy(60,whereY()-2); textcolor(12); printf("Bulan 1-12 !\n"); textcolor(7);
	 	return true;		// 	bulan 1-12
	}
	if(y < 2013 || y > 2099){
		gotoxy(55,whereY()-2); textcolor(12); printf("Tahun 2013-2099 !\n"); textcolor(7);
	 	return true;		// 	tahun 2013-2099	 	
	}
	return false;
}

//	Cek kode stasiun asal
bool cekKodeS(int x){
	if(x < '1' || x > '4'){
		gotoxy(62,whereY()-2); textcolor(12); printf("Kode 1-4 !\n"); textcolor(7);
		return true;
	}
	return false;
}

//	Cek kode stasiun tujuan
bool cekKodeD(int x, int y){
	if(x == y){
		gotoxy(57,whereY()-2); textcolor(12); printf("Asal = Tujuan !\n"); textcolor(7);
		return true;
	}
	if(x < '1' || x > '4'){
		gotoxy(62,whereY()-2); textcolor(12); printf("Kode 1-4 !\n"); textcolor(7);
		return true;
	}
	return false;
}

//	Cek kode kelas
bool cekKodeK(int x){
	if(x < '1' || x > '3'){
		gotoxy(62,whereY()-2); textcolor(12); printf("Kode 1-3 !\n"); textcolor(7);
		return true;
	}
	return false;
}

//	Cek jumlah tiket
bool cekJumlah(int x){
	if(x < 1 || x > 5){
		gotoxy(60,whereY()-2); textcolor(12); printf("Jumlah 1-5 !\n"); textcolor(7);
		return true;
	}
	return false;
}

//	Get nomor gerbong kereta
int gerbong(int kodeK){
	switch(kodeK){
		case '1' : return (rand()%2+1); break;		// 	random 1-2 (Eks)
		case '2' : return (rand()%3+3); break;		// 	random 3-5 (Bis)
		case '3' : return (rand()%4+6); break;		// 	random 6-9 (Eko)
	}
}

//	Get nomor kursi
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
void inputPembeli(queue *node, tiket &data, string kasir){	
	int kodeSA, kodeST, kodeK, kodeW, bulan, kursi;
	data.pembeli.diskon = 0;
	data.pembeli.subtotal = 0;
	data.pembeli.total = 0;
	
	do{
		data.kode = kodeTiket();
	}while(cekKodeT(node,data.kode));

	cout << "\t\b" << char(250) << "Kode Tiket                     :  " << data.kode << endl;
	
	do{
		cout << "\t\b" << char(250) << "Nama                           :  "; fflush(stdin); getline(cin,data.pembeli.nama);
	}while(cekNama(data.pembeli.nama));
	
	data.pembeli.nama = uppercase(data.pembeli.nama);
	
	do{
	   cout << "\t\b" << char(250);
	   printf("Tanggal Berangkat (dd mm yyyy) :  "); 
	   scanf("%i %i %i",&data.pembeli.berangkat.tanggal,&bulan,&data.pembeli.berangkat.tahun);
	}while(cekTanggal(data.pembeli.berangkat.tanggal,bulan,data.pembeli.berangkat.tahun));		
	
	do{
		cout << "\t\b" << char(250) << "Kode Stasiun Asal              :  "; kodeSA = getche();
		putchar('\n');
	}while(cekKodeS(kodeSA));

	do{
		cout << "\t\b" << char(250) << "Kode Stasiun Tujuan            :  "; kodeST = getche();
		putchar('\n');
	}while(cekKodeD(kodeST,kodeSA));

	do{
		cout << "\t\b" << char(250) << "Kode Kelas                     :  "; kodeK = getche();
		putchar('\n');
	}while(cekKodeK(kodeK));
	
	do{
		cout << "\t\b" << char(250) << "Kode Waktu Keberangkatan       :  "; kodeW = getche();
		putchar('\n');
	}while(cekKodeK(kodeW));

	do{
		cout << "\t\b" << char(250) << "Jumlah Tiket                   :  "; cin >> data.pembeli.jumlah;
	}while(cekJumlah(data.pembeli.jumlah));
	
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
	data.kasir.username = kasir;
}
/*	End of Input Data Pembeli	*/

/*	Start of Ubah Data Pembeli	*/
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
	
	do{
		type("\n Nama       : "); fflush(stdin); getline(cin,node->info.pembeli.nama);
	}while(cekNama(node->info.pembeli.nama));
		
	node->info.pembeli.nama = uppercase(node->info.pembeli.nama);
	
	lihat(node); getch();
	print(node); getch();	
}

//	Ubah data pembeli (Tanggal Berangkat)
void ubahTanggal(queue *node){
	int bulan;
	lihat(node);
	
	do{
		type("\n Tanggal Berangkat (dd mm yyyy) : "); 
		scanf("%i %i %i",&node->info.pembeli.berangkat.tanggal,&bulan,&node->info.pembeli.berangkat.tahun);
	}while(cekTanggal(node->info.pembeli.berangkat.tanggal,bulan,node->info.pembeli.berangkat.tahun));
			
	node->info.pembeli.berangkat.bulan = namaBulan(bulan);
	
	lihat(node); getch();
	print(node); getch();
}

//	Ubah data pembeli (Stasiun Asal)
void ubahAsal(queue *node){
	int kodeSA, kodeST, kodeK, kodeW;
	lihat(node);
	putchar('\n');
	info();
	
	kodeST = kodeStasiun(node->info.pembeli.tujuan);
	kodeK = kodeKelas(node->info.pembeli.kelas);
	kodeW = kodeWaktu(node->info.pembeli.waktu);
			
	do{
		type("\t Kode Stasiun Asal : "); kodeSA = getche();
		putchar('\n');
	}while(cekKodeD(kodeSA,kodeST));
	
	node->info.pembeli.asal = namaStasiun(kodeSA);											//	kalau stasiun asal dirubah maka,
	node->info.kereta.kode = kodeKA(kodeSA);													//	kode kereta dirubah
	node->info.kereta.nama = namaKA(kodeSA);													//	nama kereta dirubah
	node->info.kereta.berangkat = jBerangkat(kodeSA,kodeST,kodeW);								//	jadwal kereta berangkat diubah
	node->info.kereta.tiba = jTiba(kodeSA,kodeST,kodeW);										//	jadwal kereta tiba diubah
	node->info.kereta.harga = harga(kodeSA,kodeST,kodeK);										//	harga tiket kereta diubah
	node->info.pembeli.subtotal = node->info.pembeli.jumlah * node->info.kereta.harga;			//	subtotal diubah
	node->info.pembeli.diskon = diskon(node->info.pembeli.jumlah,node->info.pembeli.subtotal);	//	diskon diubah
	node->info.pembeli.total = node->info.pembeli.subtotal - node->info.pembeli.diskon;			//	total diubah
	lihat(node); getch();
	print(node); getch();	
}

//	Ubah data pembeli (Stasiun Tujuan)
void ubahTujuan(queue *node){
	int kodeSA, kodeST, kodeK, kodeW;
	lihat(node);
	putchar('\n');
	info();
	
	kodeSA = kodeStasiun(node->info.pembeli.asal);
	kodeK = kodeKelas(node->info.pembeli.kelas);
	kodeW = kodeWaktu(node->info.pembeli.waktu);
	
	do{
		type("\t Kode Stasiun Tujuan : "); kodeST = getche();
		putchar('\n');
	}while(cekKodeD(kodeST,kodeSA));
	
	node->info.pembeli.tujuan = namaStasiun(kodeST);
	node->info.kereta.kode = kodeKA(kodeSA);
	node->info.kereta.nama = namaKA(kodeSA);
	node->info.kereta.berangkat = jBerangkat(kodeSA,kodeST,kodeW);
	node->info.kereta.tiba = jTiba(kodeSA,kodeST,kodeW);
	node->info.kereta.harga = harga(kodeSA,kodeST,kodeK);
	node->info.pembeli.subtotal = node->info.pembeli.jumlah * node->info.kereta.harga;
	node->info.pembeli.diskon = diskon(node->info.pembeli.jumlah,node->info.pembeli.subtotal);
	node->info.pembeli.total = node->info.pembeli.subtotal - node->info.pembeli.diskon;
	
	lihat(node); getch();
	print(node); getch();	
}

//	Ubah data pembeli (Kelas)
void ubahKelas(queue *node){
	int kodeSA, kodeST, kodeK, kursi;
	lihat(node);
	putchar('\n');
	info();
	
	kodeSA = kodeStasiun(node->info.pembeli.asal);
	kodeST = kodeStasiun(node->info.pembeli.tujuan);
	
	do{
		type("\t Kode Kelas : "); kodeK = getche();
		putchar('\n');
	}while(cekKodeK(kodeK));
	
	node->info.pembeli.kelas = namaKelas(kodeK);							//	kalau kelas diubah maka,
	
	a : 
		node->info.kereta.gerbong = gerbong(kodeK);								//	nomor gerbong pada tiket diubah
		b : 
			kursi = rand()%maxKursi+1;		//	random 1-50
			node->info.kereta.kursi = "";										//	nomor kursi pada tiket diubah
			c :				
				if(kursi+node->info.pembeli.jumlah > maxKursi){
					goto b;
				}else{
					for(int i=0; i<node->info.pembeli.jumlah; i++){
						string k = convertInt(kursi);
						if(!cekKursi(node,
									 node->info.pembeli.asal,
									 node->info.pembeli.berangkat.tanggal,
									 node->info.pembeli.berangkat.bulan,
									 node->info.pembeli.berangkat.tahun,
									 node->info.pembeli.waktu,
									 node->info.kereta.gerbong,kursi)){
							if(i==0){
								node->info.kereta.kursi = k;
							}else{
								node->info.kereta.kursi += "_"+k;
							}
							++kursi;
						}else{
							goto a;
						}
					}					
				}	
	
	node->info.kereta.harga = harga(kodeSA,kodeST,kodeK);
	node->info.pembeli.subtotal = node->info.pembeli.jumlah * node->info.kereta.harga;
	node->info.pembeli.diskon = diskon(node->info.pembeli.jumlah,node->info.pembeli.subtotal);
	node->info.pembeli.total = node->info.pembeli.subtotal - node->info.pembeli.diskon;	
	
	lihat(node); getch();
	print(node); getch();		
}

//	Ubah data pembeli (Waktu Keberangkatan)
void ubahWaktu(queue *node){
	int kodeW, kodeSA, kodeST;
	lihat(node);
	putchar('\n');
	info();
	
	kodeSA = kodeStasiun(node->info.pembeli.asal);
	kodeST = kodeStasiun(node->info.pembeli.tujuan);	
	
	do{
		type("\t Kode Waktu Keberangkatan : "); kodeW = getche();
		putchar('\n');
	}while(cekKodeK(kodeW));
	
	node->info.pembeli.waktu = namaWaktu(kodeW);
	node->info.kereta.berangkat = jBerangkat(kodeSA,kodeST,kodeW);
	node->info.kereta.tiba = jTiba(kodeSA,kodeST,kodeW);	
	
	lihat(node); getch();
	print(node); getch();
}

//	Ubah data pembeli (Jumlah)
void ubahJumlah(queue *node){
	int kodeK, kursi;
	lihat(node);
	
	kodeK = kodeKelas(node->info.pembeli.kelas);
	
	do{
		type("\n Jumlah Tiket : "); fflush(stdin); cin >> node->info.pembeli.jumlah;
	}while(cekJumlah(node->info.pembeli.jumlah));
	
	a : 
		node->info.kereta.gerbong = gerbong(kodeK);
		b : 
			kursi = rand()%maxKursi+1;		//	random 1-50
			node->info.kereta.kursi = "";
			c :				
				if(kursi+node->info.pembeli.jumlah > maxKursi){
					goto b;
				}else{
					for(int i=0; i<node->info.pembeli.jumlah; i++){
						string k = convertInt(kursi);
						if(!cekKursi(node,
									 node->info.pembeli.asal,
									 node->info.pembeli.berangkat.tanggal,
									 node->info.pembeli.berangkat.bulan,
									 node->info.pembeli.berangkat.tahun,
									 node->info.pembeli.waktu,
									 node->info.kereta.gerbong,kursi)){
							if(i==0){
								node->info.kereta.kursi = k;
							}else{
								node->info.kereta.kursi += "_"+k;
							}
							++kursi;
						}else{
							goto a;
						}
					}					
				}		
	
	node->info.pembeli.subtotal = node->info.pembeli.jumlah * node->info.kereta.harga;
	node->info.pembeli.diskon = diskon(node->info.pembeli.jumlah,node->info.pembeli.subtotal);
	node->info.pembeli.total = node->info.pembeli.subtotal - node->info.pembeli.diskon;	
	
	lihat(node); getch();
	print(node); getch();
}

//	Menu ubah data pembeli
void ubahPembeli(queue *node){
	string kode;
	
	if(node != NULL){
		lihatPembeli(node);
		type("\n Kode Tiket : "); fflush(stdin); getline(cin,kode);
		kode = uppercase(kode);
		
		if(cekKode(&node,kode) && kode != ""){
			system("cls");
			int menu;
			do{
				do{
					system("cls");
					kotak(12,39);
					gotoxy(25,7);  cout << "    MENU UBAH DATA PEMBELI";
					gotoxy(25,9);  cout << "{ 1 }  Ubah Nama";
					gotoxy(25,10); cout << "{ 2 }  Ubah Tanggal Berangkat";
					gotoxy(25,11); cout << "{ 3 }  Ubah Stasiun Asal";
					gotoxy(25,12); cout << "{ 4 }  Ubah Stasiun Tujuan";
					gotoxy(25,13); cout << "{ 5 }  Ubah Kelas";
					gotoxy(25,14); cout << "{ 6 }  Ubah Waktu Keberangkatan";
					gotoxy(25,15); cout << "{ 7 }  Ubah Jumlah";
					gotoxy(25,16); cout << "{ 0 }  Menu Sebelumnya";
					gotoxy(25,18); type("          PILIHAN : "); menu = getche();
				}while(menu > '7');
				loading(39);
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
/*	End of Ubah Data Pembeli	*/

/*	Start of Cari Data Pembeli	*/
//	Cari kode tiket (substring applied)
void cariKode(queue *node){
	string kode;
	int x;
	kotak(1,24);
	gotoxy(32,14); textcolor(8); cout << "contoh : ka, ka123"; textcolor(7);
	gotoxy(32,12); type("Kode Tiket : "); fflush(stdin); getline(cin,kode);

	kode = uppercase(kode);
	
	system("cls");
	header();
	
	while(node != NULL){
		if(strstr(node->info.kode.c_str(),kode.c_str()) && kode != ""){			//	c_str() : convert string to char
			++x;
			body();
			output(node->info);
			node = node->next;
		}else{
			node = node->next;
		}
	}
	
	footer();
	
	if(x == 0){
		gotoxy(30,4); textcolor(12); type("Data tidak ditemukan...");
		textcolor(7);
	}
	
	getch();
}

//	Cari nama pembeli (substring applied)
void cariNama(queue *node){
	string nama;
	int x;
	kotak(1,38);
	gotoxy(25,14); textcolor(8); cout << "contoh : im, imancha"; textcolor(7);
	gotoxy(25,12); type("Nama : "); fflush(stdin); getline(cin,nama);
	nama = uppercase(nama);
	
	system("cls");
	header();
	
	while(node != NULL){
		if(strstr(node->info.pembeli.nama.c_str(),nama.c_str()) && nama != ""){			//	c_str() : convert string to char
			++x;
			body();
			output(node->info);
			node = node->next;
		}else{
			node = node->next;
		}
	}
	
	footer();
	
	if(x == 0){
		gotoxy(30,4); textcolor(12); type("Data tidak ditemukan...");
		textcolor(7);
	}	
	getch();
}

//	Cari asal (substring applied)
void cariAsal(queue *node){
	int x;
	string nama;	
	kotak(1,29);
	gotoxy(30,14); textcolor(8); cout << "contoh : ci, cirebon"; textcolor(7);
	gotoxy(30,12); type("Nama Stasiun : "); fflush(stdin); getline(cin,nama);
	nama = uppercase(nama);
	
	system("cls");
	header();
	
	while(node != NULL){
		if(strstr(node->info.pembeli.asal.c_str(),nama.c_str()) && nama != ""){			//	c_str() : convert string to char
			++x;
			body();
			output(node->info);
			node = node->next;
		}else{
			node = node->next;
		}
	}
	
	footer();
	
	if(x == 0){
		gotoxy(30,4); textcolor(12); type("Data tidak ditemukan...");
		textcolor(7);
	}	
	getch();	
}

//	Cari tujuan (substring applied)
void cariTujuan(queue *node){
	int x;
	string nama;
	kotak(1,29);
	gotoxy(30,14); textcolor(8); cout << "contoh : ci, cirebon"; textcolor(7);
	gotoxy(30,12); type("Nama Stasiun : "); fflush(stdin); getline(cin,nama);
	nama = uppercase(nama);
	
	system("cls");
	header();
	
	while(node != NULL){
		if(strstr(node->info.pembeli.tujuan.c_str(),nama.c_str()) && nama != ""){			//	c_str() : convert string to char
			++x;
			body();
			output(node->info);
			node = node->next;
		}else{
			node = node->next;
		}
	}
	
	footer();
	
	if(x == 0){
		gotoxy(30,4); textcolor(12); type("Data tidak ditemukan...");
		textcolor(7);
	}	
	getch();	
}

//	Cari kelas (substring apllied)
void cariKelas(queue *node){
	int x;
	string nama;
	kotak(1,28);
	gotoxy(30,14); textcolor(8); cout << "contoh : bi, bisnis"; textcolor(7);
	gotoxy(30,12); type("Nama Kelas : "); fflush(stdin); getline(cin,nama);
	nama = uppercase(nama);
	
	system("cls");
	header();
	
	while(node != NULL){
		if(strstr(node->info.pembeli.kelas.c_str(),nama.c_str()) && nama != ""){			//	c_str() : convert string to char
			++x;
			body();
			output(node->info);
			node = node->next;
		}else{
			node = node->next;
		}
	}
	
	footer();
	
	if(x == 0){
		gotoxy(30,4); textcolor(12); type("Data tidak ditemukan...");
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
				kotak(10,46);
				gotoxy(21,8);  cout << "     MENU PENCARIAN DATA PEMBELI";
				gotoxy(21,10); cout << "{ 1 }  Cari Berdasarkan Kode Tiket";
				gotoxy(21,11); cout << "{ 2 }  Cari Berdasarkan Nama";
				gotoxy(21,12); cout << "{ 3 }  Cari Berdasarkan Stasiun Asal";
				gotoxy(21,13); cout << "{ 4 }  Cari Berdasarkan Stasiun Tujuan";
				gotoxy(21,14); cout << "{ 5 }  Cari Berdasarkan Kelas";
				gotoxy(21,15); cout << "{ 0 }  Menu Sebelumnya";
				gotoxy(21,17); type("              PILIHAN : "); menu = getche();
			}while(menu > '6');
			loading(46);
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
		gotoxy(35,12); textcolor(12); type("Data Kosong");
		textcolor(7);
		getch();
	}
}
/*	End of Cari Data Pembeli	*/

/*	Start of Hapus Data Pembeli	*/
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
		type("\n Kode Tiket : "); fflush(stdin); getline(cin,kode);
		kode = uppercase(kode);
		
		if(cekKodeT(*node,kode)){
			deleteP(&(*node),kode);	
			lihatPembeli(*node);			
		}else{
			type("\n Data tidak ada");
		}
	}else{
		gotoxy(35,12); textcolor(12); type("Data Kosong");
		textcolor(7);		
	}

	getch();
}
/*	End of Hapus Data Pembeli	*/

//	Menu data pembeli
void menuPembeli(queue **node, tiket data, string kasir){
	int menu;
	char lagi;
	do{
		do{
			system("cls");
			kotak(10,33);
			gotoxy(28,8);  cout << "    MENU DATA PEMBELI";
			gotoxy(28,10); cout << "{ 1 }  Input Data Pembeli";
			gotoxy(28,11); cout << "{ 2 }  Ubah  Data Pembeli";
			gotoxy(28,12); cout << "{ 3 }  Cari  Data Pembeli";
			gotoxy(28,13); cout << "{ 4 }  Hapus Data Pembeli";
			gotoxy(28,14); cout << "{ 5 }  Lihat Data Pembeli";
			gotoxy(28,15); cout << "{ 0 }  Menu Utama";
			gotoxy(28,17); type("       PILIHAN : "); menu = getche();
		}while(menu > '5');
		loading(33);
		system("cls");
		switch(menu){								
			case '1' : 	do{
							system("cls");
							info();
							inputPembeli(*node,data,kasir);
							enQueue(&(*node),data);
							printTiket(*node);
							putchar('\n');
							do{
								putchar('\n');
								cout << setiosflags(ios::left)
									 << setw(28) << " ";
								type (" Input Lagi [Y/T] : "); lagi = getche();
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
						waktu(28,whereY());
						getch();
						break;			
		}
	}while(menu != '0');
}

/*	Start of File	*/
//	Load data pembeli pada file "dataPembeli.dat"
void loadPembeli(queue **node, tiket &data){
	ifstream fin("dataPembeli.dat");			//	buka file dataPembeli.dat
	
	if(fin){
		while(!fin.eof()){						//	selama bukan akhir dari file
		fin	>> data.kode										//	scan 1 kata & masukkan ke variabel data.kode
			>> data.pembeli.nama;								//	scan 1 kata & masukkan ke variabel data.pembeli.nama
			   data.pembeli.nama = Nama(data.pembeli.nama);			//	ubah "_" dengan " "
		fin >> data.pembeli.berangkat.tanggal					//	scan 1 kata & masukkan ke variabel data.pembeli.berangkat.tanggal
			>> data.pembeli.berangkat.bulan						//	scan 1 kata & masukkan ke variabel data.pembeli.berangkat.bulan
			>> data.pembeli.berangkat.tahun						//	scan 1 kata & masukkan ke variabel data.pembeli.berangkat.tahun
			>> data.pembeli.asal								//	scan 1 kata & masukkan ke variabel data.pembeli.asal
			>> data.pembeli.tujuan								//	scan 1 kata & masukkan ke variabel data.pembeli.tujuan
			>> data.pembeli.kelas								//	scan 1 kata & masukkan ke variabel data.pembeli.kelas
			>> data.pembeli.waktu								//	scan 1 kata & masukkan ke variabel data.pembeli.waktu
			>> data.kereta.kode									//	scan 1 kata & masukkan ke variabel data.kereta.kode
			>> data.kereta.nama									//	scan 1 kata & masukkan ke variabel data.kereta.nama
			>> data.kereta.berangkat							//	scan 1 kata & masukkan ke variabel data.kereta.berangkat
			>> data.kereta.tiba									//	scan 1 kata & masukkan ke variabel data.kereta.tiba
			>> data.kereta.gerbong								//	scan 1 kata & masukkan ke variabel data.kereta.gerbong
			>> data.kereta.kursi								//	scan 1 kata & masukkan ke variabel data.kereta.kursi
			>> data.kereta.harga								//	scan 1 kata & masukkan ke variabel data.kereta.harga
			>> data.pembeli.jumlah								//	scan 1 kata & masukkan ke variabel data.pembeli.jumlah
			>> data.pembeli.subtotal							//	scan 1 kata & masukkan ke variabel data.pembeli.subtotal
			>> data.pembeli.diskon								//	scan 1 kata & masukkan ke variabel data.pembeli.diskon
			>> data.pembeli.total								//	scan 1 kata & masukkan ke variabel data.pembeli.total
			>> data.kasir.username;									//	scan 1 kata & masukkan ke variabel data.kasir.nama
			   data.kasir.username = Nama(data.kasir.username);
			enQueue(&(*node),data);								//	masukkan semua variabel yang telah discan ke dalam queue
		}
	}
	
	fin.close();
}

// 	Upload data pembeli ke dataPembeli.dat
void uploadPembeli(queue *node){
	ofstream fout("dataPembeli.dat",ios::trunc);
	
	while(node != NULL){		
		fout << "\n "
			 << setiosflags(ios::left)
			 << setw(5) << node->info.kode << "   "
			 << setw(25) << _Nama(node->info.pembeli.nama) << "   "
			 << setiosflags(ios::right)
			 << setw(2) << node->info.pembeli.berangkat.tanggal << " "
			 << resetiosflags(ios::right)
			 << setiosflags(ios::left)
			 << setw(9) << node->info.pembeli.berangkat.bulan << " "
			 << setw(4) << node->info.pembeli.berangkat.tahun << "   "
			 << setw(8) << node->info.pembeli.asal << "   "
			 << setw(8) << node->info.pembeli.tujuan << "   "
			 << setw(9) << node->info.pembeli.kelas << "   "
			 << setw(5) << node->info.pembeli.waktu << "   "
			 << setw(6) << node->info.kereta.kode << "   "
			 << setw(12) << node->info.kereta.nama << "   "
			 << setw(5) << node->info.kereta.berangkat << "   "
			 << setw(5) << node->info.kereta.tiba << "   "
			 << node->info.kereta.gerbong << "   "
			 << setw(14) << node->info.kereta.kursi << "   "			 	 
			 << setiosflags(ios::right)			 
			 << setw(6) << node->info.kereta.harga << "   "
			 << node->info.pembeli.jumlah << "   "		
			 << setw(8) << node->info.pembeli.subtotal << "   "
			 << setw(7) << node->info.pembeli.diskon << "   "
			 << setw(8) << node->info.pembeli.total << "   "
			 << resetiosflags(ios::right)
			 << setiosflags(ios::left)
			 << uppercase(_Nama(node->info.kasir.username));
		node = node->next;
	}
	
	fout.close();
}
/*	End of File	*/
