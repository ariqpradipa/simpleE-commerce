/* 
    kontributor :
    1. Ariq Pradipa Santoso
    2. Muhammad Malik Ardiansyah
*/

extern char namaMasukNasabah[20];
extern char idMasukNasabah[20];
extern char saldoMasukNasabah[20];

int browseMarket() {   

    char stringItem[256], stringToko[256];
    char *stripped, *tokoName, *tokoId;
    char *itemName, *itemId, *itemPrice, *itemStock;

    int i, j;
    int countToko = 0;

    char location[50];

    FILE *fileToko = fopen("data/fileToko.txt", "r");

    i = 4;
    // untuk menghitung jumlah toko
    while(fgets(stringToko, sizeof(stringToko), fileToko) != NULL) {

        if(i%4 == 0) {

            countToko++;

        }

        i++;

    }

    fclose(fileToko);

    char namaToko[countToko][20], idToko[countToko][20];

    fileToko = fopen("data/fileToko.txt", "r");

    i = 1; j=0;
    // masukkan nama dan id toko ke dalam array
    while(fgets(stringToko, sizeof(stringToko), fileToko) != NULL) {
        
        stripped = strtok(stringToko, "\n");

        if(i == 1) {

            strcpy(namaToko[j], stripped);
            
        }
        else if(i == 2) {
            
            tokoId = strtok(stripped, " ");
            strcpy(idToko[j], tokoId);
            
        }
        else if(i == 3) {

            i = 0;
            j++;

        }

        i++;

    }

    fclose(fileToko);

    FILE *fileItem;
    printf("    ==============================================\n");
    // menampilkan semua produk yang tersedia di semua toko
    for(i=0; i<countToko; i++) {
        
        strcpy(location, "data/dataToko/");
        strcat(location, idToko[i]);
        strcat(location, ".txt");

        fileItem = fopen(location, "r");

        j = 1;
        while(fgets(stringItem, sizeof(stringItem), fileItem) != NULL) {

            stripped = strtok(stringItem, "\n");

            if(j == 1) {

                itemName = strtok(stripped, "\n");
                printf("    #   |   Nama Barang: %-23s #\n", itemName);

            }
            else if(j == 2) {

                itemId = strtok(stripped, "\n");
                printf("    #   |   Item ID    : %-23s #\n", itemId);

            }
            else if(j == 3) {

                itemPrice = strtok(stripped, "\n");
                printf("    #   |   Harga      : %-23s #\n", itemPrice);            
                
            }
            else if(j == 4) {

                itemStock = strtok(stripped, "\n");
                printf("    #   |   Stok       : %-23s #\n", itemStock);
                printf("    #   |   Toko       : %-23s #\n", namaToko[i]);
                printf("    ==============================================\n");
                
                j = 0;

            }

            j++;

        }
        
        fclose(fileItem);

    }

    printf("\n    ||    Untuk membeli barang tuliskan item ID di opsi kedua pada menu\n");
    printf("    ||  ");
    system("pause");
    system("cls");

    menuUser();

}

