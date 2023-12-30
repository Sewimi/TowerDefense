#include "Wave.h"

Wave::Wave(Path* p, int* player_health) {
    this->player_health = player_health;
    this->path = p;
    enemies = new std::vector<Enemy>;
}

int Wave::get_wave() {
    return wave_number;
}

void Wave::update() {
    for (Enemy& enemy : *enemies) {
        enemy.update();
    }

    if (detect_end_of_wave()) {
        enemies->clear();
        init_wave(10, 1);
    }
}

bool Wave::detect_end_of_wave() {
    for (Enemy& enemy : *enemies) {
        if (enemy.alive == true) {
            return false;
        }
    }
    return true;
}

void Wave::init_wave(int num_of_enemies, int difficulty) {
    for (int i = 0; i < num_of_enemies; i++) {
        enemies->push_back(Enemy(20, 0 - 5 * i, 100, 100 + 5 * i, 2, path, player_health));
    }
}

void Wave::set_wave(int n) {
    wave_number = n;
}