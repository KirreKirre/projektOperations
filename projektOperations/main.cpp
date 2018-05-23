#include <iostream>
#include "surgery.h"
#include "Heap.h"
#include "operatingTheater.h"
#include <string>
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


void displaySchedule(const operatingTheater theaters[],const int nrOfTheaters,HeapType type,const int nrOfSurgeries);

surgery* readFromFile(int &nrOfoperations);

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

		for (int i = 0; i < nrOfSurgeries/*nrOfTheaters*/; i++) {
			//Adds the first one in line to the room most to the "left", if it fits
			if (sortedOperations.peek().getTimeEstimate() <= theaters[i].getNonSchedueldTime()) {
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
	//Adds the first one in line to the room a "counter" is currently on, if it fits. (Indeed, it never checks the first ones again)
	int atIndex = 0;
	while (atIndex < nrOfTheaters)
	{
		if (sortedOperations.peek().getTimeEstimate() <= theaters[atIndex].getNonSchedueldTime())
		{
			theaters[atIndex].addSurgery(sortedOperations.extract());
		}
		else
		{
			atIndex++;
		}
	}
}

void bestFit(const surgery operations[], const int nrOfSurgeries, HeapType type, operatingTheater theaters[], const int nrOfTheaters)
{
	Heap<surgery>sortedOperations(type);

	for (int i = 0; i < nrOfSurgeries; i++) {
		sortedOperations.insert(operations[i], operations[i].getTimeEstimate());
	}

	bool added = false;
	do
	{
		bool added = false;
		int delta = 0;
		int indexForDelta = -1;
		for (int i = 0; i < nrOfTheaters; i++)
		{
			int roomDelta = theaters[i].getNonSchedueldTime() - sortedOperations.peek().getTimeEstimate();
			if (roomDelta >= 0) /*Makes sure delta is positive and therefore fits*/
			{
				if (roomDelta == 0) /*If it fits perfectly stop the for-loop*/
				{
					indexForDelta = 0;
					i = nrOfTheaters;
				}
				else
				{
					if (roomDelta < delta || delta == 0) /*if it fits better in this room or, if delta hasnt been changed yet*/
					{
						delta = roomDelta;
						indexForDelta = i;
					}
				}
			}
		}
		if (indexForDelta >= 0) /*If indexForDelta has been changed*/
		{
			theaters[indexForDelta].addSurgery(sortedOperations.extract());
			bool added = true;
		}

	} while (added);
}

void displaySchedule(const operatingTheater theaters[], const int nrOfTheaters, HeapType type, const int nrOfSurgeries)
{
	/////RELEVANT INFO

	int unplaned = nrOfSurgeries;
	for (int i = 0; i < nrOfTheaters;i++) {
		unplaned -= theaters[i].getNumberOfSurgeries();
	}
	cout << "************************************************************" << endl;
	//raw info
	cout << "SCHEDULE \n Theaters : " + to_string(nrOfTheaters)
		+ "\n number Of surgeries : " + to_string(nrOfSurgeries)
		+ "\n number Of unschedueld surgeries : " + to_string(unplaned) << endl;


	for (int i = 0; i < nrOfTheaters; i++) {
		int H = theaters[i].getTimeAvalible() / 60;
		int M = theaters[i].getTimeAvalible() % 60;
		cout << "Theater nr: " + to_string(i)
			+ "\tTime available  H: " + to_string(H) + " M: " + to_string(M) << endl;

		cout << "\n surgery lengths :"; //need get surgery info.
		for (int j = 0; j <1/*theaters[i]*/; j++) {

		}
	}

	


}

surgery * readFromFile(int &nrOfoperations)
{
	ifstream surgeryFile("Operationer_1a.txt"); /*Statiskt namn*/
	string line;
	string idString;
	string speciality;
	string timeString;
	int capacity = 30;
	surgery* surgeryList = new surgery[capacity]; //dynamic

	if (surgeryFile.is_open())
	{

		int i = 0;
		while (std::getline(surgeryFile, line))
		{
			//expand if needed 
			if (nrOfoperations == capacity) {
				capacity += 30;
				
				surgery * temp = new surgery[capacity];
				for (int j = 0; j < nrOfoperations; j++) {
					temp[j] = surgeryList[j];
					delete []surgeryList; ///konstigt [] CHECK
					surgeryList = temp;

				}
			}

			nrOfoperations++;
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
