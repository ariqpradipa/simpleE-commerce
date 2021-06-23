struct listing {

    char *namaUserList;
    char *idUserList;
    struct listing *next;

};

void displayUser(struct listing *head, int userCount);

int userList(int refill) {

    char stringUser[256];
    char *stripped, *userName, *userId;
    char *tempName, *tempId;

    int i, j, n, chs;
    int userCount = 0;

    FILE *fileUser = fopen("data/fileUser.txt", "r");

    if(fileUser == NULL) {                               // jika file fileUser.txt tidak ditemukan akan terjadi error

        printf("        ||  ERROR File Not Found\n");
        printf("        ||  ");
        system("pause");
        system("cls");

        exit(0);
        
    }

    i = 3;
    while(fgets(stringUser, sizeof(stringUser), fileUser) != NULL) {   // menghitung jumlah user dalam file

        if(i%3 == 0) {

            userCount++;

        }
        
        i++;

    }

    fclose(fileUser);

    char namaUser[userCount+1][20], idUser[userCount+1][20];

    fileUser = fopen("data/fileUser.txt", "r");
    
    i = 1, j=0;
    struct listing *head = NULL;                                        // head berisi NULL
    while(fgets(stringUser, sizeof(stringUser), fileUser) != NULL) { 
    
        if(i == 1) {

            stripped = strtok(stringUser, "\n");
            
            userName = strtok(stripped, "\n");
            strcpy(namaUser[j], userName);

            i++;
            continue;

        }
        else if(i == 2) {

            stripped = strtok(stringUser, "\n");

            userId = strtok(stripped, " ");
            strcpy(idUser[j], userId);

            i++;
            continue;

        }

        struct listing *current = malloc(sizeof(struct listing));

        current->namaUserList = (char*) malloc((n)*sizeof(char));
        strcpy(current->namaUserList, namaUser[j]);

        current->idUserList = (char*) malloc((n)*sizeof(char));
        strcpy(current->idUserList, idUser[j]);
       
        current->next = head;              // successor of node is head
        head = current;                    // new node is head of list

        i = 1;
        j++;
        
    }

    fclose(fileUser);

    displayUser(head, userCount);

    while(n != -1) {

        printf("\n    |   Input Nomor User Yang Dipilih\n");
        printf("    |   Untuk Batal Input 0\n");
        printf("    |   Input: "); scanf("%d", &chs);

        if(chs < 0 || chs > userCount) {

            printf("    ||  Input Invalid!\n");
            printf("    ||  ");
            system("pause");
            system("cls");
            fflush(stdin);

            userList(refill);

        }
        else if(chs == 0) {

            system("cls");
            fflush(stdin);

            menuAdmin();

        }
        else{

            if(refill == 1) {

                chs = (userCount - chs + 1);
                userDeposit(chs);

            }
            else if(refill == 0) {

                chs = (userCount - chs + 1);
                userDelete(chs);

            }
        }
    }
}

void displayUser(struct listing *head, int userCount) {

    int i;

    struct listing *temp = head;
    
    printf("    =============================================\n");
    for(i=0; i<userCount; i++) {
        
        printf("    #  %d|   Nama:   %-27s #\n", i+1, temp->namaUserList);
        printf("    #   |   ID:     %-27s #\n", temp->idUserList);
        printf("    =============================================\n");

        temp = temp->next;

    }
}



