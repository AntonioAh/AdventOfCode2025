#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
  string row;
  vector<vector<bool>> matrix;

  while (cin >> row){
    vector<bool> v(row.size());
    for (int i = 0; i < row.size(); i++)
      v[i] = (row[i] == '@');

    matrix.push_back(v);
  }

  unsigned int count = 0;

  bool rimosso = true;
  while (rimosso){
    rimosso = false;
    for (int i = 0; i < matrix.size(); i++){
      for (int j = 0; j < matrix[0].size(); j++){
        if (! matrix[i][j])
          continue;

        int partial = -1;
        for (int a = -1; a <= 1; a++){
          for (int b = -1; b <= 1; b++){
            if (i + a < 0 || i + a >= matrix.size() || j + b < 0 || j + b >= matrix[0].size())
              continue;

            partial += matrix[i+a][j+b];

          }
        }
        if (partial < 4){
          count++;
          rimosso = true;
          matrix[i][j] = false;
        }
        
        
      }
    }
  }

  cout << count << "\n";
}