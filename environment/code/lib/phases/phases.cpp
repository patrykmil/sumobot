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

    if (isEnemyDetected()) {
        DIRECTION = getEnemyDirection();
        currentState = ATTACKING;
        stateStartTime = millis();
        return;
    }

    if (millis() - stateStartTime > config.scanTimeout) {
        DIRECTION *= -1;
        stateStartTime = millis();
    }
}

void attack() {
    SPEED = config.attackSpeed;
    analogWrite(LEFT_PWM, SPEED);
    analogWrite(RIGHT_PWM, SPEED);

    if (DIRECTION > 0) {
        goForward();
    } else {
        goBack();
    }

    float enemyDist = getClosestEnemyDistance();

    if (enemyDist > config.enemyDetectionDistance) {
        currentState = SCANNING;
        stateStartTime = millis();
    }
}

void retreat() {
    SPEED = config.attackSpeed;
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

    if (millis() - stateStartTime > config.retreatDelay) {
        currentState = SCANNING;
        stateStartTime = millis();
    }
}