int beliItem() {  

    char stringToko[256], stringItem[256], stringUser[256];
    char *stripped, *tokoName, *tokoId, *tokoSaldo;
    char *itemName, *itemId, *itemPrice, *itemStock;
    char *idUser;
    char wishItem[20], tempName[20], tempId[20], tempPrice[20], priceItem[20];

    char location[50];
    char confm;

    int i, j, found, itemLine, lineSearch, jmlh, tempStock;
    int countToko = 0;

    float tempSaldo;
    printf("\n        |   Beli dari ID\n");
    printf("        |   Item ID: "); scanf("%[^\n]s", &wishItem);

    FILE *fileToko = fopen("data/fileToko.txt", "r");

    i = 4;
    while(fgets(stringToko, sizeof(stringToko), fileToko) != NULL) {

        if(i%4 == 0) {

            countToko++;

        }

        i++;

    }

    fclose(fileToko);

    char namaToko[countToko][20], idToko[countToko][20], saldoToko[countToko][20];

    fileToko = fopen("data/fileToko.txt", "r");

    i = 1; j=0;
    // memasukkan nama, id, dan saldo toko ke dalam array
    while(fgets(stringToko, sizeof(stringToko), fileToko) != NULL) {
        
        stripped = strtok(stringToko, "\n");

        if(i == 1) {

            strcpy(namaToko[j], stripped);
            
        }
        else if(i == 2) {
            
            tokoId = strtok(stripped, " ");
            strcpy(idToko[j], tokoId);
            
        }
        else if(i == 3) {

            tokoSaldo = strtok(stripped, " ");
            strcpy(saldoToko[j], tokoSaldo);

            i = 0;
            j++;

        }

        i++;

    }

    found = 0;
    FILE *fileItem;
    for(i=0; i<countToko; i++) {
        
        strcpy(location, "data/dataToko/");
        strcat(location, idToko[i]);
        strcat(location, ".txt");

        fileItem = fopen(location, "r");

        j = 1, itemLine = 1;
        // mengecek di semua toko adakah produk yang memiliki id yang sama seperti yang diminta user
        while(fgets(stringItem, sizeof(stringItem), fileItem) != NULL) {

            stripped = strtok(stringItem, "\n");

            if(j == 2) {

                itemId = strtok(stripped, "\n");
                if(strcmpi(wishItem, itemId) == 0) {

                    found = 1;
                    
                    break;

                }
            }
            else if(j == 4) {

              j = 0;
              itemLine++;

            }

            j++;

        }
        
        fclose(fileItem);

        if(found == 1) {

            break;

        }

    }
    // jika tidak ada toko yang memiliki produk dengan id yang diinput user, maka akan muncul seperti ini
    if(found == 0) {
        
        printf("        |   Item tidak ditemukan!\n");
        printf("        |   ");
        system("pause");
        system("cls");
        fflush(stdin);

        menuUser();

    }
    
    fileItem = fopen(location, "r");

    lineSearch = 1; 
    j = 1;
    // menampilkan kembali informasi produk 
    while(fgets(stringItem, sizeof(stringItem), fileItem) != NULL) {

        if(lineSearch != itemLine) {

            if(j == 4) {

                j = 0;
                lineSearch++;

            }

            j++;
            continue;

        }

        stripped = strtok(stringItem, "\n");

        if(j == 1) {

            itemName = strtok(stripped, "\n");
            printf("\n    ==============================================\n");
            printf("    #   |   Nama Barang: %-23s #\n", itemName);

        }
        else if(j == 2) {

            itemId = strtok(stripped, "\n");
            printf("    #   |   Item ID    : %-23s #\n", itemId);

        }
        else if(j == 3) {

            itemPrice = strtok(stripped, "\n");
            strcpy(tempPrice, itemPrice);
            printf("    #   |   Harga      : %-23s #\n", itemPrice); 
            
        }
        else if(j == 4) {

            itemStock = strtok(stripped, "\n");
            tempStock = atoi(itemStock);
            printf("    #   |   Stok       : %-23s #\n", itemStock);
            printf("    #   |   Toko       : %-23s #\n", namaToko[i]);
            printf("    ==============================================\n");

            printf("    |   Benar Item ini?(y/n) "); scanf(" %c", &confm);
            // konfirmasi ulang benar atau tidaknya produk yang diinginkan
            if(confm == 'y' || confm == 'Y') {
				
                printf("\n    |   Jumlah: "); scanf("%d", &jmlh);
                // jika stok tidak memenuhi keinginan user
                if(atoi(itemStock) < jmlh) {

                    printf("\n    ||  Stok tidak mencukupi!\n");
                    printf("    ||  ");
                    system("pause");
                    system("cls");
                    fflush(stdin);
                    fclose(fileItem);

                    menuUser();
                }
                
                // jika saldo user lebih sedikit dibanding saldo yang diperlukan, maka muncul error
                if((atoi(tempPrice) * jmlh) > atoi(saldoMasukNasabah)) {

                    printf("\n    ||  Saldo anda tidak mencukupi!\n");
                    printf("    ||  ");
                    system("pause");
                    system("cls");
                    fflush(stdin);
                    fclose(fileItem);

                    menuUser();

                }

                tempSaldo = atoi(tempPrice) * jmlh;
                
                break;
        
            }
            // jika input n/N, maka transaksi pembelian dibatalkan
            else if(confm == 'n' || confm == 'N') {

                printf("\n    ||  Pembelian dibatalkan\n");
                printf("    ||  ");
                system("pause");
                system("cls");
                fflush(stdin);
                fclose(fileItem);

                menuUser();

            }
            else {

                printf("    ||   Input Invalid\n");
                printf("    ||  ");
                system("pause");
                system("cls");
                fflush(stdin);
                fclose(fileItem);

                menuUser();

            }
        }

        j++;

    }

    fclose(fileItem);

    fileItem = fopen(location, "a+");
    FILE *fileTemp = fopen("data/dataToko/fileTemp.txt", "a+");
    lineSearch = 1;
    tempStock = tempStock - jmlh;
    j = 1;
    
    while(fgets(stringItem, sizeof(stringItem), fileItem) != NULL) {

        if(lineSearch != itemLine) {

            if(j == 4) {

                j = 0;
                lineSearch++;

            }

            fprintf(fileTemp, "%s", stringItem);
            j++;

            continue;

        }
        
        if(j>=1 && j<=3) {

            fprintf(fileTemp, "%s", stringItem);

        }
        if(j == 4) {

            fprintf(fileTemp, "%d", tempStock);

            j = 0;
            lineSearch++;

        }
        

        j++;

    }

    fclose(fileItem);
    fclose(fileTemp);

    FILE *fileUser = fopen("data/fileUser.txt", "a+");
    fileTemp = fopen("data/fileTemp.txt", "a+");

    char stringTempSaldo[20];
    j = 1;
    found = 0;
    while(fgets(stringUser, sizeof(stringUser), fileUser) != NULL) {

        stripped = strtok(stringUser, "\n");
        strcpy(tempId, stripped);
        
        if(j == 2) { // jika ada user dengan id yang sama dengan yang baru saja berbelanja

            idUser = strtok(stripped, " ");

            if(strcmp(idMasukNasabah, idUser) == 0) {

                found = 1;
                fprintf(fileTemp, "%s\n", tempId);

                continue;

            }
        }
        else if(j == 3) {

            j = 0;

        }
        // mengurangi saldo user setelah digunakan untuk belanja
        if(found == 1) {

            tempSaldo = atoi(saldoMasukNasabah) - tempSaldo;
            fprintf(fileTemp, "%.4f\n", tempSaldo);
            strcpy(saldoMasukNasabah, itoa(tempSaldo, stringTempSaldo, 10));
            j = 1;
            found = 0;

            continue;

        }
        fprintf(fileTemp, "%s\n", stringUser);
        j++;

    }

    fclose(fileTemp);
    fclose(fileUser);

    remove(location);
    rename("data/dataToko/fileTemp.txt", location);
    remove("data/fileUser.txt");
    rename("data/fileTemp.txt", "data/fileUser.txt");

    printf("    ||  Pembelian produk berhasil!\n");
    printf("    ||  Saldo anda sudah dikurangkan\n");
    printf("    ||  ");
    system("pause");
    system("cls");
    fflush(stdin);

    menuUser();

}

int ratingUlasan() {  

	char id[20], name[20], ulasan[40];
	int rating;
	
	printf("||====================||\n");
  printf("||   Rating & Ulasan  ||\n");
  printf("||====================||\n\n");
    
  // user memasukkan id toko untuk membuka file rating toko  
  printf("\tMasukan id toko yang ingin anda beri rating: "); scanf(" %[^\n]s", id);
	char fileToko[40] = "data/dataToko/";
	char folder[20] = "_rating.txt";
	strcat(fileToko, id);
	strcat(fileToko, folder);
	
	FILE *fptr = fopen(fileToko, "a+");
	if (fptr == NULL) {

		printf("Error!");
		exit(1);

	}
	
	printf("\n\tMasukan nama produk yang ingin diberi rating: "); scanf(" %[^\n]s", name);
	printf("\n\tRating anda untuk produk ini(1-10): "); scanf("%d", &rating);
	printf("\n\tUlasan anda untuk produk ini: "); scanf(" %[^\n]s", ulasan);
	
  // memasukkan informasi diatas ke file
	fprintf(fptr, "%s\nRating: %d\nUlasan: %s\n", name, rating, ulasan);
	fclose(fptr);
	system("pause");
	system("cls");
	fflush(stdin);

	menuUser();	

}