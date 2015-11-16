#ifndef UTILITY_H
#define UTILITY_H

#include <ctime>
#include <iostream>
#include <stdexcept>

//sanitizes input that is expected to be an integer



class Random{
private:
public:
	Random(){
		srand(time(NULL));
	}
	
	//returns a double between 0 and 1
	double next_double(){
		double temp;
		temp = rand() / static_cast<double>(RAND_MAX);
		return temp;
	}
	
	//returns an integer between 0 and max-1
	int next_int(int max){
		int temp = rand() % max;
		return temp;
	}

	int read_int()
	{
		int temp;
		std::cin.exceptions(std::ios_base::failbit);
		do{
			try{
				std::cin >> temp;
				return temp;
			}

			catch (std::ios_base::failure &exp){
				std::cout << "Input must be numeric\n";
				std::cin.clear();
				std::cin.ignore(INT_MAX, '\n');
			}
		} while (true);
	}
};


#endif
