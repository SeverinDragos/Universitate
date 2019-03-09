#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>

using namespace std;

struct Element {
  int val;
  float pondere;
};

float Mediana_ponderata(int stanga, int dreapta, struct Element v[]) {
  if (dreapta - stanga <= 1) {
    if (v[stanga].pondere > v[dreapta].pondere) return v[stanga].val;
    return v[dreapta].val;
  }
  else {
    int pivot = (dreapta - stanga) / 2 + stanga; ///Mediana neponderata
    float suma_stanga = 0, suma_dreapta = 0;
    for (int i = stanga; i < pivot; i++) {
      suma_stanga  += v[i].pondere;
    }
    for (int i = dreapta; i > pivot; i--) {
      suma_dreapta += v[i].pondere;
    }
    if (suma_dreapta > 0.5) {
      v[pivot].pondere += suma_stanga;
      return Mediana_ponderata(pivot, dreapta, v);
    }
    if (suma_stanga >= 0.5) {
      v[pivot].pondere += suma_dreapta;
      return Mediana_ponderata(stanga, pivot, v);
    }
    return v[pivot].val;
  }
}

int main()
{
  ifstream fin("Mediana Ponderata.in");
  ofstream fout("Mediana Ponderata.out");
  int n;
  fin >> n;
  struct Element v[n];
  for(int i = 0; i < n; i++) {
    fin >> v[i].val >> v[i].pondere;
  }

  fout << Mediana_ponderata(0, n - 1, v);

  fin.close();
  fout.close();
}
