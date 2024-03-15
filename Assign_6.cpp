////============================================================================
//// Name        : Assign_6.cpp
//// Author      :
//// Version     :
//// Copyright   : Your copyright notice
//// Description : Hello World in C++, Ansi-style
////============================================================================
//
//#include <iostream>
//#include<vector>
//using namespace std;
//
//
//	void addEdge(vector<vector<int>>&graph,int source,int dest){
//		graph[source].push_back(dest);
//		graph[dest].push_back(source);
//	}
//
//	void printGraph(vector<vector<int> >&graph,int v){
//		for (int i=0;i<v;i++){
//			cout<<"Vertex "<<i<<"| ->";
//			for (int j=0;j<graph[i].size();j++){
//				cout<<" ->"<<graph[i][j];
//			}
//			cout<<endl;
//		}
//	}
//
//int main() {
//	int V = 5;
//
//	  // Create a graph
//	  vector<vector<int> > adj[V];
//
//	  // Add edges
//	  addEdge(adj, 0, 1);
//	  addEdge(adj, 0, 2);
//	  addEdge(adj, 0, 3);
//	  addEdge(adj, 1, 2);
//	  printGraph(adj, V);
//	return 0;
//}

// Adjascency List representation in C++

#include <bits/stdc++.h>
using namespace std;

// Add edge
void addEdge(vector<int> adj[], int s, int d) {
  adj[s].push_back(d);
  adj[d].push_back(s);
}

// Print the graph
void printGraph(vector<int> adj[], int V) {
  for (int d = 0; d < V; ++d) {
    cout << "\n Vertex "
       << d << ":";
    for (auto x : adj[d])
      cout << "-> " << x;
    printf("\n");
  }
}

int main() {
  int V = 5;

  // Create a graph
  vector<int> adj[V];

  // Add edges
  addEdge(adj, 0, 1);
  addEdge(adj, 0, 2);
  addEdge(adj, 0, 3);
  addEdge(adj, 1, 2);
  printGraph(adj, V);
}
