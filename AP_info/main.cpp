#include <iostream>
#include <list>
#include <fstream>

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

struct studente{

    string cod_corso;
    string descr_cor;
    string cod_mat;
    string descr_mat;
    int matStud;
    string cogn;
    string nome;

};
int main()
{
    //dichiarazione variabili;
    char scelta;
    string labels;

    list <studente> info;


    menu();
    cout<<"Fai la tua scelta: ";
    cin>>scelta;

    while(toupper(scelta) != 'X'){

        switch(scelta){

            case '0':

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

                    studente p{codC,descrC,codM,descrM,matS,cognS,nomeS};

                    info.push_back(p);

                }

                fin.close();

                for(auto x : info){
                    cout<<x.cod_corso<<endl;

                }



        }


    }

}
