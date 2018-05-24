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
	int nrOfSurgeries ;
	
	void expand()
	{
		if (this->nrOfSurgeries == this->capacity)
		{
			this->capacity += 10;
			surgery * temp = new surgery[capacity];
			for (int i = 0; i < this->nrOfSurgeries; i++)
			{
				temp[i] = this->surgeryList[i];
			}
			delete[] surgeryList;
			surgeryList = temp;
		}
	};

public:
	operatingTheater();
	operatingTheater(int startTime, int closingTime);
	~operatingTheater();
	operatingTheater(const operatingTheater &origObj);

	void setTimeAvalible(int Time);

	void addSurgery(surgery operationToAdd);
	int getTimeAvalible()const;
	int getSchedueldTime() const;
	int getNonSchedueldTime()const;
	int getNumberOfSurgeries()const;

	surgery getSurgery(int nr)const ;

	operatingTheater &operator=(const operatingTheater &other);

};