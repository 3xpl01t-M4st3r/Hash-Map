#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int longcons(vector<int>& num)
    {
        unordered_map<int, int> map;
        int maxLen = 0;

        for (int n : num)
        {
            if (map.find(n) == map.end())
            {
                int left = map.find(n - 1) != map.end() ? map[n - 1] : 0;
                int right = map.find(n + 1) != map.end() ? map[n + 1] : 0;
                int length = left + right + 1;

                map[n] = length;
                maxLen = max(maxLen, length);

                map[n - left] = length;
                map[n + right] = length;
            }
        }

        return maxLen;
    }
};

int main()
{
    vector<int> num;
    int n, ele;
    cout << "size: ";
    cin >> n;
    cout << "elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> ele;
        num.push_back(ele);
    }
    Solution sol;
    cout << "Longest consecutive sequence length: " << sol.longcons(num) << endl;

    return 0;
}
