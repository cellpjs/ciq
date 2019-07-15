// musical juke box

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

class JukeBox {
	int _num_credits;
	std::queue<int> _playlist;
	std::vector<int> _songlist;

	public:
	JukeBox(): _num_credits(0) {}
	void add_song(int song_number){
		_songlist.push_back(song_number);
	}
	void add_coin(){
		_num_credits++;
	}
	void select_song(int song_number){
		if (_num_credits>0) {
			if (std::find(_songlist.begin(), _songlist.end(), song_number)!=_songlist.end()) {
				_playlist.push(song_number);
				_num_credits--;
			}
			else {
				std::cout << "song not found" << std::endl;
			}
		}
		else {
			std::cout << "please insert coin" << std::endl;
		}
	}
	void play_song(){
		if (!_playlist.empty()){
			std::cout << "playing song " << _playlist.front() << std::endl;
			_playlist.pop();
		}
		else {
			std::cout << "playlist empty" << std::endl;
		}
	}
	int num_credits() const{
		return _num_credits;
	}
};

int main(){

	JukeBox box;

	for (int i=1; i<=24; i++){
		box.add_song(i);
	}

	box.add_coin();
	std::cout << "credits: " << box.num_credits() <<std::endl;
	box.select_song(5);
	box.play_song();
	std::cout << "credits: " << box.num_credits() <<std::endl;
	box.add_coin();
	box.add_coin();
	std::cout << "credits: " << box.num_credits() <<std::endl;
	box.play_song();
	box.select_song(100);
	box.select_song(20);
	box.select_song(11);
	box.play_song();
    box.play_song();
    box.play_song();
    box.select_song(7);

}