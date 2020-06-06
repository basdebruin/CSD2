const int OUTPIN = 22;
const int INPIN = 14;

void setup() {
    Serial.begin(9600);
    pinMode(OUTPIN, OUTPUT);
    pinMode(INPIN, INPUT);
}

unsigned int freq = 100;

void loop() {

    int potRead = analogRead(INPIN);

    freq = map(potRead, 0, 1023, 2, 500);
    Serial.println(freq);
    
    tick(OUTPIN, freq);

    //delay(10); 
    
}

void tick(unsigned int pin, unsigned int delayTime) {

    digitalWrite(pin, HIGH);
    delay(delayTime);
    digitalWrite(pin, LOW);
    delay(delayTime);
    
}
