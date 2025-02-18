#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>

class Character {
private:
    std::string name;
    int maxHealth;
    int currentHealth;
    int damage;

public:
    Character(const std::string& name, int maxHealth, int damage);
    const std::string& getName() const;
    void takeDamage(int damage);
    int strike() const;
    void print() const;
};

#endif