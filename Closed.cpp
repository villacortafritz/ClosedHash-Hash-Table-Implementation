#include <iostream>
#include "Closed.h"
#define SIZE 11

//this is a constructor
ClosedHash::ClosedHash(){
	c = new Chash[SIZE];
	for(int i = 0; i<SIZE; i++){
		c[i].table = 0;
		c[i].tag = EMPTY;
	}
	size = SIZE;
}

//this will initialize with x as the size
ClosedHash::ClosedHash(int x){
	size = x;
	c = new Chash[x];
	for(int i = 0; i<size; i++){
		c[i].table = 0;
		c[i].tag = EMPTY;
	}
}

//this is the deconstructor
ClosedHash::~ClosedHash(){
	delete c;
}

//this will add an element x in the array
void ClosedHash::add(int x){
	int index;
	index = hash(x,0);
	if(c[index].tag == OCCUPIED){
		for (int i = 0; i<size; i++){
			index = hash(x, i*i);
			if(c[index].tag == EMPTY || c[index].tag == DELETED){
				break;
			}
			
		}
	}
	c[index].table = x;
	c[index].tag = OCCUPIED;
}

//this will remove element x in the array
void ClosedHash::remove(int x){
	int index;
	index = hash(x,0);
	if(c[index].tag == DELETED){
		for(int i=0; i<size; i++){
			index = hash(x,i*i);
			if(c[index].table == x && c[index].tag == OCCUPIED){
				break;
			}
		}
	}
	c[index].table = 0;
	c[index].tag = DELETED;
}

//returns 1 if element x is found
bool ClosedHash::contains(int x){
	bool flag = false;
	int index;
	index = hash(x,0);
	if(c[index].tag == DELETED){
		for(int i=0; i<size; i++){
			index = hash(x, i*i);
			if(c[index].tag == OCCUPIED && c[index].table == x){
				flag = true;
				break;
			}
		}
	}
	else if(c[index].tag == OCCUPIED){
			flag = true;
	}
	return flag;
}

//this is an overriden display function
void ClosedHash::display(){
	cout << "\n";
	cout << "Index" << "\t" << "Element" << "\t" << "Tag" << endl;
	for(int i=0; i<size; i++){
		cout << i << "\t" << c[i].table << "\t" <<  c[i].tag <<endl;
	}
}


