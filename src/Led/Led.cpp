#include "Led.h"

Led::Led(int pin) : _pin(pin) {}

void Led::begin() {
    pinMode(_pin, OUTPUT);
    digitalWrite(_pin, LOW);
    _state = false;
    _blinking = false;
    _lastToggle = millis();
    _interval = 0;
    _blinkCount = 0; 
}

void Led::on() {
    _state = HIGH;
    digitalWrite(_pin, _state);
}

void Led::off() {
    _state = LOW;
    digitalWrite(_pin, _state);
}

void Led::toggle() {
    _state = (_state == HIGH) ? LOW : HIGH;
    digitalWrite(_pin, _state);
}

void Led::startBlink(unsigned long interval) {
    _blinking = true;
    _interval = interval;
    _lastToggle = millis();
    _blinkCount = 0;
}

void Led::stopBlink() {
    _blinking = false;
}

void Led::update() {
    if (_blinking && (millis() - _lastToggle >= _interval)) {
        toggle();
        _lastToggle = millis();
        if (_state == HIGH) { 
            _blinkCount++;
        }
    }
}

int Led::getBlinkCount() {
    return _blinkCount;
}

bool Led::isBlinking() {
    return _blinking;
}

bool Led::isOn() {
    return _state == HIGH;
}