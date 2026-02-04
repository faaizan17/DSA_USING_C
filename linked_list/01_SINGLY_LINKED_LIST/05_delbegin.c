#include<stdio.h>
#include<stdlib.h>
typedef struct node{                //nickmane of "struct node" = node.
    int data;
    struct node *next;
} node;
node *Build123();
node *getnode(int x);
void print(node *s);
node *HP;               // head pointer
/*Build123 creates a list 1->2->3  and returns adress of first node*/
node* Build123(){
    node *temp1, *temp2, *temp3;
    temp1 = getnode(1);
    temp2 = getnode(2);
    temp3 = getnode(3);
    temp1-> next = temp2;
    temp2 -> next= temp3;
    return temp1;
}
/*getnode creates a node: assigns x to data part and NULL to next part and returns adrress of node*/                      
node* getnode(int x){                       // returs a structure pointer {pointer variable}
    node *ptr;            
    ptr = (node *)malloc(sizeof(node));
    ptr -> data = x;
    ptr -> next= NULL;
    return ptr;
}
void print(node* s){            // adress of first node
    printf("Linked List Data : \n");
    while(s != NULL){
        printf(" %d \t", s->data);
        s = s->next;
    }
    printf("\n");
}
void delbegin(node* s){
    if(HP==NULL){
        printf("\nlist is already empty");
        return;
    }
    if(HP->next==NULL){
        HP = NULL;
        free(s);
        printf("\nLinked List is now empty.\n");
        return;
    }else{
        HP = HP->next;
        free(s);
    }
}
int main(){
    HP = Build123();
    print(HP);
    delbegin(HP);
    print(HP);
    delbegin(HP);
    delbegin(HP);
    print(HP);
    return 0;
}
