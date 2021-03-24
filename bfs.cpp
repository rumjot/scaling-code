#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class graph
{
	int num_vertices;
	list<int> *adjlist;
	int tree[10][10];
	public:
		graph(int V)
		{
			num_vertices=V;
			for(int i=0;i<10;i++)
			 for(int j=0;j<10;j++)
			 tree[i][j]=-1;
			adjlist=new list<int>[V];
		}
		void addedge(int u,int w)
		{
			adjlist[u].push_back(w);
		}
		void printgraph()
		{
			int i;
			for(i=0;i<num_vertices;i++)
			{
				cout<<i;
				list<int>::iterator it;
				for(it=adjlist[i].begin();it!=adjlist[i].end();it++)
				{
					cout<<"->"<<(*it)<<" ";
				}
				cout<<endl;
			}
		}
		void bfs(int s)
		{
			bool *discover=new bool[num_vertices];
			for(int i=0;i<num_vertices;i++)
			   discover[i]=false;
			list<int>queue;
			discover[s]=true;
			queue.push_back(s);
			list<int>::iterator i;
			int t=0;
			while(!queue.empty())
			{
				int j=0;
				s=queue.front();
				queue.pop_front();
				for(i=adjlist[s].begin();i!=adjlist[s].end();i++)
				{
					if(!discover[*i])
					{
						discover[*i]=true;
						queue.push_back(*i);
						tree[t][j++]=s;
						
						tree[t][j]=(*i);
						j++;
					}
				}
				t++;
			}   
		}
		void display()
		{
			int i=0,j=0;
			while(tree[i][j]!=-1)
			{
				
				while(tree[i][j]!=-1)
				{
				 cout<<tree[i][j]<<",";
				 j++;	
				}
				cout<<endl;
				j=0;
				 i++;
			}
			
			
		}
};
int main()
{

	graph g(4);
	g.addedge(0,1);
	g.addedge(3,1);
	g.addedge(2,3);
	g.addedge(0,2);
	g.addedge(3,0);
	cout<<"VALUES IN THE GRAPH"<<endl;
	g.printgraph();
	g.bfs(2);
	cout<<endl;
	cout<<"IN BREADTH FIRST SEARCH TRAVERSAL EDGES ARE IN BETWEEN"<<endl;
	g.display();
	return 8;
}

