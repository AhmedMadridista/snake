#ifndef SNAKEH_H_INCLUDED
#define SNAKEH_H_INCLUDED
typedef enum direction direction;
enum direction{

    RIGHT,
    LEFT,
    UP,
    DOWN
};

typedef struct coordinate coordinate;
struct coordinate{
    int x;
    int y;
};

typedef struct body body;
struct body{

    int length;
    char element[1000];
    direction elementDirection[1000];
    coordinate elementCoordinate[1000];
};


typedef struct snake snake;
struct snake{

    char head;  //maybe < or > or ^  or v
    direction headDirection;
    coordinate headCoordinate;
    body snakeBody;
    coordinate transition[100];
    direction transitionDirection[100];
    int transitionNum;
};

void snakeInit(snake *me);

void newDirectionFunc(snake *me, direction newDirection); 

void print(snake *me);

void goForward(snake *me);

void initiateExample(snake *me);

void elementDirection(snake *me);
#endif // SNAKEH_H_INCLUDED
