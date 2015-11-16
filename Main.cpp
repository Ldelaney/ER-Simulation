#include"ER_Simulator.h"

using namespace std;

Random my_random;

int main(){
	string filename = "residents_273ville.txt";
	int CLOCK_MAX = 10080;

	cout << "Enter the number of nurses: ";
	int num_nurses = my_random.read_int();

	cout << "Enter the number of doctors: ";
	int num_doctors = my_random.read_int();

	cout << "Enter the number of patients per hour: ";
	int patients_per_hour = 60; // has to be initialized for the do/while loop
	do{
		patients_per_hour = my_random.read_int();
	} while (patients_per_hour >= 60);

	ER_Simulator simulation(num_doctors, num_nurses, patients_per_hour, filename);

	simulation.run_simulation(CLOCK_MAX);
}