#include<bits/stdc++.h>
using namespace std;
int main(){
int n;

cout<<"enter number of vertices: ";
cin >> n;

vector<vector<int>> graph(n, vector<int>(n));

cout<<"enter adjancency matrix : \n";
for(int i = 0; i < n; i++){
for(int j=0; j<n; j++){
cin>>graph[i][j];
}
}

vector<bool> visited(n, false);
visited[0] = true;
int totalCost = 0;

cout<<"\n edges in minimum spanning tree:\n";

for(int count = 0; count<n-1; count++){
int minWeight = INT_MAX;
int u = -1;
int v = -1;

for(int i=0; i<n; i++){
if(visited[i]){
for (int j=0;j<n; j++){
if(!visited[j] && graph[i][j] != 0  &&  graph[i][j] < minWeight){
minWeight = graph[i][j];
u = i;
v = j;
}
}
}
}

if(v == -1){
cout<<"graph is disconnected. mst cannot be formed.\n";
return 0;
}


visited[v] = true;

cout<< u << " - " <<v << ":"<< minWeight << endl;
totalCost += minWeight;
}
cout<< "minimum Cost = "<< totalCost<< endl;
return 0;
}
