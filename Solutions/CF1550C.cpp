#include <cmath>
#include <cstdio>

#define il inline
#define ll long long

int t, n;
int a[200005];

struct pt {
    int x, y;
};

il int d(pt a, pt b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}
il bool chk(pt a, pt b, pt c) {
    return d(a, b) != d(a, c) + d(c, b) && d(a, c) != d(a, b) + d(b, c) && d(b, c) != d(b, a) + d(a, c);
}
il bool chk(pt a, pt b, pt c, pt e) {
    return chk(a, b, c) && chk(a, b, e) && chk(a, c, e) && chk(b, c, e);
}

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i)
            scanf("%d", &a[i]);
        ll ans = (n << 1) - 1;
        for (int i = 1; i <= n - 2; ++i)
            if (chk({a[i], i}, {a[i + 1], i + 1}, {a[i + 2], i + 2})) {
                ++ans;
                if (i + 3 <= n && chk({a[i], i}, {a[i + 1], i + 1}, {a[i + 2], i + 2}, {a[i + 3], i + 3}))
                    ++ans;
            }
        printf("%lld\n", ans);
    }
    return 0;
}
