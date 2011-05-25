#include "numbers.h"
#include<GL/glut.h>
#include<cmath>
using namespace std;
#define PI 3.14159265358979323846

enum Status{WonByPlayer1,WonByPlayer2,Continue};

Status gameStatus=Continue;

int a=-1;
int b=-2;
int c=-3;
int d=-4;
int e=-5;
int f=-6;
int g=-7;
int h=-8;
int i=-9;
int counter=0;
char z;

void drawCross(GLfloat x, GLfloat y,GLfloat w=1.0)
{
   glLineWidth(5);
   glLoadIdentity();
   glBegin(GL_LINES);
      glVertex2f(x-w, y-w);
      glVertex2f(x+w, y+w);
      glVertex2f(x-w, y+w);
      glVertex2f(x+w, y-w);
   glEnd();
   glLineWidth(1);
}

void drawO(GLfloat x, GLfloat y, GLfloat r=1.0, int n=30)
{
   glLineWidth(5);
   glBegin(GL_LINE_LOOP);
   for(int i=0;i<n;i++)
      glVertex2f(x+r*cos(2*PI*i/n), y+r*sin(2*PI*i/n));
   glEnd();
   glLineWidth(1);
}

void lineCode(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2)
{
   glLineWidth(5);
   glColor3f(0.0, 0.0, 1.0);
   glBegin(GL_LINES);
      glVertex2f(x1, y1);
      glVertex2f(x2, y2);
   glEnd();
   glLineWidth(1);
}

void drawLine()
{
   
if(a==b && b==c)
     {
     if(a==0)
              gameStatus=WonByPlayer1;
              
     else
              gameStatus=WonByPlayer2;
     lineCode(2.0, 8.5, 9.0, 8.5);
      }
     else if(d==e && e==f)
     {
     if(d==0)
              gameStatus=WonByPlayer1;
     else
              gameStatus=WonByPlayer2;
     lineCode(2.0, 5.5, 9.0, 5.5);
     }
     else if(g==h && h==i)
     {
     if(g==0)
              gameStatus=WonByPlayer1;
     else
              gameStatus=WonByPlayer2;
     lineCode(2.0, 2.5, 9.0, 2.5);
     }
     else if(a==d && d==g)
     {
     if(a==0)
              gameStatus=WonByPlayer1;
     else
              gameStatus=WonByPlayer2;
     lineCode(2.5, 2.0, 2.5, 9.0);
     }
     else if(b==e && e==h)
     {
     if(b==0)
              gameStatus=WonByPlayer1;
     else
              gameStatus=WonByPlayer2;
     lineCode(5.5, 2.0, 5.5, 9.0);
     }
     else if(c==f && f==i)
     {
     if(c==0)
              gameStatus=WonByPlayer1;
     else
              gameStatus=WonByPlayer2;
     lineCode(8.5, 2.0, 8.5, 9.0);
     }
     else if(a==e && e==i)
     {
     if(a==0)
              gameStatus=WonByPlayer1;
     else
              gameStatus=WonByPlayer2;
     lineCode(2.0, 9.0, 9.0, 2.0);
     }
     else if(c==e && e==g)
     {
     if(c==0)
              gameStatus=WonByPlayer1;
     else
              gameStatus=WonByPlayer2;
     lineCode(2.0, 2.0, 9.0, 9.0);
     }
}
void init()
{
   glClearColor(0.0, 0.0, 0.0, 0.0);
   glShadeModel(GL_SMOOTH);
}

void defaultScreen()
{
   glClear(GL_COLOR_BUFFER_BIT);
   glColor3f(0.0, 1.0, 0.0);
   
   glBegin(GL_LINES);
      glVertex2f(1.0, 4.0);
      glVertex2f(10.0, 4.0);
      glVertex2f(1.0, 7.0);
      glVertex2f(10.0, 7.0);
      glVertex2f(4.0, 1.0);
      glVertex2f(4.0, 10.0);
      glVertex2f(7.0, 1.0);
      glVertex2f(7.0, 10.0);
   glEnd();
}
   
void display()
{
   defaultScreen();
   if(a==0)
      drawCross(2.5, 8.5);
   else if(a==1)
      drawO(2.5, 8.5);
   else
   drawOne(2.5, 8.5);
   if(b==0)
      drawCross(5.5, 8.5);
   else if(b==1)
      drawO(5.5, 8.5);
   else
      drawTwo(5.5, 8.5);
   if(c==0)
      drawCross(8.5, 8.5);
   else if(c==1)
      drawO(8.5, 8.5);
   else
      drawThree(8.5, 8.5);
   if(d==0)
      drawCross(2.5, 5.5);
   else if(d==1)
      drawO(2.5, 5.5);
   else
      drawFour(2.5, 5.5);
   if(e==0)
      drawCross(5.5, 5.5);
   else if(e==1)
      drawO(5.5, 5.5);
   else
      drawFive(5.5, 5.5);
   if(f==0)
      drawCross(8.5, 5.5);
   else if(f==1)
      drawO(8.5, 5.5);
   else
      drawSix(8.5, 5.5);
   if(g==0)
      drawCross(2.5, 2.5);
   else if(g==1)
      drawO(2.5, 2.5);
   else
      drawSeven(2.5, 2.5);
   if(h==0)
      drawCross(5.5, 2.5);
   else if(h==1)
      drawO(5.5, 2.5);
   else
      drawEight(5.5, 2.5);
   if(i==0)
      drawCross(8.5, 2.5);
   else if(i==1)
      drawO(8.5, 2.5);
   else
      drawNine(8.5, 2.5);
   drawLine();
   glFlush();
}

