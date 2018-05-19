#include "surgery.h"

surgery::surgery()
{
	this->iD = 0;
	this->subSpeciality = "undefined";
	this->timeEstimate = 9999;
}

surgery::surgery(int iD, string subSpeciality, int timeEstimate)
{
	this->iD = iD;
	this->subSpeciality = subSpeciality;
	this->timeEstimate = timeEstimate;
}

surgery::~surgery()
{
	//nothing dynamic
}

surgery::surgery(const surgery & origObj)
{
	if (this != &origObj)
	{
		this->iD = origObj.iD;
		this->subSpeciality = origObj.subSpeciality;
		this->timeEstimate = origObj.timeEstimate;
	}
}

//SET

void surgery::setId(int iD)
{
	this->iD = iD;
}

void surgery::setSubSpeciality(string subSpeciality)
{
	this->subSpeciality = subSpeciality;
}

void surgery::setTimeEstimate(int timeEstimate)
{
	this->timeEstimate = timeEstimate;
}

void surgery::setSurgery(int iD, string subSpeciality, int timeEstimate)
{
	this->iD = iD;
	this->subSpeciality = subSpeciality;
	this->timeEstimate = timeEstimate;
}

//GET

int surgery::getId()const
{
	return this->iD;
}

string surgery::getSubSpeciality()const
{
	return this->subSpeciality;
}

int surgery::getTimeEstimate()const
{
	return this->timeEstimate;
}

//OPERATORS

surgery & surgery::operator=(const surgery & other)
{
	if (this != &other)
	{
		this->setSurgery(other.getId(), other.getSubSpeciality(), other.getTimeEstimate());
	}
	return *this;
}

bool & surgery::operator==(const surgery & other)
{
	bool equal = true;
	if (this->getId() != other.getId() ||
		this->getSubSpeciality()!=other.getSubSpeciality() ||
		this->getTimeEstimate()!=other.getTimeEstimate()){
		equal = false;
	}
		
	return equal;

}



