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
#include "./character/monster/SpawnerMonster.h"
#include "Menu/GameOver.h"
#include "Menu/Menu.h"

#include <SFML/Audio.hpp>


using namespace sf;
 
class Engine
{
private:
 
    // A regular RenderWindow
    RenderWindow m_Window;

    // Menu du jeu
    Texture m_TextureButtonMenu;
    Texture m_TextureMenuBackground;
    Menu m_Menu;
    GameOver m_GameOver;
    bool m_playing = false;
    bool game_over = false;


    // Score et temps de jeu
    int p_Score = 0;  
    sf::Clock j_timePlay;
    sf::Clock t_timeWave;
    float m_FinalTimePlay = 0;

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

    // music
    sf::Music m_BackgroundMusic;
    void startMusic();


    //Monster
    SpawnerMonster sm_SpawnerMonster;
    std::vector<Monster> m_Enemies;
    int m_NumWave = 0;
    bool isCollisionBetweenMonsters(const Monster& m1, const Monster& m2);
    void updateEnemies(float dtAsSeconds, unsigned int windowWidth, unsigned int windowHeight);
    void updateWave();


    // player
    Player m_Player = Player(400.0f, 5, 0.4f);
    Barvie b_barvie = Barvie(m_Player);
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
    float m_BulletCooldown = 0.3f; // Modifier pour une fréquence de tir plus élever
 
    // Private functions for internal use only
    void input();
    void update(float dtAsSeconds);
    void draw();
    void addBullet(Bullet bullet);

    // les collisions
    void gererCollision();
    void CollisionHandler();

    void BonusHandler();

    void DisplayScore();

    void HandleGameOver();

    void drawGameOver();

    void drawMenuStart();

    Bullet createBullet(String t, float posJX, float posJY, float posMX, float posMY);

    //void checkEnemyCollisions();
    //void resolveCollision(Monster &ennemi1, Monster &ennemi2);
 
public:
    // The Engine constructor
    Engine();
 
    void start();
};