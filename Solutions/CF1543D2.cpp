#include <cstdio>

int t, n, k, r;

int kxor(int a, int b) {
    int rtn = 0, p = 1, t1, t2;
    while (a || b) {
        t1 = a % k;
        t2 = b % k;
        a /= k;
        b /= k;
        rtn += (t1 - t2 + k) % k * p;
        p *= k;
    }
    return rtn;
}

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &k);
        for (int i = 0; i < n; ++i) {
            if (!i)
                puts("0");
            else if (i & 1)
                printf("%d\n", kxor(i - 1, i));
            else
                printf("%d\n", kxor(i, i - 1));
            fflush(stdout);
            scanf("%d", &r);
            if (r)
                break;
        }
    }
    return 0;
}
