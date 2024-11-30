#include <GL/glut.h>

float angleX = 0.0f;
float angleY = 0.0f;
float angleZ = 0.0f;

float colors[6][3] = {
    {1.0f, 0.0f, 0.0f}, 
    {0.0f, 1.0f, 0.0f},
    {0.0f, 0.0f, 1.0f}, 
    {1.0f, 1.0f, 0.0f},
    {1.0f, 0.0f, 1.0f}, 
    {0.0f, 1.0f, 1.0f}  
};

void drawCube() {
    glBegin(GL_QUADS);

    glColor3f(colors[0][0], colors[0][1], colors[0][2]);
    glVertex3f(-0.5f, -0.5f, 0.5f);
    glVertex3f(0.5f, -0.5f, 0.5f);
    glVertex3f(0.5f, 0.5f, 0.5f);
    glVertex3f(-0.5f, 0.5f, 0.5f);

    glColor3f(colors[1][0], colors[1][1], colors[1][2]);
    glVertex3f(-0.5f, -0.5f, -0.5f);
    glVertex3f(-0.5f, 0.5f, -0.5f);
    glVertex3f(0.5f, 0.5f, -0.5f);
    glVertex3f(0.5f, -0.5f, -0.5f);

    glColor3f(colors[2][0], colors[2][1], colors[2][2]);
    glVertex3f(-0.5f, -0.5f, -0.5f);
    glVertex3f(-0.5f, -0.5f, 0.5f);
    glVertex3f(-0.5f, 0.5f, 0.5f);
    glVertex3f(-0.5f, 0.5f, -0.5f);

    glColor3f(colors[3][0], colors[3][1], colors[3][2]);
    glVertex3f(0.5f, -0.5f, -0.5f);
    glVertex3f(0.5f, 0.5f, -0.5f);
    glVertex3f(0.5f, 0.5f, 0.5f);
    glVertex3f(0.5f, -0.5f, 0.5f);

    glColor3f(colors[4][0], colors[4][1], colors[4][2]);
    glVertex3f(-0.5f, 0.5f, -0.5f);
    glVertex3f(-0.5f, 0.5f, 0.5f);
    glVertex3f(0.5f, 0.5f, 0.5f);
    glVertex3f(0.5f, 0.5f, -0.5f);

    glColor3f(colors[5][0], colors[5][1], colors[5][2]);
    glVertex3f(-0.5f, -0.5f, -0.5f);
    glVertex3f(0.5f, -0.5f, -0.5f);
    glVertex3f(0.5f, -0.5f, 0.5f);
    glVertex3f(-0.5f, -0.5f, 0.5f);

    glEnd();
}

void renderScene() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    gluLookAt(5.0f, 5.0f, 5.0f, 
              0.0f, 0.0f, 0.0f, 
              0.0f, 1.0f, 0.0f);

    glRotatef(angleX, 1.0f, 0.0f, 0.0f);
    glRotatef(angleY, 0.0f, 1.0f, 0.0f);
    glRotatef(angleZ, 0.0f, 0.0f, 1.0f);

    drawCube();
    glutSwapBuffers();
}

void processMouseMotion(int x, int y) {
    angleX = (float)y;
    angleY = (float)x;
    glutPostRedisplay();
}

void init() {
    glEnable(GL_DEPTH_TEST);
}

void reshape(int w, int h) {
    if (h == 0) h = 1;
    float ratio = 1.0f * w / h;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45, ratio, 1, 100);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(800, 600);
    glutCreateWindow("3D Cube with Fixed Colors");

    init();
    glutDisplayFunc(renderScene);
    glutReshapeFunc(reshape);
    glutMotionFunc(processMouseMotion);

    glutMainLoop();
    return 0;
}

