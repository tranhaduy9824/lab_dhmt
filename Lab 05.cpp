//#include <GL/glut.h>
//#include <cmath>
//
//// Function to draw a cylinder
//void drawCylinder(float radius, float height, int slices) {
//    float angleStep = 2.0f * M_PI / slices;
//    glBegin(GL_QUAD_STRIP);
//    for (int i = 0; i <= slices; ++i) {
//        float angle = i * angleStep;
//        float x = cos(angle) * radius;
//        float z = sin(angle) * radius;
//        glVertex3f(x, 0.0f, z);
//        glVertex3f(x, height, z);
//    }
//    glEnd();
//}
//
//// Function to draw a cone
//void drawCone(float radius, float height, int slices) {
//    float angleStep = 2.0f * M_PI / slices;
//
//    // Base of the cone
//    glBegin(GL_TRIANGLE_FAN);
//    glVertex3f(0.0f, 0.0f, 0.0f);
//    for (int i = 0; i <= slices; ++i) {
//        float angle = i * angleStep;
//        float x = cos(angle) * radius;
//        float z = sin(angle) * radius;
//        glVertex3f(x, 0.0f, z);
//    }
//    glEnd();
//
//    // Sides of the cone
//    glBegin(GL_TRIANGLE_FAN);
//    glVertex3f(0.0f, height, 0.0f); // Cone's apex
//    for (int i = 0; i <= slices; ++i) {
//        float angle = i * angleStep;
//        float x = cos(angle) * radius;
//        float z = sin(angle) * radius;
//        glVertex3f(x, 0.0f, z);
//    }
//    glEnd();
//}
//
//// Function to draw a sphere
//void drawSphere(float radius, int slices, int stacks) {
//    glutSolidSphere(radius, slices, stacks);
//}
//
//// Function to draw an ellipsoid
//void drawEllipsoid(float rx, float ry, float rz, int slices, int stacks) {
//    for (int i = 0; i <= stacks; ++i) {
//        float phi = M_PI * i / stacks;
//        glBegin(GL_TRIANGLE_STRIP);
//        for (int j = 0; j <= slices; ++j) {
//            float theta = 2.0f * M_PI * j / slices;
//            float x = rx * sin(phi) * cos(theta);
//            float y = ry * cos(phi);
//            float z = rz * sin(phi) * sin(theta);
//            glVertex3f(x, y, z);
//        }
//        glEnd();
//    }
//}
//
//// Function to draw a toroid
//void drawTorus(float innerRadius, float outerRadius, int slices, int stacks) {
//    glutSolidTorus(innerRadius, outerRadius, slices, stacks);
//}
//
//// Function to draw a Bezier curve
//void drawBezierCurve(float controlPoints[4][3]) {
//    glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0, 3, 4, &controlPoints[0][0]);
//    glEnable(GL_MAP1_VERTEX_3);
//
//    glBegin(GL_LINE_STRIP);
//    for (int i = 0; i <= 100; ++i) {
//        float t = (float)i / 100.0f;
//        glEvalCoord1f(t);
//    }
//    glEnd();
//}
//
//// Function to draw a Bezier surface
//void drawBezierSurface(float controlPoints[4][4][3]) {
//    glMap2f(GL_MAP2_VERTEX_3, 0.0, 1.0, 3, 4, 0.0, 1.0, 12, 4, &controlPoints[0][0][0]);
//    glEnable(GL_MAP2_VERTEX_3);
//
//    glMapGrid2f(30, 0.0, 1.0, 30, 0.0, 1.0);
//    glEvalMesh2(GL_FILL, 0, 30, 0, 30);
//}
//
//// Display function
//void display() {
//    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//    glLoadIdentity();
//    glTranslatef(0.0f, 0.0f, -15.0f);
//
//    // Cylinder
//    glPushMatrix();
//    glTranslatef(-8.0f, 0.0f, 0.0f);
//    glColor3f(0.0f, 1.0f, 0.0f);
//    drawCylinder(1.0f, 3.0f, 36);
//    glPopMatrix();
//
//    // Cone
//    glPushMatrix();
//    glTranslatef(-5.0f, 0.0f, 0.0f);
//    glColor3f(1.0f, 0.0f, 0.0f);
//    drawCone(1.0f, 3.0f, 36);
//    glPopMatrix();
//
//    // Sphere
//    glPushMatrix();
//    glTranslatef(-2.0f, 0.0f, 0.0f);
//    glColor3f(0.0f, 0.0f, 1.0f);
//    drawSphere(1.0f, 36, 18);
//    glPopMatrix();
//
//    // Ellipsoid
//    glPushMatrix();
//    glTranslatef(1.0f, 0.0f, 0.0f);
//    glColor3f(1.0f, 0.5f, 0.0f);
//    drawEllipsoid(1.0f, 1.5f, 0.5f, 36, 18);
//    glPopMatrix();
//
//    // Toroid
//    glPushMatrix();
//    glTranslatef(4.0f, 0.0f, 0.0f);
//    glColor3f(0.5f, 0.0f, 0.5f);
//    drawTorus(0.3f, 1.0f, 36, 18);
//    glPopMatrix();
//
//    // Bezier curve
//    float bezierControlPoints[4][3] = {
//        {-2.0, -1.0, 0.0}, {-1.0, 2.0, 0.0},
//        {1.0, -2.0, 0.0}, {2.0, 1.0, 0.0}
//    };
//    glPushMatrix();
//    glTranslatef(-4.0f, -3.0f, 0.0f);
//    glColor3f(1.0f, 1.0f, 0.0f);
//    drawBezierCurve(bezierControlPoints);
//    glPopMatrix();
//
//    // Bezier surface
//    float bezierSurfaceControlPoints[4][4][3] = {
//        {{-1.5, -1.5, 0.0}, {-0.5, -1.5, 0.0}, {0.5, -1.5, 0.0}, {1.5, -1.5, 0.0}},
//        {{-1.5, -0.5, 0.0}, {-0.5, -0.5, 2.0}, {0.5, -0.5, 2.0}, {1.5, -0.5, 0.0}},
//        {{-1.5, 0.5, 0.0},  {-0.5, 0.5, 2.0},  {0.5, 0.5, 2.0},  {1.5, 0.5, 0.0}},
//        {{-1.5, 1.5, 0.0},  {-0.5, 1.5, 0.0},  {0.5, 1.5, 0.0},  {1.5, 1.5, 0.0}}
//    };
//    glPushMatrix();
//    glTranslatef(4.0f, -3.0f, 0.0f);
//    glColor3f(0.5f, 0.5f, 1.0f);
//    drawBezierSurface(bezierSurfaceControlPoints);
//    glPopMatrix();
//
//    glFlush();
//    glutSwapBuffers();
//}
//
//// Initialization function
//void init() {
//    glEnable(GL_DEPTH_TEST);
//    glClearColor(0.0, 0.0, 0.0, 0.0);
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    gluPerspective(45.0, 1.0, 1.0, 100.0);
//    glMatrixMode(GL_MODELVIEW);
//}
//
//// Main function
//int main(int argc, char** argv) {
//    glutInit(&argc, argv);
//    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
//    glutInitWindowSize(800, 600);
//    glutCreateWindow("LAB 05 - Curves and Surfaces");
//    init();
//    glutDisplayFunc(display);
//    glutMainLoop();
//    return 0;
//}

