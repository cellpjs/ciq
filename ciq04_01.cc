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

int height(Itnode* r){
    if (r==NULL) return 0;
    else return 1+max(height(r->left), height(r->right));
}

bool isBalanced(Itnode* r){
    if (r==NULL) return true;
    else if (abs(height(r->left)-height(r->right))>1) return false;
    else return (isBalanced(r->left) && isBalanced(r->right));
}

/* more efficient by combining height and balance check */
int dheight(Itnode* r){
    if (r==NULL) return 0;
    else {
        int hl = dheight(r->left);
        int hr = dheight(r->right);
        if (abs(hl-hr)>1 || hl==-1 || hr==-1) return -1;
        else return 1+max(hl, hr);
    }

}

int main() {

    Itnode* root = new Itnode(10);

    root->setLeft(new Itnode(5));
    root->setRight(new Itnode(15));

    root->left->setLeft(new Itnode(3));
    root->left->setRight(new Itnode(7));

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

    cout << "height=" << height(root) << endl;

    cout << "balanced=" << isBalanced(root) << endl;

    cout << "dheight=" << dheight(root) << endl;

    cout << "balanced=" << (dheight(root)!=-1) << endl;


}
