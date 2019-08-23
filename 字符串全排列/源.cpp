#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	string s;
	while (cin >> s) {
		//sort(s.begin(), s.end());
		do {
			cout << s << ' ';
		} while (next_permutation(s.begin(), s.end()));
		cout << endl;
	}
	return 0;
}