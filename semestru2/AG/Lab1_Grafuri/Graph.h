#include <vector>

class Graph {
private:

    int n;
    int m;
    int matrix[100][100];
    std::vector<int> adjList[100];
    
public:

    Graph();

    void addEdge(int x, int y);
    void addEdgeAdjList(int x, int y);
    void printAdjList();
    bool isEdge(int x, int y);
    void printGraph();
    void minimalGradMatrix();
    void maximalGradMatrix();
    void minimalGradList();
    void maximalGradList();

};