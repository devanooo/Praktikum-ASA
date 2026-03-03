#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define ll long long 

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    ll x,y,n,z = 0;
    
    cin >> x >> y >> n;
    
    ll c = 1;

    for(int i = 0; i < n; i++){
  
        z = x * c;
        if(z % y != 0){
            cout << z << " ";
            c++;
        }
        else{
            c++;
            i--;
        }
    }
      
    
    //kelipatan x yang bukan kelipatan y
    return 0;
}
