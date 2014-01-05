/*	Start of Input Data Pegawai	*/
string getPass(const char *prompt, bool show_asterisk=true){
  	const char BACKSPACE=8;
  	const char RETURN=13;
	
  	string password;
  	unsigned char ch=0;

  	cout << prompt;

  	DWORD con_mode;
  	DWORD dwRead;

  	HANDLE hIn=GetStdHandle(STD_INPUT_HANDLE);

  	GetConsoleMode( hIn, &con_mode );
  	SetConsoleMode( hIn, con_mode & ~(ENABLE_ECHO_INPUT | ENABLE_LINE_INPUT) );

  	while(ReadConsoleA( hIn, &ch, 1, &dwRead, NULL) && ch !=RETURN){
    	if(ch==BACKSPACE){
        	if(password.length()!=0){
            	if(show_asterisk)
                	cout <<"\b \b";
                	password.resize(password.length()-1);
            }
        }else{
        	password+=ch;
            if(show_asterisk)
            	cout <<'*';
        }
    }
    
  	return password;
}

bool cekPass(queue *root, string x, string y){
	while(root != NULL){
		if(root->data.username == x && root->data.password == y){
			return true;
			break;
		}else{
			root = root->next;
		}		
	}
	gotoxy(32,15); textcolor(12); cout << "Password Salah !"; textcolor(7); getch();
	return false;	
}

void loginPegawai(queue *root, string &kasir){
	string uname;
	string pass;
	int x;
	
	do{
		system("cls");
		kotak(6,35);
		gotoxy(34,10); cout << "LOGIN PEGAWAI";
		gotoxy(27,12); cout << "Username  :  ";
		gotoxy(27,13); cout << "Password  :  ";
		gotoxy(40,12); cin >> uname;
		gotoxy(40,13); pass = getPass("",true);
		loading(35);
		++x;
		
		if(x > 2){
			gotoxy(33,15); textcolor(12); cout << "3 kali salah..."; textcolor(0);
			exit(1);
			getch();
		}		
	}while(!cekPass(root,uname,pass));
	
	kasir = uname;
	gotoxy(32,15); textcolor(14); type("Hi, "+kasir+"..."); textcolor(0);
	getch();
}

void waktu(int x, int y){
	time_t now = time(0);
	char *dt = ctime(&now);	
	
	gotoxy(x,y); cout << dt;
}

void Enqueue(queue **root, employee info){
	if(*root == NULL){
		*root = new queue;
		(*root)->data = info;
		(*root)->next = NULL;
	}else{
		Enqueue(&((*root)->next), info);
	}
}

void outputs(employee info){
	cout << char(179) << " "
		 << setiosflags(ios::right)
		 << setw(2) << info.id
		 << " " << char(179) << " "
		 << resetiosflags(ios::right)
		 << setiosflags(ios::left)
		 << setw(14) << info.username
		 << " " << char(179) << " "
		 << setw(14) << info.password
		 << " " << char(179) << " "
		 << setw(24) << info.nama
		 << " " << char(179) << " "
		 << setw(10) << info.kota
		 << " " << char(179);
}

void Dequeue(queue *root){
	if(root != NULL){
		outputs(root->data);
		Dequeue(root->next);
	}	
}

void lihatPegawai(queue *root){
	system("cls");
	if(root != NULL){
		cout << char(218); for(int i=0; i<78; i++){ if(i==4 || i==21 || i==38 || i==65) cout << char(194); else cout << char(196); } cout << char(191);
		for(int i=0; i<80; i++){ if(i==0 || i==5 || i==22 || i==39 || i==66 || i==79) cout << char(179); else cout << " "; }		
		
		textcolor(11);
		gotoxy(2,1);  cout << "ID";
		gotoxy(10,1); cout << "USERNAME";
		gotoxy(27,1); cout << "PASSWORD";
		gotoxy(50,1); cout << "NAMA";
		gotoxy(71,1); cout << "KOTA\n";
		textcolor(7);		
		
		cout << char(195); for(int i=0; i<78; i++){ if(i==4 || i==21 || i==38 || i==65) cout << char(197); else cout << char(196); } cout << char(180);
		
		Dequeue(root);

		cout << char(192); for(int i=0; i<78; i++){ if(i==4 || i==21 || i==38 || i==65) cout << char(193); else cout << char(196); } cout << char(217);				
	}else{
		gotoxy(35,12); textcolor(12); type("Data Kosong"); textcolor(7);
	}	
}

