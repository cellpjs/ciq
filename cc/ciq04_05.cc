// check if tree is binary search tree
// for all nodes, the left children < current node < right children
#include <iostream>
#include <string>
#include <queue>

using namespace std;

class Itnode{
public:
    int data;
    Itnode* left;
    Itnode* right;
    
    /* constructor */
    Itnode(int k){
        data = k;
        left = NULL;
        right = NULL;
    }
    
    void setLeft(Itnode* a){
        left = a;
    }
    
    void setRight(Itnode* b){
        right = b;
    }
    
};

void displayTree(Itnode* r){
    if (r!=NULL){
        cout << r->data;
        if (r->left!=NULL || r->right!=NULL){
            cout << "(";
            if (r->left!=NULL){
                displayTree(r->left);
            }
            cout << ",";
            if (r->right!=NULL){
                displayTree(r->right);
            }
            cout << ")";
        }
    }
}

Itnode* makeBST(int a[], size_t len){
    if (len==0) return NULL;
    else {
        Itnode* root = new Itnode(a[len/2]);
        if (len>=2){
            Itnode* left = makeBST(a, len/2);
            root->setLeft(left);
        }
        if (len>=3){
            Itnode* right = makeBST(a+len/2+1, len/2+len%2-1);
            root->setRight(right);
        }
        return root;
    }
}

bool isBSTlimits(Itnode*r, int min, int max){
    if (r==NULL) return true;
    
    if (r->data > max || r->data < min) return false;
        
    /* check if any left descendant bigger than r */
    if (!isBSTlimits(r->left, min, r->data)) return false;
    
    /* check if any right descendant smaller than r */
    if (!isBSTlimits(r->right, r->data, max)) return false;
    
    return true;
}

bool isBST(Itnode* r){
    return isBSTlimits(r, INT_MIN, INT_MAX);
}


int main(){
    
    Itnode* root = new Itnode(10);
    
    root->setLeft(new Itnode(5));
    root->setRight(new Itnode(15));
    
    root->left->setLeft(new Itnode(3));
    root->left->setRight(new Itnode(7));
    //root->left->setRight(new Itnode(20));
    root->right->setLeft(new Itnode(13));
    root->right->setRight(new Itnode(17));
    
    root->left->left->setLeft(new Itnode(2));
    root->left->left->setRight(new Itnode(4));
    root->left->right->setLeft(new Itnode(6));
    root->left->right->setRight(new Itnode(8));
    root->right->left->setLeft(new Itnode(12));
    root->right->left->setRight(new Itnode(14));
    root->right->right->setLeft(new Itnode(16));
    root->right->right->setRight(new Itnode(18));
    
    root->left->left->left->setLeft(new Itnode(1));
    root->left->right->right->setRight(new Itnode(9));
    root->right->left->left->setLeft(new Itnode(11));
    root->right->right->right->setRight(new Itnode(19));
    
    displayTree(root);
    cout << endl;
    
    cout << "isBST = " << isBST(root) << endl;
    
    Itnode* test = new Itnode(10);
    
    test->setLeft(new Itnode(5));
    test->setRight(new Itnode(15));
    
    test->left->setLeft(new Itnode(3));
    test->left->setRight(new Itnode(7));
    test->left->setRight(new Itnode(20));
    
    displayTree(test);
    cout << endl;
    
    cout << "isBST = " << isBST(test) << endl;
    
    const size_t L=10;
    
    int a[L];
    for (size_t i=0; i<L; i++){
        a[i]=i+1;
    }
    
    Itnode* bst = makeBST(a,sizeof(a)/sizeof(int));
    
    displayTree(bst);
    cout << endl;
    
    cout << "isBST = " << isBST(bst) << endl;

}
