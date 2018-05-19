#include <iostream>
#include "surgery.h"
#include "Heap.h"
#include "operatingTheater.h"
//firstFit 
//dum med mer rum
//checkar var objektet f�r plats -->b�st med max heap? 

void firstFit(const surgery operations[],const int nrOfSurgeries, HeapType type,operatingTheater theaters[], const int nrOfTheaters);

//nextFit 461
//does it fit were we put our last objket ->yes->put in same bin 
//=fill until full then take next

void nextFit(const surgery operations[], const int nrOfSurgeries, HeapType type, operatingTheater theaters[], const int nrOfTheaters);

//bestFit
//put in tightest spot right now. 

void bestFit(const surgery operations[], const int nrOfSurgeries, HeapType type, operatingTheater theaters[], const int nrOfTheaters);

	operatingTheater OT;
	OT.addSurgerysFromFile();

int main() {

	for (int i = 0; i < 1000; i++)
	{
		std::cout << "Mohahahahaha \n" << std::endl;
		system("CLS");
	}
	/*the Bin packing problem, se kap 10.1.3*/

	return 0;
}

void firstFit(const surgery operations[], const int nrOfSurgeries, HeapType type, operatingTheater theaters[], const int nrOfTheaters)
{
	Heap<surgery>sortedOperations(type) ;

	for (int i = 0; i < nrOfSurgeries; i++) {
		sortedOperations.insert(operations[i], operations[i].getTimeEstimate());
	}

	bool added = false;
	do
	{
		bool added = false;

		for (int i = 0; i < nrOfSurgeries; i++) {

			if (sortedOperations.peek().getTimeEstimate() <= theaters[i].getSchedueldTime()) {
				theaters[i].addSurgery(sortedOperations.extract());
				i = nrOfSurgeries;
				bool added = true;
			}
		}
		
	} while (added == true);
	
}


void nextFit(const surgery operations[], const int nrOfSurgeries, HeapType type, operatingTheater theaters[], const int nrOfTheaters)
{

}

void bestFit(const surgery operations[], const int nrOfSurgeries, HeapType type, operatingTheater theaters[], const int nrOfTheaters)
{

}
