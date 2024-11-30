//#include <GL/glut.h>
//#include <cmath>
//
//float theta = 0.0, phi = 0.0; // G�c quan s�t
//float zoom = 1.0;            // Ph�ng to/thu nh?
//bool wireframe = true;       // Ch? �? khung k?t n?i
//
//void drawCube() {
//    if (wireframe) {
//        glutWireCube(1.0); // Khung k?t n?i
//    } else {
//        glutSolidCube(1.0); // M?t �a gi�c
//    }
//}
//
//void setProjection() {
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    gluPerspective(60.0, 1.0, 1.0, 10.0);
//    glMatrixMode(GL_MODELVIEW);
//}
//
//void display() {
//    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//    glLoadIdentity();
//
//    // �?t v? tr� quan s�t
//    float eyeX = 3.0 * cos(phi) * cos(theta);
//    float eyeY = 3.0 * sin(phi);
//    float eyeZ = 3.0 * cos(phi) * sin(theta);
//    gluLookAt(eyeX, eyeY, eyeZ, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
//
//    // Ph�ng to/thu nh?
//    glScalef(zoom, zoom, zoom);
//
//    glColor3f(1.0, 0.0, 0.0);
//    drawCube();
//
//    glFlush();
//    glutSwapBuffers();
//}
//
//void keyboard(unsigned char key, int x, int y) {
//    switch (key) {
//        case 'w': phi += 0.1; break;    // Xoay l�n
//        case 's': phi -= 0.1; break;    // Xoay xu?ng
//        case 'a': theta -= 0.1; break;  // Xoay tr�i
//        case 'd': theta += 0.1; break;  // Xoay ph?i
//        case '+': zoom += 0.1; break;   // Ph�ng to
//        case '-': zoom -= 0.1; break;   // Thu nh?
//        case 'm': wireframe = !wireframe; break; // Chuy?n �?i khung k?t n?i/m?t �a gi�c
//        case 27: exit(0);               // Tho�t ch��ng tr?nh
//    }
//    glutPostRedisplay();
//}
//
//void init() {
//    glEnable(GL_DEPTH_TEST);
//    glClearColor(0.0, 0.0, 0.0, 0.0);
//    setProjection();
//}
//
//int main(int argc, char** argv) {
//    glutInit(&argc, argv);
//    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
//    glutInitWindowSize(500, 500);
//    glutCreateWindow("3D Object Viewer");
//    init();
//    glutDisplayFunc(display);
//    glutKeyboardFunc(keyboard);
//    glutMainLoop();
//    return 0;
//}

