#include <Arduino.h>
#include <Wire.h>
#include <SoftwareSerial.h>

#include <MeMCore.h>

MeDCMotor motor_9(9);
MeDCMotor motor_10(10);    

void move(int direction, int speed)
{
      int leftSpeed = 0;
      int rightSpeed = 0;
      if(direction == 1){
          leftSpeed = speed;
          rightSpeed = speed;
      }else if(direction == 2){
          leftSpeed = -speed;
          rightSpeed = -speed;
      }else if(direction == 3){
          leftSpeed = -speed;
          rightSpeed = speed;
      }else if(direction == 4){
          leftSpeed = speed;
          rightSpeed = -speed;
      }
      motor_9.run((9)==M1?-(leftSpeed):(leftSpeed));
      motor_10.run((10)==M1?-(rightSpeed):(rightSpeed));
}
        
double angle_rad = PI/180.0;
double angle_deg = 180.0/PI;
void LineFollower();
MeLineFollower linefollower_2(2);
boolean isObstacle();
double isObstac;
char dir;
MeUltrasonicSensor ultrasonic_3(3);
void leftTurning();
void rightTurning();
int xPosition;
int yPosition;
int xMax;
int yMax;
boolean start;


void LineFollower()
{
  
    if(((true&&(1?(linefollower_2.readSensors()&2):!(linefollower_2.readSensors()&2)))) && ((true&&(1?(linefollower_2.readSensors()&1):!(linefollower_2.readSensors()&1))))){

//Serial.println("doing something");
motor_9.run((9)==M1?-(80):(80));
        motor_10.run((10)==M1?-(80):(80));
    }
    
    if(((true&&(1?(linefollower_2.readSensors()&1):!(linefollower_2.readSensors()&1)))) && ((true&&(0?(linefollower_2.readSensors()&2):!(linefollower_2.readSensors()&2))))){
        motor_9.run((9)==M1?-(100):(100));
        motor_10.run((10)==M1?-(70):(70));
    }
    
    if(((true&&(0?(linefollower_2.readSensors()&1):!(linefollower_2.readSensors()&1)))) && ((true&&(1?(linefollower_2.readSensors()&2):!(linefollower_2.readSensors()&2))))){
        motor_9.run((9)==M1?-(70):(70));
        motor_10.run((10)==M1?-(100):(100));
    }
    
}

boolean isObstacle()
{
    if((ultrasonic_3.distanceCm()) < (30)){
        isObstac = 1;
        return true;
    }else{
        isObstac = 0;
        return false;
    }
    
}

void leftTurning()
{
    motor_9.run((9)==M1?-(0):(0));
    
    motor_10.run((10)==M1?-(0):(0));
    
    _delay(1);
    
    motor_9.run((9)==M1?-(75):(75));
    
    motor_10.run((10)==M1?-(75):(75));
    
    _delay(0.45); //changed from 0.5
    
    motor_9.run((9)==M1?-(0):(0));
    
    motor_10.run((10)==M1?-(0):(0));
    
    _delay(2.5);
    
    motor_9.run((9)==M1?-(-75):(-75));
    
    motor_10.run((10)==M1?-(75):(75));
    
    _delay(0.5);
    
    while(!((true&&(0?(linefollower_2.readSensors()&1):!(linefollower_2.readSensors()&1)))))
    {
        _loop();
        motor_9.run((9)==M1?-(-75):(-75));
        motor_10.run((10)==M1?-(75):(75));
    }
    
    motor_9.run((9)==M1?-(0):(0));
    
    motor_10.run((10)==M1?-(0):(0));
    
    _delay(0.5);
    
    while(!((true&&(0?(linefollower_2.readSensors()&2):!(linefollower_2.readSensors()&2)))))
    {
        _loop();
        motor_9.run((9)==M1?-(-75):(-75));
        motor_10.run((10)==M1?-(75):(75));
    }
    
    while(!(((true&&(1?(linefollower_2.readSensors()&2):!(linefollower_2.readSensors()&2)))) && ((true&&(1?(linefollower_2.readSensors()&1):!(linefollower_2.readSensors()&1))))))
    {
        _loop();
        motor_9.run((9)==M1?-(75):(75));
        motor_10.run((10)==M1?-(-75):(-75));
    }
    
}

