#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include "image.h"
#define TEXTURA_DO_PLANO "flamengo.rgb"

static int rot = 0;
static float camY = -10.0;
static float camZ = 0.0;

GLuint textura_plano;
GLfloat planotext[4][2] = {
    {0, 0},
    {+1, 0},
    {+1, +1},
    {0, +1}};

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    glTranslatef(0.0, camY, camZ);
    /* rotacao da cena*/
    glPushMatrix();
    glRotatef((GLfloat)rot, 0.0, 1.0, 0.0);

    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
    glBindTexture(GL_TEXTURE_2D, textura_plano);

    /* Chao */
    glColor3f(0.3, 0.3, 0.3);
    glPushMatrix();
    glTranslatef(0.0, 0.0, -15.0);
    glScalef(50.0, 0.1, 75.0);
    glutSolidCube(1.0);
    glPopMatrix();

    glColor3f(0.2, 0.2, 0.2);
    glPushMatrix();
    glTranslatef(0.0, 1.5, -10.0);
    glScalef(50.0, 3.0, 10.0);
    glutSolidCube(1.0);
    glPopMatrix();

    glColor3f(0.3, 0.3, 0.3);
    glPushMatrix();
    glTranslatef(0.0, 3.0, -25.0);
    glScalef(50.0, 6.0, 20.0);
    glutSolidCube(1.0);
    glPopMatrix();

    /* Teto */
    glColor3f(0.1, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(0.0, 25.0, -15.0);
    glScalef(50.0, 0.1, 75.0);
    glutSolidCube(1.0);
    glPopMatrix();

    /* Parede esquerda */
    glColor3f(1.0, 0.2, 0.2);
    glPushMatrix();
    glTranslatef(-25.0, 7.5, -15.0);
    glScalef(0.1, 35.0, 75.0);
    glutSolidCube(1.0);
    glPopMatrix();

    /* Parede direita */
    glPushMatrix();
    glTranslatef(25.0, 7.5, -15.0);
    glScalef(0.1, 35.0, 75.0);
    glutSolidCube(1.0);
    glPopMatrix();

    /* Parede fundo */
    glPushMatrix();
    glTranslatef(0.0, 7.5, -40.0);
    glScalef(50.0, 35.0, 0.1);
    glutSolidCube(1.0);
    glPopMatrix();

    /* Parede Tela */
    glColor3f(0.1, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(0.0, 7.5, 20.0);
    glScalef(50.0, 35.0, 0.1);
    glutSolidCube(1.0);
    glPopMatrix();

    /* Porta */
    glColor3f(0.3, 0.2, 0.1);
    glPushMatrix();
    glTranslatef(-20.0, 2.0, -39.9);
    glScalef(-10.0, 15.0, 0.2);
    glutSolidCube(2.0);
    glPopMatrix();

    /* Tela 
    glColor3f(1.0, 1.0, 1.0);
    glPushMatrix();
    glTranslatef(0.0, 12.5, 19.9);
    glScalef(35.0, 20.0, 0.1);
    glutSolidCube(1.0);
    glPopMatrix();
    */

    /* Tela com Textura */
glEnable(GL_TEXTURE_2D);
glBegin(GL_QUADS);
// The screen is scaled 35.0 (width) x 20.0 (height) x 0.1 (depth)
// Centered at (0, 12.5, 19.9)
// So vertices should be at half those dimensions
glTexCoord2f(0.0f, 0.0f); glVertex3f(-17.5f, 2.5f, 19.9f);   // Bottom-left
glTexCoord2f(1.0f, 0.0f); glVertex3f(17.5f, 2.5f, 19.9f);    // Bottom-right  
glTexCoord2f(1.0f, 1.0f); glVertex3f(17.5f, 22.5f, 19.9f);   // Top-right
glTexCoord2f(0.0f, 1.0f); glVertex3f(-17.5f, 22.5f, 19.9f);  // Top-left
glEnd();
glDisable(GL_TEXTURE_2D);

    glEnable(GL_TEXTURE_2D);
    glBegin(GL_QUADS);
    // Front face (facing the camera)
    // Bottom-left
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-5.0f, 20.0f, 20.0f);
    // Bottom-right
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(5.0f, 20.0f, 20.0f);
    // Top-right
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(5.0f, 25.0f, 20.0f);
    // Top-left
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-5.0f, 25.0f, 20.0f);
    glEnd();
    glDisable(GL_TEXTURE_2D);

    for (int i = 0; i < 5; i++)
    {
        float x, y, z;
        x = i * 5.5;
        for (int j = 0; j < 3; j++)
        {
            y = j * 3;

            z = j * 10;
            glPushMatrix();

            /* Almofada */
            glColor3f(0.1, 0.1, 0.1);
            glTranslatef(-11.0 + x, 2.0 + y, 0.0 - z);
            glPushMatrix();
            glScalef(5.0, 1.0, 5.0);
            glutSolidCube(1.0);
            glPopMatrix();

            /* Braço esquerdo */
            glColor3f(0.5, 0.5, 0.5);
            glPushMatrix();
            glTranslatef(-2.75, 0.0, 0.0);
            glScalef(0.5, 4.0, 5.0);
            glutSolidCube(1.0);
            glPopMatrix();

            /* Braço direito */
            glColor3f(0.5, 0.5, 0.5);
            glPushMatrix();
            glTranslatef(2.75, 0.0, 0.0);
            glScalef(0.5, 4.0, 5.0);
            glutSolidCube(1.0);
            glPopMatrix();

            /* Encosto */
            glColor3f(0.1, 0.1, 0.1);
            glPushMatrix();
            glRotatef(-5.0, 1.0, 0.0, 0.0);
            glTranslatef(0.0, 2.0, -3.0);
            glScalef(5.0, 5.0, 1.0);
            glutSolidCube(1.0);
            glPopMatrix();

            glPopMatrix();
        }
    }
    /* Elementos Parede*/
    for (int i = 0; i < 4; i++)
    {
        float y = (i > 2) ? 19.0 : 15.0 + (float)i * 2;
        float z = -11 * (float)i;

        /* Pilares */
        glColor3f(0.5, 0.5, 0.5);
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

        /* Luzes */
        glColor3f(1.0, 1.0, 0.0);
        glPushMatrix();
        glTranslatef(-24.0, y, z);
        glScalef(1, 3.0, 1.0);
        glutSolidSphere(1, 8, 8);
        glPopMatrix();

        glColor3f(0.2, 0.2, 0.2);
        glPushMatrix();
        glTranslatef(-24.0, y - 1.75, z);
        glRotatef(90, 1.0, 0.0, 0.0);
        glutSolidCone(1.0, 2, 8, 8);
        glPopMatrix();

        glColor3f(1.0, 1.0, 0.0);
        glPushMatrix();
        glTranslatef(24.0, y, z);
        glScalef(1.0, 3.0, 1.0);
        glutSolidSphere(1, 8, 8);
        glPopMatrix();

        glColor3f(0.2, 0.2, 0.2);
        glPushMatrix();
        glTranslatef(24.0, y - 1.75, z);
        glRotatef(90, 1.0, 0.0, 0.0);
        glutSolidCone(1.0, 2, 8, 8);
        glPopMatrix();

        /* Caixas de Som*/
        glColor3f(0.2, 0.2, 0.2);
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

    /* Projetor */
    glColor3f(0.5, 0.5, 0.5);
    glPushMatrix();
    glTranslatef(0.0, 22.5, -35);
    glScalef(5.0, 2.0, 3.0);
    glutSolidCube(1.0);
    glPopMatrix();

    glColor3f(0.5, 0.5, 0.5);
    glPushMatrix();
    glTranslatef(0.0, 24.25, -35);
    glScalef(1.0, 1.5, 1.0);
    glutSolidCube(1.0);
    glPopMatrix();

    glColor3f(0.2, 0.2, 0.2);
    glPushMatrix();
    glTranslatef(0.0, 22.5, -32.5);
    glRotatef(-180, 1.0, 0.0, 0.0);
    glutSolidCone(1.0, 2, 8, 8);
    glPopMatrix();

    glPopMatrix(); // da rotacao da cena

    glutSwapBuffers();
}

void reshape(int w, int h)
{
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(65.0, (GLfloat)w / (GLfloat)h, 1.0, 75.0);
    glMatrixMode(GL_MODELVIEW);
}

void carregar_texturas(void)
{
    IMAGE *img;
    GLenum gluerr;

    /* textura do plano */
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
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
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
        {
            camY = -15.0;
        }
        break;

    case 's':
        camY += 0.2;
        if (camY > 5.0)
        {
            camY = 5.0;
        }
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
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glEnable(GL_DEPTH_TEST);
    carregar_texturas();
    glShadeModel(GL_FLAT);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow(argv[0]);
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
