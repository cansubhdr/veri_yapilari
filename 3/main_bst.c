#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct bst{
	int data;
	struct bst *sol;
	struct bst *sag;
};

typedef struct bst node;

node * ekle (node *agac,int x){
	if(agac == NULL){
		node *root= (node *)malloc(sizeof(node));
		root -> sol = NULL;
		root -> sag = NULL;
		root -> data = x;
		return root;
	}
	
	if(agac->data < x){
		agac->sag = ekle(agac->sag,x);
		return agac;
	}
	else { 
	agac->sol = ekle (agac->sol,x);
	return agac;}
}

void dolas(node *agac){
	if(agac == NULL)
		return;
	printf("%d ",agac->data);
	dolas(agac->sag);        
	dolas(agac->sol);
}

int main(int argc, char *argv[]) {
	time_t start, end;
	time(&start);
	
	node * agac=NULL;
	
	for(int i=1; i<10001;i++){
		agac=ekle(agac,i);	
	}
	dolas(agac);
	
	time(&end);
	printf("\nIslem suresi %f",difftime(end,start));
	
	return 0;
}


