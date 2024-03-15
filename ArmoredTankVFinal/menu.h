#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#define maxMenu 4


class Menu{
    private:
        int _opcion;
        sf::Font fuente;
        sf::Text mainMenu[maxMenu];
        sf::Sprite bala;
        sf::Texture textBala;

    public:
        Menu(float width, float height);

        void draw(sf::RenderWindow& window);
        void moverAbajo();
        void moverArriba();
        int getOpcion(){return _opcion;}

        ~Menu(){};

};

Menu::Menu(float width, float height){
    fuente.loadFromFile("Fuente/fuente.ttf");
    textBala.loadFromFile("Sprites/balitaD.png");

    ///PLAY

    mainMenu[0].setFont(fuente);
    mainMenu[0].setFillColor(sf::Color::Green);
    mainMenu[0].setString("Play");
    mainMenu[0].setScale(0.5,0.5);
    mainMenu[0].setPosition(370,280);

    ///CONTROLES
    mainMenu[1].setFont(fuente);
    mainMenu[1].setFillColor(sf::Color::White);
    mainMenu[1].setString("Controles");
    mainMenu[1].setScale(0.5,0.5);
    mainMenu[1].setPosition(335,330);

    ///PUNTAJE

    mainMenu[2].setFont(fuente);
    mainMenu[2].setFillColor(sf::Color::White);
    mainMenu[2].setString("Puntajes");
    mainMenu[2].setScale(0.5,0.5);
    mainMenu[2].setPosition(342,380);

    ///SALIR

    mainMenu[3].setFont(fuente);
    mainMenu[3].setFillColor(sf::Color::White);
    mainMenu[3].setString("Salir");
    mainMenu[3].setScale(0.5,0.5);
    mainMenu[3].setPosition(362,430);

    _opcion=0;

    ///SPRITE BALA
    bala.setTexture(textBala);
    bala.setPosition(mainMenu[0].getPosition().x-60, mainMenu[0].getPosition().y-20);
    bala.setScale(0.5,0.5);

}

void Menu::draw(sf::RenderWindow& window){

    for(int i=0;i<maxMenu;i++){
        window.draw(mainMenu[i]);
    }

    window.draw(bala);
}

void Menu::moverArriba(){

    if(_opcion-1 >=0){
        mainMenu[_opcion].setFillColor(sf::Color::White);

        _opcion--;
        if(_opcion==-1){
            _opcion=3;
        }
        mainMenu[_opcion].setFillColor(sf::Color::Green);
        bala.setPosition(mainMenu[_opcion].getPosition().x-60, mainMenu[_opcion].getPosition().y-20);
    }
}


void Menu::moverAbajo(){

    if(_opcion+1 <= maxMenu){
        mainMenu[_opcion].setFillColor(sf::Color::White);

        _opcion++;

        if(_opcion==maxMenu){
            _opcion=0;
        }
        mainMenu[_opcion].setFillColor(sf::Color::Green);
        bala.setPosition(mainMenu[_opcion].getPosition().x-60, mainMenu[_opcion].getPosition().y-20);
    }
}

void mostrarControles(sf::RenderWindow &window);



void modo1(sf::RenderWindow& window, sf::RectangleShape& fondo, sf::Font &fuente, sf::Text &t1);

void modo2(sf::RenderWindow& window, sf::RectangleShape& fondo, sf::Font &fuente, sf::Text &t1, sf::Text &t2);

void setModos(sf::Font &fuente, sf::Text *text);

int elegirModo(sf::RenderWindow &window, int &vol);


