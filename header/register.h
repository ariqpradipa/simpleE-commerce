int registerToko() {

    char namaToko[20], idToko[20], passToko[20];
    char stringToko[256];
    char *checkId;
    int idLine = 1, i = 0;                               // memastikan bahwa line ke 2 yang di cek
    int spaceChecker = 0;

    char itemPath[30] = "data/dataToko/";               // untuk membuat file baru berisikan barang toko

    char *stripped;
    char sc = 'a';

    // judul function
    printf("    =============================================================================================\n");
    printf("    #        _____     _          ______           _     _             _   _                    #\n");
    printf("    #       |_   _|   | |         | ___ \\         (_)   | |           | | (_)                   #\n");
    printf("    #         | | ___ | | _____   | |_/ /___  __ _ _ ___| |_ _ __ __ _| |_ _  ___  _ __         #\n");
    printf("    #         | |/ _ \\| |/ / _ \\  |    // _ \\/ _` | / __| __| '__/ _` | __| |/ _ \\| '_ \\        #\n");
    printf("    #         | | (_) |   < (_) | | |\\ \\  __/ (_| | \\__ \\ |_| | | (_| | |_| | (_) | | | |       #\n");
    printf("    #         \\_/\\___/|_|\\_\\___/  \\_| \\_\\___|\\__, |_|___/\\__|_|  \\__,_|\\__|_|\\___/|_| |_|       #\n");
    printf("    #                                         __/ |                                             #\n");
    printf("    #                                        |___/                                              #\n");
    printf("    =============================================================================================\n");

    printf("\n");
    printf("        |   Pembuatan Akun Toko\n");
    printf("        |\n");

    FILE *fileToko = fopen("data/fileToko.txt", "r");    // membuka file

    if(fileToko == NULL) {                               // jika file nasabah.txt tidak ditemukan akan terjadi error

        printf("        ||  ERROR File Not Found\n");
        printf("        ||  ");
        system("pause");
        system("cls");

        exit(0);                                         // keluar
        
    }

    printf("        |   Nama Toko: "); scanf(" %[^\n]s", &namaToko);        // input nama
    printf("        |   ID Toko: "); scanf(" %[^\n]s", &idToko);            // input id toko
    printf("        |   Password Login: "); scanf(" %[^\n]s", &passToko);   // input password toko

    // mengecek adanya spasi dalam user id dan pass
    #pragma omp parallel num_threads(4) 
    {

        #pragma omp for
        for(i = 0; i<=strlen(idToko); i++) {    // mengecek apakah terdapat spasi di idToko

            if(idToko[i] == ' ') {

                spaceChecker = 1;

            }
        }

        #pragma omp for
        for(i = 0; i<=strlen(passToko); i++) {    // mengecek apakah terdapat spasi di passToko

            if(passToko[i] == ' ') {

                spaceChecker = 1;

            }
        }

        #pragma omp single
        if(spaceChecker == 1) {

            printf("\n        ||  ID Toko dan Password tidak boleh mengandung spasi!\n");
            printf("        ||  ");
            system("pause");
            system("cls");
            fflush(stdin);
            fclose(fileToko);
            
			#pragma omp critical
            main();

        }
    }

    while(fgets(stringToko, sizeof(stringToko), fileToko) != NULL) {   // loop untuk mengecek apakah nama depan yang dimasukkan ada yang sama
        
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

        if(strcmpi(idToko, checkId) == 0) {   // jika nama id sama seperti yang sudah ada

            printf("\n        ||  ID sudah digunakan! gunakan ID yang lain\n");
            printf("        ||  ");
            system("pause");
            system("cls");
            fflush(stdin);
            fclose(fileToko);

            main();
        
        }

        idLine++;

    }

    fclose(fileToko);
    fileToko = fopen("data/fileToko.txt", "a+");

    fprintf(fileToko, "%s\n", namaToko);
    fprintf(fileToko, "%s %s\n0\n", idToko, passToko);

    fclose(fileToko);

    printf("        |   \n");
    printf("        |   Akun Berhasil Dibuat!\n");
    printf("        |   ");
    system("pause");

    strcat(itemPath, idToko);
    strcat(itemPath, ".txt");

    FILE *fileItem = fopen(itemPath, "a+");
    fclose(fileItem);

    system("cls");
    fflush(stdin);

    main();

}

