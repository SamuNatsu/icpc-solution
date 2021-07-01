#include <cmath>
#include <cstdio>
#include <algorithm>

int t, n, px, pm;

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 0, a, ax = 0, am = 200; i < n; ++i) {
			scanf("%d", &a);
			if (a > ax) {
				ax = a;
				px = i;
			}
			if (a < am) {
				am = a;
				pm = i;
			}
		}
		int ans = 0;
		if (px < pm)
			ans = std::min({pm + 1, n - px, px + 1 + n - pm});
		else 
			ans = std::min({px + 1, n - pm, pm + 1 + n - px});
		printf("%d\n", ans);
	}
	return 0;
}
