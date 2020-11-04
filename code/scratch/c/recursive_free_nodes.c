#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
  int values[2];
  struct ListNode *next;
} ListNode;

void print_and_cleanup(ListNode *node) {
  if (node->next != NULL) print_and_cleanup(node->next);

  if (node != NULL) {
    printf("[%d, %d]\n", node->values[0], node->values[1]);
    free(node);
    node->next = NULL;
  }
}

int main() {
  ListNode *root = malloc(sizeof(ListNode));
  ListNode *next = malloc(sizeof(ListNode));
  ListNode *next_next = malloc(sizeof(ListNode));
  root->values[0] = 1;
  root->values[1] = 2;
  root->next = next;
  next->values[0] = 3;
  next->values[1] = 4;
  next->next = next_next;
  next_next->values[0] = 5;
  next_next->values[1] = 6;

  print_and_cleanup(root);
}
