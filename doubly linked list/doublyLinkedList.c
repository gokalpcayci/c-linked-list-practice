#include <stdio.h>  
#include <stdlib.h>
#include <stdbool.h>

   
typedef struct node {
    struct node* prev;
    int value;
    struct node*next;
}Node;

Node* insert_at_start(Node*head, int new_value);
Node* insert_at_end(Node* head, int new_value);
Node* delete_at_start(Node* head);
Node* delete_at_end(Node* head);
void print_nodes(Node* head);

int main(){
    Node* list = NULL;
    int i = 0;
          list = insert_at_start(list, i);
          list = insert_at_start(list, i+1);
          list = insert_at_end(list,i+2);
          list = insert_at_end(list,i+4);
          // 1 0 2 4 
       list =   delete_at_start(list);
       list =   delete_at_end(list);
       list =   delete_at_end(list);
    print_nodes(list);
    return 0;
}

Node* insert_at_start(Node*head, int new_value){

    Node* new_node = calloc(1, sizeof(Node));
    new_node->value = new_value;

    if(head!= NULL) {
        head->prev = new_node;
    }
    new_node->next = head;
    new_node->prev = NULL;
    head = new_node;
    return head;

}

Node* insert_at_end(Node* head, int new_value){
    Node* new_node, *ptr;
    new_node = calloc(1, sizeof(Node));
    ptr = head;
    new_node->value = new_value;
    while(ptr->next != NULL) ptr = ptr->next;
    ptr->next = new_node;
    new_node->prev = ptr;
    new_node->next = NULL;
    return head;
}





void print_nodes(Node* head){
    Node* current = head;
    int length = 0;
 
    while(current->next != NULL){
        length++;
        printf("node-%d: %d\n",length, current->value);
        current = current->next;
    }
 printf("node-%d: %d\n",++length, current->value);
}

Node* delete_at_start(Node* head){
    Node* current = head;
    if(current->next == NULL && current->prev == NULL) return NULL;
    if(current->next != NULL) {
        Node* temp = current->next;
        temp->prev = NULL;
        temp->next = (current->next)->next;
        free(current);
        head = temp;
    }   
    return head;    
    
}

Node* delete_at_end(Node* head){
    Node* current = head;
    if(current->next == NULL && current->prev == NULL) return NULL;
    if(current->next != NULL){
        Node*temp ;
        while(current->next != NULL) {
            temp = current;
            current = current->next;
            }
            temp->next = NULL;
            free(current);
            return head;
    }

}