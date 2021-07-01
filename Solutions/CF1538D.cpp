#include <cstdio>

int t, a, b, k;

bool apr[40000];
int prl[5000];

int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}
int sep(int x) {
	int rtn = 0;
	for (int i = 1; x != 1 && i <= prl[0]; ++i)
		while (x != 1 && x % prl[i] == 0) {
			x /= prl[i];
			++rtn;
		}
	if (x > 1)
		++rtn;
	return rtn;
}
int gm() {
	if (a == b)
		return 0;
	int g = gcd(a, b);
	if (g == a || g == b)
		return 1;
	return 2;
}

int main() {
	for (int i = 2; i * i < 40000; ++i)
		for (int j = i * i; j < 40000; j += i)
			apr[j] = true;
	for (int i = 2; i < 40000; ++i)
		if (!apr[i])
			prl[++prl[0]] = i;
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d%d", &a, &b, &k);
		int mx = sep(a) + sep(b), mn = gm();
		if ((mn <= k && k <= mx && k != 1) || (mn <= k && k <= mx && k == 1 && mn == 1))
			puts("Yes");
		else 
			puts("No");
	}
	return 0;
}
