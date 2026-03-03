// #include <stdio.h>

// #define MAX 100005

// int main() {
//     int n;
//     scanf("%d", &n);

//     int A[MAX];
//     for (int i = 0; i < n; i++) {
//         scanf("%d", &A[i]);
//     }

//     int q;
//     scanf("%d", &q);

//     while (q--) {
//         int Ni, Mi, Xi;
//         scanf("%d %d %d", &Ni, &Mi, &Xi);

//         // ubah ke index array (0-based)
//         Ni--; 
//         Mi--;

//         int nyawa = Xi;

//         if (Ni < Mi) {  
//             // jalan maju
//             for (int i = Ni; i < Mi; i++) {
//                 if (A[i+1] > A[i]) {
//                     nyawa -= (A[i+1] - A[i]);
//                     if (nyawa < 0) break;
//                 }
//             }
//         } else {
//             // jalan mundur
//             for (int i = Ni; i > Mi; i--) {
//                 if (A[i-1] > A[i]) {
//                     nyawa -= (A[i-1] - A[i]);
//                     if (nyawa < 0) break;
//                 }
//             }
//         }

//         if (nyawa < 0) printf("-1\n");
//         else printf("%d\n", nyawa);
//     }

//     return 0;
// }


#include <stdio.h>

#define MAX 100005

int A[MAX];
long long maju[MAX];
long long mundur[MAX];

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &A[i]);
    }

    maju[1] = 0;
    for (int i = 2; i <= n; i++) {
        long long naik = 0;
        if (A[i] > A[i-1])
            naik = A[i] - A[i-1];

        maju[i] = maju[i-1] + naik;
    }

    mundur[n] = 0;
    for (int i = n-1; i >= 1; i--) {
        long long naik = 0;
        if (A[i] > A[i+1])
            naik = A[i] - A[i+1];

        mundur[i] = mundur[i+1] + naik;
    }

    int q;
    scanf("%d", &q);

    while (q--) {
        int Ni, Mi;
        long long Xi;
        scanf("%d %d %lld", &Ni, &Mi, &Xi);

        long long damage;

        if (Ni < Mi) {
            damage = maju[Mi] - maju[Ni];
        } else {
            damage = mundur[Mi] - mundur[Ni];
        }

        if (damage > Xi) printf("-1\n");
        else printf("%lld\n", Xi - damage);
    }

    return 0;
}
