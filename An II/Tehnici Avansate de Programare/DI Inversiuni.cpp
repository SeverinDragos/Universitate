#include <iostream>
#include <fstream>

using namespace std;

int Sort(int stanga, int mij, int dreapta, int* v) {
  int intermediar[dreapta - stanga + 1];
  int i = stanga, j = mij + 1, indice = 0, Inv = 0;
  while (i <= mij && j <= dreapta) {
    if (v[i] < v[j])
      intermediar[indice++] = v[i++];
    else {
      intermediar[indice++] = v[j++];
      Inv += mij - i + 1;
    }
  }

  while (i <= mij)
    intermediar[indice++] = v[i++];
  while (j <= dreapta)
    intermediar[indice++] = v[j++];

  for (i = stanga; i <= dreapta; i++) {
    v[i] = intermediar[i - stanga];
  }
  return Inv;
}

int NrInv(int stanga, int dreapta, int* v) {
  if (stanga < dreapta) {
    int mij = (stanga + dreapta) / 2;
    int rez1 = NrInv(stanga, mij, v);
    int rez2 = NrInv(mij + 1, dreapta, v);
    return Sort(stanga, mij, dreapta, v) + rez1 + rez2;
  }
  return 0;
}

int main()
{
  ifstream fin("Inversiuni.in");
  ofstream fout("Inversiuni.out");
  int n;
  fin >> n;
  int* v = new int[n];
  for(int i = 0; i < n; i++) {
    fin >> v[i];
  }

  fout << NrInv(0, n - 1, v);


  delete []v;
  fin.close();
  fout.close();
}
