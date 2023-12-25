class UnionFind {
	private:
		int N;
		vector<int> par;
	public:
		UnionFind() : UnionFind(0) {}
		UnionFind(int N) : N(N), par(N, -1) {}
		int root(int u) {
			return (par[u] < 0) ? u : (par[u] = root(par[u]));
		}
		bool connect(int u, int v) {
			u = root(u);
			v = root(v);
			if (u == v) return false;
			if (par[u] > par[v]) swap(u, v);
			par[u] += par[v];
			par[v] = u;
			return true;
		}
		bool same(int u, int v) {
			return root(u) == root(v);
		}
		int size(int u) {
			return -par[root(u)];
		}
		vector<vector<int>> groups() {
			vector<vector<int>> A(N);
			for (int i = 0; i < N; ++i) {
				A[root(i)].push_back(i);
			}
			vector<vector<int>> B;
			for (int i = 0; i < N; ++i) {
				if (!empty(A[i])) {
					B.push_back(A[i]);
				}
			}
			return B;
		}
};
