#include <cstdio>
#include <cstring>

#include <algorithm>

#define ll long long

int q, n, k;
int a[300005], t[300005];
ll l[300005], r[300005], ct[300005];

int main() {
    scanf("%d", &q);
    while (q--) {
        memset(ct, 0x7F, sizeof(ct));
        scanf("%d%d", &n, &k);
        for (int i = 0; i < k; ++i)
            scanf("%d", &a[i]);
        for (int i = 0; i < k; ++i)
            scanf("%d", &t[i]);
        for (int i = 0; i < k; ++i)
            ct[a[i]] = t[i];
        ll lst = 0x7FFFFFFF;
        for (int i = 1; i <= n; ++i) {
            lst = std::min(lst + 1, ct[i]);
            l[i] = lst;
        }
        lst = 0x7FFFFFFF;
        for (int i = n; i >= 1; --i) {
            lst = std::min(lst + 1, ct[i]);
            r[i] = lst;
        }
        for (int i = 1; i <= n; ++i)
            printf(" %lld" + (i == 1), std::min(l[i], r[i]));
        putchar('\n');
    }
    return 0;
}
