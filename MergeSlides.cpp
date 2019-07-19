#include<GL/Glut.h> //includes the opengl, glu, and glut header files
#include<stdlib.h> //includes the standard library header file
#include<iostream>
#include<fstream>
using namespace std;


void init()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);// sets the current matrix to projection
	glLoadIdentity();//multiply the current matrix by identity matrix
	gluOrtho2D(0.0, 1024.0, 0.0, 1080.0);//sets the parallel(orthographic) projection of the full frame buffer 

}
void renderbitmap(float x, float y, void *font, char *string)
{
	char *c;
	glRasterPos2f(x, y);
	for (c = string;*c != '\0';c++)
	{
		glutBitmapCharacter(font, *c);
	}
}

void background(GLfloat x, GLfloat y, GLfloat z, GLfloat a, GLfloat b, GLfloat c)
{
	//Background Render

	//LeftWall
	glColor3f(x, y, z);
	glBegin(GL_POLYGON);
	glVertex2f(0, 0);
	glVertex2f(300, 300);
	glVertex2f(300, 1240);
	glVertex2f(0, 1240);
	glEnd();
	//background line 1
	glColor3f(0.0, 1.0, 1.0);
	glBegin(GL_LINES);
	glVertex2f(300, 300);
	glVertex2f(300, 1240);
	glEnd();

	//floor
	glColor3f(a, b, c);
	glBegin(GL_POLYGON);
	glVertex2f(300, 300);
	glVertex2f(1080, 300);
	glVertex2f(1080, 0);
	glVertex2f(0, 0);
	glEnd();
	//background line2
	glColor3f(0.0, 1.0, 1.0);
	glBegin(GL_LINES);
	glVertex2f(300, 300);
	glVertex2f(1080, 300);
	glEnd();
	//background line 3
	glColor3f(0.0, 1.0, 1.0);
	glBegin(GL_LINES);
	glVertex2f(300, 300);
	glVertex2f(0, 0);
	glEnd();

	//window
	glColor3f(0.0, 1.0, 1.0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(850, 750);
	glVertex2f(1000, 750);
	glVertex2f(1000, 950);
	glVertex2f(850, 950);
	glEnd();

	glColor3f(0.0, 1.0, 1.0);
	glBegin(GL_LINES);
	glVertex2f(925, 750);
	glVertex2f(925, 850);
	glEnd();
	glColor3f(0.0, 1.0, 1.0);
	glBegin(GL_LINES);
	glVertex2f(850, 850);
	glVertex2f(1000, 850);
	glEnd();
	glFlush();

}
void human1(GLfloat xr)
{
	//head
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_QUADS);
	glVertex2f(540 + xr, 680);
	glVertex2f(580 + xr, 680);
	glVertex2f(580 + xr, 620);
	glVertex2f(540 + xr, 620);
	glEnd();
	//eyes
	glColor3f(0.0, 0.0, 0.0);
	glPointSize(5.0f);
	glBegin(GL_POINTS);
	glVertex2f(550+xr, 660);
	glVertex2f(570+xr, 660);
	glEnd();

	//lips
	glBegin(GL_LINES);
	glVertex2f(550+xr, 630);
	glVertex2f(570+xr, 630);
	glEnd();
	//hair
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_LINES);
	glVertex2f(550 + xr, 680);
	glVertex2f(520 + xr, 700);
	glVertex2f(560 + xr, 680);
	glVertex2f(580 + xr, 700);
	glVertex2f(570 + xr, 680);
	glVertex2f(590 + xr, 700);
	glVertex2f(580 + xr, 680);
	glVertex2f(600 + xr, 710);
	glVertex2f(560 + xr, 680);
	glVertex2f(560 + xr, 700);
	glVertex2f(550 + xr, 680);
	glVertex2f(540 + xr, 700);
	glEnd();
	//neck
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_LINES);
	glVertex2f(560 + xr, 620);
	glVertex2f(560 + xr, 590);
	glEnd();
	//torso
	glColor3f(1.0, 0.7, 0.0);
	glBegin(GL_QUADS);
	glVertex2f(530 + xr, 590);
	glVertex2f(530 + xr, 390);
	glVertex2f(600 + xr, 390);
	glVertex2f(600 + xr, 590);
	glEnd();
	//hand left
	glPushMatrix();
	glColor3f(1.0, 0.7, 0.0);
	glBegin(GL_QUADS);
	glVertex2f(530 + xr, 590);
	glVertex2f(500 + xr, 520);
	glVertex2f(520 + xr, 500);
	glVertex2f(530 + xr, 550);
	glEnd();

	/*
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_LINES);
	glVertex2f(450 + xr, 540);
	glVertex2f(420 + xr, 530);
	glEnd();
	*/
	glutPostRedisplay();
	glutSwapBuffers();
	glPopMatrix();

	//hand right
	glColor3f(1.0, 0.7, 0.0);
	glBegin(GL_QUADS);
	glVertex2f(600 + xr, 590);
	glVertex2f(630 + xr, 520);
	glVertex2f(610 + xr, 500);
	glVertex2f(600 + xr, 550);
	glEnd();

	glColor3f(1.0, 1.0, 0.0);
	glBegin(GL_QUADS);
	glVertex2f(570 + xr, 390);
	glVertex2f(590 + xr, 300);
	glVertex2f(610 + xr, 300);
	glVertex2f(600 + xr, 390);
	glEnd();


	//left leg
	glColor3f(1.0, 1.0, 0.0);
	glBegin(GL_QUADS);
	glVertex2f(530 + xr, 390);
	glVertex2f(520 + xr, 300);
	glVertex2f(540 + xr, 300);
	glVertex2f(560 + xr, 390);
	glEnd();


}
void speaker_old()
{
	//draw speaker
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_QUADS);
	glVertex2f(660, 300);
	glVertex2f(720, 300);
	glVertex2f(720, 350);
	glVertex2f(660, 350);
	glEnd();
	//innerRect
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_QUADS);
	glVertex2f(680, 310);
	glVertex2f(700, 310);
	glVertex2f(700, 340);
	glVertex2f(680, 340);
	glEnd();
	//handle
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_QUADS);
	glVertex2f(665, 350);
	glVertex2f(665, 360);
	glVertex2f(710, 360);
	glVertex2f(710, 360);
	glEnd();
}
void human2(GLfloat xu)
{
	//legs
		//left
	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_QUADS);
	glVertex2f(800, 300);
	glVertex2f(820, 300);
	glVertex2f(840, 400);
	glVertex2f(810, 400);
	glEnd();
	//right
	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_QUADS);
	glVertex2f(840, 400);
	glVertex2f(860, 300);
	glVertex2f(880, 300);
	glVertex2f(870, 400);
	glEnd();
	//torso
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_QUADS);
	glVertex2f(810, 400);
	glVertex2f(810, 550);
	glVertex2f(870, 550);
	glVertex2f(870, 400);
	glEnd();
	//neck
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_QUADS);
	glVertex2f(830, 550);
	glVertex2f(830, 570);
	glVertex2f(850, 570);
	glVertex2f(850, 550);
	glEnd();
	//face
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_QUADS);
	glVertex2f(820, 570);
	glVertex2f(820, 630);
	glVertex2f(860, 630);
	glVertex2f(860, 570);
	glEnd();
	//hair
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(820, 630);
	glVertex2f(840, 650);
	glVertex2f(860, 630);
	glEnd();
	//left hand
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_QUADS);
	glVertex2f(810, 550);
	glVertex2f(770, 460);
	glVertex2f(800, 460+xu);
	glVertex2f(810, 540+xu);
	glEnd();
	//right hand
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_QUADS);
	glVertex2f(870, 550);
	glVertex2f(910, 460);
	glVertex2f(890, 460+xu);
	glVertex2f(870, 540+xu);
	glEnd();
	//eyes
	glColor3f(0.0, 0.0, 0.0);
	glPointSize(5.0f);
	glBegin(GL_POINTS);
	glVertex2f(830, 610);
	glVertex2f(850, 610);
	glEnd();

	//lips
	glColor3f(0.0, 0.0, 0.0);
	glPointSize(2.0f);
	glBegin(GL_LINES);
	glVertex2f(830, 580);
	glVertex2f(850, 578);
	glEnd();
}
void speaker2()
{
	glColor3f(0.0, 1.0, 0.4);
	glBegin(GL_POLYGON);
	glVertex2f(920, 300);
	glVertex2f(980, 300);
	glVertex2f(975, 360);
	glVertex2f(925, 360);
	glEnd();

	glColor3f(1.0, 0.0, 1.0);
	glBegin(GL_POLYGON);
	glVertex2f(930, 360);
	glVertex2f(930, 380);
	glVertex2f(975, 370);
	glVertex2f(930, 380);
	glEnd();

	glColor3f(1.0, 0.0, 1.0);
	glBegin(GL_TRIANGLES);
	glVertex2f(925, 360);
	glVertex2f(980, 300);
	glVertex2f(920, 300);
	glEnd();

	glColor3f(1.0, 1.0, 1.0);
	glPointSize(4.0);
	glBegin(GL_LINE_STRIP);
	glVertex2f(925, 350);
	glVertex2f(975, 350);
	glVertex2f(975, 310);
	glVertex2f(925, 310);
	glVertex2f(925, 350);
	glEnd();

	glColor3f(1.0, 1.0, 1.0);
	glPointSize(4.0);
	glBegin(GL_LINES);
	glVertex2f(950, 310);
	glVertex2f(950, 350);
	glEnd();
}
void intro()
{
	glColor3f(1.0f, 1.0f, 0.5f);
	char buf[200] = { 0 };
	sprintf_s(buf, "OBJECTIVE:");
	renderbitmap(350, 900, GLUT_BITMAP_TIMES_ROMAN_24, buf);
	glColor3f(0.0, 1.0, 0.5);
	sprintf_s(buf, "In today's world good speakers with good audio quality and superior volume is hard to come by.");
	renderbitmap(330, 850, GLUT_BITMAP_TIMES_ROMAN_24, buf);
	sprintf_s(buf, "People usually dont know what to buy and end up buying mediocre ones.");
	renderbitmap(330, 800, GLUT_BITMAP_TIMES_ROMAN_24, buf);
	sprintf_s(buf, "the new SRS-XB10 from sony is an all in package");
	renderbitmap(330, 750, GLUT_BITMAP_TIMES_ROMAN_24, buf);
	sprintf_s(buf, "We enter into a room wherea dude is listening to music on old unnamed speaker. ");
	renderbitmap(330, 700, GLUT_BITMAP_TIMES_ROMAN_24, buf);
	sprintf_s(buf, "The other dude walks in and sees the sound quality.");
	renderbitmap(330, 650, GLUT_BITMAP_TIMES_ROMAN_24, buf);
	sprintf_s(buf, "other dude says the speakers are'nt qualified enough for perfect bass. ");
	renderbitmap(330, 600, GLUT_BITMAP_TIMES_ROMAN_24, buf);
	sprintf_s(buf, "And that the quality is substantial.So why don't you try this?");
	renderbitmap(330, 550, GLUT_BITMAP_TIMES_ROMAN_24, buf);
	sprintf_s(buf, "We have Blank screen and we see the new speakers come into the screen.");
	renderbitmap(330, 500, GLUT_BITMAP_TIMES_ROMAN_24, buf);
	sprintf_s(buf, "Next we see the 2 boys dancing to the superior quality of the new speakers");
	renderbitmap(330, 450, GLUT_BITMAP_TIMES_ROMAN_24, buf);
	sprintf_s(buf, "We showcase the lates trending dance moves.");
	renderbitmap(330, 400, GLUT_BITMAP_TIMES_ROMAN_24, buf);
	sprintf_s(buf, "Floss and watch me nene with the final screen showing  SONY- FEEL THE BEAT:");
	renderbitmap(330, 350, GLUT_BITMAP_TIMES_ROMAN_24, buf);
	glColor3f(1.0f, 1.0f, 0.5f);
	sprintf_s(buf, "------>TO MOVE B/W FRAMES USE A-K KEYS<------");
	renderbitmap(450, 310, GLUT_BITMAP_TIMES_ROMAN_24, buf);
}
void speechS2()
{
	glColor3f(0.0f, 1.0f, 0.0f);
	char buf1[200] = { 0 };
	sprintf_s(buf1, "Listening to Music from J** speakers ");
	renderbitmap(300, 900, GLUT_BITMAP_TIMES_ROMAN_24, buf1);
}
void speechS3()
{
	glColor3f(0.0f, 1.0f, 0.0f);
	char buf1[200] = { 0 };
	sprintf_s(buf1, "IS THIS THE  BEST ");
	renderbitmap(890, 630, GLUT_BITMAP_TIMES_ROMAN_24, buf1);
	sprintf_s(buf1, "SOUND QUALITY");
	renderbitmap(890, 600, GLUT_BITMAP_TIMES_ROMAN_24, buf1);
	sprintf_s(buf1, "YOU CAN GET LAD?");
	renderbitmap(890, 570, GLUT_BITMAP_TIMES_ROMAN_24, buf1);
}
void speechS4()
{
	glColor3f(0.0f, 1.0f, 0.0f);
	char buf1[200] = { 0 };
	sprintf_s(buf1, "ABSOLUTELY UNLESS YOU HAVE BETTER ONES... ");
	renderbitmap(300, 900, GLUT_BITMAP_TIMES_ROMAN_24, buf1);
}
void speechS5()
{
	glColor3f(0.0f, 1.0f, 0.0f);
	char buf1[200] = { 0 };
	sprintf_s(buf1, "WAIT TILL YOU LISTEN  ");
	renderbitmap(890, 630, GLUT_BITMAP_TIMES_ROMAN_24, buf1);
	sprintf_s(buf1, "TO THIS BEAUTY!!");
	renderbitmap(890, 600, GLUT_BITMAP_TIMES_ROMAN_24, buf1);

}
void danceDescS6()
{
	glColor3f(0.0f, 1.0f, 0.0f);
	char buf1[200] = { 0 };
	sprintf_s(buf1, "LADS GROOVING,FLOSSING");
	renderbitmap(500, 750, GLUT_BITMAP_TIMES_ROMAN_24, buf1);
	sprintf_s(buf1, "ROLLING AND DANCING!!");
	renderbitmap(500, 710, GLUT_BITMAP_TIMES_ROMAN_24, buf1);
}
void finalMessage()
{
	glColor3f(0.0f, 1.0f, 0.0f);
	char buf1[200] = { 0 };
	sprintf_s(buf1, "<<<<<<FEEL THE BEAT>>>>>");
	renderbitmap(500, 650, GLUT_BITMAP_HELVETICA_18, buf1);

}

