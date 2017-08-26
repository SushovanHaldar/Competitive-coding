#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef vector<lli> VI;
void addedge(VI graph[],lli u,lli v)
{
    if(u != v)
    {
        graph[u].push_back(v);
        //graph[v].push_back(u);  
    }
    else
    {
        graph[u].push_back(u);
    }
}
void display(VI graph[],lli n)
{
    lli i;
    for(i=0;i<n;i++)
    {
        cout << "\nNode " << i << " contains:\n";
        VI::iterator itr;
        for(itr = graph[i].begin();itr < graph[i].end();++itr)
        {
            cout << "\nVertex " << *itr;
        }
        cout << endl;
    }
}
void BFS(VI graph[],lli n)
{
    lli v,i;
    VI visited(n,0),distance(n,0);
    deque<lli> dq;
    for(i=0;i<n;i++)
    {
        if(!visited[i])
        {
            visited[i] = 1;
            cout << "\nVisited vertex: " << i << endl;
            dq.push_back(i);
            while(!dq.empty())
            {
                v = dq[0];
                cout << "\nExploring vertex: " << v << endl;
                dq.pop_front();
                VI::iterator itr;
                for(itr = graph[v].begin();itr < graph[v].end();++itr)
                {
                    if(!visited[*itr])          // if already visited then exit
                    {
                        dq.push_back(*itr);
                        visited[*itr] = 1;
                        distance[*itr] = distance[v] + 1;
                        cout << "\nVisited vertex: " << *itr << endl;
                    }
                }
            }
        }
    }
}
int main()
{
	lli i,j,n,u,v,e;
	cout << "Enter the number of vertices:";
	cin >> n;
    VI graph[n];
    cout << "Enter the total number of edges:";
    cin >> e;
    cout << "\nEnter the edges:";
    for(i=0;i<e;i++)
    {
    	cin >> u >> v;
    	addedge(graph,u,v);
    }
    display(graph,n);
    BFS(graph, n);
    return 0;
}