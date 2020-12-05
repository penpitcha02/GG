#ifndef ULTIDRAGON_H
#define ULTIDRAGON_H

#include "Entity.h"

class UltiDragon :
    public Entity
{
private:
    //Variables
    float speed;
    int damage;

    float attackCooldown;
    float attackCooldownMax;

    //Initializer functions
    void initVariables();

public:
    UltiDragon(float x, float y, sf::Texture& texture);
    virtual ~UltiDragon();

    //Accessor
    void SetScale(float x, float y);
    const sf::FloatRect getBounds() const;
    sf::Vector2f GetPosition() { return sprite.getPosition(); }
    const int& getDamage() const;

    //Functions
    const bool canAttack();
    void updateAttack();

    void moveLeft();
    void moveRight();
    void leftHitbox();
    void rightHitbox();
    void updateAnimation(const float& dt);
    virtual void update(const float& dt);
};
#endif




