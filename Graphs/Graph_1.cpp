#include<iostream>
#include"Queue.h"
using namespace std;
void BFS(int G[7][7], int start, int size) //i is vertex of graph
{
	int i = start;
	struct Queue q;
	q.size = size;
	create(&q, q.size);
	int visited[7] = {0};
	
	//visit vertex
	cout<< i <<" ";
	visited[i] = 1;
	enqueue(&q,i);
	
	while(!isEmpty(&q))
	{
		i = dequeue(&q);
		//explore connected vertices
		 for(int j = 1; j<size; j++)
		 {
		 	if(G[i][j] == 1 && visited[j] == 0)
		 	{
		 	cout<<j<<" ";
		 	visited[j] = 1;
		 	enqueue(&q,j);
			}
		 	
		 }
	}		
}

//DFS
void DFS (int G[][7], int start, int n)
{
	static int visited[7] ={0};
	
	if (visited[start]==0)
	{
		cout<<start<<" ";
		visited[start] = 1;
		for (int j=1; j<n; j++)
		{
			if(G[start][j] == 1 && visited[j] == 0)
				DFS(G,j,n);
		}
	}
}
int main()
{
	// Graph representation by Adjancency Matrix
	int G[7][7] = {{0,0,0,0,0,0,0},
				   {0,0,1,1,0,0,0},
				   {0,1,0,0,1,0,0},
				   {0,1,0,0,1,0,0},
				   {0,0,1,1,0,1,1},
				   {0,0,0,0,1,0,0},
				   {0,0,0,0,1,0,0}};
			   
				   
			DFS(G, 1, 7);	   
				   
		return 0;	   
				   
				   
				   
				   
				   
				   
				   
				   
				   
}