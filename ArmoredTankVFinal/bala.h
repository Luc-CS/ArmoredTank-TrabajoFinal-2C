#ifndef BALA_H_INCLUDED
#define BALA_H_INCLUDED
#include "Colicionable.h"

class Bala: public sf::Drawable, public Collisionable
{

private:
    sf::Sprite _spriteBala;
    sf::Texture _textura;
    sf::Texture _texturaA;
    sf::Texture _texturaB;
    sf::Texture _texturaD;
    sf::Texture _texturaI;
    float _velocidad;
    bool _colision;
    int _orientacion;
    char nombre[30];
    bool estado;

public:
    Bala(const char *n="Sprites/BalitaA.png",int x=4,int y=5, int ori=0, float velocidad=6,bool es=true)
    {
        strcpy(nombre,n);
        _textura.loadFromFile(nombre);
        _spriteBala.setTexture(_textura);
        float t1=0.25f,t2=0.25f;
        _spriteBala.setScale(t1,t2);
        _orientacion=ori;
        _spriteBala.setPosition(x, y);
        this->_velocidad=velocidad;
        this->estado=es;
    }
    ~Bala(){estado=false;}

    ///geters
    int getVelocidad(){return _velocidad;}
    bool getEstado(){return estado;}
    int getOrientacion(){return _orientacion;}
    sf::Sprite& getSprite(){return _spriteBala;}

    ///seters
    void setVelocidad(int velocidad){_velocidad=velocidad;}
    void setTextureSprite(const char *nom)
    {
        _textura.loadFromFile(nom);
        _spriteBala.setTexture(_textura);

    }
    void setEstado(bool es){estado=es;}
    void setOrientacion(int ori){_orientacion=ori;}

    void Mover()
    {
        if(_orientacion==1) //arriba
        {    _texturaA.loadFromFile("Sprites/BalitaA.png");
            _spriteBala.setTexture(_texturaA);
            _spriteBala.move(0.0f, -_velocidad);

        }
        if(_orientacion==2) //abajo
        {   _texturaB.loadFromFile("Sprites/BalitaB.png");
            _spriteBala.setTexture(_texturaB);

            _spriteBala.move(0.0f, _velocidad);


        }
        if(_orientacion==3) //izquierda
        {
            _texturaI.loadFromFile("Sprites/BalitaI.png");
            _spriteBala.setTexture(_texturaI);
            _spriteBala.move(-_velocidad, 0.0f);

        }
        if(_orientacion==4) //derecha
        {     _texturaD.loadFromFile("Sprites/BalitaD.png");
            _spriteBala.setTexture(_texturaD);
            _spriteBala.move(_velocidad, 0.0f);

        }
    }

    void draw(sf::RenderTarget& target, sf::RenderStates states)const override;
    sf::FloatRect getBounds() const override;



};

void Bala::draw(sf::RenderTarget& target, sf::RenderStates states)const
{

    target.draw(_spriteBala, states);
}
sf::FloatRect Bala::getBounds() const {
return _spriteBala.getGlobalBounds();
}



#endif // BALA_H_INCLUDED
