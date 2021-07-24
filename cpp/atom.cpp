#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

std::vector<int> Bstree(10000008);

void createBst() {
	for(int i=0 ; i<Bstree.size() ;i++) {
		Bstree[i] = -1;
	}
}

int LeftChild (int parentIndex) {
	return (2*parentIndex);
}

int RightChild (int parentIndex) {
	return (2*parentIndex+1);
}

int Parent (int childIndex) {
	return (childIndex/2); 
}

void insertToBst (int value) {
	int insertIndex = 1;
	while (Bstree[insertIndex] != -1) {
		if (value > Bstree[insertIndex]) 
			insertIndex = RightChild (insertIndex);
		else 
			insertIndex = LeftChild (insertIndex);
	}
	Bstree[insertIndex] = value;
	Bstree[LeftChild(insertIndex)] = -1;
	Bstree[RightChild(insertIndex)] = -1;
}

int searchInBst (int value) {
	int searchIndex = 1;
	while (Bstree[searchIndex] != -1) {
		if (value > Bstree[searchIndex]) 
			searchIndex = RightChild (searchIndex);
		else if (value < Bstree[searchIndex])
			searchIndex = LeftChild (searchIndex);
		else
			return searchIndex;
	}
	return -1;	
}

int getLeftChild (int parent) {
	int parentIndex = searchInBst (parent);
	return Bstree[LeftChild(parentIndex)]; 
}

int getRightChild (int parent) {
	int parentIndex = searchInBst (parent);
	return Bstree[RightChild(parentIndex)]; 
}

int getParent (int child) {
	int childIndex = searchInBst (child);
	return Bstree[Parent(childIndex)]; 
}



int main() {	
	Bstree[0] = -1; 
	Bstree[1] = -1;
	
	insertToBst(10);
	insertToBst (5);
	insertToBst (20);
	insertToBst (8);
	insertToBst (4);
	insertToBst (15);
	insertToBst (23);
	insertToBst (2);

	cout << searchInBst (10) << endl;
	cout << searchInBst (5) << endl;
	cout << searchInBst (20) << endl;
	cout << searchInBst (8) << endl;
	cout << searchInBst (4) << endl;
	cout << searchInBst (15) << endl;
	cout << searchInBst (23) << endl;
	cout << searchInBst (2) << endl;

	cout << searchInBst(23) << endl;
	cout << searchInBst(20) << endl;
	return 0;
}
