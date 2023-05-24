#include <bits/stdc++.h>
#define NUM_THREADS 4
#include <omp.h>

using namespace std;
vector<int> arr[1000];
int visited[100]={0};
queue<int>q;

void bfs(int k){
    if(!visited[k]){
        q.push(k);
        visited[k]=-1;

        while (!q.empty())
        {
            int pop_node=q.front();
            q.pop();
            cout<<pop_node<<" ";
            #pragma omp parallel for num_threads(NUM_THREADS)
            for (int i = 0; i < arr[pop_node].size(); i++)
            {
                if (!visited[arr[pop_node][i]])
                {
                    q.push(arr[pop_node][i]);
                    visited[arr[pop_node][i]]=1;
                }
                
            }
            
        }
        
    }
}

int main(){
    int v,e;
    cout<<"Enter no of vertices in graph: ";
    cin>>v;
    cout<<"Enter no of edges: ";
    cin>>e;
    while(e--){
        int p,q;
        cout<<"Enter Starting And Ending vertices: ";
        cin>>p>>q;
        arr[p].push_back(q);
        arr[q].push_back(p);
    }
    bfs(0);
    return 0;
}
