#include <iostream>

using namespace std;

int D[100], pred[100], combinatii[100];

void Afisare(int i, pair<int, int> v []) {
  if (pred[i] != 0)
  Afisare(pred[i], v);
  cout << v[i].first << " " << v[i].second << endl;
}

int main()
{
  pair<int, int> v[100];
  int x, y, n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x >> y;
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
          combinatii[i] ++;
        }
    }
    D[i] = lmax;
  }

  int max = 0, imax = -1;
  for (int i = 0; i < n; i++)
    if (D[i] > max)
    {
      max = D[i];
      imax = i;
    }

  cout << "Lungime maxima: " << max << endl;
  Afisare(imax, v);
  cout << "Numar de combinatii: " << combinatii[imax];

  return 0;
}
