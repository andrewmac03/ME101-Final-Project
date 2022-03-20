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
            whoseturn = 1;
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
            drive(currentSquare, upCounter);
        }


        whoseTurn *= -1;
    }

}