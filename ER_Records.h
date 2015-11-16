#ifndef ER_RECORDS_H
#define ER_RECORDS_H

#include<string>
#include<map>
#include<set>

class ER_Records {
private:
	std::multimap <std::string, int> patient_records; // string is the name, int is the triage number
	std::set<std::string> patients_in_ER; // patients currently in ER
	std::set<std::string> patient_names; // patients who have ever been in ER
	int total_visit_count = 0; //Why not initializing?
	int total_visit_time = 0;

public:
	ER_Records();
	bool is_in_ER(std::string name);
	void new_ER_arrival(std::string name); // adds to is_in_ER
	void ER_departure(std::string name); // removes person from ER
	void add_record(std::string name, int triage_number, int visit_time); // modifies patient records and patient names 
	void show_patient_record(std::string name);
	void list_patients();
	void show_visit_time_info();
};

#endif