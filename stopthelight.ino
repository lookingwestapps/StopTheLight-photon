// This #include statement was automatically added by the Particle IDE.
#include "InternetButton/InternetButton.h"

InternetButton b = InternetButton();

void setup() {
    // Tell b to get everything ready to go
    // Use b.begin(1); if you have the original SparkButton, which does not have a buzzer or a plastic enclosure
    // to use, just add a '1' between the parentheses in the code above.
    b.begin();

}

int loopCounter;
int lightIndex;
int redV;
int greenV;
int blueV = 255;
int speed = 1000;
int direction = 1;


void loop() {


    incrLoop();

    if (b.buttonOn(2) && lightIndex == 3)
    {
        lights();
        speed = speed * .9;
        direction = -1;

    } else if (b.buttonOn(2) && lightIndex != 3)
    {
        wrong();
    }

    if (b.buttonOn(4) && lightIndex == 9)
    {
        lights();
        speed = speed * .9;
        direction = 1;

    } else if (b.buttonOn(4) && lightIndex != 9)
    {
        wrong();
    }




    if (loopCounter % speed == 0)
    {
        b.allLedsOff();

        chooseDirection(direction);


        b.ledOn(lightIndex, redV,greenV,blueV);
    }

    if (b.buttonOn(1) && b.buttonOn(3))
    {
        speed = 1000;
    }
}

// _________________________________________________________ rotation of lights

void chooseDirection(int d)
{
    if (d > 0)
    {
        lightIndex++;
        if (lightIndex > 11) {
            lightIndex = 1;
        }
    }

    if (d < 0)
    {
        lightIndex--;
        if (lightIndex < 1) {
            lightIndex = 11;
        }

    }
}


// _________________________________________________________ increase loop

int incrLoop()
{
    if(b.buttonOn(2) != 1 && b.buttonOn(4) != 1){
        loopCounter++;
    }
    return 1;
}


// ________________________________________________________ light color

void lights()
{

    winner();
    loopCounter = 1;
    // lightIndex++;

    if (redV == 0)
    {
        greenV = changeGreenVal(greenV);
    }
    if (greenV == 0)
    {
        blueV = changeBlueVal(blueV);
    }
    if (blueV == 0)
    {
        redV = changeRedVal(redV);
    }

     if(redV == 0 && greenV ==0 && blueV == 0)
     {
         redV = 79;
         greenV = 250;
         blueV = 250;
     }

}

// __________________________________________________________________________________ red value

int changeRedVal(int r)
{
    if(r == 0)
    {
        r = 255;
    } else {
        r = 0;
    }
    return r;
}

// __________________________________________________________________________________ blue value

int changeBlueVal(int b)
{
    if(b == 0)
    {
        b = 255;
    } else {
        b = 0;
    }
    return b;
}

// __________________________________________________________________________________ green value

int changeGreenVal(int g)
{
    if(g == 0)
    {
        g = 255;
    } else {
        g = 0;
    }
    return g;
}


// __________________________________________________________________________________ winners song

void winner()
{
  b.playNote("G5", 4);
}

// ___________________________________________________________________________________ losers song

void wrong()
{
    b.playNote("G3", 2);
}
