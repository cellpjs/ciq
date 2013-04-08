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

int height(Itnode* r){
    if (r==NULL) return 0;
    else return 1+max(height(r->left), height(r->right));
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

void preorderVectorize(Itnode* a, vector<int> &v){
    if (a!=NULL){
        v.push_back(a->data);
        if (a->left!=NULL || a->right!=NULL){
            if (a->left!=NULL){
                preorderVectorize(a->left, v);
            }
            if (a->right!=NULL){
                preorderVectorize(a->right, v);
            }
        }
    }
}

/* this is a weak test (produces false positives) */
bool isSubtreeWeak(Itnode* s, Itnode* b){
    vector<int> vs;
    vector<int> vb;
    
    preorderVectorize(s, vs);
    preorderVectorize(b, vb);
    
    for (vector<int>::iterator it = vb.begin() ; it != vb.end()-vs.size(); ++it) {
        if (equal(vs.begin(), vs.end(), it)) return true;
    }
    return false;
}

Itnode* heightTree(Itnode* r){
    if (r==NULL) return NULL;
    else if (r->right==NULL && r->left==NULL){
        Itnode* h = new Itnode(1);
        return h;
    }
    else {
        Itnode* left = heightTree(r->left);
        Itnode* right = heightTree(r->right);
        int k;
        if (left==NULL) k=1+right->data;
        else if (right==NULL) k=1+left->data;
        else k = 1+max(left->data, right->data);
        Itnode* h = new Itnode(k);
        h->setLeft(left);
        h->setRight(right);
        return h;
    }
}

bool subtreeMatch(Itnode* s, Itnode* hs, Itnode* b, Itnode* hb){
    if (s==NULL) return true;
    else if (b==NULL) return false;
    else if (hs->data > hb->data) return false;
    else if (hs->data == hb->data && s->data == b->data){
        return (subtreeMatch(s->left, hs->left, b->left, hb->left) &&
                subtreeMatch(s->right, hs->right, b->right, hb->right));
    }
    else {
        return (subtreeMatch(s, hs, b->left, hb->left) ||
                subtreeMatch(s, hs, b->right, hb->right));
    }
}

bool isSubtree(Itnode* s, Itnode* b){
    /* make height trees for b and s */
    Itnode* hb = heightTree(b);
    Itnode* hs = heightTree(s);
    return subtreeMatch(s, hs, b, hb);
}

int main(){
    
    const size_t L=31;
    
    int a[L];
    for (size_t i=0; i<L; i++){
        a[i]=i+1;
    }
    
    Itnode* bst_big = makeBST(a,sizeof(a)/sizeof(int));
    
    displayTree(bst_big);
    cout << endl;
    
    const size_t M=7;
    
    int b[M];
    for (size_t i=0; i<M; i++){
        b[i]=i+1;
    }
    
    Itnode* bst_small = makeBST(b,sizeof(b)/sizeof(int));
    
    displayTree(bst_small);
    cout << endl;
    
    cout << "isSubtree = " << isSubtree(bst_small, bst_big) << endl;
    
    Itnode* another = new Itnode(18);
    another->setLeft(new Itnode(17));
    another->setRight(new Itnode(19));
    
    displayTree(another);
    cout << endl;
    
    cout << "isSubtree = " << isSubtree(another, bst_big) << endl;
    
    Itnode* test = new Itnode(13);
    test->setLeft(new Itnode(15));
    
    displayTree(test);
    cout << endl;
    
    cout << "isSubtree = " << isSubtree(test, bst_big) << endl;
    
    
}
