#include "UnitpriQueue.h"
#include "Unit.h"
#include <iostream>
using namespace std;
void UnitpriQueue::PrintPriQueue()
{
    Unit* K;
    int dummy;
    priNode<Unit*>* follow = head;
    priQueue <Unit*> Qcopy(*this);
    cout << "[";
    while (Qcopy.dequeue(K, dummy))
    {
        if (follow->getNext() == nullptr)
        {
            K->Print();
        }
        else
        {
            K->Print();
            cout << ", ";

        }
        follow = follow->getNext();
    }
    cout << "]" << endl;
}