void Justleft()
{
    
    motor_9.run((9)==M1?-(0):(0));
    
    motor_10.run((10)==M1?-(0):(0));
    
    _delay(2.5);
    
    motor_9.run((9)==M1?-(-75):(-75));
    
    motor_10.run((10)==M1?-(75):(75));
    
    _delay(0.5);
    
    while(!((true&&(0?(linefollower_2.readSensors()&1):!(linefollower_2.readSensors()&1)))))
    {
        _loop();
        motor_9.run((9)==M1?-(-75):(-75));
        motor_10.run((10)==M1?-(75):(75));
    }
    
    motor_9.run((9)==M1?-(0):(0));
    
    motor_10.run((10)==M1?-(0):(0));
    
    _delay(0.5);
    
    while(!((true&&(0?(linefollower_2.readSensors()&2):!(linefollower_2.readSensors()&2)))))
    {
        _loop();
        motor_9.run((9)==M1?-(-75):(-75));
        motor_10.run((10)==M1?-(75):(75));
    }
    
    while(!(((true&&(1?(linefollower_2.readSensors()&2):!(linefollower_2.readSensors()&2)))) && ((true&&(1?(linefollower_2.readSensors()&1):!(linefollower_2.readSensors()&1))))))
    {
        _loop();
        motor_9.run((9)==M1?-(75):(75));
        motor_10.run((10)==M1?-(-75):(-75));
    }
    
}

void rightTurning()
{
    motor_9.run((9)==M1?-(0):(0));
    
    motor_10.run((10)==M1?-(0):(0));
    
    _delay(1);
    
    motor_9.run((9)==M1?-(75):(75));
    
    motor_10.run((10)==M1?-(75):(75));
    
    _delay(0.45); //changed from 0.5
    
    motor_9.run((9)==M1?-(0):(0));
    
    motor_10.run((10)==M1?-(0):(0));
    
    _delay(2.5);
    
    motor_9.run((9)==M1?-(75):(75));
    
    motor_10.run((10)==M1?-(-75):(-75));
    
    _delay(0.5);
    
    while(!((true&&(0?(linefollower_2.readSensors()&2):!(linefollower_2.readSensors()&2)))))
    {
        _loop();
        motor_9.run((9)==M1?-(75):(75));
        motor_10.run((10)==M1?-(-75):(-75));
    }
    
    motor_9.run((9)==M1?-(0):(0));
    
    motor_10.run((10)==M1?-(0):(0));
    
    _delay(0.5);
    
    while(!((true&&(0?(linefollower_2.readSensors()&1):!(linefollower_2.readSensors()&1)))))
    {
        _loop();
        motor_9.run((9)==M1?-(75):(75));
        motor_10.run((10)==M1?-(-75):(-75));
    }
    
    while(!(((true&&(1?(linefollower_2.readSensors()&2):!(linefollower_2.readSensors()&2)))) && ((true&&(1?(linefollower_2.readSensors()&1):!(linefollower_2.readSensors()&1))))))
    {
        _loop();
        motor_9.run((9)==M1?-(-75):(-75));
        motor_10.run((10)==M1?-(75):(75));
    }
    
}

void Justright()
{
       
    motor_9.run((9)==M1?-(0):(0));
    
    motor_10.run((10)==M1?-(0):(0));
    
    _delay(2.5);
    
    motor_9.run((9)==M1?-(75):(75));
    
    motor_10.run((10)==M1?-(-75):(-75));
    
    _delay(0.5);
    
    while(!((true&&(0?(linefollower_2.readSensors()&2):!(linefollower_2.readSensors()&2)))))
    {
        _loop();
        motor_9.run((9)==M1?-(75):(75));
        motor_10.run((10)==M1?-(-75):(-75));
    }
    
    motor_9.run((9)==M1?-(0):(0));
    
    motor_10.run((10)==M1?-(0):(0));
    
    _delay(0.5);
    
    while(!((true&&(0?(linefollower_2.readSensors()&1):!(linefollower_2.readSensors()&1)))))
    {
        _loop();
        motor_9.run((9)==M1?-(75):(75));
        motor_10.run((10)==M1?-(-75):(-75));
    }
    
    while(!(((true&&(1?(linefollower_2.readSensors()&2):!(linefollower_2.readSensors()&2)))) && ((true&&(1?(linefollower_2.readSensors()&1):!(linefollower_2.readSensors()&1))))))
    {
        _loop();
        motor_9.run((9)==M1?-(-75):(-75));
        motor_10.run((10)==M1?-(75):(75));
    }
    
}


