#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int value;
  struct node* next;
}Node;

Node*insert_at_start(Node*head, int new_value);
Node* insert_at_end(Node*head, int new_value);
Node* deleting_at_start(Node*head);
Node* deleting_at_end(Node*head);
void print_nodes(Node* head);

int main(){

Node* list = NULL;
list = insert_at_end(list, 1);
list = insert_at_end(list, 2);
list = insert_at_end(list, 3);
list = insert_at_start(list,20);
list = insert_at_start(list,22);
list = insert_at_start(list,24);
// list = deleting_at_start(list);
list = deleting_at_start(list);
 deleting_at_end(list);
 deleting_at_end(list);

print_nodes(list);
  return 0;
}


Node*insert_at_start(Node*head, int new_value){
Node* new_node = calloc(1, sizeof(Node));
new_node->value = new_value;

if(head == NULL) return new_node->next = new_node;
else {
Node* current = head;
  while(current->next != head) current = current->next;
  current->next = new_node;
  new_node->next = head;

}
head = new_node;
return head;
}

Node* insert_at_end(Node*head, int new_value){
  Node* new_node = calloc(1, sizeof(Node));
  new_node->value = new_value;

  if(head == NULL) return new_node->next = new_node;
  else {
    Node*curr = head;
    while(curr->next != head) curr = curr->next;
    curr->next = new_node;
    new_node->next = head;
    return head;
  }
}

void print_nodes(Node* head){

  int length = 0;
  Node* curr = head;
  printf("node-%d: %d\n",length, curr->value);
  curr = curr->next;
  while(curr != head){
    length++;
      printf("node-%d: %d\n",length, curr->value);
    curr = curr->next;

  }
}

Node* deleting_at_start(Node*head){
  Node*curr = head;
    Node* temp = head->next;
  if(temp == NULL) return NULL;
  else{
  
    while(curr->next != head) curr = curr->next;
    curr->next = temp;
  free(head);
    head = temp;
    return head;
  }
}

Node* deleting_at_end(Node*head){
  Node*curr = head;
  if(curr->next == NULL) return NULL;
  else {
    Node* prev;
    while(curr->next != head){
      prev = curr;
      curr = curr->next;
    }
    free(curr);
    prev->next = head;
    return head;
  }
}
