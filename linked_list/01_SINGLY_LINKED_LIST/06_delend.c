#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *next;
} node;
node *HP;
node* getnode(int x){
    node *ptr = (node *)malloc(sizeof(node));
    ptr->data = x;
    ptr->next = NULL;
    return ptr;
}
node* Build123(){
    node *temp1, *temp2, *temp3;
    temp1 = getnode(1);
    temp2 = getnode(2);
    temp3 = getnode(3);
    temp1->next = temp2;
    temp2->next = temp3;
    return temp1;
}
void print(node* s){
    printf("linked list data :\n");
    while(s!=NULL){
        printf("%d\t", s->data);
        s = s->next;
    }
}
void delend(node* s){
    if(HP==NULL){
        printf("List is already empty.");
        return;
    }
    if(HP->next!=NULL){
        while(s->next->next!=NULL){
            s = s->next;
        }
        free(s->next);
        s->next = NULL;
    }else{
        HP = NULL;
        free(s);
    }
}
int main(){
    HP = Build123();
    print(HP);
    printf("\n");
    delend(HP);
    print(HP);
    return 0;
}