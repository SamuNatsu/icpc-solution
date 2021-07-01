#include <cstdio>
#include <algorithm>

int t, n;
int a[200005];

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		int sum = 0;
		bool sme = true;
		for (int i = 0; i < n; ++i) {
			scanf("%d", &a[i]);
			sum += a[i];
			if (i > 0 && a[i] != a[i - 1])
				sme = false;
		}
		if (sme) {
			puts("0");
			continue;
		}
		if (sum % n) {
			puts("-1");
			continue;
		}
		std::sort(a, a + n);
		for (int i = n - 1, tot = 0; i >= 0; --i) {
			tot += a[i];
			if (i > 0 && a[i - 1] > sum / n)
				continue;
			printf("%d\n", n - i);
			break;
		}
	}
	return 0;
}
