#pragma once
#include <iostream>
#include "Unit.h"
using namespace std;
#define DefSize 999





template <class T, int size = DefSize>
class Array_Of_Pointers
{
protected:
	T * items[size];
	/******************************************************************************************************************/
	//  ------------        /\    /\        | )    :   when using this class you declare it like this " Array_Of_Pointers<int> "                                                                        
	//        |	           /  \  /  \       |   )  :   and the class will make it an array of pointers from this data type in other words you can only                                                                       
	//        |           /    \/    \      |   )  :   insert in this form " int* " (Replace int with whatever data type you are using)                                                                                     
	//        |          /            \     |  )   :   (IF YOU DON'T UNDERSTAND WHAT I WROTE CONTACT ME)                                                                        
	//        |         /              \    | )    :    ZUMA BEEH                                                                      
	//  ------------   /                \   |    
	//                                      |                                                   
	/******************************************************************************************************************/
	int count;
public:
	Array_Of_Pointers();
	bool insert(T* data);
	bool ChangeVal(T* data, int index);
	void PrintAll();
	virtual bool Delete(T* data);
	void clear();
	int GetCount();
	bool IsEmpty();
};

template<class T, int size>
inline Array_Of_Pointers<T, size>::Array_Of_Pointers()
{
	for (int i = 0; i < size; i++)
	{
		items[i] = nullptr;
	}
	count = 0;
}

template<class T, int size>
inline bool Array_Of_Pointers<T, size>::insert(T* data)
{
	if (count == size)
	{
		return false;
	}
	else
	{
		items[count] = data;
		count++;
		return true;
	}
}

template<class T, int size>
inline bool Array_Of_Pointers<T, size>::ChangeVal(T* data, int index)
{
	if (index < count)
	{
		items[index] = data;
		return true;
	}
	else
	{
		return false;
	}
}

template<class T, int size>
inline void Array_Of_Pointers<T, size>::PrintAll()
{
	cout << "[";
	for (int i = 0; i < count; i++)
	{
		if (i != count - 1)
		{
			cout << items[i] << ", ";
		}
		else
		{
			cout << items[i];
		}
	}
	cout << "]" << endl;
}

template<class T, int size>
inline bool Array_Of_Pointers<T, size>::Delete(T* data)
{
	return true;
}

template<class T, int size>
inline void Array_Of_Pointers<T, size>::clear()
{
	for (int i = 0; i < count; i++)
	{
		items[i] = nullptr;
	}
	count = 0;

}

template<class T, int size>
inline int Array_Of_Pointers<T, size>::GetCount()
{
	return count;
}

template<class T, int size>
inline bool Array_Of_Pointers<T, size>::IsEmpty()
{
	return (count == 0);
}