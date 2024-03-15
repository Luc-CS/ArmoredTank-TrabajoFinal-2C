#ifndef ENEMIGO_H_INCLUDED
#define ENEMIGO_H_INCLUDED
#include "tanque.h"

class Enemigo : public Tanque{
    private:
        std::chrono::high_resolution_clock::time_point lastFireTime2 = std::chrono::high_resolution_clock::now();

    public:
        ///CONSTRUCTOR
        Enemigo(int x=30,int y=427,sf::Vector2f vel={2,2}, int vida=100){
            _vida=vida;
            setx(x);
            setx(y);
            _velocidad=vel;
            _spriteTanque.setPosition(x,y);
            _spriteTanque.setScale(1.3,1.3);
            _estado=true;


        ///CARGA DE TEXTURAS

            if (!_texturaArriba.loadFromFile("Sprites/tanqueA1.png")){
                cout<<"Error cargando la textura"<<endl;
            }

            _spriteTanque.setTexture(_texturaArriba);

            if (!_texturaIzquierda.loadFromFile("Sprites/tanqueL1.png")){
                cout<<"Error cargando la textura TanqueIzquierda"<<endl;
            }

            if (!_texturaAbajo.loadFromFile("Sprites/tanqueB1.png")){
                cout<<"Error cargando la textura TanqueBajo"<<endl;
            }

            if (!_texturaDerecha.loadFromFile("Sprites/tanqueD1.png")){
                cout<<"Error cargando la textura TanqueDerecha"<<endl;
            }

        }

     /**------------------------------------------------------*/
    ///METODOS

        void moverSolo(bool colision);
        void dispararSolo(sf::Event &event,sf::RenderWindow &window);


};

void Enemigo::dispararSolo(sf::Event &event,sf::RenderWindow &window){

    int num=1+rand()%(120-1);

        if(num==2){
            balas.push_back(new Bala("Sprites/BalitaA.png",getx(),gety(),getOrientacion()));






        }
        for(int i=0; i<balas.size();i++){
        if(balas[i]->getEstado()){window.draw(balas[i]->getSprite());}

            balas[i]->Mover();
    }
        for(int i=0; i<balas.size();i++){

        ///SEPARE LAS CONDICIONES PORQUE SINO QUEDABA RARO

        if(balas[i]->getSprite().getPosition().y<0 || balas[i]->getSprite().getPosition().x<0 || balas[i]->getSprite().getPosition().y>=450 || balas[i]->getSprite().getPosition().x>=650){
            balas.erase(balas.begin()+i);
        }
        }
}



void Enemigo::moverSolo(bool colision){

    auto currentTime1 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsedSeconds = currentTime1 - lastFireTime2;
    if(elapsedSeconds.count()>=1.3||colision==true){
            lastFireTime2 = currentTime1;
    _orientacion=1+rand()%(5-1);
    switch(_orientacion){
case 1:
_spriteTanque.setTexture(_texturaArriba);
_velocidad.x=0;
_velocidad.y=-3;
    break;
    case 2:
        _spriteTanque.setTexture(_texturaAbajo);
        _velocidad.x=0;
_velocidad.y=3;
    break;
    case 3:
        _spriteTanque.setTexture(_texturaIzquierda);
        _velocidad.x=-3;
_velocidad.y=0;
    break;
    case 4:
        _spriteTanque.setTexture(_texturaDerecha);
        _velocidad.x=3;
_velocidad.y=0;
    break;
    }

    }
_spriteTanque.move(_velocidad);

}

#endif // ENEMIGO_H_INCLUDED
