#pragma once

#include <config.h>

extern SumoConfig config;
extern SumoState currentState;
extern unsigned long stateStartTime;
extern int SPEED, DIRECTION, LINE_COLOR, SCAN_DISTANCE;

extern const int LEFT_IN1, LEFT_IN2, LEFT_PWM, RIGHT_IN1, RIGHT_IN2, RIGHT_PWM;
extern const int LINE_FRONT_PIN, LINE_BACK_PIN;
extern const int DIST_BACK_TRIG, DIST_BACK_ECHO, DIST_FRONT_TRIG, DIST_FRONT_ECHO;

float getDistanceFront();
float getDistanceBack();

bool isEnemyDetected();
float getClosestEnemyDistance();
int getEnemyDirection();

bool isLineFront();
bool isLineBack();
bool isOnLine();
