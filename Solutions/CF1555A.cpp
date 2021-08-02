#include <cstdio>

#include <algorithm>

#define ll long long

int t;
ll n;

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%lld", &n);
        if (n <= 6)
            puts("15");
        else 
            printf("%lld\n", 15ll + 5ll * ((n - 5) >> 1));
    }
    return 0;
}
