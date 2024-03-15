#ifndef MAPA_H_INCLUDED
#define MAPA_H_INCLUDED

class Mapa{
    private:
        Bloque _bloquesL[150];
        Bloque _auxiliar;
        Bloque _bloquesH[10];
        Bloque _bloquesA[14];

    public:


    /**------------------------------------------------------*/
    ///METODOS

    int getAlto(){return _auxiliar.getSprite().getGlobalBounds().height;}
    int getAncho(){return _auxiliar.getSprite().getGlobalBounds().width;}

    Bloque* getBloqueL(){return _bloquesL;}
    Bloque* getBloqueH(){return _bloquesH;}
    Bloque* getBloqueA(){return _bloquesA;}
    void dibujarLimites(sf::Event &event,sf::RenderWindow &window);
    void dibujarMapa(sf::Event &event,sf::RenderWindow &window);
    void dibujarCostados(sf::Event &event,sf::RenderWindow &window);
    void dibujarCentro1(sf::Event &event,sf::RenderWindow &window);
    void dibujarCentro2(sf::Event &event,sf::RenderWindow &window);

};


void Mapa::dibujarLimites(sf::Event &event,sf::RenderWindow &window){//CANTIDAD DE BLOQUES USADO ACA : 95

    int posX=0;
    int posY=0;

    for(int i=0;i<41;i++){//DEL BLOQUE 0 AL 22 - ARRIBA ; DEL 23 AL 41 DERECHA
        window.draw(_bloquesL[i]);

        if(i<=22){
            posX=posX+getAncho();
            _bloquesL[i+1].setx(posX);
        }else{
            posY=posY+getAlto();
            _bloquesL[i+1].sety(posY);
            _bloquesL[i+1].setx(posX);
        }
    }

    posX=0;
    posY=0;

    for(int i=41;i<81;i++){//DEL BLOQUE 41 AL 57 - IZQUIERDA ; 58 AL 80 ABAJO

            window.draw(_bloquesL[i]);


        if(i<=57){
            posY=posY+getAlto();
            _bloquesL[i+1].sety(posY);
        }else{
            posX=posX+getAncho();
            _bloquesL[i+1].setx(posX);
            _bloquesL[i+1].sety(posY);
        }

    }

}

void Mapa::dibujarCostados(sf::Event &event,sf::RenderWindow &window){
    //TIRA IZQUIERDA LADRILLO

    int posY=getAlto()*2+getAlto()/2;
    int posX=getAncho()*2+getAncho()/2;

    for(int i=81;i<89;i++){ ///BLOQUES 81 A 88 = TOTAL 8 ; DEL 86 AL 88 DIBUJA LOS TRES LADRILLOS DE ABAJO

        if(i==86){ ///ESTO PARA LOS 3 LADRILLOS DE ABAJO
            posY=posY+getAlto()*3;
        }

        _bloquesL[i].sety(posY);
        _bloquesL[i].setx(posX);
         if(_bloquesL[i].getEstado()==true){
            window.draw(_bloquesL[i]);
        }
        posY=posY+getAlto();

    }

    //TIRA IZQUIERDA PARTE HIERRO

    for(int i=0;i<3;i++){ ///DEL 0 AL 2 SON DE HIERRO, FALTA MEJORAR IMAGEN Y MODIFICAR ALTURA :S

        if(i==2){
            posY=posY-getAlto();
            posX=posX+getAncho();
        }

        _bloquesH[i].setTipo(2);
        _bloquesH[i].sety(posY);
        _bloquesH[i].setx(posX);

        window.draw(_bloquesH[i]);
        posY=posY+getAlto();
    }

    /**------------------------------------------*/
    //TIRA DERECHA PARTE HIERRO

    posY=getAlto()*2+getAlto()/2;
    posX=getAncho()*19+getAncho()/2;

    for(int i=3;i<6;i++){ ///DEL 3 AL 5 SON DE HIERRO, LOS TRES DE ARRIBA

        if(i==5){
            posX=posX-getAncho();
            posY=posY+getAlto();
        }

        _bloquesH[i].setTipo(2);
        _bloquesH[i].sety(posY);
        _bloquesH[i].setx(posX);

        window.draw(_bloquesH[i]);
        posX=posX+getAncho();

    }

    //TIRA DERECHA LADRILLO

    posY=posY+getAlto();
    posX=posX-getAncho();

    for(int i=89;i<97;i++){ ///DEL 89 AL 96 SON LADRILLOS - TOTAL = 8 ; DEL 92 AL 96 DIBUJA LOS DE ABAJO

        if(i==92){ ///ESTO PARA LOS 5 LADRILLOS DE ABAJO
            posY=posY+getAlto()*3;
        }

        _bloquesL[i].sety(posY);
        _bloquesL[i].setx(posX);

        if(_bloquesL[i].getEstado()==true){
            window.draw(_bloquesL[i]);
        }
        posY=posY+getAlto();
    }

    _bloquesA[12].setTipo(3);
    _bloquesA[12].setx(getAncho()*4);
    _bloquesA[12].sety(getAlto()*8+getAlto()/2);
    _bloquesA[13].setTipo(3);
    _bloquesA[13].setx(getAncho()*19);
    _bloquesA[13].sety(getAlto()*8+getAlto()/2);

    window.draw(_bloquesA[12]);
    window.draw(_bloquesA[13]);

}

