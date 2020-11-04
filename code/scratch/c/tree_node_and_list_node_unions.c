#include <stdio.h>
#include <stdlib.h>

// requires C11 for anonymous structs.

typedef enum node_t { LIST_NODE, TREE_NODE } node_t;

typedef struct node {
  node_t t;
  int value;
  union {
    struct node *next;
    struct {
      struct node *left;
      struct node *right;
    };
  };
} node;

void print_next_node(node *n) {
  switch (n->t) {
    case LIST_NODE:
      printf("The next node value is: %d\n", n->next->value);
      break;
    case TREE_NODE:
      printf("The left node value is: %d\n", n->left->value);
      printf("The right node value is: %d\n", n->right->value);
      break;
    default:
      break;
  }
}

int main() {
  node *tree_node = malloc(sizeof(node));
  node *tree_left = malloc(sizeof(node));
  node *tree_right = malloc(sizeof(node));

  tree_node->t = TREE_NODE;
  tree_left->t = TREE_NODE;
  tree_right->t = TREE_NODE;
  tree_node->value = 5;
  tree_left->value = 0;
  tree_right->value = 10;
  tree_node->right = tree_right;
  tree_node->left = tree_left;

  print_next_node(tree_node);

  free(tree_node);
  free(tree_left);
  free(tree_right);

  node *list_root = malloc(sizeof(node));
  node *list_next = malloc(sizeof(node));

  list_root->t = LIST_NODE;
  list_root->value = 10;
  list_root->next = list_next;
  list_next->t = LIST_NODE;
  list_next->value = 20;

  print_next_node(list_root);

  free(list_root);
  free(list_next);
}
