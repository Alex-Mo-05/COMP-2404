#include "battle.h"
#include <iostream>

namespace Gondor {
    void fight(Character& fighter, Character& orc) {
        int fighterDamage = fighter.strike() + 1;
        int orcDamage = orc.strike() - 1;
        
        if (orcDamage < 0) orcDamage = 0;
        
        orc.takeDamage(fighterDamage);
        fighter.takeDamage(orcDamage);
        
        std::cout << fighter.getName() << " hits " << orc.getName() << " for " << fighterDamage << " damage!\n";
        std::cout << orc.getName() << " hits " << fighter.getName() << " for " << orcDamage << " damage!\n";
    }
}

namespace Mordor {
    void fight(Character& fighter, Character& orc) {
        int fighterDamage = fighter.strike() - 1;
        int orcDamage = orc.strike() + 1;
        
        if (fighterDamage < 0) fighterDamage = 0;
        
        orc.takeDamage(fighterDamage);
        fighter.takeDamage(orcDamage);
        
        std::cout << orc.getName() << " hits " << fighter.getName() << " for " << orcDamage << " damage!\n";
        std::cout << fighter.getName() << " hits " << orc.getName() << " for " << fighterDamage << " damage!\n";
    }
}