void setup(){
  Serial.begin(9600);
  dir = 'E';
  xPosition = 1;
  yPosition = 1;
  xMax = 7;
  yMax = 5;
  start = true;
  
  /*if (isObstacle() == true) {
    Justright();
    dir = 'S';
  }*/
}

void loop(){
  /*if (start == true) {          
    Justright();
    dir = 'S';
    yPosition++;
    start = false;
    atIntersection();
  }*/
  
Serial.println("x:  ");
Serial.print(xPosition);
Serial.println("    y:  ");
Serial.print(yPosition);
  
  if(xPosition == xMax && yPosition == yMax) {
    motor_9.run((9)==M1?-(0):(0));
    
    motor_10.run((10)==M1?-(0):(0));
    return;
  }
    
    while(!(((true&&(0?(linefollower_2.readSensors()&1):!(linefollower_2.readSensors()&1)))) && ((true&&(0?(linefollower_2.readSensors()&2):!(linefollower_2.readSensors()&2))))))
    {
      //Serial.println("LineFollowering");
        _loop();
        LineFollower();
    }
   atIntersection();
    //if(!(((true&&(0?(linefollower_2.readSensors()&1):!(linefollower_2.readSensors()&1)))) && ((true&&(0?(linefollower_2.readSensors()&2):!(linefollower_2.readSensors()&2)))))){
      //Serial.println("atIntersection");
      
    //}
    /*if (isObstacle() == false) {
      rightTurning;
    }*/
    
    
    //_loop();
}

void _delay(float seconds){
    long endTime = millis() + seconds * 1000;
    while(millis() < endTime)_loop();
}

void _loop(){
    
}

/*
LLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLl
LLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL
LLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL
*/

void atIntersection() {
  if (dir == 'E') {
    //Serial.println("E");
    east();
  } else if (dir == 'S') {
    south();
  } else if (dir == 'N') {
    north();
  } else if (dir == 'W') {
    west();
  }
}

void east() {
  //if on the top line:
  //  1. Go forward - E
  //  2. turn right - S
  //  3.turn right again - W
  /* If on the bottom line:  
      1. Go forward - E
      2. Turn left - N
      3. Turn left - W
  */
  if (yPosition == 1) {
    if (isObstacle() == false && xPosition < xMax) {
      LineFollower();
      _delay(0.2);
      xPosition++;
      return;
    }

    rightTurning();

    if (isObstacle() == false) {
      dir = 'S';
      yPosition++;
      return;
    }

    Justright();

    if (isObstacle() == false && xPosition > 1) {
      dir = 'W';
      xPosition--;
      return;
    }

  } else if (yPosition == yMax) {
    if (isObstacle() == false && xPosition < xMax) {
      LineFollower();
      _delay(0.2);
      xPosition++;
      return;
    }

    leftTurning();

    if (isObstacle() == false) {
      yPosition--;
      dir = 'N';
      return;
    }

    Justleft();

    if (isObstacle() == false && xPosition > 1) {
      dir = 'W';
      xPosition--;
      return;
    }
  } else {
    if (isObstacle() == false && xPosition < xMax) {
    
    LineFollower();
//    motor_9.run((9)==M1?-(75):(75));
//    motor_10.run((10)==M1?-(75):(75));
    
    _delay(0.20);
    xPosition++;
    return;
  }
  
    rightTurning();
  
  if (isObstacle() == false && yPosition < yMax) {
    
    yPosition++;
    dir = 'S';
    return;
  } 
    
  
  turn180();
  
  if (isObstacle() == false && yPosition > 1) {
    
      yPosition--;
      dir = 'N';
      
      return;
  }      
  
  
  Justleft();
  
  if (isObstacle() == false && xPosition > 1) {
    
    xPosition--;
    dir = 'W';
    
  }
  }
  
}

