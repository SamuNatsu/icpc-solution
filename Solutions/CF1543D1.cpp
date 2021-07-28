#include <cstdio>

int t, n, k, r;

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &k);
        int q = 0, lst = 0;
        for (int i = 0; i < n; ++i) {
            q = lst ^ i;
            lst ^= q;
            printf("%d\n", q);
            fflush(stdout);
            scanf("%d", &r);
            if (r)
                break;
        }
    }
    return 0;
}
