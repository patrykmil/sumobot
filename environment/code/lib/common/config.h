#pragma once
#define FRONT_LINE_SENSOR 0
#define BACK_LINE_SENSOR 0
#define DEBUG 0

struct SumoConfig {
    int scanSpeed = 80;
    int attackSpeed = 255;
    int flipSpeed = 200;
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
