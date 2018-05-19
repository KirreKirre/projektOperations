#include <iostream>
#include "surgery.h"
#include "Heap.h"
#include "operatingTheater.h"
//firstFit 
//dum med mer rum
//checkar var objektet får plats -->bäst med max heap? 

void firstFit(const surgery operations[], const int nrOfSurgeries, HeapType type, operatingTheater theaters[], const int nrOfTheaters);

//nextFit 461
//does it fit were we put our last objket ->yes->put in same bin 
//=fill until full then take next

void nextFit(const surgery operations[], const int nrOfSurgeries, HeapType type, operatingTheater theaters[], const int nrOfTheaters);

//bestFit
//put in tightest spot right now. 

void bestFit(const surgery operations[], const int nrOfSurgeries, HeapType type, operatingTheater theaters[], const int nrOfTheaters);

surgery* readFromFile();

int main() {


	/*the Bin packing problem, se kap 10.1.3*/

	return 0;
}

void firstFit(const surgery operations[], const int nrOfSurgeries, HeapType type, operatingTheater theaters[], const int nrOfTheaters)
{
	Heap<surgery>sortedOperations(type);

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
	Heap<surgery>sortedOperations(type);

	for (int i = 0; i < nrOfSurgeries; i++) {
		sortedOperations.insert(operations[i], operations[i].getTimeEstimate());
	}
	//

}

void bestFit(const surgery operations[], const int nrOfSurgeries, HeapType type, operatingTheater theaters[], const int nrOfTheaters)
{

}

surgery * readFromFile()
{
	ifstream surgeryFile("Operationer_1a.txt"); /*Statiskt namn*/
	string line;
	string idString;
	string speciality;
	string timeString;
	surgery* surgeryList = new surgery[30]; //dynamic

	if (surgeryFile.is_open())
	{
		int i = 0;
		while (std::getline(surgeryFile, line))
		{
			idString = line.substr(0, line.find(','));
			speciality = line.substr(line.find(',') + 1, (line.find_last_of(',') - line.find_first_of(',') - 1));
			timeString = line.substr(line.find_last_of(',') + 1, (line.length() - line.find_last_of(',')));

			int id = std::stoi(idString, nullptr);
			int time = std::stoi(timeString, nullptr);
			surgeryList[i] = surgery(id, speciality, time);
		}
	}
	return surgeryList;
}
