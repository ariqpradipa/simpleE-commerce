/*
    buat item jual
    hapus jualan
*/

/*
    buat item jual
    hapus jualan
*/

int menuToko(char id[20]) {
	
	int kangToko;
	
    printf("    ===================================================\n");
    printf("    #  __  __                    _____     _          #\n");
    printf("    # |  \\/  | ___ _ __  _   _  |_   _|__ | | _____   #\n");
    printf("    # | |\\/| |/ _ \\ '_ \\| | | |   | |/ _ \\| |/ / _ \\  #\n");
    printf("    # | |  | |  __/ | | | |_| |   | | (_) |   < (_) | #\n");
    printf("    # |_|  |_|\\___|_| |_|\\__,_|   |_|\\___/|_|\\_\\___/  #\n");
    printf("    ===================================================\n");
                                                

    printf("\n    |   1. Tambah Produk\n");
    printf("    |   2. Edit Informasi Produk\n");
    printf("    |   3. Rating dan Ulasan\n");
    printf("    |   4. Exit\n\n");
    printf("    |   Pilihan: ");
    scanf("%d", &kangToko);
    
    switch(kangToko) {
        
        case 1: {

            fflush(stdin);
            system("cls");

            tambahProduk(id);  // function untuk menambahkan produk

        }
        case 2: {

            fflush(stdin);
            system("cls");

            editProduk(id); // edit informasi produk yang telah tersedia
        
        }
        case 3: {

            fflush(stdin);
            system("cls");

            tampilRating(id); // edit informasi produk yang telah tersedia
        
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
        
            menuToko(id);        // kembali ke menuToko
			      
        }
    }
}