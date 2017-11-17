#pragma config(Sensor, in1,    linefollower,   sensorLineFollower)
#pragma config(Sensor, in2,    potentiometer,  sensorPotentiometer)
#pragma config(Sensor, dgtl1,  limitswitch,    sensorTouch)
#pragma config(Sensor, dgtl2,  bumpswitch,     sensorTouch)
#pragma config(Sensor, dgtl12, led,            sensorLEDtoVCC)
#pragma config(Motor,  port1,           claw,          tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port2,           rightmotor,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           leftmotor,     tmotorVex393_MC29, openLoop)

task main()
{
startMotor(rightmotor, 127);
untilPotentiometerGreaterThan(3500, potentiometer);
stopMotor(rightmotor);
wait(1);
startMotor(rightmotor, -127);
untilPotentiometerLessThan(1000, potentiometer);
wait(1);
}