void mainMenu(){

    sf::RenderWindow MENU(sf::VideoMode(800, 500), "ArmoredTanks-Menu");
    MENU.setFramerateLimit(60);
    Menu menu(MENU.getSize().x, MENU.getSize().y);
    sf::RectangleShape fondo;
    fondo.setSize(sf::Vector2f(800,500));
    sf::Texture textura;
    textura.loadFromFile("Menu/fondoVol.png");

    int vol=0;

    sf::Music music;
    if (!music.openFromFile("Musica/musicaMenu.ogg")) return; ///ABRE EL ARCHIVO, CUANDO ES MUSICA NO LO CARGA
    music.setVolume(100.f);
    music.setLoop(true);
    music.play();

    while(MENU.isOpen()){

        sf::Event event;

        while(MENU.pollEvent(event)){

            if(event.type == sf::Event::Closed){
                MENU.close();
            }
            if(event.type == sf::Event::KeyPressed){
                if(event.key.code == sf::Keyboard::Escape){
                    MENU.close();
                }
            }

            if(event.type == sf::Event::KeyReleased){

                if(event.key.code == sf::Keyboard::Up){
                    menu.moverArriba();
                    break;
                }

                if(event.key.code == sf::Keyboard::Down){
                    menu.moverAbajo();
                    break;
                }

                if(event.key.code==sf::Keyboard::M){
                    if(vol==0){
                        vol=1;
                    }else if(vol==1){vol=2;}
                }
            }
        }


        if(event.key.code == sf::Keyboard::Return){
            sf::RenderWindow Play(sf::VideoMode(800, 500), "ArmoredTanks");
            sf::RenderWindow Controles(sf::VideoMode(800,500), "Controles");
            sf::RenderWindow Puntajes(sf::VideoMode(800,500), "Puntajes");

            int x=menu.getOpcion();

            if(x==0){

                Controles.close();
                Puntajes.close();
                music.pause();
                vol=elegirModo(Play,vol);

            }

            if(x == 1){

                Play.close();
                Puntajes.close();
                mostrarControles(Controles);
            }

            if(x == 2){

                Play.close();
                Controles.close();
                mostrarPuntajes(Puntajes);
            }

            if(x == 3){
                MENU.close();
                break;
            }
        }

        if(vol==1){
            textura.loadFromFile("Menu/fondoSinVol.png");
            music.pause();
        }else if(vol==2){
            textura.loadFromFile("Menu/fondoVol.png");
           // music.setLoop(true);
            music.play();
            vol=0;
        }

        MENU.clear();
        fondo.setTexture(&textura);
        MENU.draw(fondo);
        menu.draw(MENU);
        MENU.display();
    }

}


void mostrarControles(sf::RenderWindow &window){

    sf::RectangleShape fondoC;
    fondoC.setSize(sf::Vector2f(800,500));
    sf::Texture texturaC;
    texturaC.loadFromFile("Menu/fondoControles.png");
    fondoC.setTexture(&texturaC);

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

        window.clear();
        window.draw(fondoC);
        window.display();
    }

}

void setModos(sf::Font &fuente, sf::Text *text){
    text[0].setFont(fuente);
    text[0].setFillColor(sf::Color::Green);
    text[0].setString("1 JUGADOR");
    text[0].setScale(0.8,0.8);
    text[0].setPosition(280,250);

    text[1].setFont(fuente);
    text[1].setFillColor(sf::Color::White);
    text[1].setString("1 VS 1");
    text[1].setScale(0.8,0.8);
    text[1].setPosition(340,350);
}

int elegirModo(sf::RenderWindow &window, int &vol){

    sf::RectangleShape fondoM;
    fondoM.setSize(sf::Vector2f(800,500));
    sf::Texture texturaM;
    texturaM.loadFromFile("Menu/fondoModo.png");
    fondoM.setTexture(&texturaM);

    sf::Font fuente;
    fuente.loadFromFile("Fuente/fuente.ttf");
    sf::Text modos[2];
    setModos(fuente, modos);

    sf::Texture textBala;
    sf::Sprite bala;
    textBala.loadFromFile("Sprites/balitaD.png");
    bala.setTexture(textBala);
    bala.setPosition(modos[0].getPosition().x-60, modos[0].getPosition().y-10);
    bala.setScale(0.5,0.5);

    int opc=0;

    while(window.isOpen()){

        sf::Event eventoA;

        while(window.pollEvent(eventoA)){
            if(eventoA.type == sf::Event::Closed){
                window.close();
                vol=2;
                return vol;
            }
            if(eventoA.type == sf::Event::KeyPressed){
                if(eventoA.key.code == sf::Keyboard::Escape){
                    window.close();
                    vol=2;
                    return vol;
                }
            }

            if(eventoA.type == sf::Event::KeyReleased){

                if(eventoA.key.code == sf::Keyboard::Up){
                    if(opc-1 >=0){
                        modos[opc].setFillColor(sf::Color::White);
                        opc--;
                        if(opc==-1){
                            opc=1;
                        }
                        modos[opc].setFillColor(sf::Color::Green);
                        bala.setPosition(modos[opc].getPosition().x-60, modos[opc].getPosition().y-10);
                    }

                    break;
                }

                if(eventoA.key.code == sf::Keyboard::Down){
                    if(opc+1 <= 2){
                        modos[opc].setFillColor(sf::Color::White);
                        opc++;
                        if(opc==2){
                            opc=0;
                        }
                        modos[opc].setFillColor(sf::Color::Green);
                        bala.setPosition(modos[opc].getPosition().x-60, modos[opc].getPosition().y-10);
                    }

                    break;
                }
             }

        }

        if(eventoA.key.code == sf::Keyboard::Return){
            sf::RectangleShape fondoN;
            fondoN.setSize(sf::Vector2f(800,500));
            fondoN.setTexture(&texturaM);

            if(opc==0){
                texturaM.loadFromFile("Menu/fondoNombre1.png");
                sf::Text t;

                modo1(window,fondoN,fuente,t);
                const char* c=t.getString().toAnsiString().c_str();
                vol=mainModo1Jug(window,c,vol);

            }else if(opc==1){
                texturaM.loadFromFile("Menu/fondoNombre2.png");
                sf::Text t1,t2;

                modo2(window,fondoN,fuente,t1,t2);
                const char* c=t1.getString().toAnsiString().c_str();
                const char* c2=t2.getString().toAnsiString().c_str();
                vol=mainModo2jug(window,c,c2, vol);
            }

        }

        window.clear();

        window.draw(fondoM);
        window.draw(modos[0]);
        window.draw(modos[1]);
        window.draw(bala);

        window.display();

    }

    return vol;

}

