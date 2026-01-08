#include <stdio.h>
#include <stdlib.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <time.h>

// TYPE DECLARATION
struct node
{
	int 	x;
	int 	y;
	struct node 	*next;
	struct node 	*prev;
};
enum dir{ RIGHT = 0 , LEFT = 1, UP = 2 , DOWN = 3 };
typedef enum {FALSE = 0 , TRUE = 1} bool_t;

///VARIABLE DECLARATION
	struct node 	*head = NULL;
	struct node 	*change = NULL;
	int snake_size;
	int highest_score = 0; 
	int change_x;
	int change_y;
	int food_x;
	int food_y;
	int speed;
	bool_t ate;
	bool_t play;
	enum dir direction;



//FUNCTION
void initNode()
{
	head = (struct node *)malloc(sizeof(struct node));
	head -> next  =  head -> prev = NULL;
	head -> x = 40;
	head -> y = 60;
	struct node 	*tail = head;
	int	i;
	struct node *newnode = NULL;
	for( i = 0 ; i < snake_size ; i++ )
	{
		newnode			= 	(struct node *)malloc(sizeof(struct node));
		newnode -> x 		= 	tail -> x  + 11;
		newnode -> y 		= 	tail -> y;
		tail -> next		= 	newnode;
		newnode -> prev		= 	tail;
		newnode -> next		= 	head;
		head -> prev		= 	newnode;
		tail			= 	newnode;
	}
	change = head;
}


void initGame()
{
	glColor3f(0.0, 0.0, 0.0);
	snake_size = 5;
	direction = RIGHT;
	change_x = 11;
	change_y = 0;
	food_x = 160;
	food_y = 60;
	ate = FALSE;
	speed = 5;
	play = FALSE;
	initNode();
}

void addNode( struct node *add)
{
	struct node *newnode =  (struct node *)malloc(sizeof(struct node));
	newnode -> x = add -> x ;
	newnode -> y = add -> y ;
	newnode -> next = add -> next;
	newnode -> prev = add;
	add -> next = newnode; 
	newnode -> next -> prev = newnode;
	snake_size++;
}


void freeNode()
{
	struct node *temp;
	do
	{
		temp = head -> next -> next;
		free( head -> next);
		head -> next = temp;
		temp -> prev = head;
	}while(head -> next -> next != head);
	free(head -> next);
	free(head);
}


bool_t checkEqualNode( int x1 , int y1 , int x2 , int y2)
{
	if( 	((x1 - 5) <= (x2 + 5 ) && (x1 + 5 ) >= ( x2 + 5 ) ) && ((y1 - 5) <= (y2 + 5) && (y1 + 5 ) >= (y2 + 5) ) ||
			((x1 - 5) <= (x2 + 5 ) && (x1 + 5 ) >= ( x2 + 5 ) ) && ((y1 - 5) <= (y2 - 5) && (y1 + 5 ) >= (y2 - 5) ) ||
			((x1 - 5) <= (x2 - 5 ) && (x1 + 5 ) >= ( x2 - 5 ) ) && ((y1 - 5) <= (y2 + 5) && (y1 + 5 ) >= (y2 + 5) ) ||
			((x1 - 5) <= (x2 - 5 ) && (x1 + 5 ) >= ( x2 - 5 ) ) && ((y1 - 5) <= (y2 - 5) && (y1 + 5 ) >= (y2 - 5) )
		)
		return TRUE;
	else
		return FALSE;
}

bool_t search( int x , int y)
{
	struct node * temp = head;
	do
	{
		if( checkEqualNode( temp -> x , temp -> y , x , y  ) )
		{
				return TRUE;
		}
		temp = temp -> next;
	}while( temp != head );
	return FALSE;
}

void drawCell( int x , int y)  //draw a single cell of snake
{
	
	glRecti( x-5 ,  y-5 , x+5 , y+5 );
}


void wait_for_time(int t)
{
	struct timespec rem;
	rem.tv_sec = 0;
	rem.tv_nsec = 10000000 * t;
	nanosleep( &rem , NULL  );
}

void drawSnake(void)
{
	int j=0;
	
	struct  node *temp = head;
	do
	{
		drawCell( temp -> x , temp -> y );
		temp = temp -> next;
	}while(temp != head);
}

void createFood()
{
	srand(time(0));
	do{
		food_x = rand() % 628 + 6	;
		food_y = rand() % 468 + 6;
	}while(search(food_x , food_y) );
}

void displayFood()
{
	drawCell( food_x , food_y );
}

void drawHead( int x , int y)
{
	if( direction == RIGHT || direction == LEFT )
	{
		glBegin(GL_TRIANGLES);
		glVertex2i( x - 5 , y + 5);
		glVertex2i( x     , y + 9);	
		glVertex2i( x + 5 , y + 5);
		glEnd();
	}
	else
	{
		glBegin(GL_TRIANGLES);
		glVertex2i( x + 5 , y - 5);
		glVertex2i( x + 9  , y   );	
		glVertex2i( x + 5 , y + 5);
		glEnd();
	}
}
