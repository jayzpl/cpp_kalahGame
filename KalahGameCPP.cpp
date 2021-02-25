//Made BY J.Z. 30.11.2020
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int Plansza[14];
char Kursor[14];
int kursorx = 7; //kursor gracza na poczatku

bool czyKoniec() {
    if (Plansza[0]==0 && Plansza[1] == 0 && Plansza[2] == 0 && Plansza[3] == 0 && Plansza[4] == 0 && Plansza[5] == 0) {
        return true;
    }
    else if (Plansza[7] == 0 && Plansza[8] == 0 && Plansza[9] == 0 && Plansza[10] == 0 && Plansza[11] == 0 && Plansza[12] == 0) {
        return true;
    }
    else{
        return false;
    }
}

void uzupelnijPlansze() {
    for (int i = 0; i < 14; i++) {
        if (i==6 || i==13) {
            Plansza[i] = 0;
        }
        else {
            Plansza[i] = 6; //ile kamieni w polach
        }
    }
}
void wypisz() {
    system("CLS");
    cout << "---------------------------------" << endl;
    cout << "|   | " << Plansza[0] << " | " << Plansza[1] << " | " << Plansza[2] << " | " << Plansza[3] << " | " << Plansza[4] << " | " << Plansza[5] << " |   |" << endl;
    cout << "      " << Kursor[0] << "   " << Kursor[1] << "   " << Kursor[2] << "   " << Kursor[3] << "   " << Kursor[4] << "   " << Kursor[5] << "   " << endl;
    cout << "| " << Plansza[6] << " |                       | " << Plansza[13] << " |" << endl;
    cout << "  " << Kursor[6] << "                           " << Kursor[13] << "  " << endl;
    cout << "|   | " << Plansza[7] << " | " << Plansza[8] << " | " << Plansza[9] << " | " << Plansza[10] << " | " << Plansza[11] << " | " << Plansza[12] << " |   |" << endl;
    cout << "      " << Kursor[7] << "   " << Kursor[8] << "   " << Kursor[9] << "   " << Kursor[10] << "   " << Kursor[11] << "   " << Kursor[12] << "   " << endl;
    cout << "---------------------------------" << endl;
    cout << kursorx << endl;
}
void turaBota() {
    int botkursor, punkty;
    bool CzyNext = false;
    while (true) {
        botkursor = rand() % 6;
        if (Plansza[botkursor] == 0) {
            continue;
        }
        else {
            punkty = Plansza[botkursor];
            Plansza[botkursor] = 0;
            int wskaznik = botkursor;
            while (punkty != 0) {
                if (wskaznik == 0) {
                    Plansza[6]++;
                    punkty--;
                    wskaznik = 7;
                    while (punkty != 0) {
                        if (wskaznik == 0 || wskaznik == 13) {
                            break;
                        }
                        Plansza[wskaznik] = Plansza[wskaznik] + 1;
                        wskaznik++;
                        punkty--;
                    }
                }
                else if (wskaznik == 13) {
                    Plansza[13]++;
                    punkty--;
                    wskaznik = 5;
                    while (punkty != 0) {
                        if (wskaznik == 0 || wskaznik == 13) {
                            break;
                        }
                        Plansza[wskaznik] = Plansza[wskaznik] + 1;
                        wskaznik--;
                        punkty--;
                    }
                }
                else if (punkty==1 && (wskaznik-1)==-1) {
                    wskaznik = 6;
                    Plansza[wskaznik] = Plansza[wskaznik] + 1;
                    punkty--;
                    CzyNext = true;
                }
                else if (punkty == 1 && Plansza[wskaznik - 1] == 0 && (wskaznik - 1) != -1) {
                    int roznica;
                    wskaznik--;
                    Plansza[wskaznik] = Plansza[wskaznik] + 1;
                    punkty--;
                    roznica = wskaznik + 7;
                    Plansza[6] = Plansza[6] + Plansza[roznica];
                    Plansza[roznica] = 0;
                }
                else {
                    wskaznik--;
                    Plansza[wskaznik] = Plansza[wskaznik] + 1;
                    punkty--;
                }
            }
            if(!CzyNext){
                break;
            }    
        }
    }
    wypisz();
}

void ruch() {
    char znak;
    bool CzyNext=false;
    cout << "=> ";
    cin >> znak;
    switch (znak){
    case 'a':
        if (kursorx>0) {
            Kursor[kursorx] = ' ';
            kursorx--;
            Kursor[kursorx] = '_';
            wypisz();
        }
        break;
        
    case 'd':
        if (kursorx<13) {
            Kursor[kursorx] = ' ';
            kursorx++;
            Kursor[kursorx] = '_';
            wypisz();  
        }
        break;

    case 'f':
        if (kursorx==7 || kursorx==8 || kursorx == 9 || kursorx == 10 || kursorx == 11 || kursorx == 12) {
            int punkty = Plansza[kursorx];
            Plansza[kursorx] = 0;
            int wskaznik = kursorx;
            while (punkty!=0) {
                if (wskaznik==13) {
                        wskaznik = 5;
                        while (punkty != 0) {
                            if (wskaznik == 0 || wskaznik == 13) {
                                break;
                            }
                            Plansza[wskaznik] = Plansza[wskaznik] + 1;
                            punkty--;
                            wskaznik--;
                    }
                }
                else if (wskaznik == 0) {
                    Plansza[6]++;
                    punkty--;
                    wskaznik = 7;
                    while (punkty != 0) {
                        if (wskaznik == 0 || wskaznik == 13) {
                            break;
                        }
                        Plansza[wskaznik] = Plansza[wskaznik] + 1;
                        punkty--;
                        wskaznik++;
                    }
                }
                else if (punkty==1 && (wskaznik+1)==13) { //jak punkt 1 i w kolejnym rozdysponowaniu bedzie baza to rob to
                    wskaznik++;
                    Plansza[wskaznik] = Plansza[wskaznik] + 1;
                    punkty--;
                    CzyNext = true;
                }
                else if (punkty==1 && Plansza[wskaznik+1]==0 && (wskaznik+1)!=13) {
                    int roznica;
                    wskaznik++;
                    Plansza[wskaznik] = Plansza[wskaznik] + 1;
                    punkty--;
                    roznica = wskaznik - 7;
                    Plansza[13] = Plansza[13] + Plansza[roznica];
                    Plansza[roznica] = 0;
                }
                else {
                    wskaznik++;
                    Plansza[wskaznik] = Plansza[wskaznik] + 1;
                    punkty--;
                }
            }
            wypisz();
            if (!CzyNext) {
                turaBota();
            }
        }
        else {
            cout << "Dont touch that\n";
        }
        break;
    }
}


int main(){
    srand(time(NULL));
    bool gra = true;
    uzupelnijPlansze();
    cout << "Dobre plejsy here\n";
    Kursor[kursorx] = '_';
    wypisz();

    while (gra) {
        if (czyKoniec()) {
            int pozostaleBot = 0;
            int pozostaleGracz = 0;
            for (int i = 0; i < 6; i++) {
                pozostaleBot = Plansza[i] + pozostaleBot;
                Plansza[i] = 0;
            }
            for (int j = 7; j < 14; j++) {
                pozostaleGracz = Plansza[j] + pozostaleGracz;
                Plansza[j] = 0;
            }
            Plansza[6] = Plansza[6] + pozostaleBot;
            Plansza[13] = Plansza[13] + pozostaleGracz;
            gra = false;
            
        }
        else {
            ruch();
        }
    }
    wypisz();
    cout << "Pkt BOT: " << Plansza[6] << endl;
    cout << "Pkt GRACZ: " << Plansza[13] << endl;
}

