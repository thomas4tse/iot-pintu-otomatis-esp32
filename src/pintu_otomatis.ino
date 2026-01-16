#include <ESP32Servo.h>

const int trigPin = 27;
const int echoPin = 26;
const int ledPin = 18;
const int servoPin = 14;

long duration;
int distance;
Servo myServo;

void setup() {
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    pinMode(ledPin, OUTPUT);
    myServo.attach(servoPin);
    Serial.begin(9600);
}
void loop() {
    // Mengirimkan pulsa ke trigPin
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    // Membaca durasi pulsa dari echoPin
    duration = pulseIn(echoPin, HIGH);

    // Menghitung jarak dalam cm
    distance = duration * 0.034 / 2;

    // Menampilkan jarak di Serial Monitor
    Serial.print("Jarak: ");
    Serial.print(distance);
    Serial.println(" cm");

    // Menyalakan LED dan menggerakkan servo jika jarak kurang dari 10 cm
    if (distance < 10) {
        digitalWrite(ledPin, HIGH);
        myServo.write(90); // Menggerakkan servo ke 90 derajat
    } else {
        digitalWrite(ledPin, LOW);
        myServo.write(0); // Kembali ke 0 derajat jika tidak ada objek dekat
    }

    delay(500);
}
