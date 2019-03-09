#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int Hoare_partition(int stanga, int dreapta, int* v) {
  int pivot = v[stanga], i = stanga + 1, j = dreapta;;
  while(1) {
    while (v[i] < pivot && i <= dreapta) i++;
    while (v[j] > pivot && i < j) j--;

    if (i >= j) {
      swap(v[stanga], v[i - 1]);
      return i - 1;
    }

    swap(v[i], v[j]);
  }
}

void Quicksort(int stanga, int dreapta, int* v) {
  if (stanga < dreapta) {
    srand(time(NULL));
    int random = rand() % (dreapta - stanga + 1) + stanga;
    swap(v[random], v[stanga]);
    int pivot = Hoare_partition(stanga, dreapta, v);
    Quicksort(stanga, pivot - 1, v);
    Quicksort(pivot + 1, dreapta, v);
  }
}

int main()
{
  ifstream fin("Quicksort Hoare.in");
  ofstream fout("Quicksort Hoare.out");
  int n;
  fin >> n;
  int* v = new int[n];
  for(int i = 0; i < n; i++) {
    fin >> v[i];
  }

  Quicksort(0, n - 1, v);

  for(int i = 0; i < n; i++) {
    fout << v[i] << " ";
  }

  delete []v;
  fin.close();
  fout.close();
}
