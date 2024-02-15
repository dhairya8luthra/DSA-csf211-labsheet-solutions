// #include <stdio.h>
// #include <stdlib.h>


// typedef struct
// {
//     struct node* next;
//     int data;
// }node;

// typedef struct 
// {
//     node* head;
// }linkedList;

// node* makeNode(int val) {
//     node* newNode = (node*)malloc(sizeof(node));
//     newNode->data = val;
//     newNode->next = NULL;
//     return newNode;
// }
// void insert( linkedList* list,int val) {
//      node* curr = list->head;

//      node* newNode = makeNode(val);
//     if (curr == NULL) {
//         list->head = newNode;
//         return;
//     }
//     while (curr->next != NULL)
//     {
//         curr = curr->next;        
//     }
//     curr->next = newNode;
// }


// linkedList* empty_init(){
//     linkedList* list = (linkedList*)calloc(1,sizeof(linkedList)); 
//     return list;
// }


// linkedList* init(int arr[],int n){
//     linkedList* list = empty_init();
//     for (size_t i = 0; i < n; i++)
//     {
//         insert(list,arr[i]);
//     }
    
//     return list;
// }


// void printList( linkedList* list) {
//     node* curr = list->head;
//     while (curr != NULL)
//     {
//         printf("%d ", curr->data);
//         curr = curr -> next;
//     }
    
// }

#include <stdio.h>
#include <stdlib.h>


struct node
{
    struct node* next;
    int data;
};

struct linkedList
{
    struct node* head;
};

struct node* makeNode(int val) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}
void insert(struct linkedList* list,int val) {
    struct node* curr = list->head;

    struct node* newNode = makeNode(val);
    if (curr == NULL) {
        list->head = newNode;
        return;
    }
    while (curr->next != NULL)
    {
        curr = curr->next;        
    }
    curr->next = newNode;

}


struct linkedList* empty_init(){
    struct linkedList* list = (struct linkedList*)calloc(1,sizeof(struct linkedList)); 
    return list;
}


struct linkedList* init(int arr[],int n){
    struct linkedList* list = empty_init();
    struct node* curr = makeNode(arr[0]);
    list -> head = curr;
    
    for (size_t i = 1; i < n; i++)
    {
        struct node* new = makeNode(arr[i]);
        curr -> next = new;
        curr = curr -> next;
    }
    
    return list;
}


void printList(struct linkedList* list) {
    struct node* curr = list->head;
    while (curr != NULL)
    {
        printf("%d ", curr->data);
        curr = curr -> next;
    }
    
}




