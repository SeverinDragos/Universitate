#include <iostream>
#include <algorithm>
#include <fstream>
#include <cstring>

using namespace std;

ifstream fin ("ActivitatiCuProfit.in");
ofstream fout ("ActivitatiCuProfit.out");

struct Activitate {
  int inceput, final, profit;
};

bool Comparare(struct Activitate& a, struct Activitate& b) {
  return (a.final <= b.final);
}

int Cautare(int stanga, int dreapta, int i, struct Activitate* v) {
  if (stanga <= dreapta) {
    int mij = (stanga + dreapta) / 2;
    if (v[mij].final <= v[i].inceput && v[mij + 1].final > v[i].inceput)  return mij;
    else if (v[mij + 1].final <= v[i].inceput)  return Cautare(mij + 1, dreapta, i, v);
    return Cautare(stanga, mij - 1, i, v);
  }
  return -1;
}

void Afisare (int i, int* pred, struct Activitate* v) {
  if (pred[i] != -2) {
    if (pred[i] == -1) {
      Afisare(i - 1, pred, v);
    }
    else {
      Afisare(pred[i], pred, v);
      fout << v[i].inceput << " " << v[i].final << endl;
    }
  }
  else {
    fout << v[i].inceput << " " << v[i].final << endl;
  }
}

int main()
{
  int n;
  fin >> n;
  int* pred = new int[n];
  int* Profit = new int[n];
  struct Activitate* v = new struct Activitate[n];
  for (int i = 0; i < n; i++)
    fin >> v[i].inceput >> v[i].final >> v[i].profit;

  sort(v, v + n, Comparare);
  fill_n(pred, n, -2);

  Profit[0] = v[0].profit;
  for (int i = 1; i < n; i++) {
    int daca_includ = v[i].profit;
    int j = Cautare(0, i - 1, i, v);
    if (j != -1)  daca_includ += Profit[j];

    if (daca_includ > Profit[i - 1]) {
      Profit[i] = daca_includ;
      if (j != -1)  pred[i] = j;
    }
    else {
      Profit[i] = Profit[i - 1];
      pred[i] = -1;
    }
  }
/*
  for (int i = 0; i < n; i++) {
    cout << pred[i] << " ";
  }*/

  Afisare(n - 1, pred, v);
  fout << Profit[n - 1];

  delete []v;
  delete []pred;
  delete []Profit;
  fin.close();
  fout.close();
  return 0;
}