void Mapa::dibujarCentro1(sf::Event &event,sf::RenderWindow &window){

    //CENTRO ARRIBA Y DERECHA

    int posY=getAlto()*2+getAlto()/2;
    int posX=getAncho()*6;

    for(int i=97;i<118;i++){

        _bloquesL[i].setx(posX);
        _bloquesL[i].sety(posY);

        if(_bloquesL[i].getEstado()==true){
            window.draw(_bloquesL[i]);
        }
        if(i<=107){
            posX=posX+getAncho();
        }else{
            posY=posY+getAlto();
        }

    }


    //CENTRO IZQUIERDA Y ABAJO

    posY=getAlto()*5+getAlto()/2;
    posX=getAncho()*6;

    for(int i=118;i<139;i++){

        _bloquesL[i].setx(posX);
        _bloquesL[i].sety(posY);

        if(i<=126){
            posY=posY+getAlto();
        }else{
            posX=posX+getAncho();
        }

        if(_bloquesL[i].getEstado()==true){
            window.draw(_bloquesL[i]);
        }



    }

}

void Mapa::dibujarCentro2(sf::Event &event,sf::RenderWindow &window){
    ///HIERRO DEL CENTRO

    int posY=getAlto()*6;
    int posX=getAncho()*11+(getAncho()/2);

    for(int i=6;i<10;i++){
        _bloquesH[i].setTipo(2);
        _bloquesH[i].sety(posY);
        _bloquesH[i].setx(posX);

        if(i==7){ //PARA LOS DOS DE ABAJO
            posY=posY+getAlto()*3;
        }else{
            posY=posY+getAlto();
        }
        window.draw(_bloquesH[i]);

    }


    ///PARTE ARBUSTOS ARRIBA

    posY=getAlto()*5;
    posX=getAncho()*9;

    for(int i=0;i<6;i++){
        _bloquesA[i].setTipo(3);
        _bloquesA[i].sety(posY);
        _bloquesA[i].setx(posX);

        window.draw(_bloquesA[i]);
        posX=posX+getAncho();
    }

    ///PARTE ARBUSTOS ABAJO

    posX=getAncho()*9;
    posY=getAlto()*12;

    for(int i=6;i<12;i++){
        _bloquesA[i].setTipo(3);
        _bloquesA[i].sety(posY);
        _bloquesA[i].setx(posX);

         window.draw(_bloquesA[i]);
        posX=posX+getAncho();
    }

    ///BLOQUES LADRILLO PUNTAS

    _bloquesL[139].setx(getAncho()*9);
    _bloquesL[139].sety(getAlto()*8+getAlto()/2);
    _bloquesL[140].setx(getAncho()*14);
    _bloquesL[140].sety(getAlto()*8+getAlto()/2);
    if(_bloquesL[139].getEstado()){window.draw(_bloquesL[139]);}
    if(_bloquesL[140].getEstado()){window.draw(_bloquesL[140]);}

}

void Mapa::dibujarMapa(sf::Event &event,sf::RenderWindow &window){

    dibujarLimites(event,window);
    dibujarCostados(event,window);
    dibujarCentro1(event,window);
    dibujarCentro2(event,window);

}


#endif // MAPA_H_INCLUDED

