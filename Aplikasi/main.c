#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>
#include"menu.h" //algoritma pembuatan menu dan headernya
#include"bantuan.h"

#define KIRI  0x4B  //ARROW KIRI 75
#define KANAN 0x4D //ARROW KANAN 77
#define ATAS  0x48  //ARROW ATAS 72
#define BAWAH 0x50 //ARROW BAWAH 80
#define ESC   0x1B //ESC 27
#define ENTER 0xD //enter 13

int i, j;
int posisi = 33;
int bestskor = 0;
int langkah;
char pazel[4][4]={{97, 98, 99, 100},{101, 102, 103, 104},{105, 106, 107, 108},{109, 110, 111, }};

FILE *a;

void acak_array();
void game();
void bantuan();
void underscore_kedip();
void menu();
void keluar();

int main(){
	underscore_kedip(0);
	system("title Puzzle 15");
	printf("\n\n\t\t\t======     ==    ==   ======   ======   ==        ======        || ||||||\n");
	printf("\t\t\t==    ==   ==    ==        =        =   ==        =             || ||    \n");
	printf("\t\t\t==    ==   ==    ==       =        =    ==        =             || ||    \n");
	printf("\t\t\t==    ==   ==    ==      =        =     ==        ======   ===  || ||||||\n");
	printf("\t\t\t==  ==     ==    ==     =        =      ==        =             ||     ||\n");
	printf("\t\t\t==         ==    ==    =        =       ==        =             ||     ||\n");
	printf("\t\t\t==         == == ==   ======   ======   =======   ======        || ||||||\n");
	printf("\n\n\t\t\t\t\t Selamat datang di Mini Game Puzzle-15\n\t\t\t\t\t    ");
	
	a = fopen("sekor", "r");
	fscanf(a, "%d\n", &bestskor);
	fclose(a);
	
	system("pause");
	menu();
}

void menu(){
	char *menu_utama[3];
	menu_utama[0]="1. play game\n";
	menu_utama[1]="2. bantuan\n";
	menu_utama[2]="\033[1;31mexit program (ESC)\033[0m";
	switch (arrow_menu(3, menu_utama, 1)){
   		case 0:
			game();
			break;
		case 1:
			bantuan();
			break;
		case 2:
			keluar();
			break;
	}
}

