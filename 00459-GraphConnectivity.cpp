#include <bits/stdc++.h>

using namespace std;
void dfs(vector<int> *adjlist,int node,bool *visited){
    visited[node]=1;
    int size=adjlist[node].size();
    for (int i = 0; i < size; ++i) {
        if(visited[adjlist[node][i]]==0)
            dfs(adjlist,adjlist[node][i],visited);
    }
}
int main()
{
    int cases;
    char l;
    cin>>cases;
    string edge;

    while(cases--){

        cin>>l;
        cin.ignore();
        vector<int> adjlist[l-'A'+1];
        bool matrix[26][26]={0};
        while(getline(cin,edge),edge!=""){
            int x=edge[0]-'A';
            int y=edge[1]-'A';

            if(x!=y && matrix[x][y]!=1){
                adjlist[x].push_back(y);
                adjlist[y].push_back(x);
                matrix[x][y]=1;
                matrix[y][x]=1;
            }
        }
        bool visited[l-'A'+1];

        for (int i = 0; i < l-'A'+1; ++i) visited[i]=0;

        int acum=0;

        for (int j = 0; j < l-'A'+1; ++j) {

            if(visited[j]==0){
                dfs(adjlist,j,visited);
                acum++;

            }

        }
        cout<<acum<<endl;
        if(cases!=0)
            cout<<endl;

    }
    return 0;
}

