#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cstdlib>

using namespace std;

// declaration
class Call;
class Employee;
class Respondent;
class Manager;
class Director;
class Dispatcher{

    queue<Call*> _calls_respondent;
    queue<Call*> _calls_manager;
    queue<Call*> _calls_director;

    vector<Respondent*> _respondents;
    vector<Manager*> _managers;
    vector<Director*> _directors;

    // singleton ----
    Dispatcher(); // make contructor private
    ~Dispatcher(); // disallow destructor
    Dispatcher(const Dispatcher&); // disallow copy constructor
    const Dispatcher& operator=(const Dispatcher&); //disallow assignment operator, const? &?

    public:

    static Dispatcher& Instance();
    Employee* add_respondent(string name);
    Employee* add_manager(string name);
    Employee* add_director(string name);
    // delete?

    // for use by main()
    void add_incoming_call(Call* call);
    // for use by Respondent::escalate_call()
    void add_manager_call(Call* call);
    // for use by Manager::escalate_call()
    void add_director_call(Call* call);
    void run();
    int total_calls();

    private:
    template <typename T>
    bool assign(vector<T*> ev, Call* call);
};

class Call{
    static int id_next;
    int _call_id;

    public:
    Call(): _call_id(0) {
        _call_id = id_next;
        id_next++;
    }
    int call_id(){
        return _call_id;
    }
};
int Call::id_next = 1;

class Employee{
    protected:
    static int id_next; // will this be unique or 3 separate?
    string _name;
    int _employee_id;
    Dispatcher* _dispatcher;
    Call* _handling;
    // pointer vs reference
    // reference cannot be unitialized and always points to the same object    

    public:
    Employee(string name, Dispatcher* pd): _name(name)
        , _employee_id(0), _dispatcher(pd), _handling(NULL) {
        _employee_id = id_next;
        id_next++;
    }
    bool isbusy() const {
        return (_handling!=NULL);
    }
    bool handle_call(Call *call){
        if (_handling==NULL){
            _handling = call;
            cout << _name << " handling call " << _handling->call_id() << endl;
            return true;
        }
        else {
            return false;
        }
    }
    void end_call(){
        if (_handling!=NULL){
            cout << _name << " ending call " << _handling->call_id() << endl;
            delete _handling;
            _handling = NULL;
        }
    }
    void random_action(){
        if (_handling!=NULL){
            double d=(double)rand()/RAND_MAX;
            if (d<0.6) end_call();
            else if (d<0.8) escalate_call();
            // otherwise keep on call
        }
    }
    virtual void escalate_call() = 0; // pure virtual

    virtual ~Employee() {} // base class should include this

};
int Employee::id_next = 1;

class Respondent : public Employee {
    public:
    Respondent(string name, Dispatcher* pd): Employee(name, pd) {}
    void escalate_call(){
        if (_handling!=NULL){
            cout << _name << " escalating call " << _handling->call_id() << " to manager" << endl;
            _dispatcher->add_manager_call(_handling);
            _handling = NULL;
        }
    }
};

class Manager : public Employee {
    public:
    Manager(string name, Dispatcher* pd): Employee(name, pd) {}
    void escalate_call(){
        cout << _name << " escalating call " << _handling->call_id() << " to director" << endl;
        _dispatcher->add_director_call(_handling);
        _handling = NULL;
    }
};

class Director : public Employee {
    public:
    Director(string name, Dispatcher* pd): Employee(name, pd) {}
    void escalate_call(){
        cout << "You have to handle this one yourself" << endl;
    }
};

//class Dispatcher

Dispatcher::Dispatcher(){} // make contructor private
Dispatcher::~Dispatcher(){} // disallow destructor
Dispatcher& Dispatcher::Instance(){ // how to parse this?
    //Instance is a static member function that returns a reference to a Dispatcher?
    static Dispatcher* instance = new Dispatcher; // this line runs only once
    return *instance;
}

