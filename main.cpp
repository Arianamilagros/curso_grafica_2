/*
 * GLUT Shapes Demo
 *
 * Written by Nigel Stewart November 2003
 *
 * This program is test harness for the sphere, cone
 * and torus shapes in GLUT.
 *
 * Spinning wireframe and smooth shaded shapes are
 * displayed until the ESC or q key is pressed.  The
 * number of geometry stacks and slices can be adjusted
 * using the + and - keys.
 */

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <windows.h>
#include <GL/glut.h>
#endif
#include <stdio.h>
#include <math.h>
#include <iostream>
using namespace std;

static int xc,yc,r;

void inicial()
{
    glClearColor(1.0,1.0,0.0,0.0);
    glMatrixMode(GL_PROJECTION);
    glPointSize(8.0);
    gluOrtho2D(-10,10,-10,10); //coordenadas entre <-10,10>
}
void setPixel(GLint x,GLint y)
{
     glBegin(GL_POINTS);
     x=x+xc;y=y+yc;
     glVertex2f(x,y);
     glEnd();
}

void draw_Circle()
{
    int x,y;
    float p;
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0,0,0);
    x=0;y=r;
    p=(5/4)-r;
    while(x<=y){
        if(p>=0){
            p=p+2*x-2*y+4;
            setPixel(x,y);setPixel(y,x);
            x=-1*x;setPixel(x,y);
            setPixel(y,x);
            y=-1*y;setPixel(x,y);
            setPixel(y,x);
            x=-1*x;setPixel(x,y);
            setPixel(y,x);y=-1*y;
            y--;x++;
       }
       else{
            p=p+2*x+3;
            setPixel(x,y);setPixel(y,x);
            x=-1*x;setPixel(x,y);
            setPixel(y,x);
            y=-1*y;setPixel(x,y);
            setPixel(y,x);
            x=-1*x;setPixel(x,y);
            setPixel(y,x);y=-1*y;
            x++;
           }
        }
        glFlush();
}

int main (int argc,char **argv)
{
     cout<<"INGRESAR EL CENTRO DEL CIRCULO: "<<endl;
     cin>>xc;
     cin>>yc;
     cout<<"INGRESE RADIO DEL CIRCULO: ";
     cin>>r;
     glutInit(&argc,argv);
     glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
     glutInitWindowPosition(50,25);
     glutInitWindowSize(640,480);
     glutCreateWindow("Dibujando el Circulo ...");
     inicial();
     glutDisplayFunc(draw_Circle);
     glutMainLoop();
     return 0;
}
