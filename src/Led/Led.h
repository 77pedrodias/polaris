#ifndef LED_H
#define LED_H

#include "Arduino.h"

/**
 * @brief Simple LED control class with optional non-blocking blink functionality.
 */
class Led {
    public:
        /**
        * @brief Construct a new Led object.
        * @param pin The GPIO pin number where the LED is connected.
        */
        Led(int pin);

        /**
        * @brief Initialize the LED (sets pinMode to OUTPUT and turns LED off).
        */  
        void begin();

        /**
         * @brief Turns the LED on (sets pin HIGH).
        */
        void on();

        /**
         * @brief Turns the LED off (sets pin LOW).
         */
        void off();

        /**
         * @brief Toggles the LED state (LOW <-> HIGH).
         */
        void toggle();

        /**
        * @brief Starts blinking the LED with the specified interval (non-blocking).
        * @param interval Blink interval in milliseconds.
        */
        void startBlink(unsigned long interval);

        /**
        * @brief Stops the LED from blinking.
        */
        void stopBlink();

        /**
        * @brief Updates the LED blink state. Must be called regularly in loop().
        */
        void update();

        /**
        * @brief Gets the total number of times the LED toggled during blinking.
        * @return Current blink count.
        */
        int getBlinkCount();

        /**
         * @brief Checks if the LED is currently blinking.
        * @return true if blinking, false otherwise.
        */
        bool isBlinking();

        /**
        * @brief Checks if the LED is currently ON.
        * @return true if ON, false if OFF.
        */
        bool isOn();
    private:
        int _pin;                  ///< GPIO pin number
        bool _state;               ///< Current LED state (HIGH = ON, LOW = OFF)
        bool _blinking;            ///< Whether the LED is currently blinking
        unsigned long _interval;   ///< Blink interval in milliseconds
        unsigned long _lastToggle; ///< Last time the LED toggled (for millis-based timing)
        int _blinkCount;           ///< Total blink count since start
};

#endif