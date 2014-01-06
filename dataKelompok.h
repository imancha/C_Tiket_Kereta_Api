int y_coord[2000]={0};
int XMAX=77;
int YMAX=24;
string x = "     SISTEM INFORMASI      PENJUALAN TIKET KERETA API                                      OLEH :                                      1. ADI SURIPIYANTO         2. DINAR PRISKAWATI        3. MOHAMMAD ABDUL IMAN SYAH4. RIA ANANDA              5. ROSALINA FAZRIAH        ";

void fallingChar(){
	for(int x=0; x<=XMAX; x++){
		int matrixNumber = rand()%26;
		
		y_coord[x] = y_coord[x]+1;
		
		if(y_coord[x] > YMAX) y_coord[x] = 0;
		
		textcolor(2);  gotoxy(x,y_coord[x]-1); printf(" %c ",matrixNumber+'A');
//		textcolor(10); gotoxy(x,y_coord[x]);   printf(" %c ",matrixNumber+'A');
	}
	Sleep(1);
}

void introMatrix(){	
	for(int i=0; i<XMAX; i++){
		y_coord[i] = rand()%YMAX;
	}		
	
	int a=0;
	int y=0;	
	while(y<=x.length()){
		fallingChar();
		
		int j=0;
		int k=0;	
		for(int i=0; i<=y; i++){		
			j++;
			gotoxy(27+j,6+k); textcolor(10); cout << x[i];
			if(j==27){
				k++;
				j=0;
			}
		}		
		
		y++;
	}	
}

void opening(){
	introMatrix();
	system("cls");		
	
	int j=0;
	int k=0;	
	for(int i=0; i<=x.length(); i++){		
		j++;
		gotoxy(27+j,6+k); textcolor(10); cout << x[i];
		if(j==27){
			k++;
			j=0;
		}
	}
	
	textcolor(14);
	/*	left	*/
	for(int i=0; i<12; i++){
		gotoxy(25,5+i); cout << char(179);
		Sleep(50);
	}
	/*	corner left bottom	*/
	gotoxy(25,17); cout << char(192);
	/*	bottom	*/
	for(int i=0; i<31; i++){
		gotoxy(26+i,17); cout << char(196);
		Sleep(50);
	}
	/*	corner right bottom	*/
	gotoxy(57,17); cout << char(217);
	/*	right	*/
	for(int i=0; i<12; i++){
		gotoxy(57,16-i); cout << char(179);
		Sleep(50);
	}
	/*	corner left top	*/
	gotoxy(25,4); cout << char(218);
	/*	top	*/
	for(int i=0; i<31; i++){
		gotoxy(26+i,4); cout << char(196);
		Sleep(50);
	}
	/*	corner right top	*/
	gotoxy(57,4); cout << char(191);
	/*	edge middle left	*/
	gotoxy(25,9); cout << char(195);
	/*	middle left	*/
	for(int i=0; i<11; i++){
		gotoxy(26+i,9); cout << char(196);
		Sleep(50);
	}
	/*	middle right	*/
	for(int i=0; i<12; i++){
		gotoxy(45+i,9); cout << char(196);
		Sleep(50);
	}
	/* edge middle right	*/
	gotoxy(57,9); cout << char(180);
	for(int i=0; i<27; i++){
		gotoxy(28+i,18); cout << char(196);
		Sleep(50);
	}
	gotoxy(29,23); textcolor(11); type("Copyright @ 2014 - UNIKOM");
	textcolor(7); getch();	
}

void closing(){	
	gotoxy(33,11); textcolor(13); type("Terima Kasih...");
	gotoxy(25,13); textcolor(14); type("q(^_^) (^_^) (^_^) (^_^) (^_^)p");
	textcolor(0);
}
