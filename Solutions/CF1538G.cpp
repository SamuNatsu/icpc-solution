#include <cmath>
#include <cstdio>

#include <algorithm>

#define ll long long

ll t, x, y, a, b;

int main() {
    scanf("%lld", &t);
    while (t--) {
        scanf("%lld%lld%lld%lld", &x, &y, &a, &b);
        if (a == b) {
            printf("%lld\n", std::min(x, y) / a);
            continue;
        }
        if (a < b)
            std::swap(a, b);
        ll l = 0, r = 1e10;
        while (l + 1 < r) {
            ll m = (l + r) >> 1;
            ll mr = floorl((x - b * m) * 1.0l / (a - b)), ml = ceill((y - a * m) * 1.0l / (b - a));
            if (std::max(ml, 0ll) <= std::min(mr, m))
                l = m;
            else 
                r = m;
        }
        printf("%lld\n", l);
    }
    return 0;
}
