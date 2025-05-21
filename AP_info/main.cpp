#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include "inserimento.h"

using namespace std;

//Prototipi
bool findName (vector<studente>  &studenti , long int matricola );

map<corso,map<materia,vector<studente>>> universita;

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
//punto 1

string matricolaPerCorso(long int matricola){
    string toReturn;

    for(auto corsoMateriaStudente : universita){
        for (auto corsoStudente : corsoMateriaStudente.second){
            for(auto studenti : corsoStudente.second){
                if (studenti.matr == matricola){
                    toReturn = studenti.cod_corso;
                    break;
                }
            }
        }
    }

    for(auto corsoMateriaStudente : universita){
        if (corsoMateriaStudente.first.cod_corso == toReturn){
            toReturn = corsoMateriaStudente.first.descr_corso;
            break;
        }
    }

    return toReturn;
}
//punto 2
/*string cognomePerCorso(string cogn_utente){

    string codice;
    for(auto x : info){
        for(auto t : x.second){
            if(t.cogn == cogn_utente){
                codice = x.first;
                break;
            }
        }
    }
    for(auto x : infoCors){
        for(auto t : x.second){
            if(codice == x.first) return t.descr_corso;
        }
    }
}*/

//punto 2
string cognomePerCorso(string cogn_utente){
    string toReturn;

    for(auto corsoMateriaStudente : universita){
        for(auto materiaStudente : corsoMateriaStudente.second){
            for(auto studenti : materiaStudente.second){
                if(cogn_utente == studenti.cogn)    toReturn = studenti.cod_corso;
            }
        }
    }

    for(auto corsoMateriaStudente : universita){
        if(corsoMateriaStudente.first.cod_corso == toReturn)    toReturn = corsoMateriaStudente.first.descr_corso;
    }

    return toReturn;

}


//punto 3
vector<studente> studentiPerCorso(map<corso,map<materia,vector<studente>>> &universita, string codiceCorso){
    vector<studente> toReturn;

    for(auto corsoMateriaStudente : universita){
        for (auto corsoStudente : corsoMateriaStudente.second){
            for(auto studente : corsoStudente.second){
                if (studente.cod_corso == codiceCorso and !findName(toReturn, studente.matr)){
                    toReturn.push_back(studente);
                }
            }
        }
    }

    return toReturn;
}
//per evitare duplicati
bool findName (vector<studente>  &studenti , long int matricola ){
    for(auto studente : studenti){
        if (studente.matr == matricola) return true;
    }
    return false;
}

int main()
{
    //dichiarazione variabili;
    char scelta;
    string labels;

    //punto 1
    long int mat_utente;

    //punto 2
    string cogn_utente;

    //punto 3
    map<string,map<long int,vector<studente>>> studentePerCorso;
    string cod;


    menu();
    cout<<"Fai la tua scelta: ";
    cin>>scelta;

    while(toupper(scelta) != 'X'){

        switch(scelta){

            case '0':

                inserimento(labels,universita);

                break;

            case '1':{
                cout<<"Inserisci una matricola : ";
                cin>>mat_utente;

                cout<<mat_utente<<"  :  "<< matricolaPerCorso(mat_utente)<<endl;

                break;
            }

            case '2':

                cout<<"Inserisci un cognome : ";
                cin>>cogn_utente;

                //cout<<cogn_utente<<" : "<<cognomePerCorso(cogn_utente)<<endl;

                cout<<cogn_utente<<" : "<<cognomePerCorso(cogn_utente)<<endl;

                break;


            case '3':
                cout<<"Inserisci il codice di un corso: ";
                cin>>cod;

                //costruisciMappa(studentePerCorso);
                for(auto studente : studentiPerCorso(universita,cod)){
                    cout<<studente.matr<<endl;
                }


                break;






        }

        menu();
        cin>>scelta;

    }

}
