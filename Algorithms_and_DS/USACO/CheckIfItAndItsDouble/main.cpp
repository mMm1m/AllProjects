#include <bits/stdc++.h>
using namespace std;

   bool CheckIfExists(vector<int>& arr)
   {
     int n = arr.size();
     std::sort(arr.begin(),arr.end());
     std::multiset<int> set;
     for(auto& a : arr)
       set.insert(a);
     for(int i = 0; i < n; ++i)
     {
       auto it = upper_bound(arr.begin(), arr.end(), arr[i]*2);
       if(set.find(*it) != set.end() && *it != 0)
       {
         return true;
       }
     }
     return false;
   }
   vector<int> max_;
   vector<int> maxSubsequence(vector<int>& nums, int k)
   {
     std::sort(nums.begin(), nums.end(), std::greater<int>());
     if(nums.size() < k)
     {
       for(auto a : nums)
         max_.push_back(a);
     }
     else
     {
       int index = 0;
       while(k--)
       {
         max_.push_back(nums[index++]);
       }
     }
     return max_;
   }

   int largestSumAfterKNegations(vector<int>& nums, int k)
   {
     int sum = std::accumulate(nums.begin(), nums.end(), 0);
     int index = 0;
     std::sort(nums.begin(), nums.end());
     while(k--)
     {
       if(nums[index] > 0)
       {
         sum -= 2*nums[index];
       }
       else
       {
         sum += 2*nums[index];
       }
       ++index;
     }
     return sum;
   }

   int minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2)
   {
     int n = nums1.size(), k = k1 + k2;
     // diff/freq
     std::unordered_map<int,int> map;
     for(int i = 0; i < n; ++i) {
       int x = std::abs(nums1[i] - nums2[i]);
       if (x != 0)
         ++map[x];
     }
       std::priority_queue<std::pair<int,int>> pq;
       for(auto&a : map)
         pq.emplace(a);
       while(k > 0)
       {
         auto top = pq.top();
         if(top.second <= k)
         {
           k -= top.second;
           pq.pop();
           pq.emplace(std::make_pair(top.first-1, top.second));
         }
         else
         {
           pq.emplace(std::make_pair(top.first-1, top.second));
         }
       }
       int ans = 0;
       while(!pq.empty())
       {
         ans += pq.top().first*pq.top().first*pq.top().second;
         pq.pop();
       }
     return ans;
   }

   