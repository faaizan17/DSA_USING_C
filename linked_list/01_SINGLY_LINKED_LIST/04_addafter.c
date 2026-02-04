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
    printf("LINKED LIST DATA : \n");
    while(s!=NULL){
        printf("%d\t", s->data);
        s = s->next;
    }
    printf("\n");
}
void addxaftery(int x,int y,node* s){
    node *ptr = getnode(x);
    if(s==NULL){
        return;
    }
    while(s->next!=NULL && s->data!=y){
        s = s->next;
    }
    if(s->data==y){
        ptr->next = s->next;
        s->next = ptr;
    }else{
        printf("%d is not found\n", y);
        free(ptr);
    }
}
int main(){
    HP = Build123();
    print(HP);
    addxaftery(9, 4, HP);
    print(HP);
    return 0;
}