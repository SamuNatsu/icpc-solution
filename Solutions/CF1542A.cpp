#include <cstdio>

int t, n;
int a[205];

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        int odd = 0, eve = 0;
        for (int i = 1, lmt = (n << 1), a; i <= lmt; ++i) {
            scanf("%d", &a);
            (a & 1 ? odd : eve) += 1;
        }
        puts(odd == eve ? "Yes" : "No");
    }
    return 0;
}
