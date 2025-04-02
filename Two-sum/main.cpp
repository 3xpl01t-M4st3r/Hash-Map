#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> twosum(vector<int>&nums,int target)
{
    unordered_map<int,int> Map;
    for(int i=0;i<nums.size();i++)
    {
        int complement=target-nums[i];
        if(Map.find(complement)!=Map.end())
        {
            return {Map[complement],i};
        }
        Map[nums[i]]=i;
    }
    return {};
}

int main()
{
    int n,target,num;
    cin>>n;
    vector<int> nums;
    for(int i=0;i<n;i++)
    {
        cin>>num;
        nums.push_back(num);
    }
    cin>>target;
    vector<int> result=twosum(nums,target);
    if(!result.empty())
    {
        cout<<"Index "<<result[0]<<" and "<<result[1]<<endl;
    }

    return 0;
}
