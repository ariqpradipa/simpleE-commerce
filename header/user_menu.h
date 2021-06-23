extern char namaMasukNasabah[20];
extern char idMasukNasabah[20];
extern char saldoMasukNasabah[20];

struct userData {

    char nama[20];
    char saldo[20];

};

void displayData(struct userData uData);    // untuk menampilkan nama dan sisa saldo user

int menuUser() {  // Muhammad Malik Ardiansyah

    struct userData uData;
    
    int user;

    // judul menu
    printf("    ===================================================\n");
    printf("    #  __  __                    _   _                #\n");
    printf("    # |  \\/  | ___ _ __  _   _  | | | |___  ___ _ __  #\n");
    printf("    # | |\\/| |/ _ \\ '_ \\| | | | | | | / __|/ _ \\ '__| #\n");
    printf("    # | |  | |  __/ | | | |_| | | |_| \\__ \\  __/ |    #\n");
    printf("    # |_|  |_|\\___|_| |_|\\__,_|  \\___/|___/\\___|_|    #\n");
    printf("    ===================================================\n");

    // menginput data kedalam struct
    strcpy(uData.nama, namaMasukNasabah);
    strcpy(uData.saldo, saldoMasukNasabah);

    // menampilkan data user yang login
    displayData(uData);
                                             
    printf("    |   1. Browse Market\n");      
    printf("    | 	2. Cari produk & beli\n");
    printf("    |   3. Memberikan Rating & Ulasan\n"); 
    printf("    |   4. Exit\n\n");
    printf("    |   Pilihan: ");
    scanf("%d", &user);        // input plihan menu

    switch(user) {
        
        case 1: {

            fflush(stdin);
            system("cls");

            browseMarket();     // untuk menampilkan list item yang dijual

        }
        case 2: {

            fflush(stdin);
            system("cls");

            beliItem(); 	// Function untuk mencari produk dan membelinya
        
        }
        case 3: {

            fflush(stdin);
            system("cls");

            ratingUlasan(); // untuk memberikan rating kepada toko

        }
        case 4: {
        
            system("cls");
            fflush(stdin);

            main();             // kembali ke awal
        
        }
        default: {
        
            printf("\n||  Input Invalid!\n");
            printf("||  ");
            system("pause");
            system("cls");
            fflush(stdin);
        
            menuAdmin();        // kembali ke userMenu
        
        }
    }
}

void displayData(struct userData uData) { // Ariq Pradipa Santoso

    printf("\n    |   Selamat datang %s!\n", uData.nama);
    printf("    |   Saldo anda: Rp. %s\n", uData.saldo);
    printf("    |\n");

}