int idPegawai(queue *root){	
	while(root != NULL){
		if(root->next == NULL){
			return root->data.id + 1;
			break;
		}
		root = root->next;
	}
	return ++root->data.id;
}

bool cekSpasi(queue *root, string x){
	if(x == ""){
		gotoxy(52,whereY()-2); textcolor(12); cout << "Tidak boleh kosong !\n"; textcolor(7);
		return true;
	}
	
	for(int i=0; i<x.length(); i++){
		if(x[i] == ' '){
			gotoxy(42,whereY()-2); textcolor(12); cout << "Tidak boleh mengandung spasi !\n"; textcolor(7);
			return true;
			break;
		}
	}
	
	while(root != NULL){
		if(root->data.username == x){
			gotoxy(46,whereY()-2); textcolor(12); cout << "Username telah digunakan !\n"; textcolor(7);
			return true;
			break;
		}else{
			root = root->next;
		}
	}
	
	return false;
}

void inputPegawai(queue *root, employee &info){	
	kotak(19,70);
	gotoxy(1,20); waktu(28,21);
	gotoxy(30,3); cout << "FORMULIR DATA PEGAWAI";
	
	info.id = idPegawai(root);
	gotoxy(8,6); cout << char(250) << " ID Pegawai : " << info.id << endl;	
	
	do{
		gotoxy(8,whereY()); cout << char(250) << " Username   : "; fflush(stdin); getline(cin,info.username);
	}while(cekSpasi(root,info.username));
	
	do{
		gotoxy(8,whereY()); cout << char(250) << " Password   : "; fflush(stdin); getline(cin,info.password);
	}while(cekSpasi(root,info.password));
	
	gotoxy(8,whereY()); cout << char(250) << " Nama       : "; fflush(stdin); getline(cin,info.nama);
	gotoxy(8,whereY()); cout << char(250) << " Kota       : "; fflush(stdin); getline(cin,info.kota);	
}
/*	End of Input Data Pegawai	*/

/*	Start of Ubah Data Pegawai	*/
bool cekID(queue **root, int z){
	while(*root != NULL){
		if((*root)->data.id == z){
			return true;
			break;
		}else{
			*root = (*root)->next;
		}		
	}
	return false;
}

void liat(queue *root){
	system("cls");
	cout << char(218); for(int i=0; i<78; i++){ if(i==4 || i==21 || i==38 || i==65) cout << char(194); else cout << char(196); } cout << char(191);
	for(int i=0; i<80; i++){ if(i==0 || i==5 || i==22 || i==39 || i==66 || i==79) cout << char(179); else cout << " "; }		
		
	textcolor(11);
	gotoxy(2,1);  cout << "ID";
	gotoxy(10,1); cout << "USERNAME";
	gotoxy(27,1); cout << "PASSWORD";
	gotoxy(50,1); cout << "NAMA";
	gotoxy(71,1); cout << "KOTA\n";
	textcolor(7);		
		
	cout << char(195); for(int i=0; i<78; i++){ if(i==4 || i==21 || i==38 || i==65) cout << char(197); else cout << char(196); } cout << char(180);
		
	outputs(root->data);

	cout << char(192); for(int i=0; i<78; i++){ if(i==4 || i==21 || i==38 || i==65) cout << char(193); else cout << char(196); } cout << char(217);					
}

void ubahPassword(queue *root){
	liat(root);
	
	do{
		type("\n Password : "); fflush(stdin); getline(cin,root->data.password);
	}while(cekSpasi(root,root->data.password));	
	
	liat(root);
	getch();
}

void ubahNamaP(queue *root){
	liat(root);
	
	type("\n Nama : "); fflush(stdin); getline(cin,root->data.nama);
	
	liat(root);
	getch();
}

