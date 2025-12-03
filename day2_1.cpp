#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_set>

using namespace std;

typedef unsigned long type_value;

int main(){
  string line; cin >> line; 
  vector<pair<string, string>> intervals;

  long start = 0;
  string left, right;
  for (long i = 0; i < line.size(); i++){
    if (line[i] == '-'){
      left = line.substr(start, i - start );
      start = i +1;
    }
    else if (line[i] == ','){
      right = line.substr(start, i - start);
      start = i + 1;

      intervals.push_back({left, right});
    }
  }
  string r = line.substr(start, line.size() - start + 1);
  intervals.push_back({left, r});

  unordered_set<type_value> nums;
  unsigned long long tot = 0; 
  for (const pair<string, string>& coppia : intervals){
    const string &inizio = coppia.first, &fine = coppia.second;
    
    type_value ss, ff;
    ss = stoul(inizio);
    ff = stoul(fine);

    for (; ss <= ff; ss++){
      auto a = nums.insert(ss);
      if (! a.second)
        continue;

      string str = to_string(ss);
      if (str.size() % 2 == 1)
        continue;

      if (str.substr(0, str.size() / 2) == str.substr(str.size() / 2, str.size() / 2)){
        tot += ss;
      }
    }
  }

  cout << "\ntot : " << tot << "\n";
  

  // for (auto &p : intervals)
    // cout << p.first << " " << p.second << "\n";
  
  

  
}