//c++ program to print all the combinations of balanced parenthesis

#include <bits/stdc++.h>
using namespace std;
vector<string> generateParenthesis(int n) {
        vector<string>two;
        vector<string>ans;
        if(n==1){two.push_back("{}");return two;} //Returning vector if n==1
        if(n==2){
        two.push_back("{{}}");
        two.push_back("{}{}");
        return two;
        } //Returning vector if n==2, as these are base cases
        
  
          two=generateParenthesis(n-1); //Recursively calling the function
  
          // Assigning the previous values of vector into the present function
        for(int i=0;i<two.size();i++){
            string buf="{",bug="{",bus="{";
            buf = buf+two[i]+"}";
            bug = bug+"}"+two[i];
            bus=two[i]+bus+"}";
            ans.push_back(buf);
            ans.push_back(bus);
            ans.push_back(bug);
            
        }
          
          // Removing the duplicate as kind of this {}{} remains same in either way
        ans.pop_back(); 
        
          
        return ans;
    }
int main(){
    vector<string>ff; //Vector to store all the combinations
      int n=2;
    ff=generateParenthesis(n); //Calling the function

    for (int i = 0; i < ff.size(); ++i)
    {
        cout<<ff[i]<<endl; //Print all the combinations
        /* code */
    }
}
