#include <cstdio>
#include <cstring>

#define ll long long

int t, n, m;

int head[400005];
struct e {
    int to, next;
} edge[400005];
void addE(int x, int y) {
    edge[++head[0]] = {y, head[x]};
    head[x] = head[0];
}

int mk[400005], ls1[400005], ls2[400005], mk1[400005], mk2[400005];
void dfs1(int u) {
    mk[u] = 1;
    for (int i = head[u]; i; i = edge[i].next)
        if (mk[edge[i].to] == 0)
            dfs1(edge[i].to);
        else if (mk[edge[i].to] == 1)
            ls1[++ls1[0]] = edge[i].to;
        else
            ls2[++ls2[0]] = edge[i].to;
    mk[u] = 2;
}
void dfs2(int u) {
    mk1[u] = 1;
    for (int i = head[u]; i; i = edge[i].next)
        if (mk1[edge[i].to] == 0)
            dfs2(edge[i].to);
    mk1[u] = 2;
}
void dfs3(int u) {
    mk2[u] = 1;
    for (int i = head[u]; i; i = edge[i].next)
        if (mk2[edge[i].to] == 0)
            dfs3(edge[i].to);
    mk2[u] = 2;
}

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &m);
        memset(head, 0, sizeof(int) * (n + 5));
        memset(mk, 0, sizeof(int) * (n + 5));
        memset(mk1, 0, sizeof(int) * (n + 5));
        memset(mk2, 0, sizeof(int) * (n + 5));
        ls1[0] = ls2[0] = 0;
        for (int i = 0, a, b; i < m; ++i) {
            scanf("%d%d", &a, &b);
            addE(a, b);
        }
        dfs1(1);
        for (int i = 1; i <= ls1[0]; ++i)
            dfs2(ls1[i]);
        for (int i = 1; i <= ls2[0]; ++i)
            dfs3(ls2[i]);
        for (int i = 1; i <= n; ++i)
            printf(" %d" + (i == 1), mk[i] ? (mk1[i] ? -1 : (mk2[i] ? 2 : 1)) : 0);
        putchar('\n');
    }
    return 0;
}
