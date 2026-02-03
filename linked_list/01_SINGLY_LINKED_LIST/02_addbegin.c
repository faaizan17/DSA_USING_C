#include<stdio.h>
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

node* addbegin(node* s, int x){
    node *ptr;
    ptr = getnode(x);
    ptr->next = s;
    return ptr;
}
void print(node* s){            // adress of first node
    printf("liked list data : \n");
    while(s != NULL){
        printf(" %d \t", s->data);
        s = s->next;
    }
}
int main(){
    HP = Build123();
    print(HP);
    printf("\n");
    HP = addbegin(HP, 0);
    print(HP);
    return 0;
}