void modo1(sf::RenderWindow& window, sf::RectangleShape& fondo, sf::Font &fuente, sf::Text &t1){
    sf::String input;

    sf::RectangleShape r1(sf::Vector2f(250.f,40.f));

    r1.setPosition(280,280);
    r1.setFillColor(sf::Color{200,200,200,255});
    r1.setOutlineColor(sf::Color{255,20,0});
    r1.setOutlineThickness(2.0f);

    t1.setFont(fuente);
    t1.setPosition(290,290);
    t1.setFillColor(sf::Color::Black);
    t1.setScale(0.8,0.8);

    sf::Event event;
    int b=0;

    while(window.isOpen()){

        while(window.pollEvent(event)){

            if(event.type == sf::Event::Closed){
                window.close();
            }
            if(event.type == sf::Event::KeyPressed){
                if(event.key.code == sf::Keyboard::Escape){
                    window.close();
                }
            }

            if (event.type == sf::Event::TextEntered){
                if(event.text.unicode < 128){

                    if(event.text.unicode == 13){
                        b=1;
                    }
                    if(b==0){
                        if(event.text.unicode == 8 && input.getSize() > 0){
                            input.erase(input.getSize()-1,1);
                        }else{
                            input += static_cast<char>(event.text.unicode);
                        }
                    }

                    t1.setString(input);
                }

            }
        }

        if(event.key.code == sf::Keyboard::Return){
            if(b==1){
                return;
            }
        }

        window.clear();
        window.draw(fondo);
        window.draw(r1);
        window.draw(t1);
        window.display();

    }

}

void modo2(sf::RenderWindow& window, sf::RectangleShape& fondo, sf::Font &fuente, sf::Text &t1, sf::Text &t2){

    sf::String input, input2;

    sf::RectangleShape r1(sf::Vector2f(250.f,40.f));
    sf::RectangleShape r2(sf::Vector2f(250.f,40.f));
    r1.setPosition(100,280);
    r1.setFillColor(sf::Color{200,200,200,255});
    r1.setOutlineColor(sf::Color{255,20,0});
    r1.setOutlineThickness(2.0f);

    r2.setPosition(480,280);
    r2.setFillColor(sf::Color{200,200,200,255});
    r2.setOutlineColor(sf::Color{255,20,0});
    r2.setOutlineThickness(2.0f);

    t1.setFont(fuente);
    t1.setPosition(110,290);
    t1.setFillColor(sf::Color::Black);
    t1.setScale(0.8,0.8);

    t2.setFont(fuente);
    t2.setPosition(490,290);
    t2.setFillColor(sf::Color::Black);
    t2.setScale(0.8,0.8);

    sf::Event event;
    int b=0;

    while(window.isOpen()){

        while(window.pollEvent(event)){

            if(event.type == sf::Event::Closed){
                window.close();
            }
            if(event.type == sf::Event::KeyPressed){
                if(event.key.code == sf::Keyboard::Escape){
                    window.close();
                }
            }

            if (event.type == sf::Event::TextEntered){
                if(event.text.unicode < 128){

                    if(event.text.unicode == 13){
                        if(b==1){b=2;}
                        else{b=1;};
                    }
                    if(b==0){
                        if(event.text.unicode == 8 && input.getSize() > 0){
                            input.erase(input.getSize()-1,1);
                        }else{
                            input += static_cast<char>(event.text.unicode);
                        }
                    }else if(b==1){
                        if(event.text.unicode == 8 && input.getSize() > 0){
                            input2.erase(input.getSize()-1,1);
                        }else{
                            input2 += static_cast<char>(event.text.unicode);
                            cout<<"TEXTO2"<<endl;
                        }
                    }
                    t1.setString(input);
                    t2.setString(input2);
                }

            }
        }

        if(event.key.code == sf::Keyboard::Return){
            if(b==2){
                return;
            }
        }

        window.clear();
        window.draw(fondo);
        window.draw(r1);
        window.draw(r2);
        window.draw(t1);
        window.draw(t2);
        window.display();

    }

}


#endif // MENU_H_INCLUDED
