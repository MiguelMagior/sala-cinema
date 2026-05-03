#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include "image.h"
#define TEXTURA_DO_PLANO "wood.rgb"

static int rot = 0;
static float camY = -10.0;
static float camZ = 0.0;

GLfloat mat_1_difusa[] = {0.2, 0.2, 0.2, 1.0};
GLfloat mat_1_especular[] = {1.0, 1.0, 1.0, 1.0};
GLfloat mat_1_brilho[] = {50.0};

GLfloat mat_2_difusa[] = {0.3, 0.3, 0.3, 1.0};
GLfloat mat_2_especular[] = {1.0, 1.0, 1.0, 1.0};
GLfloat mat_2_brilho[] = {50.0};

GLfloat mat_3_difusa[] = {0.5, 0.5, 0.5, 1.0};
GLfloat mat_3_especular[] = {1.0, 1.0, 1.0, 1.0};
GLfloat mat_3_brilho[] = {50.0};

GLfloat mat_4_difusa[] = {1.0, 1.0, 0.0, 1.0};
GLfloat mat_4_especular[] = {1.0, 1.0, 1.0, 1.0};
GLfloat mat_4_brilho[] = {50.0};

GLfloat mat_5_difusa[] = {0.1, 0.1, 0.1, 1.0};
GLfloat mat_5_especular[] = {1.0, 1.0, 1.0, 1.0};
GLfloat mat_5_brilho[] = {50.0};

GLfloat mat_6_difusa[] = {0.3, 0.2, 0.1, 1.0};
GLfloat mat_6_especular[] = {1.0, 1.0, 1.0, 1.0};
GLfloat mat_6_brilho[] = {50.0};

GLfloat mat_7_difusa[] = {1.0, 1.0, 1.0, 1.0};
GLfloat mat_7_especular[] = {1.0, 1.0, 1.0, 1.0};
GLfloat mat_7_brilho[] = {50.0};

GLfloat mat_8_difusa[] = {0.5, 0.1, 0.1, 1.0};
GLfloat mat_8_especular[] = {1.0, 1.0, 1.0, 1.0};
GLfloat mat_8_brilho[] = {50.0};

GLfloat posicao_luz[] = {0.0, 3.0, 0.0, 1.0};
GLfloat cor_luz[] = {1.0, 1.0, 1.0, 1.0};
GLfloat cor_luz_amb[] = {0.2, 0.2, 0.2, 1.0};

GLuint textura_plano;
GLfloat planotext[4][2] = {
    {0, 0},
    {+1, 0},
    {+1, +1},
    {0, +1}};

void drawFloor(void)
{
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_2_difusa);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_2_especular);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mat_2_brilho);
    glPushMatrix();
    glTranslatef(0.0, 0.0, -15.0);
    glScalef(50.0, 0.1, 75.0);
    glutSolidCube(1.0);
    glPopMatrix();

    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_1_difusa);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_1_especular);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mat_1_brilho);
    glPushMatrix();
    glTranslatef(0.0, 1.5, -10.0);
    glScalef(50.0, 3.0, 10.0);
    glutSolidCube(1.0);
    glPopMatrix();

    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_2_difusa);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_2_especular);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mat_2_brilho);
    glPushMatrix();
    glTranslatef(0.0, 3.0, -25.0);
    glScalef(50.0, 6.0, 20.0);
    glutSolidCube(1.0);
    glPopMatrix();
}

void drawCeiling(void)
{
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_5_difusa);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_5_especular);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mat_5_brilho);
    glPushMatrix();
    glTranslatef(0.0, 25.0, -15.0);
    glScalef(50.0, 0.1, 75.0);
    glutSolidCube(1.0);
    glPopMatrix();
}

void drawScreenWall(void)
{
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_5_difusa);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_5_especular);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mat_5_brilho);
    glPushMatrix();
    glTranslatef(0.0, 7.5, 20.0);
    glScalef(50.0, 35.0, 0.1);
    glutSolidCube(1.0);
    glPopMatrix();
}

