#include <iostream>
using namespace std;

int main(){

    int N = 5;
    for(int i = 0; i < N; i++){
        for(int j = i+1; j < N; j++){
            cout << "[" << i << "," << j <<"]";
        }
    }
}