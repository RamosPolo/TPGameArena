#include <SFML/Graphics.hpp>

#include "Bullet.h"
#include "Character.h"
 
using namespace sf;
 
class Engine
{
private:
 
    // A regular RenderWindow
    RenderWindow m_Window;  
 
    // Declare a sprite and a Texture for the background
    Sprite m_BackgroundSprite;
    Texture m_BackgroundTexture;
 
    // An instance of Character
    Character m_Character;

    // listes des bullets
    std::vector<Bullet> bullets;
 
    // Private functions for internal use only
    void input();
    void update(float dtAsSeconds);
    void draw();
    void addBullet(Bullet bullet);
 
public:
    // The Engine constructor
    Engine();
 
    void start();
 
};