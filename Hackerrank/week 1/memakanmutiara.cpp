#include <iostream>
#include <vector>

using namespace std;

#define ll long long
int main(){
    ll N,Y,X;
    cin >> N >> Y >> X;

    ll a[1000], mutiara = 0;

    for(int i = 0; i<N;i++){
        cin >> a[i];
    }

    for(int i = 0;i<N;i++){
        
        Y--;
        
        
        if(a[i] >= 1 && a[i] <= 6){
            Y += a[i];
        }
        
        if(a[i] == 7){
            if(Y + a[i] <= N - i - 1){
                Y += a[i];
            }
            else mutiara++;
        }
        
        if(Y == 0){
            break;
        }
        else{
            continue;
        }
        
    }

    if(mutiara > X){
        cout << mutiara;
    }
    else if(mutiara < X){
        cout << -1;
    }
    else cout << X;
}


/*mengumpulkan x mutiara, 
awalnya hanya mampu berjalan sejauh y meter dari titik awal
berjalan satu arah dan tidak dapat kembali
setiap meter berisi satu buah item
makanan 1-7
mutiara 7(termasuk makanan)
!= selain makanan 
kalau makan makanan n bertambah y +n meter jarak tempuh 
mutiara yang dimakan tidak termasuk yang dikumpulkan*/

/*3 3 3 9*/