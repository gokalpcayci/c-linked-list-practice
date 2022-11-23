#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
  int value;
  struct node* next;
}Node;

void print_nodes(Node*head);
Node* insert_at_start(Node*head, int new_value);
Node* insert_at_end(Node*head, int new_value);
Node* delete_at_start(Node*head);
Node* delete_at_end(Node*head);

int main(){
  Node* list = NULL;
  list = insert_at_start(list, 1);
  list = insert_at_start(list, 2);
  list = insert_at_start(list, 3);
  list =  delete_at_end(list);
  list =  delete_at_end(list);
  print_nodes(list);
  return 0;
}


Node* insert_at_start(Node*head, int new_value){

  Node* new_node = calloc(1, sizeof(Node));
  new_node->value = new_value;


  if(head == NULL) return new_node;
  else {
    new_node->next = head;
    head = new_node;
    return head;
  }
}

Node* insert_at_end(Node*head, int new_value){

  Node* new_node = calloc(1, sizeof(Node));
  new_node->value = new_value;


  if(head == NULL) return new_node;
  else {
    Node*ptr = head;
    while(ptr->next != NULL) ptr = ptr->next;
    ptr->next = new_node;
    new_node->next = NULL;
    return head;
  }
}

Node* delete_at_start(Node*head){

  if(head  == NULL) return NULL;
  else{
    Node* temp = head->next;
    free(head);
    return temp;
  }
}

Node* delete_at_end(Node*head){
      Node*ptr = head;
    if(head  == NULL) return NULL;
    else{
      
      Node*prev = head;
      while(ptr->next != NULL){
        prev = ptr;
        ptr = ptr->next;
      } 
      free(ptr);
      prev->next = NULL;
      return head;
    }
  
}


void print_nodes(Node*head){
  int length = 0;
  Node*ptr = head;
  while(ptr != NULL){
    length++;
    printf("node-%d: %d\n",length, ptr->value);
    ptr = ptr->next;
  }
}