int x = 1.0, y = 1.0, z = 0.5;
void display(void)
{
	glMatrixMode(GL_PROJECTION);// sets the current matrix to projection
	glLoadIdentity();//multiply the current matrix by identity matrix
	gluOrtho2D(0.0, 1080.0, 0.0, 1080.0);
	glColor3f(0.0,0.0,0.0);
	glFlush();
	
}
void keyboard(unsigned char key, int x, int y)
{
	GLfloat xr = 0.1,xu=0.1;
	switch (key)
	{

	case 'A':glClear(GL_COLOR_BUFFER_BIT);
		background(x, y, z, 0.0, 0.5, 1.0);
		intro();
		break;
	case 'S':glClear(GL_COLOR_BUFFER_BIT);
		glPushMatrix();
		human1(0);
		background(x, y, z, 0.0, 0.5, 1.0);
		glPopMatrix();
		glutPostRedisplay();
		break;
	case 'D':glClear(GL_COLOR_BUFFER_BIT);
		glPushMatrix();
		human1(0);
		speaker_old();
		background(x, y, z, 0.0, 0.5, 1.0);

		//SPEECH BUBBLE
		glColor3f(1.0, 1.0, 1.0);
		glBegin(GL_QUADS);
		glVertex2f(290, 940);
		glVertex2f(650, 940);
		glVertex2f(650, 860);
		glVertex2f(290, 860);
		glEnd();
		glBegin(GL_TRIANGLES);
		glVertex2f(290, 860);
		glVertex2f(290, 840);
		glVertex2f(330, 860);
		glEnd();
		speechS2();
		glPopMatrix();
		glutPostRedisplay();
		break;
	case 'F':glClear(GL_COLOR_BUFFER_BIT);//SLIDE3
		glPushMatrix();
		background(x, y, z, 0.0, 0.5, 1.0);
		human1(0);
		speaker_old();
		human2(0);

		//rENDER sPEECH sLIDE3
		glColor3f(1.0, 1.0, 1.0);
		glBegin(GL_QUADS);
		glVertex2f(890, 660);
		glVertex2f(1240, 660);
		glVertex2f(1240, 560);
		glVertex2f(890, 560);
		glEnd();
		glBegin(GL_TRIANGLES);
		glVertex2f(890, 560);
		glVertex2f(890, 530);
		glVertex2f(920, 560);
		glEnd();

		speechS3();

		glPopMatrix();
		break;

	case 'G':glClear(GL_COLOR_BUFFER_BIT);//SLIDE4
		glPushMatrix();
		human1(0);
		speaker_old();
		human2(0);
		background(x, y, z, 0.0, 0.5, 1.0);

		//SPEECH BUBBLE
		glColor3f(1.0, 1.0, 1.0);
		glBegin(GL_QUADS);
		glVertex2f(290, 940);
		glVertex2f(720, 940);
		glVertex2f(720, 840);
		glVertex2f(290, 840);
		glEnd();
		glBegin(GL_TRIANGLES);
		glVertex2f(290, 840);
		glVertex2f(290, 820);
		glVertex2f(330, 840);
		glEnd();

		speechS4();
		glPopMatrix();
		glutPostRedisplay();

		break;

	case 'H':glClear(GL_COLOR_BUFFER_BIT);
		glPushMatrix();

		human1(0);
		speaker_old();
		human2(0);
		speaker2();
		background(x, y, z, 0.0, 0.5, 1.0);

		glPopMatrix();
		//CLOSE WINDOW
		glColor3f(0.0, 1.0, 1.0);
		glBegin(GL_POLYGON);
		glVertex2f(850, 750);
		glVertex2f(1000, 750);
		glVertex2f(1000, 950);
		glVertex2f(850, 950);
		glEnd();
		//SPEECH BUBBLE HUMAN2
		glColor3f(1.0, 1.0, 1.0);
		glBegin(GL_QUADS);
		glVertex2f(890, 660);
		glVertex2f(1240, 660);
		glVertex2f(1240, 560);
		glVertex2f(890, 560);
		glEnd();
		glBegin(GL_TRIANGLES);
		glVertex2f(890, 560);
		glVertex2f(890, 530);
		glVertex2f(920, 560);
		glEnd();
		glutPostRedisplay();

		speechS5();

		break;
	case 'J':glClear(GL_COLOR_BUFFER_BIT);//SLIDE6 DANCE
		glPushMatrix();

		//glClear(GL_COLOR_BUFFER_BIT);

		
		
		while (xr < 80.0||xu<30)
		{
			xr = xr + 0.1;
			xu = xu + 0.1;
			glPushMatrix();
			glTranslatef(xr,0,0);
			human1(xr);
			human2(xu);
			speaker2();
			background(0.0, 0.0, 0.7, 0.0, 0.5, 1.0);
			glClear(GL_COLOR_BUFFER_BIT);

			glPopMatrix();

		}
		//DANCE DESCRIPTION
		glColor3f(0.8, 1.0, 1.0);
		glBegin(GL_QUADS);
		glVertex2f(490, 700);
		glVertex2f(760, 700);
		glVertex2f(760, 790);
		glVertex2f(490, 790);
		glEnd();
		glBegin(GL_TRIANGLES);
		glVertex2f(490, 700);
		glVertex2f(490, 670);
		glVertex2f(520, 700);
		glEnd();

		danceDescS6();
		human1(xr);
		human2(0);
		speaker2();
		background(0.0, 0.0, 0.7, 0.0, 0.5, 1.0);

		glPopMatrix();
		glutPostRedisplay();
		break;
	case 'K':glClear(GL_COLOR_BUFFER_BIT);
		glColor3f(0, 0, 0);
		glBegin(GL_QUADS);
		glVertex2f(100, 100);
		glVertex2f(100, 1080);
		glVertex2f(1240, 1080);
		glVertex2f(1240, 100);
		glEnd();

		finalMessage();
		speaker2();
		background(0.0, 0.0, 0.7, 0.0, 0.5, 1.0);

	}
	glutPostRedisplay();

}
int main(int argc, char** argv)
{
	glutInit(&argc, argv);

	glutInitWindowSize(1000, 1000);   //sets the width and height of the window in pixels
	glutInitWindowPosition(100, 100);//sets the position of the window in pixels from top left corner 
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);//creates a single frame buffer of RGB color capacity.
	glutCreateWindow("CG PROJECT");//creates the window as specified by the user as above.

	glClearColor(0, 0, 0, 0); // sets the backgraound color to white light
	glClear(GL_COLOR_BUFFER_BIT); // clears the frame buffer and set values defined in glClearColor() function call 

	glutDisplayFunc(display);//links the display event with the display event handler(display)
	glutKeyboardFunc(keyboard);//keyboard event handler
	glutMainLoop();//loops the current event
}
