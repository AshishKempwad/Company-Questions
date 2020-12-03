int solve(int prev, int hire, int salary, int severance, int idx,
	     vector<int> &emps, vector<vector<int > > &dp) {
    if (dp[idx][prev] == -1) {
        if (idx == emps.size()) {
            dp[idx][prev] = 0;
        } else {
            int cost = 0;
            if (emps[idx] >= prev) {
                // hire everyone
                // hiring cost + cur month salary
                cost += (emps[idx] - prev) * hire + emps[idx] * salary + solve(
                	emps[idx], hire, salary, severance, idx + 1, emps, dp
                );
            } else {
                int cur = INT_MAX;
                // try all possible combinations
                for (int i = emps[idx]; i <= prev; i++) {
                    // hire i emp
                    // severance cost + cur month salary
                    int curCost = (prev - i) * severance + i * salary + solve(
                    	i, hire, salary, severance, idx + 1, emps, dp
                    );
                    cur = min(cur, curCost);
                }
                cost += cur;
            }
            dp[idx][prev] = cost;
        }
    }
    return dp[idx][prev];
}
int minCTC(int hire, int salary, int severance, vector<int> emps) {
    int n = emps.size();
    vector<vector <int> > dp(n + 1, vector<int> (51, -1));
    int ans = solve(0, hire, salary, severance, 0, emps, dp);
    return ans;
}

int main()
 {
    vector<int> emps = {14, 10, 11};
	assert(minCTC(5, 6, 7, emps) == 307);
	return 0;
}
