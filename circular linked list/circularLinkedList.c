#include <stdio.h>
#include <stdlib.h>


typedef struct node {
  int value;
  struct node* next;
}Node;

// functions
Node *insert_at_start(Node* head, int new_value);
Node *insert_at_end(Node *head, int new_value);
Node* insert_at_between(Node* head, int new_value, int finded_val);
void print_nodes(Node* head);
Node* deleting_at_start(Node* head);
Node* deleting_at_end(Node* head);
//
//
int main(){
  Node*list = NULL;

  list = insert_at_start(list, 1);
  list = insert_at_start(list, 2);
  list = insert_at_start(list, 3);
  list = insert_at_start(list, 4);
  list = insert_at_end(list, 5);
  list = insert_at_end(list, 6);
  list = deleting_at_start(list);
  list = insert_at_end(list, 7);
  list = insert_at_between(list, 21, 3);
  list = deleting_at_end(list);
  list = deleting_at_end(list);
print_nodes(list);
  return 0;
}

Node *insert_at_start(Node* head, int new_value){
  Node * ptr ;
  Node * new_node = calloc(1, sizeof(Node));
  new_node->value = new_value;

  if(head != NULL) {
    ptr = head;
    while(ptr->next != head) ptr = ptr->next;

    ptr->next = new_node;
    new_node->next = head;
    
  }
  else {
     new_node->next = new_node;
    }
    head = new_node;
  return head;
}


Node *insert_at_end(Node *head, int new_value){
  Node* ptr;
  Node* new_node = calloc(1, sizeof(Node));
  new_node->value = new_value;

  if(head == NULL) new_node->next = new_node;
  else {
    ptr = head;
    ptr = ptr->next;

    while(ptr->next != head) ptr = ptr->next;
    ptr->next = new_node;
    new_node->next = head;
  }
    return head;
}



Node* insert_at_between(Node* head, int new_value, int finded_val){
  Node* new_node, *ptr, *preptr;
  new_node = calloc(1, sizeof(Node));
  new_node->value = new_value;
  preptr = head;
  ptr = head->next;
  while(ptr->next!=head && preptr->value != finded_val){
    preptr = ptr;
    ptr = ptr->next;
  }
  if(ptr != head){
    preptr ->next = new_node;
    new_node->next = ptr;
  }
  return head;

}



void print_nodes(Node* head){
  Node *ptr = head;
    int length = 0;
    printf("node-%d: %d\n", length, ptr->value);
    ptr = ptr->next;
    while(ptr != head) {
    length++;
    printf("node-%d: %d\n", length, ptr->value);
    ptr = ptr->next;
    }
  
}



Node* deleting_at_start(Node* head){
  Node* current = head;
  Node* ptr = head->next;
  if(ptr == NULL) return NULL;
  else {
  while(current->next != head) current = current->next;
  current->next = ptr;
  free(head);
  head = ptr;
  return head;
  }
}



Node* deleting_at_end(Node* head){

  Node* current = head;
  if(current->next == head) return NULL;
  else {
    Node * prev;
    while(current->next != head) {
      prev = current;
      current = current->next;
      }
      prev->next = head;
      free(current);
      return head;
  }
}


