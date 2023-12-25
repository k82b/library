template <class T>
class BinaryIndexedTree {
	private:
		int N;
		vector<T> data;
		T sum(int k) {
			int ret = 0;
			for (; k > 0; k -= k & -k) {
				ret += data[k - 1];
			}
			return ret;
		}
		
	public:
		BinaryIndexedTree() : N(0) {};
		explicit BinaryIndexedTree(int N) : N(N), data(N + 1) {}
		void add(int p, T x) {
			for (++p; p <= N; p += p & -p) {
				data[p - 1] += x;
			}
		}
		T sum(int l, int r) {
			return sum(r) - sum(l);
		}
};
