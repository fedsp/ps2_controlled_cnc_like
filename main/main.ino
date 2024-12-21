//aceleracao 500
//velocidade 500
#include <AccelStepper.h>

const byte stepPins[] = {2, 3, 4};
const byte directionPins[] = {5, 6, 7};
const byte enPin = 8;

const byte inputPins[] = {9, 10, 11, 12,13,A3};
const byte potPin = A0;

#define MAX_SPEED 500
#define MIN_SPEED 100 // Velocidade mínima
#define MAX_ACCELERATION 500

AccelStepper stepper1(AccelStepper::DRIVER, stepPins[0], directionPins[0]);
AccelStepper stepper2(AccelStepper::DRIVER, stepPins[1], directionPins[1]);
AccelStepper stepper3(AccelStepper::DRIVER, stepPins[2], directionPins[2]);


void setup() {
  Serial.begin(9600);
  pinMode(enPin, OUTPUT);
  digitalWrite(enPin, LOW);

  stepper1.setMaxSpeed(MAX_SPEED);
  stepper2.setMaxSpeed(MAX_SPEED);
  stepper3.setMaxSpeed(MAX_SPEED);
  stepper1.setAcceleration(MAX_ACCELERATION);
  stepper2.setAcceleration(MAX_ACCELERATION);
  stepper3.setAcceleration(MAX_ACCELERATION);

    for (byte i = 0; i < 6; i++) {
    pinMode(inputPins[i], INPUT_PULLUP);
  }
}

void loop() {
  int potValue = analogRead(potPin); // Leitura do potenciômetro (0-1023)
  int speed = map(potValue, 0, 1023, MIN_SPEED, MAX_SPEED);
  ReadInput(speed);
  stepper1.run();
  stepper2.run();
  stepper3.run();
}

void ReadInput(int speed) {
  bool anyButtonPressed = false; 
  if (digitalRead(inputPins[0]) == LOW) { // Botão na porta D9
    stepper1.setSpeed(speed);
    anyButtonPressed = true;
  } 
  if (digitalRead(inputPins[1]) == LOW) { // Botão na porta D10
    stepper1.setSpeed(-speed); // Movimento no sentido anti-horário
    anyButtonPressed = true;
  }
  if (digitalRead(inputPins[2]) == LOW) { // Botão na porta D11
    stepper2.setSpeed(speed); // Controle do segundo motor
    anyButtonPressed = true;
  }
  if (digitalRead(inputPins[3]) == LOW) { // Botão na porta D12
    stepper2.setSpeed(-speed); // Controle do terceiro motor
    anyButtonPressed = true;
  }
    if (digitalRead(inputPins[4]) == LOW) { // Botão na porta D12
    stepper3.setSpeed(speed); // Controle do terceiro motor
    anyButtonPressed = true;
  }
    if (digitalRead(inputPins[5]) == LOW) { // Botão na porta D12
    stepper3.setSpeed(-speed); // Controle do terceiro motor
    anyButtonPressed = true;
  }
  if (!anyButtonPressed) {
    stepper1.setSpeed(0);
    stepper2.setSpeed(0);
    stepper3.setSpeed(0);
  }
}