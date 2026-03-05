/* Mohon untuk Mengisi identitas berikut sebelum mengerjakan
 Nama : Devano Trestanto
 NIM  : 24060124140149
 Lab  : D1
*/

#include <iostream>
#include <vector>
using namespace std;
#define ll long long
#define vt vector

string s1,s2;
ll len[91];

char level(int n, ll k){
    if(n == 1) return s1[k-1];
    if(n == 2) return s2[k-1];

    if(k <= len[n-2])
        return level(n-2,k);
    else
        return level(n-1,k-len[n-2]);
}


int main(){
    int q, n;

    cin >> n >> q;

    cin >> s1 >> s2;

    vector<int> l(q);
    vector<long long> x(q);
    vector<char> v(q);
    len[1] = s1.length();
    len[2] = s2.length();

    for(int i=3;i<=90;i++){
        len[i] = len[i-2] + len[i-1];
        if(len[i] > 1000000000000000000LL) len[i] = 1000000000000000000LL;
    }

    for(int i = 0; i <q;i++){
        cin >> l[i] >> x[i] >> v[i];
    }

    int benar = 0;
    for(int i=0;i<q;i++){
        if(level(l[i],x[i]) == v[i]){
            benar++;
        }
        else{
            cout << l[i];
            return 0;
        }
    }
    

    cout << "1000000007";
    
    
}