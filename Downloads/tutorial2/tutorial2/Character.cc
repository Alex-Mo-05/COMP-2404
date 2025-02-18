#include "Character.h"
#include <iostream>

Character::Character(const std::string& name, int maxHealth, int damage)
    : name(name), maxHealth(maxHealth), currentHealth(maxHealth), damage(damage) {}

const std::string& Character::getName() const {
    return name;
}

void Character::takeDamage(int dmg) {
    currentHealth -= dmg;
    if (currentHealth < 0) currentHealth = 0;
}

int Character::strike() const {
    return damage;
}

void Character::print() const {
    std::cout << name << " (Health: " << currentHealth << "/" << maxHealth << ")\n";
}