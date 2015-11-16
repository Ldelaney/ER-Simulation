#ifndef PATIENT_QUEUE_H
#define PATIENT_QUEUE_H
#include "Patient.h"
#include "ER_Records.h"
#include "Practitioner.h"
#include<queue>


class Patient_Queue{
	friend class Practitioner; //friendship is not inherited. 
	friend class Nurse;
	friend class Doctor;
private:
	std::priority_queue<Patient*> nurse_queue;
	std::priority_queue<Patient*> doctor_queue;
	double arrival_rate;
	ER_Records *records;
public:
	Patient_Queue(ER_Records *records, int patients_per_hour){
		this->arrival_rate = (patients_per_hour / 60.00); //its a double
		this->records = records;
		std::cout << "both queues are empty, right? " << nurse_queue.empty() << " " << doctor_queue.empty() << std::endl;
	}

	Patient_Queue(const Patient_Queue &other){
		this->arrival_rate = other.arrival_rate;
		this->nurse_queue = other.nurse_queue;
		this->doctor_queue = other.doctor_queue;
		this->records = other.records;
	}

	Patient_Queue& operator=(Patient_Queue &other){
		Patient_Queue temp(this->records, (this->arrival_rate*60));
		temp.arrival_rate = this->arrival_rate;
		temp.nurse_queue = this->nurse_queue;
		temp.doctor_queue = this->doctor_queue;
		temp.records = this->records;
		 
		this->arrival_rate = other.arrival_rate;
		this->nurse_queue = other.nurse_queue;
		this->doctor_queue = other.doctor_queue;
		this->records = other.records;

		return *this;
	}

	~Patient_Queue(){
	}

	double get_arrival_rate(){
		return this->arrival_rate;
	}
	bool n_queue_empty()
	{
		return nurse_queue.empty();
	}
	bool d_queue_empty()
	{
		return doctor_queue.empty();
	}
	void push(Patient* new_arrival)
	{
		/*if (IN_TESTING)
		{
			std::cout << "A patient named " << new_arrival->get_name() << " with a triage rating of " << new_arrival->get_triage_number() << " has arrived\n";
		}*/

		if (new_arrival->get_triage_number() <= 10)
		{
			nurse_queue.push(new_arrival);
		}
		else
		{
			doctor_queue.push(new_arrival);
		}
	}

};


#endif
 