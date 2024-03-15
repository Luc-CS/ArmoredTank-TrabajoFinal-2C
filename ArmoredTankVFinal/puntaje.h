#ifndef PUNTAJE_H_INCLUDED
#define PUNTAJE_H_INCLUDED

class Puntaje{
private:
    char _nombre[30];
    int _puntos;

public:
    void setNombre(const char* n){strcpy(_nombre,n);};
    void setPuntos(int p){_puntos=p;};
    const char* getNombre(){return _nombre;};
    int getPuntos(){return _puntos;};

};

class ArchivoPuntajes{
    private:
        char _nombre[30];

    public:
        ArchivoPuntajes (const char *n="Puntajes.dat"){
            strcpy(_nombre,n);
        }

        void guardarPuntaje(Puntaje p);
        Puntaje leerRegistro(int pos);

};

void ArchivoPuntajes::guardarPuntaje(Puntaje p){
    FILE *pPuntajes;
    pPuntajes=fopen(_nombre,"ab");
    if(pPuntajes==nullptr){
        cout<<"ERROR ARCHIVO"<<endl;
        return;
    }

    fwrite(&p,sizeof(Puntaje),1,pPuntajes);

    fclose(pPuntajes);
}

Puntaje ArchivoPuntajes::leerRegistro(int pos){
    FILE *p;
    Puntaje pun;
    p=fopen(_nombre,"rb");

    if(p==NULL){
        cout<<"ERROR DE ARCHIVO";
        pun.setPuntos(-2);
        return pun;
    }

    fseek(p,pos*sizeof(pun),0);
    fread(&pun,sizeof(pun),1,p);

    fclose(p);
    return pun;
}

int compararPuntajes(Puntaje &p){
    ArchivoPuntajes arcP;
    Puntaje aux;

    for(int i=0;i<3;i++){
        aux=arcP.leerRegistro(i);
        if(p.getPuntos()>=aux.getPuntos()){
            return i;
        }
    }

    return -1;
}

void limpiarArchivo(const char *n){
    FILE *p;
    p=fopen(n,"wb");
    if(p==NULL){
        cout<<"ERROR EN LIMPIAR ARCHIVO"<<endl;
        return;
    }

    fclose(p);
}

void mejoresTres(Puntaje &p){
    Puntaje vecAux[3]={};
    int pos=compararPuntajes(p);
    if(pos==-1){return;}

    ArchivoPuntajes arcP;

    if(pos==0){
        vecAux[0]=p;
        vecAux[1]=arcP.leerRegistro(0);
        vecAux[2]=arcP.leerRegistro(1);
    }

    if(pos==1){
        vecAux[0]=arcP.leerRegistro(0);
        vecAux[1]=p;
        vecAux[2]=arcP.leerRegistro(1);
    }

    if(pos==2){
        vecAux[0]=arcP.leerRegistro(0);
        vecAux[1]=arcP.leerRegistro(1);
        vecAux[2]=p;
    }

    limpiarArchivo("Puntajes.dat");

    for(int i=0;i<3;i++){
        arcP.guardarPuntaje(vecAux[i]);
    }
}


void setTextos(sf::Font &font,sf::Text *v){
    v[0].setFont(font);
    v[0].setFillColor(sf::Color{255,69,0,200});
    v[0].setOutlineThickness(1);
    v[0].setOutlineColor(sf::Color{255,20,0});
    v[0].setScale(0.8,0.8);
    v[0].setPosition(260,175);

    v[1].setFont(font);
    v[1].setFillColor(sf::Color::White);
    v[1].setOutlineThickness(1);
    v[1].setOutlineColor(sf::Color{255,20,0});
    v[1].setScale(0.8,0.8);
    v[1].setPosition(260,280);

    v[2].setFont(font);
    v[2].setFillColor(sf::Color::White);
    v[2].setScale(0.8,0.8);
    v[2].setPosition(260,395);
}

void mostrarPuntajes(sf::RenderWindow& window){

    sf::RectangleShape fondoP;
    fondoP.setSize(sf::Vector2f(800,500));
    sf::Texture texturaP;
    texturaP.loadFromFile("Menu/fondoPuntajes.png");
    fondoP.setTexture(&texturaP);

    sf::Font fuente;
    fuente.loadFromFile("Fuente/fuente.ttf");
    sf::Text vecP[3];
    setTextos(fuente,vecP);

    ArchivoPuntajes arcP("Puntajes.dat");
    Puntaje aux;
    char cadAux[30];
    int p;

    while(window.isOpen()){

        sf::Event eventoA;

        while(window.pollEvent(eventoA)){
            if(eventoA.type == sf::Event::Closed){
                window.close();
            }
            if(eventoA.type == sf::Event::KeyPressed){
                if(eventoA.key.code == sf::Keyboard::Escape){
                    window.close();
                }
            }
        }


    for(int i=0;i<3;i++){
        aux=arcP.leerRegistro(i);
        p=aux.getPuntos();
        strcpy(cadAux,aux.getNombre());
        strcat(cadAux,"        ");
        vecP[i].setString(cadAux +  std::to_string(p));
    }

    window.clear();
    window.draw(fondoP);
    window.draw(vecP[0]);
    window.draw(vecP[1]);
    window.draw(vecP[2]);
    window.display();

    }

}

#endif // PUNTAJE_H_INCLUDED
