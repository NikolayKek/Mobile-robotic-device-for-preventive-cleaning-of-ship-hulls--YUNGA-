// Определяем пины для управления моторами
#define MOTOR1_DIR 4    // Направление первого мотора
#define MOTOR1_SPEED 5  // Скорость первого мотора (PWM)
#define MOTOR2_SPEED 6  // Скорость второго мотора (PWM)
#define MOTOR2_DIR 7    // Направление второго мотора

const int waterLevel = 333;  // задать собственое значение!

void setup() {
  // Настраиваем пины как выходы
  pinMode(MOTOR1_DIR, OUTPUT);
  pinMode(MOTOR1_SPEED, OUTPUT);
  pinMode(MOTOR2_SPEED, OUTPUT);
  pinMode(MOTOR2_DIR, OUTPUT);
  pinMode(2, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  Serial.println(analogRead(A0));
  delay(100);
  testing();
}
void testing() {
  if (analogRead(A0) >= waterLevel) { 
    digitalWrite(2, 1);  // включаем реле
    stopMotors();
    delay(1000);
    // Пример движения вперед
    moveForward(255);  // Максимальная скорость
    delay(2000);       // Движение вперед в течение 2 секунд

    // Пример движения назад
    moveBackward(255);  // Скорость 200 (из 255)
    delay(2000);        // Движение назад в течение 2 секунд
    // Пример поворота влево
    turnLeft(255);  // Скорость 150 (из 255)
    delay(1000);    // Поворот влево в течение 1 секунды

    // Пример поворота вправо
    turnRight(255);  // Скорость 150 (из 255)
    delay(1000);     // Поворот вправо в течение 1 секунды
  } else {
    stopMotors();
    digitalWrite(2, 0);
  }
}
// Функция для движения вперед
void moveForward(int speed) {
  // Первый мотор: направление вперед
  digitalWrite(MOTOR1_DIR, HIGH);
  analogWrite(MOTOR1_SPEED, speed);  // Устанавливаем скорость

  // Второй мотор: направление вперед
  digitalWrite(MOTOR2_DIR, HIGH);
  analogWrite(MOTOR2_SPEED, speed);  // Устанавливаем скорость
}

// Функция для движения назад
void moveBackward(int speed) {
  // Первый мотор: направление назад
  digitalWrite(MOTOR1_DIR, LOW);
  analogWrite(MOTOR1_SPEED, speed);  // Устанавливаем скорость

  // Второй мотор: направление назад
  digitalWrite(MOTOR2_DIR, LOW);
  analogWrite(MOTOR2_SPEED, speed);  // Устанавливаем скорость
}

// Функция для поворота влево
void turnLeft(int speed) {
  // Первый мотор: направление назад
  digitalWrite(MOTOR1_DIR, LOW);
  analogWrite(MOTOR1_SPEED, speed);  // Устанавливаем скорость

  // Второй мотор: направление вперед
  digitalWrite(MOTOR2_DIR, HIGH);
  analogWrite(MOTOR2_SPEED, speed);  // Устанавливаем скорость
}

// Функция для поворота вправо
void turnRight(int speed) {
  // Первый мотор: направление вперед
  digitalWrite(MOTOR1_DIR, HIGH);
  analogWrite(MOTOR1_SPEED, speed);  // Устанавливаем скорость

  // Второй мотор: направление назад
  digitalWrite(MOTOR2_DIR, LOW);
  analogWrite(MOTOR2_SPEED, speed);  // Устанавливаем скорость
}

// Функция для остановки моторов
void stopMotors() {
  // Останавливаем оба мотора (скорость = 0)
  analogWrite(MOTOR1_SPEED, 0);
  analogWrite(MOTOR2_SPEED, 0);
}