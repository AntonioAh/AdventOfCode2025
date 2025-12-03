#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main(){

  string line;
  unsigned long long tot = 0;
  while (cin >> line){
    const int n = line.size();
    vector<int> dp(n, 0);

    dp[n-1] = 0;
    for (int i = n-2; i >= 0; i--){
      dp[i] = max(dp[i+1], line[i+1] - '0');
    }

    int part = 0;
    for (int i = 0; i < n-1; i++){
      part = max(part, 10 * (line[i] - '0') + dp[i]);
    }

    // cout << part << " ";
    tot += part;
  }

  cout << "tot : " << tot << "\n";
}