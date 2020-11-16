#ifndef COCONUT_H
#define COCONUT_H

#include "Entity.h"

class Coconut :
    public Entity
{
private:
    sf::CircleShape coconutHitbox;;

    //Variables
    int type;
    float speed;
    int hp;
    int hpMax;
    int damage;
    int points;


    //Initializer functions
    void initVariables();

public:
    Coconut(float x, float y, sf::Texture& texture);
    virtual ~Coconut();

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
    void coconutBackLeft();
    void coconutBackRight();
    void coconutBackUp();
    void coconutBackDown();
    void updateAnimation(const float& dt);
    virtual void update(const float& dt);
};
#endif

