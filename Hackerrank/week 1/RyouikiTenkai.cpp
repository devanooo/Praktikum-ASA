#include <iostream>
using namespace std;


int main(){
    int SA, X, Y, N, HP[100005], t;
    
    bool menang = true;

    cin >> SA >> X >> Y >> N;
    
    for(int i = 0; i < N; i++){
        cin >> HP[i];
    }
    
    cin >> t;

    int totalHP = SA + (t * X);

    for(int i = 0; i < N; i++){
        if (HP[i] > totalHP){
            HP[i] - (t * Y);
            menang = false;
        }
    }

    if(menang = true){
        printf("WIN");
    }
    else{
        printf("FALSE");
    }
}
