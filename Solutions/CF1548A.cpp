#include <cstdio>

#include <algorithm>

int n, m, q;
int in[200005];

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0, u, v; i < m; ++i) {
        scanf("%d%d", &u, &v);
        if (u > v)
            std::swap(u, v);
        ++in[u];
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i)
        if (!in[i])
            ++ans;
    scanf("%d", &q);
    while (q--) {
        int op;
        scanf("%d", &op);
        if (op == 3)
            printf("%d\n", ans);
        else if (op == 1) {
            int u, v;
            scanf("%d%d", &u, &v);
            if (u > v)
                std::swap(u, v);
            if (!in[u])
                --ans;
            ++in[u];
        }
        else {
            int u, v;
            scanf("%d%d", &u, &v);
            if (u > v)
                std::swap(u, v);
            if (in[u] == 1)
                ++ans;
            --in[u];
        }
    }
    return 0;
}
