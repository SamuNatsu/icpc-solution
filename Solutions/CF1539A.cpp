#include <cstdio>
#include <algorithm>

#define ll long long

ll k, n, x, t;

int main() {
    scanf("%lld", &k);
    while (k--) {
        scanf("%lld%lld%lld", &n, &x, &t);
        ll p = n - t / x;
        if (p > 0)
            printf("%lld\n", t / x * p + ((t / x - 1) * (t / x) >> 1));
        else
            printf("%lld\n", (n - 1) * n >> 1);
    }
    return 0;
}