#include "Patient.h"


Patient::Patient(std::string name, int clock){
	this->name = name;
	this->arrival_time = clock;
	this->triage_rating = set_triage();
}

Patient::Patient(const Patient &other){
	this->name = other.name;
	this->arrival_time = other.arrival_time;
	this->triage_rating = other.triage_rating;
}

Patient::~Patient(){
	 //doesn't point to anything that needs to be deleted first
}


Patient& Patient::operator=(Patient other){
	Patient copy(other);

	//SWAP!
	int  temp_arrival_time;
	int  temp_triage_rating;
	std::string temp_name;

	temp_arrival_time = this->arrival_time;
	temp_triage_rating = this->triage_rating;
	temp_name = this->name;

	this->name = copy.name;
	this->arrival_time = copy.arrival_time;
	this->triage_rating = copy.triage_rating;

	copy.name = temp_name;
	copy.arrival_time = temp_arrival_time;
	copy.triage_rating = temp_triage_rating;

	//copy is deleted at the end
	//if there were pointers, we would delete the temp_pointer variables

	//Done with SWAP

	return *this;

}


std::string Patient::get_name(){
	return this->name;
}

int Patient::get_arrival_time(){
	return this->arrival_time;
}

int Patient::set_triage(){
	int percent = my_random.next_int(10);
	if (percent < 7)
		return 1 + my_random.next_int(10);
	else if (percent < 9)
		return 11 + my_random.next_int(5);
	else
		return 16 + my_random.next_int(5);
}

bool Patient::operator>(Patient &other){
	return (this->triage_rating > other.triage_rating);
}

bool Patient::operator<(Patient &other){
	return (this->triage_rating < other.triage_rating);
}

int Patient::get_triage_number(){
	return this->triage_rating;
}