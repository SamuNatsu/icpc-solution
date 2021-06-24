#include <cstdio>
#include <algorithm>

#define ll long long

int n;

struct nd {
	ll a, b;
	bool operator<(const nd& tmp) const {
		return b == tmp.b ? a > tmp.a : b < tmp.b;
	}
} it[100005];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%lld%lld", &it[i].a, &it[i].b);
	std::sort(it, it + n);
	int l = 0, r = n - 1;
	ll ans = 0, tot = 0;
	while (l <= r)
		if (tot + it[r].a <= it[l].b) {
			tot += it[r].a;
			ans += it[r].a << 1;
			--r;
		}
		else {
			ll tmp = std::max(0ll, it[l].b - tot);
			ans += tmp << 1;
			it[r].a -= tmp;
			tot += tmp + it[l].a;
			ans += it[l].a;
			++l;
		}
	printf("%lld\n", ans);
	return 0;
}
