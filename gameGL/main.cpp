#include <GLFW/glfw3.h>
#include <iostream>
#include <cmath>


using namespace std;

class Bloque{
    float width = 20;
    float height = 20;
    
public:
    float x = 0.0;
    float y = 0.0;
    int posX = 0, posY = 0;
    int coordsX[10] = {-100,-80,-60,-40,-20,0,20,40,60,80};
    int coordsY[10] = {80,60,40,20,0,-20,-40,-60,-80,-100};

    int getX(){
        return x;
    }
    int getY(){
        return y;
    }
    void setPositions(int posX, int posY){
        this->x = coordsX[posX];
        this->y = coordsY[posY];
        this->posX = posX;
        this->posY = posY;
    }
};

class Player : public Bloque {

public:
    void moveX(int newPosX){
        this->posX = newPosX;
    }
    void moveY(int newPosY){
        this->posY = newPosY;
    }
    void move(float delta){
        cout << y << " - "<<coordsY[posY];
        if(x < coordsX[posX])
            x+=delta;
        if(x > coordsX[posX])
            x-=delta;
        if(y < coordsY[posY])
            y+=delta;
        if(y > coordsY[posY])
            y-=delta;
        
    }
};

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods){
    Player * pj = reinterpret_cast<Player *>(glfwGetWindowUserPointer(window));
    switch (key) {
        case GLFW_KEY_UP:
            pj->moveY(pj->posY - 1);
            break;
        case GLFW_KEY_DOWN:
            pj->moveY(pj->posY + 1);
            break;
        case GLFW_KEY_LEFT:
            cout << "arriba";
            break;
        case GLFW_KEY_RIGHT:
            cout << "arriba";
            break;
        default:
            break;
    }
    
    
}

int main (void){
    GLFWwindow* window;
    glfwInit();
    window = glfwCreateWindow(800, 800, "Game", NULL, NULL);
    if (!window){
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    GLfloat _width = 800;
    GLfloat _height = 800;
    
    float temporal = 0.0;
    float delta = 0.0;
    Bloque bloques[5];
    bloques[0].setPositions(0,0);
    bloques[1].setPositions(0,3);
    bloques[2].setPositions(3,3);
    bloques[3].setPositions(4,10);
    bloques[4].setPositions(10,10);
    Player pj;
    pj.setPositions(1, 1);
    
    glfwSetWindowUserPointer(window, &pj);
    glfwSetKeyCallback(window, key_callback);
    while (!glfwWindowShouldClose(window)) {
        delta = glfwGetTime() - temporal;
        temporal = glfwGetTime();
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        GLfloat aspect = _width / _height;
        glOrtho(-aspect*100, aspect*100, -100.0f, 100.0f, -1.0, 1.0);
        glMatrixMode(GL_MODELVIEW);
        glColor3f(sin (0.8 * 5*glfwGetTime()), 0.4 * cos(2*glfwGetTime()), 0.7 * sin (3*glfwGetTime()));
        glBegin(GL_QUADS);
        for (int i = 0; i < 5; i++) {
            glVertex2d(bloques[i].getX(),   bloques[i].getY());
            glVertex2d(bloques[i].getX() + 20,  bloques[i].getY());
            glVertex2d(bloques[i].getX() + 20,  bloques[i].getY() + 20);
            glVertex2d(bloques[i].getX(),  bloques[i].getY() + 20);
        }
        
        glVertex2d(pj.getX(),   pj.getY());
        glVertex2d(pj.getX() + 20,  pj.getY());
        glVertex2d(pj.getX() + 20,  pj.getY() + 20);
        glVertex2d(pj.getX(),  pj.getY() + 20);
        pj.move(delta * 50);
        glEnd();
        
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwTerminate();
}