int userCari(int refill) {

    char stringUser[256]; 
    char *stripped, *namaUser, *idUser;
    char uId[20], tempName[20], tempId[20];
    char confm;

    int i, j, line;

    FILE *fileUser = fopen("data/fileUser.txt", "r");

    if(fileUser == NULL) {

        printf("    ||  Error File Not Found\n");
        printf("    ||  ");
        system("pause");
        system("cls");

        exit(101);
    }

    printf("\n    ||  Pencarian Berdasarkan User ID\n");
    printf("    |   userid: "); scanf("%s", &uId);

    line = 1;
    i = 1; j = 0;
    while(fgets(stringUser, sizeof(stringUser), fileUser) != NULL) {

        stripped = strtok(stringUser, "\n");

        if(i == 1) {

            stripped = strtok(stringUser, "\n");
            
            namaUser = strtok(stripped, "\n");
            strcpy(tempName, namaUser);

            i++;
            continue;

        }
        else if(i == 2) {

            idUser = strtok(stripped, " ");
            strcpy(tempId, idUser);

            if(strcmpi(uId, tempId) == 0) {

                printf("\n    |   Nama: %s\n", tempName);
                printf("    |   User ID: %s\n", tempId);
                printf("    ||  Benar akun ini?(y/n) "); scanf(" %c", &confm);

                if(confm == 'y' || confm == 'Y') {

                    fclose(fileUser);

                    if(refill == 1) {

                        userDeposit(line);

                    }
                    else if(refill == 0) {

                        userDelete(line);

                    }
                }
                else if(confm == 'n' || confm == 'N') {

                    printf("\n    ||  Penghapusan akun batal...\n");
                    printf("    ||  ");
                    system("pause");
                    system("cls");
                    fflush(stdin);
                    fclose(fileUser);

                    menuAdmin();

                }
                else {

                    printf("\n    ||  Input Invalid!\n");
                    printf("    ||  ");
                    system("pause");
                    system("cls");
                    fflush(stdin);
                    fclose(fileUser);

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

    printf("\n    ||  User tidak ditemukan!\n");
    printf("    ||  ");
    system("pause");
    system("cls");
    fflush(stdin);
    fclose(fileUser);

    menuAdmin();

}

int userDeposit(int userSelect) {

    char stringUser[256];
    char *stripped, *userName, *userId, *saldo;

    int i, j;
    float inputSaldo;

    
    printf("\n    |   Jumlah Saldo: "); scanf("%f", &inputSaldo);

    FILE *fileUser = fopen("data/fileUser.txt", "a+");
    FILE *fileTemp = fopen("data/tempUser.txt", "a+");

    i = 0;
    j = 1;
    while(fgets(stringUser, sizeof(stringUser), fileUser) != NULL) {

        i++;
        if(userSelect == j) {
            
            if(i == 1 || i == 2) {

                fprintf(fileTemp, "%s", stringUser);
                continue;

            }
            else if(i == 3) {

                inputSaldo = inputSaldo + atoi(stringUser);

                fprintf(fileTemp, "%.4f\n", inputSaldo);

                i = 0;
                j++;
                continue;

            }
        }
        if(i == 3) {

            i = 0;
            j++;

        }

        fprintf(fileTemp, "%s", stringUser);

    }

    fclose(fileUser);
    fclose(fileTemp);

    remove("data/fileUser.txt");
    rename("data/tempUser.txt", "data/fileUser.txt");

    printf("\n    ||   Penambahan saldo berhasil!\n");
    printf("    ||  ");
    system("pause");
    system("cls");
    fflush(stdin);

    menuAdmin();

}

int userDelete(int userSelect) {

    char stringUser[256];
    char *stripped, *userName, *userId, *saldo;

    int i, j;

    char confm;

    FILE *fileUser = fopen("data/fileUser.txt", "a+");
    FILE *fileTemp = fopen("data/tempUser.txt", "a+");

    printf("\n    |   Anda yakin untuk menghapus user ini?(Y/N) "); scanf(" %c", &confm);

    if(confm == 'y' || confm =='Y') {

        i = 0;
        j = 1;
        while(fgets(stringUser, sizeof(stringUser), fileUser) != NULL) {
        
            if(i == 3) {

                i = 0;
                j++;

            }
            if(j == userSelect) {

                i++;
                continue;
                
            }
    
            fprintf(fileTemp, "%s", stringUser);

            i++;

        }
    
        fclose(fileUser);
        fclose(fileTemp);
    
        remove("data/fileUser.txt");
        rename("data/tempUser.txt", "data/fileUser.txt");
    
        printf("\n    ||   Penghapusan akun berhasil!\n");
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
