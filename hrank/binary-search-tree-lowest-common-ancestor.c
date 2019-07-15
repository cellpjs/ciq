

/* you only have to complete the function given below.  
node is defined as  

struct node {
    
    int data;
    struct node *left;
    struct node *right;
  
};

*/
struct node *lca( struct node *root, int v1, int v2 ) {
  if ((v1 >= root->data && v2 <= root->data) || (v1 <= root->data && v2 >= root->data)){
      return root;
  } else if (v1 > root->data && v2 > root->data) {
      return lca(root->right, v1, v2);
  } else {
      // (v1 < root->data && v2 < root->data)
      return lca(root->left, v1, v2);
  }
}



