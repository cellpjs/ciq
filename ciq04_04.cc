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

int height(Itnode* r){
    if (r==NULL) return 0;
    else return 1+max(height(r->left), height(r->right));
}

int depth(Itnode* r, Itnode* v){
    if (r==NULL) return -1;
    else if (r==v) return 0;
    else {
        int dl = depth(r->left, v);
        int dr = depth(r->right, v);
        if (dl<0 && dr <0) return -1;
        else if (dl>=0 && dr<0) return 1+dl;
        else if (dr>=0 && dl<0) return 1+dr;
        else return 1+min(dl,dr);
    }
}

class Inode{
public:
    int data;
    Inode* next;
};

void appendNode(Inode *&h, int k){
    if (h==NULL){
        h = new Inode;
        h->data = k;
        h->next = NULL;
    }
    else{
        Inode* anode = new Inode;
        anode->data = k;
        anode->next = NULL;
        Inode* r = h;
        while(r->next){
            r=r->next;
        }
        r->next = anode;
    }
}

void pushNode(Inode *&h, int k){
    Inode* anode = new Inode;
    anode->data = k;
    anode->next = h;
    h=anode;
}

void printList(Inode* a){
    while (a){
        cout << a->data << " ";
        a = a->next;
    }
    cout << endl;
}

void makeDepthList(Itnode* r, Inode** &a){
    
    /* BFS */
    queue<Itnode*> cq;
    cq.push(r);

    while(!cq.empty()){
        Itnode* v = cq.front();
        cq.pop();
        if (v->left) cq.push(v->left);
        if (v->right) cq.push(v->right);
        appendNode(a[depth(r,v)],v->data);
    }

}

int main(){
    
    int h;
    
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
    
    h = height(root);

    /* dl: h pointers to linked list heads */
    Inode** dl = new Inode* [h];
    /* need to initialize? */
    for (int i=0; i<h; i++){
        dl[i]=NULL;
    }
    
    makeDepthList(root, dl);
    for (int i=0; i<h; i++){
        cout << "level " << i << " : ";
        printList(dl[i]);
    }

}
