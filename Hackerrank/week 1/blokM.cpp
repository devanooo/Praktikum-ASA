#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define ll long long

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    ll N, T,Ntiket[1000];

    cin >> N;
    cin >> T;
    
    for(int i = 0; i< N; i++){
        cin >> Ntiket[i];
    }

    
    int maxkali = -1;
    for(int i = 0; i <N; i++){
        
        for(int j = i+1; j <N; j++){
            if((Ntiket[i] + Ntiket[j]) == T){
                if((Ntiket[i]*Ntiket[j]) > maxkali){
                    maxkali = Ntiket[i]*Ntiket[j];
                }
            }   
        }
    }

    cout << maxkali;
    return 0;
}


/*N nomor tiket penumpang hari ini, T angka target
nyari sepasang tiket yang kalo dijumlahin hasilnya == T
bisa jadi ada banyak pasangan yang jumlahnya sama,
jadi cari yang perkaliannya paling besar
*/