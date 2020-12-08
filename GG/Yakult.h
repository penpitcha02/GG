#ifndef YAKULT_H
#define YAKULT_H

#include "Entity.h"

class Yakult :
    public Entity
{
private:
    //Variables
    int heal;


    //Initializer functions
    void initVariables();

public:
    Yakult(float x, float y, sf::Texture& texture);
    virtual ~Yakult();

    //Accessor
    const sf::FloatRect getBounds() const;
    sf::Vector2f GetPosition() { return sprite.getPosition(); }
    const int& getHeal() const;

    //Functions
    void updateAnimation(const float& dt);
    virtual void update(const float& dt);
};
#endif

