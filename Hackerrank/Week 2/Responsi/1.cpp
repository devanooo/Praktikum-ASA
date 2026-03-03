/* Mohon untuk Mengisi identitas berikut sebelum mengerjakan
 Nama : Devano Trestanto
 NIM  : 24060124140149
 Lab  : D1
*/

#include <iostream>
#include <vector>
using namespace std;


int main() {
    int N;
    cin >> N;
    int A[N];
    int L = 0;
    int R = 0;

    for(int i = 0; i < N; i++){
        cin >> A[i];
    }

    int res = A[0];
 
      for(int i = 0; i < N; i++) {
        int currSum = 0;
        for(int j = i; j < N; j++) {
            currSum = currSum + A[j];
            if(currSum > res){
                L = i;
                R = j;
            }
            res = max(res, currSum);
        }
    }

    cout << res;
    cout << L + 1 << R + 1;

    return 0;
}


/*Gimana, Aman ?
Tinggalkan saran di sini : 

*/