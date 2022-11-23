#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  struct node* prev;
  int value;
  struct node* next;
}Node;


Node* add_at_head(Node* head, int new_value);
Node* add_at_end(Node* head, int new_value);
void print_nodes(Node* head);

int main(){
  Node* list = NULL;
list = add_at_head(list, 1);
list = add_at_head(list, 2);
list = add_at_head(list, 3);
list = add_at_end(list, 12);
list = add_at_end(list, 13);
print_nodes(list);
  return 0;
}

Node* add_at_head(Node* head, int new_value){

  Node*new_node = calloc(1, sizeof(Node));
  new_node->value = new_value;

if(head != NULL) {
  head->prev = new_node;
}
 new_node->next = head;
 new_node->prev = NULL;
 head = new_node;
 return head;
}

Node* add_at_end(Node* head, int new_value){

  Node* curr = head;
  Node*new_node = calloc(1, sizeof(Node));
  new_node->value = new_value;

  if(head == NULL) return new_node;
  if(head->next != NULL){
    Node* ptr;
    while(curr->next != NULL){
    ptr = curr;
    curr = curr->next;

    } 
    curr->next = new_node;
    new_node->prev = ptr;
    new_node->next = NULL;
  }
  return head;
}





void print_nodes(Node* head){
  int length = 0;
  Node* ptr = head;

  while(ptr->next  != NULL){
    length++;
    printf("node-%d: %d\n", length, ptr->value);
    ptr = ptr->next;
  }
      printf("node-%d: %d\n", length, ptr->value);

}