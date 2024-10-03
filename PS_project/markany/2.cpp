#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;
string solution(string line);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cout << solution("aabbbc") << endl;
	cout << solution("helllllo") << endl;
	cout << solution("wonderful") << endl;
	
	cout.flush();
	return 0;
}

string solution(string line) {
	string answer = "";
	
	//char temp = 0;
	char temp = 0;
	bool is_repeat = false;
	for (int i = 0 ; i < line.length() ; i++) {
		if (line[i] == temp) {
			if (!is_repeat) {
				is_repeat = true;
				answer.push_back('*');
			}
			continue;
		}

		is_repeat = false;
		temp = line[i];
		answer.push_back(temp);
	}
	cout << "answer : " << answer << "\n";

	//answer.replace("**")

	return answer;
}