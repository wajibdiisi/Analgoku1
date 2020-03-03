/*
Nama : Ahmad Irfan Fadholi
NPM  : 14081080034 
Kelas : B*/

#include <iostream>
using namespace std;

#define Array 5 
string male_name[Array] = {"Victor","Wyatt","Xavier","Yancey","Zeus"};
string female_name[Array] = {"Amy","Bertha","Clare","Diane","Erika"};

int male_preferences[Array][Array] = { {1, 0, 3, 4, 2},{3, 1, 0, 2, 4},{1, 4, 2, 3, 0}, {0, 3, 2, 1, 4}, {1, 3, 0, 4, 2}};//berdasarkan urutan array pada string female_name
int female_preferences[Array][Array] = { {4, 0, 1, 3, 2},{2, 1, 3, 0, 4},{1, 2, 3, 4, 0},{0, 4, 3, 2, 1},{3, 1, 4, 2, 0}}; //berdasarkan urutan array pada string male_name
int stableMatch[Array][2];
bool male_match[Array];
bool female_match[Array];

int getmaleMatch(int female){
    for (int i=0; i<Array; i++){
        if (stableMatch[i][1]==female){
            return stableMatch[i][0]; 
            break;
        }
    }
    return -1;
}

int getPreferences(int female, int male){
    for (int i=0; i<Array; i++){
        if (female_preferences[female][i]==male){
            return i;
            break;
        }
    }
    return -1;
}

void matching(int m, int w){
    stableMatch[m][0] = m;
    stableMatch[m][1] = w;
    male_match[m] = true;
    female_match[w] = true;
}

void hasilMatching(){
    cout <<"Hasil Matching\n";
    for (int i=0;i<Array;i++){
        cout <<"("<<male_name[stableMatch[i][0]]<<" dengan "<<female_name[stableMatch[i][1]]<< ")\n";
    }
}

int main(){
    for (int i=0;i<Array;i++){
        for (int j=0;j<Array;j++){
            int m = j;
            if (male_match[m]==false) {
                int w = male_preferences[m][i];
                if (female_match[w]==true){
                    int freeM = getmaleMatch(w);
                    int freeM_pref = getPreferences(w,freeM);
                    int M_pref = getPreferences(w,m);
                    if (M_pref<freeM_pref){
                        matching(m,w);
                        male_match[freeM] = false;
                        stableMatch[freeM][1] = -1;
                        continue;
                    } else {
                        continue;
                    }
                } else {
                    matching(m,w);
                    continue;
                }
            } else {
                continue;
            }
        }
    }
    hasilMatching();
}
