#include <iostream>

using namespace std;

int nrNum;
int nums[100000];
int cache[100000];

int __contigSum(int lastIdx)
{
	int maxContigSum, maxContigSumPrev;

	/* base condition */
	if (lastIdx < 0)
		return 0;

	maxContigSum = cache[lastIdx];
	if (maxContigSum != 0x80000000)
		goto out;
	
	maxContigSum = nums[lastIdx];

	maxContigSumPrev = __contigSum(lastIdx - 1);
	if (maxContigSumPrev > 0)
		maxContigSum += maxContigSumPrev;

	cache[lastIdx] = maxContigSum;

out:
	return maxContigSum;
}

int contigSum(void)
{
	int graceTotal = 0x80000000; /* INT_MIN */

	for (int i = 0; i < nrNum; i++)
		graceTotal = max(graceTotal, __contigSum(i));

	return graceTotal;
}

int main()
{
	cin >> nrNum;

	for (int i = 0; i < nrNum; i++)
	{
		cin >> nums[i];
		cache[i] = 0x80000000 /* INT_MIN */;
	}

	cout << contigSum() << endl;

	return 0;
}
