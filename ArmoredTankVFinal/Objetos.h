#ifndef OBJETOS_H_INCLUDED
#define OBJETOS_H_INCLUDED


class Objeto : public Item{

private:
    int _x,_y;
    bool _estado;
    std::chrono::high_resolution_clock::time_point lastFireTime4 = std::chrono::high_resolution_clock::now();
    bool bloqueEjecutado; // Variable de instancia para rastrear si el bloque se ejecutó
    int idTanque;

public:
    Objeto(const char *nom,bool es=true, int x=0, int y=0){
        strcpy(_nombre,nom);
        _estado=es;
        _texture.loadFromFile(_nombre);
        _sprite.setTexture(_texture);
        _sprite.setPosition(x,y);
        bloqueEjecutado = false;
    }
    void setx(int x){
        _sprite.setPosition(x,_y);
        _x=x;
    }
    void sety(int y){
        _sprite.setPosition(_x,y);
        _y=y;
    }
    int getx(){return _sprite.getPosition().x;}
    int gety(){return _sprite.getPosition().y;}
    bool getEstado(){return _estado;}

    void Desaparecer(bool colision){
        if(colision==true){
            _estado=false;
        }
    }
    void respawn(int x,int y){
    _sprite.setPosition(x,y);
    _estado=true;
    }

void UpdateRapidez(jugador &tanq,bool colision,Mapa &mapita,int x,int y){
        auto currentTime = std::chrono::high_resolution_clock::now();//le daria la hora actual en el momento de ahora
    std::chrono::duration<double> elapsedSeconds = currentTime - lastFireTime4;

        Desaparecer(colision);
        if(colision==true){

                tanq.setVelocidad(tanq.getCantVelocidad()+2);
                lastFireTime4 = currentTime;
                bloqueEjecutado=false;
                idTanque=tanq.getID();
        }
        else if(elapsedSeconds.count() >= 5.0 && _estado==false && bloqueEjecutado==false && idTanque==tanq.getID()){


                tanq.setVelocidad(tanq.getCantVelocidad()-2);
                lastFireTime4 = currentTime;
                bloqueEjecutado=true;//bloque ejecutado
        }
        else if(elapsedSeconds.count() >=5.0 && _estado==false&&idTanque==tanq.getID()){
                respawn(x,y);

        }

}

void upgradeVida(jugador &mansotanque,bool colision,Mapa &mapita,Corazon *nCorazon,int x,int y){
auto currentTime = std::chrono::high_resolution_clock::now();//le daria la hora actual en el momento de ahora
    std::chrono::duration<double> elapsedSeconds = currentTime - lastFireTime4;

    Desaparecer(colision);

   if (colision == true) {
        bloqueEjecutado = false;


        if(mansotanque.getVida()== 150 || mansotanque.getVida()==100){
                 mansotanque.setVida(200);
           nCorazon[1].setTextura("Sprites/corazon.png");
           nCorazon[1].setEstado(true);
           lastFireTime4 = currentTime;
        }

        else  if(mansotanque.getVida()== 250 || mansotanque.getVida()==200 ){
            mansotanque.setVida(300);

            nCorazon[0].setTextura("Sprites/corazon.png");
           nCorazon[0].setEstado(true);
           lastFireTime4 = currentTime;

        }

        else if(mansotanque.getVida()== 50 ){
            mansotanque.setVida(100);
            nCorazon[2].setTextura("Sprites/corazon.png");
           nCorazon[2].setEstado(true);
           lastFireTime4 = currentTime;

        }

        idTanque=mansotanque.getID();

    }

    if(bloqueEjecutado==false && elapsedSeconds.count() >=40.0 &&mansotanque.getID()){


        respawn(x,y);
        bloqueEjecutado=true;
        lastFireTime4 = currentTime;
    }

}


void UpdateFantasma(jugador &mansotanque,bool colision,int x,int y){

    auto currentTime = std::chrono::high_resolution_clock::now();//le daria la hora actual en el momento de ahora
    std::chrono::duration<double> elapsedSeconds = currentTime - lastFireTime4;
    Desaparecer(colision);
        if(colision==true){
                mansotanque.setEstado(false);
                lastFireTime4 = currentTime;
                bloqueEjecutado=false;
                mansotanque.setTexture("Sprites/tanqueFantasmaA.png",1);
                mansotanque.setTexture("Sprites/tanqueFantasmaB.png",2);
                mansotanque.setTexture("Sprites/tanqueFantasmaI.png",3);
                mansotanque.setTexture("Sprites/tanqueFantasmaD.png",4);
                idTanque=mansotanque.getID();
        }
        else if(elapsedSeconds.count() >= 5.0 && _estado==false &&bloqueEjecutado==false&&idTanque==mansotanque.getID()){

                mansotanque.setEstado(true);
                lastFireTime4 = currentTime;
                bloqueEjecutado=true;//bloque ejecutado
                if(mansotanque.getColor()==0){
                mansotanque.setTexture("Sprites/tanqueA.jpg",1);
                mansotanque.setTexture("Sprites/tanqueB.jpg",2);
                mansotanque.setTexture("Sprites/tanqueL.jpg",3);
                mansotanque.setTexture("Sprites/tanqueD.jpg",4);
                } else if(mansotanque.getColor()==3){

                mansotanque.setTexture("Sprites/tanqueA1.png",1);
                mansotanque.setTexture("Sprites/tanqueB1.png",2);
                mansotanque.setTexture("Sprites/tanqueL1.png",3);
                mansotanque.setTexture("Sprites/tanqueD1.png",4);
                }
        }
        else if(elapsedSeconds.count() >=30.0 && _estado==false&&idTanque==mansotanque.getID()){
                respawn(x,y);
        }
}



void UpdateTam(jugador &mansotanque,bool colision,int x,int y){

    auto currentTime = std::chrono::high_resolution_clock::now();//le daria la hora actual en el momento de ahora
    std::chrono::duration<double> elapsedSeconds = currentTime - lastFireTime4;


        Desaparecer(colision);


        if(colision==true){

                mansotanque.getSprite().setScale(0.7f,0.7f);
                lastFireTime4 = currentTime;
                bloqueEjecutado=false;
                idTanque=mansotanque.getID();

        }
        else if(elapsedSeconds.count() >= 5.0 &&!bloqueEjecutado && idTanque==mansotanque.getID()){

                mansotanque.getSprite().setScale(1.3f,1.3f);
                lastFireTime4 = currentTime;
                bloqueEjecutado=true;
        }
        else if(elapsedSeconds.count() >=10.0 && _estado==false&&idTanque==mansotanque.getID()){
                respawn(x,y);
        }
   }


    void draw(sf::RenderWindow &window){
        if(_estado==true){
        window.draw(_sprite);
        }
    }

};

#endif // OBJETOS_H_INCLUDED
