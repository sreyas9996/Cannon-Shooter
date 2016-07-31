
#include<stdlib.h>
#include <math.h>

#ifdef __APPLE__
#include<openGL/openGL.h>
#include<GLUT/glut.h>
#else
#include<GL/glut.h>
#endif

double ballX = 0.6;
double ballY = 0.3;
double ballZ = -1.2;
double bombX = -0.55;
double bombY = 0.0;
double bombZ = -1.0;
double rtri = 0.0;
double blx;

int flag=1;
int space=0;
float t=10;
int stop=0;


double rotate_by_key=0;

double speed=20;
double rtrx=-2.7f;


int g=7;

void drawBomb(void) {
    
    glColor3f(0.0,0.0,0.0 );              // create bomb
    glTranslatef(bombX,bombY,bombZ);
    glutSolidSphere (0.02, 30, 30);
    space=1;
    
    
    
}
void blast(void) {                         // create blast
    flag=2;
    blx=(rtri*0.184483)-0.1;
    glColor3f(1.0,0.0,0.0 );
    
    glTranslatef(blx,-0.3,-1.2);
}


void keyPress(int key,int x,int y)                 // key cotrols
{
    
    if(key==27)
        exit(0);
    if(key==GLUT_KEY_RIGHT&&rotate_by_key<70)
        rotate_by_key+=5;
    if(key==GLUT_KEY_LEFT&&rotate_by_key>0)
        rotate_by_key-=5;
    if(key==GLUT_KEY_UP&&speed<30)
        speed+=2;
    if(key==GLUT_KEY_DOWN&&speed>10)
        speed-=2;
    if (key==' ') {
        t=0;
        bombX=-0.55;
        bombY=0.0f;
        drawBomb();
    }
    
    glutPostRedisplay();
    
}

void drawSun(void) {
    
    glColor3f(1.0,0.75,0.0 );
    glTranslatef(ballX,ballY,ballZ);
    glutSolidSphere (0.05, 30, 30);             //create sun.
    
}


void drawAv(void) {
    
    glBegin(GL_POLYGON);                        // create sea
    
    glColor3f(0.30,0.30,1.00);
    
    glVertex3f(-0.4,-0.7,-1.0);
    
    glVertex3f(-0.4,-0.3,-1.0);
    
    glVertex3f(0.67,-0.3,-1.0);
    
    glVertex3f(0.67,-0.7,-1.0);
    glEnd();
    glBegin(GL_POLYGON);                        // create land
    
    glColor3f(0.91,0.76,0.65);
    
    glVertex3f(-0.9,-0.7,-1.0);
    
    glVertex3f(-0.9,-0.03,-1.0);
    
    glVertex3f(-0.4,-0.03,-1.0);
    
    glVertex3f(-0.4,-0.7,-1.0);
    
    glEnd();
    glBegin(GL_POLYGON);                        // create grass
    
    glColor3f(0.196078,0.8,0.196078);
    
    glVertex3f(-0.9,-0.03,-1.0);
    
    glVertex3f(-0.9,0.0,-1.0);
    
    glVertex3f(-0.4,0.0,-1.0);
    
    glVertex3f(-0.4,-0.03,-1.0);
    
    glEnd();
    
    
}

void drawClouds(){}


void initRendering() {
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_NORMALIZE);
}


