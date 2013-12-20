// find a node with number x in binary search tree
// if not found return the node with the next number 
// (node with smallest number greater than or equal to x)
#include <iostream>
#include <string>

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

Itnode* bst_findnext(Itnode* r, int x, Itnode* s){
    if (r==NULL) return NULL;
    if (x == r->data) {
        /* found exact match */
        return r;
    }
    else if (x < r->data) {
        if (r->left) return bst_findnext(r->left, x, r);
        /* every time we go LEFT it means 
        we are moving to a smaller node
        while the current node is still bigger than x
        so we pass down the current node pointer
        since it is the smallest node we have seen so far 
        which is still bigger than x
        */
        else return r;        
    }
    else /* if (x > r->data) */ {
        if (r->right) return bst_findnext(r->right, x, s); /* relay down */
        else return s;
    }
}


int main(){
    
    const size_t L=25;
    
    int a[L];
    for (size_t i=0; i<L; i++){
        a[i]=10*(i+1);
    }
    
    Itnode* root = makeBST(a,sizeof(a)/sizeof(int));
    //displayTree(root);
    Itnode* next = bst_findnext(root, 145, NULL);
    if (next){
        cout << "found " << next->data << endl;
    }
    else {
        cout << "nothing bigger found" << endl;
    }
    
}
