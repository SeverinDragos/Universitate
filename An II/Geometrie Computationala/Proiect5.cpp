#include <iostream>
#include <algorithm>
#include <math.h>
#include <fstream>
#include <graphics.h>

using namespace std;

struct Punct {
  float x, y;
  int indice;
};

struct Punct baricentru;
struct Punct Origine;

float TestDeOrientare(struct Punct& P, struct Punct& Q, struct Punct& R) {
  return (Q.x * R.y + P.x * Q.y + R.x * P.y) - (Q.x * P.y + R.x * Q.y + R.y * P.x);
}

float CalculDeterminant (float a, float b, float c, float d) {
  return a * d - (b * c);
}

bool Comparare(struct Punct& a, struct Punct& b) {
  float valA = atan(a.y/a.x), valB = atan(b.y/b.x);
  if (a.x < 0)
    valA += 3.14;
  if (b.x < 0)
    valB += 3.14;

  if (valA < valB)  return true;
  return false;
}

int main()
{
  ifstream fin("proiect5.in");
  ofstream fout("proiect5.out");
  int n, m;
  struct Punct* v = new struct Punct[100];
  fin >> n;
  for (int i = 0; i < n; i++) {
    fin >> v[i].x >> v[i].y;
    v[i].indice = i + 1;
  }
  fin >> m;
  for (int i = n; i < n + m; i++) {
    fin >> v[i].x >> v[i].y;
    v[i].indice = i + 1;
  }

  /*for (int i = 0; i < n + m; i++) {
    cout << v[i].x << " " << v[i].y << endl;
  }*/

  ///Determinare baricentru
  ///Primul poligon
  float a1 = v[n/2].y - v[0].y;
  float b1 = v[0].x - v[n/2].x;
  float c1 = - v[0].x * (v[n/2].y - v[0].y) + v[0].y * (v[n/2].x - v[0].x);

  float a2 = v[n/2 + 1].y - v[1].y;
  float b2 = v[1].x - v[n/2 + 1].x;
  float c2 = - v[1].x * (v[n/2 + 1].y - v[1].y) + v[1].y * (v[n/2 + 1].x - v[1].x);

  float Det = CalculDeterminant(a1, b1, a2, b2);
  struct Punct intersectie1;
  intersectie1.x = CalculDeterminant(-c1, b1, -c2, b2) / Det;
  intersectie1.y = CalculDeterminant(a1, -c1, a2, -c2) / Det;
  //cout << intersectie1.x << " " << intersectie1.y << endl;

  ///Al doilea poligon
  a1 = v[n + m/2].y - v[n].y;
  b1 = v[n].x - v[n + m/2].x;
  c1 = - v[n].x * (v[n + m/2].y - v[n].y) + v[n].y * (v[n + m/2].x - v[n].x);

  a2 = v[n + m/2 + 1].y - v[n + 1].y;
  b2 = v[n + 1].x - v[n + m/2 + 1].x;
  c2 = - v[n + 1].x * (v[n + m/2 + 1].y - v[n + 1].y) + v[n + 1].y * (v[n + m/2 + 1].x - v[n + 1].x);

  Det = CalculDeterminant(a1, b1, a2, b2);
  struct Punct intersectie2;
  intersectie2.x = CalculDeterminant(-c1, b1, -c2, b2) / Det;
  intersectie2.y = CalculDeterminant(a1, -c1, a2, -c2) / Det;
  //cout << intersectie2.x << " " << intersectie2.y << endl;

  baricentru.x = (intersectie1.x + intersectie2.x) /2;
  baricentru.y = (intersectie1.y + intersectie2.y) /2;
  //cout << baricentru.x << " " << baricentru.y << endl;

  for (int i = 0; i < n + m; i++) {
    v[i].x -= baricentru.x;
    v[i].y -= baricentru.y;
  }

  /*for (int i = 0; i < n + m; i++)
    cout << v[i].x << " " << v[i].y << endl;*/

  ///Sortare
  sort(v, v + n + m, Comparare);

  /*for (int i = 0; i < n + m; i++)
    cout << v[i].x << " " << v[i].y << endl;*/

  for (int i = 0; i < n + m; i++)
    cout << v[i].indice << endl;

  ///Graham`s Scan
  struct Punct sol[n + m];
  sol[0] = v[0];
  sol[1] = v[1];
  int isol = 1;
  for (int i = 2; i < n + m; i++) {
    while(isol > 0) {
      if (TestDeOrientare(sol[isol - 1], v[i], sol[isol]) < 0)  break;
      isol--;
    }
    sol[++isol] = v[i];
  }

  for (int i = 0; i <= isol; i++)
    fout << sol[i].indice << " ";

  fin.close();
  fout.close();
  return 0;
}
