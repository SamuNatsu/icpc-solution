#include <cstdio>

#define il inline

int T, N, M;

int fa[1005];
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
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &N, &M);
        for (int i = 1; i <= N; ++i)
            fa[i] = i;
        int ans = N;
        for (int i = 0, A, B; i < M; ++i) {
            scanf("%d%d", &A, &B);
            if (!chk(A, B)) {
                --ans;
                mrg(A, B);
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
