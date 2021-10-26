/*
Hello there!!!
Problem Statement:- Find the number of good ways to split a string in two different strings so that both strings have same number of distnict characters.
Example: "aacaba"
Output:  2
Explanation : Lets consider, we have divided in the following ways:
            -> (a, acaba), (aa,caba), (aacab,a) = These are not a good string because both strings in each group don't have same number of distnict characters 
            -> (aaca, ba), (aac, aba) = These are good string because both strings in each group have same number of distnict characters

            So, the answer is 2

Example: "abcd"
Output: 1
Explanation : Lets divide the string into following ways:
            -> (a,bcd), (abc,d) = These are not a good strings because both strings  in each group don't have same number of distnict characters
            -> (ab,cd) = This is a good string because both strings have same number of distnict characters. 

            So, the answer is 1

*/

// The simple o(N) approach using 2 map data structure
// We can set its level to medium :)

//Lets code it

#include<bits/stdc++.h>
using namespace std;
int main(){
    // input
    string s;
    cin>>s;

    /* using 2 maps, so that in first can map all the characters, and then by second map, we can check if both strings have same density or both maps have same size */

    unordered_map<char,int>m1;
    unordered_map<char,int>m2;
    int count=0;
    for(int i=0; i<s.size(); i++)m1[s[i]]++;
        
    for(int i=0; i<s.size();i++){
        m2[s[i]]++;
        m1[s[i]]--;
        if(m1[s[i]]==0) m1.erase(s[i]);
        if(m1.size()==m2.size())count++;
    }
    
    cout<<"count of the ways string have good split :- " <<count<<endl;
    return 0;
    

}

// Notice that when you have map[key]==0, make sure you delete that cell after because it still exists in the map, hence may cause no change in size :)
// I hope you like the approach, Thank you <3 