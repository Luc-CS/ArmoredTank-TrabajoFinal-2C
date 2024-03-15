#ifndef CLASE_H_INCLUDED
#define CLASE_H_INCLUDED
#include "Colicionable.h"



class Tanque : public sf::Drawable, public Collisionable
{
protected:
    int _color;
    int _vida;
    Corazon _corazones[3];
    vector<Bala*> balas;
    sf::Vector2f _velocidad;
    int _cantVeloci;
    int _x,_y;
    int _orientacion=1;//1-ARRIBA 2-ABAJO 3-IZQUIERDA 4-DERECHA
    sf::Sprite _spriteTanque;
    sf::Texture _texturaArriba;
    sf::Texture _texturaIzquierda;
    sf::Texture _texturaDerecha;
    sf::Texture _texturaAbajo;
    bool _estado;

    std::chrono::high_resolution_clock::time_point lastFireTime1 = std::chrono::high_resolution_clock::now();


public:
    ///constructor

    Tanque(int x=630,int y=30,int color=0,int vida=300,int veloci=3,int ori=1)
    {
        _vida=vida;
        _spriteTanque.setPosition(x,y);
       setx(x);
       sety(y);

        _spriteTanque.setScale(1.3,1.3);
        _color=color;
        _cantVeloci=veloci;
        _orientacion=ori;
        _estado=true;
        if(color==0)
        {
            if (!_texturaArriba.loadFromFile("Sprites/tanqueA.jpg"))
            {
                cout<<"Error cargando la textura"<<endl;
                _spriteTanque.setTexture(_texturaArriba);
            }
            _spriteTanque.setTexture(_texturaArriba);

            if (!_texturaIzquierda.loadFromFile("Sprites/tanqueL.jpg"))
            {
                cout<<"Error cargando la textura TanqueIzquierda"<<endl;
            }

            if (!_texturaAbajo.loadFromFile("Sprites/tanqueB.jpg"))
            {
                cout<<"Error cargando la textura TanqueBajo"<<endl;
            }


            if (!_texturaDerecha.loadFromFile("Sprites/tanqueD.jpg"))
            {
                cout<<"Error cargando la textura TanqueDerecha"<<endl;
            }

        }
        if(color==1)
        {
            if (!_texturaArriba.loadFromFile("Sprites/tanqueB1.png"))
            {
                cout<<"Error cargando la textura"<<endl;
            }
            _spriteTanque.setTexture(_texturaArriba);

            if (!_texturaIzquierda.loadFromFile("Sprites/tanqueL1.png"))
            {
                cout<<"Error cargando la textura TanqueIzquierda"<<endl;
            }

            if (!_texturaAbajo.loadFromFile("Sprites/tanqueB1.png"))
            {
                cout<<"Error cargando la textura TanqueBajo"<<endl;
            }


            if (!_texturaDerecha.loadFromFile("Sprites/tanqueD1.png"))
            {
                cout<<"Error cargando la textura TanqueDerecha"<<endl;
            }

        }

    }

    ///Getters
    int getx(){return _spriteTanque.getPosition().x;}
    int gety(){return _spriteTanque.getPosition().y;}
    int getColor(){return _color;}
    int getVida(){return _vida;}
    Corazon* getCorazones(){return _corazones;}
    vector<Bala*>& getBala(){return balas;}
    sf::Sprite& getSprite(){return _spriteTanque;}
    sf::Vector2f getVelocidad(){return _velocidad;}
    int getCantVelocidad(){return _cantVeloci;}
    int getOrientacion(){return _orientacion;}
    bool getEstado();
    void setEstado(bool es);
    void setBala( vector<Bala*> bal){
    balas=bal;

    }



    ///Setters
    void setx(int x)
    {
        _spriteTanque.setPosition(x,_y);
        _x=x;
    }
    void sety(int y)
    {

        _spriteTanque.setPosition(_x,y);
        _y=y;
    }
    void setColor(int color)
    {
        _color=color;
    }
    void setVida(int vida)
    {
        _vida=vida;
    }
    void setOrientacion(int o){
     _orientacion=o;
    }
    void setVelocidad(int velo){_cantVeloci=velo;}

///-----------------------------------/

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    void respawn(int x,int y);
    sf::FloatRect getBounds() const override;

    void dibujarCorazones(sf::Event &event,sf::RenderWindow &window,int x, int y);

        bool danio(bool impacto,int x, int y);
        void setTexture(const char *n, int ori);




};


void Tanque::setTexture(const char *n, int ori){
 if(ori==1){

        if (!_texturaArriba.loadFromFile(n))
            {
                cout<<"Error cargando la textura"<<endl;
                _spriteTanque.setTexture(_texturaArriba);
            }



 }else if (ori==2){

        if (!_texturaAbajo.loadFromFile(n))
            {
                cout<<"Error cargando la textura"<<endl;
                _spriteTanque.setTexture(_texturaArriba);
            }



 }else if (ori==3){

        if (!_texturaIzquierda.loadFromFile(n))
            {
                cout<<"Error cargando la textura"<<endl;
                _spriteTanque.setTexture(_texturaArriba);
            }



 }else if (ori==4){

        if (!_texturaDerecha.loadFromFile(n))
            {
                cout<<"Error cargando la textura"<<endl;
                _spriteTanque.setTexture(_texturaArriba);
            }

 }


 }


bool Tanque::getEstado(){
return _estado;
}

void Tanque::setEstado(bool es){
_estado=es;
}

void Tanque::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    target.draw(_spriteTanque, states);
}

sf::FloatRect Tanque::getBounds() const{
    return _spriteTanque.getGlobalBounds();
}


void Tanque::respawn(int x,int y){
    _spriteTanque.setPosition(x,y);
}

bool Tanque::danio(bool impacto, int x, int y ) {

    if (impacto==true) {

        _vida -= 50;

        if (_vida == 250) _corazones[0].dibujarMediocorazon();
        if (_vida == 150) _corazones[1].dibujarMediocorazon();
        if (_vida == 50)  _corazones[2].dibujarMediocorazon();

        if (_vida == 200) {
                if(_color==0 ||_color==3){
                    respawn(x, y);
                }

            _corazones[0].setEstado(false);
        }

        if (_vida == 100) {
                if(_color==0 ||_color==3 ){
                      respawn(x, y);
                }

            _corazones[1].setEstado(false);
        }

        if (_vida == 0) {
                _corazones[2].setEstado(false);
                if(_color==0 ||_color==3){
                    return false;
                }

                respawn(x,y);
                _vida=300;





            }

    }

    return true;


}


void Tanque::dibujarCorazones(sf::Event &event,sf::RenderWindow &window,int x,int y){

for(int i=0;i<3;i++){
    _corazones[i].setx(x+(i+1)*20);
        _corazones[i].sety(y);
        if(_corazones[i].getEstado()==true){
                window.draw(_corazones[i].getSprite());
        }
}
}



#endif // CLASE_H_INCLUDED
