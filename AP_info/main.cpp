#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <map>
#include <set>
#include "inserimento.h"
#include "tools.h"

using namespace std;

void menu(){
    cout<<"============ GESTIONE UNIVERSITARIA ============"<<endl;
    cout<<"0. Carica dati da file                         ="<<endl;
    cout<<"1. Cerca corsi di uno studente (matricola)     ="<<endl;
    cout<<"2. Cerca corsi di uno studente (cognome)       ="<<endl;
    cout<<"3. Elenca studenti iscritti ad un corso        ="<<endl;
    cout<<"4. Stampa dati esami di un corso               ="<<endl;
    cout<<"5. Numero di studenti per corso                ="<<endl;
    cout<<"6. Numero di materie per corso                 ="<<endl;
    cout<<"7. Cerca materie per descrizione               ="<<endl;
    cout<<"8. Inserisci nuovo studente                    ="<<endl;
    cout<<"9. Salva i dati su file                        ="<<endl;
    cout<<"X. Esci                                        ="<<endl;
    cout<<"================================================"<<endl;
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
    string cod;

    //punto 4
    map<vector<materia>,vector<studente>> esamiStudente;

    //punto 5
    set<long int> matPerStudenti;

    //punto 6
    map<string,map<long int,studente>> studenteCorso;

    //punto 7
    string descr;
    map<string,string> descrMateria;

    //punto 8
    string materia,nome,cogn;
    long int matr;

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

                for(auto studenti : matricolaCorso(cod)){
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
                esamiStudente.clear();

                break;

            case '5':
                cout<<"Inserisci il codice di un corso: ";
                cin>>cod;
                cout<<cod<<" : ";

                cout<<contaStudentiPerCorso(cod,matPerStudenti)<<endl;

                break;

            case '6':
                cout<<"Inserisci il codice di un corso: ";
                cin>>cod;

                cout<<cod<<" : "<<materiePerCorso(cod)<<" materie"<<endl;


                break;



            case '7':
                cout<<"Inserire la descrizione della materia : ";
                cin>>descr;

                for(auto materia : descrPerMateria(descr,descrMateria)){
                    cout<<materia.second<<" - "<<materia.first<<endl;
                }
                descrMateria.clear();

                break;

            case '8':

                cout<<"Inserisci il codice della materia che frequenti: ";
                cin>>materia;
                cout<<"Inserisci il nome :  ";
                cin>>nome;
                cout<<"Inserisci il cognome :  ";
                cin>>cogn;
                cout<<"Inserisci la matricola :  ";
                cin>>matr;

                inserimentoConMateria(matr,cogn,nome,materia);

                break;

            case '9':

                ofstream fout("corsi_studenti.csv");

                fout<<labels<<endl;
                for(auto corsoMateriaStudente : universita){
                    for(auto materiaStudente : corsoMateriaStudente.second){
                        for(auto studenti : materiaStudente.second){
                            fout<<corsoMateriaStudente.first.cod_corso<<","<<corsoMateriaStudente.first.descr_corso<<","
                            <<materiaStudente.first.cod_materia<<","<<materiaStudente.first.descr_materia<<","<<studenti.matr
                            <<","<<studenti.cogn<<","<<studenti.nome<<endl;
                        }
                    }
                }

                break;

                fout.close();


        }
        menu();
        cout<<"Fai la tua scelta: ";
        cin>>scelta;


    }

}
