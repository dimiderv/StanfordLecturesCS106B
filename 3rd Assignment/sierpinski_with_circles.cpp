/*
 * File: SierpinskiTriangle.cpp
 * ----------------------------
 * Name: [TODO: enter name here]
 * Section: [TODO: enter section leader here]
 * This file is the starter code for the Sierpinski Triangle problem from
 * Assignment #3.
 * [TODO: extend the documentation]
 */

#include <iostream>
#include "gwindow.h"
#include<math.h>
#include<simpio.h>
#define PI 3.14159265

void drawCircle(GWindow &gw,double x ,double y, double d);
/* Main program */
void drawFractal(GWindow &gw,double x , double y , double l ,int lvl, int max);
void drawTriangle(GWindow &gw,double x , double y , double l);

int main() {
   GWindow gw(600, 500);
   double width = gw.getWidth();
   double height = gw.getHeight();
    drawCircle(gw,width/2,height/2,200);

        return 0;

}
void drawCircle(GWindow &gw,double x ,double y, double d){
    gw.drawOval(x,y,d,d);
    if(d>2){
        drawCircle(gw,x + d*0.5,y,d *0.5);
        drawCircle(gw,x - d*0.5,y,d *0.5);
        drawCircle(gw,x ,y- d*0.5,d *0.5);


    }
}