void ubahKota(queue *root){
	liat(root);
	
	type("\n Kota : "); fflush(stdin); getline(cin,root->data.kota);
	
	liat(root);
	getch();
}

void ubahPegawai(queue *root){
	int id;
	
	if(root != NULL){
		lihatPegawai(root);
		type("\n ID Pegawai : "); scanf("%i",&id);
		
		if(id != 1){
			if(cekID(&root,id)){
				system("cls");
				int menu;
				do{
					do{
						system("cls");
						kotak(8,30);
						gotoxy(29,9);  cout << "MENU UBAH DATA PEGAWAI";
						gotoxy(29,11); cout << "{ 1 }  Ubah Password";
						gotoxy(29,12); cout << "{ 2 }  Ubah Nama";
						gotoxy(29,13); cout << "{ 3 }  Ubah Kota";
						gotoxy(29,14); cout << "{ 0 }  Menu Sebelumnya";
						gotoxy(29,16); type("      PILIHAN : "); menu = getche();
					}while(menu > '3');
					loading(30);
					system("cls");
					switch(menu){
						case '1' :	ubahPassword(root);
									break;
						case '2' :	ubahNamaP(root);
									break;
						case '3' : 	ubahKota(root);
									break;
					}								
				}while(menu != '0');				
			}else{
				cout << "\n Data Tidak Ada !";
				getch();
			}			
		}else{
			type("\n ID Pegawai 1 tidak boleh dirubah (admin) !");
			getch();
		}
	}else{
		gotoxy(34,12); textcolor(12); cout << "Data Kosong !";
		textcolor(7);
		getch();		
	}
}
/*	End of Ubah Data Pegawai	*/

/*	Start of Cari Data Pegawai	*/
void cariUsername(queue *root){
	int y;
	string x;
	kotak(1,33);
	gotoxy(30,14); textcolor(8); cout << "contoh : im, imancha"; textcolor(7);
	gotoxy(30,12); type("Username  :  "); fflush(stdin); getline(cin,x);
	uppercase(x);
	
	system("cls");
	cout << char(218); for(int i=0; i<78; i++){ if(i==4 || i==21 || i==38 || i==65) cout << char(194); else cout << char(196); } cout << char(191);
	for(int i=0; i<80; i++){ if(i==0 || i==5 || i==22 || i==39 || i==66 || i==79) cout << char(179); else cout << " "; }		
		
	textcolor(11);
	gotoxy(2,1);  cout << "ID";
	gotoxy(10,1); cout << "USERNAME";
	gotoxy(27,1); cout << "PASSWORD";
	gotoxy(50,1); cout << "NAMA";
	gotoxy(71,1); cout << "KOTA\n";
	textcolor(7);
	
	while(root != NULL){
		if(strstr(uppercase(root->data.username).c_str(),uppercase(x).c_str()) && x != ""){			//	c_str() : convert string to char
			++y;
			
			cout << char(195); for(int i=0; i<78; i++){ if(i==4 || i==21 || i==38 || i==65) cout << char(197); else cout << char(196); } cout << char(180);
			
			outputs(root->data);
			root = root->next;
		}else{
			root = root->next;
		}
	}
	
	cout << char(192); for(int i=0; i<78; i++){ if(i==4 || i==21 || i==38 || i==65) cout << char(193); else cout << char(196); } cout << char(217);					
	
	if(y == 0){
		gotoxy(30,4); textcolor(12); type("Data tidak ditemukan...!");
		textcolor(7);
	}	
	getch();		
}

