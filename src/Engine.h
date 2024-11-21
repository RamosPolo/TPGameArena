#include <SFML/Graphics.hpp>

#include "./character/player/Bullet.h"
#include "./character/player/Player.h"
 
using namespace sf;
 
class Engine
{
private:
 
    // A regular RenderWindow
    RenderWindow m_Window;  
 
    // Declare a sprite and a Texture for the background
    Sprite m_BackgroundSprite;
    Texture m_BackgroundTexture;


    // listes des bullets
    std::vector<Bullet> bullets;
    Player m_Player;
 
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