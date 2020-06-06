// LDR Test
// gwn een  ldr'etje teste

#define PIN 14

#define SCALE_MIN 250
#define SCALE_MAX 700

void setup() {
    Serial.begin(9600);
    pinMode(PIN, INPUT);
}

void loop() {
    unsigned int data = analogRead(PIN);
    unsigned int scaled_data = constrain(map(data, SCALE_MIN, SCALE_MAX, 0, 100), 0, 100);


    Serial.println();
    Serial.print("Raw:   ");
    Serial.print(data);
    Serial.print("   Scaled:   ");
    Serial.print(scaled_data);
    

    delay(10);
}
