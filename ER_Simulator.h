#ifndef ER_SIMULATOR_H
#define ER_SIMULATOR_H

#include "Practitioner.h"
#include "Patient_Queue.h"
#include "ER_Records.h"
#include "Utility.h"
#include<vector>
#include<string>

//Random my_random;

class ER_Simulator{
private:
	int clock;
	ER_Records records; //everything else called records points to this
	std::vector<Practitioner*> staff;
	std::vector<std::string> citizens;
	
	int patients_per_hour;
	
public:
	Patient_Queue waiting_room = Patient_Queue(&records, patients_per_hour);
	ER_Simulator::ER_Simulator(int number_of_doctors, int number_of_nurses, int patients_per_hour, std::string filename);
	void update();
	void enter_data();
	void run_simulation(int CLOCK_MAX); //CLOCK_MAX = 10080 minutes
	void check_new_arrival(std::string name);

};

#endif