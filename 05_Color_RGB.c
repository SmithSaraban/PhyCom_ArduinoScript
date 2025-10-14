const int BTN_RED = 2;
const int BTN_GREEN = 3;
const int BTN_BLUE = 4;

const int PIN_RED = 5;
const int PIN_GREEN = 6;
const int PIN_BLUE = 7;

bool is_red_on = false;
bool is_green_on = false;
bool is_blue_on = false;

void setup() {
    pinMode(BTN_RED, INPUT_PULLUP);
    pinMode(BTN_GREEN, INPUT_PULLUP);
    pinMode(BTN_BLUE, INPUT_PULLUP);
    
    pinMode(PIN_RED, OUTPUT);
    pinMode(PIN_GREEN, OUTPUT);
    pinMode(PIN_BLUE, OUTPUT);

    digitalWrite(PIN_RED, 1);
    digitalWrite(PIN_GREEN, 1);
    digitalWrite(PIN_BLUE, 1);
}

void loop() {
    change_stat(BTN_RED, PIN_RED, &is_red_on);
    change_stat(BTN_GREEN, PIN_GREEN, &is_green_on);
    change_stat(BTN_BLUE, PIN_BLUE, &is_blue_on);
    delay(5);
}

void change_stat(int btn_pin, int led_pin, bool* status) {
    if (digitalRead(btn_pin) == LOW) {
        *status = !(*status);
        if (*status) {
        digitalWrite(led_pin, LOW);
        } else {
        digitalWrite(led_pin, HIGH);
        }
        delay(500);
    }
}