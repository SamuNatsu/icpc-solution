#include <cstdio>
#include <algorithm>

#define ll long long

int t, n;
int d[100005];

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
			scanf("%d", &d[i]);
		std::sort(d, d + n);
		ll ans = d[n - 1], lst = 0;
		for (int i = 1; i < n; ++i) {
			lst += (ll)(d[i] - d[i - 1]) * i;
			ans -= lst;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
