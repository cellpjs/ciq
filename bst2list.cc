// binary search tree to doubly linked list
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

void bst2list_re(Itnode *r, Itnode *&prev){
    /* note that we are passing the pointer prev by reference */
    /* this means that one instance of prev is shared by all nodes 
    as opposed to copies of the pointer being made */
    /* this insures that modification to prev made by child nodes (callee)
    are visible to the parent nodes (caller) */
    if (r==NULL) return;
    bst2list_re(r->left, prev);
    // do something
    r->setLeft(prev);
    if (prev) {
        prev->setRight(r);
    }
    prev = r;
    bst2list_re(r->right, prev);
}

Itnode* bst2list(Itnode *r){
    Itnode* prev = NULL;
    bst2list_re(r, prev);
    Itnode* head = r;
    while (head->left) {
        head = head->left;
    }
    return head;
}

void printList2(Itnode* c){
    while (c){
        cout << c->data << " ";
        c = c->right;
    }
    cout << endl;
}


int main(){
    
    const size_t L=25;
    
    int a[L];
    for (size_t i=0; i<L; i++){
        a[i]=i+1;
    }
    
    Itnode* root = makeBST(a,sizeof(a)/sizeof(int));
    Itnode* head = bst2list(root);
    printList2(head);
    
}
