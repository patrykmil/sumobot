#include <Arduino.h>
#include <move.h>
#include <phases.h>
#include <sensors.h>

void scan() {
    SPEED = config.scanSpeed;
    analogWrite(LEFT_PWM, SPEED);
    analogWrite(RIGHT_PWM, SPEED);

    if (DIRECTION > 0) {
        goRight();
    } else {
        goLeft();
    }

    DIRECTION = getEnemyDirection();
    if (DIRECTION != 0) {
        currentState = ATTACKING;
        stateStartTime = millis();
        return;
    }

    if (millis() - stateStartTime > config.scanTimeout) {
        goForward();
        delay(500);
        stop();
        DIRECTION *= -1;
        stateStartTime = millis();
    }
}

void attack() {
    SPEED = config.attackSpeed;
    analogWrite(LEFT_PWM, SPEED);
    analogWrite(RIGHT_PWM, SPEED);

    if (DIRECTION == 1) {
        goForward();
    } else if (DIRECTION == -1) {
        flip(-1);
        DIRECTION = 1;
        goForward();
    }

    float enemyDist = getDistanceFront();

    if (enemyDist > config.enemyDetectionDistance) {
        currentState = SCANNING;
        stateStartTime = millis();
    }
}

void retreat() {
    SPEED = config.scanSpeed;
    analogWrite(LEFT_PWM, SPEED);
    analogWrite(RIGHT_PWM, SPEED);

    if (isLineFront()) {
        goBack();
    } else if (isLineBack()) {
        goForward();
    } else {
        currentState = SCANNING;
        stateStartTime = millis();
        return;
    }
}