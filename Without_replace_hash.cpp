#include <bits/stdc++.h>
using namespace std;

void insertion(int arr[][2],int v) {

    int val = v%10;  
    //cout<<val<<endl;
    int i = 0;
    while(i < 10) {
        //cout<<arr[val][0]<<endl; 
        if(arr[val][0] == -1){  
            arr[val][0]= v;
            cout << "Successfully inserted the value"<< endl;
            cout<<i<<endl;
            return;
        }else {
            if (arr[val][1]==-1){
                int p=val;
                int k=(p+1)%10;
                while(arr[k][0]!=-1){
                    p++;
                }
                arr[k][0]=v;
                arr[val][1]=k;
                return;
            }
            else{
                val=(val+1)%10;
            }
            
        }
        cout<<i<<endl;
        i++;
        

    }
    cout<<"Table is full"<<endl;
    return;  
}



void display(int arr[][2]) {
    for(int i=0;i<10;i++){
        cout<<"For i="<<i<<" value is: "<<arr[i][0]<<" " <<arr[i][1]<<endl;
    }
}


// double calculate(int arr[]) {
//     int count = 0;
//     for(int i=0;i<10;i++) {
//         if(arr[i] != -1 && arr[i] != -2){
//             count++;
//         }
//     }
//     return (double)count;
// }

// void deletion(int n, int arr[][2]) {
//     int comp=0;
//     int val=n%10;
//     int i=0;
//     while(i<10) {
//         comp++;
//         int change = (val+i*i)%10;
//         if(arr[change]==n){  
//             arr[change]=-2;  
//             cout<<"Successfully deleted the value "<<endl;
//             cout<<"No. of comparisons are: "<<comp<<endl;
//             return;
//         }
//         if(arr[change]==-1){  
//             cout << "Value not found" << endl;
//             cout << "No. of comparisons are: " << comp << endl;
//             return;
//         }
//         i++;
//     }
//     cout<<"Value not found"<<endl;
// }

void search(int n, int arr[][2]) {
    int comp=0;
    int val=n%10;
    int i = 0;
    while (i < 10) {
        comp++;
        // int j=(val+i)%10;
        if(arr[val][0]==n) {  
            cout<<"Value found at location: "<<val<<endl;
            cout<<"No. of comparisons are: "<<comp<<endl;
            return;
        }else if(arr[val][0]==-1){  
            cout<<"Value is not present in table"<<endl;
            cout<<"No. of comparisons are: "<< comp<<endl;
            return;
        }else{
            if(arr[val][1]==-1){
                cout<<"Value is not present in table"<<endl;
                cout<<"No. of comparisons are: "<< comp<<endl;
                return;
            }else{
                val=arr[val][1];
            }
        }
        i++;
    }
    cout<<"Value is not present in table"<<endl;
}

int main(){
    int arr[10][2]={-1};
    for(int i=0;i<10;i++){
        arr[i][0]=-1;
        arr[i][1]=-1;
    }

    int menu;

    while (menu != 6) {
        cout << "Enter your choice (1->Insert  2->Display  3->Deletion  4->Search  5->Load factor 6->Exit): ";
        cin >> menu;
        if(menu==1){
            int n;
            cout<<"Enter value you want to enter: ";
            cin>>n;
            insertion(arr, n);
        }else if(menu==2){
            cout<<"Displaying the Hash table" << endl;
             display(arr);
        }else if(menu==3){
            int v;
            cout<<"Enter value you want to delete: ";
            cin>>v;
            // deletion(v, arr);
        }else if(menu==4){
            int v;
            cout<<"Enter value you want to search: ";
            cin>>v;
            search(v, arr);
        }else if(menu==5){
            // double lf=calculate(arr)/10.0;
            // cout<<"Load Factor is: "<<lf<< endl;
        }else if(menu==6){
            cout<<"Successfully exited from program"<< endl;
        }else{
            cout<<"Enter valid option: ";
        }
    }
    return 0;

}
