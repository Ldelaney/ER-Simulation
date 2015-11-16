#include "Practitioner.h"


Practitioner::Practitioner(ER_Records *records2, Patient_Queue * waiting_room2)
{
	this->records = records2;
	this->waiting_room = waiting_room2;
	this->currently_treating = NULL;
}

Patient* Practitioner::get_currently_treating(){
	return currently_treating;
}
void Practitioner::set_currently_treating(Patient* patient){
	this->currently_treating = patient;
}
//nurses and doctors treat a current patient the same way
void Practitioner::treat_current_patient(int clock){
	if (is_treating == 0)
	{
		int visit_time;
		visit_time = clock - currently_treating->get_arrival_time();
		records->add_record(currently_treating->get_name(), currently_treating->get_triage_number(), visit_time);
		records->ER_departure(currently_treating->get_name());
		Patient* temp = currently_treating;
		currently_treating = NULL;
		delete temp;

		currently_treating = NULL;
		
		

	}
	else
	{
		is_treating--;
	}
}

void Nurse::treat(int clock){
	if (currently_treating != NULL){
		treat_current_patient(clock);
	}
	else{
		bool flag = Practitioner::waiting_room->n_queue_empty(); //separated to a bool flag for debugging
		if(!flag){
			get_new_patient();
		}
	}
}

void Nurse::get_new_patient(){
	
	Patient* temp = Practitioner::waiting_room->nurse_queue.top();
	this->currently_treating = temp;
	Practitioner::waiting_room->nurse_queue.pop();
	records->new_ER_arrival(currently_treating->get_name());
	is_treating = my_random.next_int(MAX_TREAT_TIME) + 1; //FIXME: add next_int utility //+1 means the patient is not actually treated this minute and it takes a mintute for the nurse to do paperwork / get the patient. 
}

void Doctor::treat(int clock){
	if (currently_treating != NULL){
		treat_current_patient(clock);
	}
	else{
		if (!Practitioner::waiting_room->d_queue_empty() || !Practitioner::waiting_room->n_queue_empty())
		{
			get_new_patient();
		}
	}

}

void Doctor::get_new_patient(){
	if (!Practitioner::waiting_room->doctor_queue.empty())
	{
		this->currently_treating = Practitioner::waiting_room->doctor_queue.top();
		Practitioner::waiting_room->doctor_queue.pop();
		records->new_ER_arrival(currently_treating->get_name());
		is_treating = my_random.next_int(MAX_TREAT_TIME) + 1;
	}
	else if (!Practitioner::waiting_room->nurse_queue.empty()) //this function only gets called if there is a patient in at least one queue, so the if on this else is not really needed
	{
		this->currently_treating = Practitioner::waiting_room->nurse_queue.top();
		Practitioner::waiting_room->nurse_queue.pop();
		records->new_ER_arrival(currently_treating->get_name());
		is_treating = my_random.next_int(MAX_TREAT_TIME) + 1;
	}
}