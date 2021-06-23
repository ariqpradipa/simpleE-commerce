int menuAdmin() {
    
    int admin;
    
    printf("    =========================================================================\n");
    printf("    #        __  __                       _       _           _             #\n");
    printf("    #       |  \\/  | ___ _ __  _   _     / \\   __| |_ __ ___ (_)_ __        #\n");
    printf("    #       | |\\/| |/ _ \\ '_ \\| | | |   / _ \\ / _` | '_ ` _ \\| | '_ \\       #\n");
    printf("    #       | |  | |  __/ | | | |_| |  / ___ \\ (_| | | | | | | | | | |      #\n");
    printf("    #       |_|  |_|\\___|_| |_|\\__,_| /_/   \\_\\__,_|_| |_| |_|_|_| |_|      #\n");  
    printf("    =========================================================================\n\n");                                            

    printf("\n        |   1. Edit akun user\n");
    printf("        |   2. Edit akun toko\n");
    printf("        |   3. Exit\n\n");
    printf("        |   Pilihan: "); scanf("%d", &admin);        // input plihan menu

    switch(admin) {
        
        case 1: {

            fflush(stdin);

            userEdit();  // edit akun user

        }
        case 2: {

            fflush(stdin);

            tokoEdit(); // edit akun toko
        
        }
        case 3: {
        
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
        
            menuAdmin();        // kembali ke menuAdmin
        
        }
    }
}

int userEdit() {

    int chs;

    printf("        |   1. Tambah saldo user\n");
    printf("        |   2. Hapus akun user\n");
    printf("        |   Pilihan: "); scanf("%d", &chs);

    switch(chs) {

        case 1: {
            
            printf("\n        |   1. Pilih user dari list\n");
            printf("        |   2. Cari ID User\n");
            printf("        |   Pilihan: "); scanf("%d", &chs);

            if(chs == 1) {

                system("cls");

                userList(1);

            }
            else if(chs == 2) {

                system("cls");

                userCari(1);

            }
            else {

                printf("        ||  Input invalid!\n");
                printf("        ||  ");
                system("pause");
                system("cls");
                fflush(stdin);

                menuAdmin();

            }

        }
        case 2: {

            printf("\n        |   1. Pilih user dari list\n");
            printf("        |   2. Cari ID User\n");
            printf("        |   Pilihan: "); scanf("%d", &chs);

            if(chs == 1) {

                system("cls");

                userList(0);

            }
            else if(chs == 2) {

                system("cls");

               userCari(0);

            }
            else {

                printf("        ||  Input invalid!\n");
                printf("        ||  ");
                system("pause");
                system("cls");
                fflush(stdin);

                menuAdmin();

            }
        }
        default: {
        
            printf("\n        ||  Input Invalid!\n");
            printf("        ||  ");
            system("pause");
            system("cls");
            fflush(stdin);
        
            menuAdmin();        // kembali ke menuAdmin
        
        }
    }
}

int tokoEdit() {

    int chs;

    printf("        |   1. Hapus akun toko\n");
    printf("        |   Pilihan: "); scanf("%d", &chs);

    switch(chs) {

        case 1: {

            printf("        |   1. Pilih toko dari list\n");
            printf("        |   2. Cari ID toko\n");
            printf("        |   Pilihan: "); scanf("%d", &chs);

            if(chs == 1) {

                system("cls");

                tokoList(0);

            }
            else if(chs == 2) {

                system("cls");

               tokoCari(0);

            }
            else {

                printf("        ||  Input invalid!\n");
                printf("        ||  ");
                system("pause");
                system("cls");
                fflush(stdin);

                menuAdmin();

            }
        }
        
        default: {
        
            printf("\n||  Input Invalid!\n");
            printf("||  ");
            system("pause");
            system("cls");
            fflush(stdin);
        
            menuAdmin();        // kembali ke menuAdmin
        
        }
    }
}