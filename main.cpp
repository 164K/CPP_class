#include "Mystack.hpp"
#include "Myqueue.hpp"
#include <iostream>

int main()
{
    int arr[]={1,2,3,4};
	// Mystack<int> ms(arr, 4);
    Myqueue<int> mq(arr, 2, 2);
    mq.enQueue(8);
    mq.enQueue(10);
    mq.dispQueue();
    
    mq.deQueue();
    mq.dispQueue();
	
    mq.enQueue(100);
    mq.dispQueue();

    mq.deQueue();
    mq.dispQueue();

    mq.enQueue(114514);
    mq.dispQueue();
}