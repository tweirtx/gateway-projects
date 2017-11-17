#pragma config(Sensor, in1,    finishlinesensor, sensorLineFollower)
#pragma config(Sensor, dgtl1,  startbutton,    sensorTouch)
#pragma config(Motor,  port2,           frontmotor,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           backmotor,     tmotorVex393_MC29, openLoop, reversed)
task main()
{
	untilBump(startbutton);
	int accelerationcurve = 1;
	while (accelerationcurve < 127)	//While the acceleration curve is less than 63,
		{
			accelerationcurve = accelerationcurve + 1; 	//The acceleration curve is now the previous acceleration curve plus 2
			startMotor(frontmotor, accelerationcurve);	//Start the front motor at the acceleration curve
			startMotor(backmotor, accelerationcurve);		//Start the rear motor at the acceleration curve
			wait(0.5);																	//Wait 0.01 seconds to allow the motor to get to speed
		}


}
