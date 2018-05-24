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

void bestFitMinDelta(const surgery operations[], const int nrOfSurgeries, HeapType type, operatingTheater theaters[], const int nrOfTheaters);

void bestFitMaxDelta(const surgery operations[], const int nrOfSurgeries, HeapType type, operatingTheater theaters[], const int nrOfTheaters);


void displaySchedule(const operatingTheater theaters[], const int nrOfTheaters, HeapType type, const int nrOfSurgeries);

surgery* readFromFile(int &nrOfoperations, int &menuChoice, surgery* surgeryList);


int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	surgery* aList;
	int nrOfOperations = 0;
	//operatingTheater room[6];
	int menuChoice = -1;
	surgery* surgeryList = new surgery[30];
	/*Scenarios:
	uppgift 1 med fil 1a MINHEAP
	Uppgift 1 med fil 1a MAXHEAP
	Uppgift 1 med fil 1b MINHEAP
	Uppgift 1 med fil 1b MAXHEAP
	Uppgift 2 med fil 2 MAXHEAP
	Uppgift 2 med fil 2 MINHEAP
	*/

	while (menuChoice != 0) {

		cout << "1: Uppgift 1aMIN\n2: Uppgift 1aMAX\n3: Uppgift 1bMIN\n4: Uppgift 1bMAX\n5: Uppgift 2MIN\n6: Uppgift 2MAX\n0: Exit" << endl;
		cin >> menuChoice;
		cin.ignore();
		if (menuChoice == 1)
		{
			operatingTheater room[3];
			operatingTheater nextFitRoom[3];
			operatingTheater bestFitMinDeltaRoom[3];
			operatingTheater bestFitMaxDeltaRoom[3];

			for (int i = 0; i < 3; i++)
			{
				room[i].setTimeAvalible(660);
				nextFitRoom[i].setTimeAvalible(660);
				bestFitMinDeltaRoom[i].setTimeAvalible(660);
				bestFitMaxDeltaRoom[i].setTimeAvalible(660);
			}
			aList = readFromFile(nrOfOperations, menuChoice, surgeryList);

			firstFit(aList, nrOfOperations, MIN, room, 3);
			displaySchedule(room, 3, MIN, nrOfOperations);
			//93 87 81

			nextFit(aList, nrOfOperations, MIN, nextFitRoom, 3);
			displaySchedule(nextFitRoom, 3, MIN, nrOfOperations);
			//93 87 81

			bestFitMinDelta(aList, nrOfOperations, MIN, bestFitMinDeltaRoom, 3);
			displaySchedule(bestFitMinDeltaRoom, 3, MIN, nrOfOperations);
			//

			bestFitMaxDelta(aList, nrOfOperations, MIN, bestFitMaxDeltaRoom, 3);
			displaySchedule(bestFitMaxDeltaRoom, 3, MIN, nrOfOperations);
			//

		}
		else if (menuChoice == 2)
		{
			operatingTheater room[3];
			operatingTheater nextFitRoom[3];
			operatingTheater bestFitMinDeltaRoom[3];
			operatingTheater bestFitMaxDeltaRoom[3];

			for (int i = 0; i < 3; i++)
			{
				room[i].setTimeAvalible(660);
				nextFitRoom[i].setTimeAvalible(660);
				bestFitMinDeltaRoom[i].setTimeAvalible(660);
				bestFitMaxDeltaRoom[i].setTimeAvalible(660);
			}
			aList = readFromFile(nrOfOperations, menuChoice, surgeryList);

			firstFit(aList, nrOfOperations, MAX, room, 3);
			displaySchedule(room, 3, MAX, nrOfOperations);
			//97 92 96

			nextFit(aList, nrOfOperations, MAX, nextFitRoom, 3);
			displaySchedule(nextFitRoom, 3, MAX, nrOfOperations);
			//97 92 96


			bestFitMinDelta(aList, nrOfOperations, MAX, bestFitMinDeltaRoom, 3);
			displaySchedule(bestFitMinDeltaRoom, 3, MAX, nrOfOperations);
			//

			bestFitMaxDelta(aList, nrOfOperations, MAX, bestFitMaxDeltaRoom, 3);
			displaySchedule(bestFitMaxDeltaRoom, 3, MAX, nrOfOperations);
			//

		}
		else if (menuChoice == 3)
		{
			operatingTheater room[3];
			operatingTheater nextFitRoom[3];
			operatingTheater bestFitMinDeltaRoom[3];
			operatingTheater bestFitMaxDeltaRoom[3];

			for (int i = 0; i < 3; i++)
			{
				room[i].setTimeAvalible(660);
				nextFitRoom[i].setTimeAvalible(660);
				bestFitMinDeltaRoom[i].setTimeAvalible(660);
				bestFitMaxDeltaRoom[i].setTimeAvalible(660);
			}
			aList = readFromFile(nrOfOperations, menuChoice, surgeryList);

			firstFit(aList, nrOfOperations, MIN, room, 3);
			displaySchedule(room, 3, MIN, nrOfOperations);
			//100 94 79

			nextFit(aList, nrOfOperations, MIN, nextFitRoom, 3);
			displaySchedule(nextFitRoom, 3, MIN, nrOfOperations);
			//100 94 79

			bestFitMinDelta(aList, nrOfOperations, MIN, bestFitMinDeltaRoom, 3);
			displaySchedule(bestFitMinDeltaRoom, 3, MIN, nrOfOperations);
			//

			bestFitMaxDelta(aList, nrOfOperations, MIN, bestFitMaxDeltaRoom, 3);
			displaySchedule(bestFitMaxDeltaRoom, 3, MIN, nrOfOperations);
			//

		}
		else if (menuChoice == 4)
		{
			operatingTheater room[3];
			operatingTheater nextFitRoom[3];
			operatingTheater bestFitMinDeltaRoom[3];
			operatingTheater bestFitMaxDeltaRoom[3];

			for (int i = 0; i < 3; i++)
			{
				room[i].setTimeAvalible(660);
				nextFitRoom[i].setTimeAvalible(660);
				bestFitMinDeltaRoom[i].setTimeAvalible(660);
				bestFitMaxDeltaRoom[i].setTimeAvalible(660);
			}
			aList = readFromFile(nrOfOperations, menuChoice, surgeryList);

			firstFit(aList, nrOfOperations, MAX, room, 3);
			displaySchedule(room, 3, MAX, nrOfOperations);
			//100 97 97

			nextFit(aList, nrOfOperations, MAX, nextFitRoom, 3);
			displaySchedule(nextFitRoom, 3, MAX, nrOfOperations);
			//55 79 94

			bestFitMinDelta(aList, nrOfOperations, MAX, bestFitMinDeltaRoom, 3);
			displaySchedule(bestFitMinDeltaRoom, 3, MAX, nrOfOperations);
			//

			bestFitMaxDelta(aList, nrOfOperations, MAX, bestFitMaxDeltaRoom, 3);
			displaySchedule(bestFitMaxDeltaRoom, 3, MAX, nrOfOperations);
			//

		}
		else if (menuChoice == 5)
		{
			operatingTheater room[6];
			operatingTheater nextFitRoom[6];
			operatingTheater bestFitMinDeltaRoom[6];
			operatingTheater bestFitMaxDeltaRoom[6];

			room[0].setTimeAvalible(660);
			nextFitRoom[0].setTimeAvalible(660);
			bestFitMinDeltaRoom[0].setTimeAvalible(660);
			bestFitMaxDeltaRoom[0].setTimeAvalible(660);
			room[3].setTimeAvalible(660);
			nextFitRoom[3].setTimeAvalible(660);
			bestFitMinDeltaRoom[3].setTimeAvalible(660);
			bestFitMaxDeltaRoom[3].setTimeAvalible(660);

			room[1].setTimeAvalible(840);
			nextFitRoom[1].setTimeAvalible(840);
			bestFitMinDeltaRoom[1].setTimeAvalible(840);
			bestFitMaxDeltaRoom[1].setTimeAvalible(840);
			room[4].setTimeAvalible(840);
			nextFitRoom[4].setTimeAvalible(840);
			bestFitMinDeltaRoom[4].setTimeAvalible(840);
			bestFitMaxDeltaRoom[4].setTimeAvalible(840);

			room[2].setTimeAvalible(540);
			nextFitRoom[2].setTimeAvalible(540);
			bestFitMinDeltaRoom[2].setTimeAvalible(540);
			bestFitMaxDeltaRoom[2].setTimeAvalible(540);
			room[5].setTimeAvalible(540);
			nextFitRoom[5].setTimeAvalible(540);
			bestFitMinDeltaRoom[5].setTimeAvalible(540);
			bestFitMaxDeltaRoom[5].setTimeAvalible(540);

			aList = readFromFile(nrOfOperations, menuChoice, surgeryList);

			firstFit(aList, nrOfOperations, MIN, room, 6);
			displaySchedule(room, 6, MIN, nrOfOperations);

			nextFit(aList, nrOfOperations, MIN, nextFitRoom, 6);
			displaySchedule(nextFitRoom, 6, MIN, nrOfOperations);


			bestFitMinDelta(aList, nrOfOperations, MIN, bestFitMinDeltaRoom, 6);
			displaySchedule(bestFitMinDeltaRoom, 6, MIN, nrOfOperations);
			//

			bestFitMaxDelta(aList, nrOfOperations, MIN, bestFitMaxDeltaRoom, 6);
			displaySchedule(bestFitMaxDeltaRoom, 6, MIN, nrOfOperations);
			//


		}
		else if (menuChoice == 6)
		{
			operatingTheater room[6];
			operatingTheater nextFitRoom[6];
			operatingTheater bestFitMinDeltaRoom[6];
			operatingTheater bestFitMaxDeltaRoom[6];

			room[0].setTimeAvalible(660);
			nextFitRoom[0].setTimeAvalible(660);
			bestFitMinDeltaRoom[0].setTimeAvalible(660);
			bestFitMaxDeltaRoom[0].setTimeAvalible(660);
			room[3].setTimeAvalible(660);
			nextFitRoom[3].setTimeAvalible(660);
			bestFitMinDeltaRoom[3].setTimeAvalible(660);
			bestFitMaxDeltaRoom[3].setTimeAvalible(660);

			room[1].setTimeAvalible(840);
			nextFitRoom[1].setTimeAvalible(840);
			bestFitMinDeltaRoom[1].setTimeAvalible(840);
			bestFitMaxDeltaRoom[1].setTimeAvalible(840);
			room[4].setTimeAvalible(840);
			nextFitRoom[4].setTimeAvalible(840);
			bestFitMinDeltaRoom[4].setTimeAvalible(840);
			bestFitMaxDeltaRoom[4].setTimeAvalible(840);

			room[2].setTimeAvalible(540);
			nextFitRoom[2].setTimeAvalible(540);
			bestFitMinDeltaRoom[2].setTimeAvalible(540);
			bestFitMaxDeltaRoom[2].setTimeAvalible(540);
			room[5].setTimeAvalible(540);
			nextFitRoom[5].setTimeAvalible(540);
			bestFitMinDeltaRoom[5].setTimeAvalible(540);
			bestFitMaxDeltaRoom[5].setTimeAvalible(540);

			aList = readFromFile(nrOfOperations, menuChoice, surgeryList);

			firstFit(aList, nrOfOperations, MAX, room, 6);
			displaySchedule(room, 6, MAX, nrOfOperations);

			nextFit(aList, nrOfOperations, MAX, nextFitRoom, 6);
			displaySchedule(nextFitRoom, 6, MAX, nrOfOperations);

			bestFitMinDelta(aList, nrOfOperations, MAX, bestFitMinDeltaRoom, 6);
			displaySchedule(bestFitMinDeltaRoom, 6, MAX, nrOfOperations);
			//

			bestFitMaxDelta(aList, nrOfOperations, MAX, bestFitMaxDeltaRoom, 6);
			displaySchedule(bestFitMaxDeltaRoom, 6, MAX, nrOfOperations);
			//
		}


		//for (int i = 0; i < nrOfOperations; i++) {
		//	cout << "ID :" + to_string(aList[i].getId())
		//		+ " Time:" + to_string(aList[i].getTimeEstimate())
		//		+ " Speciality:" + aList[i].getSubSpeciality() << endl;
		//} /*Föredrar utmatning i funktionerna*/

		//nextFit(aList, nrOfOperations, MIN, room, 3);
		//displaySchedule(room, 3, MIN, nrOfOperations);

		/*the Bin packing problem, se kap 10.1.3*/

		getchar();
	}
	delete[] surgeryList;
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
		added = false;

		for (int i = 0; i < nrOfTheaters; i++) {
			//Adds the first one in line to the room most to the "left", if it fits
			if (sortedOperations.peek().getTimeEstimate() <= theaters[i].getNonSchedueldTime()) {
				theaters[i].addSurgery(sortedOperations.extract());
				i = nrOfSurgeries;
				added = true;
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

void bestFitMinDelta(const surgery operations[], const int nrOfSurgeries, HeapType type, operatingTheater theaters[], const int nrOfTheaters)
{
	Heap<surgery>sortedOperations(type);

	for (int i = 0; i < nrOfSurgeries; i++) {
		sortedOperations.insert(operations[i], operations[i].getTimeEstimate());
	}

	bool added = false;
	do
	{
		added = false;
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
			added = true;
		}

	} while (added);
}

void bestFitMaxDelta(const surgery operations[], const int nrOfSurgeries, HeapType type, operatingTheater theaters[], const int nrOfTheaters)
{
	Heap<surgery>sortedOperations(type);

	for (int i = 0; i < nrOfSurgeries; i++) {
		sortedOperations.insert(operations[i], operations[i].getTimeEstimate());
	}

	bool added = false;
	do
	{
		added = false;
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
					if (roomDelta > delta || delta == 0) /*if it fits better in this room or, if delta hasnt been changed yet*/
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
			added = true;
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

	float* floatArr = new float[nrOfTheaters];
	int arrCounter = 0;
	for (int i = 0; i < nrOfTheaters; i++) {
		int totalHours = theaters[i].getTimeAvalible() / 60;
		int totalMinutes = theaters[i].getTimeAvalible() % 60;
		int unusedTimeHours = theaters[i].getNonSchedueldTime() / 60;
		int unusedTimeMinutes = theaters[i].getNonSchedueldTime() % 60;
		cout << "\n--Theater number: " + to_string(i)
			+ "\nTime available  H: " + to_string(totalHours) + " M: " + to_string(totalMinutes)
			+ "\nUnused time H:" + to_string(unusedTimeHours) + " M: " + to_string(unusedTimeMinutes) << endl;

		float procentage = float(theaters[i].getSchedueldTime()) / float(theaters[i].getTimeAvalible()) * 100;
		floatArr[arrCounter] = procentage;
		arrCounter++;
		cout << "Time used " + to_string(procentage) + " % " << endl;
		cout << "Surgery lengths :"; //need get surgery info.
		for (int j = 0; j < theaters[i].getNumberOfSurgeries(); j++) {
			cout << to_string(theaters[i].getSurgery(j).getTimeEstimate()) + " ";
		}
		cout << endl;
	}
	float averagePercentage = 0;
	for (int i = 0; i < arrCounter; i++)
	{
		averagePercentage += floatArr[i];
	}
	averagePercentage = averagePercentage / arrCounter;
	cout << "Average percentage: " + to_string(averagePercentage) + " %" << endl;
	delete[] floatArr;
}

surgery *readFromFile(int &nrOfoperations, int &menuChoice, surgery* surgeryList)
{
	string fileName;
	if (menuChoice == 1 || menuChoice == 2)
	{
		fileName = "Operationer_1a.txt";
	}
	else if (menuChoice == 3 || menuChoice == 4)
	{
		fileName = "Operationer_1b.txt";
	}
	else if (menuChoice == 5 || menuChoice == 6)
	{
		fileName = "Operationer_2.txt";
	}
	ifstream surgeryFile(fileName);
	string line;
	string idString;
	string speciality;
	string timeString;
	int capacity = 30;

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
	surgeryFile.close();
	return surgeryList;
}