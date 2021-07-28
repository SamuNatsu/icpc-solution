#include <cmath>
#include <cstdio>

#include <algorithm>

#define ll long long

ll gcd(ll a, ll b) {
    return b ? gcd(b, a % b) : a;
}

int t;
ll a, b;

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%lld%lld", &a, &b);
        if (a == b) {
            puts("0 0");
            continue;
        }
        if (a < b)
            std::swap(a, b);
        ll t = b % (a - b);
        printf("%lld %lld\n", a - b, t > a - b - t ? a - b - t : t);
    }
    return 0;
}
