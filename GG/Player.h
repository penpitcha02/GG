#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"

class Player :
    public Entity
{
private:
    //Variables
    bool attacking;
    int hp;
    int hpMax;
    int damage;

    float attackCooldown;
    float attackCooldownMax;

    //Initializer functions
    void initVariables();
    void initComponents();

public:
    Player(float x, float y, sf::Texture& texture);
    virtual ~Player();

    //Accessor
    const sf::FloatRect HitboxgetBounds() const;
    const sf::FloatRect CutboxgetBounds() const;
    sf::Vector2f GetPosition() { return sprite.getPosition(); }
    const int& faceLeft() const;
    const int& faceRight() const;
    const int& getHp() const;
    const int& getHpMax() const;
    const int& getDamage() const;

    //Modifier
    void setHp(const int hp);
    void loseHp(const int value);
    
    //Functions
    const bool canAttack();
    void updateCoolDown();
    void updateAttack();
    const bool isAttacking();
    void updateCutbox();
    void updateAnimation(const float& dt);
    virtual void update(const float& dt);
};
#endif

