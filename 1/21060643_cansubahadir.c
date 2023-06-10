#include <stdio.h>
#include <stdlib.h>
#define N 100


int yigin[N];
int us = -1; // -> top
void ekle(int [], int);
void cikar(int []);
void listele(int []);
int bosmu(int []);
int kapasite(int []);
void tepe(int []);

int main() {
	char stack[] = "<html><head><title> BÝL Veri Yapýlarý</title></head><body><p style=""><a href=""> OMÜ </a></p></body></html>";
	int i=0, t=0;
	int lenght_s = strlen(stack);
	char tag_acma[] = "";
	char tag_kapama[] = "";
	
		while(i != lenght_s){
			if(stack[i] == '<' && stack[i+1] != '/'){	
				while(stack[i] != '>' ){
					if(stack[i+1] == '>' ){
						printf("tag kapanmis.. \n");

					}
					else{
					    ekle(yigin, tag_acma[t]);
					    
						tag_acma[t] = stack[i+1];
						printf("%c",tag_acma[t]);
						t++;


					}
					i++;

				}	
			}
			
			i++;


	}
	return 0;
}


void ekle(int dizi[], int eleman){ // -> push
    if(N - 1 == us)
        printf("Yigin doludur! %d eklenemedi\n", eleman);
    else{
        us = us + 1;
        yigin[us] = eleman;
    }
}
void cikar(int dizi[]){ // -> pop
    if(us == -1)
        printf("Yigin bos! Yigindan silinecek eleman yoktur\n");
    else{
        int silindi = dizi[us];
        us = us - 1;
        printf("%d elemani yigindan cikartildi\n", silindi);
    }  
}
void listele(int dizi[]){
    if(us == -1)
        printf("Yigin bos! Listelenecek eleman yoktur\n");
    else{
        int temp = us;
        while(temp != -1){
        	printf("%d ", dizi[temp]);
        	temp = temp - 1;
		}
		printf("\n");
    }
}
int bosmu(int dizi[]){ // -> isEmpty
    return us == -1;
}
int kapasite(int dizi[]){ // -> size veya capacity
    if(us == -1)
        return 0;
    else
        return us + 1;
}
void tepe(int dizi[]){ // -> peek
    if(us == -1)
        printf("Yigin bos!\n");
    else
        printf("Tepedeki eleman: %d\n", dizi[us]);
}
