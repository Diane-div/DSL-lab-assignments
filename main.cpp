#include <GL/glut.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

GLfloat oldx = -0.7, oldy = 0.5;

void drawkoch(GLfloat dir, GLfloat len, GLint iter) {
    GLdouble dirRad = 0.0174533 * dir;
    GLfloat newX = oldx + len * cos(dirRad);
    GLfloat newY = oldy + len * sin(dirRad);
    if (iter == 0) {
        glVertex2f(oldx, oldy);
        glVertex2f(newX, newY);
        oldx = newX;
        oldy = newY;
    } else {
        iter--;

        drawkoch(dir, len, iter);
        dir += 60.0;
        drawkoch(dir, len, iter);
        dir -= 120.0;
        drawkoch(dir, len, iter);
        dir += 60.0;
        drawkoch(dir, len, iter);
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_LINES);
    glColor3f(0.0, 1.0, 0.0);

    // Resetting starting point for each segment
    oldx = -0.7; oldy = 0.5; drawkoch(0.0, 0.04, 3);
    oldx = 0.3; oldy = 0.5; drawkoch(-120.0, 0.04, 3);
    oldx = 0.0; oldy = 0.5; drawkoch(120.0, 0.04, 3);

    glEnd();
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Koch Curve");
    glClearColor(0.0, 0.0, 0.0, 1.0); // Background color
    glColor3f(1.0, 1.0, 1.0); // Default line color
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0); // Set the coordinate system
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
