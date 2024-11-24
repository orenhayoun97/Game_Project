#pragma once
#include <iostream>
//#include "Skill.h"
/// <summary>
///		add requirements on the template parameter T
///		such that the class works as intended
/// </summary>
/// <typeparam name="T"></typeparam>
template <class T>
class ResizableArray
{
private:
	T** objArray = nullptr;//array of pointers to objects
	int currentSize = 0;//number of objects in the array
	int maxSize = 0;//capacity of the array
	void resize();

public:
	ResizableArray() = default;//default constructor
	//ResizableArray(T arr[], int size);//constructs from an array
	ResizableArray(const ResizableArray& other);//copy constructor
	ResizableArray& operator=(const ResizableArray& rhs);//copy assignment
	~ResizableArray();//destructor

	int getSize() const;//returns currentSize
	int getCapacity() const;//returns maxSize

	void pushBack(T* obj);//adds an object to the end of the array
	//bool find(T* obj) const;//returns true if the object is in the array. do not compare by address
	int findSkill(int type) const;
	void empty();//removes all objects from the array
	//bool remove(T* obj);//removes the object from the array. returns true if successful
	//void shrink();//reduces the capacity to the current size

	T* operator[](int index) const;//returns the object at the index
	const ResizableArray& operator+=(T* obj);//adds an object to the end of the array
	friend ostream& operator<<(ostream& out, const ResizableArray& ra);//prints the array
};
template<class T>
ResizableArray<T>::ResizableArray(const ResizableArray& other) : currentSize(other.currentSize), maxSize(other.maxSize)
{
	if (other.objArray != nullptr)
	{
		this->objArray = new T * [other.maxSize];
		for (int i = 0; i < currentSize; i++)
		{
			this->objArray[i] = new T(*other.objArray[i]);
		}
	}
}
template<class T>
ResizableArray<T>& ResizableArray<T>::operator=(const ResizableArray& rhs)
{
	if (this != &rhs)
	{
		for (int i = 0; i < this->currentSize; i++)
		{
			delete objArray[i];
		}
		delete[] objArray;
		this->currentSize = rhs.currentSize;
		this->maxSize = rhs.maxSize;
		this->objArray = new T * [this->maxSize];
		if (rhs.objArray != nullptr)
		{
			for (int i = 0; i < currentSize; i++)
			{
				this->objArray[i] = new T(*rhs.objArray[i]);
			}
		}
	}
	return *this;
}
template <class T>
ResizableArray<T>::~ResizableArray()
{
	this->empty();
}
template <class T>
int ResizableArray<T>::getSize() const
{
	return this->currentSize;
}
template <class T>
int ResizableArray<T>::getCapacity() const
{
	return this->maxSize;
}
template <class T>
void ResizableArray<T>::pushBack(T* obj)
{
	if (currentSize == maxSize)
		resize();
	objArray[currentSize++] = obj;
}
template <class T>
T* ResizableArray<T>::operator[](int index) const
{
	if (index < 0 || index >= this->currentSize) return nullptr;

	return objArray[index];
}
template <class T>
const ResizableArray<T>& ResizableArray<T>::operator+=(T* obj)
{
	pushBack(obj);
	return *this;
}
template <class T>
ostream& operator<<(ostream& out, const ResizableArray<T>& ra)
{
	for (int i = 0; i < ra.currentSize; i++)
	{
		out << *ra.objArray[i] << " ";
	}
	return out;
}
template <class T>
void ResizableArray<T>::empty()
{
	if (objArray != nullptr)
	{
		for (int i = 0; i < currentSize; i++)
		{
			delete objArray[i];
		}
		delete[] objArray;
		objArray = nullptr;
		currentSize = 0;
		maxSize = 0;
	}
}
template <class T>
void ResizableArray<T>::resize()
{
	if (maxSize == 0)
	{
		maxSize = 2;
		objArray = new T * [maxSize];
	}
	else
	{
		maxSize *= 2;
		T** temp = new T * [maxSize];
		for (int i = 0; i < currentSize; i++)
			temp[i] = new T(*objArray[i]);

		for (int i = 0; i < currentSize; i++)
			delete objArray[i];
		delete[] objArray;

		objArray = temp;
	}
}
template <class T>
int ResizableArray<T>::findSkill(int type) const
{
	int index = -1;
	for (int i = 0; i < currentSize; i++)
	{
		if (objArray[i]->getType() == type)
		{
			index = i;
			break;
		}
	}

	return index;
}