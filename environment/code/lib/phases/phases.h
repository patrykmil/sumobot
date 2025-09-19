#pragma once
#include <sensors.h>
#include <config.h>

extern SumoConfig config;
extern SumoState currentState;
extern unsigned long stateStartTime;
extern int SPEED, DIRECTION, LINE_COLOR, SCAN_DISTANCE;


void scan();
void attack();
void retreat();