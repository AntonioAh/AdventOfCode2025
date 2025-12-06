#include <iostream>
#include <ranges>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <numeric>
using namespace std;

typedef long long IT;

int main(){
  
  string row;
  vector<string> rows;

  while (getline(cin, row)){
    rows.push_back(row);
  }

  

  vector<bool> isSum;
  for (char c : rows.back())
    if (c == '+')
      isSum.push_back(true);
    else if (c == '*')
      isSum.push_back(false);

  vector<vector<IT>> values(rows.size() - 1, vector<IT>(isSum.size()));
  for (int i = 0; i < rows.size() - 1; i++){
    istringstream iss(rows[i]);

    int count = 0;
    IT v;
    while (iss >> v){
      values[i][count++] = v;
      cout << v << " ";
    }
    cout << "\n"; 
  }

  const int cols = isSum.size();
  vector<IT> resCol(cols);

  for (int j = 0; j < cols; j++)
    resCol[j] = values[0][j];

  for (int j = 0; j < cols; j++){
    for (int i = 1; i < values.size(); i++){
      if (isSum[j])
        resCol[j] += values[i][j];
      else
        resCol[j] *= values[i][j];
    }
  }

  for (int j = 0; j < cols; j++){
    cout << resCol[j] << " ";
    cout << "\n";
  }

  cout << std::accumulate(resCol.begin(), resCol.end(), 0LL) << "\n";
  


}