#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll flowers(int beauty[], int h[], int n) {
	vector<ll>dp(n);
	multimap<ll, ll>sortedflowers;
	dp[0] = beauty[0];
	ll ans = dp[0];
	sortedflowers.insert({h[0], beauty[0]});
	for (int i = 1; i < n; ++i) {
		dp[i] = beauty[i];
		auto it = sortedflowers.lower_bound(h[i]);
		/*This basically points the iterator to the first occurance of h[i] so, value of this gets
		added to the previous heights beauty.Because for multiple occurances of h[i] it will always
		add to the previous lesser heights,not equal heights.*/
		if (it != sortedflowers.begin()) {
			/*Meaning there is atleast one flower of height lesser than h[i] before h[i]*/
			it--;
			dp[i] += it->second; //append this flower to the end of it and increase the dp value.
			it++;
		}
		sortedflowers.insert({h[i], dp[i]});
		/*add this flower to the map.Delete all those flowers with height f=greater than this
		height but lower dp values. it = sortedflowers.upper_bound(h[i]);Taking the upper bound
		as we are finding flowers*/
		it = sortedflowers.upper_bound(h[i]);
		while (it != sortedflowers.end() and it->second <= dp[i]) {
			/*
			This basically remvoves flowers with greater heights but lesser than or equal to dp values
			,as they are of no use.
			*/
			auto tmp = it;
			tmp++;
			sortedflowers.erase(it);
			it = tmp;
		}
		ans = max(ans, dp[i]);
	}

	return ans;
}

int main() {
	int n;
	cin >> n;
	int h[n];
	for (int i = 0; i < n; ++i)
		cin >> h[i];
	int a[n];
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	cout << flowers(a, h, n);
	return 0;
}
