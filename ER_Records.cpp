#include "ER_Records.h"
#include <iostream>

const bool IN_TESTING = true;

ER_Records::ER_Records(){
	total_visit_count = 0;
	total_visit_time = 0;
}

bool ER_Records:: is_in_ER(std::string name){
	bool temp;
	temp = patients_in_ER.count(name);
	return (temp); //0 is false, not zero is true
}

void ER_Records::new_ER_arrival(std::string name){ // adds to is_in_ER
	patients_in_ER.insert(name);
}

void ER_Records::ER_departure(std::string name){ // removes person from ER
	patients_in_ER.erase(name);
}



void ER_Records::add_record(std::string name, int triage_number, int visit_time){ // modifies patient records and patient names 
	patient_records.insert(make_pair(name, triage_number));
	patient_names.insert(name);
	total_visit_time += visit_time;
	total_visit_count++;
}

void ER_Records::show_patient_record(std::string name){
	std::multimap<std::string, int>::iterator it;
		for (it = patient_records.lower_bound(name); it != patient_records.upper_bound(name); ++it)
			/*if (IN_TESTING)
			{
			std::cout << name << " ";
			}*/
			std::cout << it->first << ": " << it->second << std::endl; //pseudo code doesn’t need perfect syntax. will deal with syntax later

}

void ER_Records::list_patients(){
	std::set<std::string>::iterator it;
		for (it = patient_names.begin(); it != patient_names.end(); ++it){
		std::cout << *it << std::endl;
		}
	return;
}


void ER_Records::show_visit_time_info(){
	std::cout << "Total time : " << total_visit_time << std::endl;
	std::cout << "Total visits : " << total_visit_count << std::endl;
	double average = static_cast<double>(total_visit_time) / total_visit_count;
	std::cout << "Average visit time : " << average << std::endl; //possibly add iomanip later to modify how the double is displayed

}




