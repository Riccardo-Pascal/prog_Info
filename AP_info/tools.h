#ifndef TOOLS_H_INCLUDED
#define TOOLS_H_INCLUDED
#include <string>
#include <vector>
#include <map>
#include "strutture.h"

map<corso,map<materia,vector<studente>>> universita;

bool operator<(const materia& a, const materia& b) {
    return a.cod_materia < b.cod_materia;
}
bool operator<(const corso& a, const corso& b) {
    return a.cod_corso < b.cod_corso;
}

//controllo per evitare duplicati
bool findName (vector<studente>  &studenti , long int matricola ){
    for(auto studente : studenti){
        if (studente.matr == matricola) return true;
    }
    return false;
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
vector<studente> matricolaCorso(string codiceCorso){
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
int contaStudentiPerCorso (string codiceCorso,set<long int> &matPerStudenti){
    for(auto corsoMateriaStudente : universita){
        for(auto materiaStudente : corsoMateriaStudente.second){
            for(auto studenti : materiaStudente.second){
                if(codiceCorso == studenti.cod_corso){
                    matPerStudenti.insert(studenti.matr);
                }
            }
        }
    }



    return matPerStudenti.size();
}

//punto 6
int materiePerCorso(string codiceCorso){

    for(auto corsoMateriaStudente : universita){
            return corsoMateriaStudente.second.size();
    }
}

//punto 7
map<string,string> descrPerMateria(string descr,map<string,string> &descrMateria){

    transform(descr.begin(),descr.end(),descr.begin(),::tolower);

    for(auto corsoMateriaStudente : universita){
        for(auto materiaStudente : corsoMateriaStudente.second){
            //converto la parola in minuscolo
            string materia = materiaStudente.first.descr_materia;
            transform(materia.begin(),materia.end(),materia.begin(),::tolower);

            if(materia.find(descr) != string::npos){

                descrMateria[materiaStudente.first.descr_materia] = materiaStudente.first.cod_materia;
            }
        }
    }
    return descrMateria;
}

//punto 8
void inserimentoConMateria(long int matr,string cogn,string nome,string materia){
    for(auto &corsoMateriaStudente : universita){
        for(auto& materiaStudente : corsoMateriaStudente.second){
            if(materiaStudente.first.cod_materia == materia){
                studente ins{matr,cogn,nome,corsoMateriaStudente.first.cod_corso};

                materiaStudente.second.push_back(ins);

            }
        }
    }
}

#endif // TOOLS_H_INCLUDED
