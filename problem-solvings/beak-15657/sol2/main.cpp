#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int V[8+1];
int seq[8+1];

void func(int i, int j)
{
	int k;

	/* base condition 1 - M number selected */
	if (i > M)
	{
		for (k = 1; k <= M; k++)
			cout << seq[k] << " ";
		cout << "\n";

		return;
	}

	/* base condition 2 - no number to select */
	if (j > N)
		return;

	/* choose V[j] in seq[i] */
	seq[i] = V[j];
	func(i+1, j);

	/* do not choose V[j] in seq[i] */
	func(i, j+1);
}

int main(void)
{
	int n;

	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> M;

	for (n = 1; n <= N; n++)
		cin >> V[n];

	sort(&V[1], &V[N+1]);

	func(1, 1);

	return 0;
}
