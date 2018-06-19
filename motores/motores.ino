//DC Motors

//IZQ: VERDE
const int sm1 = 7;
const int sm1_2 = 8;
const int pwm1 = 6;//columna h protoboard
//DER: VIOLETA o AZUL
const int sm2 = 3;
const int sm2_2 = 4;
const int pwm2 = 5;//columna c 

void setup() {
  //Motores
  pinMode(sm1, OUTPUT);
  pinMode(sm1_2, OUTPUT);
  pinMode(pwm1, OUTPUT);
  pinMode(sm2, OUTPUT);
  pinMode(sm2_2, OUTPUT);
  pinMode(pwm2, OUTPUT);

}
int vel = 200;
void loop() {

  //Deben moverse los dos hacia delante
  digitalWrite(sm1,HIGH);
  digitalWrite(sm2,LOW);
  digitalWrite(sm1_2,LOW);
  digitalWrite(sm2_2,HIGH);

  analogWrite(pwm1,vel);
  analogWrite(pwm2,vel);

  delay(5000);
}
