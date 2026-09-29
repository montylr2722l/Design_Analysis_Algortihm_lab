// WAP to implement assignment problem by using branch and bound technique.

#include <bits/stdc++.h>
using namespace std;

int n;
int cost[20][20];
int bestCost = INT_MAX;
vector<int> bestAssignment;

// Calculate lower bound
int calculateBound(int person, vector<bool> &assigned) {
    int bound = 0;

    for (int i = person; i < n; i++) {
        int minCost = INT_MAX;

        for (int j = 0; j < n; j++) {
            if (!assigned[j] && cost[i][j] < minCost)
                minCost = cost[i][j];
        }

        bound += minCost;
    }

    return bound;
}

// Branch and Bound function
void assignment(int person, int currentCost, vector<bool> &assigned, vector<int> &currentAssignment) {
    // All persons assigned
    if (person == n) {
        if (currentCost < bestCost) {
            bestCost = currentCost;
            bestAssignment = currentAssignment;
        }
        return;
    }

    // Try assigning every available job
    for (int job = 0; job < n; job++) {
        if (!assigned[job]) {
            int newCost = currentCost + cost[person][job];

            assigned[job] = true;
            currentAssignment[person] = job;

            // Calculate lower bound
            int bound = newCost + calculateBound(person + 1, assigned);

            // Branch and Bound
            if (bound < bestCost) {
                assignment(person + 1, newCost, assigned, currentAssignment);
            }

            // Backtrack
            assigned[job] = false;
        }
    }
}

int main() {
    cout << "Enter number of persons/jobs: ";
    cin >> n;

    cout << "Enter cost matrix:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> cost[i][j];
        }
    }

    vector<bool> assigned(n, false);
    vector<int> currentAssignment(n);

    assignment(0, 0, assigned, currentAssignment);

    cout << "\nMinimum Cost = " << bestCost << endl;

    cout << "Assignment:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Person " << i + 1 << " -> Job " << bestAssignment[i] + 1 << " (Cost = " << cost[i][bestAssignment[i]] << ")" << endl;
    }

    return 0;
}