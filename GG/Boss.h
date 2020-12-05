#ifndef BOSS_H
#define BOSS_H

#include "Entity.h"

class Boss :
    public Entity
{
private:
    //Variables
    bool attacking;
    int hp;
    int hpMax;
    int damage;
    int points;

    float attackCooldown;
    float attackCooldownMax;

    //Initializer functions
    void initVariables();
    void initComponents();

public:
    Boss(float x, float y, sf::Texture& texture);
    virtual ~Boss();

    //Accessor
    const sf::FloatRect HitboxgetBounds() const;
    sf::Vector2f GetPosition() { return sprite.getPosition(); }
    const int& getPoints() const;
    const int& getDamage() const;
    const int& getHp() const;
    const int& getHpMax() const;

    //Modifier
    void setHp(const int hp);
    void loseHp(const int value);

    //Functions
    const bool canAttack();
    void updateCoolDown();
    void updateAttack();
    void updateAnimation(const float& dt);
    void update(const float& dt);
};
#endif

