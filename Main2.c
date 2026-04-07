#include <GL/glut.h>
#include <stdlib.h>

static int rot = 0;
static float camY = -10.0;
static float camZ = 0.0;

void init(void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glEnable(GL_DEPTH_TEST);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    glTranslatef(0.0, camY, camZ);
    /* rotacao da cena*/
    glPushMatrix();
    glRotatef((GLfloat)rot, 0.0, 1.0, 0.0);

    /* Chao */
    glColor3f(0.1, 0.1, 0.1);
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
    glColor3f(0.8, 0.8, 0.8); 
    glPushMatrix();
    glTranslatef(0.0, 25.0, -15.0);
    glScalef(50.0, 0.1, 75.0);
    glutSolidCube(1.0);
    glPopMatrix();

    /* Parede esquerda */
    glColor3f(0.6, 0.6, 0.6);
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
    glColor3f(0.5, 0.5, 0.5);
    glPushMatrix();
    glTranslatef(0.0, 7.5, 20.0);
    glScalef(50.0, 35.0, 0.1);
    glutSolidCube(1.0);
    glPopMatrix();

    /*porta*/
    glColor3f(0.3, 0.2, 0.1);
    glPushMatrix();
    glTranslatef(-20.0, 2.0, -39.9);
    glScalef(-10.0, 15.0, 0.2);
    glutSolidCube(2.0);
    glPopMatrix();

    /* Tela */
    glColor3f(1.0, 1.0, 1.0);
    glPushMatrix();
    glTranslatef(0.0, 12.5, 19.9);
    glScalef(35.0, 20.0, 0.1);
    glutSolidCube(1.0);
    glPopMatrix();

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
            glColor3f(1.0, 0.0, 0.0);
            glTranslatef(-11.0 + x, 2.0 + y, 0.0 - z);
            glPushMatrix();
            glScalef(5.0, 1.0, 5.0);
            glutSolidCube(1.0);
            glPopMatrix();

            /* Braço esquerdo*/
            glColor3f(0.0, 1.0, 0.0);
            glPushMatrix();
            glTranslatef(-2.75, 0.0, 0.0);
            glScalef(0.5, 4.0, 5.0);
            glutSolidCube(1.0);
            glPopMatrix();

            /* Braço direito*/
            glColor3f(0.0, 1.0, 0.0);
            glPushMatrix();
            glTranslatef(2.75, 0.0, 0.0);
            glScalef(0.5, 4.0, 5.0);
            glutSolidCube(1.0);
            glPopMatrix();

            /* Encosto*/
            glColor3f(0.0, 0.0, 1.0);
            glPushMatrix();
            glRotatef(-5.0, 1.0, 0.0, 0.0);
            glTranslatef(0.0, 2.0, -3.0);
            glScalef(5.0, 5.0, 1.0);
            glutSolidCube(1.0);
            glPopMatrix();

            /*Escada
            glColor3f(0.8, 0.8, 0.8);
            glPushMatrix();
            glTranslatef(-14.0, 1.0 + (j * 3), -(j * 10.0) - 5.0);
            glScalef(3.0, 0.5, 10.0);
            glutSolidCube(1.0);
            glPopMatrix();
            */
            glPopMatrix();
        }
    }
    // Luzes
    for (int i = 0; i < 5; i++)
    {
        float y = (i > 2) ? 16.0 : 10.0 + (float)i * 2;
        float z =  -9 * (float)i;
        glColor3f(1.0, 1.0, 0.0);
        glPushMatrix();
        glTranslatef(-25.0, y, z);
        glutSolidSphere(0.75, 8, 8);
        glPopMatrix();

        glColor3f(1.0, 1.0, 0.0);
        glPushMatrix();
        glTranslatef(25.0, y, z);
        glutSolidSphere(0.75, 8, 8);
        glPopMatrix();
        
        //cones som
        glColor3f(0.0, 0.0, 0.0);
        glPushMatrix();
        glTranslatef(24.5, y - 2.0, z);
        glRotatef(0.0, 0.0, 1.0, 0.0);
        glutSolidCone(0.75, 1.5, 16, 16);
        glPopMatrix();

        glColor3f(0.0, 0.0, 0.0);
        glPushMatrix();
        glTranslatef(-24.5, y - 2.0, z);
        glRotatef(0.0, 0.0, 1.0, 0.0);
        glutSolidCone(0.75, 1.5, 16, 16);
        glPopMatrix();
        
    }

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
