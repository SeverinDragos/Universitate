#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;

struct Punct {
  float x, y;
};

int O_Pot_Folosi(struct Punct& a, struct Punct& b) {
  if (a.x == b.x || a.y == b.y) return 0;
  return 1;
}

float CalculDeterminant (float a, float b, float c, float d) {
  return a * d - (b * c);
}

float distanta (struct Punct& a, struct Punct& b) {
  return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int main()
{
  struct Punct A[5];
  for (int i = 1; i <= 4; i++) {
  cout << "Coordonatele A" << i << ":" << endl;
  cin >> A[i].x >> A[i].y;
  }

  int A1A2 = O_Pot_Folosi(A[1], A[2]);
  int A2A3 = O_Pot_Folosi(A[2], A[3]);
  int A1A3 = O_Pot_Folosi(A[1], A[3]);
  int indice[5];
  struct Punct CentrulCercului;

  if (A1A2 + A2A3 + A1A3 == 1){
    if (A1A2) {
      indice[1] = 1;
      indice[2] = 2;
    }
    else if (A2A3) {
            indice[1] = 2;
            indice[2] = 3;
         }
         else {
          indice[1] = 1;
          indice[2] = 3;
         }
    CentrulCercului.x = (A[indice[1]].x + A[indice[2]].x) / 2;
    CentrulCercului.y = (A[indice[1]].y + A[indice[2]].y) / 2;
  }
  else {
    if (A1A2 == 0) {
      indice[1] = 2;
      indice[2] = 3;
      indice[3] = 1;
      indice[4] = 3;
      }
      else {
        indice[1] = 1;
        indice[2] = 2;
        if (A2A3 == 0) {
          indice[3] = 1;
          indice[4] = 3;
        }
        else {
          indice[3] = 2;
          indice[4] = 3;
        }
       }
    float m1, m2, md1, md2;
    struct Punct mij1, mij2;
    m1 = (A[indice[2]].y - A[indice[1]].y) / (A[indice[2]].x - A[indice[1]].x);
    md1 = -1 / m1;
    mij1.x = (A[indice[1]].x + A[indice[2]].x) / 2;
    mij1.y = (A[indice[1]].y + A[indice[2]].y) / 2;
    float c1 = -(md1 * mij1.x) + mij1.y;

    m2 = (A[indice[4]].y - A[indice[3]].y) / (A[indice[4]].x - A[indice[3]].x);
    md2 = -1 / m2;
    mij2.x = (A[indice[3]].x + A[indice[4]].x) / 2;
    mij2.y = (A[indice[3]].y + A[indice[4]].y) / 2;
    float c2 = -(md2 * mij2.x) + mij2.y;

    //cout << "m1 = " << m1 << endl << "md1 = " << md1 << endl << "mij1.x = " << mij1.x << endl << "mij1.y = " << mij1.y << endl << "c1 = " << c1 << endl;
    //cout << "m2 = " << m2 << endl << "md2 = " << md2 << endl << "mij2.x = " << mij2.x << endl << "mij2.y = " << mij2.y << endl << "c2 = " << c2 << endl;
    float DetA = CalculDeterminant(md1, -1, md2, -1);
    CentrulCercului.x = CalculDeterminant(-c1, -1, -c2, -1) / DetA;
    CentrulCercului.y = CalculDeterminant(md1, -c1, md2, -c2) / DetA;
  }

  //cout << "Centrul cercului: " << CentrulCercului.x << " " << CentrulCercului.y;
  //cout << "Distanta centru A1 = " << distanta(CentrulCercului, A[1]) << endl;
  //cout << "Distanta centru A4 = " << distanta(CentrulCercului, A[4]) << endl;

  float CentruA1 = distanta(CentrulCercului, A[1]);
  float CentruA4 = distanta(CentrulCercului, A[4]);
  if (CentruA1 == CentruA4)
    cout << "A4 se afla pe cercul circumscris al triunghiului A1A2A3" << endl;
  else if (CentruA1 < CentruA4)
        cout << "A4 se afla in afara cercului circumscris al triunghiului A1A2A3" << endl;
       else
        cout << "A4 se afla in interiorul cercului circumscris al triunghiului A1A2A3" << endl;

  if (distanta(A[1], A[2]) + distanta(A[3], A[4]) == distanta(A[1], A[4]) + distanta(A[2], A[3]))
    cout << "Patrulaterul este circumscriptibil" << endl;
  else
    cout << "Patrulaterul nu este circumscriptibil" << endl;
  return 0;
}
