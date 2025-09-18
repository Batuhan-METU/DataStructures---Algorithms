#include <iostream>
#include <vector>
#include <map>

using namespace std; 

class Graph {
    private: 
        map<int, vector<int>> adjList; 

    public: 
        void addVertex(int vertex) { // Method for adding a new vertex
            // If giving vertex as parameter already exists, don't do anything. If not add it.
            if (adjList.find(vertex) == adjList.end()) {
                vector <int> neighbors; // Create a new vector list. 
                adjList[vertex] = neighbors; // Key-Value pairing. 
            }
        }

        void addEdge(int from, int to) { // Method for adding a new edge.
            // Add a edge between the vertices.
            addVertex(from); 
            addVertex(to); 

            adjList[from].push_back(to); 
            adjList[to].push_back(from); 
        }

        void printGraph() {
            int numVertices = adjList.size(); 

            for (int i = 0; i<numVertices; i++) {
                int vertex = i;
                
                auto it = adjList.begin(); 
                advance(it, vertex); 
                
                vector<int>& neighbors = adjList[it->first]; 

                cout << "Adjacent to Vertex " << it->first << ": "; 

                for (int j = 0; j<neighbors.size(); j++) {
                    cout << neighbors[j] << " "; 
                }
                cout << endl; 
            }
        }

        void removeVertex(int vertex) {
            // Check whether the giving vertex is in the graph. 
            if (adjList.find(vertex) != adjList.end()) {
                adjList.erase(vertex); 

            // Remove the edges that related to giving vertex.
            for (map<int, vector<int>>::iterator it = adjList.begin(); it != adjList.end(); it++) {
                int key = it->first; // key 
                vector<int>& neighbors = it->second; // value

                vector<int>::iterator vecIt = neighbors.begin(); 
                while(vecIt != neighbors.end()) {
                    if (*vecIt == vertex) {
                        vecIt = neighbors.erase(vecIt); 
                    }
                    else {
                        vecIt++; 
                    }
                }
            } 
            }
        }

        
        void removeEdge(int from, int to) {
            if (adjList.find(from) != adjList.end() && adjList.find(to) != adjList.end()) {
                vector<int>& fromNeighbors = adjList[from]; 
                vector<int>& toNeighbors = adjList[to]; 

                for (int i = 0; i<fromNeighbors.size(); i++) {
                    if (fromNeighbors[i] == to) {
                        fromNeighbors.erase(fromNeighbors.begin() + i); // remove i. vertex 
                        break; 
                    }
                }

                for (int i = 0; i<toNeighbors.size(); i++) {
                    if (toNeighbors[i] == from) {
                        toNeighbors.erase(toNeighbors.begin() + i); // remove i. vertex 
                        break; 
                    }
                }
            }
        }
}; 


