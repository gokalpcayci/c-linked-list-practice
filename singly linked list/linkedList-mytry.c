#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
int value;
struct node *next;
}Node;

// functions
Node *insert_at_head(Node* head, int new_value);
Node *insert_at_tail(Node* head, int new_value);
Node *deleting_at_head(Node*head);
int count_matches(Node *node, int find_value);
Node *deleting_at_tail(Node *head);
int length(Node *head);
int recursive_length(Node *head);
void print_nodes(Node *head);
int replace_matches(Node *node,int find_value, int replace_value);
Node *delete_first_match(Node *head, int delete_value, bool *was_deleted );
Node *delete_all_matches(Node *head, int delete_value, int *num_deleted);

//
//
int main(){

Node * node = NULL;
int a;
printf("enter a value: ");
scanf("%d", &a);

node = insert_at_head(node, 21);
node = insert_at_tail(node, a);
node = insert_at_tail(node, a);
// node = insert_at_tail(node, a);
node = insert_at_tail(node, a+1);
node = insert_at_tail(node, a+2);
node = insert_at_tail(node, a+3);
node = insert_at_tail(node, a+4);

// node = deleting_at_tail(node);
bool deleted;
// node = delete_first_match(node, 3, &deleted);
node = delete_all_matches(node, 3,&deleted);
printf("number of 2's: %d",count_matches(node, 2) );
// replace_matches(node, 2, 5);
printf("\n");
// node = insert_at_tail(node, 70);
// node = insert_at_tail(node, 714);
print_nodes(node);
  return 0;
}


Node *insert_at_head(Node* head, int new_value){

Node *new_node = calloc(1, sizeof(Node));
new_node->value = new_value;
if(head == NULL) {
  return new_node;
} else {
  new_node->next = head;
  return new_node;
}

}

Node *insert_at_tail(Node* head, int new_value){
Node *new_node = calloc(1, sizeof(Node));
new_node->value = new_value;
if(head == NULL) return new_node;
else {
  Node *current = head;
  while(current->next !=NULL) current = current->next;
  current->next = new_node;
  return head;
}
}


void print_nodes(Node *head){
Node *current;
current = head;
int a = 0;
while(current != NULL){
  printf("Node-%d: %d \n", a, current->value);
  a++;
  current = current->next;
}
}

Node *deleting_at_head(Node*head){
  if(head == NULL) return NULL;
  else {
    Node * to_return = head->next;
    free(head);
    return to_return;
  }
}

Node *deleting_at_tail(Node *head){
  if(head == NULL) return NULL;
  else if(head->next == NULL) {
    free(head);
    return NULL;
  }
  else{
    Node *current = head;
    Node *prev = NULL;
     while(current->next != NULL){
      prev = current;
      current = current->next;
      } 
      prev->next = NULL;
      free(current);
      return head;
     
  }
}

int length(Node *head){
  Node *current ;
  current = head;
  int length = 0;
  while(current !=NULL){
    current = current->next;
    length++;
  }
  return length;
}

int recursive_length(Node *node){
  if(node == NULL) return 0;
  else return 1 + recursive_length(node->next);
}

int count_matches(Node *node, int find_value){
  if(node == NULL) return 0;
  else if(node->value == find_value){
    return 1 + count_matches(node->next, find_value);
  }
  else return count_matches(node->next, find_value);
}


int replace_matches(Node *node,int find_value, int replace_value){

  if(node != NULL) {
  if(node->value == find_value)  node->value = replace_value;
    replace_matches(node->next, find_value, replace_value);
  }
}

Node *delete_first_match(Node *head, int delete_value, bool *was_deleted ){

  if(head == NULL){
    *was_deleted = false;
    return NULL;
  }
  if(head->value == delete_value) {
    Node *temp = head->next;
    free(head);
    *was_deleted = true;
    return temp;
  }

  Node *current = head->next;
  Node *prev = head;

  while(current != NULL){

    if(current->value == delete_value){
      prev->next = current->next;
      free(current);
      *was_deleted  = true;
      return head;
    }

    prev = current; 
    current = current->next;

  }
  *was_deleted = false;
  return head;
}




Node *delete_all_matches(Node *head, int delete_value, int *num_deleted)
{
  Node *current = head;
  bool deleted = false;
  *num_deleted = 0;
  do{
    current = delete_first_match(current, delete_value, &deleted);
    if(deleted) *num_deleted = num_deleted + 1;
  }while(deleted);

  return current;
}