void handleResize(int w, int h) {      // handles resizing
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0,(double)w / (double)h,1.0,200.0);
}
void canon()
{
    
    glBegin(GL_POLYGON);                // create cannon
    glColor3f(0.0f,0.0f,0.0f);
    glVertex3f(-0.65f, 0.0f, -1.0f);
    glVertex3f(-0.60f, 0.03f, -1.0f);
    glVertex3f(-0.50f, 0.03f, -1.0f);
    glVertex3f(-0.45f, 0.0f, -1.0f);
    glEnd();
    glRotatef(  rotate_by_key,-0.55f, 0.0f, -1.0f );
    glBegin(GL_POLYGON);
    
    glVertex3f(-0.525f, 0.0f, -1.0f);
    glVertex3f(-0.525f, 0.08f, -1.0f);
    glVertex3f(-0.575f, 0.08f, -1.0f);
    glVertex3f(-0.575f, 0.0f, -1.0f);
    
    glEnd();
    
    
}
void boat()
{

    glTranslatef(rtri,rtrx,-6.0f);          // create boat
    
    glBegin(GL_POLYGON);
    glColor3f(1.0f,0.0f,0.0f);
    glVertex3f(-1.0f, 1.0f, 0.0f);
    glVertex3f(-0.4f, 1.0f, 0.0f);
    glVertex3f(-0.5f, 0.9f, 0.0f);
    glVertex3f(-0.9f, 0.9f, 0.0f);
   
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex3f(-1.0f, 1.1f, 0.0f);
    glVertex3f(-0.75f, 1.1f, 0.0f);
    glVertex3f(-0.75f, 1.5f, 0.0f);
    
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex3f(-0.4f, 1.1f, 0.0f);
    glVertex3f(-0.65f, 1.1f, 0.0f);
    glVertex3f(-0.65f, 1.5f, 0.0f);
    
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex3f(-0.69f, 1.0f, 0.0f);
    glVertex3f(-0.69f, 1.5f, 0.0f);
    glVertex3f(-0.71f, 1.5f, 0.0f);
    glVertex3f(-0.71f, 1.0f, 0.0f);
    glEnd();
    if (flag==1) {
        rtri+=0.02f;
        if(rtri>4.4)
            flag=0;
    }
    else if (flag==0){
        rtri-=0.02f;
        if(rtri<-1.4)
            flag=1;
    }
    else if (flag==2){
        rtrx-=0.02f;
        blx-=0.02f;
    }
    
}
void speedMeter()
{
    glBegin(GL_POLYGON);                // create speed meter
    glColor3f(0.0f,1.0f,0.0f);
    glVertex3f(-0.6f, 0.32f, -1.0f);
    glVertex3f(-0.6f, 0.35f, -1.0f);
    glColor3f(1.0f,0.0f,0.0f);
    glVertex3f(-0.4f, 0.35f, -1.0f);
    glVertex3f(-0.4f, 0.32f, -1.0f);
    glEnd();
    glTranslatef(((speed-20)/50)-0.4, 0.4,-1.0);
    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex3f(-0.6f, 0.33f, -1.0f);
    glVertex3f(-0.6f, 0.4f, -1.0f);
    glVertex3f(-0.6f, 0.33f, -1.0f);
    glVertex3f(-0.61f, 0.34f, -1.0f);
    glVertex3f(-0.6f, 0.33f, -1.0f);
    glVertex3f(-0.59f, 0.34f, -1.0f);
    glEnd();
    
    
}

void drawScene()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);      // handles all display functions
    glClearColor(0.22,0.69,0.87,0.0);
    glMatrixMode(GL_MODELVIEW);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    
    glLoadIdentity();
 
    glPushMatrix();
    drawSun();
    glPopMatrix();
    
    glPushMatrix();
    drawAv();
    glPopMatrix();
    if (space==1) {
    glPushMatrix();
    drawBomb();
    glPopMatrix();
    }
    if (stop==1) {
        
    glPushMatrix();
    blast();
    glPopMatrix();
    
    }
    glPushMatrix();
    speedMeter();
    glPopMatrix();
    
    glPushMatrix();
    boat();
    glPopMatrix();
    
    glPushMatrix();
    canon();
    glPopMatrix();
    
    glutSwapBuffers();
}

void update(int value) {
    
    if (space==1) {
        t+=0.25;
        bombX+=(speed*sin(rotate_by_key*0.0174533)*t)/5000;
        bombY+=((speed*cos(rotate_by_key*0.0174533)*t)-(5*t*t))/5000;
    }
    if (bombY<-0.4) {
        space=0;
    }
    if ((bombX<=(rtri*0.184483)&&bombX>=(rtri*0.184483)-0.2)&&bombY<=-0.2&&bombY>=-0.4) {
        stop=1;
    }
    glutPostRedisplay(); //Tell GLUT that the display has changed
    
    //Tell GLUT to call update again in 25 milliseconds
    glutTimerFunc(25, update, 0);
}

int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
    
    glutInitWindowSize(400,400);
    
    glutCreateWindow("Sun");
    
    initRendering();
    
    glutDisplayFunc(drawScene);
    
    glutSpecialFunc(keyPress);

    glutFullScreen();
    
    glutReshapeFunc(handleResize);
    
    glutTimerFunc(25, update, 0);
    
    glutMainLoop();
    
    return(0);
}