#include<stdio.h>
#include<stdlib.h>
#include<curses.h>
#include<string.h>
#define N 10000

typedef struct hash{
    int val;
    struct hash *next;
}node;

int hashing(int val){
    int mod = val%N;
    if (mod < 0){
        mod += N;
    }
    return mod;
}

bool isPresent(int key, node *values[N]){
    int modul = hashing(key);
    if (values[modul] == NULL){
        return false;
    }
    node *ptr = values[modul];
    while (ptr != NULL){
        if (ptr->val == key){
            return true;
        }
        ptr = ptr->next;
    }
    return false;
}

int insert(int key, node *values[N], int colcnt){
    if (isPresent(key, values)){
        colcnt++;
        return colcnt;
    }
    int modul = hashing(key);
    node *ptr = values[modul];
    if (ptr == NULL){
        node *temp;
        temp = malloc(sizeof(*temp));
        temp->val = key;
        temp->next = NULL;
        values[modul] = temp;
        return colcnt;
    }
    while (ptr->next != NULL){
        ptr = ptr->next;
    }
    node *temp;
    temp = malloc(sizeof(*temp));
    temp->val = key;
    temp->next = NULL;
    ptr->next = temp;
    colcnt++;
    return colcnt;
}

int search(int key, node *values[N], int searchcnt){
    if (isPresent(key, values)){
        searchcnt++;
    }
    return searchcnt;
}
int main(int argc, char** argv){
    node *values[N] = {NULL};
    int colcnt = 0;
    int searchcnt = 0;
    if (argc < 2) {
		printf("error\n");
		return 0;
	}
    FILE *fp = fopen(argv[1], "r");
    char c;
    int i;
    int r = fscanf(fp, "%c\t%d\n", &c, &i);
    while(r != EOF){
        if (c == 'i'){
            //printf("%c\n", c);
            colcnt = insert(i, values, colcnt);
        }else if (c == 's'){
            //printf("%c\n", c);
            searchcnt = search(i, values, searchcnt);
        }
        r = fscanf(fp, "%c\t%d\n", &c, &i);
    }
    fclose(fp);
    printf("%d\n", colcnt);
    printf("%d", searchcnt);
    /*
    int colcnt = 0;
    int searchcnt = 0;
    colcnt = insert(10, values, colcnt);
    colcnt = insert(12, values, colcnt);
    searchcnt = search(10, values, searchcnt);
    colcnt = insert(10010, values, colcnt);
    searchcnt = search(5, values, searchcnt);
    searchcnt = search(10010, values, searchcnt);
    printf("%d", colcnt);
    printf("\n");
    printf("%d", searchcnt);
    */
    return 0;
}