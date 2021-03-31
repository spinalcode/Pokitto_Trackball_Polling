#include "Pokitto.h"
#include "mouse.h"

using PC = Pokitto::Core;
using PD = Pokitto::Display;
using PB = Pokitto::Buttons;


DigitalIn button0 = DigitalIn(EXT0); // Button
DigitalIn ballLeft = DigitalIn(EXT3); // Left
DigitalIn ballRight = DigitalIn(EXT4); // Right
DigitalIn ballUp = DigitalIn(EXT5); // Up
DigitalOut ledGreen = DigitalOut(EXT6); // Green LED
DigitalOut ledWhite = DigitalOut(EXT7); // White LED
DigitalIn ballDown = DigitalIn(EXT8); // Down
DigitalOut ledBlue = DigitalOut(EXT9); // Blue LED
DigitalOut ledRed = DigitalOut(EXT10); // Red LED

int main() {
    PC::begin();
    PD::persistence = false;
    PD::invisiblecolor = 0;

    button0.mode(PullUp); // Button Low active
    ballLeft.mode(PullUp); // Left
    ballRight.mode(PullUp); // Right
    ballUp.mode(PullUp); // Up
    ballDown.mode(PullUp); // Down

    ledGreen.write(LOW); // Green
    ledWhite.write(LOW); // White
    ledBlue.write(LOW); // Blue
    ledRed.write(LOW); // Red

    int oldUp, oldDown, oldLeft, oldRight, up, down, left, right;
    int px,py = 0;
    int speed = 3;

    float sx = 0.0;
    float sy = 0.0;

    while( PC::isRunning() ){
        PD::update();
        
        up = ballUp.read();
        down = ballDown.read();
        left = ballLeft.read();
        right = ballRight.read();

        if(up != oldUp){
            oldUp = up;
            py-=speed;
        }
        if(down != oldDown){
            oldDown = down;
            py+=speed;
        }
        if(left != oldLeft){
            oldLeft = left;
            px-=speed;
        }
        if(right != oldRight){
            oldRight = right;
            px+=speed;
        }

        if(PB::upBtn()){ledRed.write(HIGH);}else{ledRed.write(LOW);}
        if(PB::downBtn()){ledGreen.write(HIGH);}else{ledGreen.write(LOW);}
        if(PB::leftBtn()){ledBlue.write(HIGH);}else{ledBlue.write(LOW);}
        if(PB::rightBtn()){ledWhite.write(HIGH);}else{ledWhite.write(LOW);}


        PD::printf("X: %d, Y: %d\n", px,py);
        PD::drawBitmap(px,py,mouse);
    }
}