#include <iostream>
#include <fstream>

using namespace std;

void Sort(int stanga, int mij, int dreapta, int* v) {
  int intermediar[dreapta - stanga + 1];
  int i = stanga, j = mij + 1, indice = 0;
  while (i <= mij && j <= dreapta) {
    if (v[i] < v[j])
      intermediar[indice++] = v[i++];
    else
      intermediar[indice++] = v[j++];
  }

  while (i <= mij)
    intermediar[indice++] = v[i++];
  while (j <= dreapta)
    intermediar[indice++] = v[j++];

  for (i = stanga; i <= dreapta; i++) {
    v[i] = intermediar[i - stanga];
  }
}

void mergeSort(int stanga, int dreapta, int* v) {
  if (stanga < dreapta) {
    int mij = (stanga + dreapta) / 2;
    mergeSort(stanga, mij, v);
    mergeSort(mij + 1, dreapta, v);
    Sort(stanga, mij, dreapta, v);
  }
}

int main()
{
  ifstream fin("mergeSort.in");
  ofstream fout("mergeSort.out");
  int n;
  fin >> n;
  int* v = new int[n];
  for(int i = 0; i < n; i++) {
    fin >> v[i];
  }

  mergeSort(0, n - 1, v);

  for (int i = 0; i < n; i++) {
    fout << v[i] << " ";
  }


  delete []v;
  fin.close();
  fout.close();
}
