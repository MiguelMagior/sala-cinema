#include <GL/glut.h>
#include <stdlib.h>

static int rot = 0;

void init(void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glEnable(GL_DEPTH_TEST);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    /* rotacao da cena*/
    glPushMatrix();
    glRotatef((GLfloat)rot, 0.0, 1.0, 0.0);

    float x;
    for (int i = 0; i < 5; i++)
    {
        glPushMatrix();
        x = i * 5.5;

        /* Almofada */
        glColor3f(1.0, 0.0, 0.0);
        glTranslatef(0.0 + x, 2.0, 0.0);
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
    gluPerspective(65.0, (GLfloat)w / (GLfloat)h, 1.0, 40.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0, -3.0, -10.0);
}

void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'r':
        rot = (rot + 5) % 360;
        glutPostRedisplay();
        break;
    case 'R':
        rot = (rot - 5) % 360;
        glutPostRedisplay();
        break;
    case 27:
        exit(0);
        break;
    default:
        break;
    }
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