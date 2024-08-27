#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	vector<int> input;
	vector<int> unique_sort;
	map <int, int> degree = map<int, int>();

	cin >> n;

	input = vector<int>(n);

	for (int i = 0; i < n; i++) {
		cin >> input[i];
	}

	unique_sort = input;

	sort(unique_sort.begin(), unique_sort.end());
	unique_sort.erase(unique(unique_sort.begin(), unique_sort.end()), unique_sort.end());

	for (int i = 0; i < unique_sort.size(); i++) {
		degree[unique_sort[i]] = i;
	}

	for (int i = 0; i < input.size(); i++) {
		cout << degree[input[i]] << " ";
	}

	for (int i = 0; i < input.size(); i++) {
		cout << lower_bound(unique_sort.begin(), unique_sort.end(), input[i]) - unique_sort.begin() << " ";
	}
	cout.flush();

	return 0;
}
