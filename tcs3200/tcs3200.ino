//TCS3200 Color Sensor
const int s0 = 11;//Verde
const int s1 = 12;//Amarillo
const int s2 = 10;//Naranja
const int s3 = 9;//Morado
const int out = 14;//Azul: A0

void setup() {
  
  //Sensor TCS3200
  pinMode(s0,OUTPUT);
  pinMode(s1,OUTPUT);
  pinMode(s2,OUTPUT);
  pinMode(s3,OUTPUT);
  pinMode(out,INPUT);
  Serial.begin(9600);
  digitalWrite(s0,LOW);//2% frequency scaling: 10-12kHz Limited because of Arduino's clock
  digitalWrite(s1,HIGH);
}

typedef struct{
  unsigned long R;
  unsigned long G;
  unsigned long B;
}color;
color rgb;//tcs
float input_neuron[10];

/**Variables de la prueba avanzada**/
/*unsigned long duracion = 0;
float color[]= {
  0,0,0,0};//R,G,C,B*/
  
void loop() {

delayMicroseconds(50);
  //Lee el valor en frecuencia de el color que lee, además de cambiarlo a rango RGB

    //Leemos el rojo
    digitalWrite(s2, LOW);
    digitalWrite(s3,LOW);
    rgb.R = pulseIn(out,digitalRead(out)== HIGH ? LOW : HIGH);

    //Leemos el verde
    digitalWrite(s2, HIGH);
    digitalWrite(s3,HIGH);
    rgb.G = pulseIn(out,digitalRead(out)== HIGH ? LOW : HIGH);

    //Leemos el blue
    digitalWrite(s2, LOW);
    digitalWrite(s3,HIGH);
    rgb.B = pulseIn(out,digitalRead(out)== HIGH ? LOW : HIGH);

//compara el valor con el del veneno: ROJO

if ((rgb.R < rgb.B)&&(rgb.G > rgb.B)&& (rgb.R < 400)){

    input_neuron[0] = 0;//ponemos la neurona de comida a 0
    input_neuron[1] = 1;//ponemos la neurona de veneno a 1
  }

//compara el valor de la comida: AZUL

else if ((rgb.B < rgb.R)&&(rgb.G > rgb.B)&& (rgb.G < rgb.R)){

    input_neuron[0] = 1;//ponemos la neurona de comida a 1
    input_neuron[1] = 0;//ponemos la neurona de veneno a 0
  }
else{
  input_neuron[0] = 0;//ponemos la neurona de comida a 0 Control de versiones
  input_neuron[1] = 0;//ponemos la neurona de veneno a 0 Control de versiones
}

//Apagamos el sensor
//******************************************************************//
Serial.println("Valor neurona 0, parte del subprocess:");
Serial.println(input_neuron[0]);
Serial.println("Valor neurona 1, parte del subprocess:");
Serial.println(input_neuron[1]);
//******************************************************************//

Serial.print("rgb.R: ");
Serial.println(rgb.R);

Serial.print("rgb.G: ");
Serial.println(rgb.G);

Serial.print("rgb.B: ");
Serial.println(rgb.B);
/********************Prueba avanzada del sensor************************/
   /*for(int i = 0; i < 2; i++){

      digitalWrite(s2, i);//Red: 00, Blue: 01; Clear: 10; Green: 11
      for(int j = 0; j < 2; j++){
        digitalWrite(s3, j);
        delay(1);//in miliseconds
        duracion= pulseIn(out,digitalRead(out) == HIGH ? LOW : HIGH);
        color[2*i+j] = 1000000/duracion;
        Serial.print("Color ");
        Serial.print(2*i+j);
        Serial.print(": ");
        Serial.println(color[2*i+j]);

        Serial.print("Duracion: ");
        Serial.println(duracion);
      }
    }
    if (color[0] == 0 || color[1] == 0 || color[2] == 0 || color[3] == 0){
      Serial.println("Error");      
    }*/
delay(2500);

}
