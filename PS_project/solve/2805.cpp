#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> trees;
	long long int result = 0;
	int n, need;
	int low, high;
	int cut;
	cin >> n >> need;

	trees = vector<int>(n);

	for (int i = 0; i < n; i++) {
		cin >> trees[i];
	}

	sort(trees.begin(), trees.end());

	low = 0;
	high = trees.back();
	
	while (low <= high) {
		long long int sum = 0;
		cut = (low + high) / 2;

		for (const auto& log : trees) {
			if (log - cut > 0) sum += log - cut;
		}

		if (sum < need) {
			high = cut - 1;
		}
		else {
			result = cut;
			low = cut + 1;
		}
	}
	cout << result << endl;

	return 0;
}
