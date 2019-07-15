// in order traversal of binary search tree
#include <iostream>
#include <string>
#include <stack>

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

// recursive
void traverseTree(Itnode* r){
    if (!r) return;
    if (r->left!=NULL){
        traverseTree(r->left);
    }
    cout << r->data <<" ";
    if (r->right!=NULL){
        traverseTree(r->right);
    }
}

// nonrecursive (iterative) stack
void traverseTreeS(Itnode *r){
  if (!r) return;
  Itnode* node = r;
  std::stack<Itnode*> pstack;
  while (!pstack.empty() || node!=NULL)
    if (node!=NULL) {
      pstack.push(node); // all nodes are pushed into the stack once
      node = node->left;
    }
    else { // node == NULL
      node = pstack.top(); pstack.pop(); // pop a node out of the stack
      cout << node->data << " ";
      node = node->right;
    }
}

// nonrecursive (morris traversal)
void traverseTreeNR(Itnode *r){
    if (!r) return;
    Itnode *cur, *pre;
    cur = r;
    while(cur) {
        if(!cur->left) {
            cout << (cur->data) << " ";
            cur= cur->right;
        } 
        else {
            // if you go down left you have to come back up
            pre = cur->left; 
            while (pre->right && pre->right != cur) {
                pre = pre->right;
            }
            if (!pre->right) {
                pre->setRight(cur); // this is the link to come back up
                cur = cur->left;
            } 
            else { // pre->right == cur
                // this happens on the second visit when you come back up
                // after visiting all the nodes to the left
                pre->setRight(NULL); // remove the link to come back up
                cout << (cur->data) << " ";
                cur = cur->right;
            }
        }
    }
}

int main(){
    
    const size_t L=25;
    
    int a[L];
    for (size_t i=0; i<L; i++){
        a[i]=i+1;
    }
    
    Itnode* root = makeBST(a,sizeof(a)/sizeof(int));
    
    displayTree(root);
    cout << endl;

    cout << "recursive: ";
    traverseTree(root);
    cout << endl;

    cout << "nonrecursive (stack): ";
    traverseTreeS(root);
    cout << endl;

    cout << "nonrecursive (uplink): ";
    traverseTreeNR(root);
    cout << endl;
    
}
