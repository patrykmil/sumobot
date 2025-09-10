#pragma once

extern int SPEED, DIRECTION;
extern const int LEFT_IN1, LEFT_IN2, LEFT_PWM, RIGHT_IN1, RIGHT_IN2, RIGHT_PWM;

void goForward();
void goBack();
void goLeft();
void goRight();
void stop();

void chargeForward(int power = 255);
void chargeBack(int power = 255);
void rotateLeft(int power = 80);
void rotateRight(int power = 80);