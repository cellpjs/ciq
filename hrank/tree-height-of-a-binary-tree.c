

/* you only have to complete the function given below.  
node is defined as  

struct node {
    
    int data;
    struct node *left;
    struct node *right;
  
};

*/
int getHeight(struct node* root) {
    int left, right, hmax;
    if (root==NULL) {
        exit(-1);
    }
    left = (root->left ? 1 + getHeight(root->left) : 0);
    right = (root->right ? 1 + getHeight(root->right) : 0);
    hmax = (left > right ? left : right);
    //printf("%d -- %d\n", root->data, hmax);
    return hmax;
    
}



