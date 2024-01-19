#include "Enemy.h"
#include "../Game.h"

Enemy::Enemy(Position position, float health, unsigned int damage, CharData *charData) : InteractiveObject(position, charData) {
    m_health = health;
    m_damage = damage;
}

float Enemy::getHealth() {
    return m_health;
}

unsigned int Enemy::getDamage() {
    return m_damage;
}


void Enemy::dealDamage(unsigned int incomingDamage) {
    //nedochazi ke kontrole jiti do zapornych cisel, prototoze tuto vlastnost pozdeji vyuzije okno pro souboj
    m_health -= incomingDamage;
}

void Enemy::onPlayerEnter(Game *game) {

}

void Enemy::onPlayerProximity(Game *game) {

}