void game(){
	acak_array();
	langkah=0;
	while(1){
		system("cls");
		for(i=0;i<4;i++){
			for(j=0;j<4;j++){
				printf("%c ", pazel[i][j]);
			}
			printf("\n");
		}
		printf("\nLangkah : %d", langkah);
		printf("\nskor terbaik : %d", bestskor);
		printf("\n\nNOTE:");
		printf("\nTEKAN ESC UNTUK KEMBALI KE MENU");
		printf("\nTEKAN R UNTUK MELAKUKAN PENGACAKAN LAGI");
		printf("\nTEKAN ENTER UNTUK MENYERAH DAN MELIHAT TOTAL SKOR");
		int dummy0_posisi=posisi/10;
		int dummy1_posisi=posisi%10;
		int dummy_pazel;
		int k, l;
		int cek=0, bener22=0, bener23=0, bener32=0, bener33=0, bener34=0, bener43=0, skor=0, enter=0;
		switch(getch()){
			case ATAS:
				if(dummy0_posisi!=0){
					dummy_pazel=pazel[dummy0_posisi][dummy1_posisi];
					pazel[dummy0_posisi][dummy1_posisi]=pazel[dummy0_posisi-1][dummy1_posisi];
					pazel[dummy0_posisi-1][dummy1_posisi]=dummy_pazel;
					posisi-=10;
					langkah++;
				}
				break;
			
			case BAWAH:
				if(dummy0_posisi!=3){
					dummy_pazel=pazel[dummy0_posisi][dummy1_posisi];
					pazel[dummy0_posisi][dummy1_posisi]=pazel[dummy0_posisi+1][dummy1_posisi];
					pazel[dummy0_posisi+1][dummy1_posisi]=dummy_pazel;
					posisi+=10;
					langkah++;
				}
				break;
				
			case KIRI:
				if(dummy1_posisi!=0){
					dummy_pazel=pazel[dummy0_posisi][dummy1_posisi];
					pazel[dummy0_posisi][dummy1_posisi]=pazel[dummy0_posisi][dummy1_posisi-1];
					pazel[dummy0_posisi][dummy1_posisi-1]=dummy_pazel;
					posisi--;
					langkah++;
				}
				break;
			
			case KANAN:
				if(dummy1_posisi!=3){
					dummy_pazel=pazel[dummy0_posisi][dummy1_posisi];
					pazel[dummy0_posisi][dummy1_posisi]=pazel[dummy0_posisi][dummy1_posisi+1];
					pazel[dummy0_posisi][dummy1_posisi+1]=dummy_pazel;
					posisi++;
					langkah++;
				}
				break;
			case 'r':
			case 'R':
				game();
				break;
			case ESC:
				menu();
				break;
			case ENTER:
				//CEK NILAINYA
				enter=1;
				bener22=0;
				for(i=0;i<3;i++){
					for(j=0;j<3;j++){
						int angka_awal=pazel[i][j];
						cek=1;
						for(k=0;k<2;k++){
							for(l=0;l<2;l++){
								if(pazel[i+k][j+l]!=angka_awal+(k*2)+l){
									cek=0;
									break;
								}
							}
							if(cek==0){break;}
						}
						if(cek==1){
							bener22++;
						}
					}
				}
				bener23=0;
				for(i=0;i<2;i++){
					for(j=0;j<3;j++){
						int angka_awal=pazel[i][j];
						cek=1;
						for(k=0;k<3;k++){
							for(l=0;l<2;l++){
								if(pazel[i+k][j+l]!=angka_awal+(k*2)+l){
									cek=0;
									break;
								}
							}
							if(cek==0){break;}
						}
						if(cek==1){
							bener22-=2;
							bener23++;
						}
					}
				}
				bener32=0;
				for(i=0;i<3;i++){
					for(j=0;j<2;j++){
						int angka_awal=pazel[i][j];
						cek=1;
						for(k=0;k<2;k++){
							for(l=0;l<3;l++){
								if(pazel[i+k][j+l]!=angka_awal+(k*3)+l){
									cek=0;
									break;
								}
							}
							if(cek==0){break;}
						}
						if(cek==1){
							bener32++;
						}
					}
				}
				bener33=0;
				for(i=0;i<2;i++){
					for(j=0;j<2;j++){
						int angka_awal=pazel[i][j];
						cek=1;
						for(k=0;k<3;k++){
							for(l=0;l<3;l++){
								if(pazel[i+k][j+l]!=angka_awal+(k*3)+l){
									cek=0;
									break;
								}
							}
							if(cek==0){break;}
						}
						if(cek==1){
							bener33++;
							bener32-=2;
						}
					}
				}
				bener34=0;
				for(i=0;i<2;i++){
					for(j=0;j<1;j++){
						int angka_awal=pazel[i][j];
						cek=1;
						for(k=0;k<3;k++){
							for(l=0;l<4;l++){
								if(pazel[i+k][j+l]!=angka_awal+(k*4)+l){
									cek=0;
									break;
								}
							}
							if(cek==0){break;}
						}
						if(cek==1){
							bener34++;
						}
					}
				}
				bener43=0;
				for(i=0;i<1;i++){
					for(j=0;j<2;j++){
						int angka_awal=pazel[i][j];
						cek=1;
						for(k=0;k<4;k++){
							for(l=0;l<3;l++){
								if(pazel[i+k][j+l]!=angka_awal+(k*3)+l){
									cek=0;
									break;
								}
							}
							if(cek==0){break;}
						}
						if(cek==1){
							bener43++;
							bener33-=2;
							bener32++;
						}
					}
				}
		}
		cek=0;
		if(cek==0){
			cek=1;
			for(i=0;i<4;i++){
				for(j=0;j<4;j++){
					if(i==3&&j==3){}
					else if(pazel[i][j]!=(i*4)+j+98){
						cek=0;
					}
				}
			}
		}
		if(cek==1||bener22>0||bener23>0||bener32>0||bener33>0||bener34>0||bener43>0){
			char *pilih_menu[3];
			char aad[300]="SELAMAT ANDA BERHASIL MENYELESAIKAN PUZZLE INI\n\n\t\t\033[1;33mAnda berhasil membuat bentuk";
			if(cek==1){skor+=500;sprintf(aad, "%s\n\t\t  - %d buah bentuk 3x3", aad);}
			if(bener22>0){skor+=bener22*300;sprintf(aad, "%s\n\t\t  - %d buah bentuk 2x2", aad, bener22);}
			if(bener23>0){skor+=bener23*350;sprintf(aad, "%s\n\t\t  - %d buah bentuk 2x3", aad, bener23);}
			if(bener32>0){skor+=bener32*350;sprintf(aad, "%s\n\t\t  - %d buah bentuk 3x2", aad, bener32);}
			if(bener33>0){skor+=bener33*400;sprintf(aad, "%s\n\t\t  - %d buah bentuk 3x3", aad, bener33);}
			if(bener34>0){skor+=bener34*450;sprintf(aad, "%s\n\t\t  - %d buah bentuk 3x4", aad, bener34);}
			if(bener43>0){skor+=bener43*450;sprintf(aad, "%s\n\t\t  - %d buah bentuk 4x3", aad, bener43);}
			int skorakhir = skor-(langkah/10);
			if(skorakhir>bestskor){bestskor=skorakhir;}
			enter=0;
			sprintf(aad, "%s\n\t\tAnda melakukan pergerakan sebanyak : %d langkah\n\t\tSkor akhir anda adalah : %d\n\n\t\tSkor terbaik anda saat ini adalah : %d\n\n\t\t\033[1;31mapakah anda ingin mencoba bermain lagi?", aad, langkah, skorakhir, bestskor);
			pilih_menu[0]=aad;
			pilih_menu[1]="YA (mencoba lagi)";
			pilih_menu[2]="TIDAK (kembali ke menu utama) (ESC)";
			switch (arrow_menu(3, pilih_menu, 3)){
				case 0:
					game();
				case 1:
					menu();
			}
		}
		else if(enter==1){
			char *pilih_menu[3];
			pilih_menu[0]="YAAAH ANDA TIDAK BERHASIL MENDAPATKAN SKOR SAMA SEKALI, JANGAN BERKECIL HATI,\n\t\tANDA BISA MENCOBANYA LAGI, TETAP SEMANGAT YA!!!\n\n\t\tapakah anda ingin mencoba bermain lagi?";
			pilih_menu[1]="YA (mencoba lagi)";
			pilih_menu[2]="TIDAK (kembali ke menu utama) (ESC)";
			switch (arrow_menu(3, pilih_menu, 3)){
				case 0:
					game();
				case 1:
					menu();
			}
		}
	}
}

