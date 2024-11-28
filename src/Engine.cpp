#include "Engine.h"

#include "./character/player/Bullet.h"
#include "Obstacles/Obstacle.h"
#include "./character/Barvie.h"

#include <cmath> 

Engine::Engine() {
    // Get the screen resolution and create an SFML window and View
    Vector2f resolution;
    resolution.x = VideoMode::getDesktopMode().width;
    resolution.y = VideoMode::getDesktopMode().height;

    m_Window.create(VideoMode(resolution.x, resolution.y),
                    "Simple Game Engine",
                    Style::Fullscreen);

    m_Window.setFramerateLimit(50);

    // Set le Menu
    m_TextureButtonMenu.loadFromFile("../assets/image/start_button.png");
    m_TextureMenuBackground.loadFromFile("../assets/image/MenuBackground.png");
    m_Menu.setTextureButton(m_TextureButtonMenu);
    m_Menu.setTextureBackground(m_TextureMenuBackground);
    m_Menu.setMenu(m_Window.getSize().x, m_Window.getSize().y);


    // background
    m_BackgroundTexture.loadFromFile("../assets/image/arena_steamPunk.png");
    m_BackgroundSprite.setTexture(m_BackgroundTexture);

    // texture des balles
    m_BulletTexture.loadFromFile("../assets/image/bullet.png");
    m_BulletTextureFire.loadFromFile("../assets/image/fireBullet.png");
    m_BulletTextureSnow.loadFromFile("../assets/image/snowBall.png");

    // texture des bonus
    m_bonusTextureDefault.loadFromFile("../assets/image/defaultRing.png");
    m_bonusTextureFire.loadFromFile("../assets/image/fireRing.png");
    m_bonusTextureSnow.loadFromFile("../assets/image/snowRing.png");
    m_EnemiesTexture.loadFromFile("../assets/image/Golem/Walking.png");

    m_BonusFactory = BonusFactory();

    m_EnemiesTexture.loadFromFile("./assets/image/Golem/Walking.png");
}

void Engine::start()
{
    // Timing
    Clock clock;
 
    while (m_Window.isOpen())
    {
        // Restart the clock and save the elapsed time into dt
        Time dt = clock.restart();

        // Make a fraction from the delta time
        float dtAsSeconds = dt.asSeconds();
 
        input();
        update(dtAsSeconds);
        draw();
    }
}

void Engine::input() {
    
    Event event;

    handlePlayer(event);
    handleBullet();
    CollisionHandler();
}

void Engine::update(float dtAsSeconds)
{
    unsigned int windowWidth = m_Window.getSize().x;
    unsigned int windowHeight = m_Window.getSize().y;

    gererCollision();

    if (m_Enemies.size() == 0 && m_NumWave < 5  ) {
        m_Enemies = sm_SpawnerMonster.generateWave(m_NumWave);
        m_NumWave = m_NumWave + 1;
    }


    updatePlayer(dtAsSeconds, windowWidth, windowHeight);
    updateEnemies(dtAsSeconds, windowWidth, windowHeight);
    updateBullets(dtAsSeconds, windowWidth, windowHeight);

}


void Engine::draw()
{
    // Rub out the last frame
    m_Window.clear(Color::White);

    // Draw the background
    m_Window.draw(m_BackgroundSprite);

    if(!m_Menu.isPlaying()) {
        // draw le menu
        m_Window.draw(*m_Menu.getSpriteBackground());
        m_Window.draw(*m_Menu.getSpriteButton());
    } else {
        // draw le joueur
        if (!m_Player.isDestroyed()) {
            m_Window.draw(*m_Player.getSprite());
        }

        for (auto &ennemi : m_Enemies) {
            m_Window.draw(*ennemi.getSprite());
        }

        // draw les projectiles
        for(auto & bullet : bullets) {
            m_Window.draw(*bullet.getSprite());
        }

        for (auto & bonus : bonuses) {
            m_Window.draw(*bonus.getSprite());
        }

        m_Window.draw(b_barvie.getRectangle());

        DisplayScore();
    }
    // Show everything we have just drawn
    m_Window.display();
}

void Engine::handlePlayer(Event event){
        while (m_Window.pollEvent(event)) // Gestion des événements
    {
        if (event.type == Event::Closed || Keyboard::isKeyPressed(Keyboard::Escape))
        {
            m_Window.close();
        }
    }

    if(Mouse::isButtonPressed(Mouse::Left)) {
        if(m_Menu.isButtonClicked(Mouse::getPosition().x, Mouse::getPosition().y)) {
            m_Menu.Play();
        }
    }
 
    // Handle the player moving
    if (Keyboard::isKeyPressed(Keyboard::Q))
    {
        m_Player.moveLeft();
    }
    else
    {
        m_Player.stopLeft();
    }
 
    if (Keyboard::isKeyPressed(Keyboard::D))
    {
        m_Player.moveRight();
    }
    else
    {
        m_Player.stopRight();
    }
    if(Keyboard::isKeyPressed(Keyboard::Z)) {
        m_Player.moveTop();
    }
    else {
        m_Player.stopTop();
    }

    if(Keyboard::isKeyPressed(Keyboard::S)) {
        m_Player.moveDown();
    }
    else {
        m_Player.stopDown();
    }

}

