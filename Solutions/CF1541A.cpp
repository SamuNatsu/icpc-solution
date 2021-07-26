#include <cstdio>

int t, n;

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        if (n & 1) {
            for (int i = 1; i <= n - 3; i += 2)
                printf(" %d %d" + (i == 1), i + 1, i);
            if (n == 3)
                puts("3 1 2");
            else 
                printf(" %d %d %d\n", n, n - 2, n - 1);
        }
        else {
            for (int i = 1; i <= n; i += 2)
                printf(" %d %d" + (i == 1), i + 1, i);
            putchar('\n');
        }
    }
    return 0;
}
