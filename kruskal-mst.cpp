#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, e;

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> e;

    vector<vector<int>> edges;

    cout << "Enter edges (u v weight):\n";

    for(int i = 0; i < e; i++)
    {
        int u, v, weight;

        cin >> u >> v >> weight;

        edges.push_back({u, v, weight});
    }

    // Sort edges according to weight
    sort(edges.begin(), edges.end(),
        [](vector<int> a, vector<int> b)
        {
            return a[2] < b[2];
        });

    vector<int> parent(n);

    for(int i = 0; i < n; i++)
    {
        parent[i] = i;
    }

    int totalCost = 0;
    int count = 0;

    for(int i = 0; i < e; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int weight = edges[i][2];

        // Find parent
        int pu = u;
        while(parent[pu] != pu)
        {
            pu = parent[pu];
        }

        int pv = v;
        while(parent[pv] != pv)
        {
            pv = parent[pv];
        }

        // If parents are different, no cycle
        if(pu != pv)
        {
            cout << u << " - " << v
                 << " : " << weight << endl;

            totalCost += weight;

            parent[pv] = pu;

            count++;
        }

        if(count == n - 1)
        {
            break;
        }
    }

    cout << "Minimum Cost = "
         << totalCost << endl;

    return 0;
}
