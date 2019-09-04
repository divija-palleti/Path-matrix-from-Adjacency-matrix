
#include<bits/stdc++.h> 
using namespace std; 

int A[4][4] = {{0, 1, 0, 0},{0, 0, 0, 1},{0, 0, 0, 0},{1, 0, 1, 0}};
  
class Graph 
{ 
    int V; // No. of vertices 
    bool **tc; 
    list<int> *adj; // array of adjacency lists 
    void DFSUtil(int u, int v); 
public: 
    Graph(int V); // Constructor 
  
    // add an edge to graph 
    void addEdge(int v, int w) {
    	adj[v].push_back(w);
    	} 
  
   
    void transitiveClosure(); 
}; 

Graph::Graph(int V) 
{ 
    this->V = V; 
    adj = new list<int>[V]; 
  
    tc = new bool* [V]; 
    for (int i=0; i<V; i++) 
    { 
        tc[i] = new bool[V]; 
        memset(tc[i], false, V*sizeof(bool)); 
    } 
} 


// A recursive DFS traversal function that finds all reachable vertices for s. 
void Graph::DFSUtil(int s, int v) 
{ 
    // Mark reachability from s to t as true. 
    tc[s][v] = true; 
  
    // Find all the vertices reachable through v 
    list<int>::iterator i; 
    for (i = adj[v].begin(); i != adj[v].end(); ++i) 
        if (tc[s][*i] == false) 
            DFSUtil(s, *i); 
} 



void Graph::transitiveClosure() 
{ 
	int n=4;
	int count =0;
    
    for (int i = 0; i < V; i++) 
        DFSUtil(i, i); 
        
    for (int i=0; i<n; i++) 
            { 
                count=0;
                for (int j=0; j<n; j++) 
                {
                    if(A[i][j]==0)
                    count++;
			
                }
                if(count==n)
                {
                    tc[i][i]=false;
                }  
            } 
  
    for (int i=0; i<V; i++) 
    { 
        for (int j=0; j<V; j++) 
            cout << tc[i][j] << " "; 
        cout << endl; 
    } 
}




int main() 
{ 
    
     
     Graph g(4); 
     int n=4;
     for(int i=0;i<n;i++)
            {
                // a.push_back(i);
                for(int j=0;j<n;j++)
                    {
                     if(A[i][j]==1)
                     {
                     	g.addEdge(i,j);
                     }
                       
                    }
            }
    
  
    cout << "Path  matrix is \n"; 
    g.transitiveClosure(); 
  
    return 0; 
} 