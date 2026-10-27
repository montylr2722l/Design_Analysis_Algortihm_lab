#include<bits/stdc++.h>
using namespace std;

// Compute Prefix Function
void computePrefixFunction(string P, int pi[]) {
    int m = P.length();

    pi[0] = 0;
    int k = 0;

    for (int q = 1; q < m; q++) {
        while (k > 0 && P[k] != P[q]) {
            k = pi[k - 1];
        }

        if (P[k] == P[q]) {
            k++;
        }

        pi[q] = k;
    }
}

// KMP Matcher
void KMP(string T, string P) {
    int n = T.length();
    int m = P.length();
    int pi[m];

    // Compute prefix function
    computePrefixFunction(P, pi);

    int q = 0; //current pattern position
 
    for (int i = 0; i < n; i++) {
        while (q > 0 && P[q] != T[i]) {
            q = pi[q - 1];
        }

        if (P[q] == T[i]) {
            q++;
        }

        if (q == m) {
            cout << "Pattern occurs at index " << i - m + 1 << endl;
            q = pi[q - 1];
        }
    }
}

int main() {
    
    string T, P;
    cout << "Enter text: ";
    cin >> T;
    cout << "Enter pattern: ";
    cin >> P;

    KMP(T, P);
    return 0;
}