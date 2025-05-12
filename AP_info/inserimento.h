#ifndef INSERIMENTO_H_INCLUDED
#define INSERIMENTO_H_INCLUDED
#include <string>


void ins(string codC,string descrC,string codM,string descrM,string mat,string cognS,string nomeS,string labels){
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
}
#endif // INSERIMENTO_H_INCLUDED
