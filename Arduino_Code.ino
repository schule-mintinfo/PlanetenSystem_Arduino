#define EN 8
#define xDir 5
#define xStep 2
#define yDir 6
#define yStep 3
#define zDir 7
#define zStep 4

String input;
int FastDelay;
int NormalDelay;
void setup() {
 pinMode(EN, OUTPUT);
 pinMode(xDir, OUTPUT);
 pinMode(xStep, OUTPUT);
 pinMode(yDir, OUTPUT);
 pinMode(yStep, OUTPUT);
 pinMode(zDir, OUTPUT);
 pinMode(zStep, OUTPUT);
input = "";


}

void loop() {
  if (Serial.available()){
  input = Serial.readString();
   }
   Turn(GetDelay(input));

}


void Turn(int DELAY) {
    if(delay == 0){
        digitalWrite(xStep, HIGH);
        digitalWrite(yStep, HIGH);
        digitalWrite(zStep, HIGH);
        delayMircoseconds(500);
        digitalWrite(xStep, LOW);
        digitalWrite(yStep, LOW);
        digitalWrite(zStep, LOW);
        delayMircoseconds(500);
    } else if (delay == -1){
        digitalWrite(xStep, LOW);
        digitalWrite(yStep, LOW);
        digitalWrite(zStep, LOW);
    }else{
        for(int i=0; i<200; i++){
            digitalWrite(xStep, HIGH);
            digitalWrite(yStep, HIGH);
            digitalWrite(zStep, HIGH);
            delayMircoseconds(DELAY);
            digitalWrite(xStep, LOW);
            digitalWrite(yStep, LOW);
            digitalWrite(zStep, LOW);
            delayMircoseconds(DELAY);
        }
    }
}
 int GetDelay(String data) {
    if (data == "fast") {
        return 500;
    } else if (data == "normal") {
        return 1000;
    } else if (data == "reset"){
        return 0;
    } else if (data == "stop"){
        return -1;
    }
}


