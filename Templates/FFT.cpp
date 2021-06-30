// FFT Template
// Sample: Big interger multiplication
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define il inline

const double PI = acos(-1.0);

// Quick read
il char gc() {
	static char buff[0xFFFF], *p1 = buff, *p2 = buff;
	return p1 == p2 && (p2 = (p1 = buff) + fread(buff, 1, 0xFFFF, stdin), p1 == p2) ? EOF : *p1++;
}
int rS(char* str) {
	int l = 0;
	char c = gc();
	while ((c == ' ' || c == '\n' || c == '\r') && c != EOF)
		c = gc();
	while (c != ' ' && c != '\n' && c != '\r' && c != EOF) {
		str[l++] = c;
		c = gc();
	}
	str[l] = '\0';
	return l;
}

// Do not use std::complex in order to get better performance
class cpx {
	public:
		double r, i;
		cpx(double a = 0.0, double b = 0.0): r(a), i(b) {}
		cpx operator+(const cpx& tmp) {
			return cpx(r + tmp.r, i + tmp.i);
		}
		cpx operator-(const cpx& tmp) {
			return cpx(r - tmp.r, i - tmp.i);
		}
		cpx operator*(const cpx& tmp) {
			return cpx(r * tmp.r - i * tmp.i, r * tmp.i + i * tmp.r);
		}
};

// Binary reverse
int rvs[2100005];

// FFT(op == true) or IFFT(op == false)
void FFT(cpx* A, int n, int len, bool op) {
	// Reverse
	for (int i = 0; i < n; ++i)
		if (i < rvs[i])
			std::swap(A[i], A[rvs[i]]);
	// Start calculating
	for (int i = 1; i < n; i <<= 1) {
		// FFT need sin(PI / i), but IFFT need -sin(PI / i)
		cpx wn(cos(PI / i), sin(PI / i) * (op ? 1.0 : -1.0));
		for (int j = 0; j < n; j += (i << 1)) {
			cpx w(1.0, 0.0);
			for (int k = 0; k < i; ++k, w = w * wn) {
				cpx x = A[j + k], y = w * A[i + j + k];
				A[j + k] = x + y;
				A[i + j + k] = x - y;
			}
		}
	}
	// If is IFFT
	if (!op)
		for (int i = 0; i < n; ++i)
			A[i].r /= n;
}

int lA, lB;
char A[1000005], B[1000005];

int n = 1, len = 0;
cpx cA[2100005], cB[2100005];

int sA[2100005];

int main() {
	// Read integer as string
	lA = rS(A);
	lB = rS(B);
	// Build complex
	for (int i = lA - 1; i >= 0; --i)
		cA[lA - i - 1].r = A[i] - '0';
	for (int i = lB - 1; i >= 0; --i)
		cB[lB - i - 1].r = B[i] - '0';
	for (int sum = lA + lB + 1; n <= sum; n <<= 1, ++len);
	// Get binary reverse
	for (int i = 1; i < n; ++i)
		rvs[i] = (rvs[i >> 1] >> 1) | ((i & 1) << (len - 1));
	// FFT
	FFT(cA, n, len, true);
	FFT(cB, n, len, true);
	// Convolution
	for (int i = 0; i < n; ++i)
		cA[i] = cA[i] * cB[i];
	// IFFT
	FFT(cA, n, len, false);
	// Output
	for (int i = 0; i < n; ++i) {
		sA[i] += int(cA[i].r + 0.5);
		sA[i + 1] += sA[i] / 10;
		sA[i] %= 10;
	}
	int lst = n;
	while (lst && sA[lst] <= 0)
		--lst;
	for (int i = lst; i >= 0; --i)
		putchar(sA[i] + '0');
	puts("");
	return 0;
}
