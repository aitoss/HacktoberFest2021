// ****** 0-1 pattern
// 1
// 0 1 
// 1 0 1
// 0 1 0 1
// 1 0 1 0 1

#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter an input : ";
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            if((i+j)%2==0){
                cout<<" 1 ";
            }else{
                cout<<" 0 ";
            }
        }
        cout<<endl;
    }
    return 0;  
}