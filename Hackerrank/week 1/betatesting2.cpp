#include <iostream>

using namespace std;

#define ll long long
#define vt vector
#define max 100000
int main(){
    ll N; 
    cin >> N;
    ll a[max];
    for(int i = 0; i < N; i++){
        cin >> a[i]; 
    }
    ll Q;
    cin >> Q; 

    ll n[max], m[max], x[max];
    

    for(int i = 0; i < Q; i++){
        cin >> n[i] >> m[i] >> x[i];

        if(m[i] > N || n[i] < 1 ){
            cout << -1;
            break;
        }
    }
    
    for(int i = 0; i<Q;i++){
        ll darah = 0;
        ll awal = n[i] - 1;
        ll akhir = m[i] -1;

        if(awal < akhir){
            for(int j = awal; j < akhir; j++){
                if(a[j+1] > a[j]){
                    darah += (a[j+1] - a[j]);
                }
                else{
                    continue;
                } 
            }
            
        }
        else {
            for(int j = awal; j>akhir; j--){
                if(a[j-1] > a[j]){
                    darah += a[j-1] - a[j];
                }
                else{
                    continue;
                }
            }
        }

        if(darah > x[i]){
            cout << -1 << endl;
        }
        else{
            cout << x[i] - darah << endl;
        }
    }

    
}


/*melakukan Q kali penjelajahan
tiap penjelajahan ke i diminta bergerak dari
Ni ke Mi
kalau Ni > Mi level mundur, darah nambah
jumlah nyawa Xi di awal penjelajahan ke i
pengurangan darah : misal l level sekarang dan p
adalah level selanjutnya
kalau p > l dara berkurang sebanyak p-l, kalau l > p ga berkurang
kalau total pengurangan nyawa melebihi Xi, game over*/