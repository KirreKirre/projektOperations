#include <iostream>
#include "surgery.h"
#include "operatingTheater.h"
//firstFit 
//dum med mer rum
//checkar var objektet får plats -->bäst med max heap? 

//nextFit 461
//does it fit were we put our last objket ->yes->put in same bin 
//=fill until full then take next

//bestFit
//put in tightest spot right now. 

int main() {

	operatingTheater OT;
	OT.addSurgerysFromFile();


	for (int i = 0; i < 1000; i++)
	{
		std::cout << "Mohahahahaha \n" << std::endl;
		system("CLS");
	}
	/*the Bin packing problem, se kap 10.1.3*/

	return 0;
}