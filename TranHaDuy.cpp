#include <iostream>
#include <cmath>
#include <GL/glut.h>

typedef struct {
    float x, y;
} vector2;

vector2 randomGradient(int ix, int iy) {
    const unsigned w = 8 * sizeof(unsigned);
    const unsigned s = w / 2; 
    unsigned a = ix, b = iy;
    a *= 3284157493;
    b ^= a << s | a >> w - s;
    b *= 1911520782;
    a ^= b << s | b >> w - s;
    a *= 2048419356;
    float random = a * (3.14159265 / ~(~0u >> 1));
    
    vector2 v;
    v.x = sin(random);
    v.y = cos(random);
    return v;
}

float dotGridGradient(int ix, int iy, float x, float y) {
    vector2 gradient = randomGradient(ix, iy);
    float dx = x - (float)ix;
    float dy = y - (float)iy;
    return (dx * gradient.x + dy * gradient.y);
}

float interpolate(float a0, float a1, float w) {
    return (a1 - a0) * (3.0 - w * 2.0) * w * w + a0;
}

float perlin(float x, float y) {
    int x0 = (int)x; 
    int y0 = (int)y;
    int x1 = x0 + 1;
    int y1 = y0 + 1;

    float sx = x - (float)x0;
    float sy = y - (float)y0;
    
    float n0 = dotGridGradient(x0, y0, x, y);
    float n1 = dotGridGradient(x1, y0, x, y);
    float ix0 = interpolate(n0, n1, sx);
    
    n0 = dotGridGradient(x0, y1, x, y);
    n1 = dotGridGradient(x1, y1, x, y);
    float ix1 = interpolate(n0, n1, sx);
    
    return interpolate(ix0, ix1, sy);
}

const int windowWidth = 1920;
const int windowHeight = 1080;
unsigned char* pixels;

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    
    const int GRID_SIZE = 400;
    
    for (int x = 0; x < windowWidth; x++) {
        for (int y = 0; y < windowHeight; y++) {
            float val = 0;
            float freq = 1;
            float amp = 1;

            for (int i = 0; i < 12; i++) {
                val += perlin(x * freq / GRID_SIZE, y * freq / GRID_SIZE) * amp;
                freq *= 2;
                amp /= 2;
            }

            val *= 1.2;

            if (val > 1.0f) val = 1.0f;
            else if (val < -1.0f) val = -1.0f;

            int color = (int)(((val + 1.0f) * 0.5f) * 255);
            int index = (y * windowWidth + x) * 3;
            
            pixels[index] = color;     
            pixels[index + 1] = color;  
            pixels[index + 2] = color;  
        }
    }

    glDrawPixels(windowWidth, windowHeight, GL_RGB, GL_UNSIGNED_BYTE, pixels);
    glutSwapBuffers();
}

void init() {
    glClearColor(0, 0, 0, 1);
    pixels = new unsigned char[windowWidth * windowHeight * 3];
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(windowWidth, windowHeight);	
    glutCreateWindow("Perlin Noise");

    init();
    glutDisplayFunc(display);
    glutIdleFunc(display);

    glutMainLoop();

    delete[] pixels;
    return 0;
}
