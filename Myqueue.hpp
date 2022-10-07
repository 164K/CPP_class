#ifndef MY_QUEUE
#define MY_QUEUE

#include <iostream>
#define QUEUE_MAX 100

using namespace std;


template<class T>
class Myqueue
{
public:
	Myqueue(int MaxSize=QUEUE_MAX);
    Myqueue(T* arr, int N, int MaxSize=QUEUE_MAX);
    ~Myqueue(){delete data;}

    void enQueue(T elem);
	T deQueue();

	void dispQueue();
	int getElemNum();
    bool isEmpty();
    bool isFull();
private:
	int front;
    int rear;
    int MaxSize;
    int MS;
	T* data;
};

template<class T>
Myqueue<T>::Myqueue(int MaxSize):
	front(0), rear(0), MaxSize(MaxSize), MS(MaxSize+1),data(new T[MaxSize+1]){}

template<class T>
Myqueue<T>::Myqueue(T* arr, int N, int MaxSize):Myqueue<T>(MaxSize)
{
    for(int i=0;i<N && !isFull();i++)
        enQueue(arr[i]);
}

template<class T>
bool Myqueue<T>::isEmpty()
{
    return front==rear;
}

template<class T>
int Myqueue<T>::getElemNum()
{
	return (rear-front+MS)%MS;
}

template<class T>
bool Myqueue<T>::isFull()
{
    return getElemNum()==MaxSize;
}

template<class T>
void Myqueue<T>::enQueue(T elem)
{
    if(!isFull())
    {
        rear = (rear+1)%MS;
        data[rear] = elem;
    }
    else
    	cout<<"[WARNING] Queue out of memery. "<<elem<<" is not enqueue."<<endl;
}

template<class T>
T Myqueue<T>::deQueue()
{
    if(!isEmpty())
    {
        front=(front+1)%MS;
        return data[front];
    }
    else
    {
    	cout<<"[WARNING] Queue is empty. No element dequeue."<<endl;
        return T(0);
    }
}

template<class T>
void Myqueue<T>::dispQueue()
{
    cout<<"Queue: > ";
    for(int i=(front+1)%MS;i!=(rear+1)%MS;i=(i+1)%MS)
        cout<<data[i]<<" > ";
    cout<<endl;
}

#endif