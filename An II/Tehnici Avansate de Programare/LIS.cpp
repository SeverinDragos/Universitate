#include <iostream>
#include <algorithm>
#include <fstream>
#include <cstring>

using namespace std;

ifstream fin ("LIS.in");
ofstream fout ("LIS.out");

int Cautare(int stanga, int dreapta, int valoare, int* tail, int* v) {
  if (stanga <= dreapta) {
    int mij = (stanga + dreapta) / 2;
    if (valoare <= v[tail[mij]] && valoare > v[tail[mij - 1]])  return mij;
    if (valoare <= v[tail[mij]])  return Cautare(stanga, mij - 1, valoare, tail, v);
    return Cautare(mij + 1, dreapta, valoare, tail, v);
  }
  return -1;
}

void Afisare(int i, int* pred, int* v) {
  if (pred[i] != -1) {
    Afisare(pred[i], pred, v);
  }
  fout << v[i] << " ";
}

int main()
{
  int n;
  fin >> n;
  int* v = new int[n];
  int* tail = new int[n];
  int* pred = new int[n];
  for (int i = 0; i < n; i++)
    fin >> v[i];

  tail[0] = 0;
  pred[0] = -1;
  int indice = 1;
  for (int i = 1; i < n; i++) {
    if (v[i] < v[tail[0]]) {
      tail[0] = i;
      pred[i] = -1;
    }/*
    else if (v[i] > v[tail[indice - 1]]) {
      pred[i] = tail[indice - 1];
      tail[indice++] = i;
    }*/
    else {
      int poz = Cautare(0, indice - 1, v[i], tail, v);
      cout << "pt " << i << " : " << poz << endl;
      if (poz != - 1) {
      tail[poz] = i;
      pred[i] = tail[poz - 1];
      }
      else {
      pred[i] = tail[indice - 1];
      tail[indice++] = i;
      }
    }
  }

  for (int i = 0; i < n; i++) {
    cout << pred[i] << " ";
  }

  Afisare(tail[indice - 1], pred, v);
  fout << endl;
  fout << indice;

  delete []v;
  delete []tail;
  delete []pred;
  fin.close();
  fout.close();
  return 0;
}
