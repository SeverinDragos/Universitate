#include <iostream>
#include <algorithm>
#include <fstream>
#include <cmath>

using namespace std;

struct Punct {
  int x, y;
};

double Distanta (struct Punct& A, struct Punct& B) {
  return sqrt((B.x - A.x) * (B.x - A.x) + (B.y - A.y) * (B.y - A.y));
}

bool SortareDupaX (struct Punct& A, struct Punct& B) {
  if (A.x < B.x)  return true;
  return false;
}

bool SortareDupaY (struct Punct& A, struct Punct& B) {
  if (A.y < B.y)  return true;
  return false;
}

double DistantaIntreDouaPuncte (struct Punct X[], int stanga, int dreapta, struct Punct Y[]) {
  if (dreapta - stanga < 4) {
    double d = 9999999;
    for (int i = stanga; i < dreapta; i++) {
      for (int j = i + 1; j <= dreapta; j++) {
        ///if (Distanta(X[i], X[j]) < d) d = Distanta(X[i], X[j]);
        d = min(Distanta(X[i], X[j]), d);
      }
    }
    return d;
  }
  else {
    int mij = (stanga + dreapta) / 2;
    int n = dreapta - stanga + 1;
    struct Punct SY[n], DY[n];
    int ind1 = 0, ind2 = 0;
    for (int i = 0; i < n; i++) {
      if (Y[i].y <= X[mij].x)
        SY[ind1++] = Y[i];
      else
        DY[ind2++] = Y[i];
    }
    double d1 = DistantaIntreDouaPuncte(X, stanga, mij, SY);
    double d2 = DistantaIntreDouaPuncte(X, mij + 1, dreapta, DY);
    double d = min(d1, d2);
    struct Punct LY[n];
    int ind3 = 0;
    for (int i = 0; i < n; i++) {
      if (abs(Y[i].x - X[mij].x) <= d)
        LY[ind3++] = Y[i];
    }
    for (int i = 0; i < ind3 - 1; i++) {
      for (int j = i + 1, k = 0; k < 7 && j < ind3; k++, j++) {
        ///if (Distanta(LY[i], LY[j]) < d) d = Distanta(LY[i], LY[j]);
        d = min (Distanta(LY[i], LY[j]), d);
      }
    }
    return d;
  }
}

int main()
{
  ifstream fin ("Cele mai apropiate doua puncte.in");
  ofstream fout ("Cele mai apropiate doua puncte.out");

  int n;
  fin >> n;
  struct Punct X[n], Y[n];
  for (int i = 0; i < n; i++) {
    fin >> X[i].x >> X[i].y;
    Y[i].x = X[i].x;
    Y[i].y = X[i].y;
  }

  sort(X, X + n, SortareDupaX);
  sort(Y, Y + n, SortareDupaY);

  fout << DistantaIntreDouaPuncte(X, 0, n - 1, Y);

  for (int i = 0; i < n; i++) {
    cout << X[i].x << " " << X[i].y << endl;
  }
  cout << endl;
  for (int i = 0; i < n; i++) {
    cout << Y[i].x << " " << Y[i].y << endl;
  }

  fin.close();
  fout.close();
  return 0;
}