int registerUser() {

    char namaUser[30], idUser[20], passUser[20];
    char stringUser[256];
    char *stripped, *checkId;

    int spaceChecker = 0, i;
    int idLine = 1;

    printf("    ===========================================================================================\n");
    printf("    #       _   _                 ____            _     _             _   _                   #\n");
    printf("    #      | | | |___  ___ _ __  |  _ \\ ___  __ _(_)___| |_ _ __ __ _| |_(_) ___  _ __        #\n");
    printf("    #      | | | / __|/ _ \\ '__| | |_) / _ \\/ _` | / __| __| '__/ _` | __| |/ _ \\| '_ \\       #\n");
    printf("    #      | |_| \\__ \\  __/ |    |  _ <  __/ (_| | \\__ \\ |_| | | (_| | |_| | (_) | | | |      #\n");
    printf("    #       \\___/|___/\\___|_|    |_| \\_\\___|\\__, |_|___/\\__|_|  \\__,_|\\__|_|\\___/|_| |_|      #\n");
    printf("    #                                       |___/                                             #\n");
    printf("    ===========================================================================================\n");

    printf("\n");
    printf("        |   Pembuatan Akun User\n");
    printf("        |\n");
    
    FILE *fileUser = fopen("data/fileUser.txt", "r");

    if(fileUser == NULL) {                               // jika file nasabah.txt tidak ditemukan akan terjadi error

        printf("        ||  ERROR File Not Found\n");
        printf("        ||  ");
        system("pause");
        system("cls");

        exit(0);
        
    }

    printf("        |   Nama User: "); scanf(" %[^\n]s", &namaUser);
    printf("        |   ID User: "); scanf(" %[^\n]s", &idUser);
    printf("        |   Password Login: "); scanf(" %[^\n]s", &passUser);

    // mengecek adanya spasi dalam user id dan pass
    #pragma omp parallel num_threads(4) 
    {

        #pragma omp for
        for(i = 0; i<=strlen(idUser); i++) {    // mengecek apakah terdapat spasi di idUser

            if(idUser[i] == ' ') {

                spaceChecker = 1;

            }
        }

        #pragma omp for
        for(i = 0; i<=strlen(passUser); i++) {    // mengecek apakah terdapat spasi di passUser

            if(passUser[i] == ' ') {

                spaceChecker = 1;

            }
        }

        #pragma omp single
        if(spaceChecker == 1) {

            printf("\n        ||  ID Toko dan Password tidak boleh mengandung spasi!\n");
            printf("        ||  ");
            system("pause");
            system("cls");
            fflush(stdin);
            fclose(fileUser);

            main();

        }
    }

    while(fgets(stringUser, sizeof(stringUser), fileUser) != NULL) {   // loop untuk mengecek apakah nama depan yang dimasukkan ada yang sama
        
        if(idLine == 1) {

            idLine++;
            continue;

        }
        else if(idLine == 3) {

            idLine = 1;
            continue;

        }

        stripped = strtok(stringUser, "\n");
        checkId = strtok(stripped, " ");

        if(strcmpi(idUser, checkId) == 0) {   // jika nama id sama seperti yang sudah ada

            printf("\n        ||  ID sudah digunakan! gunakan ID yang lain\n");
            printf("        ||  ");
            system("pause");
            system("cls");
            fflush(stdin);
            fclose(fileUser);

            main();
        
        }

        idLine++;

    }

    fclose(fileUser);   // menutup file
    fileUser = fopen("data/fileUser.txt", "a+");    // membuka kembali file dalam mode append

    // menuliskan hasil kedalam file
    fprintf(fileUser, "%s\n", namaUser);
    fprintf(fileUser, "%s %s\n0\n", idUser, passUser);

    fclose(fileUser);   // menutup file

    printf("        |   \n");
    printf("        |   Akun Berhasil Dibuat!\n");
    printf("        |   ");
    system("pause");

    system("cls");
    fflush(stdin);

    main();

}
