#include <iostream>
#include <string>
using namespace std;

void printMazePaths(int sr, int sc, int dr, int dc, string psf){
    // write your code here
    if(sr > dr || sc > dc)
    {
        return;
    }
    
    if(sc == dc && sr == dr)
    {
        cout << psf << endl;
        return;
    }
    printMazePaths(sr, sc + 1, dr, dc, psf + "h");
    printMazePaths(sr + 1, sc, dr, dc, psf + "v");
}

int main(){
    int n;
    int m;
    cin >> n >> m;
    printMazePaths(1, 1, n, m, "");
}