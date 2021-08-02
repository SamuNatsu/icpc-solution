#include <cstdio>

int t, n;
char s1[200005], s2[200005];

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        scanf("%s%s", s1, s2);
        int ans = 0;
        for (int i = 0; i < n; ++i)
            if (s2[i] == '1') {
                if (s1[i] == '0') {
                    ++ans;
                    s1[i] = '*';
                }
                else {
                    if (i && s1[i - 1] == '1') {
                        ++ans;
                        s1[i - 1] = '*';
                    }
                    else if (i < n - 1 && s1[i + 1] == '1') {
                        ++ans;
                        s1[i + 1] = '*';
                    }
                }
            }
        printf("%d\n", ans);
    }
    return 0;
}
