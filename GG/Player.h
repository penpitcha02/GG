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
    const int& getHp() const;
    const int& getHpMax() const;

    //Modifier
    void setHp(const int hp);
    void loseHp(const int value);
    
    //Functions
    void updateAttack();
    void updateAnimation(const float& dt);
    virtual void update(const float& dt);
};
#endif

