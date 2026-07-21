#include<bits/stdc++.h>
using namespace std;
int partition(vector<int>&arr, int low , int high ){
    int pivot = arr[high];
    int i = low-1;


    for(int j=low ; j<high; j++){
        if(arr[j]<pivot){
        i++;
        swap(arr[i],arr[j]);    
    }
}
swap(arr[i+1],arr[high]);
return i+1;
}

void quick_sort(vector<int>&arr, int low , int high){
    if(low<high){
        
        int pi = partition(arr, low , high);

        quick_sort(arr , low, pi-1);
        quick_sort(arr, pi+1, high);

    }
}

int binary_search (vector<int>&arr ,int key){
    int low = 0;
    int high = arr.size() - 1;

    while(low<high){
        int mid = (high+low)/2;
        if(arr[mid]==key ){
        return mid ;
        }

        else if(arr[mid < key])
        {
        low = mid+1;
        }

        else{
        high = mid-1;
        }
    }
    return -1;
}


int main (){
    vector<int> arr = {2,5,6,7,8,1,9};
    int n = arr.size();
    quick_sort(arr, 0, n-1);
    
    for (int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    
    }
    cout<<endl;


    //binary search 

    int key ;
    cout<<"enter element to search :";
    cin>>key;

    int index = binary_search(arr,key);
    if(index != -1){
        cout<<"element found at index :"<<index<<endl;
    }
    else {
        cout<<"element not found !"<<endl;
    }

    return 0 ;
}
