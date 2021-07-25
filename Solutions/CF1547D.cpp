#include <cstdio>

int t, n;
int x[200005], y[200005];

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i)
            scanf("%d", &x[i]);
        for (int i = 2; i <= n; ++i)
            y[i] = ((x[i - 1] ^ y[i - 1]) | x[i]) ^ x[i];
        for (int i = 1; i <= n; ++i)
            printf(" %d" + (i == 1), y[i]);
        putchar('\n');
    }
    return 0;
}
