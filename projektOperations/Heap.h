#pragma once

template <typename T>
enum HeapType {MIN,MAX}; //min or max
class Heap 
{
private:

	
	class Container
	{
	public:
		T package;
		int priority;
	};
	Container * queue;
	int nrOfitems;


public:
	Heap ();
	~Heap ();


};

template<typename T>
inline Heap<T>::Heap()
{
}

template<typename T>
inline Heap<T>::~Heap()
{
}
