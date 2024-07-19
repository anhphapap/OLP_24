// https://leetcode.com/problems/median-of-two-sorted-arrays/
#include <bits/stdc++.h>

using namespace std;

vector<int> nums1 = {1};
vector<int> nums2 = {2};
int m, n, mid;

int main()
{
    n = nums1.size();
    m = nums2.size();
    nums1.push_back(INT_MAX);
    nums2.push_back(INT_MAX);
    mid = (n + m - 1) / 2;
    int l = 0, r = 0, counter = 0;
    float ans;
    while (counter <= mid)
    {
        if (nums1[l] < nums2[r])
        {
            ans = nums1[l];
            l++;
        }
        else
        {
            ans = nums2[r];
            r++;
        }
        counter++;
    }
    ans = float(ans) / 1.0;
    if ((m + n) % 2 == 0)
    {
        if (nums1[l] < nums2[r])
            ans += nums1[l];
        else
            ans += nums2[r];
        ans = float(ans) / 2.0;
    }
    cout << ans;
    return 0;
}