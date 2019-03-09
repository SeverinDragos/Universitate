#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cmath>
#include <vector>

using namespace std;

struct muchie {
  int vf1, vf2;
  double pondere;
};

struct punct2D {
  int x, y;
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

double distanta (int x1, int y1, int x2, int y2) {
  if (x1 == x2)
    return abs(y1 - y2);
  if (y1 == y2)
    return abs(x1 - x2);
  return sqrt( pow(abs(x1 - x2), 2) + pow(abs(y1 - y2), 2) );
}

int main()
{
  ifstream fin ("graf.in");
  if (!fin.is_open())  cout << "Eroare la deschiderea fisierului!" << endl;

  int n, m, blocuri, centrale, nr_iteratii = 0, nod, nod2, cost_total = 0;
  fin >> centrale >> blocuri >> m;
  n = centrale + blocuri;
  int* tata = new int [n + 1];
  int* h = new int [n + 1];
  muchie* v = new muchie [m];
  punct2D* coordonate = new punct2D [n + 1];
  for (int i = 1; i <= n; i++) {
    fin >> coordonate[i].x >> coordonate[i].y;
  }

  for (int i = 0; i < m; i++) {
    fin >> nod >> nod2;
    v[i].vf1 = nod;
    v[i].vf2 = nod2;
    v[i].pondere = distanta(coordonate[nod].x, coordonate[nod].y, coordonate[nod2].x, coordonate[nod2].y);
  }

  ///Sortare muchii
  int (*pf)(const void*, const void*);
  pf = cmp;
  qsort(v, m, sizeof(muchie),pf);

  ///Initializare
  for (int i = 1; i <= n; i++)
    Initializare(i, tata, h);

  for (int i = 2; i <= centrale; i++) {
    tata[i] = 1;
  }

  ///Sa fie nebunie
  for (int i = 0; (i < m) && (nr_iteratii != n - 1); i++) {
    if ( Reprez(v[i].vf1, tata) != Reprez(v[i].vf2, tata) ) {
      Reuneste(v[i].vf1, v[i].vf2, tata, h);
      cout << v[i].vf1 << " " << v[i].vf2 << endl;
      cost_total += v[i].pondere;
      nr_iteratii++;
    }
  }

  cout << "Costul: " << cost_total << endl;

  delete []tata;
  delete []h;
  delete []v;
  fin.close();
  return 0;
}

  /**Afisare muchii, in caz ca-mi trebuie

  for (int i = 0; i < m; i++) {
    cout <<  v[i].vf1 << " "  << v[i].vf2 << " : "  << v[i].pondere << endl;
  }

  Afisare tata si h

  for (int i = 1; i <= n; i++) {
    cout << i << ": " << tata[i] << " " << h[i] << endl;
  }
  */
