// directed graph
// find whether there is route between two nodes 
#include <iostream>
#include <string>
#include <list>

using namespace std;

class dnode{
    public:
    list<dnode*> links;
    bool visited; // initialized to 0?
};

bool isroute(dnode* a, dnode* b){

    cout << "$";
    if (a==b) return true;
    else{
        bool found = false;
        for (list<dnode*>::iterator iter=a->links.begin(); iter!=a->links.end(); ++iter){
            if ((*iter)->visited==false){
                (*iter)->visited=true;
                found+=isroute(*iter, b);
            }
        }
        return found;
    }

}

int main(){

dnode* a = new dnode();

dnode* b = new dnode();

dnode* c = new dnode();

dnode* d = new dnode();

dnode* e = new dnode();

dnode* f = new dnode();

a->links.push_back(c);

c->links.push_back(d);

c->links.push_back(e);

d->links.push_back(a);

e->links.push_back(b);

cout << isroute(a,b) << endl;

}



