#include <iostream>
#include <vector>
#include <map>
#include <math.h>
#include <algorithm>

using namespace std;
bool exist(vector<string> &list, string target);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int listen, see;
	vector<string> listen_list, see_list;
	vector<string> result;
	cin >> listen >> see;

	for (int i = 0; i < listen; i++) {
		string t;
		cin >> t;
		listen_list.push_back(t);
	}
	for (int i = 0; i < see; i++) {
		string t;
		cin >> t;
		see_list.push_back(t);
	}

	sort(listen_list.begin(), listen_list.end());
	sort(see_list.begin(), see_list.end());
	
	for (const auto& i : listen_list) {
		if (exist(see_list,i)) {
			result.push_back(i);
		}
	}
	sort(result.begin(), result.end());

	cout << result.size() << "\n";
	for (const auto& i : result) {
		cout << i << "\n";
	}
	cout << endl;
}

bool exist(vector<string> &list, string target) {
	int length = list.size();
	int front = 0, end = length;
	int idx = length / 2;
	while (true)
	{
		//cout << front << " " << end << " " << idx << endl;
		idx = front + (end - front) / 2;
		int compare = target.compare(list[idx]);
		if (compare == 0) {
			list.erase(list.begin() + idx);
			return true;
		}
		if (front == idx) break;
		if (compare < 0) {
			// 사전상 앞
			end = idx;
		}
		else {
			// 사전상 뒤
			front = idx;
		}
	}
	return false;
}
