#include <cstdio>

#include <set>
#include <vector>
#include <algorithm>

#define ll long long

int t, n;
int a[200005];

std::vector<int> prime;
int vis[1000005];

std::set<int> fact[200005];

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int main() {
    // Euler's sieve
    for (int i = 2; i <= 1000000; ++i) {
        if (!vis[i]) {
            prime.emplace_back(i);
            vis[i] = i;
        }
        for (size_t j = 0; j < prime.size() && i * prime[j] <= 1000000; ++j) {
            vis[i * prime[j]] = prime[j];
            if (i % prime[j] == 0)
                break;
        }
    }

    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        int g; // GCD
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
            g = (i ? gcd(g, a[i]) : a[i]);
        }

        // Factorization
        for (int i = 0; i < n; ++i) {
            int t = a[i] / g;
            while (t != 1) {
                fact[i].insert(vis[t]);
                t /= vis[t];
            }
        }

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (auto& p : fact[i]) {
                int l = (i + n - 1) % n, r = i, cnt = 0;
                while (fact[l].count(p) > 0) {
                    fact[l].erase(p);
                    --l;
                    ++cnt;
                    if (l < 0)
                        l = n - 1;
                }
                while (fact[r].count(p) > 0) {
                    if (i != r)
                        fact[r].erase(p);
                    ++r %= n;
                    ++cnt;
                }
                ans = std::max(ans, cnt);
            }
            fact[i].clear();
        }
        printf("%d\n", ans);
    }
    return 0;
}
