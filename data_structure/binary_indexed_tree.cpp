template <class T> struct BinaryIndexedTree {
	int N;
	vector<T> data;
	BinaryIndexedTree() : BinaryIndexedTree(0) {};
	explicit BinaryIndexedTree(int N) : N(N), data(N + 1) {}
	void add(int k, T x) {
		for (++k; k <= N; k += k & -k) {
			data[k] += x;
		}
	}
	T sum(int k) {
		T ret = 0;
		for (; k > 0; k -= k & -k) {
			ret += data[k];
		}
		return ret;
	}
	T sum(int l, int r) {
		return sum(r) - sum(l);
	}
};
