#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;


int main()
{
  ifstream fin ("subsiruri descrescatoare.in");
  ofstream fout ("subsiruri descrescatoare.out");

  int n, indice, linia, capat_max;
  fin >> n;
  int v[n], ultimul[n], sol[n][n];
  for (int i = 0; i < n; i++) {
    fin >> v[i];
  }

  ///Metoda Greedy
  sol[0][0] = v[0];
  ultimul[0] = 0;
  indice = 0;
  for (int i = 1; i < n; i++) {
    linia = -1;
    capat_max = INT_MAX;
    for (int j = 0; j <= indice; j++) {
      if (v[i] <= sol[j][ultimul[j]]) {
        if (sol[j][ultimul[j]] < capat_max) {
          capat_max = sol[j][ultimul[j]];
          linia = j;
        }
      }
    }
    if (linia == -1) {
      sol[++indice][0] = v[i];
      ultimul[indice] = 0;
    }
    else {
      sol[linia][++ultimul[linia]] = v[i];
    }
  }


  for (int i = 0; i <= indice; i++) {
    for (int j = 0; j <= ultimul[i]; j++) {
      fout << sol[i][j] << " ";
    }
    fout << endl;
  }


  fin.close();
  fout.close();
  return 0;
}
