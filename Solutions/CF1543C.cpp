#include <cmath>
#include <cstdio>

#define il inline
#define EPS 1e-8

il bool feq(double a, double b) {
    return fabs(a - b) < EPS;
}
il bool flq(double a, double b) {
    return a < b || feq(a, b);
}

int t;
double c, m, p, v;

double dfs(double a, double b, double c, double v, int cnt, double pct) {
    if (feq(c, 0.0))
        return 0.0;
    double ans = cnt * c * pct;
    if (!feq(a, 0.0)) {
        double ta = a, tb = b, tc = c;
        if (a > v) {
            ta = a - v;
            if (!feq(b, 0.0)) {
                tb += v / 2.0;
                tc += v / 2.0;
            }
            else
                tc += v;
        }
        else {
            ta = 0;
            if (!feq(b, 0.0)) {
                tb += a / 2.0;
                tc += a / 2.0;
            }
            else
                tc += a;
        }
        ans += dfs(ta, tb, tc, v, cnt + 1, pct * a);
    }
    if (!feq(b, 0.0)) {
        double ta = a, tb = b, tc = c;
        if (b > v) {
            tb = b - v;
            if (!feq(a, 0.0)) {
                ta += v / 2.0;
                tc += v / 2.0;
            }
            else
                tc += v;
        }
        else {
            tb = 0;
            if (!feq(a, 0.0)) {
                ta += b / 2.0;
                tc += b / 2.0;
            }
            else
                tc += b;
        }
        ans += dfs(ta, tb, tc, v, cnt + 1, pct * b);
    }
    return ans;
}

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%lf%lf%lf%lf", &c, &m, &p, &v);
        printf("%.12f\n", dfs(c, m, p, v, 1, 1.0));
    }
    return 0;
}
