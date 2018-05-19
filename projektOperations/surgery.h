#pragma once
#include <string>

using namespace std;

class surgery {
private:
	int iD; //Känns onödigt? Är väl samma som plats i arrayen?
	string subSpeciality;
	int timeEstimate;

public:
	surgery();
	surgery(int iD, string subSpeciality, int timeEstimate);
	~surgery();
	surgery(const surgery &origObj);

	//SET
	void setId(int iD);
	void setSubSpeciality(string subSpeciality);
	void setTimeEstimate(int timeEstimate);
	void setSurgery(int iD,string subSpeciality,int timeEstimate);

	//GET
	int getId() const;
	string getSubSpeciality()const;
	int getTimeEstimate()const;

	//operators
	surgery &operator=(const surgery &other);
	bool &operator==(const surgery &other);



};