void Engine::handleBullet(){
    if( (Mouse::isButtonPressed(Mouse::Left)
        || Keyboard::isKeyPressed(Keyboard::Space))
        && m_BulletClock.getElapsedTime().asSeconds() >= m_BulletCooldown) {

        addBullet(createBullet(this->m_bonus.getTypeBonus(), m_Player.getPositionX(), m_Player.getPositionY(), Mouse::getPosition().x, Mouse::getPosition().y));
        m_BulletClock.restart();
    }

    if (m_BonusClock.getElapsedTime() >= spawnIntervalBonus) {
        BonusHandler();
    }
}

void Engine::addBullet(Bullet bullet) {
    bullets.emplace_back(bullet);
}

void Engine::gererCollision() {
    // gérer collsion avec les bullets
    bullets.erase(std::remove_if(bullets.begin(), bullets.end(), [](const Bullet& tir) {
            return tir.isDestroyed();
        }), bullets.end());


    // gérer collision avec les monstres
    m_Enemies.erase(std::remove_if(m_Enemies.begin(), m_Enemies.end(), [](const Monster& m) {
            return m.isDestroyed();
        }), m_Enemies.end());


    // gérer collision avec les monstres
    bonuses.erase(std::remove_if(bonuses.begin(), bonuses.end(), [](const GameObject& m) {
            return m.isDestroyed();
        }), bonuses.end());
}

void Engine::CollisionHandler() {
    // collisions entre Ennemmies et Projectiles
    for (auto &tir: bullets) {
        for (auto& ennemi : m_Enemies) {
            if (tir.getSprite()->getGlobalBounds().intersects(ennemi.getSprite()->getGlobalBounds())) {
                if(ennemi.getLife() - tir.demage() <= 0) {
                    ennemi.destroy();
                    p_Score += 10;
                } else {
                    ennemi.getDemage(tir.demage());
                }
                tir.destroy();
            }
        }
    }

    // collisions entre Bonus et Joueur
    for (auto& b : bonuses) {
        if (m_Player.getSprite()->getGlobalBounds().intersects(b.getSprite()->getGlobalBounds())) {
            m_bonus = b;
            b.destroy();
        }
    }

    for (auto& b : m_Enemies) {
        if (m_Player.getSprite()->getGlobalBounds().intersects(b.getSprite()->getGlobalBounds())) {
            if (c_damageClock.getElapsedTime().asSeconds() >= 1.0f) {
                if(m_Player.getLife() >= 1){
                    m_Player.getDemage(1); 
                    if (m_Player.getLife() == 0) {
                        m_Player.destroy();
                    } else {
                        c_damageClock.restart(); 
                    }
                }
            }
        }
    }

}

void Engine::BonusHandler() {
    Bonus b = m_BonusFactory.createRandomBonus();
    if(b.getTypeBonus() == "default") {
        b.setTextureBonus(m_bonusTextureDefault);
    }
    if(b.getTypeBonus() == "fire") {
        b.setTextureBonus(m_bonusTextureFire);
    }
    if(b.getTypeBonus() == "snow") {
        b.setTextureBonus(m_bonusTextureSnow);
    }
    b.getSprite()->scale(Vector2f(0.3f, 0.3f));
    b.positionnerBonus();
    bonuses.push_back(b);
    m_BonusClock.restart();
}

Bullet Engine::createBullet(String t, float posJX, float posJY, float posMX, float posMY) {
    Bullet bul;
    if(t == "default") {
        bul = DefaultBullet();
        bul.setTextureBullet(m_BulletTexture);
    }
    if(t == "fire") {
        bul = FireBullet();
        bul.getSprite()->scale(Vector2f(0.06f, 0.06f));
        bul.setTextureBullet(m_BulletTextureFire);
    }
    if(t == "snow") {
        bul = SnowBullet();
        bul.setTextureBullet(m_BulletTextureSnow);
        bul.getSprite()->scale(Vector2f(0.2f, 0.2f));
    }
    bul.setPosition(posJX, posJY);
    bul.setTarget(posMX, posMY);
    return bul;

}

bool Engine::isCollisionBetweenMonsters(const Monster& m1, const Monster& m2) {
    float x1 = m1.getPositionX();
    float y1 = m1.getPositionY();
    float width1 = m1.getSpriteWidth();
    float height1 = m1.getSpriteHeight();

    float x2 = m2.getPositionX();
    float y2 = m2.getPositionY();
    float width2 = m2.getSpriteWidth();
    float height2 = m2.getSpriteHeight();

    // Vérifier si les rectangles se chevauchent
    bool xOverlap = (x1 < x2 + width2) && (x1 + width1 > x2);
    bool yOverlap = (y1 < y2 + height2) && (y1 + height1 > y2);

    return xOverlap && yOverlap;
}

