#include <tree.h>
struct Node *new_node(char data)
{
  struct Node *node = (struct Node *)malloc(sizeof(struct Node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;

  return (node);
}

int search(char arr[], int strt, int end, char value)
{
  // TODO: Your code here
  int i;
  for(i = strt; i <= end; i++){
    if(arr[i] == value){
      return i;
    }
  }
}

/* Recursive function to construct a binary tree from
   inorder traversal in[in_left..in_right] and preorder
   traversal pre[pre_left..pre_right]. */

struct Node *build_tree(char in[], char pre[], int in_left, int in_right,
                        int pre_left, int pre_right)
{
  
  // TODO: Your code here
  if(in_left > in_right){
    return NULL;
  }


  struct Node *n = new_node(pre[pre_left]);
  
  int i = search(in, in_left, in_right, n->data);

  int l1 = i-in_left;
  int l2 = in_right - i; 

  if(l1 > 0){
    n->left = build_tree(in, pre, in_left, in_left+l1-1,pre_left+1,pre_left+l1);
  }

  else{
    n->left = NULL;
  }

  if(l2 >0){
    n->right = build_tree(in, pre, in_right-l2+1, in_right, pre_right-l2+1, pre_right);
  }

  else{
    n->right = NULL;
  }

  return n;
  
}

void print_postorder(struct Node *node)
{
  if (node == NULL)
    return;

  // first recur on left subtree
  print_postorder(node->left);

  // then recur on right subtree
  print_postorder(node->right);

  // now deal with the node
  printf("%c", node->data); // << node->data << " "; }
}

int print_postorder_string(struct Node *node, int pos, char *output)
{
  if (node == NULL)
    return pos;

  // first recur on left subtree
  int index = 0, index2 = 0;
  index = print_postorder_string(node->left, pos, output);

  // then recur on right subtree
  index2 = print_postorder_string(node->right, index, output);

  output[index2] = node->data;

  return index2 + 1;
}

void build_tree_string(char in[], char pre[], char *output)
{
  int len = print_postorder_string(
      build_tree(in, pre, 0, strlen(in) - 1, 0, strlen(pre) - 1), 0, output);
  output[len] = '\0';
}