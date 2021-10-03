#include <bits/stdc++.h>

using namespace std;

int fact(int n,int k){
  if(n==0){
    return k;
  }
  return fact(n-1,n*k);
}

int main(){
  int a;
  cin >> a;
  cout << fact(a,1) << '\n';
}