#include <SFML/Graphics.hpp>

#include "Bonus/Bonus.h"
#include "Bonus/BonusFactory.h"
#include "./character/player/Bullet.h"
#include "./character/player/Player.h"
#include "./character/monster/Monster.h"


#include "Obstacles/Obstacle.h"
#include "Obstacles/ObstacleFactory.h"
#include "WorkingFile/CollisionManager.h"

#include "./character/Barvie.h"

using namespace sf;
 
class Engine
{
private:
 
    // A regular RenderWindow
    RenderWindow m_Window;  


    // Score et temps de jeu
    int p_Score = 0;  
    sf::Clock j_timePlay;
    void DisplayScore();

 
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



    //Monster
    std::vector<Monster> m_Enemies;
    bool isCollisionBetweenMonsters(const Monster& m1, const Monster& m2);
    void updateEnemies(float dtAsSeconds, unsigned int windowWidth, unsigned int windowHeight);


    // player
    Player m_Player = Player(400.0f, 5);
    Barvie b_barvie = Barvie();
    void updatePlayer(float dtAsSeconds, int windowWidth, int windowHeight);
    void handlePlayer(Event event);

    // Collisions
    CollisionManager m_CollisionManager;
    sf::Clock c_damageClock;



    // listes des bullets
    std::vector<Bullet> bullets;
    void updateBullets(float dtAsSeconds, int windowWidth, int windowHeight);
    void handleBullet();


    // Slot Bonus du joueur
    Bonus m_bonus;
    std::vector<Bonus> bonuses;
    Clock m_BonusClock;
    Time spawnIntervalBonus = seconds(7.f); // 7 secondes


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

    // les collisions
    void gererCollision();
    void CollisionHandler();

    void BonusHandler();

    Bullet createBullet(String t, float posJX, float posJY, float posMX, float posMY);

    //void checkEnemyCollisions();
    //void resolveCollision(Monster &ennemi1, Monster &ennemi2);
 
public:
    // The Engine constructor
    Engine();
 
    void start();
 
};