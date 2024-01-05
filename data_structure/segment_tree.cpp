template <class T> struct SegmentTree {
	int N;
	vector<T> node;
	SegmentTree() : N(0) {}
	explicit SegmentTree(int N_) {
		for (N = 1; N < N_; N <<= 1);
		node.resize(N << 1);
	}
	template <class S> explicit SegmentTree(const vector<S> &v) {
		int N_ = (int) size(v);
		for (N = 1; N < N_; N <<= 1);
		node.resize(N << 1);
		for (int i = 0; i < N_; ++i) node[N + i] = T(v[i]);
		for (int i = N; i--; ) pull(i);
	}
	T &operator[](int i) {
		return node[N + i];
	}
	inline void pull(int i) {
		node[i].pull(node[i << 1], node[i << 1 | 1]);
	}
	template <class S> void change(int p, const S &x) {
		node[p += N] = T(x);
		for (; p >>= 1; pull(p));
	}
	T get(int l, int r) {
		if (l == r) return T();
		T L, R, t;
		for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
			if (l & 1) { t.pull(L, node[l++]); L = t; }
			if (r & 1) { t.pull(node[--r], R); R = t; }
		}
		t.pull(L, R);
		return t;
	}
	T allGet() {
		return node[1];
	}
};
