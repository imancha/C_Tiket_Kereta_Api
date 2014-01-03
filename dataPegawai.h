//	Get nama kasir 
string namaKasir(int no){
	switch(no){
		case 1 : return "Imancha"; break;
		case 2 : return "Dinar"; break;
		case 3 : return "Adi"; break;
		case 4 : return "Ria"; break;
		case 5 : return "Rosalina"; break;		
	}
}

//	Show data pegawai/kasir
void pegawai(){
	cout << char(218); for(int i=0; i<78; i++){ if(i==4 || i==29 || i==63) cout << char(194); else cout << char(196); } cout << char(191)
		 << char(179) << " NO " << char(179) << "          NAMA          " << char(179) << "             ALAMAT              " << char(179) << "    PHONE     " << char(179)
		 << char(195); for(int i=0; i<78; i++){ if(i==4 || i==29 || i==63) cout << char(197); else cout << char(196); } cout << char(180)
		 << char(179) << "  1 " << char(179) << " Imancha                " << char(179) << " Jl. Imancha No. 266  Cirebon    " << char(179) << " 085224057100 " << char(179)
		 << char(179) << "  2 " << char(179) << " Dinar                  " << char(179) << " Jl. Cipedes No. 8  Bandung      " << char(179) << " 085624545428 " << char(179)
		 << char(179) << "  3 " << char(179) << " Adi                    " << char(179) << " Jl. Gagak No. 3  Bandung        " << char(179) << " 08980545071  " << char(179)
		 << char(179) << "  4 " << char(179) << " Ria                    " << char(179) << " Jl. Cisitu Baru No. 44  Bandung " << char(179) << " 08561618388  " << char(179)
		 << char(179) << "  5 " << char(179) << " Rosalina               " << char(179) << " Jl. Dipatiukur No. 90 Bandung   " << char(179) << " 085759261223 " << char(179)
		 << char(192); for(int i=0; i<78; i++){ if(i==4 || i==29 || i==63) cout << char(193); else cout << char(196); } cout << char(217);
		 getch();
}
