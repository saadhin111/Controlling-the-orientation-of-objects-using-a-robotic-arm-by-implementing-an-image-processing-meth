#include <Servo.h>		//servo motor library
#define S0 4			//Servo motor 1
#define S1 5			//Servo motor 2
#define S2 6			//Servo motor 3
#define S3 7			//Servo motor 4
#define S4 8			//servo motor 5
const int analogInput = A0;
Servo servo;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;
int degree;

void setup() {
	Serial.begin(9600);
	pinMode(2, OUTPUT);
	pinMode(S0, OUTPUT);
	pinMode(S1, OUTPUT);
	pinMode(S2, OUTPUT);
	pinMode(S3, OUTPUT);
	pinMode(S4, OUTPUT);
	
servo.attach(3);	  //attaches the servo 1 on pin3 to the servo object
servo2.attach(9);	  //attaches the servo 2 on pin9 to the servo object
servo3.attach(10);	//attaches the servo 3 on pin10 to the servo object
servo4.attach(13);	//attaches the servo 4 on pin13 to the servo object
servo5.attach(14);	//attaches the servo 5 on pin14 to the servo object
Serial.begin(9600);
servo.write(180);	  //servo motor 1 initial position (x-axis)
servo2.write(180);	//servo motor 2 initial position (y-axis)
servo3.write(45);	  //servo motor 3 initial position (y-axis)
servo4.write(0);	  //servo motor 4 initial position (x-axis)
servo5.write(30);	  //servo motor 5 initial position (Grip)
}

void loop
{
	if(Serial.available() > 0)
	 {
		float info;
		info= Serial.parseFloat('\n');
		
if(info.equals("0 degrees")){
for (position=45; position>=0; position -=1){ //moves servo 3 from 45 to 0 degrees
servo3.write(position);		                    //instruction to move the servo to defined position
delay(15);	                                  //stops other motions for 15ms
}
for(position=30; position>=20; position-=1){  //moves servo 5 by 10 degrees from 30 to 20
//closes grip
servo5.write(position);//give instruction to move to desired position
delay(15);	                                  //stops other motions for 15ms
}
for(position=0;position<=45;position+=1){     //moves servo3 from 0 to 45 degrees
servo3.write(position);
delay(15);	                                  //stops other motions for 15ms
}
for(position=180;position>=135;position-=1){  //moves servo2 from 180 to 135 degrees
servo2.write(position);                       //give instruction to servo2 to move to desired position
delay(15);	                                  //stops other motions for 15ms
}
for(position=180;position>=90;position-=1){   //moves servo1 to from 180 to 90 degrees
//moves to make change of 90 degree
servo.write(position);
delay(15);	                                  //stops other motions for 15ms
}
for(position=135;position<=180;position+=1){  //moves servo to from 180 to 135 degrees
servo2.write(position);                     	//moves servo to desired position
delay(15);                                  	//stops other motions for 15ms
}
for(position=45;position>=0;position-=1)      //moves servo3 from 45 to 0 degrees
servo3.write(position);
delay(15);	                                  //stops other motions for 15ms
}
for(position=20:position<=30; position+=1)    //moves servo5 from 20 to 30 degrees
//opens grip
servo5.write(position);                       //give instruction to move to desired position
delay(15);	                                  //stops other motions for 15ms
}
for(position=0;position<=45;position+=1){     //moves servo3 from 0 to 45 degrees
servo3.write(position);
delay(15);	                                  //stops other motions for 15ms
}
for(position=180;position>=135;position-=1){  //moves servo2 from 180 to 135 degrees
servo2.write(position);                       //give instruction to servo2 to move to desired position
delay(15);	                                  //stops other motions for 15ms
}
for(position=90;position<=180;position+=1){   //moves servo1 to from 90 to 180 degrees
//moves base by 90 degrees
servo.write(position);
delay(15);	                                  //stops other motions for 15ms
}
for(position=135;position<=180;position+=1){  //moves servo to from 180 to 135 degrees
servo2.write(position);	                      //moves servo to desired position
delay(15);	                                  //stops other motions for 15ms
}delay(1000);
}

else                                          //every angle other than 0 degrees
for (position=45; position>=0; position -=1){ //moves servo 3 from 45 to 0 degrees
servo3.write(position);		                    //instruction to move the servo to defined position
delay(15);	                                  //stops other motions for 15ms
}
for(position=30; position>=20; position-=1){  //moves servo 5 by 10 degrees from 30 to 20
//closes grip
servo5.write(position);                       //give instruction to move to desired position
delay(15);	                                  //stops other motions for 15ms
}
for(position=0;position<=45;position+=1){     //moves servo3 from 0 to 45 degrees
servo3.write(position);
delay(15);	                                  //stops other motions for 15ms
}
for(position=180;position>=135;position-=1){  //moves servo2 from 180 to 135 degrees
servo2.write(position);                       //give instruction to servo2 to move to desired position
delay(15);	                                  //stops other motions for 15ms
}
for(position=180;position>=90;position-=1){   //moves servo1 to from 180 to 90 degrees
//moves to make change of 90 degree
servo.write(position);
delay(15);	                                  //stops other motions for 15ms
}
for(position=135;position<=180;position+=1){  //moves servo to from 180 to 135 degrees
servo2.write(position);	                      //moves servo to desired position
delay(15);	                                  //stops other motions for 15ms
}
for(position=0;position<=info;position+=1){   //moves servo4 from 0 to match the orientation of the object
//orientation correction from position 2 to position 1
servo4.write(position);                       //move to desired position
delay(15);	                                  //stops other motions for 15ms
}
for(position=45;position>=0;position-=1)      //moves servo3 from 45 to 0 degrees
servo3.write(position);
delay(15);	                                  //stops other motions for 15ms
}
for(position=20:position<=30; position+=1)    //moves servo5 from 20 to 30 degrees
//opens grip
servo5.write(position);                       // give instruction to move to desired position
delay(15);	                                  //stops other motions for 15ms
}
for(position=0;position<=45;position+=1){     //moves servo3 from 0 to 45 degrees
servo3.write(position);
delay(15);	                                  //stops other motions for 15ms
}
for(position=info;position>=0;position-=1){   //moves servo4 from detected orientation and corrects it back to 0 degrees
//orientation correction to default position
servo4.write(position);                       //move to desired position
delay(15);	                                  //stops other motions for 15ms
}
for(position=180;position>=135;position-=1){  //moves servo2 from 180 to 135 degrees
servo2.write(position);                       //give instruction to servo2 to move to desired position
delay(15);	                                  //stops other motions for 15ms
}
for(position=90;position<=180;position+=1){   //moves servo1 to from 90 to 180 degrees
//moves base by 90 degrees
servo.write(position);
delay(15);	                                  //stops other motions for 15ms
}
for(position=135;position<=180;position+=1){  //moves servo to from 180 to 135 degrees
servo2.write(position);	                      //moves servo to desired position
delay(15);	                                  //stops other motions for 15ms
}
delay(1000);
}
}
