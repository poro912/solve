#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

#define NUM_ALPHABET 26

string solution(string encrypted_text, string key, int rotation);
//char** solution(const char* letters);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	//solution("abca");
	//solution("abcbc");
	//solution("wxyz");
	cout << solution("qyyigoptvfb", "abcdefghijk", 3) << endl;
	cout << solution("abcdefghijklmnopqrstuvwxyz", "tttttttttttttttttttttttttt", 19) << endl;
	/*cout << solution("qyyigoptvfb", "abcdefghijk", 0) << endl;
	cout << solution("qyyigoptvfb", "abcdefghijk", 1) << endl;
	cout << solution("qyyigoptvfb", "abcdefghijk", 2) << endl;
	cout << solution("qyyigoptvfb", "abcdefghijk", 3) << endl;
	cout << solution("qyyigoptvfb", "abcdefghijk", 20) << endl;*/
	cout << solution("bcdefga", "aaaaaaa", -1) << endl;
	cout << solution("bcdefga", "aaaaaaa", -2) << endl;
	cout << solution("bcdefga", "aaaaaaa", -3) << endl;
	cout << solution("bcdefga", "aaaaaaa", -4) << endl;
	cout << solution("bcdefga", "aaaaaaa", -5) << endl;
	cout << solution("bcdefga", "aaaaaaa", -6) << endl;
	cout << solution("bcdefga", "aaaaaaa", -7) << endl;
	cout << solution("bcdefga", "aaaaaaa", -8) << endl;



	cout.flush();
	return 0;
}

// 암호화된 문자열, 문자 키, 회전 수
string solution(string encrypted_text, string key, int rotation) {
	// 회전 후 바꿔줘야함 
	string temp = encrypted_text;
	string answer;
	int head = 0;

	// 회전
	head += rotation;
	if (0 < rotation) {
		// 우측으로
		head %= encrypted_text.length() - 1;
	}
	else {
		// 좌측으로
		while (head < 0) {
			head += encrypted_text.length();
		}
	}

	if (head != 0) {
		answer = temp.substr(head, temp.length() - 1);
		answer.append(temp.substr(0, head));
	}
	else {
		answer = temp;
	}
	
	cout << "temp : " << temp << "\n";
	cout << "shift : " << answer << "\n";
	cout << "rotation : " << rotation << "\n";
	cout << "head : " << head << "\n";

	
	// 변환
	for (int i = 0; i < answer.length(); i++) {
		answer[i] = answer[i] - (key[i] - 'a' + 1);
		if(answer[i] - 'a' < 0) answer[i] += NUM_ALPHABET;
	}
	cout << "\n" << endl;
	return answer;
}