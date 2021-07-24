#include <cstdio>

int t, n, a, b;
char s[105];

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d%d", &n, &a, &b);
        scanf("%s", s);
        if (b >= 0) {
            printf("%d\n", n * (a + b));
            continue;
        }
        int cnt = 1;
        for (int i = 1; s[i]; ++i)
            if (s[i] != s[i - 1])
                ++cnt;
        cnt >>= 1;
        ++cnt;
        printf("%d\n", a * n + b * cnt);
    }
    return 0;
}
