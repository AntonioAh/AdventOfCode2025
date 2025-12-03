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
    if (n<=12){
      tot += stoull(line);
      continue;
    }

    cout << line << " ";
    auto prevPos = line.begin();
    string str(12, ' ');

    for (int i = 11; i >= 0; i--){
      auto maxCifra = max_element(prevPos, line.end() - i);
      str[11 - i] = (*maxCifra);
      prevPos = maxCifra + 1;
    }

    cout << str << "\n";
    tot += stoull(str);
  }

  cout << "tot : " << tot << "\n";
}