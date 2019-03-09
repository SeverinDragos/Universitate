#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

struct Interval {///De forma [a,b]
  int a, b;
};

bool Comparare (struct Interval x, struct Interval y) {
  if (x.a == y.a)
    return (x.b > y.b);
  return (x.a < y.a);
}

int main()
{
  ifstream fin ("acoperire.in");
  ofstream fout ("acoperire.out");

  int inceput, final, n;
  fin >> inceput >> final >> n;
  Interval v[100];

  for (int i = 0; i < n; i++)
    fin >> v[i].a >> v[i].b;

  sort (v, v + n, Comparare);

  for (int i = 0; i < n; i++)
    cout << v[i].a << " " << v[i].b << endl;

  ///Solutia Greedy
  int nr_intervale_selectate = 0, a_fixat = inceput, imax = -1, max = 0;
  while (a_fixat <= final) {
    imax = -1;
    max = 0;
    for (int i = 0; i < n; i++) {
      if (v[i].a > a_fixat) break;
      else  if (v[i].b > max) {
              imax = i;
              max = v[i].b;
            }
    }
    if (imax == -1) {
      fout << -1;
      break;
    }
    nr_intervale_selectate++;
    a_fixat = v[imax].b;
  }

  if (imax != -1)
  fout << nr_intervale_selectate;
  fin.close();
  fout.close();
  return 0;
}
