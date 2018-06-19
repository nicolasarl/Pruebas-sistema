//Phototransistors
const int sel1 = 2; //se reasigna por falta de pines: blanco sube segundo piso
const int sel2 = 17;//gris sube segundo piso
const int lect_r = 18;//marron sube segundo piso
const int lect_b = 19;//amarillo sube segundo piso
void setup() {

  //Fototransistores
  pinMode(sel1, OUTPUT);
  pinMode(sel2, OUTPUT);
  pinMode(lect_r, INPUT);
  pinMode(lect_b, INPUT);

  Serial.begin(9600);
}
typedef struct{
  int R;
  int G;
  int B;
}zonas;
zonas temp;//fototransistores

float input_neuron[10];
void loop() {

//Control de versiones 
  //Realizamos la lectura para el cuadrante 1
  digitalWrite(sel1, LOW);
  digitalWrite(sel2, LOW);
  delay(1);

  temp.B = analogRead(lect_b);
    Serial.println("Tempb 1: ");
  Serial.println(temp.B); 
  input_neuron[3] = (1.0/212.0)*temp.B-1.20755;
  input_neuron[3] = constrain(input_neuron[3],0,1);
  temp.R = analogRead(lect_r);
    Serial.println("Tempr 1: ");
  Serial.println(temp.R); 
  input_neuron[2] = 0.001038*temp.R-0.0322;
  input_neuron[2] = constrain(input_neuron[2],0,1);
  
  //Realizamos la lectura para el cuadrante 2
  digitalWrite(sel1, LOW);
  digitalWrite(sel2, HIGH);
  delay(1);

  temp.B = analogRead(lect_b);
    Serial.println("Tempb 2: ");
  Serial.println(temp.B); 
  input_neuron[5] = (1.0/212.0)*temp.B-1.20755;
  input_neuron[5] = constrain(input_neuron[5],0,1);
  temp.R = analogRead(lect_r);
    Serial.println("Tempr 2: ");
  Serial.println(temp.R); 
  input_neuron[4] = 0.001038*temp.R-0.0322;
  input_neuron[4] = constrain(input_neuron[4],0,1);

  //Realizamos la lectura para el cuadrante 3
  digitalWrite(sel1, HIGH);
  digitalWrite(sel2, LOW);
  delay(1);
  temp.B = analogRead(lect_b);
    Serial.println("Tempb 3: ");
  Serial.println(temp.B); 
  input_neuron[7] = (1.0/212.0)*temp.B-1.20755;
  input_neuron[7] = constrain(input_neuron[7],0,1);
  temp.R = analogRead(lect_r);
    Serial.println("Tempr 3: ");
  Serial.println(temp.R); 
  input_neuron[6] = 0.001038*temp.R-0.0322;
  input_neuron[6] = constrain(input_neuron[6],0,1);

  //Realizamos la lectura para el cuadrante 4
  digitalWrite(sel1, HIGH);
  digitalWrite(sel2, HIGH);
  delay(1);
  temp.B = analogRead(lect_b);
  Serial.println("Tempb 4: ");
  Serial.println(temp.B);  
  input_neuron[9] = (1.0/212.0)*temp.B-1.20755;
  input_neuron[9] = constrain(input_neuron[9],0,1);
  temp.R = analogRead(lect_r);
    Serial.println("Tempr 4: ");
  Serial.println(temp.R); 
  input_neuron[8] = 0.001038*temp.R-0.0322;
  input_neuron[8] = constrain(input_neuron[8],0,1);
//******************************************************************//
  Serial.println("Valor neurona 2, roja:");
  Serial.println(input_neuron[2]);
  Serial.println("Valor neurona 4, roja:");
  Serial.println(input_neuron[4]);
  Serial.println("Valor neurona 6, roja:");
  Serial.println(input_neuron[6]);
  Serial.println("Valor neurona 8, roja:");
  Serial.println(input_neuron[8]);
  
  Serial.println("Valor neurona 3, azul:");
  Serial.println(input_neuron[3]);
  Serial.println("Valor neurona 5, azul:");
  Serial.println(input_neuron[5]);
  Serial.println("Valor neurona 7, azul:");
  Serial.println(input_neuron[7]);
  Serial.println("Valor neurona 9, azul:");
  Serial.println(input_neuron[9]);
//***************************************************************//  

  delay(10000);
}
