#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int coinChangePermutationInfi(vector<int> &arr, int tar, string ans)
{
    if (tar == 0)
    {
        cout << ans << endl;
        return 1;
    }

    int count = 0;
    for (int ele : arr)
    {
        if (tar - ele >= 0)
            count += coinChangePermutationInfi(arr, tar - ele, ans + to_string(ele));
    }

    return count;
}

int coinChangeCombinationInfi(vector<int> &arr, int idx, int tar, string ans)
{
    if (tar == 0)
    {
        cout << ans << endl;
        return 1;
    }

    int count = 0;
    for (int i = idx; i < arr.size(); i++)
    {
        if (tar - arr[i] >= 0)
            count += coinChangeCombinationInfi(arr, i, tar - arr[i], ans + to_string(arr[i]));
    }

    return count;
}

int coinChangeCombination(vector<int> &arr, int idx, int tar, string ans)
{
    if (tar == 0)
    {
        cout << ans << endl;
        return 1;
    }

    int count = 0;
    for (int i = idx; i < arr.size(); i++)
    {
        if (tar - arr[i] >= 0)
            count += coinChangeCombination(arr, i + 1, tar - arr[i], ans + to_string(arr[i]));
    }

    return count;
}

int coinChangePermutation(vector<int> &arr, int tar, string ans)
{
    if (tar == 0)
    {
        cout << ans << endl;
        return 1;
    }

    int count = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        int ele = arr[i];
        if (arr[i] > 0 && tar - ele >= 0)
        {
            arr[i] = -arr[i];
            count += coinChangePermutation(arr, tar - ele, ans + to_string(ele));
            arr[i] = -arr[i];
        }
    }

    return count;
}

int coinChangeCombinationInfiSubSeq(vector<int> &arr, int idx, int tar, string ans)
{
    if (idx == arr.size() || tar == 0)
    {
        if (tar == 0)
        {
            cout << ans << endl;
            return 1;
        }
        return 0;
    }

    int count = 0;
    if (tar - arr[idx] >= 0)
        count += coinChangeCombinationInfiSubSeq(arr, idx, tar - arr[idx], ans + to_string(arr[idx]));
    count += coinChangeCombinationInfiSubSeq(arr, idx + 1, tar, ans);

    return count;
}

int coinChangeCombinationSubSeq(vector<int> &arr, int idx, int tar, string ans)
{
    if (idx == arr.size() || tar == 0)
    {
        if (tar == 0)
        {
            cout << ans << endl;
            return 1;
        }
        return 0;
    }

    int count = 0;
    if (tar - arr[idx] >= 0)
        count += coinChangeCombinationSubSeq(arr, idx + 1, tar - arr[idx], ans + to_string(arr[idx]));
    count += coinChangeCombinationSubSeq(arr, idx + 1, tar, ans);

    return count;
}

int coinChangePermutationInfiSubSeq(vector<int> &arr, int idx, int tar, string ans)
{

    if (idx == arr.size() || tar == 0)
    {
        if (tar == 0)
        {
            cout << ans << endl;
            return 1;
        }
        return 0;
    }

    int count = 0;
    if (tar - arr[idx] >= 0)
        count += coinChangePermutationInfiSubSeq(arr, 0, tar - arr[idx], ans + to_string(arr[idx]));
    count += coinChangePermutationInfiSubSeq(arr, idx + 1, tar, ans);

    return count;
}

int coinChangePermutationSubSeq(vector<int> &arr, int idx, int tar, string ans)
{

    if (idx == arr.size() || tar == 0)
    {
        if (tar == 0)
        {
            cout << ans << endl;
            return 1;
        }
        return 0;
    }

    int count = 0;
    int ele = arr[idx];
    if (tar - ele >= 0 && arr[idx] > 0)
    {
        arr[idx] = -arr[idx];
        count += coinChangePermutationSubSeq(arr, 0, tar - ele, ans + to_string(ele));
        arr[idx] = -arr[idx];
    }
    count += coinChangePermutationSubSeq(arr, idx + 1, tar, ans);

    return count;
}

//  Questions.====================================================================

vector<int> smallAns;
vector<vector<int>> res;

void combinationSum(vector<int> &arr, int idx, int target)
{
    if (idx == arr.size() || target == 0)
    {
        if (target == 0)
        {
            res.push_back(smallAns);
        }
        return;
    }

    if (target - arr[idx] >= 0)
    {
        smallAns.push_back(arr[idx]);
        combinationSum(arr, idx, target - arr[idx]);
        smallAns.pop_back();
    }
    combinationSum(arr, idx + 1, target);
}

vector<vector<int>> combinationSum(vector<int> &arr, int target)
{
    combinationSum(arr, 0, target);
    return res;
}

void combinationSum2(vector<int> &arr, int idx, int target)
{
    if (target == 0)
    {
        res.push_back(smallAns);
        return;
    }

    int prev = -1;
    for (int i = idx; i < arr.size(); i++)
    {
        if (prev != -1 && arr[prev] == arr[i])
            continue;

        if (target - arr[i] >= 0)
        {
            smallAns.push_back(arr[i]);
            combinationSum2(arr, i + 1, target - arr[i]);
            smallAns.pop_back();
        }

        prev = i;
    }
}

vector<vector<int>> combinationSum2(vector<int> &arr, int target)
{
    sort(arr.begin(), arr.end());
    combinationSum2(arr, 0, target);
    return res;
}

// leetcode 46
void permute(vector<int> &nums, int count, vector<bool> &vis)
{
    if (count == nums.size())
    {
        res.push_back(smallAns);
        return;
    }
    for (int i = 0; i < nums.size(); i++)
    {
        if (!vis[i])
        {
            vis[i] = true;
            smallAns.push_back(nums[i]);
            permute(nums, count + 1, vis);
            smallAns.pop_back();
            vis[i] = false;
        }
    }
}

vector<vector<int>> permute(vector<int> &nums)
{
    vector<bool> vis(nums.size(), false);
    permute(nums, 0, vis);
    return res;
}

int main()
{
    vector<int> arr{2, 3, 5, 7};
    int tar = 10;
    // cout << coinChangePermutationInfi(arr, tar, "");
    // cout << coinChangeCombinationInfi(arr, 0,tar, "");
    // cout << coinChangeCombination(arr, 0, tar, "")<<endl;
    // cout << coinChangePermutation(arr,tar, "");

    // cout << coinChangePermutationInfiSubSeq(arr, 0, tar, "") << endl;
    // cout << coinChangeCombinationInfiSubSeq(arr, 0, tar, "") << endl;
    // cout << coinChangeCombinationSubSeq(arr, 0, tar, "") << endl;
    cout << coinChangePermutationSubSeq(arr, 0, tar, "") << endl;

    return 0;
}