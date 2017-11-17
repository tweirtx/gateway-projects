#pragma config(Motor,  port6,           clawmotor,     tmotorVex393_MC29, openLoop)
task main()
{
	while (true)
	{
		startMotor(clawmotor, -100);							//Start the claw motor
		wait(0.25);															//Give it a bit of time to open
		startMotor(clawmotor, 100);
		wait(0.25);
		stopMotor(clawmotor);										//Stop the claw motor
	}
}
