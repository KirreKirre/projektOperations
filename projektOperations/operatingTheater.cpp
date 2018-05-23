#include "operatingTheater.h"

operatingTheater::operatingTheater()
{
	timeAvalible = 100;
	scheduledTime = 0;

	surgeryList = new surgery[capacity];
}

operatingTheater::operatingTheater(int startTime, int closingTime)
{
	int totalTime = closingTime - startTime;
	timeAvalible = totalTime;
	scheduledTime = 0;
	surgeryList = new surgery[capacity];
}

operatingTheater::~operatingTheater()
{
	delete[] this->surgeryList;
}

operatingTheater::operatingTheater(const operatingTheater & origObj)
{
	if (this != &origObj)
	{
		this->timeAvalible = origObj.timeAvalible;
		this->scheduledTime = origObj.scheduledTime;
		this->surgeryList = new surgery[origObj.capacity];

		for (int i = 0; i < origObj.nrOfSurgerys; i++)
		{
			this->surgeryList[i] = origObj.surgeryList[i];
		}
		this->nrOfSurgerys = origObj.nrOfSurgerys;
	}
}

void operatingTheater::setTimeAvalible(int Time)
{
	this->timeAvalible = Time;
}


void operatingTheater::addSurgery(surgery operationToAdd)
{
	expand();

	this->surgeryList[nrOfSurgerys] = operationToAdd;
	this->nrOfSurgerys++;
	scheduledTime += operationToAdd.getTimeEstimate();
}

int operatingTheater::getTimeAvalible()const
{
	return this->timeAvalible;
}

int operatingTheater::getSchedueldTime() const
{
	return this->scheduledTime;
}

int operatingTheater::getNonSchedueldTime() const
{
	return this->timeAvalible - scheduledTime;
}

int operatingTheater::getNumberOfSurgeries() const
{
	return this->capacity;
}

surgery operatingTheater::getSurgery(int nr) const
{
	surgery temp;
	if (nr > -1 && nr < this->nrOfSurgerys) {
		temp = this->surgeryList[nr];
	}

	return temp;
}

operatingTheater & operatingTheater::operator=(const operatingTheater & other)
{
	if (this != &other) {
		delete[] this->surgeryList;
		surgeryList = new surgery[other.capacity];

		for (int i = 0; i < other.nrOfSurgerys; i++) {
			surgeryList[i] = other.surgeryList[i];
		}
		this->timeAvalible = other.timeAvalible;
		this->scheduledTime = other.scheduledTime;
		this->nrOfSurgerys = other.nrOfSurgerys;
		this->capacity = other.capacity;
	}
	return *this;

	// TODO: insert return statement here
}
