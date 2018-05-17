#pragma once

#include "surgery.h"
class operatingTheater 
{
private:

	int timeAvalible; //in min

	int scheduledTime;
	//array ?

	surgery* surgeryList;
	int capacity;
	int nrOfSurgerys;

public:
	operatingTheater();
	operatingTheater(int startTime, int closingTime);
	~operatingTheater();
	operatingTheater(const operatingTheater &origObj);

	void addSurgery();
	string getStartAndClosingTime();

	operatingTheater &operator=(const operatingTheater &other);

};