#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

int flux[100][100], capacitate[100][100];

int BF(int s, int* tata, int* viz, vector <int> l[], vector <int> lin[], int n) {
  memset(tata, 0, sizeof(int) * (2*n + 3));
  memset(viz, 0, sizeof(int) * (2*n + 3));
  queue <int> Q;
  int u, v;
  Q.push(s);
  viz[s] = 1;
  while (!Q.empty()) {
    u = Q.front();
    Q.pop();
    for (int i = 0; i < l[u].size(); i++) { /// Pe listele de intrare
      v = l[u][i];
      if (viz[v] == 0 && capacitate[u][v] - flux[u][v] > 0) {
        tata[v] = u;
        if (v == 2*n + 2)  return 1;
        Q.push(v);
        viz[v] = 1;
      }
    }
    for (int i = 0; i < lin[u].size(); i++) { /// Pe listele de iesire (arce inverse)
      v = lin[u][i];
      if (viz[v] == 0 && flux[v][u] > 0) {
        tata[v] = -u;
        if (v == 2*n + 2)  return 1;
        Q.push(v);
        viz[v] = 1;
      }
    }
  }
  return 0;
}

int main()
{
  ifstream fin ("graf.in");
  if (!fin.is_open())  cout << "Eroare la deschiderea fisierului!" << endl;

  int n, cost;
  fin >> n;
  int* tata = new int [2*n + 2 + 1]; ///Varfurile de doua ori + sursa si destinatie + incepem de la 1, nu 0
  int* viz = new int [2*n + 2 + 1];
  vector <int> l[2*n + 2 + 1];
  vector <int> lin[2*n + 2 + 1];

  int s = 1, t = 2*n + 2, fmax = 0, iP, suma = 0, suma2 = 0;

  for (int i = 2; i < n + 2; i++) { ///De la sursa la varfurile din prima multime
    fin >> cost;
    l[s].push_back(i);
    lin[i].push_back(s);
    capacitate[s][i] = cost;
    suma += cost;
  }

  for (int i = n + 2; i < 2*n + 2; i++) { ///De la varfurile din a doua multime la destinatie
    fin >> cost;
    l[i].push_back(t);
    lin[t].push_back(i);
    capacitate[i][t] = cost;
    suma2 += cost;
  }

  if (suma != suma2) {
    cout << "Date de intrare incorecte" << endl;
    return 0;
  }

  for (int i = 2; i < n + 2; i++) {
    for (int j = n + 2; j < 2*n + 2; j++) {
      if (i != j - n) { ///Daca nu e corespondentul lui
        l[i].push_back(j);
        lin[j].push_back(i);
        capacitate[i][j] = 1;
      }
    }
  }

  while (BF(1,tata,viz,l,lin,n) == 1) { ///Cat timp nu ne blocam (nu am ajuns la taietura minima)
    iP = 999999;
    t = 2*n + 2;
    ///Determinare iP (capacitatea reziduala)
    cout << "Lantul din BF la pasul asta: " << endl;
    while (t!=s) {
      cout << t << " ";
      if (tata[t] > 0) {
        iP = min(iP, capacitate[tata[t]][t] - flux[tata[t]][t]);
        t = tata[t];
      }
      else {
        iP = min(iP, flux[t][-tata[t]]);
        t = - tata[t];
      }
    }
    cout << s << " capacitate reziduala: " << iP << endl;
    ///Revizuire flux
    t = 2*n + 2;
    while (t!=s) {
      if (tata[t] > 0) {
        flux[tata[t]][t] += iP;
        t = tata[t];
      }
      else {
        flux[t][-tata[t]] -= iP;
        t = -tata[t];
      }
    }
    fmax += iP;
  }

  if (fmax == suma) {
    for (int i = 2; i < n + 2; i++) {
      for (int j = 0; j < l[i].size(); j++) { ///Pe muchiile pornind din prima multime
        if(flux[i][l[i][j]] == 1) {
          cout << i - 1 << " " << l[i][j] - n - 1 << endl;
        }
      }
    }
  }


  delete []tata;
  delete []viz;
  fin.close();
  return 0;
}
