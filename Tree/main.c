#include <acutest.h>
#include <stdint.h>
#include <tree.h>

// int main() {
//   // char preorder[100] = "ADFGHKLPQRWZ", inorder[100] = "GFHKDLAWRQPZ"; //
//   // GKHFLDWRQZPA

//   //  char preorder[100] = "ABCDEFG", inorder[100] = "CBDAFEG";

//   // char preorder[100] = "1C569", inorder[100] = "5C619";
//   // 56C91

//   //
//   char preorder[100] = "12485367", inorder[100] = "48251637";
//   // 8, 4, 5, 2, 6, 7, 3, 1

//   printf("Input the pre-order traversal: ");

//   // Read in pre-order traversal from the command line
//   // scanf("%s", preorder);

//   printf("Input the in-order traversal: ");
//   // Read in in-order traversal from the command line
//   // scanf("%s", inorder);

//   int len;

//   len = strlen(preorder);

//   // Calculate the length of input strings
//   printf("%d", len);
//   // Build the binary tree
//   struct Node *root = build_tree(inorder, preorder, 0, len - 1, 0, len - 1);

//   // Output the post-order of the binary tree
//   printf("The post-order traversal is: ");
//   print_postorder(root);

//   struct Node *root2 =
//       build_tree_static(inorder, preorder, 0, len - 1, 0, len - 1);

//   // Output the post-order of the binary tree
//   printf("The post-order traversal is: ");

//   print_postorder(root2);

//   printf("\n");

//   return 0;
// }

struct TestVector
{
  const char *inorder;
  const char *preorder;
  const char *postorder;
  int len;
  const char *name;
};

struct TestVector test_vectors[] = {
    // Inorder,Preorder,Postorder(Expected)
    {"abc", "bac", "acb", 3, "Test1"},
    {"12345", "42135", "13254", 5, "Test2"},
    {"CBDAFEG", "ABCDEFG", "CDBFGEA", 7, "Test3"},
    {"GFHKDLAWRQPZ", "ADFGHKLPQRWZ", "GKHFLDWRQZPA", 12, "Test4"}};

void tester_basic(void)
{
  int i;
  uint8_t *output;
  size_t output_size;

  for (i = 0; i < sizeof(test_vectors) / sizeof(test_vectors[0]); i++)
  {
    struct TestVector *vec = &test_vectors[i];
    output = NULL;
    /* Output the name of the tested test vector. */
    TEST_CASE(vec->name);

    /* Now, we can check the function produces what it should for the
     * current test vector. If any of the following checking macros
     * produces any output (either because the check fails, or because
     * high `--verbose` level is used), Acutest also outputs the  currently
     * tested vector's name. */
    char output_string[100];
    build_tree_string(vec->inorder, vec->preorder, output_string);
    TEST_CHECK(!strcmp(vec->postorder, output_string));
    TEST_MSG("Expected: %s", vec->postorder);
    TEST_MSG("Produced: %s", output_string);
    printf("\n%s", output_string);
  }
}

TEST_LIST = {{"basic", tester_basic}, {NULL, NULL}

};