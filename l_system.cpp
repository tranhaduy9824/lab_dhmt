//#include <iostream>
//#include <cmath>
//#include <GL/glut.h>
//
//typedef struct {
//    float x, y, z;
//} vector3;
//
//std::string axiom = "F";
//std::string currentString = axiom;
//float angle = 25.0f; 
//
//void applyRule(char &c) {
//    if (c == 'F') {
//        c = 'F[+F]F[-F]F[F+]';
//    }
//}
//
//void generateLSystem(int iterations) {
//    for (int i = 0; i < iterations; ++i) {
//        std::string nextString = "";
//        for (int j = 0; j < currentString.length(); ++j) {
//            char c = currentString[j];
//            applyRule(c);
//            nextString += c;
//        }
//        currentString = nextString;
//    }
//}
//
//void drawTree(float length, float angle, int iterations) {
//    glPushMatrix();
//    
//    glLineWidth(2);
//    glColor3f(0.55f, 0.27f, 0.07f);
//    
//    glBegin(GL_LINES);
//    glVertex3f(0, 0, 0);
//    glVertex3f(0, length, 0);
//    glEnd();
//    
//    if (iterations > 0) {
//        glTranslatef(0, length, 0);
//        
//        glPushMatrix();
//        glRotatef(angle, 0, 0, 1);
//        drawTree(length * 0.7f, angle, iterations - 1);
//        glPopMatrix();
//        
//        glPushMatrix();
//        glRotatef(-angle, 0, 0, 1);
//        drawTree(length * 0.7f, angle, iterations - 1);
//        glPopMatrix();
//    }
//
//    glPopMatrix();
//}
//
//void display() {
//    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//    glLoadIdentity();
//    
//    glTranslatef(0, -1.0f, -5.0f);
//    
//    drawTree(1.0f, angle, 9);
//    
//    glutSwapBuffers();
//}
//
//void init() {
//    glClearColor(0.7f, 0.7f, 1.0f, 1.0f);
//    glEnable(GL_DEPTH_TEST);
//    
//    generateLSystem(9);
//}
//
//void reshape(int w, int h) {
//    glViewport(0, 0, w, h);
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    gluPerspective(45.0f, (GLfloat)w / (GLfloat)h, 1.0f, 100.0f);
//    glMatrixMode(GL_MODELVIEW);
//}
//
//int main(int argc, char** argv) {
//    glutInit(&argc, argv);
//    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
//    glutInitWindowSize(800, 600);
//    glutCreateWindow("L-System Tree");
//
//    init();
//    glutDisplayFunc(display);
//    glutReshapeFunc(reshape);
//    
//    glutMainLoop();
//    return 0;
//}

