#include "Enemy.h"

Enemy::Enemy() {
    this->x = 10;
    this->y = 10;
    this->health = 10;
    this->speed = 1000;
}

Enemy::Enemy(int x, int y, int maxHealth, int speed, Path* path, int* player_hp, int* money) {
    this->x = x;
    this->y = y;
    this->player_hp = player_hp;
    this-> money = money;
    this->maxHealth = maxHealth;
    this->health = this->maxHealth;
    this->speed = speed;
    this->path = path;
    this->clock = new Clock(speed);
}

Enemy::~Enemy() {
    // Destructor implementation
}

int Enemy::getX() {
    return x;
}

int Enemy::getY() {
    return y;
}

void Enemy::setX(int sX) {
    x = sX;
}

void Enemy::setY(int sY) {
    y = sY;
}

int Enemy::getHealth() {
    return health;
}

int Enemy::getMaxHealth(){
	return maxHealth;
}

void Enemy::setHealth(int h) {
    health = h;
}

void Enemy::setSpeed(int sp) {
    speed = sp;
}

void Enemy::changeColour() {
    float percent = health;
}

void Enemy::move() {
    if (clock->time_passed() && step < path->no_turns) {

        if (path->getPointX(step) == x && path->getPointY(step) == y) {
            step++;
        }
        if (path->getPointX(step) > x) {
            x++;
        }
        else if (path->getPointX(step) < x) {
            x--;
        }
        else if (path->getPointY(step) < y) {
            y--;
        }
        else if (path->getPointY(step) > y) {
            y++;
        }
    }
}

void Enemy::update() {
    move();
    if(health <= 0){
    	if(alive == true){
    		*money += 10;
		}
    	alive = false;
	}
    
    if (step >= path->no_turns) {
        if (alive == true) {
            *player_hp -= 2;
        }
        alive = false;
    }
}

void Enemy::draw() {
    // Draw implementation
}





