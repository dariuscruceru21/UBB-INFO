#include "Graph.h"

#include<iostream>
#include<fstream>

using namespace std;

int main(){

    Graph g;
    //cout<<g.isEdge(0,1)<<endl;
    g.printAdjList();
    g.maximalGradMatrix();
    g.minimalGradMatrix();
    g.maximalGradList();
    g.minimalGradList();




}