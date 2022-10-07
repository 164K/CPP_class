#ifndef MY_STACK
#define MY_STACK

#include <iostream>
#include <new>

#define STACK_MAX 100

using namespace std;

template<class T>
class Mystack
{
public:
	Mystack(int MaxSize=STACK_MAX);
    Mystack(T* arr, int N, int MaxSize=STACK_MAX);
    ~Mystack(){delete data;}

	void dispStack();

    void push(T elem);
    T pop();
    T getTop();

    int getElemNum();
    bool isEmpty();
    bool isFull();
private:
    int top;
    int MaxSize;
	T* data;
};


template<class T>
Mystack<T>::Mystack(int MaxSize):top(-1),MaxSize(MaxSize),data(new T[MaxSize]){}

template<class T>
Mystack<T>::Mystack(T* arr,int N, int MaxSize):Mystack<T>(MaxSize)
{
    for (int i=0;i<N && !isFull();i++)
		push(arr[i]);
}

template<class T>
void Mystack<T>::dispStack()
{
    cout<<"Stack: [[ ";
    for(int i=0;i<=top;i++)
        cout<<data[i]<<" -> ";
    cout<<endl;
}

template<class T>
bool Mystack<T>::isEmpty()
{
    return top==-1;
}

template<class T>
bool Mystack<T>::isFull()
{
    return getElemNum() >= MaxSize;
}

template<class T>
void Mystack<T>::push(T elem)
{
    if(!isFull())
		data[++top] = elem;
    else
     cout<<"[WARNING] Stack out of memery. "<< elem <<" is not pushed."<<endl;
}


template<class T>
T Mystack<T>::pop()
{
    if (!isEmpty())
		return data[top--];
    else
    {
     	cout<<"[WARNING] Stack is empty. No element poped." <<endl;
     	return T(0);
    }
}


template<class T>
int Mystack<T>::getElemNum()
{
    return top+1;
}

template<class T>
T Mystack<T>::getTop()
{
    return data[top];
}

#endif