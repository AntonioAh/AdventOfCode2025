#include <iostream>
#include <string>

using namespace std;

int main(){
  string s;
  long count = 0;
  int pos = 50;

  bool consider = true;

  while (cin >> s){
    bool right = s[0] == 'R';

    string nString(s.begin() + 1, s.end());
    int number = std::stoi(nString);

    count += (number / 100);
    number = number % 100;
    if (right)
      pos += number;
    else
      pos -= number;

    string t = "aggiunto";

    if (pos == 0 || pos == 100){
      count++;
      consider = false;
      pos = 0;
    }
    else if (pos < 0){
      pos = 100 + pos;
      count += consider;      
     }
    else if (pos > 100){
      pos = pos - 100;
      count += consider;
    }

    if (!consider && pos != 0)
      consider = true;
  }

  cout << count << "\n";
}