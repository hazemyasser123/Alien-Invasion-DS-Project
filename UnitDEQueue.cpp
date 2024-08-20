#include "UnitDEQueue.h"

void UnitDEQueue::PrintQueue()
{
	Unit* K;
	UnitDEQueue Qcopy(*this);
	Node<Unit*>* follow = frontPtr;
	cout << "[";
	while (Qcopy.dequeue(K))
	{
		if (follow == nullptr)
		{
			cout << " " << endl;
			return;
		}
		else if (follow->getNext() == nullptr)
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
