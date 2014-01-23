int y_coord[2000]={0};
int XMAX=77;
int YMAX=24;
string x = "     SISTEM INFORMASI     PENJUALAN TIKET KERETA API                                     OLEH                                                                MOHAMMAD ABDUL IMAN SYAH ";

void fallingChar(){
	for(int x=0; x<=XMAX; x++){
		int matrixNumber = rand()%26;
		
		y_coord[x] = y_coord[x]+1;
		
		if(y_coord[x] > YMAX) y_coord[x] = 0;
		
		textcolor(2);  gotoxy(x,y_coord[x]-1); printf("  %c  ",matrixNumber+'A');
//		textcolor(10); gotoxy(x,y_coord[x]);   printf(" %c ",matrixNumber+'A');
	}
	Sleep(50);
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
			gotoxy(26+j,8+k); textcolor(10); cout << x[i];
			if(j==26){
				k++;
				j=0;
			}
		}		
		
		y++;
	}	
}

void kotakOpening(){
	textcolor(14);
	/*	left	*/
	for(int i=0; i<11; i++){
		gotoxy(24,6+i); cout << char(179);
		Sleep(50);
	}
	/*	corner left bottom	*/
	gotoxy(24,17); cout << char(192);
	/*	bottom	*/
	for(int i=0; i<31; i++){
		gotoxy(25+i,17); cout << char(196);
		Sleep(50);
	}
	/*	corner right bottom	*/
	gotoxy(55,17); cout << char(217);
	/*	right	*/
	for(int i=0; i<10; i++){
		gotoxy(55,16-i); cout << char(179);
		Sleep(50);
	}
	/*	corner left top	*/
	gotoxy(24,6); cout << char(218);
	/*	top	*/
	for(int i=0; i<31; i++){
		gotoxy(25+i,6); cout << char(196);
		Sleep(50);
	}
	/*	corner right top	*/
	gotoxy(55,6); cout << char(191);
	/*	edge middle left	*/
	gotoxy(24,11); cout << char(195);
	/*	middle left	*/
	for(int i=0; i<12; i++){
		gotoxy(25+i,11); cout << char(196);
		Sleep(50);
	}
	/*	middle right	*/
	for(int i=0; i<12; i++){
		gotoxy(43+i,11); cout << char(196);
		Sleep(50);
	}
	/* edge middle right	*/
	gotoxy(55,11); cout << char(180);
	/*	line bottom	*/
	for(int i=0; i<26; i++){
		gotoxy(27+i,18); cout << char(196);
		Sleep(50);
	}	
}

void opening(){
	introMatrix();
	system("cls");		
	
	int j=0;
	int k=0;	
	for(int i=0; i<=x.length(); i++){		
		j++;
		gotoxy(26+j,8+k); textcolor(10); cout << x[i];
		if(j==26){
			k++;
			j=0;
		}
	}
	
	kotakOpening();
	
	gotoxy(27,23); textcolor(11); type("Copyright @ 2014 - IMANCHA");
	textcolor(7); getch();	
}

void closing(){	
	gotoxy(33,11); textcolor(13); type("Terima Kasih...");
	gotoxy(25,13); textcolor(14); type("q(^_^) (^_^) (^_^) (^_^) (^_^)p");
	textcolor(0);
}
