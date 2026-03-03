#include <iostream>
#include <vector>
using namespace std;

#define vt vector

int main(){
    int n;
    cin >> n;
    vt<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    int awal = a[0], total = 0, selisih = 0;
    char x = 'z';

    for(int i=0;i<n-1;i++){
        char y = 'z';
        if (a[i] == a[i+1]) {
            continue;
        }
        if(a[i] > a[i+1]){
            y = 'n';
        }
        if(a[i] < a[i+1]){
            y = 't';
        }

        if(x != y && x != '0'){
            selisih = abs(a[i] - awal);
            total = max(total , selisih);
            awal = a[i];
        }

        x = y;

    }

    total = max(total, abs(a[n-1]-awal));

    cout << total;

    

}