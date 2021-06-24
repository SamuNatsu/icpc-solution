#include <cstdio>
#include <algorithm>

#define il inline
#define ll long long

il char gc() {
	static char buff[0xFFFF], *p1 = buff, *p2 = buff;
	return p1 == p2 && (p2 = (p1 = buff) + fread(buff, 1, 0xFFFF, stdin), p1 == p2) ? EOF : *p1++;
}
ll rdI() {
	ll t = 0;
	char c = gc();
	while (c < '0' || c > '9')
		c = gc();
	while (c >= '0' && c <= '9') {
		t = t * 10 + c - '0';
		c = gc();
	}
	return t;
}

ll n, k, x;
ll a[200005];

int top;
struct nd {
	int pos;
	ll gap;
	bool operator<(const nd& tmp) const {
		return gap < tmp.gap;
	}
} ps[200005];

int main() {
	n = rdI();
	k = rdI();
	x = rdI();
	for (int i = 0; i < n; ++i)
		a[i] = rdI();
	std::sort(a, a + n);
	for (int i = 1; i < n; ++i)
		if (a[i] - a[i - 1] > x)
			ps[top++] = {i - 1, a[i] - a[i - 1]};
	std::sort(ps, ps + top);
	int ans = top + 1;
	for (int i = 0; i < top; ++i) {
		ll ned = ps[i].gap / x - (ps[i].gap % x ? 0 : 1);
		if (ned > k)
			break;
		--ans;
		k -= ned;
	}
	printf("%d\n", ans);
	return 0;
}
