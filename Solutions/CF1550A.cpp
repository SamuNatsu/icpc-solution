#include <cstdio>

int t, s;

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &s);
        int ans = 1, lst = 3;
        --s;
        while (s >= lst) {
            s -= lst;
            lst += 2;
            ++ans;
        }
        if (s)
            ++ans;
        printf("%d\n", ans);
    }
    return 0;
}
