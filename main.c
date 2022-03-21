/*
    TODO:
    - Finish configure sensors function
    - Finish drive function
    - Finish draw function
    - Create 'hard' mode intelligence for robot
    - Clean up main function, logic for gameOver and ensure robot works as expected
*/

void configureSensors()
{
   	SensorType[S1] = sensorEV3_Touch;
	SensorType[S2] = sensorEV3_Ultrasonic;
	SensorType[S3] = sensorEV3_Color;
	SensorType[S4] = sensorEV3_Gyro;
	wait1Msec(50);
	Sensormode = modeEV3Gyro_Calibration;
	wait1Msec(50);
	Sensormode = modeEV3Gyro_RateAndAngle;
}

//1 for x win -1 for O win 0 for no win
//assuming x is 1 o is -1 and 0 is unused this is different from current config but is easier for checking with this method because of sum
int GameOver(int gameBoard[3][3])
{
	//check col victory
	int sum = 0;
	int count1 =0;
	while(abs(sum) < 3 && count1 < 3)
	{	
		sum = 0;
		for(int count2 = 0; count2 < 3; count2++)
		{
			sum += gameBoard[count1][count2];
		}
		count1++;
	}
	//check row victory
	if(abs(sum) != 3)
	{
		while(abs(sum) < 3 && count1 < 3)
		{	
			sum = 0;
			for(int count2 = 0; count2 < 3; count2++)
			{
				sum += gameBoard[count2][count1];
			}
		}
		count1++;
	}
	//check for left diagoal victory
	if(abs(sum) != 3)
	{
		sum = 0;
		for(int count = 0; count < 3; count++)
			sum += gameBoard[count][count];
	}
	//check for right diagoal victory
	if(abs(sum) != 3)
	{
		sum = 0;
		for(int count1 = 2; count1 >= 0; count1--)
			for(int count2 = 0; count2 < 3; count2++)
				sum += gameBoard[count1][count2];
	}
	//return values
	if(sum == 3)
		return 1;
	else if(sum == -3)
		return -1;
	else
		return 0;
}

void penDown()
{
    nMotorEncoder[motorB] = 0;
    motor[motorB]=10;
    while (nMotorEncoder[motorB] < 120)
    {}
    motor[motorB] = 0;
}
void penUp()
{
    nMotorEncoder[motorB] = 0;
    motor[motorB]= -10;
    while (abs(nMotorEncoder[motorB]) < 120)
    {}
    motor[motorB] = 0;
}
void drive(int currentSquare, int futureSquare)
{

}
void drawFunction(int xORo)
{
    //1 for X, 0 for O
}
void rotateAngle(int angle, int motorPower)
{
    resetGyro(S4);
    if (angle > 0)
    {
        motor[motorA] = -motorPower;
        motor[motorD] = motorPower;
    }
    else
    {
        motor[motorA] = motorPower;
        motor[motorD] = -motorPower;
    }
    angle = abs(angle);
    while(abs(getGyroDegrees(S4)) < angle)
    {}
    motor[motorA] = motor[motorD] = 0;
}
void easyMode(int gameBoard[3][3])
{
    int randomChoice = random(1) //random number between 0 and 1
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            if (gameBoard[row][col] == -1)
            {
                //Not entirely complete
                drive(currentSquare, futureSquare);
                drawFunction(randomChoice);
            }
        }
    }
}
task main()
{
    //1 for X, 0 for O, -1 for empty. We assume robot starts at [0][0] for convinience (upper left corner)
    int gameboard[3][3] = {{-1}};
    
    //Starting Game
    displayString(1, "Press touch sensor to start game!");
    while(sensorValue[S1] == 0)
    {}
    
    //Deciding who goes first (this can be changed later)
    displayString(1, "Press UP to go first, DOWN for robot goes first")
    
    int whoseTurn = -1; //-1 for user term, 1 for robot turn
        while(!getButtonPress(buttonAny))
        {}
        if (getButtonPress(buttonDown))
        {
            whoseTurn = 1;
        }
    
    //Main game loop
    bool gameOver = false;
    while (gameOver == false)
    {
        if (whoseTurn == -1)
        {
            int upCounter = 0;
            int currentSquare = 0;
            //The following squence to get button pressess may be flawed
            while(!getButtonPress(buttonAny))
            {}
            while(!getButtonPress(buttonEnter) && getButtonPress(buttonUp))
            {
                upCounter++;
            }
            //Pseudocode-ish. Will fix later
            drive(currentSquare, upCounter); //drive to desired square
            
            displayString(1, "Press UP for X, DOWN for O!";)
            
            //Choosing between X and O
            while(!getButtonPress(buttonAny))
            {}
            if(getButtonPress(buttonUp))
            {
                drawFunction(1);
                gameBoard[X][X] = 1; //NOT CORRECT SYNTAX WILL FIX
            }
            else
            {
                drawFunction(0);
                gameboard[X][X] = 0; //FIX
            }
            whoseTurn *= -1;
        }
    if (whoseTurn == 1)
    {
        easyMode(gameboard); //or HARD MODE
        whoseTurn *= -1;
    }
    //Need to add condition for game end
    }
}
