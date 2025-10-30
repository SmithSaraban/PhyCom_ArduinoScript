#include <Keypad.h>

const byte numRows = 4;
const byte numCols = 4;

const int LED_RED = 10;
const int LED_GREEN = 11;
const int LED_BLUE = 12;

char keymap[numRows][numCols] = 
{
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[numRows] = {9, 8, 7, 6};
byte colPins[numCols] = {5, 4, 3, 2};

Keypad myKeypad = Keypad(makeKeymap(keymap), rowPins, colPins, numRows, numCols);

void setup()
{
    Serial.begin(9600);
    pinMode(LED_RED, OUTPUT);
    pinMode(LED_GREEN, OUTPUT);
    pinMode(LED_BLUE, OUTPUT);
}

void loop()
{
    char keypressed = myKeypad.getKey();
    if (keypressed)
    {
        Serial.println(keypressed);
        switch (keypressed)
        {
            case '1':
                digitalWrite(LED_RED, 1);
                digitalWrite(LED_GREEN, 0);
                digitalWrite(LED_BLUE, 0);
                break;
            case '2':
                digitalWrite(LED_RED, 1);
    			digitalWrite(LED_GREEN, 1);
    			digitalWrite(LED_BLUE, 0);
                break;
            case '3':
                digitalWrite(LED_RED, 0);
    			digitalWrite(LED_GREEN, 1);
    			digitalWrite(LED_BLUE, 0);
                break;
          	case '4':
                digitalWrite(LED_RED, 0);
    			digitalWrite(LED_GREEN, 1);
    			digitalWrite(LED_BLUE, 1);
                break;
            case '5':
                digitalWrite(LED_RED, 0);
    			digitalWrite(LED_GREEN, 0);
    			digitalWrite(LED_BLUE, 1);
                break;
            case '6':
                digitalWrite(LED_RED, 1);
                digitalWrite(LED_GREEN, 0);
                digitalWrite(LED_BLUE, 1);
                break;
          	case '7':
                digitalWrite(LED_RED, 1);
                digitalWrite(LED_GREEN, 1);
                digitalWrite(LED_BLUE, 1);
                break;
            case '8':
                digitalWrite(LED_RED, 1);
                digitalWrite(LED_GREEN, 0);
                digitalWrite(LED_BLUE, 0);
                delay(1000);
                digitalWrite(LED_RED, 1);
                digitalWrite(LED_GREEN, 1);
                digitalWrite(LED_BLUE, 0);
                delay(1000);
                digitalWrite(LED_RED, 0);
                digitalWrite(LED_GREEN, 1);
                digitalWrite(LED_BLUE, 0);
                delay(1000);
                digitalWrite(LED_RED, 0);
                digitalWrite(LED_GREEN, 1);
                digitalWrite(LED_BLUE, 1);
                delay(1000);
                digitalWrite(LED_RED, 0);
                digitalWrite(LED_GREEN, 0);
                digitalWrite(LED_BLUE, 1);
                delay(1000);
                digitalWrite(LED_RED, 1);
                digitalWrite(LED_GREEN, 0);
                digitalWrite(LED_BLUE, 1);
                delay(1000);
                digitalWrite(LED_RED, 1);
                digitalWrite(LED_GREEN, 1);
                digitalWrite(LED_BLUE, 1);
                delay(1000);
                break;
            case '9':
                digitalWrite(LED_RED, random(0, 2));
                digitalWrite(LED_GREEN, random(0, 2));
                digitalWrite(LED_BLUE, random(0, 2));
                break;
          	case '0':
                digitalWrite(LED_RED, 0);
                digitalWrite(LED_GREEN, 0);
                digitalWrite(LED_BLUE, 0);
                break;
            default:
                break;
        }
    }
}