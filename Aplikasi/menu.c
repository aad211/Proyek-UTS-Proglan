#include<stdio.h>
#include<string.h>
#include"menu.h"

int i, j;

int arrow_menu(int banyak_menu, char *list_menu[banyak_menu+2] , int z){
	int pilih=0;
	banyak_menu+=2;
	if (z==1){ //menu utama
		banyak_menu-=2;
		while (1) {
		  	system("cls");
		  	judul();
		  	judul_menu();
		  	for (i=0; i<banyak_menu; i++){
				if (pilih==i){printf("--> ");}
				else {printf("   ");}
				printf("%s\n", list_menu[i]);
			}
		    switch ( getch() ) {
		    case ENTER: //enter
		    	for (i=0; i<banyak_menu; i++){
					if (pilih==i){
			   			return i;
					}
				}
			case ATAS: //arrow atas
	    		pilih--;
	    		if (pilih<0){
	    			pilih=banyak_menu-1;
				}
				break;
			case BAWAH: //arrow bawah
				pilih++;
				if (pilih>=banyak_menu){
					pilih=0;
				}
				break;
			case ESC:
				keluar();
			}
		}
	}
	else if (z==2){ //submenu atau switch menu saat salah
		pilih=2;
		if (list_menu[0]==NULL){
			banyak_menu-=2;
			list_menu[banyak_menu];
		}
		while (1) {
		  	system("cls");
		  	submenu(list_menu[1], 1);
			printf("  silahkan pilih apa yang ingin anda lakukan\n\n");
		  	for (i=2; i<banyak_menu; i++){
				if (pilih==i){printf("--> ");}
				else {printf("   ");}
				if (list_menu[0]!=NULL){
					if (i<banyak_menu-2){
						printf("%s\n", list_menu[i]);
					}
					else {
						printf("\033[1;31m");
						printf("%s", list_menu[i]);
						printf("\033[0m");
					}
					if (pilih==banyak_menu-2){
						list_menu[banyak_menu-2]="Back (ESC)\t\t\t\t\t\t\t\t\t\t\t\t  ";
						list_menu[banyak_menu-1]="Main Menu\n\n";
					}
					else {
						list_menu[banyak_menu-2]="Back (ESC)\t\t\t\t\t\t\t\t\t\t\t\t  ";
						list_menu[banyak_menu-1]="Main Menu\n\n";
					}
				}
				else {
					if (i<banyak_menu){
						printf("%s\n", list_menu[i]);
					}
				}
			}
		    switch ( getch() ) {
		    case ENTER: //enter
		    	if (pilih==banyak_menu-1&&list_menu[0]!=NULL){
		    		menu();
				}
	   			else {
		    		for (i=0; i<banyak_menu; i++){
						if (pilih==i){
			    			return i-2;
						}
					}
				}
			case ATAS: //arrow atas
	    		pilih--;
	    		if (pilih<2){
	    			pilih=banyak_menu-1;
				}
				break;
			case BAWAH: //arrow bawah
				pilih++;
				if (pilih>=banyak_menu){
					pilih=2;
				}
				break;
			case ESC:
				if (list_menu[0]!=NULL){return banyak_menu-4;}
				return banyak_menu-3;
			}
		}
	}
	else if (z==3){ //statement seperti ya atau tidak, lanjutkan atau tidak
		pilih=1;
		banyak_menu-=2;
		list_menu[banyak_menu];
		while (1) {
		  	system("cls");
		  	printf("\033[1;31m");
		  	printf("\n\n\n\n\n\n\n\n\n\n\n\t\t%s\n\n", list_menu[0]);
		  	printf("\033[0m");
		  	for (j=1; j<banyak_menu; j++){
				if (pilih==j){printf("\t\t--> ");}
				else {printf("\t\t   ");}
				printf("%s", list_menu[j]);
				if (strcmp(list_menu[0], "Apakah anda yakin ingin keluar?")==0){
					if (pilih==1&&j==1){printf("\t\t\t:( :( :( *jangan dong :(");}
					else if (pilih!=1&&j!=1) {printf("\t\t:) :) :) *yeay :)");}
				}
				printf("\n\n");
			}
		    switch ( getch() ) {
		    case ENTER: //enter
		    	for (j=0; j<banyak_menu; j++){
					if (pilih==j){
			    		return j-1;
					}
				}
			case ATAS: //arrow atas
	    		pilih--;
	    		if (pilih<1){
	    			pilih=banyak_menu-1;
				}
				break;
			case BAWAH: //arrow bawah
				pilih++;
				if (pilih>=banyak_menu){
					pilih=1;
				}
				break;
			case ESC:
				return banyak_menu-2;
			}
		}
	}
}

void judul(){
	printf("\t\t\t================================================================\n");
    printf("\t\t\t||                                                            ||\n");
    printf("\t\t\t||                            GAME                            ||\n");
    printf("\t\t\t||                          PUZZLE 15                         ||\n");
    printf("\t\t\t||                                                            ||\n");
    printf("\t\t\t================================================================\n\n");
}


void judul_menu(){
	printf("\t\t\t\t      =================================\n");
	printf("\t\t\t\t      |                               |\n");
    printf("\t\t\t\t      |           Menu Utama          |\n");
    printf("\t\t\t\t      |                               |\n");
    printf("\t\t\t\t      =================================\n\n");
}

void submenu(char *list_menu, int z){
	if (z==0){
		z = strlen(list_menu);
		if (z>100){z/=2;}
		
		printf("\t\t\t\t\t\t   ");
		for(i=0; i<z/2; i++){
			printf("\b \b");
		}
		printf("=========");
		for(i=0; i<z; i++){
			printf("=");
		}
		printf("========\n");

		printf("\t\t\t\t\t\t   ");
		for(i=0; i<z/2; i++){
			printf("\b \b");
		}
		printf("|               ");
		for(i=0; i<z; i++){
			printf(" ");
		}
		printf("|\n");

		printf("\t\t\t\t\t\t   ");
		for(i=0; i<z/2; i++){
			printf("\b \b");
		}
		printf("|        %s       |\n", list_menu);

		printf("\t\t\t\t\t\t   ");
		for(i=0; i<z/2; i++){
			printf("\b \b");
		}
		printf("|               ");
		for(i=0; i<z; i++){
			printf(" ");
		}
		printf("|\n");

		printf("\t\t\t\t\t\t   ");
		for(i=0; i<z/2; i++){
			printf("\b \b");
		}
		printf("=========");
		for(i=0; i<z; i++){
			printf("=");
		}
		printf("========\n\n");
	}
	else{
		z = strlen(list_menu);
		if (z>100){z/=2;z-=5;}
		
		printf("  ======");
		for(i=0; i<z; i++){
			printf("=");
		}
		printf("=====\n");
		printf("  |     %s    |\n", list_menu);
		printf("  ======");
		for(i=0; i<z; i++){
			printf("=");
		}
		printf("=====\n\n");
	}
}
