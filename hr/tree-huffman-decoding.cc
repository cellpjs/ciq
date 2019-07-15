

/* 
The structure of the node is

typedef struct node
{
    int freq;
    char data;
    node * left;
    node * right;
    
}node;

*/


void decode_huff(node * root, string s) {
    node * walk = root;
    long slen = s.length();
    int i;
    for (i=0; i<slen; i++){
        //std::cout << s[i];
        if (s[i]=='0'){
            walk = walk->left;
        } else if (s[i]=='1'){
            walk = walk->right;
        }
        if ((walk->left == NULL) && (walk->right == NULL)) {
            std::cout << walk->data;
            walk = root;
        }
    }
}



