#include <cstdio>

#include <algorithm>

int t, k, n, m;
int a[105], b[105], c[205];

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d%d", &k, &n, &m);
        for (int i = 1; i <= n; ++i)
            scanf("%d", &a[i]);
        for (int i = 1; i <= m; ++i)
            scanf("%d", &b[i]);
        c[0] = 0;
        bool fail = false;
        for (int l = 1, r = 1; l <= n || r <= m;) {
            bool f = true;
            while (a[l] && a[l] <= k && l <= n) {
                c[++c[0]] = a[l];
                ++l;
                f = false;
            }
            while (b[r] && b[r] <= k && r <= m) {
                c[++c[0]] = b[r];
                ++r;
                f = false;
            }
            if (f) {
                f = true;
                while (!a[l] && l <= n) {
                    c[++c[0]] = a[l];
                    ++l;
                    f = false;
                    ++k;
                }
                while (!b[r] && r <= m) {
                    c[++c[0]] = b[r];
                    ++r;
                    f = false;
                    ++k;
                }
                if (f) {
                    puts("-1");
                    fail = true;
                    break;
                }
            }
        }
        if (!fail) {
            for (int i = 1; i <= c[0]; ++i)
                printf(" %d" + (i == 1), c[i]);
            putchar('\n');
        }
    }
    return 0;
}
