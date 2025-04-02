#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution
{
  public:
  int longcons(vector<int>&num)
  {
      if(num.empty())
      {
          return 0;
      }
      unordered_set<int> set(num.begin(),num.end());
      int streak=0;
      for(int n:set)
      {
          if(set.find(n-1)==set.end())
          {
              int curr=n;
              int currstreak=1;
              while(set.find(curr+1)!=set.end())
              {
                  curr++;
                  currstreak++;
              }
              streak=max(streak,currstreak);
          }
      }
      return streak;
  }
};

int main()
{
    vector<int> num;
    int n,ele;
    cout<<"size";
    cin>>n;
    cout<<"element";
    for(int i=0;i<n;i++)
    {
        cin>>ele;
        num.push_back(ele);
    }
    Solution sol;
    cout<<sol.longcons(num)<<endl;

    return 0;
}
