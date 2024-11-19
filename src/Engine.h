#include <SFML/Graphics.hpp>

#include "Bullet.h"
#include "Player.h"
 
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

    // Gérer le temps des projectiles
    Clock m_BulletClock;
    float m_BulletCooldown = 0.5f; // Modifier pour une fréquence de tir plus élever
 
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