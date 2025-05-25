#ifndef INSERIMENTO_H_INCLUDED
#define INSERIMENTO_H_INCLUDED
#include "strutture.h"
#include <fstream>
#include <string>
#include <map>

using namespace std;

void inserimento(string &labels,map<corso,map<materia,vector<studente>>> &universita){
    ifstream fin("corsi_studenti.csv",ios::in);
    //input labels
    getline(fin,labels);
    string codC,descrC,codM,descrM,mat,cognS,nomeS;
    int matS;
    while(getline(fin,codC,',')){

        //input codice_corso
        if (codC == "") break;
        //descrizione_corso
        getline(fin,descrC,',');
        corso c{codC,descrC};

        //codice_materia
        getline(fin,codM,',');
        //descrizione_materia
        getline(fin,descrM,',');
        materia s{codM,descrM,codC};

        //matricola_studente
        getline(fin,mat,',');
        matS = stoi(mat);
        //cognome_studente
        getline(fin,cognS,',');
        //nome_studente
        getline(fin,nomeS);
        studente p{matS,cognS,nomeS,codC};

        universita[c][s].push_back(p);

    }
    fin.close();
}



#endif // INSERIMENTO_H_INCLUDED
