#include <iostream>
#include <vector>
using namespace std;

#define ll long long
long long faktorial(int x){
    long long hasil = 1;
    for(int i = 2; i <= x; i++){
        hasil *= i;
    }
    return hasil;
}

int main(){
    string s;
    cin >> s;

    int n = s.length();
    string alfabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    vector<int> freq(26, 0);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < 26; j++){
            if(s[i] == alfabet[j]){
                freq[j]++;
                break;
            }
        }
    }   

    ll total = 1;
    for(int i = 0; i < 26; i++){
        if(freq[i] != 0){
            total = total * faktorial(freq[i]);
        }
    }

    ll jawaban = 0 ;
    jawaban = (faktorial(n) / total);

    cout << jawaban;
    
}   