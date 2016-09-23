//Cory Hutson
//ceh0050@auburn.edu
//vim, g++, linux
//Complie: g++ -o HW4 hw4.cpp
//sample usage: ./HW4
//

#include <iostream>
#include <stdlib.h>
#include <assert.h>
#include <ctime>

using namespace std;

bool twoAlive(bool aAlive, bool bAlive, bool cAlive);

void test_twoAlive(void);
void test_aShoots();
void test_aIntentionalMiss();
void test_bShoots();
void test_cShoots();


void duelStrat1();
void duelStrat2();

const double aProb = 1.0/3.0;
const double bProb = 0.5;
const double cProb = 1;

const double duels = 10000;

bool aAlive = true;
bool bAlive = true;
bool cAlive = true;

int aWins1 = 0;
int aWins2 = 0;
int bWins = 0;
int cWins = 0;

bool hit = false;

int currentRand = 0;


int main()
{
    srand(time(NULL));
    
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    
    cout << "****** Welcome to Cory Hutsons' Duel Simulator ******\n";
    
    cout << "Unit Test 1: Function - twoAlive(aAlive, bAlive, cAlive)\n";
    test_twoAlive();
    
    cout << "Press any key to continue...";
    cin.ignore().get();
    
    cout << "Unit Test 2: Function - aShoots(bAlive, cAlive)\n";
    test_aShoots();
    
    cout << "Press any key to continue...";
    cin.ignore().get();
    
    cout << "Unit Test 3: Function - aIntentionalMiss(bAlive, cAlive)\n";
    test_aIntentionalMiss();
    
    cout << "Press any key to continue...";
    cin.ignore().get();  
    cout << "Unit Test 4: Function - bShoots(aAlive, cAlive)\n";
    test_bShoots();
    
    cout << "Press any key to continue...";
    cin.ignore().get();
    
    cout << "Unit Test 5: Function - cShoots(aAlive, bAlive)\n";
    test_cShoots();
    
    cout << "Press any key to continue...";
    cin.ignore().get();
    
    cout << "Ready to test strategy 1 (run 1000 times)\n";
    
    cout << "Press any key to continue...";
    cin.ignore().get();
    
    int count = 1;
    
    while (count <= duels) {
        cout << "Duel " << count << "\n";
        duelStrat1();
        aAlive = true;
        bAlive = true;
        cAlive = true;
        count++;
    }
    
    cout << "Aaron won " << aWins1 << " duels, or " << (aWins1/duels)*100 << "%\n";
    cout << "Bob won " << bWins << " duels, or " << (bWins/duels)*100 << "%\n";
    cout << "Charlie won " << cWins << " duels, or " << (cWins/duels)*100 << "%\n";
    
    cout << "Ready to test strategy 2 (run 1000 times)\n";
    
    cout << "Press any key to continue...";
    cin.ignore().get();
    
    count = 1;
    bWins = 0;
    cWins = 0;
    
    aAlive = true;
    bAlive = true;
    cAlive = true;
    
    
    while (count <= duels) {
        cout << "Duel " << count << "\n";
        duelStrat2();
        aAlive = true;
        bAlive = true;
        cAlive = true;
        count++;
    }
    
    cout << "Aaron won " << aWins2 << " duels, or " << (aWins2/duels)*100 << "%\n";
    cout << "Bob won " << bWins << " duels, or " << (bWins/duels)*100 << "%\n";
    cout << "Charlie won " << cWins << " duels, or " << (cWins/duels)*100 << "%\n";
    
    if (aWins2>aWins1) {
        cout << "Strategy 2 is better than Strategy 1.";
    }
    else {
        cout << "Strategy 1 is better than Strategy 2.";
    }
    
}

bool twoAlive (bool aAlive, bool bAlive, bool cAlive){
    int numAlive = 0;
    if (aAlive) {
        numAlive++;
    }
    if (bAlive) {
        numAlive++;
    }
    if (cAlive){
        numAlive++;
    }
    if (numAlive >= 2) {
        return true;
    }
    else {
        return false;
    }
}



void test_twoAlive(void) {
    
    cout << "Case 1: Aaron alive, Bob alive, Charlie alive\n";
    assert(true == twoAlive(true, true, true));
    cout << "Case passed ...\n";
    cout << "Case 2: Aaron dead, Bob alive, Charlie alive\n";
    assert(true == twoAlive(false, true, true));
    cout << "Case passed ...\n";
    cout << "Case 3: Aaron dead, Bob dead, Charlie alive\n";
    assert(false == twoAlive(false, false, true));
    cout << "Case passed ...\n";
    cout << "Case 4: Aaron dead, Bob dead, Charlie dead\n";
    assert(false == twoAlive(false, false, false));
    cout << "Case passed ...\n";
    cout << "Case 5: Aaron alive, Bob alive, Charlie dead\n";
    assert(true == twoAlive(true, true, false));
    cout << "Case passed ...\n";
    cout << "Case 6: Aaron alive, Bob dead, Charlie dead\n";
    assert(false == twoAlive(true, false, false));
    cout << "Case passed ...\n";
    cout << "Case 7: Aaron alive, Bob dead, Charlie alive\n";
    assert(true == twoAlive(true, false, true));
    cout << "Case passed ...\n";
    cout << "Case 8: Aaron dead, Bob alive, Charlie dead\n";
    assert(false == twoAlive(false, true, false));
    cout << "Case passed ...\n";
}

