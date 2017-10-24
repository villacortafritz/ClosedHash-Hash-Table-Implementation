#include <iostream>
#include "Closed.h"

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	ClosedHash sample(10);

	sample.add(54);
	sample.add(0);
	sample.add(12);
	sample.add(5);
	sample.add(27);
	sample.add(34);
	sample.display();
	
	cout << "\nRemove 54";
	sample.remove(54);
	sample.display();
	
	cout << "\nContains 27? " << sample.contains(27);
	cout << "\nContains 99? " << sample.contains(99);
	return 0;
}
