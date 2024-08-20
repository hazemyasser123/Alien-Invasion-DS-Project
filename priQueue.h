#pragma once
#include "priNode.h"
#include <iostream>
using namespace std;


//This class impelements the priority queue as a sorted list (Linked List)
//The item with highest priority is at the front of the queue
template <typename T>
class priQueue
{
protected:
    priNode<T>* head;
    int count=0;
public:
    priQueue() : head(nullptr) {}

    ~priQueue() {
        T tmp;
        int p;
        while (dequeue(tmp,p));
    }


    priQueue(const priQueue<T>& LQ)
    {
        head = nullptr;
        priNode<T>* NodePtr = LQ.head;	//start at the front node in LQ
        int dummy;
        while (NodePtr)
        {
            enqueue(NodePtr->getItem(dummy), NodePtr->getPri());	//get data of each node and enqueue it in this queue 
            NodePtr = NodePtr->getNext();
        }
    }


    virtual void PrintPriQueue()
    {
        //For this function to work properly, the LikedQueue class MUST
        //have  a copy constructor (pass by value)
        T K;
        int dummy;
        priQueue <T> Qcopy(*this);
        while (Qcopy.dequeue(K, dummy))
            cout << K << " ";
        cout << endl;
    }

    //insert the new node in its correct position according to its priority
    void enqueue(const T& data, int priority) {
        priNode<T>* newNode = new priNode<T>(data, priority);

        if (head == nullptr || priority > head->getPri()) {
            
            newNode->setNext(head);
            head = newNode;
            count++;
            return;
        }
       
        priNode<T>* current = head;        
        while (current->getNext() && priority <= current->getNext()->getPri()) {
            current = current->getNext();
        }
        newNode->setNext( current->getNext());
        current->setNext( newNode); 
        count++;
    }

    bool dequeue(T& topEntry, int& pri) {
        if (isEmpty())
            return false;

        topEntry = head->getItem(pri);
        priNode<T>* temp = head;
        head = head->getNext();
        delete temp;
        count--;
        return true;
    }

    bool peek(T& topEntry, int& pri) {
        if (isEmpty())
            return false;
        pri = head->getPri();
        topEntry = head->getItem(pri); // i think this should be getItem(pri) OR remove the argument list in priNode.h -- mtamer
        return true;
    }

    bool isEmpty() const {
        return head == nullptr;
    }

    int getcount()
    {
        return count;
    }
};