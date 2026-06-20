#define in1 2
#define in2 3
#define in3 4
#define in4 5

#define SENSOR_ESQ 6
#define SENSOR_DIR 7

#define TRIG 9
#define ECHO 10

// Variáveis Globais
long duracao;
float distancia;

// Ajuste conforme seu sensor:
// Em muitos módulos TCRT5000:
// LOW = detectou preto
// HIGH = detectou branco
#define BRANCO HIGH
#define PRETO LOW

void setup() {

  // Pinos ligados em IN1 e IN2 Motor A
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);

  // Pinos ligados em IN3 e IN4 Motor B
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  // Sensores TCRT5000
  pinMode(SENSOR_ESQ, INPUT);
  pinMode(SENSOR_DIR, INPUT);

  // Pinos do Ultrassônico
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);

  Serial.begin(9600);
}

void loop() {

  int faixaEsq = digitalRead(SENSOR_ESQ);
  int faixaDir = digitalRead(SENSOR_DIR);

  dispararUltrassonico();

  Serial.print("Distancia: ");
  Serial.print(distancia);
  Serial.print(" cm | Sensor Esq: ");
  Serial.print(faixaEsq);
  Serial.print(" | Sensor Dir: ");
  Serial.println(faixaDir);

  // Se detectar faixa branca, foge da borda
  if (faixaEsq == BRANCO || faixaDir == BRANCO) {
    fugirDaBorda(faixaEsq, faixaDir);
  }

  // Se detectar adversário, ataca
  else if (distancia <= 50) {
    frenteMotorA();
    frenteMotorB();
  }

  // Se não detectar adversário, procura girando
  else {
    pararMotorA();
    frenteMotorB();
  }
}

// =======================
// MOVIMENTOS DO ROBÔ
// =======================

void frenteMotorA() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
}

void frenteMotorB() {
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void trasMotorA() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
}

void trasMotorB() {
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void pararMotorA() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
}

void pararMotorB() {
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}

void pararMotores() {
  pararMotorA();
  pararMotorB();
}

// Gira para esquerda
void girarEsquerda() {
  trasMotorA();
  frenteMotorB();
}

// Gira para direita
void girarDireita() {
  frenteMotorA();
  trasMotorB();
}

// Ré nos dois motores
void darRe() {
  trasMotorA();
  trasMotorB();
}

// =======================
// CONTROLE DA BORDA
// =======================

void fugirDaBorda(int faixaEsq, int faixaDir) {

  pararMotores();
  delay(100);

  // Primeiro dá ré
  darRe();
  delay(400);

  pararMotores();
  delay(100);

  // Se o sensor esquerdo viu a borda, gira para a direita
  if (faixaEsq == BRANCO && faixaDir != BRANCO) {
    girarDireita();
    delay(500);
  }

  // Se o sensor direito viu a borda, gira para a esquerda
  else if (faixaDir == BRANCO && faixaEsq != BRANCO) {
    girarEsquerda();
    delay(500);
  }

  // Se os dois sensores viram a borda, gira mais forte
  else if (faixaEsq == BRANCO && faixaDir == BRANCO) {
    girarDireita();
    delay(700);
  }

  pararMotores();
  delay(100);
}

// =======================
// ULTRASSÔNICO
// =======================

void dispararUltrassonico() {

  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);

  digitalWrite(TRIG, LOW);

  duracao = pulseIn(ECHO, HIGH, 30000);

  if (duracao == 0) {
    distancia = 999;
  } else {
    distancia = duracao * 0.034 / 2;
  }

  delay(50);
}