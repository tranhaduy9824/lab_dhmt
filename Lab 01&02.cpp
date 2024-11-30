//#include <GL/glut.h>
//#include <cmath>
//
//void display() {
//    glClear(GL_COLOR_BUFFER_BIT);
//    glColor3f(1.0, 1.0, 1.0);
//    glPointSize(2.0);
//    glBegin(GL_POINTS);
//
//    for (float x = -1.0; x <= 1.0; x += 0.001) {
//        float y = x * x;
//        glVertex2f(x, y);
//    }
//
//    for (float x = -1.0; x <= -0.1; x += 0.001) {
//        float y = 1 / x;
//        glVertex2f(x, y);
//    }
//    for (float x = 0.1; x <= 1.0; x += 0.001) {
//        float y = 1 / x;
//        glVertex2f(x, y);
//    }
//
//    for (float x = -3.14; x <= 3.14; x += 0.001) {
//        float y = sin(x);
//        glVertex2f(x / 3.14, y);
//    }
//
//    for (float x = -3.14; x <= 3.14; x += 0.001) {
//        float y = cos(x);
//        glVertex2f(x / 3.14, y);
//    }
//
//    glEnd();
//    glFlush();
//}
//
//void init() {
//    glClearColor(0.0, 0.0, 0.0, 0.0);
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    gluOrtho2D(-1.5, 1.5, -1.5, 1.5);
//}
//
//int main(int argc, char** argv) {
//    glutInit(&argc, argv);
//    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//    glutInitWindowSize(500, 500);
//    glutCreateWindow("Ve Duong Cong");
//    init();
//    glutDisplayFunc(display);
//    glutMainLoop();
//    return 0;
//}

