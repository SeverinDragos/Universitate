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

int KMin(int stanga, int dreapta, int K, int* v) {
  srand(time(NULL));
  int random = rand() % (dreapta - stanga + 1) + stanga;
  swap(v[random], v[stanga]);
  int pivot = Hoare_partition(stanga, dreapta, v);

  if (pivot == K) return v[K];
  if (pivot < K) return KMin(pivot + 1, dreapta, K, v);
  return KMin(stanga, pivot - 1, K, v);
}

int main()
{
  ifstream fin("Al K-lea minim.in");
  ofstream fout("Al K-lea minim.out");
  int K, n;
  fin >> K >> n;
  K--;
  int* v = new int[n];
  for(int i = 0; i < n; i++) {
    fin >> v[i];
  }

  fout << KMin(0, n - 1, K, v);

  delete []v;
  fin.close();
  fout.close();
}
