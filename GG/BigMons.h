#ifndef BIGMONS_H
#define BIGMONS_H

#include "Entity.h"

class BigMons :
    public Entity
{
private:
    //Variables
    bool attacking;
   
    int type;
    float speed;
    int hp;
    int hpMax;
    int damage;
    int points;

    //Initializer functions
    void initVariables();

public:
    BigMons(float x, float y, sf::Texture& texture);
    virtual ~BigMons();

    //Accessor
    const sf::FloatRect getBounds() const;
    sf::Vector2f GetPosition() { return sprite.getPosition(); }
    const int& getPoints() const;
    const int& getDamage() const;
    const int& getHp() const;
    const int& getHpMax() const;

    //Modifier
    void setHp(const int hp);
    void loseHp(const int value);

    //Functions
    void bigmonsBackLeft();
    void bigmonsBackRight();
    void bigmonsBackUp();
    void bigmonsBackDown();

    void updateAnimation(const float& dt);
    virtual void update(const float& dt);
};
#endif

