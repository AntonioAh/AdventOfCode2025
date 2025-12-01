#include <iostream>
#include <string>

using namespace std;

int main(){
  string s;
  long count = 0;
  int pos = 50;

  while (cin >> s){
    bool right = s[0] == 'R';

    string nString(s.begin() + 1, s.end());
    int number = std::stoi(nString);

    number = number % 100;
    if (right)
      pos += number;
    else
      pos -= number;


    if (pos == 0 || pos == 100){
      count++;
      pos = 0;
    }
    else if (pos < 0){
      pos = 100 + pos;
     }
    else if (pos > 100){
      pos = pos - 100;
    }
  }

  cout << count << "\n";
}