#include <cstdio>
#include <cstring>

int t, n, m;
char s[100005];
int cnt[100005][30];

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &m);
        memset(cnt, 0, sizeof(cnt));
        for (int i = 0; i < n; ++i) {
            scanf("%s", s);
            for (int j = 0; s[j]; ++j)
                ++cnt[j][s[j] - 'a'];
        }
        for (int i = 1; i < n; ++i) {
            scanf("%s", s);
            for (int j = 0; s[j]; ++j)
                --cnt[j][s[j] - 'a'];
        }
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < 26; ++j)
                if (cnt[i][j]) {
                    putchar(j + 'a');
                    break;
                }
        putchar('\n');
    }
    return 0;
}
