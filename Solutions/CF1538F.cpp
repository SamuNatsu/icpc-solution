#include <cstdio>

#define ll long long

int t, l, r;

ll count(ll x) {
    ll rtn = 0;
    for (ll i = 1; i <= x; i *= 10)
        rtn += x / i;
    return rtn - 1;
}

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &l, &r);
        printf("%lld\n", count(r) - count(l));
    }
    return 0;
}
