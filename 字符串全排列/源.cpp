#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	string s;
	while (cin >> s) {
		//sort(s.begin(), s.end());
		do {
			if (s[0] == '1' ||
				s[1] == '2' ||
				s[2] == '3' ||
				s[3] == '4')
				continue;
			cout << s << ' ';
		} while (next_permutation(s.begin(), s.end()));
		cout << endl;
	}
	return 0;
}