#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
    struct node *prev;
} node;

node *HP = NULL;  // Head pointer
node *temp = NULL; // Tail pointer

void link(node *s){
    if(HP == NULL){   // First node
        HP = s;
        temp = s;
    } else {          // Append at end
        temp->next = s;
        s->prev = temp;
        temp = s;
    }
}

void getnode(int x){
    node *ptr = (node *)malloc(sizeof(node));
    if(ptr == NULL){
        printf("Memory allocation failed!\n");
        exit(1);
    }
    ptr->data = x;
    ptr->next = NULL;
    ptr->prev = NULL;
    link(ptr);
}

void print(){
    node *s = HP;
    printf("\nData:\n");
    while(s != NULL){
        printf("%d\t", s->data);
        s = s->next;
    }
    printf("\n");
}

void print2(){
    node *s = HP;
    while(s->next != NULL){
        s = s->next;
    }
    printf("Linked List Data in Reverse Order:\n");
    while(s != NULL){
        printf("%d\t", s->data);
        s = s->prev;
    }
    printf("\n");
}

void freelist(node* s){
    node *temp;
    while(s != NULL){
        temp = s;
        s = s->next;
        free(temp);
    }
}

int main(){
    int num, n;
    printf("Enter Number of elements to be stored: ");
    scanf("%d", &n);

    for(int i = 1; i <= n; i++){
        printf("Enter Number%d to be stored: ", i);
        scanf("%d", &num);
        getnode(num);
    }

    print();
    print2();

    freelist(HP);

    return 0;
}