void reshape(int w, int h)
{
   glViewport(0, 0, w, h);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   gluOrtho2D(0.0, 11.0, 0.0, 11.0);
   glMatrixMode(GL_MODELVIEW);
}

void keyboard(unsigned char key, int x, int y)
{
   switch(key)
   {
      case '1':
               if(gameStatus==Continue)
               {
                    if(a==-1)
                    {
                       if(counter%2==0)
                          a=0;
	              else
                          a=1;
                      counter++;
                    }
               }
	       break;
      case '2':
               if(gameStatus==Continue)
               {
                    if(b==-2)
                    {
                       if(counter%2==0)
                          b=0;
	              else
                          b=1;
                      counter++;
                    }
               }
	       break;
     case '3':
               if(gameStatus==Continue)
               {
                    if(c==-3)
                    {
                       if(counter%2==0)
                          c=0;
	              else
                          c=1;
                      counter++;
                    }
               }
	       break;
    case '4':
              if(gameStatus==Continue)
               {
                    if(d==-4)
                    {
                       if(counter%2==0)
                          d=0;
	              else
                          d=1;
                      counter++;
                    }
               }
	       break;
    case '5':
              if(gameStatus==Continue)
               {
                    if(e==-5)
                    {
                       if(counter%2==0)
                          e=0;
	              else
                          e=1;
                      counter++;
                    }
               }
	       break;
    case '6':
               if(gameStatus==Continue)
               {
                    if(f==-6)
                    {
                       if(counter%2==0)
                          f=0;
	              else
                          f=1;
                      counter++;
                    }
               }
	       break;
    case '7':
               if(gameStatus==Continue)
               {
                    if(g==-7)
                    {
                       if(counter%2==0)
                          g=0;
	              else
                          g=1;
                      counter++;
                    }
               }
	       break;
    case '8':
               if(gameStatus==Continue)
               {
                    if(h==-8)
                    {
                       if(counter%2==0)
                          h=0;
	              else
                          h=1;
                      counter++;
                    }
               }
	       break;
    case '9':
              if(gameStatus==Continue)
               {
                    if(i==-9)
                    {
                       if(counter%2==0)
                          i=0;
	              else
                          i=1;
                      counter++;
                    }
               }
	       break;
    case 'r':
             a=-1;b=-2;c=-3;d=-4;e=-5;f=-6;g=-7;h=-8;i=-9;
             gameStatus=Continue;
             counter=0;
             break;
    default:
            break;
      }
    glutPostRedisplay();
}

void mouse(int button, int state, int x, int y)
{
	switch(button)
	{
	case GLUT_LEFT_BUTTON:
		if(state==GLUT_DOWN)
		{
			if(gameStatus==Continue)
			{
				if(x<200 && y <200 && a==-1)
				{
					if(counter%2==0)
					{
						a=0;
					}
					else
					{
						a=1;
					}
					counter++;
					break;
				}

				else if(x< 7*50 && x>200 && y < 4*50 && b==-2)
				{
					if(counter%2==0)
					{
						b=0;
					}
					else
					{
						b=1;
					}
					counter++;
					break;
				}

				else if(x< 11*50 && x> 7*50 && y < 4*50 && c==-3)
				{
					if(counter%2==0)
					{
						c=0;
					}
					else
					{
						c=1;
					}
					counter++;
					break;
				}

				else if(x< 4*50 && y < 7*50 && y> 200&& d==-4)
				{
					if(counter%2==0)
					{
						d=0;
					}
					else
					{
						d=1;
					}
					counter++;
					break;
				}

				else if(x< 7*50 && x> 200 && y < 7*50 && y> 200 && e==-5)
				{
					if(counter%2==0)
					{
						e=0;
					}
					else
					{
						e=1;
					}
					counter++;
					break;
				}

				else if(x< 11*50 && x> 7*50 && y < 7*50 && y> 200 && f==-6)
				{
					if(counter%2==0)
					{
						f=0;
					}
					else
					{
						f=1;
					}
					counter++;
					break;
				}

				else if(x< 4*50 && y < 11*50 && y > 7*50 && g==-7)
				{
					if(counter%2==0)
					{
						g=0;
					}
					else
					{
						g=1;
					}
					counter++;
					break;
				}

				else if(x< 7*50 && x> 200 && y < 11*50 && y > 7*50  && h==-8)
				{
					if(counter%2==0)
					{
						h=0;
					}
					else
					{
						h=1;
					}
					counter++;
					break;
				}

				else if(x< 11*50 && x> 7*50 && y < 11*50 && y > 7*50  && i==-9)
				{
					if(counter%2==0)
					{
						i=0;
					}
					else
					{
						i=1;
					}
					counter++;
					break;
				}
			}
		}
	default:
		break;
		}
	glutPostRedisplay();
}
int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
   glutInitWindowPosition(0, 0);
   glutInitWindowSize(550, 550);
   glutCreateWindow(">>crg<<");
   init();
   glutDisplayFunc(display);
   glutKeyboardFunc(keyboard);
   glutReshapeFunc(reshape);
   glutMouseFunc(mouse);
   glutMainLoop();
   return 0;
}
