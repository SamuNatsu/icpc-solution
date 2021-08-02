#include <cstdio>
#include <cstring>

#include <algorithm>

#define ll long long

int t, m;
int a[2][100005];
ll f[2][100005];

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &m);
        for (int i = 0; i < 2; ++i)
            for (int j = 1; j <= m; ++j) {
                scanf("%d", &a[i][j]);
                f[i][j] = f[i][j - 1] + a[i][j];
            }
        ll mx = 0x7FFFFFFFFFFFFFFF;
        for (int i = 1; i <= m; ++i)
            mx = std::min(mx, std::max(f[0][m] - f[0][i], f[1][i - 1] - f[1][0]));
        printf("%lld\n", mx);
    }
    return 0;
}
