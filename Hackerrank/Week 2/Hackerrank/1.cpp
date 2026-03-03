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
int main() {
    ll q;
    cin >> q;
     ll l[q], r[q];
    
    
    for(int i = 0; i< q; i++){
        cin >> l[i] >> r[i];
    }

    if(q == 1){
        ll count = 0;
        for(int i = l[0]; i < r[0]; i++){
            for(int j = 2; j < sqrt(l[i]);j++){
                if(l[i] > 1 && l[i] % j != 0){
                    count++;
                    cout << l[i] << " ";
                }
                else{
                    continue;
                }
            }
        }
    }

    else{
        ll count = 0;

        for(int i = l[0]; i < r[0]; i++){
            for(int j = 2; j < sqrt(l[i]);j++){
                if(l[i] > 1 && l[i] % j != 0){
                    count++;
                    for(int i = 0; i < q;i++){
                        cout << count << endl;
                    }
                }
                else{
                    continue;
                }
            }
        }

        

    }
    return 0;
}


/*Gimana, Aman ?
Tinggalkan saran di sini : 

*/


