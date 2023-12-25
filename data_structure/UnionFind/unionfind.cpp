int root(vector<int>& uf, int u) {
	return (uf[u] < 0) ? u : (uf[u] = root(uf, uf[u]));
}
bool connect(vector<int>& uf, int u, int v) {
	u = root(uf, u);
	v = root(uf, v);
	if (u == v) return false;
	if (uf[u] > uf[v]) swap(u, v);
	uf[u] += uf[v];
	uf[v] = u;
	return true;
}
vector<vector<int>> groups(vector<int>& uf) {
	int N = (int) size(uf);
	vector<vector<int>> A(N);
	for (int i = 0; i < N; ++i) {
		A[root(uf, i)].push_back(i);
	}
	vector<vector<int>> B;
	for (int i = 0; i < N; ++i) {
		if (size(A[i])) {
			B.push_back(A[i]);
		}
	}
	return B;
}
