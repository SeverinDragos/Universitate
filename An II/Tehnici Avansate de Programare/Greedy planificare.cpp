#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

struct Activitate {
  int inceput, final;
};

bool Comparare (struct Activitate a, struct Activitate b) {
  return b.final > a.final;
}

int main()
{
  ifstream fin ("planificare.in");
  ofstream fout ("planificare.out");

  int n, indice;
  fin >> n;
  struct Activitate v[n], sol[n];
  for (int i = 0; i < n; i++) {
    fin >> v[i].inceput >> v[i].final;
  }

  sort(v, v + n, Comparare);

  for (int i = 0; i < n; i++) {
    cout << v[i].inceput << " " << v[i].final << endl;
  }

  ///Metoda Greedy
  sol[0] = v[0];
  indice = 0;
  for (int i = 1; i < n; i++) {
    if (v[i].inceput >= sol[indice].final) {
      sol[++indice] = v[i];
    }
  }

  for (int i = 0; i <= indice; i++) {
    fout << sol[i].inceput << " " << sol[i].final << endl;
  }

  fin.close();
  fout.close();
  return 0;
}
