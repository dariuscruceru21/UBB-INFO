#include "Graph.h"
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

Graph::Graph(){

    ifstream f;
    f.open("data.in");
    f >> n;
    f >> m;
    int x,y;
    for(int i=0; i<m; i++){
        f>>x>>y;
        addEdgeAdjList(x,y);
        addEdge(x,y);
    }

}




void Graph::maximalGradMatrix(){
    int maximGrade = 0;
    int s;
    for(int i = 0;i<n;i++){
        s = 0;
        for (int j = 0; j < n; j++){
            if (matrix[i][j] == 1)
                s += 1;}
        if(s > maximGrade)
            maximGrade = s;

    }
    cout<<"Maximum Grade of Graph out of Matrix:"<<maximGrade;
}

void Graph::minimalGradMatrix(){
    int minimGrade = INT_MAX;
    int s;
    for(int i = 0;i<n;i++){
        s = 0;
        for (int j = 0; j < n; j++){
            if (matrix[i][j] == 1)
                s += 1;}
        if(s < minimGrade )
            minimGrade = s;

    }
    cout<<'\n'<<"Maximum Grade of Graph out of Matrix:"<<minimGrade;
}

void Graph::maximalGradList() {
    int maxGrade = INT_MIN;
    int s;
    for(int i = 0;i< n ;i++) {
            s = adjList[i].size();
            if(s > maxGrade)
                maxGrade = s;

    }
    cout<<'\n'<<"Max Grade of Adj List is:"<<maxGrade;
}



void Graph::minimalGradList() {
    int minGrade = INT_MAX;
    int s;
    for(int i = 0;i<n;i++){
        s = adjList[i].size();
        if(s < minGrade)
            minGrade = s;


    }
    cout<<'\n'<<"Min Grade of Adj List is:"<<minGrade;

}








void Graph::addEdge(int x, int y){
    matrix[x][y] = 1;
    matrix[y][x] = 1;
}

void Graph::addEdgeAdjList(int x, int y){
        adjList[x].push_back(y);
        adjList[y].push_back(x);

}


bool Graph::isEdge(int x, int y){
    return matrix[x][y] == 1;
}

void Graph::printAdjList(){
    for(int i = 0; i < n; i++){
        cout << '\n';
        for(int j = 0; j<adjList[i].size();j++)
            cout<<i<<':'<<adjList[i][j]<< ' ';

    }



};



void Graph::printGraph(){
    for (int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << matrix[i][j] << " ";
        }
        cout<<endl;
    }
}