// variable global untuk menyimpan data login
// nasabah adalah orang yang membeli belanjaan
extern char namaMasukNasabah[20];
extern char idMasukNasabah[20];
extern char saldoMasukNasabah[20];

int loginAdmin() { // Mochammad Shaffa Prawiranegara

    char username[20], validUser[20];
    int pass, validPass, admin;

    // predefine username and password
    strcpy(validUser, "admin");     // username yang benar
    validPass = 12345;              // password yang benar

    printf("\n        |   Admin ID: "); scanf("%s", &username);
    printf("        |   Password: "); scanf("%d", &pass);

    if(strcmp(username, validUser) == 0 && pass == validPass) { // jika username dan password yang di input benar

        printf("\n        ||    Login Berhasil!\n");
        printf("        ||  ");
        system("pause");

        system("cls");
        fflush(stdin);

        menuAdmin();    // terdapat pada admin_menu.h

    }
    else {  // jika username dan password yang di input salah

        printf("\n        ||    Admin ID / Password salah!\n");
        printf("        ||  ");
        system("pause");
        fflush(stdin);
        system("cls");

        main(); // kembali ke awal

    }
}

int loginToko() { // Ariq Pradipa Santoso dan Mochammad Shaffa Prawiranegara

    char stringToko[256];
    char idToko[20], passToko[20];
    char *stripped, *checkId, *checkPass;
    int idLine = 1, login = 0;

    FILE *fileToko = fopen("data/fileToko.txt", "r");   // membuka file

    if(fileToko == NULL) {                              // jika file nasabah.txt tidak ditemukan akan terjadi error

        printf("        ||  ERROR File Not Found\n");
        printf("        ||  ");
        system("pause");
        system("cls");

        exit(0);
        
    }

    printf("\n        |  ID Toko: "); scanf(" %[^\n]s", &idToko);
    printf("        |  Password: "); scanf(" %[^\n]s", &passToko);

    while(fgets(stringToko, sizeof(stringToko), fileToko) != NULL) {   // loop untuk mengecek apakah userID yang dimasukkan ada yang sama
        
        if(idLine == 1) {

            idLine++;
            continue;

        }
        else if(idLine == 3) {

            idLine = 1;
            continue;

        }

        stripped = strtok(stringToko, "\n");
        checkId = strtok(stripped, " ");
        checkPass = strtok(NULL, " ");

        if(strcmp(idToko, checkId) == 0 && strcmp(passToko, checkPass) == 0) {   // jika nama id sama seperti di dalam file

            login = 1;
            break;
        
        }

        idLine++;

    }

    fclose(fileToko);   // menutup file

    if(login == 1) {    // jika kredensial login benar maka akan masuk kesini

        printf("\n        ||  Login Berhasil!\n");
        printf("        ||  ");
        system("pause");
        system("cls");

        menuToko(idToko);   // berada pada header toko_menu.h
    
    }
    else if(login == 0) {   // jika kredensial login yang di input salah

        printf("\n        ||  ID Toko / Password yang dimasukkan salah!\n");
        printf("        ||  ");
        system("pause");
        system("cls");
        fflush(stdin);

        main();

    }
}

int loginUser() { // Ariq Pradipa Santoso dan Mochammad Shaffa Prawiranegara

    char stringUser[256];
    char idUser[20], passUser[20];
    char *stripped, *checkId, *checkPass;
    int idLine = 1, login = 0;

    FILE *fileUser = fopen("data/fileUser.txt", "r");   // membuka file

    if(fileUser == NULL) {                              // jika file nasabah.txt tidak ditemukan akan terjadi error

        printf("        ||  ERROR File Not Found\n");
        printf("        ||  ");
        system("pause");
        system("cls");

        exit(0);
        
    }

    // input user ID dan password
    printf("\n        |   ID User: "); scanf(" %[^\n]s", &idUser);
    printf("        |   Password: "); scanf(" %[^\n]s", &passUser);

    // loop untuk mengecek apakah userID dan password yang dimasukkan ada yang sama
    while(fgets(stringUser, sizeof(stringUser), fileUser) != NULL) {   
        
        if(idLine == 99) {

            strcpy(saldoMasukNasabah, strtok(stringUser, "\n"));    // memasukkan saldo kedalam variable global
            login = 1;

            break;

        }
        else if(idLine == 1) {

            strcpy(namaMasukNasabah, strtok(stringUser, "\n"));     // memasukkan nama kedalam variable global
            idLine++;
            continue;

        }
        else if(idLine == 2) {

            stripped = strtok(stringUser, "\n");
            checkId = strtok(stripped, " ");
            checkPass = strtok(NULL, " ");

            if(strcmp(idUser, checkId) == 0 && strcmp(passUser, checkPass) == 0) {   // jika nama id sama seperti yang di dalam file

                strcpy(idMasukNasabah, idUser);                     // memasukkan id kedalam variable global
                idLine = 99;
                continue;
        
            }

            idLine++;

        }
        else if(idLine == 3) {

            idLine = 1;
            continue;

        }

    }

    fclose(fileUser);   // menutup file

    if(login == 1) {

        printf("\n        ||  Login Berhasil!\n");
        printf("        ||  ");
        system("pause");
        system("cls");

        menuUser();
    
    }
    else if(login == 0) {

        printf("\n        ||  ID User / Password yang dimasukkan salah!\n");
        printf("        ||  ");
        system("pause");
        system("cls");
        fflush(stdin);

        main();

    }
}