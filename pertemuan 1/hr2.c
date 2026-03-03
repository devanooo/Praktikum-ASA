
int HitungBit(int n, int b) {
    if (n < 0) return 0;

    int panjangpola = 1 << (b + 1);   
    int setengahpola = 1 << b;      

    int jmlhpola = (n + 1) / panjangpola; 
    int sisa = (n + 1) % panjangpola;     

    int count = jmlhpola * setengahpola;  /* jmlh dari 0 s/d n yang bit ke-b-nya = 1. */
    if (sisa > setengahpola) {
        count += (sisa - setengahpola);
    }

    return count;
}

int main() {
    int Q;
    scanf("%d", &Q);

    while (Q--) {
        int J, K;
        scanf("%d %d", &J, &K);

        int total = K - J + 1;
        int max = 0;

        for (int b = 0; b < 20; b++) {
            int jumlah1 = HitungBit(K, b) - HitungBit(J - 1, b); /* sama dgn count, tapi range [J..K] */
            if (jumlah1 > max) {
                max = jumlah1;
            }
        }

        int jawab = total - max;
        printf("%d\n", jawab);
    }
    return 0;
}


// blackbox soal no 2
#include <stdio.h>
#include <stdlib.h>

int main() {
    /* -------- baca N dan array A -------- */
    int N;
    if (scanf("%d", &N) != 1) return 0;

    /* indeks mulai dari 1, jadi alokasi N+2 agar index 0 tersedia */
    long long *A = (long long *)malloc((N + 2) * sizeof(long long));
    A[0] = 0;                       /* dummy agar indexing mulai dari 1 */
    for (int i = 1; i <= N; ++i) {
        scanf("%lld", &A[i]);
    }

    /* -------- naikMaju[i] : total kenaikan dari 1 sampai i -------- */
    long long *naikMaju = (long long *)calloc(N + 1, sizeof(long long));
    for (int i = 2; i <= N; ++i) {
        naikMaju[i] = naikMaju[i - 1];
        if (A[i] > A[i - 1]) {
            naikMaju[i] += A[i] - A[i - 1];
        }
    }

    /* -------- naikMundur[i] : total kenaikan dari N sampai i (ke kiri) -------- */
    long long *naikMundur = (long long *)calloc(N + 2, sizeof(long long));
    for (int i = N - 1; i >= 1; --i) {
        naikMundur[i] = naikMundur[i + 1];
        if (A[i] > A[i + 1]) {
            naikMundur[i] += A[i] - A[i + 1];
        }
    }

    /* -------- proses query -------- */
    int Q;
    scanf("%d", &Q);
    while (Q--) {
        int Nawal, Mtujuan;
        long long X;
        scanf("%d %d %lld", &Nawal, &Mtujuan, &X);

        long long totalKehilangan;
        if (Nawal < Mtujuan) {
            /* bergerak ke kanan */
            totalKehilangan = naikMaju[Mtujuan] - naikMaju[Nawal];
        } else {
            /* bergerak ke kiri (termasuk diam di tempat) */
            totalKehilangan = naikMundur[Mtujuan] - naikMundur[Nawal];
        }

        if (totalKehilangan > X) {
            printf("-1\n");
        } else {
            printf("%lld\n", X - totalKehilangan);
        }
    }

    /* -------- bersihkan memori -------- */
    free(A);
    free(naikMaju);
    free(naikMundur);
    return 0;
}

// gpt no 2
#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    scanf("%d", &N);

    long long *A = (long long *) malloc((N + 1) * sizeof(long long));
    long long *naikMaju = (long long *) malloc((N + 1) * sizeof(long long));
    long long *naikMundur = (long long *) malloc((N + 1) * sizeof(long long));

    for (int i = 1; i <= N; i++) {
        scanf("%lld", &A[i]);
    }

    /* Prefix sum kenaikan kalau jalan maju (kiri -> kanan) */
    naikMaju[1] = 0;
    for (int i = 2; i <= N; i++) {
        naikMaju[i] = naikMaju[i - 1];
        if (A[i] > A[i - 1]) {
            naikMaju[i] += (A[i] - A[i - 1]);
        }
    }

    /* Prefix sum kenaikan kalau jalan mundur (kanan -> kiri) */
    naikMundur[N] = 0;
    for (int i = N - 1; i >= 1; i--) {
        naikMundur[i] = naikMundur[i + 1];
        if (A[i] > A[i + 1]) {
            naikMundur[i] += (A[i] - A[i + 1]);
        }
    }

    int Q;
    scanf("%d", &Q);

    while (Q--) {
        int Nawal, Mtujuan;
        long long X;
        scanf("%d %d %lld", &Nawal, &Mtujuan, &X);

        long long totalKehilangan;

        if (Nawal < Mtujuan) {
            totalKehilangan = naikMaju[Mtujuan] - naikMaju[Nawal];
        } else {
            totalKehilangan = naikMundur[Mtujuan] - naikMundur[Nawal];
        }

        if (totalKehilangan > X) {
            printf("-1\n");
        } else {
            printf("%lld\n", X - totalKehilangan);
        }
    }

    free(A);
    free(naikMaju);
    free(naikMundur);

    return 0;
}