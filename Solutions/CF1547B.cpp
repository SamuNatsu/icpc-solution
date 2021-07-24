#include <cstdio>
#include <cstring>

int t;
bool b[30];
char s[30];

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%s", s);
        memset(b, false, sizeof(b));
        bool f = false;
        for (int i = 0; s[i]; ++i)
            if (b[s[i] - 'a']) {
                f = true;
                break;
            }
            else 
                b[s[i] - 'a'] = true;
        if (f) {
            puts("NO");
            continue;
        }
        int l, r;
        for (l = 0; s[l]; ++l)
            if(s[l] == 'a') {
                r = l;
                break;
            }
        if (!s[l]) {
            puts("NO");
            continue;
        }
        int len = strlen(s);
        f = false;
        char c = 'a';
        while (r - l + 1 != len) {
            ++c;
            if (l - 1 >= 0 && s[l - 1] == c)
                --l;
            else if (r + 1 < len && s[r + 1] == c)
                ++r;
            else {
                f = true;
                break;
            }
        }
        if (f) {
            puts("NO");
            continue;
        }
        puts("YES");
    }
    return 0;
}
