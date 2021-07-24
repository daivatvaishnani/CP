#include <iostream>
#include <vector>

using namespace std;

struct adjList {
	std::vector<int> v;
};

void addEdge(struct adjList* array ,int v1, int v2) {
	array[v1].v.push_back(v2);
	array[v2].v.push_back(v1);
}

void printGraph(struct adjList* array, int size) {
	for(int i=0; i<size; i++) {
		int vectorsize = array[i].v.size();
		cout << "At vertex " << i << " : ";
		for(int j=0; j<vectorsize; j++) cout << array[i].v[j] << " ";
		cout << endl;
	}
}

void bfs(struct adjList* array) {

}

int main() {
	int n=5;

	struct adjList array[n];

	addEdge(array, 0, 1);
    addEdge(array, 0, 4);
    addEdge(array, 1, 2);
    addEdge(array, 1, 3);
    addEdge(array, 1, 4);
    addEdge(array, 2, 3);
    addEdge(array, 3, 4);

    printGraph(array,5);

	return 0;
}