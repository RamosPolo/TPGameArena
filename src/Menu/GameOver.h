//
// Created by PC on 28/11/2024.
//

#ifndef GAMEOVER_H
#define GAMEOVER_H

#include <SFML/Graphics.hpp>

using namespace sf;

class GameOver {
private:
    // sprites et textures
    Texture GO_BackgroundTexture;
    Sprite GO_BackgroundSprite;

    // position du Game Over
    Vector2f menu_position;

    // font du texte
    Text Title_text;
    Text result_text;
    Font menu_font;
public:
    void setGameOver(int WsizeX, int WsizeY);
    void setTitle(int WsizeX, int WsizeY);
    void setContent(int WsizeX, int WsizeY);
    void setTexte(String txt);
    Sprite *getSpriteBackgroundGO();
    void setTextureBGGO(const Texture &t);
    Text getTitle();
    Text getContent();
};



#endif //GAMEOVER_H
