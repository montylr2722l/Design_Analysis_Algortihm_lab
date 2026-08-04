#include<bits/stdc++.h>
using namespace std;

struct item {
    int value;
    int weight;

};

bool compare( item a , item b){
    double ratio1 = (double)a.value/a.weight;
    double ratio2 = (double)b.value/b.weight;

    return ratio1>ratio2;
}

double fractionalKnapsack( int capacity, vector<item> &items){
sort(items.begin(), items.end(), compare);

double total_value = 0.0;

for(int i = 0; i<items.size(); i++){

    if(items[i].weight <= capacity){
        total_value += items[i].value;
        capacity -= items[i].weight; 
    }
    else{
        double fraction = (double)capacity/items[i].weight;
        total_value += items[i].value * fraction;
        break;
    }
}
return total_value;
}

int main(){
    int n;
    cout<<"enter number of items: "<<endl;
    cin>>n;

    vector<item> items(n);
    cout<<"\n enter value and weight of each item :\n";
    for(int i = 0;i<n; i++){
        cin>>items[i].value>>items[i].weight;
    }
    int capacity;
    cout<<"\n enter knapstack capacity :";
    cin>>capacity;

    double maxProfit = fractionalKnapsack(capacity, items);
    cout << "\nMaximum Profit = " << maxProfit << endl;

    return 0;


}