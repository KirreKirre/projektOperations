#pragma once
#include <fstream>

#include "surgery.h"
class operatingTheater
{
private:

	int timeAvalible; //in min

	int scheduledTime;
	//array ?

	surgery* surgeryList;
	int capacity = 20;
	int nrOfSurgerys = 0;

	void expand()
	{
		if (this->nrOfSurgerys == this->capacity)
		{
			this->capacity += 10;
			surgery * temp = new surgery[capacity];
			for (int i = 0; i < this->nrOfSurgerys; i++)
			{
				temp[i] = this->surgeryList[i];
			}
			delete surgeryList;
			surgeryList = temp;
		}
	};

public:
	operatingTheater();
	operatingTheater(int startTime, int closingTime);
	~operatingTheater();
	operatingTheater(const operatingTheater &origObj);

	void addSurgery(surgery operationToAdd);
	int getTimeAvalible()const;
	int getNonSchedueldTime()const;
	int getNumberOfSurgeries()const;

	surgery getSurgery(int nr);

	operatingTheater &operator=(const operatingTheater &other);

};