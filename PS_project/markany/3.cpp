#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;
vector<string> solution(string letters);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	solution("abca");
	solution("abcbc");
	solution("wxyz");
	
	cout.flush();
	return 0;
}

vector<string> solution(string letters) {
	vector<string> answer;
	string temp = letters;
	
	sort(temp.begin(), temp.end() );
	
	//cout << temp << "\n";
	//cout << "permutation" << "\n";
	do {
		bool is_repeat = false;
		for (int i = 0; i < temp.length() - 1 ; i++) {
			if (temp[i] == temp[i + 1]) {
				is_repeat = true;
				break;
			}
		}
		if (!is_repeat){
			//cout << temp << "\n";
			answer.push_back(temp);
		}

	}while(next_permutation(temp.begin(), temp.end()));

	return answer;
}


