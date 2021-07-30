#include <cstdio>

#include <algorithm>

#define ll long long

int t, n;
int a[200005];
ll ans;

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
            scanf("%d", &a[i]);
        ans = -1;
        for (int i = 1; i < n; ++i)
            ans = std::max(ans, (ll)a[i] * a[i - 1]);
        printf("%lld\n", ans);
    }
    return 0;
}
