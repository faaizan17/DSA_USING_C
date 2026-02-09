#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *next;
} node;
node *HP = NULL;
node* getnode(int x){
    node *ptr = (node *)malloc(sizeof(node));
    ptr->data = x;
    ptr->next = NULL;
    return ptr;
}
node* build(){
    node *temp1, *temp2, *temp3;
    temp1 = getnode(1);
    temp2 = getnode(2);
    temp3 = getnode(3);
    temp1->next = temp2;
    temp2->next = temp3;
    temp3->next = temp1;
    return temp1;
}
// void print(){
//     node *s = NULL;
//     printf("linked list data :\n");
//     while(s!=HP){
//         if(s==NULL){
//             s = HP;
//             printf("%d\t", s->data);
//             s = s->next;
//             continue;
//         }
//         printf("%d\t", s->data);
//         s = s->next;
//     }
// }
void print(){
    if(HP==NULL){
        printf("list is empty");
        return;
    }
    node *s = HP;
    printf("linked list data :\n");
    do{
        printf("%d\t", s->data);
        s = s->next;
    } while (s != HP);
}
void freelist(){
    node *temp = NULL;
    node *s = HP;
    do{
        temp = s;
        free(temp);
        s = s->next;
    } while (s != HP);
    HP = NULL;
}
int main(){
    HP = build();
    print();
    freelist();
    return 0;
}
