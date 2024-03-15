#ifndef ITEM_H_INCLUDED
#define ITEM_H_INCLUDED

class Item : public sf::Drawable, public Collisionable{
protected:
    char _nombre[30];
    sf::Sprite _sprite;
    sf::Texture _texture;
public:
    sf::Sprite getSprite(){return _sprite;}
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    void respawn(int x,int y);
    sf::FloatRect getBounds() const override;
};

void Item::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(_sprite, states);
}

void Item::respawn(int x,int y){
_sprite.setPosition(x,y);
}

sf::FloatRect Item::getBounds() const{
return _sprite.getGlobalBounds();
}


#endif // ITEM_H_INCLUDED
