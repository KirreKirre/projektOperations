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
			this->package = package;
			this->priority = priority;
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
	Heap();
	Heap(HeapType type);
	Heap(const Heap& oriObj);
	~Heap();

	void insert(const T & element, const int priority);
	//later modifie to handle other data types as priority

	T peek();		//look at first element
	T extract();	//pick out first element

	int leftChild(int parentInd) { return (((parentInd + 1) * 2) - 1); }
	int rightChild(int parentInd) { return((parentInd + 1) * 2); }
	int parent(int childInd) { return(((childInd + 1) / 2) - 1); }
	void swap(Container *firsobjekt, Container *other);


	bool isEmpty()const;

};

template<typename T>
inline void Heap<T>::expand()
{
	this->capacity += (10 + capacity / 2);
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
	this->queue = new Container[capacity];
}

template<typename T>
inline Heap<T>::Heap(HeapType type)
{
	this->capacity = 10;
	this->nrOfitems = 0;
	this->heapType = type;
	this->queue = new Container[capacity];
}

template<typename T>
inline Heap<T>::Heap(const Heap & oriObj)
{
	this->capacity = oriObj.capacity;
	this->nrOfitems = oriObj.nrOfitems;
	this->queue = new Container[this->capacity];
	for (int i = 0; i < this->nrOfitems; i++) {
		this->queue[i] = oriObj.queue[i];
	}
}

template<typename T>
inline Heap<T>::~Heap()
{
	delete[] this->queue;
}

template<typename T>
inline void Heap<T>::insert(const T & element, const int priority)
{
	if (this->nrOfitems == this->capacity) {
		expand();
	}
	this->queue[this->nrOfitems].package = element;
	this->queue[this->nrOfitems].priority = priority;
	this->nrOfitems++;
	//sort
	int i = this->nrOfitems - 1;
	int par = parent(i);

	//for MIN
	if (this->heapType == MIN) {
		while (i != 0 && queue[par].priority > queue[i].priority)
		{
			this->swap(&queue[i], &queue[par]);
			i = par;
			par = parent(i);
		}
	}
	//for MAX
	else {
		while (i != 0 && queue[par].priority < queue[i].priority)
		{
			this->swap(&queue[i], &queue[par]);
			i = par;
			par = parent(i);
		}
	}


}

template<typename T>
inline T Heap<T>::peek()
{
	T temp;
	if (this->nrOfitems > 0)
	{
		temp = this->queue[0].package;
	}
	return temp;
}

template<typename T>
inline T Heap<T>::extract()
{
	T temp = this->queue[0].package;

	this->nrOfitems--;

	queue[0] = queue[this->nrOfitems];
	int par = 0;
	int left = par + 1;
	int right = par + 2;
	int toSwap = 0;
	bool stop = false;

	//MIN

	if (this->heapType == MIN) {

		while (!stop)
		{
			if (left < this->nrOfitems) {
				if (right < this->nrOfitems) {
					if (queue[left].priority > queue[right].priority) {
						toSwap = right;
					}
					else {
						toSwap = left;
					}
				}
				else {
					toSwap = left;
				}
				if (queue[toSwap].priority < queue[par].priority) {
					swap(&queue[toSwap], &queue[par]);
					par = toSwap;
					left = leftChild(par);
					right = rightChild(par);
				}
				else {
					stop = true;
				}
			}
			else {
				stop = true;
			}
		}
	}

	//MAX
	if (this->heapType == MIN) {
		//ska testas
		while (!stop)
		{
			if (left < this->nrOfitems) {
				if (right < this->nrOfitems) {
					if (queue[left].priority < queue[right].priority) {
						toSwap = right;
					}
					else {
						toSwap = left;
					}
				}
				else {
					toSwap = left;
				}
				if (queue[toSwap].priority > queue[par].priority) {
					swap(&queue[toSwap], &queue[par]);
					par = toSwap;
					left = leftChild(par);
					right = rightChild(par);
				}
				else {
					stop = true;
				}
			}
			else {
				stop = true;
			}
		}
	}


	return temp;
}

template<typename T>
inline void Heap<T>::swap(Container * firstObjekt, Container * other)
{
	Container temp = *firstObjekt;
	*firstObjekt = *other;
	*other = temp;
}

template<typename T>
inline bool Heap<T>::isEmpty() const
{
	bool temp = false;
	if (this->nrOfitems == 0)
	{
		temp = true;
	}
	return temp;
}
