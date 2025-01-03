#include<bits/stdc++.h>
using namespace std; 

void searching(int arr[n], int x){
    int index= x%n;
    int k=0;
    while(arr[index]!=x && k<=n){
        index=(index+1)%n;
        k++;
    }   
    if(arr[index]==x){
        cout<<"Element"<<x<<"present at index:"<<index;
    }else{
        cout<<"Element not found";
    }
}

int main(){
    int n;
    cin>>n; //size of hash table
    int arr[n]={-1};
    bool x= true;
    while(x){
        int y;
        cout<<"Enter the value to be entered:";
        cin>>y;
        int j=y%n;
        int m=0;
        while(arr[j]!=-1 && m<=n){
            j=(j+1)%n;
            m++;
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
