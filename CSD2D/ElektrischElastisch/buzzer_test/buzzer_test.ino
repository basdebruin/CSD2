const unsigned int pin = 22;

void setup() {
    Serial.begin(9600);
    pinMode(pin, OUTPUT);
}

unsigned int freq = 100;
bool goin_down = true;

void loop() {

    Serial.println(freq);

    if (goin_down) { freq--; }
    else           { freq++; }
    
    if (freq < 4 && goin_down)          { goin_down = false; }
    else if (freq > 100 && !goin_down) { goin_down = true;  }

    tone(pin, freq);

    delay(100); 
    
}
