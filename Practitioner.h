#ifndef PRACTITIONER_H
#define PRACTITIONER_H
#include "Patient.h"
#include "ER_Records.h"
#include "Patient_Queue.h"
#include "ER_Simulator.h"

#include "Utility.h"

//extern Random my_random;


class Practitioner {
	friend class ER_Simulator;
protected:
	int is_treating;
	Patient* currently_treating;
	ER_Records * records;
	Patient_Queue * waiting_room;
	void treat_current_patient(int clock);
	virtual void get_new_patient() = 0;

public:
	Patient* get_currently_treating();

	void set_currently_treating(Patient* p);

	virtual void treat(int clock) = 0;
	

	Practitioner(ER_Records * records, Patient_Queue* waiting_room);
};

class Nurse : public Practitioner{
	friend class ER_Simulator;
private:
	const int MAX_TRIAGE = 10;
	const int MAX_TREAT_TIME = 10;
	//void treat_current_patient(int clock); is same as all practitioners
	void get_new_patient();
public:
	Nurse(ER_Records * records2, Patient_Queue* waiting_room2) : Practitioner(records2, waiting_room2){}
	void treat(int clock);

};

class Doctor : public Practitioner{
	friend class ER_Simulator;
private: 
	const int MAX_TRIAGE = 20;
	const int MAX_TREAT_TIME = 20;
	//void treat_current_patient(int clock); // is same as all practitioners
	void get_new_patient();

public:
	Doctor(ER_Records * records2, Patient_Queue* waiting_room2) : Practitioner(records2, waiting_room2){}
	void treat(int clock);
};

#endif
