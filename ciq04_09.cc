#include <iostream>
#include <vector>

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

void sumPathsRecursive(int s, Itnode*r, vector<int> v){
    if (r==NULL) return;
    
    v.push_back(r->data);
    // look for sum paths that ends with r
    int psum = 0;
    for (vector<int>::reverse_iterator rit=v.rbegin(); rit!=v.rend(); rit++){
        psum+= *rit;
        if (psum==s) {
            for (vector<int>::iterator pit=(rit+1).base(); pit!=v.end(); pit++){
                cout << *pit << " ";
            }
            cout << endl;
        }
    }
    // look at further down end nodes
    sumPathsRecursive(s, r->left, v);
    sumPathsRecursive(s, r->right, v);
}

void sumPaths(int s, Itnode* r){
    /* finds sum paths for DIRECTED trees */
    
    vector<int> v;
    
    cout << "paths with sum = " << s << endl;
    
    sumPathsRecursive(s, r, v);
    
}

int main(){
    
    const size_t L=31;
    
    int a[L];
    for (size_t i=0; i<L; i++){
        a[i]=i+1;
    }
    
    Itnode* bst = makeBST(a,sizeof(a)/sizeof(int));
    
    displayTree(bst);
    cout << endl;
    
    sumPaths(15, bst);
    
    sumPaths(30, bst);
    
    sumPaths(121, bst);
    
}
