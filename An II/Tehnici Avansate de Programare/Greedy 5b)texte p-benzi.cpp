#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

int main()
{
  ifstream fin ("texte p-benzi.in");
  ofstream fout ("texte p-benzi.out");

  int n, p;
  fin >> p >> n;
  int lungimi[n];
  int benzi[p][n];
  for (int i = 0; i < n; i++) {
    fin >> lungimi[i];
  }

  sort(lungimi, lungimi + n);

  ///Metoda Greedy
  int banda_curenta = 0, col = 0;
  for (int i = 0; i < n; i++) {
    benzi[banda_curenta++][col] = lungimi[i];
    if (banda_curenta == p) {
      banda_curenta = 0;
      col++;
    }
  }
  if (banda_curenta == 0) col--;

  for (int i = 0; i < p; i++) {
    for (int j = 0; j <= col; j++) {
      if (banda_curenta != 0 && j == col) {
        if (i >= banda_curenta) break;
      }
      fout << benzi[i][j] << " ";
    }
    fout << endl;
  }

  fin.close();
  fout.close();
  return 0;
}
