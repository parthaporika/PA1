#include<stdio.h>
#include<stdlib.h>
#include<curses.h>
#include<string.h>

typedef struct list{
    int val;
    struct list *next;
}node;

void create_node(node **head, int addval){
    node *temp;
    temp = malloc(sizeof(*temp));
    temp->val = addval;
    if ((*head) == NULL){
        *head = temp;
        (*head)->next = NULL;
    }else{
        node *ptr = *head;
        node *prev = *head;
        while(ptr->next != NULL && temp->val > ptr->val){
            prev = ptr;
            ptr = ptr->next;
        }if (temp->val <= (*head)->val){
            temp->next = *head;
            *head = temp;
        }else if (ptr->next == NULL && ptr->val < temp->val){
            ptr->next = temp;
            temp->next = NULL;
        }else{
            prev->next = temp;
            temp->next = ptr;
        }
    }
}

void delete(node **head, int delval){
    if ((*head) == NULL){
        return;
    }
    if((*head)->val == delval){
        node* temp = *head; 
        *head = (*head)->next;
        free(temp);
        return;
    }
    node *ptr = *head;
    node *prev = *head;
    while (ptr->next != NULL && ptr->val != delval){
        prev = ptr;
        ptr = ptr->next;
    }
    if(ptr->next == NULL && ptr->val == delval){
        prev->next = NULL;
        free(ptr);
    }else if (ptr->val == delval){
        prev->next = ptr->next;
        free(ptr);
    }
}

void printoutput(node *head){
    node *ptr = head;
    int count = 0;
    while (ptr != NULL){
        count++;
        ptr = ptr->next;
    }
    if (count == 0){
        printf("%d", 0);
    }else{
        printf("%d\n", count);
        while(head->next != NULL) {
            if (head->val == head->next->val){
                head = head->next;
                continue;
            }
            printf("%d\t", head->val);
            head = head->next;
        } 
        printf("%d", head->val);
    }
}
void print_stacki(node *head){
    while(head != NULL) {
        printf("%d-", head->val);
        head = head->next;
    }
    printf("\n");
}

int main(int argc, char** argv){
    if (argc < 2) {
		printf("error\n");
		return 0;
	}
    node *head = NULL;
    /*
    create_node(&head, 10);
    create_node(&head, 15);
    create_node(&head, 10);
    create_node(&head, 3);
    printoutput(head);
    delete(&head, 15);
    delete(&head, 3);
    printoutput(head);
    */
    FILE *fp = fopen(argv[1], "r");
    char c;
    int i;
    int r = fscanf(fp, "%c\t%d\n", &c, &i);
    while(r != EOF){
        if (c == 'i'){
            create_node(&head, i);
        }else if (c == 'd'){
            delete(&head, i);
        }
        r = fscanf(fp, "%c\t%d\n", &c, &i);
    }
    fclose(fp);
    printoutput(head);
    free(head);
    return 0;
}