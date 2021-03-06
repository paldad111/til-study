#include <iostream>

using namespace std;

int N, M;
int seq[8+1];

void func(int i, int j)
{
	int k;

	/* base condition 1 - choose M number */
	if (i > M)
	{
		for (k = 1; k <= M; k++)
			cout << seq[k] << " ";
		cout << "\n";

		return;
	}

	/* base condition 2 - no number to choose */
	if (j > N)
		return;

	/* choose j to seq[i] */
	seq[i] = j;
	func(i+1, j);

	/* do not choose j to seq[i] */
	func(i, j+1);
}

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> M;

	func(1, 1);

	return 0;
}
