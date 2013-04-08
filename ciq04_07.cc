#include <iostream>
#include <string>

using namespace std;

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

ItnodeLU* commonAncestor(ItnodeLU* a, ItnodeLU* b){
    ItnodeLU* sa = a;
    ItnodeLU* sb = b;
    int da = 0;
    int db = 0;
    while(sa->parent) {
        sa = sa->parent;
        da++;
    }
    while (sb->parent) {
        sb = sb->parent;
        db++;
    }
    sa = a;
    sb = b;
    if (da>db){
        for (int i=0; i<da-db; i++){
            sa = sa->parent;
        }
    }
    else if (db>da){
        for (int i=0; i<db-da; i++){
            sb = sb->parent;
        }
    }
    /* now at the same level */
    while (sa != sb){
        sa = sa->parent;
        sb = sb->parent;
    }
    return sa;
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
    
    ItnodeLU* u = root->right->right;
    cout << u->data << endl;
    
    ItnodeLU* v = root->right->left->left;
    cout << v->data << endl;
    
    ItnodeLU* c = commonAncestor(u,v);
    cout << c->data << endl;
    
    
}
