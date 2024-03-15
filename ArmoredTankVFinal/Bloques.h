#ifndef BLOQUES_H_INCLUDED
#define BLOQUES_H_INCLUDED

class Bloque : public sf::Drawable, public Collisionable{
private:
    int _durabilidad=1;
    int _tipo;
    int _x,_y;
    bool _estado;
    sf::Sprite _spriteBloque;
    sf::Texture _texture;


public:
    Bloque(int t=1,int x=0,int y=0,int du=100,bool es=true){
        _durabilidad=du;
        _tipo=t;
        _x=x;
        _y=y;
        _estado=es;
        _spriteBloque.setScale(1.5,1.5);

        if(_tipo==1){
            _texture.loadFromFile("Sprites/ladrillo.png");
            _spriteBloque.setTexture(_texture);
        }
        if(_tipo==2){
            _texture.loadFromFile("Sprites/hierro.png");
            _spriteBloque.setTexture(_texture);
        }

        if(_tipo==3){
            _texture.loadFromFile("Sprites/arbusto.png");
            _spriteBloque.setTexture(_texture);
        }
    }
    ~Bloque(){};

    ///SETS
    void ladrilloRoto(){
    _texture.loadFromFile("Sprites/ladrilloRoto.png");

    _spriteBloque.setTexture(_texture);

    }
    void setDurabilidad(int d){_durabilidad=d;}
    void setTipo(int t){
        _tipo=t;

        if(_tipo==1){
            _texture.loadFromFile("Sprites/ladrillo.png");
            _spriteBloque.setTexture(_texture);
        }
        if(_tipo==2){
            _texture.loadFromFile("Sprites/hierro.png");
            _spriteBloque.setTexture(_texture);
        }

        if(_tipo==3){
            _texture.loadFromFile("Sprites/arbusto.png");
            _spriteBloque.setTexture(_texture);
        }
    }

    void setEstado(bool es){_estado=es;}
    void setx(int x){
        _spriteBloque.setPosition(x,_y);
        _x=x;
    }
    void sety(int y){
        _spriteBloque.setPosition(_x,y);
        _y=y;
    }

    ///GETS

    int getDurabilidad(){return _durabilidad;}
    int getTipo(){return _tipo;}
    int getx(){return _spriteBloque.getPosition().x;}
    int gety(){return _spriteBloque.getPosition().y;}
    sf::Sprite getSprite(){return _spriteBloque;}
    bool getEstado(){return _estado;}

    void bloqueLadrillo();
    void bloqueHierro();
    void bloqueArbusto();
    void marcarEliminar();
    bool verificarEliminar();

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    sf::FloatRect getBounds() const override;

};

void Bloque::marcarEliminar(){
_estado=false;
}

bool Bloque::verificarEliminar(){
return _estado;
}

void Bloque::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(_spriteBloque, states);
}

sf::FloatRect Bloque::getBounds() const
{
    return _spriteBloque.getGlobalBounds();
}


#endif // BLOQUES_H_INCLUDED
