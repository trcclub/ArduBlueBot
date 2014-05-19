#include <Servo.h> 

#define AUTO_ROBOT_MODE 1
#define BT_ROBOT_MODE 2
#define SERVO_POSITIONS_LENGTH 7
int servo_positions[SERVO_POSITIONS_LENGTH]={5,30,60,90,120,150,173};

Servo servo1;
int robotMode = BT_ROBOT_MODE;

void loop_auto_mod(){
  if (robotMode==AUTO_ROBOT_MODE){
    scan_distance();
    stopMotors();
  }
}
void setup_auto_mod(){
  servo1.attach(10);
  Serial.print("setup_auto_mod");
}

void scan_distance(){
  static unsigned long lasttime=millis();
  if (millis()-lasttime > 500){
    
    int servo_position = next_servo_position();
    moveServo(servo_position);
    lasttime=millis();
  }  
}

void moveServo(int servo_position){
  servo1.write(servo_position);
}
int next_servo_position(){
  static int servo_position_index=0;
  static int servo_step=1;


  if (servo_position_index==SERVO_POSITIONS_LENGTH-1 || 
  (servo_position_index==0 && servo_step<0 )){
    servo_step*=-1;
  }
  servo_position_index+=servo_step;
  int retorno= servo_positions[servo_position_index];

  return retorno;
} 
