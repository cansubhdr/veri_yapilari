#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Node
{
    int data;
    struct Node *sol;
    struct Node *sag;
    int height;
};

int height(struct Node *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}

int max(int a, int b)
{
    return (a > b)? a : b;
}

struct Node* new_Node(int data)
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data   = data;
    node->sol   = NULL;
    node->sag  = NULL;
    node->height = 1;  
    return(node);
}

struct Node *saga_Dondurme(struct Node *y)
{
    struct Node *x = y->sol;
    struct Node *T2 = x->sag;
    x->sag = y;
    y->sol = T2;
    
    y->height = max(height(y->sol),height(y->sag)) + 1;
    x->height = max(height(x->sol),height(x->sag)) + 1;
 
    return x;
}
 
struct Node *sola_Dondurme(struct Node *x)
{
    struct Node *y = x->sag;
    struct Node *T2 = y->sol;
    y->sol = x;
    x->sag = T2;
 
    x->height = max(height(x->sol),height(x->sag)) + 1;
    y->height = max(height(y->sol),height(y->sag)) + 1;
 
    return y;
}

int getBalance(struct Node *N)
{
    if (N == NULL)
        return 0;
    return height(N->sol) - height(N->sag);
}

struct Node* insert(struct Node* node, int data)
{
    if (node == NULL)
        return(new_Node(data));
 
    if (data < node->data)
        node->sol  = insert(node->sol, data);
    else if (data > node->data)
        node->sag = insert(node->sag, data);
    else 
        return node;
        
        
	node->height = 1 + max(height(node->sol),height(node->sag));
	
 	int balance = getBalance(node);
 
	if (balance > 1 && data < node->sol->data)
        return saga_Dondurme(node);
 
	if (balance < -1 && data > node->sag->data)
        return sola_Dondurme(node);
 
	if (balance > 1 && data > node->sol->data)
    {
		node->sol =  sola_Dondurme(node->sol);
        return saga_Dondurme(node);
    }
 
 	if (balance < -1 && data < node->sag->data)
    {
        node->sag = saga_Dondurme(node->sag);
        return sola_Dondurme(node);
    }
 
    return node;
}

void preOrder(struct Node *root)
{
    if(root != NULL)
    {
        printf("%d ", root->data);
        preOrder(root->sol);
        preOrder(root->sag);
    }
}

int main() {
	time_t start, end;
	time(&start);
	
	struct Node *root = NULL;
	
	for(long i =1; i<100001; i++){
		root = insert(root,i);
	}
	
	preOrder(root);	
	time(&end);
	printf("\nIslem suresi %f",difftime(end,start));
	
	
	return 0;
}








