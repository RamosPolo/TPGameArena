#include "Engine.h"

#include "./character/player/Bullet.h"
#include "Obstacles/Obstacle.h"


Engine::Engine()
{
    // Get the screen resolution and create an SFML window and View
    Vector2f resolution;
    resolution.x = VideoMode::getDesktopMode().width;
    resolution.y = VideoMode::getDesktopMode().height;
 
    m_Window.create(VideoMode(resolution.x, resolution.y),
        "Simple Game Engine",
        Style::Fullscreen);
 
    m_Window.setFramerateLimit(25);

    // Load the background into the texture
    // Be sure to scale this image to your screen size
    m_BackgroundTexture.loadFromFile("../assets/image/arena_steamPunk.png");

    // Associate the sprite with the texture
    m_BackgroundSprite.setTexture(m_BackgroundTexture);
 
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
    while (m_Window.pollEvent(event)) // Gestion des événements
    {
        if (event.type == Event::Closed || Keyboard::isKeyPressed(Keyboard::Escape))
        {
            m_Window.close();
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

    if( (Mouse::isButtonPressed(Mouse::Left)
        || Keyboard::isKeyPressed(Keyboard::Space))
        && m_BulletClock.getElapsedTime().asSeconds() >= m_BulletCooldown) {

        // Les projectiles sont géreé ici
        Bullet bul;
        bul.setPosition(m_Player.getPositionX(), m_Player.getPositionY());
        float xMouse =  Mouse::getPosition().x;
        float yMouse =  Mouse::getPosition().y;
        bul.setTarget(xMouse, yMouse);
        addBullet(bul);

        // Réinitialise le chronomètre pour le tir
        m_BulletClock.restart();
    }
}

void Engine::draw()
{
    // Rub out the last frame
    m_Window.clear(Color::White);
 
    // Draw the background
    m_Window.draw(m_BackgroundSprite);

    m_Window.draw(m_Player.getSprite());
    m_Window.draw(m_Golem.getSprite());

    for(auto & bullet : bullets) {
        m_Window.draw(bullet.getSprite());
    }

    Obstacle obstacle;
    obstacle.setPosition(60,60);
    m_Window.draw(obstacle.getSprite());
 
    // Show everything we have just drawn
    m_Window.display();
}

void Engine::update(float dtAsSeconds)
{
    unsigned int windowWidth = m_Window.getSize().x;
    unsigned int windowHeight = m_Window.getSize().y;

    m_Player.update(dtAsSeconds, windowWidth, windowHeight);
    m_Golem.update(dtAsSeconds, windowWidth, windowHeight);


    // Mise à jour des projectiles
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

void Engine::addBullet(Bullet bullet) {
    bullets.emplace_back(bullet);
}

