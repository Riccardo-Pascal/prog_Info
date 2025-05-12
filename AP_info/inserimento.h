#ifndef INSERIMENTO_H_INCLUDED
#define INSERIMENTO_H_INCLUDED
#include "strutture.h"
#include <fstream>
#include <string>

using namespace std;


void inserimento(string labels,vector <studente> &info,vector <materia> &infoMat,vector <corso> &infoCors){

    ifstream fin("corsi_studenti.csv",ios::in);
    //input labels
    getline(fin,labels);
    while(!fin.eof()){
        string codC,descrC,codM,descrM,mat,cognS,nomeS;
        int matS;
        //input codice_corso
        getline(fin,codC,',');
        if (codC == "") break;
        //descrizione_corso
        getline(fin,descrC,',');
        //codice_materia
        getline(fin,codM,',');
        //descrizione_materia
        getline(fin,descrM,',');
        //matricola_studente
        getline(fin,mat,',');
        matS = stoi(mat);
        //cognome_studente
        getline(fin,cognS,',');
        //nome_studente
        getline(fin,nomeS);

        //popolo vector info
        studente p{matS,cognS,nomeS,codC};
        info.push_back(p);

        //popolo vector infoMat
        materia s{codM,descrM,codC};
        infoMat.push_back(s);

        //popolo vector infoCorso
        corso c{codC,descrC};
        infoCors.push_back(c);

    }
    fin.close();
}
#endif // INSERIMENTO_H_INCLUDED
