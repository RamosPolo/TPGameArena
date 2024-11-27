#include "Bullet.h"
#include <complex>

Bullet::Bullet() {
    this->dammage = 5;
    // Initialiser la vitesse
    this->b_speed = 500;
}

/*
Sprite* Bullet::getSprite() {
    return &this->b_Sprite;
}
*/

void Bullet::setTextureBullet(const Texture &t) {
    this->getSprite()->setTexture(t);
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
    this->getSprite()->setPosition(b_position.x, b_position.y);
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

// FIRE BULLET
FireBullet::FireBullet(){
    this->dammage = 10;
    this->b_Texture.loadFromFile("../assets/image/fireBullet.png");
    this->b_Sprite.setTexture(b_Texture);
    // Initialiser la vitesse
    this->b_speed = 550;
}

SnowBullet::SnowBullet() {
    this->dammage = 7;
    this->b_Texture.loadFromFile("../assets/image/snowBall.png");
    this->b_Sprite.setTexture(b_Texture);
    // Initialiser la vitesse
    this->b_speed = 470;
}

