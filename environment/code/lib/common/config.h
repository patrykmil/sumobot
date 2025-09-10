#pragma once

struct SumoConfig {
    int normalSpeed = 120;
    int attackSpeed = 255;
    int scanSpeed = 60;
    int lineColor = 1;  // 0 for white line, 1 for black line
    int enemyDetectionDistance = 25;
    int closeEnemyDistance = 10;
    unsigned long scanTimeout = 3000;
    unsigned long retreatDelay = 300;
};

enum SumoState {
    SCANNING,
    ATTACKING,
    RETREATING,
};
