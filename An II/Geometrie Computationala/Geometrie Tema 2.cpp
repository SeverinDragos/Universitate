#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;

struct Punct {
  float x, y;
};

struct Det {
  float val;
  int punct_exclus;
};

int Comparare (const void* a, const void* b) {
  if ( ((struct Punct*)b)->x == ((struct Punct*)a)->x)
    return ((struct Punct*)a)->y - ((struct Punct*)b)->y;
  return ((struct Punct*)b)->x - ((struct Punct*)a)->x;
}

int Comparare2 (const void* a, const void* b) {
  if ( ((struct Punct*)b)->y == ((struct Punct*)a)->y)
    return ((struct Punct*)a)->x - ((struct Punct*)b)->x;
  return ((struct Punct*)b)->y - ((struct Punct*)a)->y;
}

int ComparareDet (const void* a, const void* b) {
  return ((struct Det*)a)->val - ((struct Det*)b)->val;
}

int Coliniare (struct Punct A[4], struct Punct& a) {
  if ((a.x - A[0].x) * (A[1].y - A[0].y) == (a.y - A[0].y) * (A[1].x - A[0].x))
    return 1;
  return 0;
}

float CalculArie(struct Punct& a, struct Punct& b, struct Punct& c) {
  return abs((a.x * b.y) + (b.x * c.y) + (c.x * a.y) - (b.y * c.x) - (c.y * a.x) - (a.y * b.x)) / 2;
}

bool TestOrientare(struct Punct& a, struct Punct& b, struct Punct& c) {
  if (((b.x * c.y) + (a.x * b.y) + (a.y * c.x) - (b.x * a.y) - (c.x * b.y) - (c.y * a.x)) < 0)  return false;
  return true;
}

int main()
{
  struct Punct A[4];
  for (int i = 0; i < 4; i++) {
    cout << "Coordonatele punctului A" << i + 1 << ":" << endl;
    cin >> A[i].x >> A[i].y;
  }

  ///Cazul I, Punctele sunt coliniare
  if (Coliniare(A, A[2]) && Coliniare(A, A[3])) {
    if (A[0].x == A[1].x == A[2].x == A[3].x) {
      int (*pf)(const void*, const void*) = Comparare2;
      qsort (A, 4, sizeof(struct Punct), pf);
    }
    else {
      int (*pf)(const void*, const void*) = Comparare;
      qsort (A, 4, sizeof(struct Punct), pf);
    }
    cout << "I = { (" << A[0].x << "," << A[0].y << "), (" << A[2].x << "," << A[2].y << ") }";
    cout << "J = { (" << A[1].x << "," << A[1].y << "), (" << A[3].x << "," << A[3].y << ") }";
    return 0;
  }

  ///Cazul II, Punctele formeaza un triunghi
  struct Det D[4];
  D[0].val = CalculArie(A[0], A[1], A[2]);
  D[0].punct_exclus = 3;
  D[1].val = CalculArie(A[0], A[1], A[3]);
  D[1].punct_exclus = 2;
  D[2].val = CalculArie(A[0], A[2], A[3]);
  D[2].punct_exclus = 1;
  D[3].val = CalculArie(A[1], A[2], A[3]);
  D[3].punct_exclus = 0;
  qsort(D, 4, sizeof(struct Det), ComparareDet);

  /*
  for (int i = 0; i < 4; i++) {
    cout << D[i].val << " ";
  }*/

  if (D[0].val + D[1].val + D[2].val == D[3].val) {
    cout << "I = { ";
    for (int i = 0; i < 4; i++)
      if (D[3].punct_exclus != i)
        cout << "(" << A[i].x << "," << A[i].y <<") ";
      cout << "}";

    cout << endl << "J = { (" << A[D[3].punct_exclus].x << "," << A[D[3].punct_exclus].y << ") }";
    return 0;
  }

  ///Cazul III, Punctele formeaza un paralelogram
  if (TestOrientare(A[0], A[1], A[2]) != TestOrientare(A[0], A[1], A[3])) {
    cout << "I = { (" << A[0].x << "," << A[0].y << ") (" << A[1].x << "," << A[1].y << ") }";
    cout << "J = { (" << A[2].x << "," << A[2].y << ") (" << A[3].x << "," << A[3].y << ") }";
    return 0;
  }
  if (TestOrientare(A[0], A[2], A[1]) != TestOrientare(A[0], A[2], A[3])) {
    cout << "I = { (" << A[0].x << "," << A[0].y << ") (" << A[2].x << "," << A[2].y << ") }";
    cout << "J = { (" << A[1].x << "," << A[1].y << ") (" << A[3].x << "," << A[3].y << ") }";
    return 0;
  }
  if (TestOrientare(A[0], A[3], A[2]) != TestOrientare(A[0], A[3], A[1])) {
    cout << "I = { (" << A[0].x << "," << A[0].y << ") (" << A[3].x << "," << A[3].y << ") }";
    cout << "J = { (" << A[1].x << "," << A[1].y << ") (" << A[2].x << "," << A[2].y << ") }";
    return 0;
  }


  return 0;
}
