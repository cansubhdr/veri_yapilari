#include <stdio.h>
#include <stdlib.h>
#define BOYUT 5

int kuyruk[BOYUT], front = -1, rear = -1;


void islem_yaz(int veri)
{
	if(rear == 	BOYUT)
	{
		printf("\nkuyruk dolu");
	}
	else
	{
		if(front == -1)
			front = 0;
		rear = rear + 1;
		kuyruk[rear] = veri;
	}
}

void islem_sil(){
	if(front == -1 || front > rear)
	{
		printf("\nkuyruk bos");
		front = -1;
		rear= -1;
	}
	else{
		front = front + 1;
	}
}


int main() {
	int sayi1, sayi2, sayi3;
	char islem1,islem2;
	int sonuc1, tam_sonuc;
	
	printf("[sayi1 () sayi2 () sayi] olucak sekilde islem yaziniz. NOT: parantez iclerine yapmak istediginiz islemi yazin..");
	
	printf("\nsayi1'i girin..\n");
	scanf("%d",&sayi1);

	printf("\nsayi2'yi girin..\n");
	scanf("%d",&sayi2);

	printf("\nsayi3'u girin..\n");
	scanf("%d",&sayi3);
	
	islem_yaz(sayi1);
	islem_yaz(sayi2);
	islem_yaz(sayi3);
	
	printf("yapmak istediginiz islemi girin..");
	scanf("%s",&islem1);
	
	switch(islem1)
	{
		case '+':
			sonuc1 = kuyruk[0] + kuyruk[1];
			printf("%d\n",sonuc1);
			
			printf("islem2 yi girin..");
			scanf("%s",&islem2);
			
				switch(islem2)
				{
					case '+':
					    tam_sonuc = sonuc1 + kuyruk[2];
					    printf("%d\n",tam_sonuc);
					    break;
			
					case '-':
					    tam_sonuc = sonuc1 - kuyruk[2];
					    printf("%d\n",tam_sonuc);
					    break;
					
					case '*':
					    tam_sonuc = sonuc1 * kuyruk[2];;
					    printf("%d\n",tam_sonuc);
					    break;
					
					case '/':
					    tam_sonuc = sonuc1 / kuyruk[2];
					    printf("%d\n",tam_sonuc);
					    break;
			
				}
			
			   break;
		case '-':
			sonuc1 = kuyruk[0] - kuyruk[1];
			printf("%d\n",sonuc1);
			printf("islem2 yi girin..");
			scanf("%s",&islem2);
			
				switch(islem2)
				{
					case '+':
					    tam_sonuc = sonuc1 + kuyruk[2];
					    printf("%d",tam_sonuc);
					    break;
			
					case '-':
					    tam_sonuc = sonuc1 - kuyruk[2];
					    printf("%d",tam_sonuc);
					    break;
					
					case '*':
					    tam_sonuc = sonuc1 * kuyruk[2];;
					    printf("%d",tam_sonuc);
					    break;
					
					case '/':
					    tam_sonuc = sonuc1 / kuyruk[2];
					    printf("%d",tam_sonuc);
					    break;
			
					}
			break;
		case '*':
			sonuc1 = kuyruk[0] * kuyruk[1];
			printf("%d\n",sonuc1);
			printf("islem2 yi girin..");
			scanf("%s",&islem2);
			
				switch(islem2)
				{
					case '+':
					    tam_sonuc = sonuc1 + kuyruk[2];
					    printf("%d",tam_sonuc);
					    break;
			
					case '-':
					    tam_sonuc = sonuc1 - kuyruk[2];
					    printf("%d",tam_sonuc);
					    break;
					
					case '*':
					    tam_sonuc = sonuc1 * kuyruk[2];;
					    printf("%d",tam_sonuc);
					    break;
					
					case '/':
					    tam_sonuc = sonuc1 / kuyruk[2];
					    printf("%d",tam_sonuc);
					    break;
			
					}
			break;
		case '/':
			sonuc1 = kuyruk[0] / kuyruk[1];
			printf("%d\n",sonuc1);
			printf("islem2 yi girin..");
			scanf("%s",&islem2);
			
				switch(islem2)
				{
					case '+':
    					tam_sonuc = sonuc1 + kuyruk[2];
    					printf("%d",tam_sonuc);
    					break;
			
					case '-':
    					tam_sonuc = sonuc1 - kuyruk[2];
    					printf("%d",tam_sonuc);
    					break;
					
					case '*':
    					tam_sonuc = sonuc1 * kuyruk[2];;
    					printf("%d",tam_sonuc);
    					break;
					
					case '/':
    					tam_sonuc = sonuc1 / kuyruk[2];
    					printf("%d",tam_sonuc);
    					break;
			
					}
			break;
	}

	return 0;
}
