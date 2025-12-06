#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

typedef long long IT;

IT parse(const string &s){
  if constexpr (is_same<IT, int>::value)
    return stoi(s);
  else
    return stoll(s);
}

int main(){
  vector<pair<IT, IT>> intervals;
  string row;

  // Read ONLY the interval section
  while (getline(cin, row)){
    if (row.empty()) continue;

    size_t dash = row.find('-');
    if (dash == string::npos)
        break; // stop at the beginning of queries

    IT x = parse(row.substr(0, dash));
    IT y = parse(row.substr(dash+1));

    intervals.emplace_back(x, y);
  }
  
  sort(intervals.begin(), intervals.end());

  IT count = 0;
  IT left = intervals[0].first, right = intervals[0].second;

  for (int i = 1; i < intervals.size(); i++){
    if (intervals[i].first <= right + 1){
      right = max(right, intervals[i].second);
    } else {
      count += (right - left + 1);
      left = intervals[i].first;
      right = intervals[i].second;
    }
  }

  count += (right - left + 1);

  cout << count << "\n";
}
