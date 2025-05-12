#ifndef STRUTTURE_H_INCLUDED
#define STRUTTURE_H_INCLUDED
#include <string>

using namespace std;

struct studente{
    int matr;
    string cogn;
    string nome;
    string cod_corso;


};
struct materia{

    string cod_materia;
    string descr_materia;
    string cod_corso;
};

struct corso{

    string cod_corso;
    string descr_corso;

};

#endif // STRUTTURE_H_INCLUDED
