// jigsaw puzzle

#include <iostream>
#include <string>
#include <vector>
#include <list>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::list;

class Side{
public:
	bool fitsWith(PuzzleSide s){
		return (s.signature()==this.signature());
	}
	bool signature(){
		return _signature;
	}
	bool boundary(){
		return (_signature==0);
	}

private:
	int _signature;
};

class Piece {
public:
	Piece(){
		// initialize sides;
	}
	void rotate(){
		// circular shift on the array
	}
	bool put(int x, int y){
		// if fitsWith()...
	}

private:
	Side sides[4]; 

};

class Puzzle {
public:
	Puzzle(const int width, const int height){

	}
	void solve(){}

private:
	vector<vector<Piece>> pieces;

};


int main(){

	Puzzle puzzle(100,150);

	puzzle.solve();

}