#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cstring>

using namespace std;

struct muchie {
  int vf1, vf2;
  int pondere;
};

int distanta(char *s1, char *s2){
int n1=strlen(s1);
int n2=strlen(s2);
int *ci1=new int[n2+1];
int *ci=new int[n2+1];
for(int j=0;j<=n2;j++)
ci1[j]=j;
for(int i=1;i<=n1;i++){
ci[0]=i;
for(int j=1;j<=n2;j++)
if(s1[i-1]==s2[j-1])
ci[j]=ci1[j-1];
else
ci[j]=1+min(min(ci1[j],ci[j-1]),ci1[j-1]);
for(int j=0;j<=n2;j++)
ci1[j]=ci[j];
}
return ci[n2];
}

int cmp (const void* a, const void* b) {
  return ((muchie*)a)->pondere - ((muchie*)b)->pondere;
}

void Initializare (int u, int* tata, int* h) {
  tata[u] = -1;
  h[u] = 0;
}

int Reprez (int u, int* tata) {
  if (tata[u] == -1)
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
  ifstream fin ("cuvinte.in");
  if (!fin.is_open())  cout << "Eroare la deschiderea fisierului!" << endl;

  int nr_iteratii = 0, k, n = 0, ind = 0, separare;
  char cuv[50][25], s[25];
  for (int i = 0; i < 50; i++) {
    cuv[i][0] = '\0';
  }

  while (fin >> s) {
    strcpy(cuv[n++], s);
  }



  int* tata = new int [n];
  int* h = new int [n];
  muchie* v = new muchie [(n * (n - 1)) / 2];


  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n; j++) {
      if (i < j) {
      v[ind].vf1 = i;
      v[ind].vf2 = j;
      v[ind].pondere = distanta(cuv[i], cuv[j]);
      ind++;
      }
    }
  }


  //Sortare muchii
  int (*pf)(const void*, const void*);
  pf = cmp;
  qsort(v, (n * (n - 1)) / 2, sizeof(muchie),pf);


  //Initializare
  for (int i = 0; i < n; i++)
    Initializare(i, tata, h);

  cout << "Numarul de clase:";
  cin >> k;
  //Sa fie nebunie
  for (int i = 0; (i < (n * (n - 1)) / 2) && (nr_iteratii < n - k); i++) {
    if ( Reprez(v[i].vf1, tata) != Reprez(v[i].vf2, tata) ) {
      Reuneste(v[i].vf1, v[i].vf2, tata, h);
      nr_iteratii++;
    }
    separare = v[i].pondere;
  }

  //Afisare vector tata (rezultatul)
  for (int i = 0; i < n; i++) {
    cout << i << ": " << tata[i] << endl;
  }
  cout << separare << endl;

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
