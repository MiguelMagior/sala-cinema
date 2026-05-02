#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include "image.h"
#define TEXTURA_DO_PLANO "wood.rgb"

static int rot = 0;
static float camY = -10.0;
static float camZ = 0.0;

GLfloat mat_1_difusa[]    = { 0.2, 0.2, 0.2, 1.0 };// varios e caixa de som
GLfloat mat_1_especular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat mat_1_brilho[]    = { 50.0 };

GLfloat mat_2_difusa[]    = { 0.3, 0.3, 0.3, 1.0 };//chao
GLfloat mat_2_especular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat mat_2_brilho[]    = { 50.0 };

GLfloat mat_3_difusa[]    = { 0.5, 0.5, 0.5, 1.0 };//pilares e projetor e braço cadeira
GLfloat mat_3_especular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat mat_3_brilho[]    = { 50.0 };

GLfloat mat_4_difusa[]    = { 1.0, 1.0, 0.0, 1.0 }; //luzes
GLfloat mat_4_especular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat mat_4_brilho[]    = { 50.0 };

GLfloat mat_5_difusa[]    = { 0.1, 0.1, 0.1, 1.0 };//teto parede da tela
GLfloat mat_5_especular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat mat_5_brilho[]    = { 50.0 };

GLfloat mat_6_difusa[]    = { 0.3, 0.2, 0.1, 1.0 };// porta
GLfloat mat_6_especular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat mat_6_brilho[]    = { 50.0 };

GLfloat mat_7_difusa[]    = { 1.0, 1.0, 1.0, 1.0 };//tela
GLfloat mat_7_especular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat mat_7_brilho[]    = { 50.0 };

GLfloat mat_8_difusa[]    = { 0.5, 0.1, 0.1, 1.0 };//almofada encosto
GLfloat mat_8_especular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat mat_8_brilho[]    = { 50.0 };

