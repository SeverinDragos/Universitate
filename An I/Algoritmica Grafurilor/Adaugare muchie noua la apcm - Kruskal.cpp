#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <cstring>

using namespace std;

struct muchie {
  int vf1, vf2, pondere;
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

void DF (int u , int& contor, vector <pair <int, int> > li[], int* tata, int* viz, muchie* ciclu, int& indice) {
    viz[u] = 1;
    for (int i = 0; i < li[u].size(); i ++)
    if (contor == 0){
      int v = li[u][i].second;
      if (viz[v] == 0) {
        tata[v] = u;
        DF(v,contor, li, tata, viz, ciclu, indice);
      }
      else if (tata[u] != v){
        contor = 1;
        indice = 0;
        ciclu[indice].vf1 = u;
        ciclu[indice].vf2 = v;
        ciclu[indice].pondere = li[u][i].first;
        indice++;
        int parc = u;
        while (parc != v) {
          for (int j = 0; j < li[parc].size(); j++) {
            if (tata[parc] == li[parc][j].second) {
              ciclu[indice].vf1 = parc;
              ciclu[indice].vf2 = tata[parc];
              ciclu[indice].pondere = li[parc][j].first;
              indice++;
            }
          }
          parc = tata[parc];
        }
      }
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
  int* viz = new int [n + 1];
  muchie* v = new muchie [m];
  vector <pair <int, int> > li[n + 1];
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

  muchie nou;
  cin >> nou.vf1 >> nou.vf2 >> nou.pondere;

  int sum = 0;
  cout << "Muchiile apcm in G: " << endl;
  //Sa fie nebunie
  for (int i = 0; (i < m) && (nr_iteratii != n - 1); i++) {
    if ( Reprez(v[i].vf1, tata) != Reprez(v[i].vf2, tata) ) {
      Reuneste(v[i].vf1, v[i].vf2, tata, h);
      cout << v[i].vf1 << " " << v[i].vf2 << endl;
      sum += v[i].pondere;
      li[v[i].vf1].push_back(make_pair(v[i].pondere, v[i].vf2));
      li[v[i].vf2].push_back(make_pair(v[i].pondere, v[i].vf1));
      nr_iteratii++;
    }
  }
  cout << "Cost " << sum << endl;

  memset(tata, 0, sizeof(int) * (n + 1));
  memset(viz, 0, sizeof(int) * (n + 1));

  muchie* ciclu = new muchie [n];
  li[nou.vf1].push_back(make_pair(nou.pondere, nou.vf2));
  li[nou.vf2].push_back(make_pair(nou.pondere, nou.vf1));

  int contor = 0, indice = 0;
  DF(nou.vf1, contor, li, tata, viz, ciclu, indice);

  int maxim = 0, retin;
  for (int i = 0; i < indice; i++) {
    if (ciclu[i].pondere > maxim) {
      maxim = ciclu[i].pondere;
      retin = i;
    }
  }

  cout << "Muchia de cost maxim din ciclul inchis de " << nou.vf1 << " " << nou.vf2 << " in apcm este " << ciclu[retin].vf1 << " " << ciclu[retin].vf2 << " de cost " << ciclu[retin].pondere << endl;
  cout << "Dupa adaugarea muchiei apcm are costul " << sum + nou.pondere - ciclu[retin].pondere << endl;

  delete []viz;
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
