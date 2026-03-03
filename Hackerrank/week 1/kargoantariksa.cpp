#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
      int N, A[1000];
    int S = 0;
    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> A[i];
    }
    
    int max = -1;
    for(int i = 0; i < N; i++){
        for(int j = i + 1; j < N; j++){
            for(int k = j + 1; k < N; k++){
                S = (A[i] * A[k]) + (A[j] * A[k]) + (A[i] * A[j]);
                if(S % 2 != 0){
                    int total = A[i] + A[j] + A[k];
                    if(total > max){
                        max = total;
                    }
                }
            }
        }
    }
    cout << max;
}
