#include <cstdio>

#include <set>
#include <vector>
#include <algorithm>

#define il inline

int fa[100005];
int fnf(int x) {
    return fa[x] == x ? x : (fa[x] = fnf(fa[x]));
}
il bool chk(int x, int y) {
    return fnf(x) == fnf(y);
}
void mrg(int x, int y) {
    int fx = fnf(x), fy = fnf(y);
    fx < fy ? (fa[fy] = fx) : (fa[fx] = fy);
}

int main() {
    while (1) {
        std::set<int> nd;
        std::vector<std::pair<int, int>> vc;
        for (int i = 1; i <= 100000; ++i)
            fa[i] = i;
        int A, B;
        scanf("%d%d", &A, &B);
        if (A == -1)
            break;
        if (A == 0) {
            puts("Yes");
            continue;
        }
        vc.emplace_back(A, B);
        nd.insert(A);
        nd.insert(B);
        while (scanf("%d%d", &A, &B), A) {
            vc.emplace_back(A, B);
            nd.insert(A);
            nd.insert(B);
        }
        int cnt = 0;
        bool f = true;
        for (auto& i : vc)
            if (chk(i.first, i.second)) {
                puts("No");
                f = false;
                break;
            }
            else {
                mrg(i.first, i.second);
                ++cnt;
            }
        if (f)
            puts(nd.size() - cnt == 1 ? "Yes" : "No");
    }
    return 0;
}
