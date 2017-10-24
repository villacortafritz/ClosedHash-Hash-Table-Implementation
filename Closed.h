#ifndef CLOSED_H_
#define CLOSED_H_

using namespace std;

enum Tag{EMPTY, OCCUPIED, DELETED};

struct Chash{
	int table;
	Tag tag;
};

class ClosedHash{
	private:
		Chash* c;
		int size;
		int hash (int key, int i){return (key+i) %size;};
	public:
		ClosedHash();
		ClosedHash(int x);
		~ClosedHash();
		void add (int x);
		void remove(int x);
		bool contains(int x);
		void display();
};

#endif
