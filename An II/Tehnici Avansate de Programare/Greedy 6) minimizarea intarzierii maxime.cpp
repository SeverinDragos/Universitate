#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

struct Activitate {
  int lungime, termen, indice_initial;
};

bool Comparare (struct Activitate& a, struct Activitate& b) {
  return a.termen <= b.termen;
}

int main()
{
  ifstream fin ("minimizarea intarzierii maxime.in");
  ofstream fout ("minimizarea intarzierii maxime.out");

  int n;
  fin >> n;
  struct Activitate v[n];
  for (int i = 0; i < n; i++) {
    fin >> v[i].lungime >> v[i].termen;
    v[i].indice_initial = i + 1;
  }

  sort(v, v + n, Comparare);

  ///Metoda Greedy
  int final = 0, intarziere_maxima = -1;
  for (int i = 0; i < n; i++) {
    fout << "activitatea " << v[i].indice_initial << ": intervalul [" << final << " " << final + v[i].lungime << ") intarziere " << final + v[i].lungime - v[i].termen << endl;
    if (final + v[i].lungime - v[i].termen > intarziere_maxima)
      intarziere_maxima = final + v[i].lungime - v[i].termen;
    final += v[i].lungime;
  }
  fout << "Intarziere planificare " << intarziere_maxima << endl;



  fin.close();
  fout.close();
  return 0;
}
