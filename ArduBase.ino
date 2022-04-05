#define PWMA 3
#define AIN1 5
#define AIN2 4
#define PWMB 9
#define BIN1 7
#define BIN2 8
#define STBY 6
#define ECHO 10
#define TRIG 11

#define PWMPower 150

#define trigPin 6
#define echoPin 7

int direzione = 0;
/*
 * Allora, ho deciso che i valori per la direzione saranno i seguenti:
 * 8 - Avanti
 * 2 - Indietro
 * 6 - Destra
 * 4 - Sinistra
 * 5 - Fermi
 */

void setup()
{
  Serial.begin(115200);
  Serial.setTimeout(1);
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  digitalWrite(TRIG, LOW);
  
}

void motoriAvanti(){
  digitalWrite(AIN1, HIGH);
  digitalWrite(AIN2, LOW);
  analogWrite(PWMA, PWMPower);
  analogWrite(PWMB, PWMPower);
  digitalWrite(BIN1, HIGH);
  digitalWrite(BIN2, LOW);
  digitalWrite(STBY, HIGH);
}

void motoriIndietro(){
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, HIGH);
  analogWrite(PWMA, PWMPower);
  analogWrite(PWMB, PWMPower);
  digitalWrite(BIN1, LOW);
  digitalWrite(BIN2, HIGH);
  digitalWrite(STBY, HIGH);
}

void motoriFermi(){
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, LOW);
  digitalWrite(PWMA, LOW);
  digitalWrite(PWMB, LOW);
  digitalWrite(BIN1, LOW);
  digitalWrite(BIN2, LOW);
  digitalWrite(STBY, LOW);
}

void motoriDestra(){
  digitalWrite(AIN1, HIGH);
  digitalWrite(AIN2, LOW);
  analogWrite(PWMA, PWMPower);
  analogWrite(PWMB, PWMPower);
  digitalWrite(BIN1, LOW);
  digitalWrite(BIN2, HIGH);
  digitalWrite(STBY, HIGH);
}

void motoriSinistra(){
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, HIGH);
  analogWrite(PWMA, PWMPower);
  analogWrite(PWMB, PWMPower);
  digitalWrite(BIN1, HIGH);
  digitalWrite(BIN2, LOW);
  digitalWrite(STBY, HIGH);
}

void loop()
{
    while(!Serial.available());
    direzione = Serial.readString().toInt();
    switch (direzione){
      case 0:
        motoriAvanti();
        Serial.println("Motori - Avanti");
        break;
      case 1:
        motoriIndietro();
        Serial.println("Motori - Indietro");
        break;
      case 2:
        motoriDestra();
        Serial.println("Motori - Destra");
        break;
      case 3:
        motoriSinistra();
        Serial.println("Motori - Sinistra");
        break;
      case 4:
        motoriFermi();
        Serial.println("Motori - Fermi");
        break;
    }
}
