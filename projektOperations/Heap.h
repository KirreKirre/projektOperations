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
