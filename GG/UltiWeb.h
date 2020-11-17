#ifndef ULTIWEB_H
#define ULTIWEB_H

#include "Entity.h"

class UltiWeb :
    public Entity
{
private:
    //Variables
    float speed;
    int hp;
    int hpMax;
    int damage;
    int points;

    float attackCooldown;
    float attackCooldownMax;

    //Initializer functions
    void initVariables();

public:
    UltiWeb(float x, float y, sf::Texture& texture);
    virtual ~UltiWeb();

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
    const bool canAttack();
    void updateAttack();

    void attackwebBackLeft();
    void attackwebBackRight();
    void updateAnimation(const float& dt);
    virtual void update(const float& dt);
};
#endif


