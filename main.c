#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <omp.h>

#include "header/admin_menu.h"
#include "header/login.h"
#include "header/register.h"
#include "header/toko_menu.h"
#include "header/user_menu.h"
#include "header/func_user.h"
#include "header/func_toko.h"
#include "header/adminUser.h"
#include "header/adminToko.h"

// login header
int loginAdmin();
int loginToko();
int loginUser();

//header register
int registerToko();
int registerUser();

// menu
int menuUser();
int menuToko(char id[20]);
int menuAdmin();

// user Edit
int userEdit();
int userList();
int userCari();
int userDeposit(int userSelect);
int userDelete(int userSelect);

// toko Edit
int tokoEdit();
int tokoList();
int tokoCari();
int tokoDelete(int *tokoSelect);

// function user
int browseMarket();

// function toko
int tambahProduk(char id[20]);
int editProduk(char id[20]);

char namaMasukNasabah[20];
char idMasukNasabah[20];
char saldoMasukNasabah[20];

int main() {


    int chs;

    // program title
    printf("    ==============================================================================================================\n");
    printf("    #     ________  _______   _______   ________        ________  _________  ________  ________  _______         #\n");
    printf("    #    |\\   ___ \\|\\  ___ \\ |\\  ___ \\ |\\   __  \\      |\\   ____\\|\\___   ___\\\\   __  \\|\\   __  \\|\\  ___ \\        #\n");
    printf("    #    \\ \\  \\_|\\ \\ \\   __/|\\ \\   __/|\\ \\  \\|\\  \\     \\ \\  \\___|\\|___ \\  \\_\\ \\  \\|\\  \\ \\  \\|\\  \\ \\   __/|       #\n");
    printf("    #     \\ \\  \\ \\\\ \\ \\  \\_|/_\\ \\  \\_|/_\\ \\   ____\\     \\ \\_____  \\   \\ \\  \\ \\ \\  \\\\\\  \\ \\   _  _\\ \\  \\_|/__     #\n");
    printf("    #      \\ \\  \\_\\\\ \\ \\  \\_|\\ \\ \\  \\_|\\ \\ \\  \\___|      \\|____|\\  \\   \\ \\  \\ \\ \\  \\\\\\  \\ \\  \\\\  \\\\ \\  \\_|\\ \\    #\n");
    printf("    #       \\ \\_______\\ \\_______\\ \\_______\\ \\__\\           ____\\_\\  \\   \\ \\__\\ \\ \\_______\\ \\__\\\\ _\\\\ \\_______\\   #\n");
    printf("    #        \\|_______|\\|_______|\\|_______|\\|__|          |\\_________\\   \\|__|  \\|_______|\\|__|\\|__|\\|_______|   #\n");
    printf("    #                                                     \\|_________|                                           #\n");
    printf("    ==============================================================================================================\n");

    // memilih jenis login
    printf("\n\n");                                                         
    printf("        |   1. Admin%-10s|\n", "");
    printf("    	|   2. Toko%-11s| \n", "");
    printf("    	|   3. User%-11s| \n", "");
    printf("    	|   4. Help%-11s| \n", "");
    printf("    	|                 \n");
    printf("    	|   Input: "); scanf("%d", &chs);

    switch(chs) {

        case 1: {

            loginAdmin();   // di header login.h

        }
        case 2: {
            
            printf("\n        |   1. Login\n");
            printf("        |   2. Create New Account\n");
            printf("        |   Input: "); scanf("%d", &chs);

            if(chs == 1) {

                loginToko();    // di header login.h
            }
            else if(chs == 2) {

                system("cls");

                registerToko(); // di header register.h

            }
            else {

                printf("\n        |   Input Invalid!\n");
                printf("        |   ");
                system("pause");
                system("cls");
                fflush(stdin);

                main();

            }
        }
        case 3: {

            printf("\n        |   1. Login\n");
            printf("        |   2. Create New Account\n");
            printf("        |   Input: "); scanf("%d", &chs);

            if(chs == 1) {

                loginUser();    // di header login.h

            }
            else if(chs == 2) {

                system("cls");

                registerUser(); // di header register.h

            }
            else {

                // jika input tidak benar
                printf("\n        |   Input Invalid!\n");
                printf("        |   ");
                system("pause");
                system("cls");
                fflush(stdin);

                main();

            }
        }
        case 4: {

            printf("        |   Ini adalah program e-commerce sederhana yang dapat melakukan jual beli yang mudah\n");
            printf("        |   ");
            system("pause");
            system("cls");
            fflush(stdin);
            
            main();

        }
        default: {

            // jika input yang dimasukkan tidak sesuai
            printf("\n        |   Input yang dimasukkan salah!\n");
            printf("        |   ");
            system("pause");
            system("cls");
            fflush(stdin);

            main();

        }
    }
}