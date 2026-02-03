const int N = 2e5;
vector<int> prime;
void sieve() {
	vector<bool> isPrime(N + 1, true);
	isPrime[0] = isPrime[1] = false;
	for (int i = 2; i * i <= N; i++) {
		if (isPrime[i]) {
			for (int j = i * i; j <= N; j += i)
				isPrime[j] = false;
		}
	}
	for (int i = 2; i <= N; i++) {
		if (isPrime[i]) prime.push_back(i);
	}
}
