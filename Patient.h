#ifndef PATIENT_H
#define PATIENT_H

#include<string>
#include "Utility.h"


extern Random my_random;


class Patient
{
private:
	std::string name;
	int triage_rating;
	int arrival_time;
public:
	Patient(std::string name, int clock);
	Patient(const Patient &other);
	Patient& operator=(Patient other);
	~Patient();
	std::string get_name();
	int get_arrival_time();
	int set_triage();
	bool operator>(Patient &other);
	bool operator<(Patient &other);
	int get_triage_number();

};


#endif