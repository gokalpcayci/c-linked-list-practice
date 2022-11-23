#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  struct node* prev;
  int value;
  struct node* next;
}Node;

Node* insert_at_start(Node*head, int new_value);
Node* insert_at_end(Node*head, int new_values);
Node*delete_from_start(Node*head);
Node*delete_from_end(Node*head);
void print_nodes(Node*head);

int main(){



  return 0;
}


Node* insert_at_start(Node*head, int new_value){

  Node* new_node = calloc(1, sizeof(Node));
  new_node->value = new_value;

  if(head->next == NULL){
    new_node->next = new_node;
    new_node->prev = NULL;
  }
  else {
    
  }



}

Node* insert_at_end(Node*head, int new_values){

}

void print_nodes(Node*head){

}

Node*delete_from_start(Node*head){

}

Node*delete_from_end(Node*head){

}