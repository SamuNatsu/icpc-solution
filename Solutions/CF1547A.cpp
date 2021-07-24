#include <cmath>
#include <cstdio>

int t, xa, ya, xb, yb, xf, yf;

bool in(int a, int b, int c) {
    return (a < c && c < b) || (b < c && c < a);
}

int dis(int xa, int ya, int xb, int yb) {
    return abs(xa - xb) + abs(ya - yb);
}

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d%d%d%d%d", &xa, &ya, &xb, &yb, &xf, &yf);
        if ((xa == xb && xa == xf && in(ya, yb, yf)) || (ya == yb && ya == yf && in(xa, xb, xf)))
            printf("%d\n", dis(xa, ya, xb, yb) + 2);
        else 
            printf("%d\n", dis(xa, ya, xb, yb));
    }
    return 0;
}
