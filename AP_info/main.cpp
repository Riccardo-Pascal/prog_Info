#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include "inserimento.h"

using namespace std;

map<corso,map<materia,vector<studente>>> universita;

//controllo per evitare duplicati
bool findName (vector<studente>  &studenti , long int matricola ){
    for(auto studente : studenti){
        if (studente.matr == matricola) return true;
    }
    return false;
}

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
    string cod;

    for(auto corsoMateriaStudente : universita){
        for (auto corsoStudente : corsoMateriaStudente.second){
            for(auto studenti : corsoStudente.second){
                if (studenti.matr == matricola){
                    cod = studenti.cod_corso;
                    break;
                }
            }
        }
    }

    for(auto corsoMateriaStudente : universita){
        if (corsoMateriaStudente.first.cod_corso == cod){
            cod = corsoMateriaStudente.first.descr_corso;
            break;
        }
    }

    return cod;
}

//punto 2
string cognomePerCorso(string cogn_utente){
    string cod;

    for(auto corsoMateriaStudente : universita){
        for(auto materiaStudente : corsoMateriaStudente.second){
            for(auto studenti : materiaStudente.second){
                if(cogn_utente == studenti.cogn)    cod = studenti.cod_corso;
            }
        }
    }

    for(auto corsoMateriaStudente : universita){
        if(corsoMateriaStudente.first.cod_corso == cod)    cod = corsoMateriaStudente.first.descr_corso;
    }

    return cod;

}

//punto 3
vector<studente> studentiPerCorso(string codiceCorso){
    vector<studente> stud;

    for(auto corsoMateriaStudente : universita){
        for (auto corsoStudente : corsoMateriaStudente.second){
            for(auto studenti : corsoStudente.second){
                if (studenti.cod_corso == codiceCorso and !findName(stud, studenti.matr)){
                    stud.push_back(studenti);
                }
            }
        }
    }

    return stud;
}

//punto 4
map<vector<materia>,vector<studente>> esamiPerCorso(string codiceCorso,map<vector<materia>,vector<studente>> &esamiStudente){

    for(auto corsoMateriaStudente : universita){
        if(corsoMateriaStudente.first.cod_corso == codiceCorso){
            for(auto materiaStudente : corsoMateriaStudente.second){
                vector<materia> mat {materiaStudente.first};

                for(auto studenti : materiaStudente.second){
                    esamiStudente[mat].push_back(studenti);
                }
            }
        }
    }

    return esamiStudente;
}
//punto 5


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
    string cod;

    //punto 4
    map<vector<materia>,vector<studente>> esamiStudente;

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

                cout<<cogn_utente<<" : "<<cognomePerCorso(cogn_utente)<<endl;

                break;

            case '3':
                cout<<"Inserisci il codice di un corso: ";
                cin>>cod;

                for(auto studenti : studentiPerCorso(cod)){
                    cout<<cod<<" : "<<studenti.cogn<<","<<studenti.nome<<","<<studenti.matr<<endl;
                }

                break;

            case '4':
                cout<<"Inserisci il codice di un corso: ";
                cin>>cod;

                for (auto studenti : esamiPerCorso(cod, esamiStudente)) {
                    for (auto z : studenti.first) {
                        for (auto x : studenti.second)  {
                            cout << cod << " : "
                                 << z.cod_materia << ","
                                 << z.descr_materia << ","
                                 << x.cogn << ","
                                 << x.nome << ","
                                 << x.matr << endl;
                        }
                    }
                }
                break;





        }
        menu();
        cin>>scelta;

    }

}
