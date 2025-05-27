class Solution
{
public:
    int subarrayLCM(vector<int> &nums, int k)
    {
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; ++i)
        {
            int a = nums[i];
            for (int j = i; j < n; ++j)
            {
                a = lcm(a, nums[j]);
                if (a == k)
                    ++ans;
                if (a > k || k % a != 0)
                    break;
            }
        }
        return ans;
    }
};
