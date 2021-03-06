zIWA -=e[A#pragma config(Sensor, in1,    finishlinesensor, sensorLineFollower)
#pragma config(Sensor, dgtl1,  startbutton,    sensorTouch)
#pragma config(Motor,  port2,           leftmotor,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           rightmotor,     tmotorVex393_MC29, openLoop)

task main()
{
	while (true)														//Repeat forever
	{
		untilBump(startbutton);								//Wait for the start button to be pressed
		startMotor(leftmotor, 127);						//Start the left drive motor
		startMotor(rightmotor, -127);					//Start the right drive motor
		wait(3);															//Wait 3 seconds to clear the start line
		untilLight(2900, finishlinesensor);		//Wait until the finish line sensor detects the finish line
		stopMotor(leftmotor);									//Stop the left motor
		stopMotor(rightmotor);								//Stop the right motor
	}
}