void acak_array(){
	system("cls");
	printf("HARAP BERSABAR, HURUF SEDANG DIACAK, SILAHKAN TUNGGU SEBENTAR :)\nLoading");
	int k=1;
	for (i=0; i<4; i++){
		for(j=0; j<4; j++){
		    int dummy = pazel[i][j];
		    srand(time(0));
		    int indeksrandom0 = rand() % 4;
		    Sleep(300);
		    int indeksrandom1 = rand() % 4;
		
		    pazel[i][j] = pazel[indeksrandom0][indeksrandom1];
		    pazel[indeksrandom0][indeksrandom1] = dummy;

			printf(".");
			if (k%5==0){printf("\b \b\b \b\b \b\b \b\b \b");}
			k++;
		}
	}
	for(i=0; i<4; i++){
		for(j=0; j<4; j++){
			if(pazel[i][j]==0){
		    	posisi=(i*10)+(j);
		    	int k=0;
		    	break;
			}
		}
		if(k==0){break;}
	}
}

void keluar(){
	char *pilih_menu[3];
	pilih_menu[0]="Apakah anda yakin ingin keluar?";
	pilih_menu[1]="YA (keluar dari aplikasi)";
	pilih_menu[2]="TIDAK (kembali ke menu utama) (ESC)";
	switch (arrow_menu(3, pilih_menu, 3)){
		case 0:
			break;
		case 1:
			menu();
			break;
	}
	//simpan skor tertinggi
	a = fopen("sekor","w");
	fprintf(a, "%d", bestskor);
	fclose(a);
	
	system("cls");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\t\tyaaahhh :(");
	sleep(1);
	system("cls");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\t\tyaudah, nanti pakai aplikasi ini lagi ya ;)");
	sleep(1);
	system("cls");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\t\tterima kasih");
	for (i=0; i<3; i++){
		printf(" ;)");
		Sleep(500);
	}
	printf(" :)\n\n\n\n\n\n\n\n\n\n\n\n\n");
	exit(0);
}

//UNTUK MENGHILANGKAN UNDERSCORE KEDIP-KEDIP YANG BIASA ADA DI BAWAH CMD
void underscore_kedip(int z){
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE); //VARIABEL OUT UNTUK PENGHUBUNG DENGAN CONSOL(CMD)
    CONSOLE_CURSOR_INFO kedip; //DECLARE VARIABEL KEDIP
    GetConsoleCursorInfo(out, &kedip); //MENGAMBIL DATA UNDERSCORE SAAT INI KEDALAM VARIABEL KEDIP
    kedip.bVisible = z; //UNTUK MENGATUR UNDERSCORE KEDIP-KEDIP YANG ADA DI VARIABEL KEDIP (0 TIDAK DITAMPILKAN, 1 DITAMPILKAN)
    SetConsoleCursorInfo(out, &kedip); //MENGEMBALIKAN DATA UNDERSCORE KEDIP YANG TELAH DIMODIFIKASI DALAM VARIABEL KEDIP
}