void aShoots (bool& bAlive, bool& cAlive){
    hit = false;
    currentRand = rand()%100;
    if (currentRand < 33) {
        hit = true;
    }
    if (cAlive) {
        if (hit) {
            cAlive = false;
            cout << "Aaron shot Charlie.\n";
        }
        else {
            cout << "Aaron shot at Charlie, but missed.\n";
        }
    }
    else if (bAlive){
        if (hit) {
            bAlive = false;
            cout << "Aaron shot Bob.\n";
        }
        else {
            cout << "Aaron shot at Bob, but missed.\n";
        }
    }
}

void test_aShoots() {
    cout << "Case 1: Bob alive, Charlie alive\n";
    bAlive = true;
    cAlive = true;
    aShoots(bAlive, cAlive);
    cout << "Case passed ...\n";
    
    cout << "Case 2: Bob alive, Charlie dead\n";
    bAlive = true;
    cAlive = false;
    aShoots(bAlive, cAlive);
    cout << "Case passed ...\n";
    
    cout << "Case 3: Bob dead, Charlie alive\n";
    bAlive = false;
    cAlive = true;
    aShoots(bAlive, cAlive);
    cout << "Case passed ...\n";
}

void aIntentionalMiss(bool& bAlive, bool& cAlive) {
    if (bAlive && cAlive) {
        cout << "Aaron misses intentionally.\n";
    }
    else {
        hit = false;
        currentRand = rand()%100;
        if (currentRand < 33) {
            hit = true;
        }
        if (cAlive) {
            if (hit) {
                cAlive = false;
                cout << "Aaron shot Charlie.\n";
            }
            else {
                cout << "Aaron shot at Charlie, but missed.\n";
            }
        }
        else if (bAlive){
            if (hit) {
                bAlive = false;
                cout << "Aaron shot Bob.\n";
            }
            else {
                cout << "Aaron shot at Bob, but missed.\n";
            }
        }
    }
}

void test_aIntentionalMiss() {
    cout << "Case 1: Bob alive, Charlie alive\n";
    bAlive = true;
    cAlive = true;
    aIntentionalMiss(bAlive, cAlive);
    cout << "Case passed ...\n";
    
    cout << "Case 2: Bob alive, Charlie dead\n";
    bAlive = true;
    cAlive = false;
    aIntentionalMiss(bAlive, cAlive);
    cout << "Case passed ...\n";
    
    cout << "Case 3: Bob dead, Charlie alive\n";
    bAlive = false;
    cAlive = true;
    aIntentionalMiss(bAlive, cAlive);
    cout << "Case passed ...\n";
}

void bShoots(bool& aAlive, bool& cAlive){
    hit = false;
    currentRand = rand();
    currentRand = currentRand % 100;
    if (currentRand < 50) {
        hit = true;
    }
    if (cAlive) {
        if (hit) {
            cAlive = false;
            cout << "Bob shot Charlie.\n";
        }
        else {
            cout << "Bob shot at Charlie, but missed.\n";
        }
    }
    else if (aAlive){
        if (hit) {
            aAlive = false;
            cout << "Bob shot Aaron.\n";
        }
        else {
            cout << "Bob shot at Aaron, but missed.\n";
        }
    }
}

void test_bShoots() {
    cout << "Case 1: Aaron alive, Charlie alive\n";
    aAlive = true;
    cAlive = true;
    bShoots(aAlive, cAlive);
    cout << "Case passed ...\n";
    
    cout << "Case 2: Aaron alive, Charlie dead\n";
    aAlive = true;
    cAlive = false;
    bShoots(aAlive, cAlive);
    cout << "Case passed ...\n";
    
    cout << "Case 3: Aaron dead, Charlie alive\n";
    aAlive = false;
    cAlive = true;
    bShoots(aAlive, cAlive);
    cout << "Case passed ...\n";

}

void cShoots(bool& aAlive, bool& bAlive){
    if (bAlive) {
            bAlive = false;
            cout << "Charlie shot Bob.\n";
    }
    else if (aAlive){
            aAlive = false;
            cout << "Charlie shot Aaron.\n";
    }
}

void test_cShoots() {
    cout << "Case 1: Aaron alive, Bob alive\n";
    aAlive = true;
    bAlive = true;
    cShoots(aAlive, bAlive);
    cout << "Case passed ...\n";
    
    cout << "Case 2: Aaron alive, Bob dead\n";
    aAlive = true;
    bAlive = false;
    cShoots(aAlive, bAlive);
    cout << "Case passed ...\n";
    
    cout << "Case 3: Aaron dead, Bob alive\n";
    aAlive = false;
    bAlive = true;
    cShoots(aAlive, bAlive);
    cout << "Case passed ...\n";
}

void duelStrat1(){
    while (twoAlive(aAlive, bAlive, cAlive)) {
        if (aAlive) {
            aShoots(bAlive, cAlive);
        }
        if (bAlive) {
            bShoots(aAlive, cAlive);
        }
        if (cAlive) {
            cShoots(aAlive, bAlive);
        }
    }
    if (aAlive) {
        aWins1++;
        cout << "Aaron wins the duel.\n";
    }
    if (bAlive) {
        bWins++;
        cout << "Bob wins the duel.\n";
    }
    if (cAlive) {
        cWins++;
        cout << "Charlie wins the duel.\n";
    }
}

void duelStrat2(){
    while (twoAlive(aAlive, bAlive, cAlive)) {
        if (aAlive) {
            aIntentionalMiss(bAlive, cAlive);
        }
        if (bAlive) {
            bShoots(aAlive, cAlive);
        }
        if (cAlive) {
            cShoots(aAlive, bAlive);
        }
    }
    if (aAlive) {
        aWins2++;
        cout << "Aaron wins the duel.\n";
    }
    if (bAlive) {
        bWins++;
        cout << "Bob wins the duel.\n";
    }
    if (cAlive) {
        cWins++;
        cout << "Charlie wins the duel.\n";
    }
}


