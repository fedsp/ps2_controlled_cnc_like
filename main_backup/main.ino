#include "PS2X_lib.h"

PS2X ps2x;

int error = 0;
byte type = 0;
byte vibrate = 0;

void setup()
{
    Serial.begin(115200);

    error = ps2x.config_gamepad(12, 10, 9, 11, false, false);

    if (error == 0)
    {
        Serial.println("Found Controller, configured successful");
        Serial.println("Try out all the buttons, X will vibrate the controller, faster as you press harder;");
        Serial.println("holding L1 or R1 will print out the analog stick values.");
        Serial.println("Go to www.billporter.info for updates and to report bugs.");
    }

    else if (error == 1)
        Serial.println("No controller found, check wiring, see readme.txt to enable debug. visit www.billporter.info for troubleshooting tips");

    else if (error == 2)
        Serial.println("Controller found but not accepting commands. see readme.txt to enable debug. Visit www.billporter.info for troubleshooting tips");

    else if (error == 3)
        Serial.println("Controller refusing to enter Pressures mode, may not support it. ");

    type = ps2x.readType();

    switch (type)
    {
    case 0:
        Serial.println("Unknown Controller type");
        break;
    case 1:
        Serial.println("DualShock Controller Found");
        break;
    case 2:
        Serial.println("GuitarHero Controller Found");
        break;
    default:
        break;
    }
}

void moveMotors(int number)
{
    return;
}

void loop()
{
    ps2x.read_gamepad(false, vibrate);

    if (ps2x.ButtonPressed(PSB_GREEN))
    {
        Serial.println("Triangle just pressed");
        moveMotors(1);
    }

    if (ps2x.ButtonPressed(PSB_RED))
    {
        Serial.println("Circle just pressed");
        moveMotors(2);
    }

    if (ps2x.ButtonPressed(PSB_BLUE))
    {
        Serial.println("X just pressed");
        moveMotors(3);
    }

    if (ps2x.ButtonPressed(PSB_PINK))
    {
        Serial.println("Square just pressed");
        moveMotors(4);
    }

    if (ps2x.ButtonPressed(PSB_PAD_UP))
    {
        Serial.println("Up just pressed");
        moveMotors(5);
    }

    if (ps2x.ButtonPressed(PSB_PAD_DOWN))
    {
        Serial.println("Down just pressed");
        moveMotors(6);
    }

    if (ps2x.ButtonPressed(PSB_PAD_LEFT))
    {
        Serial.println("Left just pressed");
        moveMotors(7);
    }

    if (ps2x.ButtonPressed(PSB_PAD_RIGHT))
    {
        Serial.println("Right just pressed");
        moveMotors(8);
    }
}
