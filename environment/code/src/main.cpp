#include <Arduino.h>
#include <config.h>
#include <move.h>
#include <phases.h>
#include <sensors.h>

#define BACK_LINE_SENSOR 0

SumoConfig config;
SumoState currentState;
unsigned long stateStartTime = 0;
int SPEED = 80;
int DIRECTION = 1;
int LINE_COLOR = 1;
int SCAN_DISTANCE = 25;

// Motor pins definition
const int LEFT_IN1 = 12;
const int LEFT_IN2 = 13;
const int LEFT_PWM = 11;
const int RIGHT_IN1 = 8;
const int RIGHT_IN2 = 9;
const int RIGHT_PWM = 10;

// Sensor pins definition
const int LINE_FRONT_PIN = 2;
const int LINE_BACK_PIN = 3;
const int DIST_BACK_TRIG = 4;
const int DIST_BACK_ECHO = 5;
const int DIST_FRONT_TRIG = 6;
const int DIST_FRONT_ECHO = 7;

void debug() {
    Serial.print("\nState: ");
    Serial.print(currentState == SCANNING    ? "SCANNING"
                 : currentState == ATTACKING ? "ATTACKING"
                                             : "RETREATING");
    Serial.print("\nFront Distance: ");
    Serial.print(getDistanceFront());
    Serial.print("\nBack Distance: ");
    Serial.print(getDistanceBack());
    Serial.print("\nEnemy Detected: ");
    Serial.print(isEnemyDetected() ? "Yes" : "No");
    Serial.print("\nClosest Enemy: ");
    Serial.print(getClosestEnemyDistance());
    Serial.print("\nDirection: ");
    Serial.print(getEnemyDirection());
    Serial.print("\nLine front: ");
    Serial.print(isLineFront() ? "Yes" : "No");
#if BACK_LINE_SENSOR
    Serial.print("\nLine back: ");
    Serial.print(isLineBack() ? "Yes" : "No");
#endif
    Serial.print("\n\n-------------------");
    delay(1000);
}

void setup() {
    SPEED = config.normalSpeed;
    LINE_COLOR = config.lineColor;
    SCAN_DISTANCE = config.enemyDetectionDistance;

    pinMode(LEFT_IN1, OUTPUT);
    pinMode(LEFT_IN2, OUTPUT);
    pinMode(LEFT_PWM, OUTPUT);
    pinMode(RIGHT_IN1, OUTPUT);
    pinMode(RIGHT_IN2, OUTPUT);
    pinMode(RIGHT_PWM, OUTPUT);

    pinMode(LINE_FRONT_PIN, INPUT);
    pinMode(LINE_BACK_PIN, INPUT);

    pinMode(DIST_FRONT_TRIG, OUTPUT);
    pinMode(DIST_FRONT_ECHO, INPUT);
    pinMode(DIST_BACK_TRIG, OUTPUT);
    pinMode(DIST_BACK_ECHO, INPUT);

    analogWrite(LEFT_PWM, config.normalSpeed);
    analogWrite(RIGHT_PWM, config.normalSpeed);

    delay(5000);

    currentState = SCANNING;
    stateStartTime = millis();

    Serial.begin(9600);
}

void loop() {
    if (isOnLine() && currentState != RETREATING) {
        currentState = RETREATING;
        stateStartTime = millis();
    }

    switch (currentState) {
        case SCANNING:
            scan();
            break;

        case ATTACKING:
            attack();
            break;

        case RETREATING:
            retreat();
            break;
    }
    debug();

    delay(50);
}