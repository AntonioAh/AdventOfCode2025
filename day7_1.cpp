#include <string>
#include <vector>
#include <iostream>

using namespace std;



int main(){
  constexpr char splitSym = '^';
  constexpr char beamSym = '|';
  constexpr char startingSym = 'S';

  string line;
  vector< string > lines;
  while ( cin >> line ){
    lines.push_back( line );
  }
  const int rows = lines.size(), cols = lines[0].size();
  int count = 0;

  for ( int col = 0; col < cols; col++ )
    if (lines[ 0 ][ col ] == startingSym)
      lines[ 0 ][ col ] = beamSym;

  for ( int row = 1; row < lines.size() - 1; row++ ){
    for ( int col = 0; col < lines[0].size(); col++ ){

      if (lines[ row - 1 ][ col ] != beamSym)
        continue;

      if ( lines[ row ][ col ] == splitSym ){
        bool aggiunto = false;
        if ( col > 0 && lines[ row ][ col - 1 ] != splitSym ){
          lines[ row ][ col - 1] = beamSym;
          aggiunto = true;
        }

        if ( col + 1 < cols && lines[ row ][ col + 1] != splitSym ){
          lines[ row ][ col + 1] = beamSym;
          aggiunto = true;
        }
        count += aggiunto;
      }
      else
        lines[ row ][ col ] = beamSym;
    }
  }

  for ( int row = 0; row < rows; row++ ){
    for (int col = 0; col < cols; col++ )
      cout << lines[ row ][ col ] << " ";
    cout << "\n";
  } 

  cout << count << "\n";
}