#include <Arduino.h>
#include <sensors.h>

float getDistanceFront() {
    float echoTime;
    float calculatedDistance;

    digitalWrite(DIST_FRONT_TRIG, HIGH);
    delayMicroseconds(10);
    digitalWrite(DIST_FRONT_TRIG, LOW);

    echoTime = pulseIn(DIST_FRONT_ECHO, HIGH);

    if (echoTime == 0) {
        return 999;
    }

    calculatedDistance = echoTime * 0.017;

    if (calculatedDistance > 200 || calculatedDistance < 2) {
        return 999;
    }

    return calculatedDistance;
}

float getDistanceBack() {
    float echoTime;
    float calculatedDistance;

    digitalWrite(DIST_BACK_TRIG, HIGH);
    delayMicroseconds(10);
    digitalWrite(DIST_BACK_TRIG, LOW);

    echoTime = pulseIn(DIST_BACK_ECHO, HIGH);

    if (echoTime == 0) {
        return 999;
    }

    calculatedDistance = echoTime * 0.017;

    if (calculatedDistance > 200 || calculatedDistance < 2) {
        return 999;
    }

    return calculatedDistance;
}

bool isEnemyDetected() {
    float frontDist = getDistanceFront();
    float backDist = getDistanceBack();
    return (frontDist < config.enemyDetectionDistance && frontDist > 0) ||
           (backDist < config.enemyDetectionDistance && backDist > 0);
}

float getClosestEnemyDistance() {
    float frontDist = getDistanceFront();
    float backDist = getDistanceBack();

    if (frontDist <= 0) frontDist = 999;
    if (backDist <= 0) backDist = 999;

    return min(frontDist, backDist);
}

int getEnemyDirection() {
    float frontDist = getDistanceFront();
    float backDist = getDistanceBack();

    if (frontDist <= 2 || frontDist >= 200) frontDist = 999;
    if (backDist <= 2 || backDist >= 200) backDist = 999;

    if (frontDist < 25 && backDist < 25) {
        return (frontDist < backDist) ? 1 : -1;
    } else if (frontDist < 25) {
        return 1;
    } else if (backDist < 25) {
        return -1;
    }

    return 0;
}

bool isLineFront() {
    return digitalRead(LINE_FRONT_PIN) == LINE_COLOR;
}

bool isLineBack() {
    return digitalRead(LINE_BACK_PIN) == LINE_COLOR;
}

bool isOnLine() {
#if BACK_LINE_SENSOR && FRONT_LINE_SENSOR
    return isLineFront() || isLineBack();
#elif FRONT_LINE_SENSOR
    return isLineFront();
#endif
    return false;
}
