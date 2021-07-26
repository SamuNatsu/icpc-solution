#include <cstdio>

#define ll long long

int t, n, a, b;

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d%d", &n, &a, &b);
        if (a == 1) {
            puts((n - 1) % b ? "No" : "Yes");
            continue;
        }
        if (b == 1) {
            puts("Yes");
            continue;
        }
        int tg = n % b;
        bool f = false;
        for (ll i = 1; i <= n; i *= a)
            if (i % b == tg) {
                f = true;
                break;
            }
        puts(f ? "Yes" : "No");
    }
    return 0;
}
