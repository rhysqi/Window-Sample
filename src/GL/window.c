
#include <GL/gl.h>
#include <GL/glut.h>

void display(void)
{
    //Clear all pixels
    glClear(GL_COLOR_BUFFER_BIT);
    
    // Don't wait start processing buffered OpenGL routines
    glFlush();
}

void init(){
    //select clearing (background) color
    glClearColor(0.0, 100.0, 50.0, 10.0);
}

int main(int argc, char **argv){

    //Initialise GLUT with command-line parameters. 
    glutInit(&argc, argv);
    
    //Set Display Mode
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    
    //Set the window size
    glutInitWindowSize(250,250);
    
    //Set the window position
    glutInitWindowPosition(100,100);
    
    //Create the window
    glutCreateWindow("A Simple OpenGL Windows Application with GLUT");
    
    //Call init (initialise GLUT
    init();
    
    //Call "display" function
    glutDisplayFunc(display);
    
    //Enter the GLUT event loop
    glutMainLoop();

    return 0;
}