void drawTextureWalls(void)
{
    glEnable(GL_TEXTURE_2D);
    glBegin(GL_QUADS);
    glNormal3f(1.0, 0.0, 0.0);
    glTexCoord2f(0.0, 0.0);
    glVertex3f(-24.95, -10.0, -52.5);
    glNormal3f(1.0, 0.0, 0.0);
    glTexCoord2f(5.0, 0.0);
    glVertex3f(-24.95, -10.0, 22.5);
    glNormal3f(1.0, 0.0, 0.0);
    glTexCoord2f(5.0, 5.0);
    glVertex3f(-24.95, 25.0, 22.5);
    glNormal3f(1.0, 0.0, 0.0);
    glTexCoord2f(0.0, 5.0);
    glVertex3f(-24.95, 25.0, -52.5);
    glEnd();
    glDisable(GL_TEXTURE_2D);

    glEnable(GL_TEXTURE_2D);
    glBegin(GL_QUADS);
    glNormal3f(-1.0, 0.0, 0.0);
    glTexCoord2f(0.0, 0.0);
    glVertex3f(24.95, -10.0, -52.5);
    glNormal3f(-1.0, 0.0, 0.0);
    glTexCoord2f(5.0, 0.0);
    glVertex3f(24.95, -10.0, 22.5);
    glNormal3f(-1.0, 0.0, 0.0);
    glTexCoord2f(5.0, 5.0);
    glVertex3f(24.95, 25.0, 22.5);
    glNormal3f(-1.0, 0.0, 0.0);
    glTexCoord2f(0.0, 5.0);
    glVertex3f(24.95, 25.0, -52.5);
    glEnd();
    glDisable(GL_TEXTURE_2D);

    glEnable(GL_TEXTURE_2D);
    glBegin(GL_QUADS);
    glNormal3f(0.0, 0.0, 1.0);
    glTexCoord2f(0.0, 0.0);
    glVertex3f(-25.0, -10.0, -39.95);
    glNormal3f(0.0, 0.0, 1.0);
    glTexCoord2f(5.0, 0.0);
    glVertex3f(25.0, -10.0, -39.95);
    glNormal3f(0.0, 0.0, 1.0);
    glTexCoord2f(5.0, 5.0);
    glVertex3f(25.0, 25.0, -39.95);
    glNormal3f(0.0, 0.0, 1.0);
    glTexCoord2f(0.0, 5.0);
    glVertex3f(-25.0, 25.0, -39.95);
    glEnd();
    glDisable(GL_TEXTURE_2D);
}

void drawDoor(void)
{
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_6_difusa);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_6_especular);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mat_6_brilho);
    glPushMatrix();
    glTranslatef(-20.0, 2.0, -39.9);
    glScalef(-10.0, 15.0, 0.2);
    glutSolidCube(2.0);
    glPopMatrix();
}

void drawScreen(void)
{
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_7_difusa);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_7_especular);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mat_7_brilho);
    glPushMatrix();
    glTranslatef(0.0, 12.5, 19.9);
    glScalef(35.0, 20.0, 0.1);
    glutSolidCube(1.0);
    glPopMatrix();
}

void drawChairs(void)
{
    for (int i = 0; i < 5; i++)
    {
        float x = i * 5.5;
        for (int j = 0; j < 3; j++)
        {
            float y = j * 3;
            float z = j * 10;
            glPushMatrix();

            glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_8_difusa);
            glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_8_especular);
            glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mat_8_brilho);
            glTranslatef(-11.0 + x, 2.0 + y, 0.0 - z);
            glPushMatrix();
            glScalef(5.0, 1.0, 5.0);
            glutSolidCube(1.0);
            glPopMatrix();

            glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_3_difusa);
            glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_3_especular);
            glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mat_3_brilho);
            glPushMatrix();
            glTranslatef(-2.75, 0.0, 0.0);
            glScalef(0.5, 4.0, 5.0);
            glutSolidCube(1.0);
            glPopMatrix();

            glPushMatrix();
            glTranslatef(2.75, 0.0, 0.0);
            glScalef(0.5, 4.0, 5.0);
            glutSolidCube(1.0);
            glPopMatrix();

            glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_8_difusa);
            glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_8_especular);
            glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mat_8_brilho);
            glPushMatrix();
            glRotatef(-5.0, 1.0, 0.0, 0.0);
            glTranslatef(0.0, 2.0, -3.0);
            glScalef(5.0, 5.0, 1.0);
            glutSolidCube(1.0);
            glPopMatrix();

            glPopMatrix();
        }
    }
}

