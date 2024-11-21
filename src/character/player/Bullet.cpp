#include "Bullet.h"
#include <complex>

Bullet::Bullet() {
    // Charger la texture
    b_Texture.loadFromFile("./assets/image/bullet.png");
    b_Sprite.setTexture(b_Texture);
    b_Sprite.setTextureRect(IntRect(0, 0, b_Texture.getSize().x, b_Texture.getSize().y));

    // Initialiser la vitesse
    b_speed = 500;
}

Sprite Bullet::getSprite() {
    return b_Sprite;
}

void Bullet::setPosition(float x, float y) {
    b_position.x = x;
    b_position.y = y;
}

void Bullet::move(float elapsedTime) {
    // Déplacement basé sur la direction et la vitesse
    b_position.x += b_direction.x * b_speed * elapsedTime;
    b_position.y += b_direction.y * b_speed * elapsedTime;

    // Mettre à jour la position du sprite
    b_Sprite.setPosition(b_position.x, b_position.y);
}

void Bullet::setTarget(float x, float y) {
    b_target.x = x;
    b_target.y = y;

    // Calcul du vecteur direction
    b_direction.x = b_target.x - b_position.x;
    b_direction.y = b_target.y - b_position.y;

    // Normalisation du vecteur direction
    float magnitude = std::sqrt(b_direction.x * b_direction.x + b_direction.y * b_direction.y);
    if (magnitude != 0) {
        b_direction.x /= magnitude;
        b_direction.y /= magnitude;
    }
}

bool Bullet::isOutOfBounds(unsigned int windowWidth, unsigned int windowHeight) const {
    // Récupérer la position actuelle du projectile
    float x = b_position.x;
    float y = b_position.y;

    // Vérifier si le projectile est hors des limites de la fenêtre
    return (x < 0 || x > windowWidth || y < 0 || y > windowHeight);
}
