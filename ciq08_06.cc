// jigsaw puzzle
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::list;
using std::setw;
using std::setfill;

int randi(int i) { return std::rand()%i;}

class Side {
public:
	Side(int sig=0): _signature(sig) {}
	bool fitsWith(Side* s){
		return (s->signature()==this->signature());
	}
	bool boundary(){
		return (_signature==0);
	}
	int signature(){
		return _signature;
	}
private:
	int _signature;
};

class Piece {
public:
	Piece(Side top, Side right, Side bottom, Side left): 
		_top(top), _right(right), _bottom(bottom), _left(left) {}
	void rotate(){
		Side temp=_top;
		_top=_right;
		_right=_bottom;
		_bottom=_left;
		_left=temp;
	}
	Side top() { return _top; }
	Side right() { return _right; }
	Side bottom() { return _bottom; }
	Side left() { return _left; }
private:
	Side _top, _right, _bottom, _left; 
};

class Puzzle {
public:
	Puzzle(const int height, const int width){
		vector<int> rsig;
  		for (int i=1; i<4*width*height-2*width-2*height; ++i) rsig.push_back(i);
  		std::random_shuffle(rsig.begin(), rsig.end(), randi);
		// initialize board
  		board.resize(height, vector<Piece*>(width, NULL));
		for (int i=0; i<height; i++) {
			for (int j=0; j<width; j++) {
				Side top, right, bottom, left;
				if (i>0) { top = (board[i-1][j])->bottom(); }
				if (j<width-1) { right = rsig.back(); rsig.pop_back(); }
				if (i<height-1) { bottom = rsig.back(); rsig.pop_back(); }
				if (j>0) { left = (board[i][j-1])->right(); }
        		board[i][j]=new Piece(top, right, bottom, left);
    		}
		}
	}
	void showboard(){
		cout << "board piece [left,top,bottom,right]" << endl;
		int height = board.size();
		int width = board[0].size(); 
		int w=(int)ceil(log10(4*width*height-2*width-2*height));
		for (vector< vector<Piece*> >::iterator ot=board.begin(); ot!=board.end(); ++ot) {
			for (vector<Piece*>::iterator it= ot->begin(); it!=ot->end(); ++it) {
				if (*it){
					cout << "[" << setfill('0') << setw(w) << ((*it)->left()).signature() << ","; 
					cout << setfill('0') << setw(w) << ((*it)->top()).signature() << ",";
					cout << setfill('0') << setw(w) << ((*it)->bottom()).signature() << ",";
					cout << setfill('0') << setw(w) << ((*it)->right()).signature() << "]";
				} else {
					cout << "[" << setfill('-') << setw(w) << '-' << ",";
					cout << setfill('-') << setw(w) << '-' << ",";
					cout << setfill('-') << setw(w) << '-' << ",";
					cout << setfill('-') << setw(w) << '-' << "]";	
				}
    		}
    		cout << endl;
		}
	}
	void clearboard(){
		for (vector< vector<Piece*> >::iterator ot=board.begin(); ot!=board.end(); ++ot) {
			for (vector<Piece*>::iterator it= ot->begin(); it!=ot->end(); ++it) {
				if (*it){
					unplaced.push_back(*it);
					(*it)=NULL;
				}
			}
		}
		std::random_shuffle(unplaced.begin(), unplaced.end(), randi);
	}
	void showunplaced(){
		cout << "unplaced piece [left,top,bottom,right]" << endl;
		int height = board.size();
		int width = board[0].size(); 
		int w=(int)ceil(log10(4*width*height-2*width-2*height));
		for (vector<Piece*>::iterator it=unplaced.begin(); it!=unplaced.end(); ++it){
			cout << "[" << setfill('0') << setw(w) << ((*it)->left()).signature() << ","; 
			cout << setfill('0') << setw(w) << ((*it)->top()).signature() << ",";
			cout << setfill('0') << setw(w) << ((*it)->bottom()).signature() << ",";
			cout << setfill('0') << setw(w) << ((*it)->right()).signature() << "]";
		}
	}
	void solve(){
		
	}
private:
	vector< vector<Piece*> > board;
	vector<Piece*> unplaced;
};

int main(){
	std::srand(unsigned(std::time(0)));
	Puzzle puzzle(6,10);
	puzzle.showboard();
	puzzle.clearboard();
	puzzle.showboard();
	puzzle.showunplaced();
	puzzle.solve();
}
