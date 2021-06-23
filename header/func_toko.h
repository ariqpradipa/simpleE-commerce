int tambahProduk(char id[20]) { // Muhammad Malik Ardiansyah

	int jum, i, harga, stok, spaceChecker = 0;
	char nama[20], idProduk[20];
	
	char fileToko[30] = "data/dataToko/";
	char txt[10] = ".txt";
	
	// gabungkan string untuk membuat file directory yang tepat untuk setiap nama toko
	strcat(fileToko, id);
	strcat(fileToko, txt);
	
	printf("	|	Berapa produk yang ingin anda tambahkan: "); scanf("%d", &jum);

  // akan loop sebanyak produk yang ingin ditambah
	for (i=0; i<jum; i++) {
		
		printf("\n	|	Nama Produk: "); scanf(" %[^\n]s", nama);
    printf("	|	Id Produk  : "); scanf(" %[^\n]s", idProduk); // id tidak boleh memakai spasi
	
		// mengecek adanya spasi dalam id produk
	  	#pragma omp parallel num_threads(4)
      // inisialisasikan menjadi 4 thread 
	  	{
        // loop sebanyak jumlah elemen char di idProduk dan mengecek terdapat spasi atau tidak
	    	#pragma omp for
	    	for(i = 0; i<=strlen(idProduk); i++) {    

	      		if(idProduk[i] == ' ') {
	        	spaceChecker = 1;

	      	}
	    }
	    
		#pragma omp barrier	
	    #pragma omp single
      // jika iya akan menampilkan pesan dibawah ini
	    if(spaceChecker == 1) {

	      printf("\n        ||  ID Produk tidak boleh mengandung spasi!\n");
	      printf("        ||  ");
	      system("pause");
	      system("cls");
	      fflush(stdin);
	
	      menuToko(id);

	    }
		}

		printf("	|	Harga	   : Rp "); scanf("%d", &harga);
		printf("	|	Stok	   : "); scanf("%d", &stok);
		
		FILE *fptr = fopen(fileToko, "a+");
		fprintf(fptr, "%s\n%s\n%d\n%d\n", nama, idProduk, harga, stok); // memasukkan data di atas ke file
		fclose(fptr);	

	}
	
	system("pause");
	system("cls");
	fflush(stdin);

	menuToko(id);	// kembali ke menu toko

}

