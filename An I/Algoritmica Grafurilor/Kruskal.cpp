#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

struct muchie {
  int vf1, vf2;
  double pondere;
};

int cmp (const void* a, const void* b) {
  return ((muchie*)a)->pondere - ((muchie*)b)->pondere;
}

void Initializare (int u, int* tata, int* h) {
  tata[u] = h[u] = 0;
}

int Reprez (int u, int* tata) {
  if (tata[u] == 0)
    return u;
  tata[u] = Reprez(tata[u], tata);
  return tata[u];
}

void Reuneste (int u, int v, int* tata, int* h) {
  int ru = Reprez(u, tata), rv = Reprez(v, tata);
  if (h[ru] > h[rv]) {
    tata[rv] = ru;
  }
  else {
    tata[ru] = rv;
    if(h[ru] == h[rv])
        h[rv] ++;
  }
}

int main()
{
  ifstream fin ("graf.in");
  if (!fin.is_open())  cout << "Eroare la deschiderea fisierului!" << endl;

  int n, m, nr_iteratii = 0;
  fin >> n >> m;
  int* tata = new int [n + 1];
  int* h = new int [n + 1];
  muchie* v = new muchie [m];
  for (int i = 0; i < m; i++) {
    fin >> v[i].vf1 >> v[i].vf2 >> v[i].pondere;
  }

  //Sortare muchii
  int (*pf)(const void*, const void*);
  pf = cmp;
  qsort(v, m, sizeof(muchie),pf);

  //Initializare
  for (int i = 1; i <= n; i++)
    Initializare(i, tata, h);

  //Sa fie nebunie
  for (int i = 0; (i < m) && (nr_iteratii != n - 1); i++) {
    if ( Reprez(v[i].vf1, tata) != Reprez(v[i].vf2, tata) ) {
      Reuneste(v[i].vf1, v[i].vf2, tata, h);
      nr_iteratii++;
    }
  }

  //Afisare vector tata (rezultatul)
  for (int i = 1; i <= n; i++) {
    cout << i << ": " << tata[i] << endl;
  }

  delete []tata;
  delete []h;
  delete []v;
  fin.close();
  return 0;
}

  /*Afisare muchii, in caz ca-mi trebuie

  for (int i = 0; i < m; i++) {
    cout <<  v[i].vf1 << " "  << v[i].vf2 << " : "  << v[i].pondere << endl;
  }

  Afisare tata si h

  for (int i = 1; i <= n; i++) {
    cout << i << ": " << tata[i] << " " << h[i] << endl;
  }
  */
