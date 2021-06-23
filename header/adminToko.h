struct listingToko {

    char *namaTokoList;
    char *idTokoList;
    struct listingToko *next;

};

int tokoList(int refill) { // Mochammad Shaffa Prawiranegara

    char stringToko[256];
    char *stripped, *tokoName, *tokoId;
    char *tempName, *tempId;

    int i, j, n, chs;
    int tokoCount = 0;

    FILE *fileToko = fopen("data/fileToko.txt", "r");

    if(fileToko == NULL) {                               // jika fileToko.txt tidak ditemukan akan terjadi error

        printf("        ||  ERROR File Not Found\n");
        printf("        ||  ");
        system("pause");
        system("cls");

        exit(0);
        
    }

    i = 3;
    while(fgets(stringToko, sizeof(stringToko), fileToko) != NULL) {   // menghitung jumlah toko dalam file

        if(i%3 == 0) {

            tokoCount++;

        }
        
        i++;

    }

    fclose(fileToko);

    char namaToko[tokoCount+1][20], idToko[tokoCount+1][20];

    fileToko = fopen("data/fileToko.txt", "r");
    
    i = 1, j=0;
    struct listingToko *head = NULL;                                        // head berisi NULL
    while(fgets(stringToko, sizeof(stringToko), fileToko) != NULL) { 
    
        if(i == 1) {

            stripped = strtok(stringToko, "\n");
            
            tokoName = strtok(stripped, "\n");
            strcpy(namaToko[j], tokoName);

            i++;
            continue;

        }
        else if(i == 2) {

            stripped = strtok(stringToko, "\n");

            tokoId = strtok(stripped, " ");
            strcpy(idToko[j], tokoId);

            i++;
            continue;

        }

        struct listingToko *current = malloc(sizeof(struct listingToko));

        current->namaTokoList = (char*) malloc((n)*sizeof(char));
        strcpy(current->namaTokoList, namaToko[j]);

        current->idTokoList = (char*) malloc((n)*sizeof(char));
        strcpy(current->idTokoList, idToko[j]);
       
        current->next = head;              // successor of node is head
        head = current;                    // new node is head of list

        i = 1;
        j++;
        
    }

    fclose(fileToko);

    struct listingToko *temp = head;
    printf("    =============================================\n");
    for(i=0; i<tokoCount; i++) {
        
        printf("    #  %d|   Nama:   %-27s #\n", i+1, temp->namaTokoList);
        printf("    #   |   ID:     %-27s #\n", temp->idTokoList);
        printf("    =============================================\n");

        temp = temp->next;

    }

    while(n != -1) {

        printf("\n    |   Input Nomor Toko Yang Dipilih\n");
        printf("    |   Untuk Batal Input 0\n");
        printf("    |   Input: "); scanf("%d", &chs);

        if(chs < 0 || chs > tokoCount) {

            printf("    ||  Input Invalid!\n");
            printf("    ||  ");
            system("pause");
            system("cls");
            fflush(stdin);

            tokoList(refill);

        }
        else if(chs == 0) {

            system("cls");
            fflush(stdin);

            menuAdmin();

        }
        else{

            if(refill == 0) {

                chs = (tokoCount - chs + 1);
                tokoDelete(&chs);

            }
        }
    }
}

int tokoCari(int refill) { // Mochammad Shaffa Prawiranegara

    char stringToko[256]; 
    char *stripped, *namaToko, *idToko;
    char uId[20], tempName[20], tempId[20];
    char confm;

    int i, j, line;

    FILE *fileToko = fopen("data/fileToko.txt", "r");

    if(fileToko == NULL) {

        printf("    ||  Error File Not Found\n");
        printf("    ||  ");
        system("pause");
        system("cls");

        exit(101);
    }

    printf("\n    ||  Pencarian Berdasarkan Toko ID\n");
    printf("    |   tokoid: "); scanf("%s", &uId);

    line = 1;
    i = 1; j = 0;
    while(fgets(stringToko, sizeof(stringToko), fileToko) != NULL) {

        stripped = strtok(stringToko, "\n");

        if(i == 1) {

            stripped = strtok(stringToko, "\n");
            
            namaToko = strtok(stripped, "\n");
            strcpy(tempName, namaToko);

            i++;
            continue;

        }
        else if(i == 2) {

            idToko = strtok(stripped, " ");
            strcpy(tempId, idToko);

            if(strcmpi(uId, tempId) == 0) {

                printf("\n    |   Nama: %s\n", tempName);
                printf("    |   Toko ID: %s\n", tempId);
                printf("    ||  Benar toko ini?(y/n) "); scanf(" %c", &confm);

                if(confm == 'y' || confm == 'Y') {

                    fclose(fileToko);

                    if(refill == 0) {

                    	tokoDelete(&line);

                    }
                }
                else if(confm == 'n' || confm == 'N') {

                    printf("\n    ||  Penghapusan toko batal...\n");
                    printf("    ||  ");
                    system("pause");
                    system("cls");
                    fflush(stdin);
                    fclose(fileToko);

                    menuAdmin();

                }
                else {

                    printf("\n    ||  Input Invalid!\n");
                    printf("    ||  ");
                    system("pause");
                    system("cls");
                    fflush(stdin);
                    fclose(fileToko);

                    menuAdmin();

                }
            }

            i++;
            continue;
        }

        i = 1;
        j++;
        line++;

    } 

    printf("\n    ||  Toko tidak ditemukan!\n");
    printf("    ||  ");
    system("pause");
    system("cls");
    fflush(stdin);
    fclose(fileToko);

    menuAdmin();

}

int tokoDelete(int *tokoSelect) { // Mochammad Shaffa Prawiranegara

    char stringToko[256];
    char *stripped, *tokoName, *tokoId;
    char idTemp[20];
    char location[50] = "data/dataToko/";

    int i, j;

    char confm;

    FILE *fileToko = fopen("data/fileToko.txt", "a+");
    FILE *fileTemp = fopen("data/tempToko.txt", "a+");

    printf("\n    |   Anda yakin untuk menghapus toko ini?(Y/N) "); scanf(" %c", &confm);

    if(confm == 'y' || confm =='Y') {

        i = 0;
        j = 1;
        while(fgets(stringToko, sizeof(stringToko), fileToko) != NULL) {
        
            if(i == 3) {

                i = 0;
                j++;

            }
            if(j == *tokoSelect) {

                if(i == 1) {

                    tokoId = strtok(stringToko, " ");
                    strcpy(idTemp, tokoId);

                }

                i++;
                continue;
                
            }
    
            fprintf(fileTemp, "%s", stringToko);

            i++;

        }
        
        fclose(fileToko);
        fclose(fileTemp);

        strcat(location, idTemp);
        strcat(location, ".txt");
        remove(location);

        strcpy(location, "data/dataToko/");
        strcat(location, idTemp);
        strcat(location, "_rating.txt");
        remove(location);
        
        remove("data/fileToko.txt");
        rename("data/tempToko.txt", "data/fileToko.txt");
    
        printf("\n    ||   Penghapusan toko berhasil!\n");
        printf("    ||  ");
        system("pause");
        system("cls");
        fflush(stdin);
    
        menuAdmin();
    

    }
    else if(confm == 'n' || confm == 'N') {

        system("cls");
        fflush(stdin);

        menuAdmin();

    }
    else {

        printf("    ||  Input Invalid!\n");
        printf("    ||  ");
        system("pause");
        system("cls");
        fflush(stdin);

        menuAdmin();

    }
}