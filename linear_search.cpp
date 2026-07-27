#include<bits/stdc++.h>
using namespace std;

int linear_search(vector<int> &arr, int key)
{
    for(int i = 0; i < arr.size(); i++)
    {
        if(arr[i] == key)
        {
            return i;
        }
    }

    return -1;
}


int main()
{
    vector<int> arr = {2,3,4,7,8,0};

    int key;
    cout << "Enter element to search: ";
    cin >> key;


    int result = linear_search(arr, key);


    if(result != -1)
        cout << "Element found at index: " << result << endl;
    else
        cout << "Element not found!" << endl;


    return 0;
}
