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

class Aceite : public Bloque {
    
public:
    
    
};

class Player : public Bloque {
public:


   bool borderLower = false;
    bool borderUpper = false;
    bool borderLeft = false;
    bool borderRight = false;
    bool onAceite = false;

    bool isMoveX = false;
    bool isMoveY = false;

    void moveX(int newPosX){
        if(newPosX < 10 && newPosX >= 0)
            this->posX = newPosX;
    }
    void moveY(int newPosY){
        if(newPosY < 10 && newPosY >= 0)
            this->posY = newPosY;
    }
    
    void move(float delta){
        moveOnX(delta);
        moveOnY(delta);

    }
    
    void moveOnY(float delta){
        if(y < coordsY[posY] + 1 && y > coordsY[posY] - 1){
            isMoveY = false;
            y = coordsY[posY];
        }
        else if(y > coordsY[posY]){
            y -= delta;
        }
        else if(y < coordsY[posY]){
            y += delta;
        }
    }
    
    void moveOnX(float delta){
        if(x < coordsX[posX] + 1 && x > coordsX[posX] - 1){
            isMoveX = false;
            x = coordsX[posX];
        }
        else if(x > coordsX[posX]){
            x -= delta;
        }
        else if(x < coordsX[posX]){
            x += delta;
        }
    }

     void compareBorder(Bloque bloque) {

            if (bloque.posY == this -> posY + 1 && bloque.posX == this -> posX){
                this -> borderLower = true;
            }
           

            if (bloque.posY == this -> posY - 1 && bloque.posX == this -> posX){
                this -> borderUpper = true;
            }
            


            if (bloque.posY == this -> posY && bloque.posX == this -> posX - 1){
                this -> borderLeft = true;
            }
            
             if (bloque.posY == this -> posY && bloque.posX == this -> posX + 1){
                this -> borderRight = true;
            }

    }
    
    void isBloqueAceite(Aceite aceite){
        if(aceite.posY == this -> posY && aceite.posX == this -> posX){
            onAceite = true;
        }
        else{
            onAceite = false;
        }
    }
};

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods){
    Player * pj = reinterpret_cast<Player *>(glfwGetWindowUserPointer(window));

    if(pj -> isMoveX == false && pj->isMoveY == false){

        switch (key) {
            case GLFW_KEY_UP:
                if(pj -> borderUpper == false){
                pj-> moveY(pj->posY - 1);
                pj-> isMoveY = true;
            }
                pj -> borderUpper = false;
                break;
            case GLFW_KEY_DOWN:

                if(pj -> borderLower == false){
    

                pj-> moveY(pj->posY + 1);
                pj-> isMoveY = true;
                }
                 pj -> borderLower = false;
                break;
            case GLFW_KEY_LEFT:
            if(pj -> borderLeft == false){
                pj-> moveX(pj->posX - 1);
                pj-> isMoveX = true;
            }
                pj -> borderLeft = false;
                break;
            case GLFW_KEY_RIGHT:
            if(pj -> borderRight == false){
                pj-> moveX(pj->posX + 1);
                pj-> isMoveX = true;
            }
                pj -> borderRight = false;
                break;
            default:
                break;
        }
    }
}

int main (void){
    GLFWwindow* window;
    glfwInit();
    window = glfwCreateWindow(600, 600, "Game", NULL, NULL);
    if (!window){
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    GLfloat _width = 800;
    GLfloat _height = 800;
    
    float temporal = 0.0;
    float delta = 0.0;
    Bloque bloques[35];
    //marco

    bloques[0].setPositions(0,0);
    bloques[1].setPositions(0,1);
   bloques[2].setPositions(0,2);
    bloques[3].setPositions(0,5);
    bloques[4].setPositions(1,7);
    bloques[5].setPositions(1,8);
    bloques[6].setPositions(1,9);
    bloques[7].setPositions(2,0);
    bloques[8].setPositions(2,4);
    bloques[9].setPositions(2,5);
    bloques[10].setPositions(3,0);
    bloques[11].setPositions(3,2);
    bloques[12].setPositions(3,5);
    bloques[13].setPositions(3,8);
    bloques[14].setPositions(3,9);
    bloques[15].setPositions(4,2);
    bloques[16].setPositions(4,3);
    bloques[17].setPositions(5,4);
    bloques[18].setPositions(5,5);
    bloques[19].setPositions(5,9);
    bloques[20].setPositions(6,0);
    bloques[21].setPositions(6,1);
    bloques[22].setPositions(6,2);
    bloques[23].setPositions(6,9);
    bloques[24].setPositions(7,0);
    bloques[25].setPositions(7,2);
    bloques[26].setPositions(7,5);
    bloques[27].setPositions(8,0);
    bloques[28].setPositions(8,2); 
    bloques[29].setPositions(8,4); 
    bloques[30].setPositions(8,5); 
    bloques[31].setPositions(9,0); 
    bloques[32].setPositions(9,1); 
    bloques[33].setPositions(9,2); 
    bloques[34].setPositions(9,8); 
   
   //marco

    
    
    Player pj;
    pj.setPositions(1, 0);
    
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

//player

        glColor3f(1, 0, 0);
        glBegin(GL_QUADS);
        glVertex2d(pj.getX(),   pj.getY());
        glVertex2d(pj.getX() + 20,  pj.getY());
        glVertex2d(pj.getX() + 20,  pj.getY() + 20);
        glVertex2d(pj.getX(),  pj.getY() + 20);
        
        pj.move(delta * 150);

        
        glEnd();

//bloques

        glColor3f(2 * sin (0.5 * 5*glfwGetTime()), 0.4 * cos(5*glfwGetTime()), 0.7 * sin (1*glfwGetTime()));
        glBegin(GL_QUADS);
        for (int i = 0; i < 35; i++) {
            glVertex2d(bloques[i].getX(),   bloques[i].getY());
            glVertex2d(bloques[i].getX() + 20,  bloques[i].getY());
            glVertex2d(bloques[i].getX() + 20,  bloques[i].getY() + 20);
            glVertex2d(bloques[i].getX(),  bloques[i].getY() + 20);
            pj.compareBorder(bloques[i]);
        }
        
        glEnd();
        
      

        glfwSwapBuffers(window);
        glfwPollEvents();

    }

    glfwTerminate();
}

