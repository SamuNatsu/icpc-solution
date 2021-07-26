#include <cstdio>
#include <cstring>

#define ll long long

int t, n;
int a[100005], b[200005];

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        memset(b, -1, sizeof(int) * n * 2 + 3);
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &a[i]);
            b[a[i]] = i;
        }
        ll ans = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; (ll)a[i] * j <= ((ll)n << 1); ++j)
                if (b[j] != -1 && b[j] > i && a[i] != j && a[i] * j == i + b[j])
                    ++ans;
        }
        printf("%lld\n", ans);
    }
    return 0;
}
