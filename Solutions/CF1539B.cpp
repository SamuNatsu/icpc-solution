#include <cstdio>

#define ll long long

int n, q, l, r;
char s[100005];
int tot[100005][26];

int main() {
    scanf("%d%d", &n, &q);
    scanf("%s", s + 1);
    for (int i = 1; s[i]; ++i) {
        for (int j = 0; j < 26; ++j)
            tot[i][j] = tot[i - 1][j];
        ++tot[i][s[i] - 'a'];
    }
    while (q--) {
        scanf("%d%d", &l, &r);
        ll ans = 0;
        for (int i = 0; i < 26; ++i)
            ans += (i + 1) * (tot[r][i] - tot[l - 1][i]);
        printf("%lld\n", ans);
    }
    return 0;
}