/////////////
// UPDATE //
////////////

void Engine::updateEnemies(float dtAsSeconds, unsigned int windowWidth, unsigned int windowHeight) {
    for (size_t i = 0; i < m_Enemies.size(); ++i) {
        // Mise à jour de chaque ennemi
        m_Enemies[i].update(dtAsSeconds, windowWidth, windowHeight, m_Player.getPositionX(), m_Player.getPositionY());

        // Vérification des collisions avec les autres ennemis
        for (size_t j = i + 1; j < m_Enemies.size(); ++j) {
            if (isCollisionBetweenMonsters(m_Enemies[i], m_Enemies[j])) {
                // Calcul de la direction et de la distance entre les deux monstres
                float dx = m_Enemies[j].getPositionX() - m_Enemies[i].getPositionX();
                float dy = m_Enemies[j].getPositionY() - m_Enemies[i].getPositionY();
                float distance = std::sqrt(dx * dx + dy * dy);

                if (distance > 0) {
                    // Normalisation du vecteur direction
                    float invDistance = 1.0f / distance;
                    float nx = dx * invDistance;
                    float ny = dy * invDistance;

                    // Éloignement des monstres pour éviter qu'ils se chevauchent
                    float overlap = 0.5f; // Facteur d'éloignement ajustable
                    m_Enemies[i].Move(-nx * overlap, -ny * overlap);
                    m_Enemies[j].Move(nx * overlap, ny * overlap);
                }
            }
        }
    }
}

void Engine::updatePlayer(float dtAsSeconds, int windowWidth, int windowHeight){
    m_Player.update(dtAsSeconds, windowWidth, windowHeight);
    b_barvie.update(m_Player);
}

// Mise à jour des projectiles
void Engine::updateBullets(float dtAsSeconds, int windowWidth, int windowHeight){
    auto it = bullets.begin();
    while (it != bullets.end()) {
        // on bouge le projectile
        it->move(dtAsSeconds);

        // Vérifiez si le projectile est hors de l'écran
        if (it->isOutOfBounds(windowWidth, windowHeight)) {
            it = bullets.erase(it); // Supprime le projectile
            } else {
                ++it;
            }
    }
}


void Engine::DisplayScore(){
    
    // Load font
    Font font;
    if (!font.loadFromFile("../assets/font/arial.ttf")) {
        // Handle font loading error
    }

    // Score display
    sf::Text scoreText;
    scoreText.setFont(font);
    scoreText.setString("Score: " + std::to_string(p_Score));
    scoreText.setCharacterSize(48);
    scoreText.setFillColor(sf::Color::White);
    scoreText.setPosition(m_Window.getSize().x - 300, 10);

    // Add black background rectangle for Score
    sf::RectangleShape scoreBackground(sf::Vector2f(scoreText.getLocalBounds().width + 20, scoreText.getLocalBounds().height + 30));
    scoreBackground.setFillColor(sf::Color::Black);
    scoreBackground.setPosition(scoreText.getPosition().x - 10, scoreText.getPosition().y - 5);
    m_Window.draw(scoreBackground);

    // Draw score text
    m_Window.draw(scoreText);

    // Time display
    float elapsedTime = j_timePlay.getElapsedTime().asSeconds();
    sf::Text timeText;
    timeText.setFont(font);
    timeText.setString("Time: " + std::to_string(static_cast<int>(elapsedTime)) + "s");
    timeText.setCharacterSize(48);
    timeText.setFillColor(sf::Color::White);
    timeText.setPosition(m_Window.getSize().x - 300, 90);

    // Add black background rectangle for Time
    sf::RectangleShape timeBackground(sf::Vector2f(timeText.getLocalBounds().width + 20, timeText.getLocalBounds().height + 30));
    timeBackground.setFillColor(sf::Color::Black);
    timeBackground.setPosition(timeText.getPosition().x - 10, timeText.getPosition().y - 5);
    m_Window.draw(timeBackground);

    // Draw time text
    m_Window.draw(timeText);

    // Wave display
    sf::Text waveText;
    waveText.setFont(font);
    waveText.setString("Vague: " + std::to_string(m_NumWave));
    waveText.setCharacterSize(48);
    waveText.setFillColor(sf::Color::White);
    waveText.setPosition(m_Window.getSize().x - 300, 170);

    // Add black background rectangle for Wave
    sf::RectangleShape waveBackground(sf::Vector2f(waveText.getLocalBounds().width + 20, waveText.getLocalBounds().height + 30));
    waveBackground.setFillColor(sf::Color::Black);
    waveBackground.setPosition(waveText.getPosition().x - 10, waveText.getPosition().y - 5);
    m_Window.draw(waveBackground);
    m_Window.draw(waveText);
}




