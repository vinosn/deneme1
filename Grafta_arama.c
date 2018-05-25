#include <stdio.h>
#include <time.h>
#include <stdlib.h>


int labirent_olusturma(int size){

	int lab_size, lab_wall;                    // labirent boyutu ve labirent duvar
	int temp, i, j;                           // indexler ve kullanılacak degiskenler.
	int labirent[30][30];
	int tablo[20][20];
	int input1;
	int input2; 

	size = lab_size; 			 			

	printf("Labirentin boyutu kaca kac olsun:");
	scanf("%d",&lab_size);

	for (i = 0; i < lab_size; i++)                    // buradaki ic ice for islemi labirentin random bir sekilde olusturuyor
	{
		for (j = 0; j < lab_size; j++)
		{
			temp = rand() % 2;						// random fonksiyon ile olusturan degerleri temp degiskenine atıyor.

			tablo[i][j] = temp; 					// burada random ile olusturan butun islemler tablo matris'e atıyor. 

			printf("%d",temp);						// Random ile olusturan butun degerleri ekranda gostermek icin.
		}
		printf("\n");
	}

	tablo[0][0] = 0;

	printf("Labirent Random bir sekilde olusturuldu.\n");

	lab_wall = ( 2 * lab_size ) + 1;

	for ( i = 0; i < lab_wall; i++)
	{
		for ( j = 0; j < lab_wall; j++)
		{
			if ( ( i % 2 == 0 ) && ( j % 2 == 0 ) )
			{
				labirent[i][j] = 6;
			}
			else{

				labirent[i][j] = 0;
			}
		}
	}

	// labirentin duvari olusturmak icin 
	for ( i = 0; i < lab_wall; i++)
	{
		if ( i % 2 == 0 ){

			labirent[i][0] 			= 6;
			labirent[0][i] 			= 6;
			labirent[i][lab_wall-1] = 6;
			labirent[lab_wall-1][i] = 6;
		}
		else {

			labirent[i][0] 			= 5;
			labirent[0][i] 			= 4;
			labirent[i][lab_wall-1] = 5;
			labirent[lab_wall-1][i] = 4;

			}
		}

		labirent[1][1] = 1;                              // labirent(1,1) noktasi (*) koymak icin kullanildi.
	
		for ( i = 0; i < lab_size; i++)
		{
			for ( j = 0; j < lab_size; j++)
			{
				if (tablo[i][j] == 1){

				labirent[ (2*i)+1 ][ (2*j)+2 ]  = 5;
				labirent[ (2*i)+1 ][ (2*j) ]    = 5;
				labirent[ (2*i)+2 ][ (2*j)+1 ]  = 4;
				labirent[ (2*i) ][ (2*j)+1 ]    = 4;

				}
			}
		}

		// labirentin duvarları olusturacaktir.
		for ( i = 0; i < lab_wall; i++)
		{
			for ( j = 0; j < lab_wall; j++)
			{
				switch(labirent[i][j]){

				case 0:
					printf(" ");
					break;
				case 1:
					printf("*"); 
					break;
				case 2:
					printf("I");
					break;
				case 3:
					printf("X");
					break;
				case 4:
					printf("-");
					break;
				case 5:
					printf("|");
					break;
				case 6:
					printf("+");
					break;
				}
			}
			printf("\n");
		}


			// buradaki islemler labirentte cikis yolunu eklemek icindir.

	printf("Cikis yolunu eklemek icin lutfen labirentin hanigi gozunde olacagi icin indexlerini giriniz\n\n");

	printf("(i) indexi giriniz:");
	scanf("%d",&input1);

	printf("(j) indexi giriniz:");
	scanf("%d",&input2);

	labirent[(2*input1)][(2*input2)] = 3; // cikis yolu eklemek icin 3 kullanildi, buradaki 3 'te  asagadaki case 3'e gitmek icin  
	//i = input1;
	//j = input2;

	for ( i = 0; i < lab_wall; i++)
	{
		for ( j = 0; j < lab_wall; j++)
		{
			switch(labirent[i][j]){

				case 0:
					printf(" ");
					break;
				case 1:
					printf("*");
					break;
				case 2:
					printf("I");
					break;
				case 3:
					printf("X"); // cikis yolu 
					break;
				case 4:
					printf("-");
					break;
				case 5:
					printf("|");
					break;
				case 6:
					printf("+");
					break;
				}
		}
		printf("\n");
	}
	

	
		return lab_size;
}

/*int duvar( int labirent[50][50]){

	int lab_wall;
	int i,j;

	for ( i = 0; i < lab_wall; i++)
	{
		for ( j = 0; j < lab_wall; j++)
		{
			switch(labirent[i][j]){

				case 0:
					printf(" ");
					break;
				case 1:
					printf("*");
					break;
				case 2:
					printf("I");
					break;
				case 3:
					printf("X");
					break;
				case 4:
					printf("-");
					break;
				case 5:
					printf("|");
					break;
				case 6:
					printf("+");
					break;
				}
		}
		printf("\n");
	}
	
}*/



int main(int argc, char const *argv[])
{
	
	int size,input1,input2;
	int secim;

	while (1 == 1){
	printf(">>>>>>>>>>>>>>>>>>>PROGRAMIN MENUSU<<<<<<<<<<<<<<<<<<<\n\n");


	printf("1. Labirenti olustur ve cikis yolu ekleme\n");
	printf("2. Labirentte cikis nokatasi ekleme\n");
	printf("3. Labirenti cikis noktasiyle gosterme\n");
	printf("4. Cikis noktasina gitme\n");
	printf("5. Cikmak icin 5'i tuslayiniz\n\n");

	printf("Lutfen menu'den bir islem seciniz:\n");
	scanf("%d",&secim);


	switch (secim){

		case 1:
			printf("Labirent olusturma:\n");
			labirent_olusturma(size);
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			exit(0);
			break;	
		default:
		printf("Yanlis tus tikladiniz.\n");

	}

	
	
	}
	return 0;
}