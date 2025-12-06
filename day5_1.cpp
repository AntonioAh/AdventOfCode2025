#include <iostream>
#include <vector>
#include <type_traits>
#include <string>
using namespace std;

typedef long long IT;

IT parse(const string &s){
  if constexpr (is_same<IT, int>::value)
    return stoi(s);
  else if constexpr (is_same<IT, long long>::value)
    return stoll(s);

  return IT();
}
int main(){
  vector<pair<IT, IT>> intervals;
  vector<IT> queries;
  string row;

  while (getline(cin, row)){
    if (row.empty())
      continue;

    size_t dash = row.find('-');
    if (dash != string::npos){
      IT x = parse(row.substr(0, dash));
      IT y = parse(row.substr(dash+1));

      intervals.emplace_back(x, y);
    }
    else{
      queries.push_back(parse(row));
    }
  }
  
  sort(intervals.begin(), intervals.end());

  // for (auto &inter : intervals)
  //   cout << inter.first << " " << inter.second << "\n";

  // for (int n : queries)
  //   cout << n << " ";

  int count = 0;
  for (IT query : queries){
    pair<IT, IT> cerca = {query, 0};

    for (auto it = intervals.begin() ; it != intervals.end(); it++){
      if (it->first > query)
        break;

      if (it->first <= query && query <= it->second){
        count++;
        break;
      }

    }
  }

    cout << count << "\n";
}