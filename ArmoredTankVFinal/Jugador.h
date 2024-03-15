#ifndef JUGADOR_H_INCLUDED
#define JUGADOR_H_INCLUDED

class jugador:public Tanque{

private:
   int _id;
   char _nombre[30];
   int _puntaje;
   bool _estado;

public:
    jugador(int color,int id){
         setColor(color);

         if(color==3){
            setTexture("Sprites/tanqueA1.png",1);
            setTexture("Sprites/tanqueB1.png",2);
            setTexture("Sprites/tanqueL1.png",3);
            setTexture("Sprites/tanqueD1.png",4);
            sety(430);
            setx(35);
        }
            _id=id;
            _puntaje=0;
    }

    int getPuntaje(){return _puntaje;}

    void setPuntaje(int n){
      _puntaje+=n;
    }


    int getID(){return _id;}
    const char* getNombre(){return _nombre;};
    void setNombre(const char* n){strcpy(_nombre,n);};

 int UpdateDibujarSprite(){
    _velocidad= {0,0};

    //ARRIBA
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && _spriteTanque.getPosition().y>32){
        _spriteTanque.setTexture(_texturaArriba);
        _velocidad.y=-_cantVeloci;
        _orientacion=1;
    }

    //IZQUIERDA
   else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)&& _spriteTanque.getPosition().x>32){
        _spriteTanque.setTexture(_texturaIzquierda);
        _velocidad.x=-_cantVeloci;
        _orientacion=3;
    }

    //ABAJO
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)&& _spriteTanque.getPosition().y<445){
        _spriteTanque.setTexture(_texturaAbajo);
        _velocidad.y=_cantVeloci;
        _orientacion=2;
    }

    //DERECHA
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)&& _spriteTanque.getPosition().x<660){
        _spriteTanque.setTexture(_texturaDerecha);
        _velocidad.x=_cantVeloci;
        _orientacion=4;
    }

    _spriteTanque.move(_velocidad);
    return _orientacion;

}

void Disparar(sf::Event &event,sf::RenderWindow &window){

    auto currentTime = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> elapsedSeconds = currentTime - lastFireTime1;


        if (sf::Keyboard::isKeyPressed(sf::Keyboard::RShift) && elapsedSeconds.count() >= 0.7){
            balas.push_back(new Bala("Sprites/BalitaA.png",getx(),gety(),getOrientacion()));



            lastFireTime1 = currentTime;

        }



    for(int i=0; i<balas.size();i++){
        if(balas[i]->getEstado()){window.draw(balas[i]->getSprite());}

            balas[i]->Mover();
    }

    for(int i=0; i<balas.size();i++){


        if(balas[i]->getSprite().getPosition().y<0 || balas[i]->getSprite().getPosition().x<0 || balas[i]->getSprite().getPosition().y>=460 || balas[i]->getSprite().getPosition().x>=700){
            balas.erase(balas.begin()+i);
        }

    }

}


  int UpdateDibujarSpriteJug2(){
    _velocidad= {0,0};

    //ARRIBA
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W) && _spriteTanque.getPosition().y>30){
        _spriteTanque.setTexture(_texturaArriba);
        _velocidad.y=-_cantVeloci;
        _orientacion=1;
    }

    //IZQUIERDA
   else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)&& _spriteTanque.getPosition().x>30){
        _spriteTanque.setTexture(_texturaIzquierda);
        _velocidad.x=-_cantVeloci;
        _orientacion=3;
    }

    //ABAJO
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)&& _spriteTanque.getPosition().y<446){
        _spriteTanque.setTexture(_texturaAbajo);
        _velocidad.y=_cantVeloci;
        _orientacion=2;
    }

    //DERECHA
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)&& _spriteTanque.getPosition().x<662){
        _spriteTanque.setTexture(_texturaDerecha);
        _velocidad.x=_cantVeloci;
        _orientacion=4;
    }

    _spriteTanque.move(_velocidad);
    return _orientacion;

}



 void DispararJug2(sf::Event &event,sf::RenderWindow &window){


    auto currentTime = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> elapsedSeconds = currentTime - lastFireTime1;


        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && elapsedSeconds.count() >= 0.7){
            balas.push_back(new Bala("Sprites/BalitaA.png",getx(),gety(),getOrientacion()));



            lastFireTime1 = currentTime;

        }



    for(int i=0; i<balas.size();i++){
        if(balas[i]->getEstado()){window.draw(balas[i]->getSprite());}

            balas[i]->Mover();
    }

    for(int i=0; i<balas.size();i++){


        if(balas[i]->getSprite().getPosition().y<0 || balas[i]->getSprite().getPosition().x<0 || balas[i]->getSprite().getPosition().y>=460 || balas[i]->getSprite().getPosition().x>=700){
            balas.erase(balas.begin()+i);
        }

    }

}

};


#endif // JUGADOR_H_INCLUDED
