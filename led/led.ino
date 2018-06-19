//LED's OUTPUT
const int ledr = 13;//morado sube segundo piso
const int ledb = 16;//azul sube segundo piso

void setup() {
  pinMode(ledr,OUTPUT);
  pinMode(ledb,OUTPUT);

}

void loop() {
//ROJO
  digitalWrite(ledr,LOW);
  digitalWrite(ledb,LOW);

  delay(5000);
//AZUL
  digitalWrite(ledr,HIGH);
  digitalWrite(ledb,LOW);
  
  delay(5000);
}
