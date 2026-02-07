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
}
void build(){
    node *temp1, *temp2, *temp3;
    temp1 = getnode(1);
    temp2 = getnode(2);
    temp3 = getnode(3);
    HP = temp1;
    temp1->next = temp2;
    temp2->next = temp3;
    temp3->prev = temp2;
    temp2->prev = temp1;
}
void print(){
    node *s = HP;
    printf("linked list data :\n");
    while(s!=NULL){
        printf("%d\t", s->data);
        s = s->next;
    }
    printf("\n");
}
void addXafterY(int x,int y){
    node *ptr = getnode(x);
    if(HP==NULL){
        HP = ptr;
        return;
    }
    node *s = HP;
    while(s->next!=NULL&&s->data!=y){
        s = s->next;
    }
    if(s->next==NULL&&s->data==y){
        s->next = ptr;
        ptr->prev = s;
    }else if(s->data==y){
        ptr->prev = s;
        ptr->next = s->next;
        s->next->prev = ptr;
        s->next = ptr;
    }else{
        printf("not found!!!!");
        free(ptr);
    }
}
void freelist(){
    node *s = HP;
    node *temp = NULL;
    while(s!=NULL){
        temp = s;
        s = s->next;
        free(temp);
    }
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
int main(){
    build();
    print();
    addXafterY(17, 3);
    print();
    print2();
    freelist();
}