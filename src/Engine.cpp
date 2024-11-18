#include "Engine.h"
 
Engine::Engine()
{
    // Get the screen resolution and create an SFML window and View
    Vector2f resolution;
    resolution.x = VideoMode::getDesktopMode().width;
    resolution.y = VideoMode::getDesktopMode().height;
 
    m_Window.create(VideoMode(resolution.x, resolution.y),
        "Simple Game Engine",
        Style::Fullscreen);
 
    m_Window.setFramerateLimit(60);

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
    // Handle the player quitting
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
        m_Character.moveLeft();
    }
    else
    {
        m_Character.stopLeft();
    }
 
    if (Keyboard::isKeyPressed(Keyboard::D))
    {
        m_Character.moveRight();
    }
    else
    {
        m_Character.stopRight();
    }
    if(Keyboard::isKeyPressed(Keyboard::Z)) {
        m_Character.moveTop();
    }
    else {
        m_Character.stopTop();
    }

    if(Keyboard::isKeyPressed(Keyboard::S)) {
        m_Character.moveDown();
    }
    else {
        m_Character.stopDown();
    }
}

void Engine::draw()
{
    // Rub out the last frame
    m_Window.clear(Color::White);
 
    // Draw the background
    m_Window.draw(m_BackgroundSprite);
    m_Window.draw(m_Character.getSprite());
 
    // Show everything we have just drawn
    m_Window.display();
}

void Engine::update(float dtAsSeconds)
{
    m_Character.update(dtAsSeconds);
}