void positionYellowLights(float x, float y, float z, int i)
{
    GLfloat light_pos[] = {x, y, z, 1.0};
    GLfloat yellow_diffuse[] = {1.0, 0.85, 0.4, 1.0};
    GLfloat yellow_specular[] = {0.8, 0.7, 0.3, 1.0};
    GLfloat yellow_ambient[] = {0.2, 0.15, 0.05, 1.0};
    
    glLightfv(GL_LIGHT1 + i, GL_POSITION, light_pos);
    glLightfv(GL_LIGHT1 + i, GL_DIFFUSE, yellow_diffuse);
    glLightfv(GL_LIGHT1 + i, GL_SPECULAR, yellow_specular);
    glLightfv(GL_LIGHT1 + i, GL_AMBIENT, yellow_ambient);
    glLightf(GL_LIGHT1 + i, GL_CONSTANT_ATTENUATION, 1.0);
    glLightf(GL_LIGHT1 + i, GL_LINEAR_ATTENUATION, 0.1);
    glLightf(GL_LIGHT1 + i, GL_QUADRATIC_ATTENUATION, 0.02);
    glEnable(GL_LIGHT1 + i);
}

void drawWallElements(void)
{
    int lightIndex = 0;
    for (int i = 0; i < 4; i++)
    {
        float y = (i > 2) ? 19.0 : 15.0 + (float)i * 2;
        float z = -11 * (float)i;

        glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_3_difusa);
        glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_3_especular);
        glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mat_3_brilho);
        glPushMatrix();
        glTranslatef(-25.0, 12.5, z);
        glScalef(1.0, 25.0, 3.0);
        glutSolidCube(1.0);
        glPopMatrix();

        glPushMatrix();
        glTranslatef(25.0, 12.5, z);
        glScalef(1.0, 25.0, 3.0);
        glutSolidCube(1.0);
        glPopMatrix();

        glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_4_difusa);
        glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_4_especular);
        glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mat_4_brilho);
        glPushMatrix();
        glTranslatef(-24.0, y, z);
        glScalef(1, 3.0, 1.0);
        glutSolidSphere(1, 8, 8);
        glPopMatrix();
        positionYellowLights(-24.0, y, z, lightIndex++);

        glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_1_difusa);
        glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_1_especular);
        glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mat_1_brilho);
        glPushMatrix();
        glTranslatef(-24.0, y - 1.75, z);
        glRotatef(90, 1.0, 0.0, 0.0);
        glutSolidCone(1.0, 2, 8, 8);
        glPopMatrix();

        glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_4_difusa);
        glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_4_especular);
        glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mat_4_brilho);
        glPushMatrix();
        glTranslatef(24.0, y, z);
        glScalef(1.0, 3.0, 1.0);
        glutSolidSphere(1, 8, 8);
        glPopMatrix();
        positionYellowLights(24.0, y, z, lightIndex++);

        glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_1_difusa);
        glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_1_especular);
        glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mat_1_brilho);
        glPushMatrix();
        glTranslatef(24.0, y - 1.75, z);
        glRotatef(90, 1.0, 0.0, 0.0);
        glutSolidCone(1.0, 2, 8, 8);
        glPopMatrix();

        glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_1_difusa);
        glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_1_especular);
        glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mat_1_brilho);
        glPushMatrix();
        glTranslatef(25.0, y - 2.0, z + 5.5);
        glRotatef(30, 0.0, 0.0, 1.0);
        glScalef(1.0, 3.0, 2.0);
        glutSolidCube(1.0);
        glPopMatrix();

        glPushMatrix();
        glTranslatef(-25.0, y - 2.0, z + 5.5);
        glRotatef(-30, 0.0, 0.0, 1.0);
        glScalef(1.0, 3.0, 2.0);
        glutSolidCube(1.0);
        glPopMatrix();
    }
}

