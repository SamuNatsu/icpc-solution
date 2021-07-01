#include <cstdio>
#include <algorithm>

int t, n, l, r;
int a[200005];

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d%d", &n, &l, &r);
		for (int i = 0; i < n; ++i)
			scanf("%d", &a[i]);
		std::sort(a, a + n);
		long long ans = 0;
		for (int i = 0; i < n; ++i) {
			ans += std::upper_bound(a, a + n, r - a[i]) - a;
			ans -= std::lower_bound(a, a + n, l - a[i]) - a;
			if (l <= (a[i] << 1) && (a[i] << 1) <= r)
				--ans;
		}
		printf("%lld\n", ans >> 1);
	}
	return 0;
}
