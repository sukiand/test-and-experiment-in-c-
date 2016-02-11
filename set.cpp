#include <iostream>
#include <string>
#include <malloc.h>

// int max

using namespace std;

class Set{
private:
	int * array;
	int capacity;
	int curIndex;

public:
	Set(int capacity = 10);
	int size();
	bool isEmpty();
	bool contains(int k);
	int * toArray();
	bool add(int k);
	bool remove(int k);
	bool containsAll(Set A);
	bool addAll(Set A);
	bool removeAll(Set A);
	void clear();
	bool equal(Set A);
	bool extend();
};

Set::Set(int capacity = 10){
	this->capacity = capacity;
	this->array = new int[capacity];
	this->curIndex = 0;
}

bool Set::add(int k){
	if (this->contains(k)) return false;
	if (curIndex == this->capacity){
		this->extend();
	}
	this->array[curIndex] = k;
	curIndex++;
	return true;
}

int Set::size(){
	return curIndex;
}

bool Set::extend(){
	this->capacity = this->capacity * 3 / 2 + 1;
	int * newArray = new int[this->capacity];
	for (int i = 0; i < this->curIndex; i++){
		newArray[i] = this->array[i];
	}
	delete(this->array);
	this->array = newArray;
}

bool Set::remove(int k){
	for (int i = 0; i < this->curIndex; i++){
		if (this->array[i] == k){
			for (int j = i; j < this->curIndex-1; j++){
				this->array[j] = this->array[j + 1];
			}
			curIndex--;
			return true;
		}
	}
	return false;
}

bool Set::contains(int k){
	for (int i = 0; i < this->curIndex; i++){
		if (this->array[i] == k)
		{
			return true;
		}
	}
	return false;
}
