template <class T> vector<int> ZAlgo(T& S) {
	int N = (int) size(S);
	vector<int> A(N);
	for (int i = 1, j = 0; i < N; ++i) {
		if (i + A[i - j] < j + A[j]) {
			A[i] = A[i - j];
		} else {
			A[i] = max(j + A[j] - i, 0);
			while (i + A[i] < N && S[A[i]] == S[i + A[i]]) ++A[i];
			j = i;
		}
	}
	A[0] = N;
	return A;
}
