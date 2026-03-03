#include <iostream>
using namespace std;


int main(){
    int N, ai[100];

    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> ai[i];
    }

    for(int i = 0; i < N - 1; i++) {
        for(int j = 0; j < N - i - 1; j++) {
            if(ai[j] < ai[j + 1]) {
                int temp = ai[j];
                ai[j] = ai[j + 1];
                ai[j + 1] = temp;
            }
        }
    }
    
    cout << ai[0] + ai[1];

    

}