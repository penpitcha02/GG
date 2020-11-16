#ifndef LOCKWEB_H
#define LOCKWEB_H

#include "Entity.h"

class LockWeb :
    public Entity
{
private:

    //Variables
    float speed;
    int hp;
    int hpMax;
    int points;

    //Initializer functions
    void initVariables();

public:
    LockWeb(float x, float y, sf::Texture& texture);
    virtual ~LockWeb();

    //Accessor
    const sf::FloatRect getBounds() const;
    sf::Vector2f GetPosition() { return sprite.getPosition(); }
    const int& getPoints() const;
    const int& getHp() const;
    const int& getHpMax() const;

    //Modifier
    void setHp(const int hp);
    void loseHp(const int value);

    //Functions
    void updateAnimation(const float& dt);
    virtual void update(const float& dt);
};
#endif

