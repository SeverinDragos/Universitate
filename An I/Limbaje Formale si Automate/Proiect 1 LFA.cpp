#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <fstream>

using namespace std;

class Tranzitie {
    char *stare , caracter;
    Tranzitie* next;
public:
    Tranzitie(char* p = "" , char c = '0' , Tranzitie* p2 = NULL);
    ~Tranzitie();
    Tranzitie* get_next();
    void set_next(char* p = "" , char c = '0' , Tranzitie* p2 = NULL);
    char* get_stare();
    void set_stare(char*);
    Tranzitie* Parcurgere();
    char* DetermineNextState(char c);
    void Afisare();
};

Tranzitie::Tranzitie(char* p, char c, Tranzitie* p2) {
    stare = new char [ strlen(p) + 1 ];
    strcpy( stare , p );
    caracter = c;
    next = p2;
}

Tranzitie::~Tranzitie() { delete stare; delete next; }

Tranzitie* Tranzitie::get_next() { return next; }

void Tranzitie::set_next(char* p, char c, Tranzitie* p2) { next = new Tranzitie(p , c , p2); }

char* Tranzitie::get_stare() { return stare; }

void Tranzitie::set_stare(char* p) {  delete stare; stare = new char [ strlen(p) + 1 ]; strcpy(stare , p); }

Tranzitie* Tranzitie::Parcurgere() {
    if ( next == NULL ) return this;
    else    return next->Parcurgere();
}

char* Tranzitie::DetermineNextState(char c) {
    if(caracter == c)   return stare;
    else
        if(next == NULL)    return "";
        else    return next->DetermineNextState(c);
}

void Tranzitie::Afisare() {
    if( caracter == '0' )
        cout << stare << "->";
    else
        cout << stare << " , " << caracter << " -> ";
    if(next != NULL) next->Afisare();
        else cout << "-|";
}

int main()
{
    /**Declaratii si deschidere fisier*/
    int n , m , i = 0 , retin_i , j;
    char *sir , *stare_initiala = new char [25] , *s = new char [25] , *p;
    Tranzitie* creator;
    ifstream fin ("Mereu.in");
    if( !fin ) { cout << "Eroare la deschiderea fisierului" << endl; }

    /**Citire si memorare stari*/
    fin >> n;
    Tranzitie v[n];
    sir = new char [n * 25];
    fin.get();
    fin.get(sir , n * 25);
    //cout << n << endl << sir << endl;
    p = strtok(sir , ",;{}()\n");
    while(p) {
        v[i++].set_stare(p);
        p = strtok(NULL , ",;{})()\n");
    }

    /**Citire alfabet*/
    delete sir;
    fin >> m;
    sir = new char [m * 25];
    fin.get();
    fin.get(sir , m * 25);
    //cout << m << endl << sir << endl;

    /**Citire stare initiala*/
    fin.get();
    fin.get(stare_initiala , 25);

    /**Citire si memorare stari finale*/
    delete sir;
    fin >> m;
    sir = new char [m * 25];
    char* stari_finale[m];
    fin.get();
    fin.get(sir , m * 25);
    //cout << m << endl << sir << endl;
    i = 0;
    p = strtok(sir , ",;{}()\n");
    while(p) {
        stari_finale[i] = new char [25];
        strcpy(stari_finale[i++] , p);
        p = strtok(NULL , ",;{}()\n");
    }
    //for(i = 0 ; i < m ; i ++)
       //cout << stari_finale[i] << endl;

    /**Citire si memorare Tranzitii*/
    delete sir;
    sir = new char [100];
    fin.get();
    while(fin.get(sir , 100)) {
            //cout << sir << endl;
        p = strtok(sir , ",;{}()\n");
        for(i = 0 ; i < n ; i ++) {
            if( !strcmp( v[i].get_stare() , p ) ) break;
        }
        p = strtok(NULL , ",;{}()\n");
        strcpy(s , p);
        p = strtok(NULL , ",;{}()\n");
        //cout << s << endl << p <<endl;
        creator = v[i].Parcurgere();
        creator -> set_next(s , p[0]);
        fin.get();
    }
        delete s;

    for(i = 0 ; i < n ; i ++) {
        v[i].Afisare();
        cout << endl;
    }

    /**Determinarea apartenentei cuvantului dat la limbaj*/
    delete sir;
    sir = new char [100];
    int Stop;
    bool Acceptat;
    char *stare_actuala = new char [25] , *temp = new char [25];
    cout << "Se da cuvantul: ";
    cin.get(sir , 100);
    while( strcmp(sir , "OUT") ){
        strcpy(stare_actuala , stare_initiala);
        Stop = 0;
        Acceptat = false;
        for(i = 0 ; i < strlen(sir) && Stop == 0 ; i ++) {
            for(j = 0 ; j < n ; j ++) {
                if( !strcmp(v[j].get_stare() , stare_actuala) ) break;
            }
            temp = v[j].DetermineNextState(sir[i]);
            if( !strcmp(temp , "") )    Stop = 1;
            else {
                strcpy(stare_actuala , temp);
            }
        }
        if(Stop == 1)   cout << "Cuvantul nu este in limbaj" << endl;
        else {
            for(i = 0 ; i < m ; i ++) {
                if( !strcmp(stari_finale[i] , stare_actuala) )  Acceptat = true;
            }
            if( Acceptat == true)   cout << "Cuvantul apartine limbajului" << endl;
            else    cout << "Cuvantul nu este in limbaj" << endl;
        }
        cout << "Se da cuvantul: ";
        cin.get();
        cin.get(sir , 100);
    }
    return 0;
}
