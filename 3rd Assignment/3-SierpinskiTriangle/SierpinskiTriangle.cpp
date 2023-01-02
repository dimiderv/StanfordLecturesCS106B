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


/* Main program */
void drawFractal(GWindow &gw,double x , double y , double l ,int lvl, int max);
void drawTriangle(GWindow &gw,double x , double y , double l);

int main() {
   GWindow gw(600, 500);
   double width = gw.getWidth();
   double height = gw.getHeight();
   int edge_legth;

   int order = 1;
   std::  cout<<"give maximum order ";
   int max_order = getInteger();
   std:: cout<<"give length of edge";
   std::  cin>> edge_legth;
 drawFractal(gw,width/2-edge_legth/2,height/2+sin(PI/3)*edge_legth/2,edge_legth,order,max_order);
//drawTriangle(gw,width/2-edge_legth/2,height/2+sin(PI/3)*edge_legth/2,edge_legth);



        return 0;

}
void drawFractal(GWindow &gw,double x , double y , double l ,int lvl, int max){
    if(lvl == max){
        drawTriangle(gw ,x ,y , l);
    }else{
        drawFractal(gw , x, y, l/2, lvl+1 , max);
        drawFractal(gw , x+l/2, y, l/2, lvl+1, max);
        drawFractal(gw , x+l/4, y- sin(PI/3) * l/2 , l/2 , lvl+1 , max);
    }
}

void drawTriangle(GWindow &gw , double x , double y , double l){
    gw.drawLine( x, y, x + l/2, y - sin(PI/3) * l);
    gw.drawLine( x + l/2 , y - sin(PI/3) * l, x+l , y);
    gw.drawLine( x + l, y , x , y);
}
