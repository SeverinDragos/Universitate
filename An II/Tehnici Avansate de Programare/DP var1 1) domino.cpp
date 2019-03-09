#include <iostream>
#include <fstream>

using namespace std;

int D[100], pred[100], combinatii[100];

void Afisare(int i, pair<int, int> v []) {
  if (pred[i] != 0)
  Afisare(pred[i], v);
  cout << v[i].first << " " << v[i].second << endl;
}

int main()
{
  ifstream fin ("domino.in");
  ofstream fout ("domino.out");

  int x, y, n;
  fin >> n;
  pair<int, int> v[n];
  for (int i = 0; i < n; i++) {
    fin >> x >> y;
    v[i] = make_pair(x, y);
  }

  for (int i = 0; i < n; i++) {
    int lmax = 1;
    for (int j = 0; j < i; j++) {
      if (v[j].second == v[i].first)
        if (D[j] + 1 > lmax) {
          lmax = D[j] + 1;
          pred[i] = j;
          combinatii[i] = 1;
        }
        else if (D[j] + 1 == lmax) {
          combinatii[i]++;
        }
    }
    D[i] = lmax;
  }

  int max = 0, imax = -1, comb = 0;
  for (int i = 0; i < n; i++) {
    if (D[i] > max)
    {
      max = D[i];
      imax = i;
      comb = combinatii[i];
    }
    else if (D[i] == max) {
      comb += combinatii[i];
    }
  }

  fout << "Lungime maxima: " << max << endl;
  Afisare(imax, v);
  fout << "Numar de combinatii: " << comb;

  return 0;
}
