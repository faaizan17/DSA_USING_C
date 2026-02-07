// void addXafterY(int x,int y){
//     node *ptr = getnode(x);
//     node *s = HP;
//     if(HP==NULL){
//         HP = ptr;
//         return;
//     }
//     if(HP->next==NULL&&HP->data==y){
//         HP->next = ptr;
//         ptr->prev = HP;
//         return;
//     }
//     while(s->next!=NULL&&s->data!=y){
//         s = s->next;
//     }
//     if(s->data==y&&s->next!=NULL){
//         ptr->prev = s;
//         ptr->next = s->next;
//         s->next->prev = ptr;
//         s->next = ptr;
//     }else{
//         if(s->data==y&&s->next==NULL){
//             s->next = ptr;
//             ptr->prev = s;
//         }else{
//             printf("%d not found\n",y);
//             free(ptr);
//         }
//     }
// }