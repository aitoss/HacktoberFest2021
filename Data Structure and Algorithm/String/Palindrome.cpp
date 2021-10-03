/*
Palindrome checker in string
*/
#include <iostream>
#include <stdio.h>

//This header file is used to make use of the system defined String methods.
#include <string.h>

using namespace std;

int main()
{
    cout << "\n\nWelcome to Studytonight :-)\n\n\n";
    cout << " =====  Program to Determine whether String is Palindrome or not, in CPP  ===== \n\n";

    //String Variable Declaration
    char s1[100], c = 'a';
    int n1, i = 0;

    cout << "\n\nEnter the String you want to check : ";
    cin >> s1;

    //Computing string length without using system defined method
    while (c != '\0')
    {
        c = s1[i++];
    }

    n1 = i-1;
    char s2[n1+1];

    cout << "Length of the entered string is : " << n1 << "\n\n";

    i = 0;
    //Computing reverse of the String without using system defined method
    while (i != n1 + 1)
    {
        s2[i] = s1[n1 - i - 1];
        i++;
    }

    cout << "Reverse of the entered string is : " << s2 << "\n\n\n";

    i = 0;
    //Logic to check for Palindrome
    while (i != n1)
    {
        if (s2[i] != s1[i])
            break;

        i++;
    }

    if (i != n1)
        cout << "The String \"" << s1 << "\"" << " is not a Palindrome.";
    else
        cout << "The String \"" << s1 << "\"" << " is a Palindrome.";

    cout << "\n\n";

    return 0;
}