#include <windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
#include <iostream>
#include <math.h>
using namespace std;
int postX1=0;
int postY1=0;
float a=1.0;
float b=0.0;
float c=0.0;
float rotasi =1.0;
float scaled=1.0;
void lingkaran(int xp, int yp, int r, int n){
    float a,x,y;
    glBegin(GL_POLYGON);
        a=6.28/n;
        for (int i=0; i<n; i++){
            x = xp+r * cos(i*a);
            y = yp+r * sin(i*a);
            glVertex2d(x,y);
       }
    glEnd();
}
void display(){
    glClear (GL_COLOR_BUFFER_BIT);
    glBegin(GL_LINES);
    for(int i = 0; i < 100; i++){
            if(i==50){
                glColor3f(1,1,0);
                glVertex2d(-50+i,100);
                glVertex2d(-50+i,-100);
            }else{
                glColor3f(1,0,0);
                glVertex2d(-50+i,100);
                glVertex2d(-50+i,-100);
            }
            }
    for(int i = 0; i < 100; i++){
            if(i==50){
                glColor3f(1,1,0);
                glVertex2d(100+i,-50+i);
                glVertex2d(-100+i,-50+i);
            }else{
                glColor3f(1,0,0);
                glVertex2d(100+i,-50+i);
                glVertex2d(-100+i,-50+i);
            }
            }
            glEnd();
            glBegin(GL_POINTS);
             glColor3f(1,0,1);

            glVertex2f(2.0f,3.0f);
            glRotated(90,0,0,1);



            glEnd();

            glPushMatrix();
            glRotated(rotasi,0,0,1);
            glScalef(scaled,scaled,0.0);
            //lingkaran
            glColor3f(1.0,1.0,0.0);
            lingkaran(0+postX1,0+postY1,8,50);
            glColor3f(1.0,1.0,1.0);
            lingkaran(0+postX1,0+postY1,6,50);
            glColor3f(0.0,0.0,0.0);
            lingkaran(0+postX1,0+postY1,5.5,50);
            glColor3f(1.0,1.0,0.0);
            lingkaran(0+postX1,0+postY1,4.5,50);
            //potong lingkaran
            glBegin(GL_POLYGON);
            glColor3f(1.0,1.0,0.0);
            glVertex2d(-5+postX1,-5+postY1);
            glVertex2d(-3+postX1,-1+postY1);
            glVertex2d(-1+postX1,-3+postY1);
            glVertex2d(-3+postX1,-7+postY1);
             glEnd();

            //kotak1
            glBegin(GL_POLYGON);
            glColor3f(a,b,c);
            glVertex2d(-5+postX1,-6+postY1);
            glVertex2d(1+postX1,7+postY1);
            glVertex2d(2.7+postX1,7+postY1);
            glVertex2d(-3+postX1,-6+postY1);
            glEnd();
            //kotak2
            glBegin(GL_POLYGON);
            glColor3f(a,b,c);
            glVertex2d(1+postX1,7+postY1);
            glVertex2d(2.7+postX1,7+postY1);
            glVertex2d(2.7+postX1,-1+postY1);
            glVertex2d(1+postX1,0.5+postY1);
            glEnd();
            //kotak3
            glBegin(GL_POLYGON);
            glColor3f(a,b,c);
            glVertex2d(-1+postX1,-0.5+postY1);
            glVertex2d(1+postX1,-0.5+postY1);
            glVertex2d(1+postX1,-2.3+postY1);
            glVertex2d(-1.5+postX1,-2.3+postY1);
            glEnd();
             //segitiga1
            glBegin(GL_POLYGON);
            glColor3f(a,b,c);
            glVertex2d(1+postX1,0.2+postY1);
            glVertex2d(2.7+postX1,-1.3+postY1);
            glVertex2d(1+postX1,-3+postY1);
            glEnd();

            //segitiga2
            glBegin(GL_POLYGON);
            glColor3f(a,b,c);
            glVertex2d(1+postX1,-3.3+postY1);
            glVertex2d(2.7+postX1,-1.7+postY1);
            glVertex2d(2.7+postX1,-3.3+postY1);
            glEnd();
             //lineA
            glBegin(GL_LINE_LOOP);
            glColor3f(0.0,0.0,1.0);
            glRotated(90.0,1,0,0);
            glVertex2d(-5+postX1,-6+postY1);
            glVertex2d(1+postX1,7+postY1);
            glVertex2d(2.7+postX1,7+postY1);
            glVertex2d(2.7+postX1,-1+postY1);
            glVertex2d(1.1+postX1,0.5+postY1);
            glVertex2d(1.1+postX1,3.5+postY1);
            glVertex2d(-0.6+postX1,-0.5+postY1);
            glVertex2d(1+postX1,-0.5+postY1);
            glVertex2d(1+postX1,0.2+postY1);
            glVertex2d(2.7+postX1,-1.3+postY1);
            glVertex2d(1+postX1,-3+postY1);
            glVertex2d(1+postX1,-2.3+postY1);
            glVertex2d(-1.4+postX1,-2.3+postY1);
            glVertex2d(-3+postX1,-6+postY1);
            glEnd();
            glBegin(GL_LINE_LOOP);
            glColor3f(0.0,0.0,1.0);
            glVertex2d(1+postX1,-3.3+postY1);
            glVertex2d(2.7+postX1,-1.7+postY1);
            glVertex2d(2.7+postX1,-3.3+postY1);
            glEnd();
            glPopMatrix();
            glFlush ();
}
void inputan(unsigned char key,int x,int y){
            //kanan
            if(key=='d' || key == 'D'){
                postX1 += 2;
               cout <<  postX1<< endl;
                display();
            }
            //kiri
            if(key == 'a' || key == 'A'){
                 postX1 -= 2;
                cout <<  postX1 << endl;
               display();
            }
            //atas
            if(key == 'w' || key == 'W'){
                 postY1+= 2;
                cout <<  postY1 << endl;
                display();
                }
            //bawah
            if(key == 's' || key == 'S'){
                 postY1 -= 2;
                cout <<  postY1 << endl;
                display();
            }
            //serong kiri atas
            if(key == 'q' || key == 'q'){
                 postX1-= 2;
                 postY1+= 2;
                cout <<  postY1 << endl;
                display();
                }
            //serong kanan atas
            if(key == 'e' || key == 'e'){
                postX1+= 2;
                postY1+= 2;
                cout <<  postY1 << endl;
                display();
            }
            //serong kiri bawah
            if(key == 'z' || key == 'z'){
                 postX1-= 2;
                 postY1-= 2;
                cout <<  postY1 << endl;
                display();
                }
            //serong kanan bawah
            if(key == 'c' || key == 'c'){
                 postX1+= 2;
                 postY1-= 2;
                cout <<  postY1 << endl;
                display();
            }
            //warna
            if(key == '1'){
                 a = 1.0;
                 b = 0.0;
                 c = 0.0;
                cout <<  "merah" << endl;
                display();
            }
            if(key == '2'){
                 a = 0.0;
                 b = 1.0;
                 c = 0.0;
                cout <<  "hijau" << endl;
                display();
            }
            if(key == '3'){
                 a = 0.0;
                 b = 0.0;
                 c = 1.0;
                cout <<  "biru" << endl;
                display();
            }
            if(key == '4'){
                 a = 1.0;
                 b = 1.0;
                 c = 0.0;
                cout <<  "kuning" << endl;
                display();
            }
            if(key == '5'){
                 a = 1.0;
                 b = 0.0;
                 c = 1.0;
                cout <<  "ungu" << endl;
                display();
            }
            if(key == '6'){
                 a = 0.0;
                 b = 1.0;
                 c = 1.0;
                cout <<  "biru muda" << endl;
                display();
            }

            //rotate kiri
             if (key == 'o' || key == 'O')
            {
                rotasi += 1;
                cout << rotasi << endl;
                display();
            }
            //rotate kanan
            if (key == 'p' || key == 'P')
            {
                rotasi -= 1;
                cout << rotasi << endl;
                display();
            }
            //reset ke titik 0 ketika mau rotate
            if (key == 'l' || key == 'L')
            {
                postX1=postX1*0;
                postY1=postY1*0;
                rotasi=0;
                cout << rotasi << endl;
                display();
            }
            //zoom in
            if (key == 'm' || key == 'M')
            {
                scaled += 0.01;
                cout << scaled << endl;
                display();
            }
            //zoom out
            if (key == 'n' || key == 'N')
            {
                scaled -= 0.01;
                cout << scaled << endl;
                display();
            }
}

void myinit()
{
	glClearColor(1,1,1,0);  //untuk memberi warna pada background
	glColor3f(1.0, 0.0, 0.0); // color pada object
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-20.0, 20.0, -20.0, 20.0);  // kordinat pada area menggambar
	glMatrixMode(GL_MODELVIEW);
	glPointSize(10);

}
int main(int argc, char *argv[])
{
    glutInitWindowSize(600,600);
    glutInitWindowPosition(100,100);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutCreateWindow("190411100127_muhammad fahmi ady susilo");
    glutDisplayFunc(display);
    glutKeyboardFunc(inputan);
    myinit();
    glutMainLoop();
    return 0;
}