void cariNamaP(queue *root){
	int y;
	string x;
	kotak(1,33);
	gotoxy(30,14); textcolor(8); cout << "contoh : im, imancha"; textcolor(7);
	gotoxy(30,12); type("Nama  :  "); fflush(stdin); getline(cin,x);
	
	system("cls");
	cout << char(218); for(int i=0; i<78; i++){ if(i==4 || i==21 || i==38 || i==65) cout << char(194); else cout << char(196); } cout << char(191);
	for(int i=0; i<80; i++){ if(i==0 || i==5 || i==22 || i==39 || i==66 || i==79) cout << char(179); else cout << " "; }		
		
	textcolor(11);
	gotoxy(2,1);  cout << "ID";
	gotoxy(10,1); cout << "USERNAME";
	gotoxy(27,1); cout << "PASSWORD";
	gotoxy(50,1); cout << "NAMA";
	gotoxy(71,1); cout << "KOTA\n";
	textcolor(7);
	
	while(root != NULL){
		if(strstr(uppercase(root->data.nama).c_str(),uppercase(x).c_str()) && x != ""){			//	c_str() : convert string to char
			++y;
			
			cout << char(195); for(int i=0; i<78; i++){ if(i==4 || i==21 || i==38 || i==65) cout << char(197); else cout << char(196); } cout << char(180);
			
			outputs(root->data);
			root = root->next;
		}else{
			root = root->next;
		}
	}
	
	cout << char(192); for(int i=0; i<78; i++){ if(i==4 || i==21 || i==38 || i==65) cout << char(193); else cout << char(196); } cout << char(217);					
	
	if(y == 0){
		gotoxy(30,4); textcolor(12); type("Data tidak ditemukan...!");
		textcolor(7);
	}	
	getch();		
}

void cariKota(queue *root){
	int y;
	string x;
	kotak(1,33);
	gotoxy(30,14); textcolor(8); cout << "contoh : im, imancha"; textcolor(7);
	gotoxy(30,12); type("Kota  :  "); fflush(stdin); getline(cin,x);
	
	system("cls");
	cout << char(218); for(int i=0; i<78; i++){ if(i==4 || i==21 || i==38 || i==65) cout << char(194); else cout << char(196); } cout << char(191);
	for(int i=0; i<80; i++){ if(i==0 || i==5 || i==22 || i==39 || i==66 || i==79) cout << char(179); else cout << " "; }		
		
	textcolor(11);
	gotoxy(2,1);  cout << "ID";
	gotoxy(10,1); cout << "USERNAME";
	gotoxy(27,1); cout << "PASSWORD";
	gotoxy(50,1); cout << "NAMA";
	gotoxy(71,1); cout << "KOTA\n";
	textcolor(7);
	
	while(root != NULL){
		if(strstr(uppercase(root->data.kota).c_str(),uppercase(x).c_str()) && x != ""){			//	c_str() : convert string to char
			++y;
			
			cout << char(195); for(int i=0; i<78; i++){ if(i==4 || i==21 || i==38 || i==65) cout << char(197); else cout << char(196); } cout << char(180);
			
			outputs(root->data);
			root = root->next;
		}else{
			root = root->next;
		}
	}
	
	cout << char(192); for(int i=0; i<78; i++){ if(i==4 || i==21 || i==38 || i==65) cout << char(193); else cout << char(196); } cout << char(217);					
	
	if(y == 0){
		gotoxy(30,4); textcolor(12); type("Data tidak ditemukan...!");
		textcolor(7);
	}	
	getch();		
}

void cariPegawai(queue *root){
	int menu;
	if(root != NULL){
		do{
			do{
				system("cls");
				kotak(8,40);
				gotoxy(24,9);  cout << "  MENU PENCARIAN DATA PEGAWAI";
				gotoxy(24,11); cout << "{ 1 }  Cari Berdasarkan Username";
				gotoxy(24,12); cout << "{ 2 }  Cari Berdasarkan Nama";
				gotoxy(24,13); cout << "{ 3 }  Cari Berdasarkan Kota";				
				gotoxy(24,14); cout << "{ 0 }  Menu Sebelumnya";
				gotoxy(24,16); type("           PILIHAN : "); menu = getche();
			}while(menu > '3');
			loading(40);
			system("cls");
			switch(menu){
				case '1' : 	cariUsername(root);
							break;
				case '2' :	cariNamaP(root);
							break;
				case '3' :	cariKota(root);
							break;
			}
		}while(menu != '0');		
	}else{
		gotoxy(34,12); textcolor(12); type("Data Kosong !");
		textcolor(7);
		getch();
	}
}
/*	End of Cari Data Pegawai	*/

