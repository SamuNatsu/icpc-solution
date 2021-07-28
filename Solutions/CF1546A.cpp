#include <cstdio>

#include <vector>

int t, n;
int a[105], b[105];
std::vector<std::pair<int, int>> ls;

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i)
            scanf("%d", &a[i]);
        for (int i = 1; i <= n; ++i)
            scanf("%d", &b[i]);
        int l = 1, r = n;
        ls.clear();
        while (l <= n || r > 0) {
            while (a[l] <= b[l] && l <= n)
                ++l;
            while (a[r] >= b[r] && r > 0)
                --r;
            if (l > n || r <= 0)
                break;
            while (a[l] > b[l] && a[r] < b[r]) {
                ls.emplace_back(l, r);
                --a[l];
                ++a[r];
            }
        }
        bool f = false;
        for (int i = 1; i <= n; ++i)
            if (a[i] != b[i]) {
                f = true;
                break;
            }
        if (f) {
            puts("-1");
            continue;
        }
        printf("%llu\n", ls.size());
        for (auto& i : ls) 
            printf("%d %d\n", i.first, i.second);
    }
    return 0;
}
