//
// Created by PC on 28/11/2024.
//

#ifndef MENU_H
#define MENU_H
#include <SFML/Graphics.hpp>

using namespace sf;

class Menu {
private:
    // sprites et textures
    Texture menu_ButtonTexture;
    Sprite menu_ButtonSprite;
    Texture menu_BackgroundTexture;
    Sprite menu_BackgroundSprite;

    // positions des élements
    Vector2f menu_position;
    Vector2f menu_ButtonPosition;
public:
    Menu();
    void setMenu(int WsizeX, int WsizeY);
    void setTextureButton(const Texture &t);
    void setTextureBackground(const Texture &t);
    Sprite *getSpriteButton();
    Sprite *getSpriteBackground();
    bool isButtonClicked(float posXMouse, float posYMouse);
};



#endif //MENU_H
