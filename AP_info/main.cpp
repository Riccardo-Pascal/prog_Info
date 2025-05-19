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

void studentiScrittiCorso(map <string,vector<string>> &corsoStudenti,vector <studente> info,vector <corso> infoCors,string cod){

    for(auto x : infoCors){
        if(x.cod_corso == cod){

            for(auto t : info){

                corsoStudenti[x.descr_corso].push_back(t.cogn);
            }
            break;
        }
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
    long int mat_utente;

    //punto 2
    string cogn_utente;

    //punto 3
    map <string,vector<string>> corsoStudenti;
    string cod;


    menu();
    cout<<"Fai la tua scelta: ";
    cin>>scelta;

    while(toupper(scelta) != 'X'){

        switch(scelta){

            case '0':

                inserimento(labels,info,infoMat,infoCors);

                break;

            case '1':{
                cout<<"Inserisci una matricola : ";
                cin>>mat_utente;
                string codice;

                for(auto x : info){
                    if(x.matr == mat_utente){
                        codice = x.cod_corso;
                    }
                }

                for(auto x : infoCors){
                    if(codice == x.cod_corso){
                        cout<<mat_utente<<"  :  "<<x.descr_corso<<endl;
                    }
                    break;
                }
                break;
            }

            case '2':{

                cout<<"Inserisci un cognome : ";
                cin>>cogn_utente;
                string c;

                for(auto x : info){
                    if(x.cogn == cogn_utente){
                        c = x.cod_corso;
                    }
                    break;
                }

                for(auto x : infoCors){
                    if(c == x.cod_corso){
                        cout<<cogn_utente<<"  :  "<<x.descr_corso<<endl;
                    }
                    break;
                }
                break;
            }

            case '3':
                cout<<"Inserisci il codice di un corso: ";
                cin>>cod;



                studentiScrittiCorso(corsoStudenti,info,infoCors,cod);

                for(auto x : corsoStudenti){

                    for(auto t : x.second){

                        cout<<x.first<<"  :  "<<t<<endl;

                    }
                }
                break;


        }

        menu();
        cin>>scelta;

    }

}
