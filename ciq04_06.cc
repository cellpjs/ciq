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

/* use inheritance? */
class ItnodeLU{
    public:
    int data;
    ItnodeLU* left;
    ItnodeLU* right;
    ItnodeLU* parent;
    
    ItnodeLU(int k){
        data = k;
        left = NULL;
        right = NULL;
        parent = NULL;
    }
    
    void setLeft(ItnodeLU* a){
        left = a;
        a->parent = this;
    }
    
    void setRight(ItnodeLU* b){
        right = b;
        b->parent = this;
    }
    
};

void displayTreeLU(ItnodeLU* r){
    if (r!=NULL){
        cout << r->data;
        if (r->left!=NULL || r->right!=NULL){
            cout << "(";
            if (r->left!=NULL){
                displayTreeLU(r->left);
            }
            cout << ",";
            if (r->right!=NULL){
                displayTreeLU(r->right);
            }
            cout << ")";
        }
    }
}

ItnodeLU* BSTNext(ItnodeLU* a){
    
    ItnodeLU* b = a;
    
    if (b->right) {
        b = b->right;
        while (b->left){
            b = b->left;
        }
    }
    else {
        while (b->parent){
            b = b->parent;
            if (b->data >= a->data) break;
        }
    }
    /* handle last node? */
    return b;
}

ItnodeLU* makeBSTLU(int a[], size_t len){
    if (len==0) return NULL;
    else {
        ItnodeLU* root = new ItnodeLU(a[len/2]);
        if (len>=2){
            ItnodeLU* left = makeBSTLU(a, len/2);
            root->setLeft(left);
        }
        if (len>=3){
            ItnodeLU* right = makeBSTLU(a+len/2+1, len/2+len%2-1);
            root->setRight(right);
        }
        return root;
    }
}

int main(){
    
    const size_t L=31;
    
    int a[L];
    for (size_t i=0; i<L; i++){
        a[i]=i+1;
    }
    
    ItnodeLU* root = makeBSTLU(a,sizeof(a)/sizeof(int));
    
    displayTreeLU(root);
    cout << endl;
    
    ItnodeLU* u = root;
    while (u->left) {
        u = u->left;
    }
    cout << u->data << endl;
    
    for (size_t i=0; i<L-1; i++){
        u = BSTNext(u);
        cout << u->data << endl;
    }
    
}
