// design the data structure for an online book reader system

#include <iostream>
#include <string>
#include <map>

using std::string;
using std::cout;
using std::cin;
using std::endl;

class Book {
	string _title;
	string _author;

	public:
	Book(string title, string author): _title(title), _author(author) {}
	Book() {}; // default constructor must be provided 
	// it is implicitly called by _books[id]
	string to_s(){
		return "\"" + _title + "\" by " + _author; 
	}
};

class User {
	string _name;

	public:
	User(string name): _name(name) {};
	User() {};
	string to_s(){
		return _name;
	}
}; 

class BookCatalog {
	int _next_id;
	std::map<int, Book> _books;

	public:
	BookCatalog(): _next_id(1) {};
	void add_book(string title, string author){
		Book book(title, author);
		_books.insert(std::make_pair(_next_id, book));
		_next_id++;
	}
	void show_books(){
		for (std::map<int,Book>::iterator it=_books.begin(); it!=_books.end(); ++it){
    		cout << it->first << " => " << (it->second).to_s() << '\n';
    	}
	}
	void remove_book(int id){
		_books.erase(id);
	}
	Book* get_book_ptr(int id) {
		if (_books.count(id)){
			return &(_books[id]);
		}
		else {
			return NULL;
		}
	}


};

class UserRegistry {
	int _next_id;
	std::map<int, User> _users;

	public:
	UserRegistry(): _next_id(1) {};
	void add_user(string name){
		User user(name);
		_users.insert(std::make_pair(_next_id, user));
		_next_id++;
	}
	void show_users(){
		for (std::map<int,User>::iterator it=_users.begin(); it!=_users.end(); ++it){
    		cout << it->first << " => " << (it->second).to_s() << '\n';
    	}
	}
	void remove_user(int id){
		_users.erase(id);
	}
	User* get_user_ptr(int id) {
		if (_users.count(id)){
			return &(_users[id]);
		}
		else {
			return NULL;
		}
	}
};

class Session {
	User _user;
	Book _book;
	
	public:
	Session(User user, Book book): _user(user), _book(book) {};
	Session() {};
	string to_s(){
		return _user.to_s() + " is reading " + _book.to_s();
	}

};

class SessionManager {
	int _next_id;
	std::map<int, Session> _sessions;
	UserRegistry* _user_registry;
	BookCatalog* _book_catalog;
	
	public:
	SessionManager(UserRegistry* ur, BookCatalog* bc): _next_id(1)
	, _user_registry(ur), _book_catalog(bc) {};
	void add_session(int user_id, int book_id){
		User* user_ptr = _user_registry->get_user_ptr(user_id);
		Book* book_ptr = _book_catalog->get_book_ptr(book_id); 
		if (user_ptr==NULL){
			cout << "user not found" << endl;
		}
		else if (book_ptr==NULL){
			cout << "book not found" << endl;
		}
		else {
			Session session(*user_ptr, *book_ptr);
			_sessions.insert(std::make_pair(_next_id, session));
			_next_id++;
		}
	}
	void show_sessions(){
		for (std::map<int, Session>::iterator it=_sessions.begin(); it!=_sessions.end(); ++it){
    		cout << it->first << " => " << (it->second).to_s() << '\n';
    	}
	}
	void remove_session(int id){
		_sessions.erase(id);
	}
};

int main(){

	BookCatalog* book_catalog = new BookCatalog();
	book_catalog->add_book("The Cat In The Hat", "Dr. Seuss");
	book_catalog->add_book("The Lorax", "Dr. Seuss");
	book_catalog->add_book("Knuffle Bunny", "Mo Willems");
	book_catalog->add_book("The Very Hungry Caterpillar", "Eric Carle");
	book_catalog->add_book("Good Night Moon", "Margaret Wise Brown");
	book_catalog->add_book("Millions Of Cats", "Wanda Gag");
	book_catalog->remove_book(2);
	book_catalog->show_books();
	cout << endl;
	UserRegistry* user_registry = new UserRegistry();
	user_registry->add_user("Anna");
	user_registry->add_user("Emma");
	user_registry->add_user("Curt");
	user_registry->add_user("Noah");
	user_registry->show_users();
	cout << endl;
	SessionManager* session_manager = new SessionManager(user_registry, book_catalog);
	session_manager->add_session(1,1);
	session_manager->add_session(4,3);
	session_manager->show_sessions();
	cout << endl;
	session_manager->remove_session(1);
	session_manager->add_session(2,1);
	session_manager->show_sessions();

	delete session_manager;
	delete user_registry;
	delete book_catalog;

}