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

  unsigned long long tot = 0;
  unordered_set<type_value> nums;

  for (const pair<string, string>& coppia : intervals){
    const string &inizio = coppia.first, &fine = coppia.second;

    type_value ss = stoul(inizio), ff = stoul(fine);
    for (; ss <= ff; ss++){
      bool aggiunto = false;

      string str = to_string(ss);

      //lunghezza della stringa ripetuta
      for (int lung = 1; !aggiunto && lung < str.size() / 2 + 1; lung++){
        if (str.size() % lung != 0)
          continue;

        string cop = str.substr(0, lung);
        // cout << cop << " ";
        bool valido = true;
        for (int rep = 0; valido && rep < str.size() / lung; rep++){
          if (cop != str.substr(rep * lung, lung))
            valido = false;
        }

        aggiunto = valido;
      }
     
      if (aggiunto){
        tot += ss;
        // cout << " " << ss << "\n";
      }
    }
  }
  cout << "\ntot : " << tot << "\n";
  

  // for (auto &p : intervals)
    // cout << p.first << " " << p.second << "\n";
  
  

  
}