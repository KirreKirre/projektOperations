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


void displaySchedule(const operatingTheater theaters[], const int nrOfTheaters, HeapType type, const int nrOfSurgeries);

surgery* readFromFile(int &nrOfoperations);

int main() {

	surgery* aList;
	int nrOfOperations = 0;
	aList = readFromFile(nrOfOperations);
	operatingTheater room[3];
	room[0].setTimeAvalible(1440);
	room[1].setTimeAvalible(1220);
	room[2].setTimeAvalible(1000);

	//for (int i = 0; i < nrOfOperations; i++) {
	//	cout << "ID :" + to_string(aList[i].getId())
	//		+ " Time:" + to_string(aList[i].getTimeEstimate())
	//		+ " Speciality:" + aList[i].getSubSpeciality() << endl;
	//} /*Föredrar utmatning i funktionerna*/

	nextFit(aList, nrOfOperations, MIN, room, 3);
	displaySchedule(room, 3, MIN, nrOfOperations);
	/*the Bin packing problem, se kap 10.1.3*/

	getchar();
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

		for (int i = 0; i < nrOfTheaters; i++) {
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
	for (int i = 0; i < nrOfTheaters; i++) {
		unplaned -= theaters[i].getNumberOfSurgeries();
	}
	cout << "************************************************************" << endl;
	//raw info
	cout << "SCHEDULE \n Theaters : " + to_string(nrOfTheaters)
		+ "\n number Of surgeries : " + to_string(nrOfSurgeries)
		+ "\n number Of unschedueld surgeries : " + to_string(unplaned) << endl;


	for (int i = 0; i < nrOfTheaters; i++) {
		int totalHours = theaters[i].getTimeAvalible() / 60;
		int totalMinutes = theaters[i].getTimeAvalible() % 60;
		int unusedTimeHours = theaters[i].getNonSchedueldTime() / 60;
		int unusedTimeMinutes = theaters[i].getNonSchedueldTime() % 60;
		cout << "\nTheater nr: " + to_string(i)
			+ "\nTime available  H: " + to_string(totalHours) + " M: " + to_string(totalMinutes)
			+ "\nUnused time H:" + to_string(unusedTimeHours) + " M: " + to_string(unusedTimeMinutes) << endl;

		float procentage = float(theaters[i].getSchedueldTime()) / float(theaters[i].getTimeAvalible()) * 100;
		cout << "Time used " + to_string(procentage) + " % " << endl;
		cout << "Surgery lengths :"; //need get surgery info.
		for (int j = 0; j < theaters[i].getNumberOfSurgeries(); j++) {
			cout << to_string(theaters[i].getSurgery(j).getTimeEstimate()) + " ";
		}
		cout << endl;
	}

}

surgery *readFromFile(int &nrOfoperations)
{
	ifstream surgeryFile("Operationer_2.txt"); /*Statiskt namn*/
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
				}
				delete[]surgeryList; ///konstigt [] CHECK
				surgeryList = temp;
			}

			nrOfoperations++;

			idString = line.substr(0, line.find(','));
			speciality = line.substr(line.find(',') + 1, (line.find_last_of(',') - line.find_first_of(',') - 1));
			timeString = line.substr(line.find_last_of(',') + 1, (line.length() - line.find_last_of(',')));

			int id = std::stoi(idString, nullptr);
			int time = std::stoi(timeString, nullptr);
			surgery temp(id, speciality, time);
			surgeryList[i] = temp;

			cout << "ID :" + to_string(surgeryList[i].getId())
				+ " Time:" + to_string(surgeryList[i].getTimeEstimate())
				+ " Speciality:" + surgeryList[i].getSubSpeciality() << endl;

			i++; //saknades :P
		}

	}
	return surgeryList;
}