#include <iostream>
#include <algorithm>
#include <fstream>
#include <time.h>

using namespace std;


int main()
{
  ifstream fin ("tabla Stanga Dreapta.in");
  ofstream fout ("tabla Stanga Dreapta.out");

  int v[100], n = -1, S, D, valS, valD, sol[100], indice = -1, computer[100], indice_comp = -1;
  while (!fin.eof()) {
    fin >> v[++n];
  }
  srand(time(NULL));

  for (int i = 0; i <= n; i++)
    cout << v[i] << " ";

  ///Metoda Greedy
  S = 0;
  D = n;
  while (S <= D) {
    valS = v[S] - v[S + 1];
    valD = v[D] - v[D - 1];
    if (valS < valD) {
      sol[++indice] = v[D];
      D--;
    }
    else {
      sol[++indice] = v[S];
      S++;
    }

    if (rand()%2 == 1) {
      computer[++indice_comp] = v[S];
      S++;
    }
    else {
      computer[++indice_comp] = v[D];
      D--;
    }
  }

  for (int i = 0; i <= indice; i++) {
    fout << sol[i] << " ";
  }
  fout << endl;

  for (int i = 0; i <= indice_comp; i++) {
    fout << computer[i] << " ";
  }

  fin.close();
  fout.close();
  return 0;
}