void west() {
  if (yPosition == 1) {
    leftTurning();

    if (isObstacle() == false && yPosition < yMax) {
      yPosition++;
      dir = 'S';
      return;
    }

    Justright();

    if (isObstacle() == false && xPosition > 1) {
      xPosition--;
      return;
    }

    turn180();

    if (isObstacle() == false && xPosition < xMax) {
      xPosition++;
      dir = 'E';
      return;
    }
  } else if (yPosition == yMax) {
    rightTurning();

    if (isObstacle() == false) {
      yPosition--;
      dir = 'N';
      return;
    }

    Justleft();

    if (isObstacle() == false && xPosition > 1) {
      xPosition--;
      return;
    }

    turn180();

    if (isObstacle == false && xPosition < xMax) {
      xPosition++;
      dir = 'E';
      return;
    }
  } else {
    leftTurning();
  
  if (isObstacle() == false && yPosition < yMax) {
    yPosition++;
    dir = 'S';
    //LineFollower();
    return;
  }
  
  turn180();
  
  if (isObstacle() == false && yPosition > 1) {
    yPosition--;
    dir = 'N';
    //LineFollower();
    return;
  }
  
  Justleft();
  
  if (isObstacle() == false && xPosition > 1) {
    xPosition--;
    //LineFollower();
    return;
  }
  
  turn180();
  
  if (isObstacle() == false && xPosition < xMax) {
    xPosition++;
    dir = 'E';
    //LineFollower();
  }
  }
}

void north() {
  if (xPosition == 1) {
    rightTurning();

    if (isObstacle() == false && xPosition < xMax) {
      xPosition++;
      dir = 'E';
      return;
    }

    Justleft();
    
    if (isObstacle() == false && yPosition > 0) {
      yPosition--;
      return;
    }

    turn180();

    if (isObstacle == false && yPosition < yMax) {
      yPosition++;
      dir = 'S';
      return;
    }
    
  } else if (xPosition == xMax) {
    if (isObstacle() == false && yPosition > 1) {
      yPosition--;
      return;
    }

    leftTurning();

    if (isObstacle() == false && xPosition > 1) {
      xPosition--;
      dir = 'W';
      return;
    }

    Justleft();

    if (isObstacle() == false && yPosition < yMax) {
      yPosition++;
      dir = 'S';
      return;
    }
  } else {
    rightTurning();
  
  if (isObstacle() == false && xPosition < xMax) {
    xPosition++;
    dir = 'E';
    ////LineFollower();
    return;
  }
  
  Justleft();
  
  if (isObstacle() == false && yPosition > 1) {
    yPosition--;
    ////LineFollower();
    return;
  }
  
  Justleft();
  
  if (isObstacle() == false && xPosition > 1) {
    xPosition--;
    dir = 'W';
    //LineFollower();
    return;
  }
  
  Justleft();
  
  if (isObstacle() == false && yPosition < yMax) {
    yPosition++;
    dir = 'S';
    //LineFollower();
    return;
  }
  }
  
}

void south() {
  if (xPosition == 1) {
    if (isObstacle() == false && yPosition < yMax) {
      yPosition++;
      return;
    }
    leftTurning();

    if (isObstacle() == false) {
      xPosition++;
      dir = 'E';
      return;
    }

    Justleft();

    if (isObstacle() == false && yPosition > 1) {
      yPosition--;
      dir = 'N';
      return;
    }
  } else if (xPosition == xMax) {
    if (isObstacle() == false && yPosition < yMax) {
      yPosition++;
      return;
    }
    rightTurning();

    if (isObstacle() == false) {
      xPosition--;
      dir = 'W';
      return;
    }

    Justright();

    if (isObstacle() == false && yPosition > 1) {
      yPosition--;
      dir = 'N';
      return;
    }
  } else {
    if (isObstacle() == false && yPosition < yMax) {
    LineFollower();
    _delay(0.2);
    yPosition++;
    return;
  }

  leftTurning();

  if (isObstacle() == false && xPosition < xMax) {
    xPosition++;
    dir = 'E';
    return;
  }

  turn180();

  if (isObstacle() == false && xPosition > 0) {
    xPosition--;
    dir = 'W';
    return;
  }

  Justright();

  if (isObstacle() == false && yPosition > 0) {
    yPosition--;
    dir = 'N';
    return;
  }
  }
  
}



void turn180() {
  if ((xPosition == 1 && dir == 'N') || (xPosition == xMax && dir == 'S') || (yPosition == 1 && dir == 'E') || (yPosition == yMax && dir == 'W')) {
    Justright();
    Justright();
  } else if ((xPosition == 1 && dir == 'S') || (xPosition == xMax && dir == 'N') || yPosition == 1 && dir == 'W') || (yPosition == yMax && dir == 'E')) {
    Justleft();
    Justleft();
  } else {
    Justright();
    Justright();
  }
}



