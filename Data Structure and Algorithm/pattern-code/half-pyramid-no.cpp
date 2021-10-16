
//  Half pyramid using no
//  1
//  1 2 
//  1 2 3
//  1 2 3 4 5

#include<iostream>
using namespace std;
int main(){
    int row;
    cout<<"Enter a no of Row : ";
    cin>>row;
    for(int i=1;i<=row;i++){
        for(int j=1;j<=i;j++){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    return 0;
}
