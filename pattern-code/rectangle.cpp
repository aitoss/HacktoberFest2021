// Rectangle pattern
// * * * * * *.......
// * * * * * *.......
// * * * * * *.......


#include<iostream>
using namespace  std;
int main(){
    int row , col;
    cout<<"Enter a no of row :";
    cin>>row;
    cout<<"Enter a no of col :";
    cin>>col;
    for(int i=1;i<=row;i++){
        for(int j=1;j<=col;j++){
            cout<<" * ";
        }
        cout<<endl;
    }
    return 0;
}