template <class T> vector<int> zAlgo(T S) {
	int N = (int) size(S);
	vector<int> A(N);
	for (int i = 1, j = 0; i < N; ++i) {
		if (i + A[i - j] < j + A[j]) {
			A[i] = A[i - j];
		} else {
			A[i] = max(0, j + A[j] - i);
			while (i + A[i] < N && S[A[i]] == S[i + A[i]]) ++A[i];
			j = i;
		}
	}
	A[0] = N;
	return A;
}
