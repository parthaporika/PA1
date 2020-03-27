#include<stdio.h>
#include<stdlib.h>
#include<curses.h>
#include<string.h>
#define MAX_SIZE 20

void swap(int* a, int* b){ 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 

void sort(int arr[], int size){
    int x = -1;
    for (int y = 0; y < size; y++){
        if (arr[y] % 2 == 0){
            x++;
            swap(&arr[y], &arr[x]);
        }
    }
    int i = 0;
    while (arr[i]%2 == 0){
        i++;
    }
    int a, j, min_idx;  
  
    for (a = 0; a < i-1; a++)  
    {  
        min_idx = a;  
        for (j = a+1; j < i; j++)  
        if (arr[j] < arr[min_idx])  
            min_idx = j;  
  
        swap(&arr[min_idx], &arr[a]);  
    }
    int b, c, max_idx;  
  
    for (b = i; b < size-1; b++)  
    {  
        max_idx = b;  
        for (c = b+1; c < size; c++)  
        if (arr[c] > arr[max_idx])  
            max_idx = c;  
  
        swap(&arr[max_idx], &arr[b]);  
    } 
} 

int main(int argc, char** argv){
    /*
    int arr[] = {25, 10, 1, 99, 4, 2}; 
    int arr_size = sizeof(arr)/sizeof(arr[0]); 
    int i = 0;
    */
    if (argc < 2) {
		printf("error\n");
		return 0;
	}
    int arr_size;
    FILE *fp = fopen(argv[1], "r");
    fscanf(fp,"%d\n", &arr_size);
    int arr[arr_size];
    for (int i = 0; i < arr_size; i++){
        fscanf(fp, "%d", &arr[i]);
    }
    fclose(fp);
  
    sort(arr, arr_size); 
    int j = 0;
    for (j = 0; j < arr_size-1; j++) 
        printf("%d\t", arr[j]); 
    printf("%d", arr[j]);
    return 0;
}