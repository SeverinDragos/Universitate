#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

int Cautare_Binara(int stanga, int dreapta, int v[]) {
  int mij = (stanga + dreapta) / 2;
  if (v[mij - 1] < v[mij] && v[mij] > v[mij + 1]) return v[mij];
  if (v[mij - 1] < v[mij])  return Cautare_Binara(mij + 1, dreapta, v);
  return Cautare_Binara(stanga, mij - 1, v);
}

int main()
{
  ifstream fin ("munte.in");
  ofstream fout ("munte.out");
  int n;
  fin >> n;
  int v[n];
  for (int i = 0; i < n; i++)
    fin >> v[i];

  fout << Cautare_Binara(0, n - 1, v);

  fin.close();
  fout.close();
  return 0;
}
