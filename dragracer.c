#pragma config(Sensor, in1,    finishlinesensor, sensorLineFollower)
#pragma config(Sensor, dgtl1,  startbutton,    sensorTouch)
#pragma config(Motor,  port2,           frontmotor,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           backmotor,     tmotorVex393_MC29, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task finishline()												//Define the finishline task
{
	untilLight(2000, finishlinesensor);		//Wait until the line follower detects the line
	stopMotor(backmotor);									//Stop the back motor
	stopMotor(frontmotor);								//Stop the front motor
}
/*task emergencystop()
{
untilBump(startbutton);
stopMotor(backmotor);
stopMotor(frontmotor);
stopTask(main);
startTask(main);
}
*/
task main()
{
	while (true)													//Run forever
	{
		untilBump(startbutton);					//Wait for the start button
		startTask(finishline);					//Run the finish line task
		int accelerationcurve = 1;			//Define the accelerationcurve variable as a 1 integer
		while (accelerationcurve < 63)	//While the acceleration curve is less than 63,
		{
			accelerationcurve = accelerationcurve + 2; 	//The acceleration curve is now the previous acceleration curve plus 2
			startMotor(frontmotor, accelerationcurve);	//Start the front motor at the acceleration curve
			startMotor(backmotor, accelerationcurve);		//Start the rear motor at the acceleration curve
			wait(0.01);																	//Wait 0.01 seconds to allow the motor to get to speed
		}
		startMotor(frontmotor, 127);									//Start the front motor at full power
		startMotor(backmotor, 127);										//Start the rear motor at full power
		wait(5);																			//Wait 5 seconds
		stopMotor(backmotor);													//Stop the back motor
		stopMotor(frontmotor);												//Stop the front motor
		/*	startMotor(backmotor, 127);					//Start the back motor at full power
		startMotor(frontmotor, 64);					//Start the front motor at half speed (to reduce wheelie chance)
		wait(2.5);													//Wait 2.5 seconds for tires to get grip.
		startMotor(frontmotor, 127);				//Start the front motor at full power to increase speed
		*/

	}
}

/*
Todo list:
Tweak acceleration
*/
