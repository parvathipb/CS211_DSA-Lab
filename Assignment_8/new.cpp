// C++ implementation of the approach
#include<bits/stdc++.h>
using namespace std;
 
vector<vector<int>> adj;
 
 
// function to add edge to the graph
void addEdge(int x,int y)
{
    adj[x][y] = 1;
    adj[y][x] = 1;
}
 
// Function to perform BFS on the graph
void bfs(int start)
{
    // Visited vector to so that
    // a vertex is not visited more than once
    // Initializing the vector to false as no
    // vertex is visited at the beginning
    vector<bool> visited(adj.size(), false);
    vector<int> q;
    q.push_back(start);
  
    // Set source as visited
    visited[start] = true;
  
    int vis;
    while (!q.empty()) {
        vis = q[0];
  
        // Print the current node
        cout << vis << " ";
        q.erase(q.begin());
  
        // For every adjacent vertex to the current vertex
        for (int i = 0; i < adj[vis].size(); i++) {
            if (adj[vis][i] == 1 && (!visited[i])) {
  
                // Push the adjacent node to the queue
                q.push_back(i);
  
                // Set
                visited[i] = true;
            }
        }
    }
}
  
// Driver code
int main()
{
  // number of vertices
  int v = 5;
 
 
  // adjacency matrix
  adj= vector<vector<int>>(v,vector<int>(v,0));
 
  addEdge(0,1);
  addEdge(0,2);
  addEdge(1,3);
   
  // perform bfs on the graph
  bfs(0);
}

// #include <iostream>
// #include <queue>
// #define SIZE 5
// using namespace std;

// //vertices
// char vertices[SIZE] = {'A', 'B', 'C', 'D', 'E'};
// //array mapping to mark visited vertices
// int  visited[SIZE] = {0};
// //Adjacency Matrix (Graph)
// int adjacencyM[SIZE][SIZE] = {{0, 1, 1, 0, 0},
//                               {1, 0, 0, 1, 0},
//                               {1, 0, 0, 0, 1},
//                               {0, 1, 0 ,0, 0},
//                               {0, 1, 1, 0, 0}};
 
// class BFS{
// public:
//   void solve(int root){
//     queue<int> Queue;

//     //Visit root node and add to the queue
//     visited[root] = 1;
//     Queue.push(root);
   
//     //BFS until queue is empty
//     while(!Queue.empty()){
//       //Pop the vertex and display
//       int current_vertex= Queue.front();
//       Queue.pop();
//       cout << vertices[current_vertex] << " ";

//       //add connected non-visited vertices to the queue
//       int neighbor_Vertex;
//       while((neighbor_Vertex =unvisitedNeighbor(current_vertex)) != -1){
//         //Mark neighbors as visited
//         visited[neighbor_Vertex] = 1;
//         Queue.push(neighbor_Vertex);
//       }
//     }

//   }
  
//   //Function returns index of unvisited connected vertices
//   int unvisitedNeighbor(int index){
//     for(int i=0; i<SIZE; i++){
//       if(adjacencyM[index][i] == 1 && (visited[i] == 0)){
//         return i;
//       }
//     }
//     return -1;
//   }
// };
 
// //Driver Code 
// int main() {
//     BFS bfs;
//     bfs.solve(0);
//     return 0;
// }