extern "C" {
  #include "indicator_logic.h"
}
#include <esp32-hal-ledc.h>

#define LEFT_BUTTON_PIN 18
#define RIGHT_BUTTON_PIN 19
#define LEFT_LED_PIN 21
#define RIGHT_LED_PIN 22
#define PWM_PIN 23

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  Serial.println("Started");
  pinMode(LEFT_BUTTON_PIN, INPUT);
  pinMode(RIGHT_BUTTON_PIN, INPUT);
  pinMode(LEFT_LED_PIN, OUTPUT);
  pinMode(RIGHT_LED_PIN, OUTPUT);
  pinMode(PWM_PIN, OUTPUT);
  
}

void loop() {
  static unsigned long lastTick = 0;

  if (millis() - lastTick >= 100) {
    lastTick = millis();

    // Read buttons (LOW = pressed)
    indicator_logic_U.BTNL = digitalRead(LEFT_BUTTON_PIN) == LOW ? 0: 1;
    indicator_logic_U.BTNR = digitalRead(RIGHT_BUTTON_PIN) == LOW ? 0 : 1;
    indicator_logic_U.time = millis();
    
    // Run the logic step
    indicator_logic_step();

    // Control LEDs based on outputs
    digitalWrite(LEFT_LED_PIN, indicator_logic_Y.led_left == 1? HIGH : LOW);
    digitalWrite(RIGHT_LED_PIN, indicator_logic_Y.led_right == 1 ? HIGH : LOW);
    
    if(indicator_logic_Y.pwm == 1)
    {
         ledcAttach(PWM_PIN, 2, 16);
         ledcWrite(PWM_PIN,100);
    }
    else
         ledcDetach(PWM_PIN);


    // Debug output to Serial
    Serial.println("");
    Serial.print("Time: ");
    Serial.print(millis());
    Serial.print(" | BTNL: ");
    Serial.print(indicator_logic_U.BTNL);
    Serial.print(" | BTNR: ");
    Serial.print(indicator_logic_U.BTNR);
    Serial.print("      | LEDL: ");
    Serial.print(indicator_logic_Y.led_left);
    Serial.print(" | LEDR: ");
    Serial.print(indicator_logic_Y.led_right);
  }
}
