int root(vector<int>& uf, int u) { return (uf[u] < 0) ? u : (uf[u] = root(uf, uf[u])); }
bool connect(vector<int>& uf, int u, int v) {
	u = root(uf, u);
	v = root(uf, v);
	if (u == v) return false;
	if (uf[u] > uf[v]) swap(u, v);
	uf[u] += uf[v];
	uf[v] = u;
	return true;
}
