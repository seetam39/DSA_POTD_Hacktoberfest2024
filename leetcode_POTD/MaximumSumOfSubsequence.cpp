#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to find the maximum sum of an increasing subsequence
int maxSumIncreasingSubsequence(vector<int>& arr) {
    int n = arr.size();
    
    // dp[i] will store the maximum sum of the increasing subsequence ending at index i
    vector<int> dp(n);

    // Initialize dp[] with the values of arr[] as each element is an increasing subsequence of length 1
    for (int i = 0; i < n; i++) {
        dp[i] = arr[i];
    }

    // Build the dp array
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            // If arr[i] is greater than arr[j] and including arr[i] results in a larger sum subsequence
            if (arr[i] > arr[j] && dp[i] < dp[j] + arr[i]) {
                dp[i] = dp[j] + arr[i];
            }
        }
    }

    // The result is the maximum value in the dp array
    return *max_element(dp.begin(), dp.end());
}

int main() {
    vector<int> arr = {1, 101, 2, 3, 100, 4, 5};
    cout << "Maximum sum of increasing subsequence is: " << maxSumIncreasingSubsequence(arr) << endl;
    return 0;
}