void drawProjector(void)
{
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_3_difusa);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_3_especular);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mat_3_brilho);
    glPushMatrix();
    glTranslatef(0.0, 22.5, -35);
    glScalef(5.0, 2.0, 3.0);
    glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0, 24.25, -35);
    glScalef(1.0, 1.5, 1.0);
    glutSolidCube(1.0);
    glPopMatrix();

    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_1_difusa);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_1_especular);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mat_1_brilho);
    glPushMatrix();
    glTranslatef(0.0, 22.5, -32.5);
    glRotatef(-180, 1.0, 0.0, 0.0);
    glutSolidCone(1.0, 2, 8, 8);
    glPopMatrix();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    glTranslatef(0.0, camY, camZ);
    glPushMatrix();
    glRotatef((GLfloat)rot, 0.0, 1.0, 0.0);

    glPushMatrix();
    GLfloat pos_projector[] = {0.0, 22.5, -32.5, 1.0};
    glLightfv(GL_LIGHT0, GL_POSITION, pos_projector);

    GLfloat spot_dir[] = {0.0, 0, 1.0};
    glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, spot_dir);
    glPopMatrix();

    drawFloor();
    drawCeiling();
    drawScreenWall();
    drawTextureWalls();
    drawDoor();
    drawScreen();
    drawChairs();
    drawWallElements();
    drawProjector();

    glPopMatrix();
    glutSwapBuffers();
}

void configProjectorLight()
{
    GLfloat pos[] = {0.0, 22.5, -32.0, 1.0};
    GLfloat color_light[] = {2.0, 2.0, 2.0, 1.0};
    GLfloat color_amb_light[] = {0.05, 0.05, 0.05, 1.0};
    GLfloat direction_spot[] = {0.0, -0.7, 1.0};

    glLightfv(GL_LIGHT0, GL_POSITION, pos);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, color_light);
    glLightfv(GL_LIGHT0, GL_SPECULAR, color_light);
    glLightfv(GL_LIGHT0, GL_AMBIENT, color_amb_light);

    glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, direction_spot);
    glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, 40.0);
    glLightf(GL_LIGHT0, GL_SPOT_EXPONENT, 5.0);

    glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION, 1.0);
    glLightf(GL_LIGHT0, GL_LINEAR_ATTENUATION, 0.0);
    glLightf(GL_LIGHT0, GL_QUADRATIC_ATTENUATION, 0.0);
}

void reshape(int w, int h)
{
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(65.0, (GLfloat)w / (GLfloat)h, 1.0, 75.0);
    glMatrixMode(GL_MODELVIEW);
}

void loadTextures(void)
{
    IMAGE *img;
    GLenum gluerr;

    glGenTextures(1, &textura_plano);
    glBindTexture(GL_TEXTURE_2D, textura_plano);

    if (!(img = ImageLoad(TEXTURA_DO_PLANO)))
    {
        fprintf(stderr, "Error reading a texture.\n");
        exit(-1);
    }

    gluerr = gluBuild2DMipmaps(GL_TEXTURE_2D, 3,
                               img->sizeX, img->sizeY,
                               GL_RGB, GL_UNSIGNED_BYTE,
                               (GLvoid *)(img->data));
    if (gluerr)
    {
        fprintf(stderr, "GLULib%s\n", gluErrorString(gluerr));
        exit(-1);
    }

    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
}

void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'd':
        rot = (rot + 5) % 360;
        break;
    case 'a':
        rot = (rot - 5) % 360;
        break;
    case 'w':
        camY -= 0.2;
        if (camY < -15.0)
            camY = -15.0;
        break;
    case 's':
        camY += 0.2;
        if (camY > 5.0)
            camY = 5.0;
        break;
    case 'q':
        camZ += 1.0;
        if (camZ > 10.0)
            camZ = 10.0;
        break;
    case 'e':
        camZ -= 1.0;
        if (camZ < -20.0)
            camZ = -20.0;
        break;
    case 27:
        exit(0);
        break;
    }
    glutPostRedisplay();
}

void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glEnable(GL_DEPTH_TEST);

    GLfloat global_ambient[] = {0.05, 0.05, 0.05, 1.0};
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global_ambient);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_AUTO_NORMAL);
    glEnable(GL_NORMALIZE);

    configProjectorLight();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow(argv[0]);
    init();
    loadTextures();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}