int editProduk(char id[20]) { // Muhammad Malik Ardiansyah     

	char fileToko[40] = "data/dataToko/";
	char fileTemp[40] = "data/dataToko/temp.txt";
	char txt[20] = ".txt";
	char stringUser[256]; // variabel untuk menyimpan data yang diambil dari file
	int i=1, pil, j, k, nomor;
  
  // gabungkan string untuk keperluan membuka file
	strcat(fileToko, id);
	strcat(fileToko, txt);
	
	FILE *fptr = fopen(fileToko, "a+");
	
	if (fptr == NULL) {

		printf("Error!");
		exit(1);

	}
	
	printf("	||====================||\n");
  printf("	||     Edit Produk    ||\n");
  printf("	||====================||\n\n");
  j = 1;
  	
	printf("\n    ===============================================\n");
	/*secara otomatis menampilkan list produk yang dimiliki toko terlebih dahulu
  while ini akan membaca line per line. Satu informasi produk terdiri dari 4 baris, dalam setiap 4 baris
  tersebut, urutan field akan selalu sama, yaitu nama, id, harga, dan stok*/
  while (fgets(stringUser, sizeof(stringUser), fptr) != NULL) {
  		
		if (i == 1) {

		    printf("    #  %d|	Nama Produk : %-20s #\n", j, strtok(stringUser, "\n"));

		}
		else if (i == 2) {

			printf("    #   |	ID Produk   : %-20s #\n", strtok(stringUser, "\n"));

		}
		else if (i == 3) {

			printf("    #   |	Harga Produk: %-20s #\n", strtok(stringUser, "\n"));

		}
    	else if (i == 4) {

			printf("    #   |	Stok Produk : %-20s #\n", strtok(stringUser, "\n"));
			printf("    ===============================================\n");

		}

		i++;	
		if (i > 4) {
			i=1;
			j++;	
		}

	}
	fclose(fptr);

  	printf("\n	|	1. Hapus Produk\n");
  	printf("	|	2. Edit Informasi Produk\n");
  	printf("	|	3. Exit\n\n");
  	printf("	|	Pilihan: "); scanf("%d", &pil);
    
  	// jika memilih menu hapus produk  
  	if (pil == 1) {  
  	/* prinsip-nya adalah dengan mengopy seluruh isi file produk kecuali produk yang dipilih untuk dihapus
  	ke dalam file sementara, menghapus file produk, kemudian mengubah nama file sementara menjadi file produk */

		printf("\n	|	Masukkan nomor produk yang ingin dihapus: "); scanf("%d", &nomor);
		FILE *fptr = fopen(fileToko, "a+");
		FILE *ftemp = fopen(fileTemp, "a+");

		if (fptr == NULL) {

			printf("Error!");
			exit(1);

		}
		if (ftemp == NULL) {

			printf("Error!");
			exit(1);

		}
    	k = 0;
	  	j = 1;

    	// while ini akan mengopy seluruh data file produk kecuali produk yang ingin dihapus
	  	while(fgets(stringUser, sizeof(stringUser), fptr) != NULL) { 
	    	
			if(k == 4) {
	      	k = 0;
	      	j++;

	    }
	    /* jika j sudah sama dengan nomor produk yang ingin dihapus, maka program akan berhenti memasukkan data
      ke fileTemp sebanyak 4 line*/
	    if(j == nomor) {

	      k++;
	      continue;

	    }

	    fprintf(ftemp, "%s", stringUser);
	    k++;

	  	}

		fclose(fptr);
	  fclose(ftemp);

    // menghapus file produk dan mengganti nama file sementara menjadi file produk	
		remove(fileToko);
		rename(fileTemp, fileToko);
			
		system("pause");
		system("cls");
		fflush(stdin);

		menuToko(id);

	}
	
  // jika ingin mengedit informasi produk
	else if (pil == 2) {
  /* prinsip-nya adalah dengan mengopy seluruh isi file produk kecuali field dari sebuah produk yang ingin diganti oleh 
  user ke dalam file sementara, menghapus file produk, kemudian mengubah nama file sementara menjadi file produk */

		int nomor, choice;
		char ubah[20];
		
		printf("	|	Masukkan nomor produk yang ingin diedit: "); scanf("%d", &nomor);
		printf("\n\tField apa yang ingin anda ubah :\n\t1. Nama Produk\n\t2. Id Produk\n\t3. Harga Produk\n\t4. Stok Produk");
	  	printf("\n\tPilihan: "); scanf("%d", &choice);

    // error handling apabila inputnya tidak terdapat dalam pilihan input
	  	if( choice < 1 || choice > 4) {

	    	printf("Invalid Input!!!");
	   	 	menuToko(id);

		}

	  printf("\n\tField tersebut ingin diubah menjadi: "); scanf(" %[^\n]s", ubah);

		FILE *fptr = fopen(fileToko, "a+");
		FILE *ftemp = fopen(fileTemp, "a+");

		if (fptr == NULL) {

			printf("Error!");
			exit(1);

		}
		if (ftemp == NULL) {

			printf("Error!");
			exit(1);

		}

    	k = 0;
	  	j = 1;
	  	while(fgets(stringUser, sizeof(stringUser), fptr) != NULL) {

	    	if(k == 4) {

	      		k = 0;
	      		j++;

	    	}
        /* mirip seperti yg sebelumnya, tetapi disini terdapat seleksi kondisi sehingga pada produk nomer ke sekian
        dan pada field yang dipilih yang akan diganti (nama/id/harga/stok) akan digantikan nilainya oleh string baru*/
	    	if(j == nomor && (k+1) == choice) {	

	      		fprintf(ftemp, "%s\n", ubah);
	      		k++;
	      		continue;

	    	}

	    	if(j == nomor) {

				  fprintf(ftemp, "%s", stringUser);
	      	k++;
	      	continue;

	    	}

	    	fprintf(ftemp, "%s", stringUser);
	    	k++;

	  	}

	  	fclose(fptr);
	  	fclose(ftemp);
			
		remove(fileToko);
		rename(fileTemp, fileToko);
			
		system("pause");
		system("cls");
		fflush(stdin);

		menuToko(id);	

	}
    
  	else if (pil == 3) {

    system("cls");
    fflush(stdin);

    menuToko(id); // kembali ke menu toko

	}
	
	else {
		printf("\n||  Input Invalid!\n");
        printf("||  ");
        system("pause");
        system("cls");
        fflush(stdin);
		menuToko(id); // kembali ke menu toko
	}

	fflush(stdin);	

}

int tampilRating(char id[20]) { // Muhammad Malik Ardiansyah

	char fileToko[40] = "data/dataToko/";
	char txt[20] = "_rating.txt";
	char stringUser[256];
	int i=1, pil, j=1;
	
	strcat(fileToko, id);
	strcat(fileToko, txt);
	
	FILE *fptr = fopen(fileToko, "r+");
  
  // File Rating Toko ini belum akan ada sampai setidaknya terdapat satu user yang memberikan rating ke toko ini
	if (fptr == NULL) {

		printf("	||	File Rating toko ini belum ada!");
		printf("	||	");
		system("pause");
		system("cls");
		
		menuToko(id);

	}
	while (fgets(stringUser, sizeof(stringUser), fptr) != NULL) {
  // akan membaca line per line dalam file dan menampilkannya
  	if (i == 1) {
		  printf("%d	Nama Produk: ", j); printf("%s", stringUser);
		}
		else if (i == 2) {
			printf("	%s", stringUser);
		}
		else if (i == 3) {
			printf("	%s\n", stringUser);
		}
		i++;	
		if (i > 3) {
			i=1;
			j++;	
		}
	}

	fclose(fptr);	
	system("pause");
  system("cls");
  fflush(stdin);

  menuToko(id); // kembali lagi ke editProduk

}
