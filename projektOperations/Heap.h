#pragma once
 //min or max
enum HeapType { MIN, MAX };
template <typename T>

class Heap 
{
private:

	class Container
	{
	public:
		T package;
		int priority;
		Container(T package, int priority)
		{
			package = package;
			priority = priority;
		};
		Container()
		{

		};
		~Container()
		{

		};

	};

	HeapType heapType; //standard MAX
	Container * queue;
	int nrOfitems;
	int capacity;
	void expand();


public:
	Heap ();
	Heap(HeapType type);
	Heap(const Heap& oriObj);
	~Heap ();


};

template<typename T>
inline void Heap<T>::expand()
{
	this->capacity += capacity/2;
	Container * temp = new Container[this->capacity];
	for (int i = 0; i < this->nrOfitems; i++)
	{
		temp[i] = this->queue[i];
	}
	delete[]this->queue;
	this->queue = temp;
}

template<typename T>
inline Heap<T>::Heap()
{
	this->capacity = 10;
	this->nrOfitems = 0;
	this->heapType = MAX;
}

template<typename T>
inline Heap<T>::Heap(HeapType type)
{
	this->capacity = 10;
	this->nrOfitems = 0;
	this->heapType = type;
}

template<typename T>
inline Heap<T>::Heap(const Heap & oriObj)
{
}

template<typename T>
inline Heap<T>::~Heap()
{
}
