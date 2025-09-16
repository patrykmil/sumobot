#pragma once

extern int SPEED, DIRECTION;
extern const int LEFT_IN1, LEFT_IN2, LEFT_PWM, RIGHT_IN1, RIGHT_IN2, RIGHT_PWM;

void goForward();
void goBack();
void goLeft();
void goRight();
void stop();

void chargeForward(int power);
void chargeBack(int power);
void rotateLeft(int power);
void rotateRight(int power);
void flip(int power);