/* Mohon untuk Mengisi identitas berikut sebelum mengerjakan
 Nama : Devano Trestanto
 NIM  : 24060124140149
 Lab  : D1
*/

#include <stdio.h>

#define MAXN 100005

int A[MAXN];
int forward[MAXN];
int backward[MAXN];

int main() {
    int N;
    scanf("%d", &N);

    for (int i = 1; i <= N; i++) {
        scanf("%d", &A[i]);
    }

    forward[1] = 0;
    for (int i = 2; i <= N; i++) {
        int diff = A[i] - A[i-1];
        if (diff > 0) forward[i] = forward[i-1] + diff;
        else forward[i] = forward[i-1];
    }

    backward[1] = 0;
    for (int i = 2; i <= N; i++) {
        int diff = A[i-1] - A[i];
        if (diff > 0) backward[i] = backward[i-1] + diff;
        else backward[i] = backward[i-1];
    }

    int Q;
    scanf("%d", &Q);

    while (Q--) {
        int Ni, Mi;
        int Xi;
        scanf("%d %d %d", &Ni, &Mi, &Xi);

        int damage;

        if (Ni < Mi) {
            damage = forward[Mi] - forward[Ni];
        } else {
            damage = backward[Ni] - backward[Mi];
        }

        if (damage > Xi) printf("-1\n");
        else printf("%d\n", Xi - damage);
    }

    return 0;
}