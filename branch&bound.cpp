#include <iostream>
#include <vector>
using namespace std;

int n;
int cost[10][10];
int answer = 999999;

int bound(int level, vector<int>& assigned)
{
    int b = 0;

    for(int i = level; i < n; i++)
    {
        int minimum = 999999;

        for(int j = 0; j < n; j++)
        {
            if(assigned[j] == 0)
            {
                minimum = min(minimum, cost[i][j]);
            }
        }

        b += minimum;
    }

    return b;
}

void solve(int level, int currentCost, vector<int>& assigned)
{
    if(level == n)
    {
        answer = min(answer, currentCost);
        return;
    }

    int b = currentCost + bound(level, assigned);

    if(b >= answer)
        return;

    for(int j = 0; j < n; j++)
    {
        if(assigned[j] == 0)
        {
            assigned[j] = 1;

            solve(level + 1,
                  currentCost + cost[level][j],
                  assigned);

            assigned[j] = 0;
        }
    }
}

int main()
{
    cout << "Enter n: ";
    cin >> n;

    cout << "Enter cost matrix:\n";

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> cost[i][j];
        }
    }

    vector<int> assigned(n, 0);

    solve(0, 0, assigned);

    cout << "Minimum Assignment Cost = "
         << answer << endl;

    return 0;
}