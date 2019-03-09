#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;

struct Punct {
  float x, y;
  int Eu, Perechea;
};

float CalculDeterminant (float a, float b, float c, float d) {
  return a * d - (b * c);
}

int Comparare (const void* a, const void* b) {
  if (((struct Punct*)a)->x == ((struct Punct*)b)->x)
    return ((struct Punct*)a)->y - ((struct Punct*)b)->y;
  return ((struct Punct*)a)->x - ((struct Punct*)b)->x;
}

int main()
{
  struct Punct A[4];
  for (int i = 0; i < 4; i++) {
    cout << "Coordonatele punctului A" << i + 1 << ":" << endl;
    cin >> A[i].x >> A[i].y;
    A[i].Eu = i;
    if (i % 2 == 0)
    A[i].Perechea = i + 1;
    else
    A[i].Perechea = i - 1;
  }
  float a1 = A[1].y - A[0].y;
  float b1 = A[0].x - A[1].x;
  float a2 = A[3].y - A[2].y;
  float b2 = A[2].x - A[3].x;
  float c1 = - A[0].x * (A[1].y - A[0].y) + A[0].y * (A[1].x - A[0].x);
  float c2 = - A[2].x * (A[3].y - A[2].y) + A[2].y * (A[3].x - A[2].x);
  float DetA = CalculDeterminant(a1, b1, a2, b2);

  /*cout << a1 << "x +" << b1 << "y +" << c1 << endl;
  cout << a2 << "x +" << b2 << "y +" << c2 << endl;*/
  if (DetA != 0)  {///Cazul I
    float x = CalculDeterminant(-c1, b1, -c2, b2) / DetA;
    float y = CalculDeterminant(a1, -c1, a2, -c2) / DetA;
    bool A0A1 = false, A2A3 = false;

    if (A[0].x == x == A[1].x) {
      if ((A[0].y <= y) && (y <= A[1].y) || (A[0].y >= y) && (y >= A[1].y))
        A0A1 = true;
    }
    else
      if ((A[0].x <= x) && (x <= A[1].x) || (A[0].x >= x) && (x >= A[1].x))
        A0A1 = true;

    if (A[2].x == x == A[3].x) {
      if ((A[2].y <= y) && (y <= A[3].y) || (A[2].y >= y) && (y >= A[3].y))
        A2A3 = true;
    }
    else
      if ((A[2].x <= x) && (x <= A[3].x) || (A[2].x >= x) && (x >= A[3].x))
        A2A3 = true;

    if (A0A1 == true && A2A3 == true)
      cout << "Intersectia celor doua segmente este punctul: " << x << " " << y << endl;
    else
      cout << "Cele doua segmente nu se intersecteaza" << endl;
  }
  else {///Cazul II
    if (CalculDeterminant(a1, c1, a2, c2) != 0 || CalculDeterminant(b1, c1, b2 ,c2) != 0)
      cout << "Cele doua segmente nu se intersecteaza" << endl;
    else {
      qsort(A, 4, sizeof(struct Punct), Comparare);
      /*for (int i = 0; i < 4; i++)
        cout << "Coordonatele punctului A" << i << ":" << A[i].x << " " << A[i].y << endl;*/
      if (A[0].Perechea == A[1].Eu)
        cout << "Cele doua segmente nu se intersecteaza" << endl;
      else
      cout << "Intersectia celor doua segmente este segmentul [" << A[1].x << " " << A[1].y << "," << A[2].x << " " << A[2].y << "]" << endl;
    }
  }
  return 0;
}
