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
  ifstream fin ("n-planificare.in");
  ofstream fout ("n-planificare.out");

  int n, indice;
  fin >> n;
  struct Activitate v[n], sol[n][n];
  int ultimul[n], linia, capat_max;
  for (int i = 0; i < n; i++) {
    fin >> v[i].inceput >> v[i].final;
  }

  sort(v, v + n, Comparare);

  for (int i = 0; i < n; i++) {
    cout << v[i].inceput << " " << v[i].final << endl;
  }

  ///Metoda Greedy
  sol[0][0] = v[0];
  ultimul[0] = 0;
  indice = 0;
  for (int i = 1; i < n; i++) {
    linia = -1;
    capat_max = -1;
    for (int j = 0; j <= indice; j++) {
      if (v[i].inceput >= sol[j][ultimul[j]].final) {
        if (sol[j][ultimul[j]].final > capat_max) {
          capat_max = sol[j][ultimul[j]].final;
          linia = j;
        }
      }
    }
    if (linia == -1) {
      sol[++indice][0] = v[i];
      ultimul[indice] = 0;
    }
    else {
      ultimul[linia]++;
      sol[linia][ultimul[linia]] = v[i];
    }
  }

  for (int i = 0; i <= indice; i++) {
    for (int j = 0; j <= ultimul[i]; j++) {
      fout << sol[i][j].inceput << " " << sol[i][j].final << " , ";
    }
    fout << endl;
  }

  fin.close();
  fout.close();
  return 0;
}
