#include <servo.h> //подключаем библиотеку для работы с сервоприводом
Servo CamServo; //объявляем переменную CamServo типа Servo

//к этому порту подключен сигнал заднего хода

int switchPin = 7;

//к этому порту подключен сервопривод

int servoPin = 9;

//к этому порту подключено реле

int relayPin1 = 8;
int relayPin2 = 6;
//переменные posClose и posOpen указывают в какую позицию должен повернуться сервопривод
//максимальный угол поворота сервопривода — 180 градусов

int posClose = 0;
int posOpen = 80;

void setup() {
pinMode(switchPin, INPUT); //определяем порт switchPin как входящий
pinMode(relayPin1, OUTPUT); //определяем порт relayPin как исходящий
pinMode(relayPin2, OUTPUT); //определяем порт relayPin как исходящий
CamServo.attach(servoPin); //определяем порт servoPin как управляющий сервоприводом
}

void loop() {
if (digitalRead(switchPin) == HIGH) //если на порт switchPin подается напряжение — логическая 1 через делитель напряжения
{
digitalWrite(relayPin1, LOW); //подаем сигнал на порт relayPin реле привода
digitalWrite(relayPin2, LOW); //подаем сигнал на порт relayPin реле камеры
CamServo.write(posOpen); // Говорим серво повернуться в позицию open градусов

}
else //иначе
{
digitalWrite(relayPin2, HIGH); //отключаем реле камеры
CamServo.write(posClose); //говорим серво повернуться в позицию Close градусов
delay(2000); //устанавливаем задержку в милисекундах
digitalWrite(relayPin1, HIGH); //отключаем реле привода
}

}
