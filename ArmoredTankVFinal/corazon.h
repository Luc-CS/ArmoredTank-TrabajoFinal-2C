#ifndef CORAZON_H_INCLUDED
#define CORAZON_H_INCLUDED
class Corazon : public sf::Drawable{
private:
    sf::Sprite _spriteCorazon;
    sf::Texture _textureCorazon;
    int _x,_y;
    bool _estado;
public:
    Corazon(){
        if (!_textureCorazon.loadFromFile("Sprites/corazon.png"))
            {
                cout<<"Error cargando la textura"<<endl;
            }
        _spriteCorazon.setTexture(_textureCorazon);
        _estado=true;
        _spriteCorazon.setScale(2.3,2.3);
    }
    sf::Sprite& getSprite(){return _spriteCorazon;}
    int getx(){return _spriteCorazon.getPosition().x;}
    int gety(){return _spriteCorazon.getPosition().y;}
    bool getEstado(){return _estado;}
    void setx(int x){
        _spriteCorazon.setPosition(x,_y);
        _x=x;
    }
    void sety(int y){
        _spriteCorazon.setPosition(_x,y);
        _y=y;
    }

    void setEstado(bool es){_estado=es;}
    void dibujarMediocorazon();
    void setTextura(const char *n){
    _textureCorazon.loadFromFile(n);
    }
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

};

void Corazon::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    target.draw(_spriteCorazon, states);
}

void Corazon::dibujarMediocorazon() {
    if (!_textureCorazon.loadFromFile("Sprites/corazonMitad.png")) {
        cout << "Error cargando la textura" << endl;
  }
    _spriteCorazon.setTexture(_textureCorazon);
}


#endif // CORAZON_H_INCLUDED
