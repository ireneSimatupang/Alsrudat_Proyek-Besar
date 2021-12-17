/*Source Code of Video File Handling in C -
  INSERT, UPDATE, DELETE, SORT, SEARCH of STUDENT RECORD - IN FILE WITH STRUCTURE
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <time.h>

typedef struct pengguna{
    char ktp[16];
    char nama[100];
    char hp[16];
    char email[100];
    char password[100];
    char repassword[100];
} pengguna;


typedef struct kota {
	char kode[100];
	char nama[100];
} kota;

typedef struct rute {
	char kbrt[100];
	char tjn[100];
	char kode[100];
	int bisnis;
	int premium;
}rute;



int delay(int number_of_seconds)
{
    // Converting time into milli_seconds
    int milli_seconds = 1000 * number_of_seconds;
  
    // Storing start time
    clock_t start_time = clock();
  
    // looping till required time is not achieved
    while (clock() < start_time + milli_seconds);
}

int tambahRute() {
	rute *r;
	kota k1;
    FILE *fp,*fp1;
    int n,i,j;

    r = (rute*)malloc(100*sizeof(rute));
    fp = fopen("rute.txt","a+");
    fp1 = fopen("kota.txt","r");
    
	printf("#TAMBAH DATA RUTE#\n\n");
	char kode1[100], kode2[100], kode3[100];
    for(i=0;i<1;i++){
    	printf("Tambah Data Rute : ");
    	fflush(stdin);
        scanf("%s %s %d %d",r[i].kbrt,r[i].tjn,&r[i].bisnis,&r[i].premium);
        while(fread(&k1,sizeof(kota),1,fp1)) {
            if(strcmp(r[i].kbrt,k1.nama)==0) {
            	strcpy(kode1,k1.kode);
			} 
			
			if (strcmp(r[i].tjn,k1.nama)==0) {
				strcpy(kode2,k1.kode);
			}
			
			strcpy(kode3,strcat(kode1,"-"));
			strcpy(r[i].kode,(strcat(kode3,kode2)));
        }
        
        fwrite(r+i,sizeof(rute),1,fp);
    }
    
    printf("\n-----------------------------------------");
    printf("\nData Berhasil Ditambahkan\n");
    printf("------------------------------------------");
    
    fclose(fp);
    
    kelolaRute();
}


int tambahKota() {
	kota *k;
    FILE *fp;
    int n,i,j;

    k = (kota*)malloc(100*sizeof(kota));
    fp = fopen("kota.txt","a+");
    
	printf("#TAMBAH DATA KOTA#\n\n");
    for(i=0;i<1;i++){
    	printf("Tambah Kota : ");
    	fflush(stdin);
        scanf("%s %s",k[i].kode,k[i].nama);
        
        fwrite(k+i,sizeof(kota),1,fp);
    }
    
    fclose(fp);
    
}

int lihatRute() {
	rute *r;
	rute r1;
    FILE *fp;
    int n,i,j, counter=1;
    

	
	printf("\n\n-------------------------------------------------------------------");
    
    fp = fopen("rute.txt","r");
	system("cls");
	printf("#LIHAT DATA RUTE#");
	printf("\nData Lengkap Rute Kereta Api");
	printf("\n-------------------------------------------------------------------\n");
	printf("No\t\tKeberangkatan\tTujuan\t\tKode_Rute\t\tBisnis\t\tPremium\n");
	while(fread(&r1,sizeof(rute),1,fp)) { 
		printf("%d\t\t%s\t\t%s\t\t%s\t%d\t%d\n",counter,r1.kbrt,r1.tjn,r1.kode,r1.bisnis,r1.premium);
		counter++;
    }
	
	printf("\n\n-------------------------------------------------------------------");
    fclose(fp);
}

int lihatKota() {
	kota *k;
	kota k1;
    FILE *fp;
    int n,i,j, counter=1;
    
    fp = fopen("kota.txt","r");
	system("cls");
	printf("#LIHAT DATA KOTA#");
	printf("\nData Lengkap Kota");
	printf("\n-------------------------------------------------------------------\n");
	printf("No\t\tKode Kota\t\tNama Kota\n");
	while(fread(&k1,sizeof(kota),1,fp)) { 
		printf("%d\t\t%s\t\t\t%s\n",counter,k1.kode,k1.nama);
		counter++;
    }
	
	printf("\n\n-------------------------------------------------------------------");
    fclose(fp);
}

int editRute() {
	rute *r;
	int i=0;
	int j, found=0, counter=1;
    rute r1;
    kota k1;
    FILE *fp, *fp1, *fp2;
    
    char kode[100], kode1[100], kode2[100], kode3[100];
    
	system("cls");
    lihatRute();


    fflush(stdin);
    
	fp = fopen("kota.txt","r");
    fp1 = fopen("rute.txt","r");
    fp2 = fopen("temp.txt","w");
    
    
    printf("\n\nEdit Rute : \nEDIT_");
    scanf("%[^\n]s",kode);
    
	while(fread(&r1,sizeof(rute),1,fp1)){
    	if(strcmp(r1.kode,kode)==0){
				found = 1;
		    	fflush(stdin);
	            printf("\nKeberangkatan : ");
			    scanf("%[^\n]s",r1.kbrt);
			    fflush(stdin);
			    printf("Tujuan : ");
			    scanf("%[^\n]s",r1.tjn);
			    fflush(stdin);
			    printf("Bisnis : ");
			    scanf("%d",&r1.bisnis);
			    fflush(stdin);
			    printf("Premium : ");
			    scanf("%d",&r1.premium);
				fflush(stdin);	    	

			while(fread(&k1,sizeof(kota),1,fp)) {
//	            if((strcmp(r1.kbrt,k1.nama)==0) && (strcmp(r1.tjn,k1.nama)==0)) {
//	            	if(strcmp(r1.kbrt,k1.nama)==0) {
//						strcpy(kode1,k1.kode);	
//						strcpy(kode3,strcat(kode1,"-"));
//					} else {
//						strcpy(kode2,k1.kode);
//					}
//				} 
//				
//				strcpy(r1.kode,(strcat(kode3,kode2)));
	        }
	    	
        } 
        
    	fwrite(&r1,sizeof(rute),1,fp2);
    }
    fclose(fp);
    fclose(fp1);
    fclose(fp2);
    
    if (found==1) {
	    
    	fp = fopen("rute.txt","w");
    	fp1 = fopen("temp.txt","r");
    	
		while(fread(&r1,sizeof(rute),1,fp1)) {
            fwrite(&r1,sizeof(rute),1,fp);
        }
        
	    fclose(fp);
	    fclose(fp1);
	    
	} else {
		printf("\n\nnot found");
	}
}

int editKota() {
	int i=0;
	int j, found=0, counter=1;
    kota k1;
    FILE *fp, *fp1;
    char kode[100];
    
    fp = fopen("kota.txt","r");
	
    printf("#EDIT DATA KOTA#");
    
	printf("\nData Lengkap Kota");
	printf("\n-------------------------------------------------------------------\n");
	printf("No\t\tKode Kota\t\tNama Kota\n");
	while(fread(&k1,sizeof(kota),1,fp)) { 
		printf("%d\t\t%s\t\t\t%s\n",counter,k1.kode,k1.nama);
		counter++;
    }
	
	printf("\n\n-------------------------------------------------------------------");
	
	fclose(fp);

    fflush(stdin);
    printf("\n\nEdit Kota : \nEDIT_");
    scanf("%[^\n]s",kode);
    
    fp = fopen("kota.txt","r");
    fp1 = fopen("temp.txt","w");
    
    while(fread(&k1,sizeof(kota),1,fp)){
        if(strcmp(k1.kode,kode)==0){
       		found = 1;
        	fflush(stdin);
            printf("\nKode Kota : ");
		    scanf("%[^\n]s",k1.kode);
		    fflush(stdin);
		    printf("Nama Kota : ");
		    scanf("%[^\n]s",k1.nama);
        } 
        fwrite(&k1,sizeof(kota),1,fp1);
    }
    fclose(fp);
    fclose(fp1);
    
    if (found==1) {
    	fp = fopen("kota.txt","w");
    	fp1 = fopen("temp.txt","r");
    	while(fread(&k1,sizeof(kota),1,fp1)) {
            fwrite(&k1,sizeof(kota),1,fp);
        }
        
	    fclose(fp);
	    fclose(fp1);
	} else {
		printf("\n\nnot found");
	}
	
	kelolaRute();
}

int hapusRute() {
	int i, j, found=0;
    rute r1;
    FILE *fp, *fp1;
    char kode[100];
    fp = fopen("rute.txt","r");
	system("cls");
	lihatRute();
    
    printf("\nDelete Rute : DELETE_");
    fflush(stdin);
    scanf("%[^\n]s",kode);

    fp = fopen("rute.txt","r");
    fp1 = fopen("temp.txt","w");
    while(fread(&r1,sizeof(rute),1,fp)){
        if(strcmp(r1.kode,kode)==0){
            found = 1;
        }
        else
            fwrite(&r1,sizeof(rute),1,fp1);
    }
    fclose(fp);
    fclose(fp1);


    if(found){
        fp = fopen("rute.txt","w");
        fp1 = fopen("temp.txt","r");

        while(fread(&r1,sizeof(rute),1,fp1)){
            fwrite(&r1,sizeof(rute),1,fp);
        }
        fclose(fp);
        fclose(fp1);
    }
    else
        printf("\nNot Found.....\n");
}

int hapusKota() {
	int i, j, found=0;
    kota k1;
    FILE *fp, *fp1;
    char kode[100];
    fp = fopen("kota.txt","r");
	system("cls");
	lihatKota();
    
    printf("\nDelete Kota : DELETE_");
    fflush(stdin);
    scanf("%[^\n]s",kode);

    fp = fopen("kota.txt","r");
    fp1 = fopen("temp.txt","w");
    while(fread(&k1,sizeof(kota),1,fp)){
        if(strcmp(k1.kode,kode)==0){
            found = 1;
        }
        else
            fwrite(&k1,sizeof(kota),1,fp1);
    }
    fclose(fp);
    fclose(fp1);


    if(found){
        fp = fopen("kota.txt","w");
        fp1 = fopen("temp.txt","r");

        while(fread(&k1,sizeof(kota),1,fp1)){
            fwrite(&k1,sizeof(kota),1,fp);
        }
        fclose(fp);
        fclose(fp1);
    }
    else
        printf("\nNot Found.....\n");
} 


int kelolaRute() {
	int i, j, counter=1;
    rute r1;
    rute *r;
    FILE *fp;
	
	fp = fopen("rute.txt","r");

	system("cls");
	printf("#LIHAT DATA RUTE#");
	printf("\nData Lengkap Rute Kereta Api");
	printf("\n-------------------------------------------------------------------\n");
    
    printf("No\t\tKeberangkatan\tTujuan\t\tKode_Rute\t\tBisnis\t\tPremium\n");
	while(fread(&r1,sizeof(rute),1,fp)) { 
		printf("%d\t\t%s\t\t%s\t\t%s\t\t%d\t\t%d\n",counter,r1.kbrt,r1.tjn,r1.kode,r1.bisnis,r1.premium);
		counter++;
    }
	
	printf("\n\n-------------------------------------------------------------------");
	
	printf("\n\n1. Tambah Data Rute");
	printf("\n2. Lihat Data Rute");
	printf("\n3. Edit Data Rute");
	printf("\n4. Delete Data Rute");
	printf("\n99. Menu Utama");
	
	printf("\n\nPilihan : ");
	int choice;
	fflush(stdin);
	scanf("%d",&choice);
	
	switch(choice) {
		case 1: 
			system("cls");
			tambahRute();
			kelolaRute();
			break;
		case 2:
			system("cls");
			lihatRute();
			kelolaRute();
			break;
		case 3:
			system("cls");
			editRute();
			kelolaRute();
			break;
		case 4:
			hapusRute();
			kelolaRute();
			system("cls");
			break;
		case 99:
			system("cls");
			menuAdmin();
			break;
		default:
			printf("Inputan anda tidak valid !");
	}
}


int kelolaKota() {
	int i, j, counter=1;
    kota k1;
    kota *k;
    FILE *fp;
	
	fp = fopen("kota.txt","r");

	system("cls");
	printf("#LIHAT DATA KOTA#");
	printf("\nData Lengkap Kota");
	printf("\n-------------------------------------------------------------------\n");
	printf("No\t\tKode Kota\t\tNama Kota\n");
	while(fread(&k1,sizeof(kota),1,fp)) { 
		printf("%d\t\t%s\t\t\t%s\n",counter,k1.kode,k1.nama);
		counter++;
    }
	
	printf("\n\n-------------------------------------------------------------------");
	
	printf("\n\n1. Tambah Data Kota");
	printf("\n2. Lihat Data Kota");
	printf("\n3. Edit Data Kota");
	printf("\n4. Delete Data Kota");
	printf("\n99. Menu Utama");
	
	printf("\n\nPilihan : ");
	int choice;
	fflush(stdin);
	scanf("%d",&choice);
	
	switch(choice) {
		case 1: 
			system("cls");
			tambahKota();
			kelolaKota();
			break;
		case 2:
			system("cls");
			lihatKota();
			kelolaKota();
			break;
		case 3:
			system("cls");
			editKota();
			kelolaKota();
			break;
		case 4:
			system("cls");
			hapusKota();
			kelolaKota();
			break;
		case 99:
			system("cls");
			menuAdmin();
			break;
		default:
			printf("Inputan anda tidak valid !");
	}
	
}


int kelolaPengguna() {
    int i, j, found=0;
    pengguna s1;
    FILE *fp, *fp1;
    char ktp[100];
    printf("#KELOLA AKUN BY ADMIN#");
    
    fflush(stdin);
    printf("\nMasukkan Nomor KTP : ");
    scanf("%[^\n]s",ktp);

    fp = fopen("pengguna.txt","r");
    fp1 = fopen("temp.txt","w");
    while(fread(&s1,sizeof(pengguna),1,fp)){
        if(strcmp(s1.ktp,ktp)==0){
            found = 1;
            printf("--Data Pengguna--");
            printf("\nNama Lengkap : %s",s1.nama);
   			printf("\nNomor Handphone : %s",s1.hp);
   			printf("\nEmail : %s",s1.email);
   			printf("\nPassword : %s",s1.password);  
   			
   			printf("\n\n--Ubah Data Pengguna--");
            fflush(stdin);
        	printf("\nNomor KTP : ");
	        fflush(stdin);
	        scanf("%[^\n]s",s1.ktp);
	        fflush(stdin);
	        printf("Nama Lengkap : ");
	        scanf("%[^\n]s",s1.nama);
	        fflush(stdin);
	        printf("Nomor Handphone : ");
	        scanf("%[^\n]s",s1.hp);
	        fflush(stdin);
	        printf("Email : ");
	        scanf("%[^\n]s",s1.email);
	        fflush(stdin);
	        printf("Password : ");
	        scanf("%[^\n]s",s1.password);
	        fflush(stdin);
	        printf("Re-Password : ");
	        scanf("%[^\n]s",s1.repassword);
        } else {
        	printf("\nTidak Ada Nomor KTP dalam sistem, silahkan coba lagi\n");
        	kelolaPengguna();
		}
        fwrite(&s1,sizeof(pengguna),1,fp1);
    }
    fclose(fp);
    fclose(fp1);


    if(found){
        fp = fopen("pengguna.txt","w");
        fp1 = fopen("temp.txt","r");

        while(fread(&s1,sizeof(pengguna),1,fp1)){
            fwrite(&s1,sizeof(pengguna),1,fp);
            printf("\n\nData Berhasil Diupdate, Berikut Data Terbaru: ");
            printf("\nNama Lengkap : %s",s1.nama);
   			printf("\nNomor Handphone : %s",s1.hp);
   			printf("\nEmail : %s",s1.email);
   			printf("\nPassword : %s",s1.password);

			}  
        }
        fclose(fp);
        fclose(fp1);
    }




int kelolaProfile() {
	int i, j, found=0;
    pengguna s1;
    FILE *fp, *fp1;
    char ktp[100];
    printf("#KELOLA AKUN BY PENUMPANG#");
    fflush(stdin);
    printf("\n\nMasukkan Nomor KTP : ");
    scanf("%[^\n]s",ktp);

    fp = fopen("pengguna.txt","r");
    fp1 = fopen("temp.txt","w");
    while(fread(&s1,sizeof(pengguna),1,fp)){
        if(strcmp(s1.ktp,ktp)==0){
        	
            found = 1;
            printf("--Data Pengguna--");
            printf("\nNama Lengkap : %s",s1.nama);
   			printf("\nNomor Handphone : %s",s1.hp);
   			printf("\nEmail : %s",s1.email);
   			printf("\nPassword : %s",s1.password);  
   			
   			printf("\n\n--Ubah Data Pengguna--");
            fflush(stdin);
        	printf("\nNomor KTP : ");
	        fflush(stdin);
	        scanf("%[^\n]s",s1.ktp);
	        fflush(stdin);
	        printf("Nama Lengkap : ");
	        scanf("%[^\n]s",s1.nama);
	        fflush(stdin);
	        printf("Nomor Handphone : ");
	        scanf("%[^\n]s",s1.hp);
	        fflush(stdin);
	        printf("Email : ");
	        scanf("%[^\n]s",s1.email);
	        fflush(stdin);
	        printf("Password : ");
	        scanf("%[^\n]s",s1.password);
	        fflush(stdin);
	        printf("Re-Password : ");
	        scanf("%[^\n]s",s1.repassword);
        } else {
        	printf("\nTidak Ada Nomor KTP dalam sistem, silahkan coba lagi\n");
        	kelolaPengguna();
		}
        fwrite(&s1,sizeof(pengguna),1,fp1);
    }
    fclose(fp);
    fclose(fp1);


    if(found){
        fp = fopen("pengguna.txt","w");
        fp1 = fopen("temp.txt","r");

        while(fread(&s1,sizeof(pengguna),1,fp1)){
            fwrite(&s1,sizeof(pengguna),1,fp);
            printf("\n\nData Berhasil Diupdate, Berikut Data Terbaru: ");
            printf("\nNama Lengkap : %s",s1.nama);
   			printf("\nNomor Handphone : %s",s1.hp);
   			printf("\nEmail : %s",s1.email);
   			printf("\nPassword : %s",s1.password);  
			
			// MENU ADMIN
			system("cls");
			printf("#MENU ADMIN#");
			int i, j, found=0;
		    pengguna s1;
		    FILE *fp;
		
		    
			printf("\nWelcome, admin");
			printf("\n\n1. Kelola Akun");
			printf("\n2. Kelola Kota");
			printf("\n3. Kelola Rute");
			printf("\n4. Lihat Pemasukan");
			printf("\n5. Lihat Jadwal Kereta Api");
			printf("\n0. Logout");
			printf("\n\nPilihan : ");
			
			int choice;
			fflush(stdin);
			scanf("%d",&choice);
			
			switch(choice) {
				case 1:
					system("cls");
					kelolaPengguna();
					break;
				case 2: 
					system("cls");
					kelolaKota();
					break;
				case 3:
					
					break;
				default:
					
					break;
			}  
        }
        fclose(fp);
        fclose(fp1);
    }
}



int menuPengguna() {
	system("cls");
	printf("#MENU PENGGUNA#");
	int i, j, found=0;
    pengguna s1;
    FILE *fp;

    fp = fopen("pengguna.txt","r");
    while(fread(&s1,sizeof(pengguna),1,fp)){
		printf("\nWelcome, %s",s1.nama);
		printf("\n\n1. Booking Tiket");
		printf("\n2. Kelola Profile");
		printf("\n3. History Pembelian");
		printf("\n0. Logout");
		printf("\n\nPilihan : ");
		
		int choice;
		fflush(stdin);
		scanf("%d",&choice);
		
		switch(choice) {
			case 1:
				
				break;
			case 2: 
				kelolaProfile();
				break;
			case 3:
				
				break;
			default:
				
				break;
		}
		
    }
}



int menuAdmin() {
	system("cls");
	printf("\n#MENU ADMIN#");
	int i, j, found=0;
    pengguna s1;
    FILE *fp;
    
	printf("\nWelcome, admin");
	printf("\n\n1. Kelola Akun");
	printf("\n2. Kelola Kota");
	printf("\n3. Kelola Rute");
	printf("\n4. Lihat Pemasukan");
	printf("\n5. Lihat Jadwal Kereta Api");
	printf("\n0. Logout");
	printf("\n\nPilihan : ");
	
	int choice;
	fflush(stdin);
	scanf("%d",&choice);
	
	switch(choice) {
		case 1:
			system("cls");
			kelolaPengguna();
			break;
		case 2: 
			system("cls");
			kelolaKota();
			break;
		case 3:
			system("cls");
			kelolaRute();
			break;
			
		default:
			
			break;
	}
}



int login(){
    int i, j, found=0;
    pengguna s1;
    pengguna *s;
    FILE *fp;
    char email[100];
    char password[100];
    fflush(stdin);
    printf("Email : ");
    scanf("%[^\n]s",email);
    fflush(stdin);
    printf("Password : ");
    scanf("%[^\n]s",password);

    fp = fopen("pengguna.txt","r");
    while(fread(&s1,sizeof(pengguna),1,fp)){
        if(strcmp(s1.email,email)==0){
            if (strcmp(s1.password,password)==0) {
       			menuPengguna();
				found = 1;
			}
        } else if (strcmp(email,"admin123")==0) {
        	if (strcmp(password,"admin123")==0) {
        		menuAdmin();
			}
		}
    }
    if(!found)
        printf("\nAkun tidak terdaftar.....\n");
    else 
		printf("\nAnda berhasil login!");	
    fclose(fp);
}



int daftar(){
        pengguna *s;
        FILE *fp;
        int n,i,j;

        s = (pengguna*)malloc(100*sizeof(pengguna));
        fp = fopen("pengguna.txt","w+");

        for(i=0;i<1;i++){
        	fflush(stdin);
            printf("Nomor KTP : ");
            scanf("%[^\n]s",s[i].ktp);
            fflush(stdin);
            printf("Nama Lengkap : ");
            scanf("%[^\n]s",s[i].nama);
            fflush(stdin);
            printf("Nomor Handphone : ");
            scanf("%[^\n]s",s[i].hp);
            fflush(stdin);
            printf("Email : ");
            scanf("%[^\n]s",s[i].email);
            fflush(stdin);
            printf("Password : ");
            scanf("%[^\n]s",s[i].password);
            fflush(stdin);
            printf("Re-Password : ");
            scanf("%[^\n]s",s[i].repassword);

            fwrite(s+i,sizeof(pengguna),1,fp);
        }
    fclose(fp);
}


//
//void update(){
//    int i, j, found=0;
//    pengguna s1;
//    FILE *fp, *fp1;
//    int rno;
//    printf("Enter RollNo to Update : ");
//    scanf("%d",&rno);
//
//    fp = fopen("mystudents1.txt","r");
//    fp1 = fopen("temp.txt","w");
//    while(fread(&s1,sizeof(pengguna),1,fp)){
//        if(s1.rno == rno){
//            found = 1;
//            s1.total=0;
//            s1.per=0;
//            fflush(stdin);
//            printf("Enter New Name : ");
//            scanf("%[^\n]s",s1.name);
//            for(j=0;j<3;j++){
//                printf("Enter New Marks of Sub%d : ",j+1);
//                scanf("%d",&s1.sub[j].mark);
//                s1.total += s1.sub[j].mark;
//            }
//            s1.per = s1.total / 3.0;
//        }
//        fwrite(&s1,sizeof(pengguna),1,fp1);
//    }
//    fclose(fp);
//    fclose(fp1);
//
//
//    if(found){
//            fp = fopen("mystudents1.txt","w");
//            fp1 = fopen("temp.txt","r");
//
//            while(fread(&s1,sizeof(pengguna),1,fp1)){
//                fwrite(&s1,sizeof(pengguna),1,fp);
//            }
//            fclose(fp);
//            fclose(fp1);
//    }
//    else
//        printf("\nNot Found.....\n");
//}



//
//void append(){
//        pengguna *s, s1;
//        FILE *fp;
//        int n,i,j;
//
//        printf("Enter how many students : ");
//        scanf("%d",&n);
//        s = (pengguna*)malloc(1*sizeof(pengguna));
//        fp = fopen("mystudents1.txt","a");
//
//        for(i=0;i<n;i++){
//            s[i].total=0;
//            s[i].per=0;
//            printf("Enter RollNo : ");
//            scanf("%d",&s[i].rno);
//            fflush(stdin);
//            printf("Enter Name : ");
//            scanf("%[^\n]s",s[i].name);
//            for(j=0;j<3;j++){
//                printf("Enter Marks of Sub%d : ",j+1);
//                scanf("%d",&s[i].sub[j].mark);
//                s[i].total += s[i].sub[j].mark;
//            }
//            s[i].per = s[i].total / 3.0;
//
//            fwrite(s+i,sizeof(pengguna),1,fp);
//        }
//    fclose(fp);
//}


//void delete_rec(){
//    int i, j, found=0;
//    pengguna s1;
//    FILE *fp, *fp1;
//    int rno;
//    printf("Enter RollNo to Delete : ");
//    scanf("%d",&rno);
//
//    fp = fopen("mystudents1.txt","r");
//    fp1 = fopen("temp.txt","w");
//    while(fread(&s1,sizeof(pengguna),1,fp)){
//        if(s1.rno == rno){
//            found = 1;
//        }
//        else
//            fwrite(&s1,sizeof(pengguna),1,fp1);
//    }
//    fclose(fp);
//    fclose(fp1);
//
//
//    if(found){
//            fp = fopen("mystudents1.txt","w");
//            fp1 = fopen("temp.txt","r");
//
//            while(fread(&s1,sizeof(pengguna),1,fp1)){
//                fwrite(&s1,sizeof(pengguna),1,fp);
//            }
//            fclose(fp);
//            fclose(fp1);
//    }
//    else
//        printf("\nNot Found.....\n");
//}


//void count(){
//        pengguna s1;
//        FILE *fp;
//        fp = fopen("mystudents1.txt","r");
//        fseek(fp,0,SEEK_END);
//        int n = ftell(fp)/sizeof(pengguna);
//        printf("\nNo of Records = %d\n",n);
//        fclose(fp);
//}

//void display(){
//        pengguna s1;
//        FILE *fp;
//        int j;
//        fp = fopen("mystudents1.txt","r");
//        while(fread(&s1,sizeof(pengguna),1,fp))
//        {
//            printf("\n%-5d%-20s",s1.rno,s1.name);
//            for(j=0;j<3;j++){
//                printf("%4d",s1.sub[j].mark);
//            }
//            printf("%5d%7.2f",s1.total,s1.per);
//        }
//        fclose(fp);
//}

//void sort_on_screen(){
//        pengguna *s, s1;
//        FILE *fp;
//        fp = fopen("mystudents1.txt","r");
//        fseek(fp,0,SEEK_END);
//        int n = ftell(fp)/sizeof(pengguna);
//        int i,j;
//        rewind(fp);
//        s = (pengguna*)calloc(n,sizeof(pengguna));
//        for(i=0;i<n;i++)
//            fread(&s[i],sizeof(pengguna),1,fp);
//
//        for(i=0;i<n;i++){
//            for(j=i+1;j<n;j++){
//                if(s[i].total<s[j].total){
//                    s1 = s[i];
//                    s[i] = s[j];
//                    s[j] = s1;
//                }
//            }
//        }
//
//
//        for(i=0;i<n;i++){
//            printf("\n%-5d%-20s",s[i].rno,s[i].name);
//            for(j=0;j<3;j++){
//                printf("%4d",s[i].sub[j].mark);
//            }
//            printf("%5d%7.2f",s[i].total,s[i].per);
//        }
//        fclose(fp);
//}

//void sort_in_file(){
//
//        pengguna *s, s1;
//        FILE *fp;
//        fp = fopen("mystudents1.txt","r");
//        fseek(fp,0,SEEK_END);
//        int n = ftell(fp)/sizeof(pengguna);
//        int i,j;
//        rewind(fp);
//        s = (pengguna*)calloc(n,sizeof(pengguna));
//        for(i=0;i<n;i++)
//            fread(&s[i],sizeof(pengguna),1,fp);
//
//        fclose(fp);
//        for(i=0;i<n;i++){
//            for(j=i+1;j<n;j++){
//                if(s[i].total<s[j].total){
//                    s1 = s[i];
//                    s[i] = s[j];
//                    s[j] = s1;
//                }
//            }
//        }
//        for(i=0;i<n;i++){
//            printf("\n%-5d%-20s",s[i].rno,s[i].name);
//            for(j=0;j<3;j++){
//                printf("%4d",s[i].sub[j].mark);
//            }
//            printf("%5d%7.2f",s[i].total,s[i].per);
//        }
//
//        fp = fopen("mystudents1.txt","w");
//
//        for(i=0;i<n;i++){
//            fwrite(&s[i],sizeof(pengguna),1,fp);
//        }
//
//        fclose(fp);
//}

//void sort_by_name(){
//        pengguna *s, s1;
//        FILE *fp;
//        fp = fopen("mystudents1.txt","r");
//        fseek(fp,0,SEEK_END);
//        int n = ftell(fp)/sizeof(pengguna);
//        int i,j;
//        rewind(fp);
//        s = (pengguna*)calloc(1,sizeof(pengguna));
//        for(i=0;i<n;i++)
//            fread(&s[i],sizeof(pengguna),1,fp);
//
//        for(i=0;i<n;i++){
//            for(j=i+1;j<n;j++){
//                if(strcmp(s[i].name,s[j].name)>0){
//                    s1 = s[i];
//                    s[i] = s[j];
//                    s[j] = s1;
//                }
//            }
//        }
//        for(i=0;i<n;i++){
//            printf("\n%-5d%-20s",s[i].rno,s[i].name);
//            for(j=0;j<3;j++){
//                printf("%4d",s[i].sub[j].mark);
//            }
//            printf("%5d%7.2f",s[i].total,s[i].per);
//        }
//        fclose(fp);
//}







int main(){
    int ch;
   
    do{
    	printf("SELAMAT DATANG");
        printf("\n1.Login");
        printf("\n2.Register");
//        printf("\n3.DISPLAY");
//        printf("\n4.NO OF RECORDS");
//        printf("\n5.SEARCH");
//        printf("\n6.UPDATE");
//        printf("\n7.DELETE");
//        printf("\n8.SORT IN FILE BY TOTAL DESC");
//        printf("\n9.SORT ON SCREEN BY TOTAL DESC");
//        printf("\n10.SORT ON SCREEN BY NAME");
        printf("\n0.EXIT");
        printf("\nMasukan Pilihan Anda : ");
        scanf("%d",&ch);
        switch(ch){
        case 1:
                login();
            break;
        case 2: 
                daftar();
            break;
//        case 3:
//                display();
//            break;
//        case 4:
//                count();
//        break;
//        case 5:
//                search();
//        break;
//        case 6:
//                update();
//            break;
//            case 7:
//                delete_rec();
//            break;
//            case 8:
//                sort_in_file();
//                break;
//            case 9:
//                sort_on_screen();
//            break;
//            case 10:
//                sort_by_name();
//            break;

            
        }
    }while(ch!=0);

    return 0;
}
