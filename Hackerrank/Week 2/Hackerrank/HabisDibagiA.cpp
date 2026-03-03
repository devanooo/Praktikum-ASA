/* Mohon untuk Mengisi identitas berikut sebelum mengerjakan
 Nama : Devano Trestanto
 NIM  : 24060124140149
 Lab  : D1
*/

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

#define ll long long
#define vt vector


bool isprime(int x){
    for(int i = 2; i * i <= x; i++){
        if(x % i == 0){
            return false;
        }
    }

    return true;
}

int main() {
    ll q;
    cin >> q;
     ll l[q], r[q];
    
    
    for(int i = 0; i< q; i++){
        cin >> l[i] >> r[i];
    }

    if(q == 1){
            int awal = l[0];
            int akhir = r[0];
            int count = 0;
            for(int j = awal; j <= akhir;j++){
                if(isprime(j)){
                    count++;
                }
            }
            cout << count << endl;
            
            for(int j = awal; j <= akhir;j++){
                if(isprime(j)){
                    cout << j << " ";
                }
            }
    }

    if(q > 1){
        for(int i = 0; i < q; i++){
            ll count = 0;
            int awal = l[i];
            int akhir = r[i];
            
            
            for(int j = awal; j <= akhir;j++){
                if(isprime(j)){
                    count++;
                }
            }

            cout << count << endl;
        }
    }
    
    return 0;
}


/*Gimana, Aman ?
Tinggalkan saran di sini : 

*/


