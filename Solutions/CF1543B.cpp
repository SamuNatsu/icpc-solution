#include <cstdio>

#define ll long long

int t, n;
int a[200005];

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        ll sum = 0;
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &a[i]);
            sum += a[i];
        }
        ll lft = sum % n;
        printf("%lld\n", lft * ((ll)n - lft));
    }
    return 0;
}
