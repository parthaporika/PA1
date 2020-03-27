#include<stdio.h>
#include<stdlib.h>
#include<curses.h>
#include<string.h>

typedef struct BST{
    int val;
    struct BST *left;
    struct BST *right;
}node;

node* newNode(int data) 
{ 
  node* newnode = (node*)malloc(sizeof(node)); 
  newnode->val = data; 
  newnode->left = NULL; 
  newnode->right = NULL; 
  return(newnode); 
} 

node* addBST(int *values, int beg, int end){
    if (beg > end){
        return NULL;
    }
    int mid = (beg+end)/2;
    node *root = newNode(values[mid]);
    root->left = addBST(values, beg, mid-1);
    root->right = addBST(values, mid+1, end);
    return root;
}

int removeDup(int *values, int size, int *arr){
    //bool exists = false;
    arr[0] = values[0];
    int j = 1;
    for (int i = 1; i < size; i++){
        if (values[i] != values[i-1]){
            arr[j] = values[i];
            j++;
        }
    }
    return j;
}

void inorder(node *root){
    if (root == NULL){
        return;
    }
    inorder(root->left);
    printf("%d\t", root->val);
    inorder(root->right);
}

void swap(int* a, int* b){ 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 

int main(int argc, char** argv){
    /*
    int input[7] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(input) / sizeof(input[0]);
    node *root = addBST(input, 0, n-1);
    inorder(root);
    */
    
    if (argc < 2) {
		printf("error\n");
		return 0;
	}
    //printf("Before Everything");
    FILE *fp = fopen(argv[1], "r");
    //int input[10];
    char c;
    int x = 0;
    int i;
    int r = fscanf(fp, "%c\t%d\n", &c, &i);
    while(r != EOF){
        if (c == 'i'){
            x++;
        }
        r = fscanf(fp, "%c\t%d\n", &c, &i);
    }
    fclose(fp);
    int input[x];
    FILE *fptr = fopen(argv[1], "r");
    char a;
    int y = 0;
    int n;
    int u = fscanf(fptr, "%c\t%d\n", &a, &n);
    while(u != EOF){
        if (a == 'i'){
            input[y] = n;
            y++;
        }
        u = fscanf(fptr, "%c\t%d\n", &a, &n);
    }
    fclose(fptr);
    int b, min_idx, j;
    for (b = 0; b < x-1; b++){  
        min_idx = b;  
        for (j = b+1; j < x; j++)  
        if (input[j] < input[min_idx])  
            min_idx = j;  
  
        swap(&input[min_idx], &input[b]);  
    }
    int arrem[x];
    int rsize = removeDup(input, x, arrem);
    node *root = addBST(arrem, 0, rsize-1);
    inorder(root);
    return 0;
}