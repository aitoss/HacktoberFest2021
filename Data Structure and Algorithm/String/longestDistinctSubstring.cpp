#include <bits/stdc++.h>

using namespace std;

int longestUniqueSubsttr(string s){
  int i=0;
  int j=0;
  int n=s.length();
  int count[256]={0};
  
  int ans=0;
  int cur=0;
  while(i<n){
    if(count[s[i]]==1){
      while(s[j]!=s[i]){
        count[s[j]]--;
        j++;
      }
      count[s[j]]--;
      j++;
    }
    
    count[s[i]]++;
    i++;
    cur=i-j;
    ans=max(ans,cur);
  }
  
  return ans;
}

int main(){
  string s;
  cin >> s;
  int ans=longestUniqueSubsttr(s);
  cout << ans << '\n';
  return 0;
}

/* Explaination - 
Task - Find the length of longest substring of current string with all distinct characters.

This can be easily solved by using two pointer approach and using a hash table of constant size 256.
We can take two indices and keep increasing first index until we distinct elements and as soon as we
reach a character which is already present in our string then we can keep incrementing our previous
variable until it removes previous occur of that element. In this way we can easily get all substrings
in our string which have only distinct character and we can easily output the length of longest string
among all possible strings.
*/