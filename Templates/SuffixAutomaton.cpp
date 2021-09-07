#define fill(pnt, val) memset(pnt, val, sizeof(pnt))
#define copy(from, to) memcpy(to, from, sizeof(to))

struct SuffixAutomaton {
	struct Node {
		int next[26];
		int len, fa;
		Node(): len(0) {
			fill(next, 0);
		}
		Node& operator=(const Node& tmp) {
			copy(tmp.next, next);
			len = tmp.len;
			fa = tmp.fa;
			return *this;
		}
	} *T;
	int las, tot;
	SuffixAutomaton(int sz): T(new Node[sz << 1]), las(1), tot(1) {}
	~SuffixAutomaton() {delete[] T;}
	void ins(int c) {
		int p = las, np = ++tot;
		las = tot;
		T[np].len = T[p].len + 1;
		T[np].fa = p;
		for (; p && !T[p].next[c]; p = T[p].fa)
			T[p].next[c] = np;
		if (!p)
			T[np].fa = 1;
		else {
			int q = T[p].next[c];
			if (T[q].len == T[p].len + 1)
				T[np].fa = q;
			else {
				int nq = ++tot;
				T[nq] = T[q];
				T[nq].len = T[p].len + 1;
				T[np].fa = T[q].fa = nq;
				for (; T[p].next[c] == q; p = T[p].fa)
					T[p].next[c] = nq;
			}
		}
	}
	void build(const char* str) {
		for (int i = 0; str[i]; ++i)
			ins(str[i] - 'a');
	}
};
