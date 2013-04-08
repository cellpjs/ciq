// parking lot

// for simplicity: forget once a car leaves
// instead of remembering past transactions 

#include <iostream>
#include <string>
#include <list>
#include <ctime>
#include <unistd.h>

class ParkedVehicle {
	int _ticket_number;
	time_t _time_in;

	public:
	ParkedVehicle(time_t t_in, int tn): _time_in(t_in), _ticket_number(tn) {}

	int ticket_number() const {
		return _ticket_number;
	}

	time_t time_in() const {
		return _time_in;
	}
};

class ParkingLot {
	const int _capacity;
	int _next_ticket_number;
	int _fees_collected;
	std::list<ParkedVehicle> _vehicles;

	public:
	ParkingLot(int cap): _capacity(cap), _next_ticket_number(1), _fees_collected(0) {}

	int accept_vehicle(){
		int ticket_number = _next_ticket_number;
		ParkedVehicle v_in(time(NULL), ticket_number); // new and pointer?
		_next_ticket_number++; // how to reuse?
		_vehicles.push_back(v_in);
		std::cout << ticket_number << " entered" << std::endl;
	}

	void sendoff_vehicle(int ticket_number){
		// look up the list by ticket_number
		std::list<ParkedVehicle>::iterator it;
		for (it=_vehicles.begin(); it!=_vehicles.end(); ++it){
    		if (it->ticket_number()==ticket_number) break;
  		}
  		if (it==_vehicles.end()) {
  			std::cout << "ticket number not found" << std::endl;
  		}
  		else {
  			int fee = amount_due(it->time_in(),time(NULL));
  			_fees_collected+=fee;
  			_vehicles.erase(it);
  			std::cout << ticket_number << " exited ($" << fee << " collected)" << std::endl;
    	}  		
	}

	void view_parked_vehicles() const {
		std::cout << "# : time_in" << std::endl;
		std::list<ParkedVehicle>::const_iterator it;
		for (it=_vehicles.begin(); it!=_vehicles.end(); ++it){
			time_t t = it->time_in();
			std::cout << it->ticket_number() << " : " << ctime(&t) << std::endl;
   		}
	}

	int fees_collected(){
		return _fees_collected;
	}

	private:
	int amount_due(time_t t_in, time_t t_out){
		double dsec = difftime(t_out, t_in);
		return (int)dsec; // 1 dollars per second!
	}

};


int main(){

	ParkingLot lot(20);

	lot.accept_vehicle(); 
	sleep(1);
	lot.accept_vehicle();
	sleep(1);
	lot.accept_vehicle();
	sleep(1);
	lot.accept_vehicle();
	sleep(1);
	lot.sendoff_vehicle(2);
	sleep(1);
	lot.accept_vehicle();
	sleep(1);
	lot.accept_vehicle();
	sleep(1);
	lot.sendoff_vehicle(3);
	sleep(1);
	lot.accept_vehicle();
	sleep(1);
	lot.sendoff_vehicle(1);
	sleep(1);
	lot.accept_vehicle();
	sleep(1);
	lot.accept_vehicle();
	sleep(1);
	lot.sendoff_vehicle(4);
	sleep(1);
	lot.sendoff_vehicle(7);
	lot.view_parked_vehicles();

	std::cout << "total $" << lot.fees_collected() << " collected so far" << std::endl;


}