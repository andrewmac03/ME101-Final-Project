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
void drive(int direction)
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
task main()
{
    //1 for X, 0 for O
    int gameboard[3][3] = {{0}};
}
