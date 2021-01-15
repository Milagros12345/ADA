#include <iostream>
#include <list>
#include <vector>
#include <queue>
#include <set>
using namespace std;
/*class Graph {
  int numVertices;
  list<int>* adjLists;
  bool* visited;

   public:
  Graph(int vertices);
  void addEdge(int src, int dest);
  void BFS(int startVertex);
};

Graph::Graph(int vertices) {
  numVertices = vertices;
  adjLists = new list<int>[vertices];
}

// Add edges to the graph
void Graph::addEdge(int src, int dest) {
  adjLists[src].push_back(dest);
  adjLists[dest].push_back(src);
}

// BFS algorithm
void Graph::BFS(int startVertex) {
  visited = new bool[numVertices];
  for (int i = 0; i < numVertices; i++)
    visited[i] = false;

  list<int> queue;

  visited[startVertex] = true;
  queue.push_back(startVertex);

  list<int>::iterator i;

  while (!queue.empty()) {
    int currVertex = queue.front();
    cout << "Visited " << currVertex << " ";
    queue.pop_front();

    for (i = adjLists[currVertex].begin(); i != adjLists[currVertex].end(); ++i) {
      int adjVertex = *i;
      if (!visited[adjVertex]) {
        visited[adjVertex] = true;
        queue.push_back(adjVertex);
      }
    }
  }
}

int main() {
  Graph g(8);
  g.addEdge(0, 1);
  g.addEdge(1, 2);
  g.addEdge(2, 3);
  g.addEdge(2, 4);
  g.addEdge(3, 5);
  g.addEdge(3, 4);
  g.addEdge(4, 3);
  g.addEdge(4, 5);
  g.addEdge(4, 6);
  g.addEdge(6, 4);
  g.addEdge(6, 7);
  g.addEdge(7, 5);

  g.BFS(2);

  return 0;
}
*/
#include<iostream>
#include <fstream>
using namespace std;
int main()
{
    ifstream archivo_entrada;
    string linea;

    archivo_entrada.open("D:/quinto semestre/base de datos II/archivos/tb200.txt");
    while(!archivo_entrada.eof()){
    getline(archivo_entrada, linea);

    cout << linea << endl;
    }
}