Employee* Dispatcher::add_respondent(string name){
    Respondent* respondent = new Respondent(name, this);
    _respondents.push_back(respondent);
    return respondent;
}
Employee* Dispatcher::add_manager(string name){
    Manager* manager = new Manager(name, this);
    _managers.push_back(manager);\
    return manager;
}
Employee* Dispatcher::add_director(string name){
    Director* director = new Director(name, this);
    _directors.push_back(director);
    return director;
}
// delete?

// for use by main()
void Dispatcher::add_incoming_call(Call* call){
    _calls_respondent.push(call);
} 
// for use by Respondent::escalate_call()
void Dispatcher::add_manager_call(Call* call){
    _calls_manager.push(call);
} 
// for use by Manager::escalate_call()
void Dispatcher::add_director_call(Call* call){
    _calls_director.push(call);
} 

void Dispatcher::run(){              
    while (!_calls_director.empty()) {
        Call* call = _calls_director.front();
        if (assign(_directors, call)){
            _calls_director.pop();
        }
        else {
            break;
        }
    }
    while (!_calls_manager.empty()) {
        Call* call = _calls_manager.front();
        if (assign(_managers, call)){
            _calls_manager.pop();
        }
        else {
            break;
        }
    }
    while (!_calls_respondent.empty()) {
        Call* call = _calls_respondent.front();
        if (assign(_respondents, call)){
            _calls_respondent.pop();
        }
        else {
            break;
        }
    }
}

int Dispatcher::total_calls(){
    int queued = _calls_respondent.size()+
                _calls_manager.size()+_calls_director.size();
    int handling = 0;
    vector<Respondent*>::iterator it_r = _respondents.begin();
    while (it_r!=_respondents.end()){
        handling += (*it_r)->isbusy();
        ++it_r;
    }
    vector<Manager*>::iterator it_m = _managers.begin();
    while (it_m!=_managers.end()){
        handling += (*it_m)->isbusy();
        ++it_m;
    }
    vector<Director*>::iterator it_d = _directors.begin();
    while (it_d!=_directors.end()){
        handling += (*it_d)->isbusy();
        ++it_d;
    }
    return queued+handling;
}

template <typename T>
bool Dispatcher::assign(vector<T*> ev, Call* call){
    // find a respondent who is free
    size_t size = ev.size();
    size_t offset = rand()%size;
    for (size_t i=0; i<size; i++){
        T* e=(ev[(i+offset)%size]);
        if (!(e->isbusy())) {
            e->handle_call(call);
            return true;
        }
    }
    return false;
}

int main(){

    Dispatcher& dispatcher = Dispatcher::Instance();

    Employee* r1 = dispatcher.add_respondent("Ron");
    Employee* r2 = dispatcher.add_respondent("Ray");
    Employee* r3 = dispatcher.add_respondent("Rick");
    Employee* r4 = dispatcher.add_respondent("Rob");
    Employee* r5 = dispatcher.add_respondent("Roger");
    Employee* r6 = dispatcher.add_respondent("Ryan");
    Employee* r7 = dispatcher.add_respondent("Rosa");
    Employee* r8 = dispatcher.add_respondent("Rebecca");

    Employee* m1 = dispatcher.add_manager("Mark");
    Employee* m2 = dispatcher.add_manager("Mike");
    Employee* m3 = dispatcher.add_manager("Mindy");
    Employee* m4 = dispatcher.add_manager("Molly");

    Employee* d1 = dispatcher.add_director("Derek");
    Employee* d2 = dispatcher.add_director("Donald");

    for (int i=0; i<100; i++){
        Call *call = new Call;
        dispatcher.add_incoming_call(call);
    }
    dispatcher.run();
    cout << dispatcher.total_calls() << " calls remaining" << endl;

    for (int i=0; i<20; i++) {
        cout << endl;
        r1->random_action();
        r2->random_action();
        r3->random_action();
        r4->random_action();
        r5->random_action();
        r6->random_action();
        r7->random_action();
        r8->random_action();
        m1->random_action();
        m2->random_action();
        m3->random_action();
        m4->random_action();
        d1->random_action();
        d2->random_action();
        dispatcher.run();
        cout << dispatcher.total_calls() << " calls remaining" << endl;
    }
}

