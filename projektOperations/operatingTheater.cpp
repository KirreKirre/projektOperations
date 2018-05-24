#include "operatingTheater.h"

operatingTheater::operatingTheater()
{
	timeAvalible = 100;
	scheduledTime = 0;
	this->nrOfSurgeries = 0;
	surgeryList = new surgery[capacity];
}

operatingTheater::operatingTheater(int startTime, int closingTime)
{
	int totalTime = closingTime - startTime;
	timeAvalible = totalTime;
	this->nrOfSurgeries = 0;
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

		for (int i = 0; i < origObj.nrOfSurgeries; i++)
		{
			this->surgeryList[i] = origObj.surgeryList[i];
		}
		this->nrOfSurgeries = origObj.nrOfSurgeries;
	}
}

void operatingTheater::setTimeAvalible(int Time)
{
	this->timeAvalible = Time;
}


void operatingTheater::addSurgery(surgery operationToAdd)
{
	expand();

	this->surgeryList[nrOfSurgeries] = operationToAdd;
	this->nrOfSurgeries++;
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
	return this->nrOfSurgeries;
}

surgery operatingTheater::getSurgery(int nr) const
{
	surgery temp;
	if (nr > -1 && nr < this->nrOfSurgeries) {
		temp = this->surgeryList[nr];
	}

	return temp;
}

operatingTheater & operatingTheater::operator=(const operatingTheater & other)
{
	if (this != &other) {
		delete[] this->surgeryList;
		surgeryList = new surgery[other.capacity];

		for (int i = 0; i < other.nrOfSurgeries; i++) {
			surgeryList[i] = other.surgeryList[i];
		}
		this->timeAvalible = other.timeAvalible;
		this->scheduledTime = other.scheduledTime;
		this->nrOfSurgeries = other.nrOfSurgeries;
		this->capacity = other.capacity;
	}
	return *this;

	// TODO: insert return statement here
}
