// Final code for
// Eletrisch-akkoestisch instrument
// Author: Bas de Bruin

#define LDR_PIN 14
#define BUZ_PIN 22

#define IN_MIN 250
#define IN_MAX 700

#define PITCH_MIN 3
#define PITCH_MAX 300

void setup() {
    Serial.begin(9600);
    pinMode(LDR_PIN, INPUT);
    pinMode(BUZ_PIN, OUTPUT);
}

void loop() {
    
    // get ldr data and map it
    unsigned int data = analogRead(LDR_PIN);
    unsigned int freq = constrain(map(data, IN_MIN, IN_MAX, PITCH_MIN, PITCH_MAX), PITCH_MIN, PITCH_MAX);

    // sound
    tone(BUZ_PIN, freq);

    // debug printing
    Serial.println();
    Serial.print("Raw:   ");
    Serial.print(data);
    Serial.print("   Scaled:   ");
    Serial.print(freq);
    
    delay(10);
    
}
