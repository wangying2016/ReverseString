#include <iostream>
#include <cstdlib>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
#include <regex>

using std::cout;
using std::endl;
using std::string;
using std::isspace;
using std::vector;
using std::reverse;
using std::isupper;
using std::regex;
using std::smatch;

class Solution {
public:
	string wordRverse(string s) {
		vector<bool> caps;
		for (auto c : s)
			caps.push_back(isupper(c) ? true : false);
		reverse(s.begin(), s.end());
		for (int i = 0; i < s.size(); ++i)
			if (caps[i]) s[i] = toupper(s[i]);
			else s[i] = tolower(s[i]);
		return s;
	}

	string reverseString(string s) {
		regex e(" ");
		smatch m;
		string result;
		while (regex_search(s, m, e)) {
			result += wordRverse(m.prefix().str());
			result += " ";
			s = m.suffix();
		}
		result += wordRverse(s);
		
		return result;
	}
};

int main()
{
	string s = "Many people spell MySQL incorrectly";
	Solution solution;
	string result = solution.reverseString(s);
	cout << result << endl;
	system("pause");
	return 0;
}