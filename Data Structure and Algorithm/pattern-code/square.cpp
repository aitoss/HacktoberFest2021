//  square pattern 
//write a program for below output
//  * * * *
//  * * * *
//  * * * *
//  * * * *

#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter a side of square :";
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<" * ";
        }
        cout<<endl;
    }
    return 0;
}