#include<iostream>
#include<string>
#include "Character.cc"
#include "battle.cc"

using namespace std;

int main () {
    string fname = "";
    int fhp = 0;
    int fdmg = 0;
    string oname = "";
    int ohp = 0;
    int odmg = 0;
    cout << "Input <<FIGHTER>> Name, Max Health, and Damage: ";
    cin >> fname;
    cin >> fhp;
    cin >> fdmg;
    Character *newFight = new Character(fname, fhp, fdmg);
    cout << "Input <<ORC>> Name, Max Health, and Damage: ";
    cin >> oname;
    cin >> ohp;
    cin >> odmg;
    Character *newOrc = new Character(oname, ohp, odmg);

    newFight->print();
    newOrc->print();    

    Gondor::fight(*newFight, *newOrc);
    newFight->print();
    newOrc->print();    

    
    Mordor::fight(*newFight, *newOrc);
    newFight->print();
    newOrc->print();    
    return 0;

}