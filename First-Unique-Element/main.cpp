#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> map;
        for (char c : s) map[c]++;
        for (int i = 0; i < s.size(); i++)
            if (map[s[i]] == 1) return i;
        return -1;
    }
};

int main() {
    Solution solution;
    string s;
    cout << "Enter a string: ";
    cin >> s;
    int result = solution.firstUniqChar(s);
    cout << "First unique character index: " << result << endl;
    return 0;
}
