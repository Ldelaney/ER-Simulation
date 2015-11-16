#include "ER_Simulator.h"
#include<fstream>



ER_Simulator::ER_Simulator(int number_of_doctors, int number_of_nurses, int patients_per_hour, std::string filename){

	this->patients_per_hour = patients_per_hour;
	this->clock = 0;

	Patient_Queue tempPQ(&records, patients_per_hour);
	this->waiting_room = tempPQ;

	Patient_Queue* wait_room = &(this->waiting_room);

	for (int i = 0; i < number_of_nurses; ++i)
	{
		Practitioner* new_staff = new Nurse(&records, wait_room);
		staff.push_back(new_staff);
	}
	for (int i = 0; i < number_of_doctors; ++i)
	{
		staff.push_back(new Doctor(&records, &(this->waiting_room)));
	}

	std::ifstream fin;
	fin.open(filename);
	if (fin.fail())
	{
		std::cout << "Failed to open file of citizen names\n";
		throw 404; //file not found
	}

	std::string temp_name;
	while (!fin.eof())
	{
		fin >> temp_name;
		citizens.push_back(temp_name);
	}

	fin.close();

	
	
}


void ER_Simulator::update(){
	//clock is incremented in the for loop a level higher than this
	
	std::string name;
	do{
		name = citizens[my_random.next_int(citizens.size())];
	} while (records.is_in_ER(name));
	
	check_new_arrival(name);

	for (int i = 0; i < staff.size(); ++i)
	{
		staff[i]->treat(clock);
	}

}


void ER_Simulator::check_new_arrival(std::string name){
	double temp;
	temp = my_random.next_double();

	if (temp < waiting_room.get_arrival_rate())
	{
		Patient * new_arrival = new Patient(name, clock);
		waiting_room.push(new_arrival);
	}
}



void ER_Simulator::run_simulation(int CLOCK_MAX){
	for (this->clock = 0; this->clock < CLOCK_MAX; ++clock)
	{
		update();
	}

	std::cout << "SIMULATION COMPLETE!\n";
	int choice;
	std::string name;

	do{
		do{
			std::cout << "\nChoose a menu option: \n" << "1) list all patients treated\n";
			std::cout << "2) search for a patient record by name\n" << "3) view visit time statistics\n" << "4) exit\n";
			choice = my_random.read_int();
		} while (choice > 4 || choice < 1);
		switch (choice)
		{
		case 1:
			records.list_patients();
			break;
		case 2:
			
			std::cout << "Please enter the name of the patient (CASE SENSITIVE): ";
			std::cin >> name;
			records.show_patient_record(name);
			break;
		case 3:
			records.show_visit_time_info();
			break;
		case 4:
			return;
		default: 
			return;
		}

	} while (choice != 4);

	return;
}