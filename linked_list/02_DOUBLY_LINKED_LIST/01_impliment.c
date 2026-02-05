#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *next;
    struct node *prev;
} node;
node *HP;
node* getnode(int x){
    node *ptr = (node *)malloc(sizeof(node));
    ptr->data = x;
    ptr->next = NULL;
    ptr->prev = NULL;
    return ptr;
}
node* Build(){
    node *temp1, *temp2, *temp3;
    temp1 = getnode(1);
    temp2 = getnode(2);
    temp3 = getnode(3);
    temp1->next = temp2;
    temp2->next = temp3;
    temp3->prev = temp2;
    temp2->prev = temp1;
    return temp1;
}
void print1(){
    node *s = HP;
    printf("Linked List Data :\n");
    while(s!=NULL){
        printf("%d\t", s->data);
        s = s->next;
    }
    printf("\n");
}
void print2(){
    node *s = HP;
    while(s->next!=NULL){
        s = s->next;
    }
    printf("Linked List Data in Reverse Order : \n");
    while(s!=NULL){
        printf("%d\t", s->data);
        s = s->prev;
    }
    printf("\n");
}
void freelist(node* s){
    node *temp;
    while(s!=NULL){
        temp = s;
        s = s->next;
        free(temp);
    }
}
int main(){
    HP = Build();
    print1();
    print2();
    freelist(HP);
    print1();
    return 0;
}