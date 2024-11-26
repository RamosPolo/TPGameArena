#include <SFML/Graphics.hpp>

#include "Bonus/Bonus.h"
#include "Bonus/BonusFactory.h"
#include "./character/player/Bullet.h"
#include "./character/player/Player.h"
#include "./character/monster/Monster.h"


#include "Obstacles/Obstacle.h"
#include "Obstacles/ObstacleFactory.h"
#include "WorkingFile/CollisionManager.h"

using namespace sf;
 
class Engine
{
private:
 
    // A regular RenderWindow
    RenderWindow m_Window;  
 
    // Declare a sprite and a Texture for the background
    Sprite m_BackgroundSprite;
    Texture m_BackgroundTexture;

    // texture des bullets
    Texture m_BulletTexture;
    Texture m_BulletTextureFire;
    Texture m_BulletTextureSnow;

    // texture bonus
    Texture m_bonusTextureFire;
    Texture m_bonusTextureSnow;
    Texture m_bonusTextureDefault;

    // texture characters
    Texture m_EnemiesTexture;


    std::vector<Monster> m_Enemies;

    // Collisions
    CollisionManager m_CollisionManager;


    // listes des bullets
    std::vector<Bullet> bullets;

    // Slot Bonus du joueur
    Bonus m_bonus;
    std::vector<Bonus> bonuses;
    Clock m_BonusClock;
    Time spawnIntervalBonus = seconds(7.f); // 7 secondes

    // player
    Player m_Player = Player(400.f, 5);


    // les Obstacles
    ObstacleFactory m_ObstacleFactory;

    // bonus génerate
    BonusFactory m_BonusFactory;

    // Gérer le temps des projectiles
    Clock m_BulletClock;
    float m_BulletCooldown = 0.5f; // Modifier pour une fréquence de tir plus élever
 
    // Private functions for internal use only
    void input();
    void update(float dtAsSeconds);
    void draw();
    void addBullet(Bullet bullet);
    //void checkEnemyCollisions(); 
    //void resolveCollision(Monster &ennemi1, Monster &ennemi2);
 
public:
    // The Engine constructor
    Engine();
 
    void start();
 
};