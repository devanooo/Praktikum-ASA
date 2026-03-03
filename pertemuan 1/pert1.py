import sys
input = sys.stdin.readline


def itung(x, b):
    if x < 0:
        return 0
    block = 1 << (b + 1)      
    half = 1 << b             

    full = (x + 1) // block
    sisa = (x + 1) % block

    return full * half + max(0, sisa - half)

def itungrange(L, R, b):
    return itung(R, b) - itung(L - 1, b)

Q = int(input().strip())

for _ in range(Q):
    J, K = map(int, input().split())
    length = K - J + 1

    X = 0

    b = 0
    while (1 << b) <= K:
        cnt = itungrange(J, K, b)
        X = max(X, cnt)
        b += 1

    
    print(length - X)

    