GLfloat posicao_luz[]    = { 0.0, 3.0, 0.0, 1.0};
GLfloat cor_luz[]        = { 1.0, 1.0, 1.0, 1.0};
GLfloat cor_luz_amb[]    = { 0.2, 0.2, 0.2, 1.0};

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


    /* Chao */
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

    /* Teto */
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_5_difusa);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_5_especular);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mat_5_brilho);
    glPushMatrix();
    glTranslatef(0.0, 25.0, -15.0);
    glScalef(50.0, 0.1, 75.0);
    glutSolidCube(1.0);
    glPopMatrix();

    /* Parede esquerda
    glColor3f(1.0, 0.2, 0.2);
    glPushMatrix();
    glTranslatef(-25.0, 7.5, -15.0);
    glScalef(0.1, 35.0, 75.0);
    glutSolidCube(1.0);
    glPopMatrix();
    */

    /* Parede direita
    glPushMatrix();
    glTranslatef(25.0, 7.5, -15.0);
    glScalef(0.1, 35.0, 75.0);
    glutSolidCube(1.0);
    glPopMatrix();
*   /

    /* Parede fundo
    glPushMatrix();
    glTranslatef(0.0, 7.5, -40.0);
    glScalef(50.0, 35.0, 0.1);
    glutSolidCube(1.0);
    glPopMatrix();
    */

    /* Parede Tela */
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_5_difusa);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_5_especular);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mat_5_brilho);
    glPushMatrix();
    glTranslatef(0.0, 7.5, 20.0);
    glScalef(50.0, 35.0, 0.1);
    glutSolidCube(1.0);
    glPopMatrix();

    /* Parede esquerda com textura */
    glEnable(GL_TEXTURE_2D);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 0.0); glVertex3f(-24.95, -10.0, -52.5);
    glTexCoord2f(5.0, 0.0); glVertex3f(-24.95, -10.0, 22.5);
    glTexCoord2f(5.0, 5.0); glVertex3f(-24.95, 25.0, 22.5);
    glTexCoord2f(0.0, 5.0); glVertex3f(-24.95, 25.0, -52.5);
    glEnd();
    glDisable(GL_TEXTURE_2D);

    /* Parede direita com textura */
    glEnable(GL_TEXTURE_2D);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 0.0); glVertex3f(24.95, -10.0, -52.5);
    glTexCoord2f(5.0, 0.0); glVertex3f(24.95, -10.0, 22.5);
    glTexCoord2f(5.0, 5.0); glVertex3f(24.95, 25.0, 22.5);
    glTexCoord2f(0.0, 5.0); glVertex3f(24.95, 25.0, -52.5);
    glEnd();
    glDisable(GL_TEXTURE_2D);

    /* Parede fundo com textura  */
    glEnable(GL_TEXTURE_2D);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 0.0); glVertex3f(-25.0, -10.0, -39.95);
    glTexCoord2f(5.0, 0.0); glVertex3f(25.0, -10.0, -39.95);
    glTexCoord2f(5.0, 5.0); glVertex3f(25.0, 25.0, -39.95);
    glTexCoord2f(0.0, 5.0); glVertex3f(-25.0, 25.0, -39.95);
    glEnd();
    glDisable(GL_TEXTURE_2D);

    /* Porta */
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_6_difusa);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_6_especular);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mat_6_brilho);
    glPushMatrix();
    glTranslatef(-20.0, 2.0, -39.9);
    glScalef(-10.0, 15.0, 0.2);
    glutSolidCube(2.0);
    glPopMatrix();

    /* Tela*/
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_7_difusa);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_7_especular);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mat_7_brilho);
    glPushMatrix();
    glTranslatef(0.0, 12.5, 19.9);
    glScalef(35.0, 20.0, 0.1);
    glutSolidCube(1.0);
    glPopMatrix();

    /* Tela com Textura
    glEnable(GL_TEXTURE_2D);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 0.0);
    glVertex3f(-17.5, 2.5, 19.9); // Bottom-left
    glTexCoord2f(1.0, 0.0);
    glVertex3f(17.5, 2.5, 19.9); // Bottom-right
    glTexCoord2f(1.0, 1.0);
    glVertex3f(17.5, 22.5, 19.9); // Top-right
    glTexCoord2f(0.0, 1.0);
    glVertex3f(-17.5, 22.5, 19.9); // Top-left
    glEnd();
    glDisable(GL_TEXTURE_2D);
    */

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
            glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_8_difusa);
            glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_8_especular);
            glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mat_8_brilho);
            glTranslatef(-11.0 + x, 2.0 + y, 0.0 - z);
            glPushMatrix();
            glScalef(5.0, 1.0, 5.0);
            glutSolidCube(1.0);
            glPopMatrix();

            /* Braço esquerdo */
            glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_3_difusa);
            glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_3_especular);
            glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mat_3_brilho);
            glPushMatrix();
            glTranslatef(-2.75, 0.0, 0.0);
            glScalef(0.5, 4.0, 5.0);
            glutSolidCube(1.0);
            glPopMatrix();

            /* Braço direito */
            glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_3_difusa);
            glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_3_especular);
            glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mat_3_brilho);
            glPushMatrix();
            glTranslatef(2.75, 0.0, 0.0);
            glScalef(0.5, 4.0, 5.0);
            glutSolidCube(1.0);
            glPopMatrix();

            /* Encosto */
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
    /* Elementos Parede*/
    for (int i = 0; i < 4; i++)
    {
        float y = (i > 2) ? 19.0 : 15.0 + (float)i * 2;
        float z = -11 * (float)i;

        /* Pilares */
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

        /* Luzes */
        glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_4_difusa);
        glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_4_especular);
        glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mat_4_brilho);
        glPushMatrix();
        glTranslatef(-24.0, y, z);
        glScalef(1, 3.0, 1.0);
        glutSolidSphere(1, 8, 8);
        glPopMatrix();

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

        glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_1_difusa);
        glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_1_especular);
        glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mat_1_brilho);;
        glPushMatrix();
        glTranslatef(24.0, y - 1.75, z);
        glRotatef(90, 1.0, 0.0, 0.0);
        glutSolidCone(1.0, 2, 8, 8);
        glPopMatrix();

        /* Caixas de Som*/
        glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_1_difusa);
        glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_1_especular);
        glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mat_1_brilho);;
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
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_3_difusa);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_3_especular);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mat_3_brilho);
    glPushMatrix();
    glTranslatef(0.0, 22.5, -35);
    glScalef(5.0, 2.0, 3.0);
    glutSolidCube(1.0);
    glPopMatrix();

    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_3_difusa);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_3_especular);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mat_3_brilho);
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

void init(void){
  glClearColor (0.0, 0.0, 0.0, 0.0);
  glEnable(GL_DEPTH_TEST);

  // Configura a Luz 0
  glLightfv(GL_LIGHT0, GL_DIFFUSE, cor_luz);
  glLightfv(GL_LIGHT0, GL_SPECULAR, cor_luz);
  glLightfv(GL_LIGHT0, GL_AMBIENT, cor_luz_amb);
  glLightfv(GL_LIGHT0, GL_POSITION, posicao_luz);

  // Ativa a iluminação
  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);

  // Ativa a normalização automática (importante para luz bater certo nos objetos escalonados)
  glEnable(GL_AUTO_NORMAL);
  glEnable(GL_NORMALIZE);
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
