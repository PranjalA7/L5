#include <bits/stdc++.h>
#define NUM_THREADS 4
#include <omp.h>

using namespace std;

vector<int>arr[100];
int visited[100]={0};

void dfs(int k){
    if(!visited[k]){
        cout<<k<<" ";
        visited[k]=1;
        #pragma omp parallel for num_threads(NUM_THREADS)
        for (int i = 0; i < arr[k].size(); i++)
        {
            if(!visited[arr[k][i]]){
                dfs(arr[k][i]);
            }
        }
        
    }
}

int main(){
    int v,e;
    cout<<"Enter no of vertices: ";
    cin>>v;
    cout<<"Enter no of edges: ";
    cin>>e;
    while(e--){
        int p,q;
        cout<<"Enter Starting And Ending Vertices:";
        cin>>p>>q;
        arr[p].push_back(q);
        arr[q].push_back(p);
    }
    dfs(0);
    return 0;
}
