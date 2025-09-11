#include <Arduino.h>
#include <move.h>
#include <sensors.h>

void goForward() {
    digitalWrite(LEFT_IN1, LOW);
    digitalWrite(LEFT_IN2, HIGH);
    digitalWrite(RIGHT_IN1, LOW);
    digitalWrite(RIGHT_IN2, HIGH);
}

void goBack() {
    digitalWrite(LEFT_IN1, HIGH);
    digitalWrite(LEFT_IN2, LOW);
    digitalWrite(RIGHT_IN1, HIGH);
    digitalWrite(RIGHT_IN2, LOW);
}

void goLeft() {
    digitalWrite(LEFT_IN1, LOW);
    digitalWrite(LEFT_IN2, HIGH);
    digitalWrite(RIGHT_IN1, HIGH);
    digitalWrite(RIGHT_IN2, LOW);
}

void goRight() {
    digitalWrite(LEFT_IN1, HIGH);
    digitalWrite(LEFT_IN2, LOW);
    digitalWrite(RIGHT_IN1, LOW);
    digitalWrite(RIGHT_IN2, HIGH);
}

void stop() {
    digitalWrite(LEFT_IN1, LOW);
    digitalWrite(LEFT_IN2, LOW);
    digitalWrite(RIGHT_IN1, LOW);
    digitalWrite(RIGHT_IN2, LOW);
}

void chargeForward(int power) {
    analogWrite(LEFT_PWM, power);
    analogWrite(RIGHT_PWM, power);
    goForward();
}

void chargeBack(int power) {
    analogWrite(LEFT_PWM, power);
    analogWrite(RIGHT_PWM, power);
    goBack();
}

void rotateLeft(int power) {
    analogWrite(LEFT_PWM, power);
    analogWrite(RIGHT_PWM, power);
    goLeft();
}

void rotateRight(int power) {
    analogWrite(LEFT_PWM, power);
    analogWrite(RIGHT_PWM, power);
    goRight();
}

void flip(int power) {
    analogWrite(LEFT_PWM, power);
    analogWrite(RIGHT_PWM, power);
    stop();
    delay(100);
    rotateRight(power);
    delay(850);
    stop();
    delay(100);
}