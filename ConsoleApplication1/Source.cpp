#include <windows.h>  // For MS Windows
#include <GL/glut.h>  // GLUT, includes glu.h and gl.h
#include <cmath>

/* Handler for window-repaint event. Call back when the window first appears and
whenever the window needs to be re-painted. */
const int width = 640;
const int height = 480;


void display() {
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Set background color to white and opaque
	glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer

	// Draw Line
	glLineWidth(5);
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_LINES);
	glVertex2f(-0.8, 0.8);
	glVertex2f(-0.6, 0.6);
	glEnd();

	// Draw Square with filled color
	glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
	glColor3f(1.0f, 0.0f, 0.0f); // Red
	glVertex2f(-0.3f, 0.6f);    // x, y
	glVertex2f(0, 0.6f);
	glVertex2f(0, 0.9f);
	glVertex2f(-0.3f, 0.9f);
	glEnd();
	

	// Draw Square with un-filled color
	glLineWidth(2);
	glBegin(GL_LINE_LOOP);
	glVertex2f(0.3f, 0.6f); 
	glVertex2f(0.6f, 0.6f);
	glVertex2f(0.6f, 0.9f); 
	glVertex2f(0.3f, 0.9f);
	glEnd();

	// Draw Triangle
	glBegin(GL_LINE_LOOP);
	glVertex2f(-0.5f, -0.2f); 
	glVertex2f(-0.8f, -0.5f);
	glVertex2f(-0.3f, -0.5f);
	glEnd();

	// Draw Pentagon
	glBegin(GL_LINE_LOOP);
	glVertex2f(0.0f, 0.0f);
	glVertex2f(0.15f, -0.25f);
	glVertex2f(0.1f, -0.5f);
	glVertex2f(-0.1f, -0.5f);
	glVertex2f(-0.15f, -0.25f);
	glEnd();

	// Draw Circle
	glBegin(GL_LINE_LOOP);
	int num_segments = 100;
	float r = 0.25, cx = 0.7, cy = -0.25;
	for (int ii = 0; ii < num_segments; ii++)   {
		float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);//get the current angle 
		float x = r * cosf(theta);//calculate the x component 
		float y = r * sinf(theta);//calculate the y component 
		glVertex2f(x + cx, y + cy);//output vertex 
	}
	glEnd();
	glFlush();  // Render now
}

/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char** argv) {
	glutInit(&argc, argv);                 // Initialize GLUT
	glutCreateWindow("OpenGL Setup Test"); // Create a window with the given title
	glutInitWindowSize(width, height);   // Set the window's initial width & height
	glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
	glutReshapeWindow(width, height);
	glutDisplayFunc(display); // Register display callback handler for window re-paint
	glutMainLoop();           // Enter the infinitely event-processing loop
	return 0;
}

//Example code from: https://www3.ntu.edu.sg/home/ehchua/programming/opengl/HowTo_OpenGL_C.html