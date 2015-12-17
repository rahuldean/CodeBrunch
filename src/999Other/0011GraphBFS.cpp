#include <iostream>
#include <list>
using namespace std;
class Graph {
	private:
		int vertex_count;
		list<int>* adjacent_vertices;
	public:
		Graph();
		Graph(int vertex_count);
		void Insert(int vertex, int weight);
		void BFS(int start_vertex);
};

Graph :: Graph() {}
Graph :: Graph(int vertex_count){
	this->vertex_count = vertex_count;
	this->adjacent_vertices = new list<int>[vertex_count];
}
void Graph :: Insert(int vertex, int weight){
	this->adjacent_vertices[vertex].push_back(weight);
}

void Graph :: BFS(int start_vertex){
	bool* visited = new bool[this->vertex_count];

	// set all to be not visited
	for(int i = 0; i < this->vertex_count; i++)
		visited[i] = false;

	// create a queue
	list<int> queue;

	// mark start vertex to be visited
	visited[start_vertex] = true;

	// enqueue it
	queue.push_back(start_vertex);

	// run through the queue
	while(!queue.empty()){

		// peek whats in front
		int current = queue.front();
		cout << current << " ";

		// dequeue it
		queue.pop_front();

		// check all the adjacents if the current element
		for(std::list<int>::const_iterator it = this->adjacent_vertices[current].begin(); it != this->adjacent_vertices[current].end(); ++it){
			// if current adjacent vertex is not visited
			if(!visited[*it]){
				visited[*it] = true;
				queue.push_back(*it);
			}
		}

	}
	delete visited;
}
int main() {
	// your code goes here
	Graph g(4);
    g.Insert(0, 1);
    g.Insert(0, 2);
    g.Insert(1, 2);
    g.Insert(2, 0);
    g.Insert(2, 3);
    g.Insert(3, 3);
 
    cout << "Following is Breadth First Traversal (starting from vertex 2) \n";
    g.BFS(2);
 
	return 0;
}