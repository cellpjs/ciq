#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <ctime>


using namespace std;

enum suit_t {None, Spades, Clubs, Hearts, Diamonds};
enum rank_t {Zero, Ace, Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King};

class Card {
    suit_t s;
    rank_t r;

    public:
    Card(suit_t _s, rank_t _r): s(_s), r(_r) { }

    string to_string() {
        string rname, sname;
        switch(s){
            case Spades : sname = "Spades"; break;
            case Clubs : sname = "Clubs"; break;
            case Hearts : sname = "Hearts"; break;
            case Diamonds : sname = "Diamonds"; break;
            default : sname = "N";
        }
        switch(r){
            case Ace : rname = "A"; break;
            case Two : rname = "2"; break;
            case Three : rname = "3"; break;
            case Four : rname = "4"; break;
            case Five : rname = "5"; break;
            case Six : rname = "6"; break;
            case Seven : rname = "7"; break;
            case Eight : rname = "8"; break;
            case Nine : rname = "9"; break;
            case Ten : rname = "10"; break;
            case Jack : rname = "J"; break;
            case Queen : rname = "Q"; break;
            case King : rname = "K"; break;
            default : rname = "0";
        }
        string cname = rname+" of "+sname;
        return cname;
    }

    suit_t get_suit(){
        return s;
    }
    rank_t get_rank(){
        return r;
    }

};

class Deck_of_Cards {

    vector<Card> deck;

    void populate_deck(){
        for (int i=Spades; i<=Diamonds; i++){
            for (int j=Ace; j<=King; j++){
                Card c((suit_t)i, (rank_t)j);
                deck.push_back(c);
            }
        }
    }

    public:
    Deck_of_Cards(){
        populate_deck();
    }

    void shuffle(){
        random_shuffle(deck.begin(), deck.end());
    }

    Card deal(){
        if (!deck.empty()) {
            Card c = deck.back();
            deck.pop_back();
            return c;
        }
        else return Card(None, Zero);
    }

    int size(){
        return deck.size();
    }

    bool empty(){
        return deck.empty();
    }

    void reset(){
        deck.clear();
        populate_deck();
    }

};

class Hand {

    protected:

    list<Card> cardlist;

    public:

    virtual void receive(Card c){
        cardlist.push_back(c);
    }

    virtual void reset(){
        cardlist.clear();
    }

    int size(){
        return cardlist.size();
    }

    bool empty(){
        return cardlist.empty();
    }

    void show_cards(){
        for (list<Card>::iterator it=cardlist.begin(); it!=cardlist.end(); ++it){
            cout << (*it).to_string() << endl;
        }
    }
};

class HandBlackjack : public Hand {

    int total, total_alt, points;

    int value(Card c){
        int val;
        switch(c.get_rank()){
            case Ace : val = 1; break;
            case Two : val = 2; break;
            case Three : val = 3; break;
            case Four : val = 4; break;
            case Five : val = 5; break;
            case Six : val = 6; break;
            case Seven : val = 7; break;
            case Eight : val = 8; break;
            case Nine : val = 9; break;
            case Ten : val = 10; break;
            case Jack : val = 10; break;
            case Queen : val = 10; break;
            case King : val = 10; break;
            default : val = 0;
        }
        return val;
    }

    public:

    HandBlackjack() : total(0), total_alt(0), points(0) {}

    void receive(Card c){
        //cout << "before: " << total << ", " << total_alt << endl;
        cardlist.push_back(c);
        total+=value(c);
        total_alt+=value(c);
        //cout << "after: " << total << ", " << total_alt << endl;
        if (c.get_rank() == Ace) total_alt+=10;
        if (total>21) {
            points = 0;
        }
        else if (total_alt>21){
            points = total;
        }
        else {
            points = total_alt;
        }
    }

    int get_points(){
        return points;
    }

    void reset(){
        cardlist.clear();
        total = 0;
        total_alt = 0;
        points = 0;
    }

};

class Game {

    protected:

    Deck_of_Cards doc;

    public:

    virtual void play(){}

};


class GameBlackjack : Game {

    HandBlackjack player, dealer;

    int balance;

    public:

    GameBlackjack() : balance(10) { }

    void play(){

        char entered;

        doc.shuffle();

        cout << "Welcome to Blackjack!\n" << endl;

        cout << "You have $" << balance << " dollars.\n" << endl;

        do {

            cout << "Let's play Blackjack!\n" << endl;

            player.reset();
            dealer.reset();

            if (doc.size()<12){
                doc.reset();
                doc.shuffle();
                cout << "deck reset\n" << endl;
            }

            player.receive(doc.deal());
            dealer.receive(doc.deal());
            player.receive(doc.deal());
            dealer.receive(doc.deal());

            cout << "<dealer>" << endl;
            dealer.show_cards();
            cout << dealer.get_points() << " points\n" << endl;

            cout << "<player>" << endl;
            player.show_cards();
            cout << player.get_points() << " points\n" << endl;

            /* hit or stay */
            while(player.get_points()!=0 && player.get_points()!=21) {
                do {
                cout << "hit or stay? [h/s]" << endl;
                cin >> entered;
                } while( !cin.fail() && entered!='h' && entered!='s' );

                if (entered=='h'){
                    player.receive(doc.deal());
                    player.show_cards();
                    cout << player.get_points() << " points\n" << endl;
                }
                else {
                    break;
                }
            }
            cout << "<player final>" << endl;
            player.show_cards();
            cout << player.get_points() << " points\n" << endl;

            /* dealer play */
            while (dealer.get_points()!=0 && dealer.get_points() < 17){
                dealer.receive(doc.deal());
            }
            cout << "<dealer final>" << endl;
            dealer.show_cards();
            cout << dealer.get_points() << " points\n" << endl;

            if (player.get_points()>dealer.get_points()){
                cout << "You won!\n" << endl;
                balance+=1;
            }
            else if (player.get_points()==dealer.get_points()){
                cout << "It's a push.\n" << endl;
            }
            else {
                cout << "You lost.\n" << endl;
                balance-=1;
            }
            cout << "You have $" << balance << " dollars.\n" << endl;

            if (balance>0) {
                do {
                cout << "play again? [y/n]" << endl;
                cin >> entered;
                } while( !cin.fail() && entered!='y' && entered!='n' );
            }
            else {
                entered='n';
            }
            cout << endl;
        } while (entered=='y');
        cout << "Your final balance is $" << balance << " dollars.\n" << endl;
    }
};

class TestDeck{

    Deck_of_Cards doc;

    public:
    void test(){

        cout << "Testing Deck of Cards\n" << endl;

        while (!doc.empty()) {
            Card c = doc.deal();
            cout << c.to_string() << endl;
        }
        cout << endl;

        doc.reset();
        doc.shuffle();

        Hand h1, h2;

        h1.receive(doc.deal());
        h2.receive(doc.deal());
        h1.receive(doc.deal());
        h2.receive(doc.deal());

        h1.show_cards();
        cout << endl;

        h2.show_cards();
        cout << endl;
    }

};


int main(){

    srand(time(NULL));

    /*
    TestDeck td;
    td.test();
    */

    GameBlackjack bj;
    bj.play();

}

