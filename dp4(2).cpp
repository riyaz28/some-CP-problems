

const int MAX = 101;
int memo[MAX][MAX], cnt[MAX], pr[MAX];
int n;

int best(int curIdx, int lastIdx)
{
	if(curIdx == n)
		return 0;

	int &ret = memo[curIdx][lastIdx];
	if(ret != -1)	return ret;

	int sum = 10;
	for (int i = lastIdx; i <= curIdx; ++i)	// we could use array accumulation to make this in O(1)
		sum += cnt[i];

	// Enough Interval
	ret = best(curIdx+1, curIdx+1) + sum * pr[curIdx];

	// Add me to current interval
	if(curIdx != n-1)	// as long as bigger interval is possible
		ret = min(ret, best(curIdx+1, lastIdx) );

	return ret;
}




// Note that: previousSum is inferenced variable and equals SumRange(i, j). Then we don't memoize it.

int best2(int curIdx, int lastIdx, int previousSum = 0)
{
	if(curIdx == n)
	{
		if(lastIdx != curIdx)	// at end all groups finished
			return (int)1e9;	// max correct answer: 100 * 1010 * 1000
		return 0;
	}

	int &ret = memo[curIdx][lastIdx];
	if(ret != -1)	return ret;

	ret = best2(curIdx+1, curIdx+1, 0) + (previousSum+cnt[curIdx]+10) * pr[curIdx];

	ret = min(ret, best2(curIdx+1, lastIdx, previousSum+cnt[curIdx]) );

	return ret;
}






























int main()
{
	freopen("c.in", "rt", stdin);

	int cases;
	scanf("%d", &cases);

	while(cases--) {
		scanf("%d", &n);
		lp(i, n)
			scanf("%d%d", &cnt[i], &pr[i]);


		clr(memo, -1);

		printf("%d\n", best2(0, 0));
	}


	return 0;
}
