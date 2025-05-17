#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include "inserimento.h"

using namespace std;

void menu(){

    cout<<"====== GESTIONE UNIVERSITARIA ======"<<endl;
    cout<<"0. Carica dati da file"<<endl;
    cout<<"1. Cerca corsi di uno studente (matricola)"<<endl;
    cout<<"2. Cerca corsi di uno studente (cognome)"<<endl;
    cout<<"3. Elenca studenti iscritti ad un corso"<<endl;
    cout<<"4. Stampa dati esami di un corso"<<endl;
    cout<<"5. Numero di studenti per corso"<<endl;
    cout<<"6. Numero di materie per corso"<<endl;
    cout<<"7. Cerca materie per descrizione"<<endl;
    cout<<"8. Inserisci nuovo studente"<<endl;
    cout<<"9. Salva i dati su file"<<endl;
    cout<<"X. Esci"<<endl;

}

void mappaCorsi(map<long int,string> &corsiPerMatricola,vector <studente> info,vector <corso> infoCors){

    for(int i = 0;i<info.size();i++){

        corsiPerMatricola[info[i].matr] = infoCors[i].descr_corso;
    }
}


int main()
{
    //dichiarazione variabili;
    char scelta;
    string labels;

    vector <studente> info;
    vector <materia> infoMat;
    vector <corso> infoCors;

    //punto 1
    map<long int,string> corsiPerMatricola;


    menu();
    cout<<"Fai la tua scelta: ";
    cin>>scelta;

    while(toupper(scelta) != 'X'){

        switch(scelta){

            case '0':

                inserimento(labels,info,infoMat,infoCors);

                break;

            case '1':
                mappaCorsi(corsiPerMatricola,info,infoCors);

                for(auto x :  corsiPerMatricola){

                    cout<<x.first<<"  :  "<<x.second<<endl;
                }
                break;



        }

        menu();
        cin>>scelta;

    }

}
