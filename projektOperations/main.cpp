#include <iostream>
#include "surgery.h"
#include "Heap.h"
//firstFit 
//dum med mer rum
//checkar var objektet får plats -->bäst med max heap? 

void firstFit(surgery operations[],HeapType type);

//nextFit 461
//does it fit were we put our last objket ->yes->put in same bin 
//=fill until full then take next

void nextFit(surgery operations[],HeapType type);

//bestFit
//put in tightest spot right now. 

void bestFit(surgery operations[],HeapType type);

int main() {

	for (int i = 0; i < 1000; i++)
	{
		std::cout << "Mohahahahaha \n" << std::endl;
		system("CLS");
	}
	/*Dab on them haters*/

	return 0;
}

void firstFit(surgery operations[], HeapType type)
{

}

void nextFit(surgery operations[], HeapType type)
{

}

void bestFit(surgery operations[], HeapType type)
{

}