/*	Start of Hapus Data Pegawai		*/
bool cekIDP(queue *root, int kode){
	while(root != NULL){
		if(root->data.id == kode){
			return true;
			break;		
		}else{
			root = root->next;
		}		
	}	
}

void deleteE(queue **root, int kode){
	queue *hapus;
	if(*root != NULL){
		if((*root)->next->data.id == kode){
			hapus = (*root)->next;
			(*root)->next = hapus->next;
			hapus = NULL;		
		}else{
			deleteE(&((*root)->next), kode);
		}
	}
}

void hapusPegawai(queue **root){
	int x;
	
	if(root != NULL){
		lihatPegawai(*root);
		type("\n ID Pegawai  :  "); cin >> x;		
		
		if(x != 1){
			if(cekIDP(*root,x)){
				deleteE(&(*root),x);
				lihatPegawai(*root);
			}else{
				type("\n Data tidak ada !");
			}
		}else{
			type("\n ID Pegawai 1 tidak boleh dihapus (admin) !");
		}
		
	}else{
		gotoxy(35,12); textcolor(12); type("Data Kosong");
		textcolor(7);		
	}

	getch();	
}
/*	End of Hapus Data Pegawai	*/

void menuPegawai(queue **root, employee info){
	int menu;
	char lagi;
	do{
		do{
			system("cls");
			kotak(10,33);
			gotoxy(28,8);  cout << "    MENU DATA PEGAWAI";
			gotoxy(28,10); cout << "{ 1 }  Input Data Pegawai";
			gotoxy(28,11); cout << "{ 2 }  Ubah  Data Pegawai";
			gotoxy(28,12); cout << "{ 3 }  Cari  Data Pegawai";
			gotoxy(28,13); cout << "{ 4 }  Hapus Data Pegawai";
			gotoxy(28,14); cout << "{ 5 }  Lihat Data Pegawai";
			gotoxy(28,15); cout << "{ 0 }  Menu Utama";
			gotoxy(28,17); type("       PILIHAN : "); menu = getche();
		}while(menu > '5');
		loading(33);
		system("cls");
		switch(menu){								
			case '1' : 	do{
							system("cls");
							inputPegawai(*root,info);
							Enqueue(&(*root),info);
							do{								
								gotoxy(30,23); cout << ("Input Lagi [Y/T] : "); lagi = getche();
								lagi = toupper(lagi);
							}while(!(lagi == 'Y' || lagi == 'T'));
						}while(lagi == 'Y');
						break;
			case '2' : 	ubahPegawai(*root);
						break;
			case '3' :	cariPegawai(*root);
						break;
			case '4' :	hapusPegawai(&(*root));
						break;
			case '5' : 	lihatPegawai(*root);
						waktu(28,whereY());
						getch();
						break;			
		}
	}while(menu != '0');
}

/*	Start of File	*/
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

void loadPegawai(queue **root, employee &info){
	ifstream fin("dataPegawai.dat");
	
	if(fin){
		while(!fin.eof()){
			fin >> info.id
				>> info.username
				>> info.password
				>> info.nama;
				   info.nama = Nama(info.nama);
			fin >> info.kota;
			Enqueue(&(*root),info);
		}
	}
	
	fin.close();
}

void uploadPegawai(queue *root){
	ofstream fout("dataPegawai.dat",ios::trunc);
	
	while(root != NULL){
		fout << "\n "
			 << setiosflags(ios::right)
			 << setw(2) << root->data.id << "   "
			 << resetiosflags(ios::right)
			 << setiosflags(ios::left)
			 << setw(15) << root->data.username << "   "
			 << setw(15) << root->data.password << "   "
			 << setw(25) << _Nama(root->data.nama) << "   "
			 << _Nama(root->data.kota);
			 root = root->next;
	}
	
	fout.close();
}
/*	End of File	*/

void destroy(queue *node){
	if(node != NULL){
		delete node;
		destroy(node->next);
	}
}
