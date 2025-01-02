#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n; //size of hash table
    int arr[n]={0};
    bool x= true;
    while(x){
        int y;
        cout<<"Enter the value to be entered:";
        cin>>y;
        int j=y%n;
        while(arr[j]!=-1){
            j=(j+1)%n;
        }
        arr[j]=y;
        bool k;
       // cout<<'You want to add another number? '<<endl<<'Yes or No :';
        cin>>k;
        if(k){
            x=false;
        }     
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<endl;
    }
}
