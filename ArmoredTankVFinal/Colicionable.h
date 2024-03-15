#ifndef COLICIONABLE_H_INCLUDED
#define COLICIONABLE_H_INCLUDED

class Collisionable{

public:
    virtual sf::FloatRect getBounds() const = 0;
    bool isCollision(Collisionable& col) const;


};

bool Collisionable::isCollision(Collisionable& obj) const{

return getBounds().intersects(obj.getBounds());
}
#endif // COLICIONABLE_H_INCLUDED
