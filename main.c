
// macro for the key press

#define KEYPRESS		2
#define KEYPRESS_MASK	(1L<<0)
#define WIN_X			800
#define WIN_Y			600


 #include <strings.h> // TODO remove
 #include <stdio.h> // TODO remove
 #include <stdlib.h> // TODO remove
 #include <stdint.h> // TODO remove



#include <mlx.h>
#include "keycode_mac.h"


typedef struct s_env //mega struct pour le projet mlx car pas acces a la loop
{
	void *mlx_context;
	void *mlx_window;
	void *image;
	char *pix_buff;
	int  bpp;
	int32_t  len_line;
	int  endian;
	int  up_down;
	int  left_right;
}				t_env;


void	put_pixel(t_env *e, int x, int y, int color)
{
	int a, b, c;

	// (void)x;
	// (void)y;
	// (void)color;

	// *(int *)&e->pix_buff[y * e->len_line + x * e->bpp / 8] = color;

	// char	(*segments)[phnum][phentsize] = NULL;

	int (*buff)[e->len_line][1]; //variably-modified type system, syntactic sugar
	// int (*buff)[97890879087][]; //variably-modified type system, syntactic sugar

	// char (*buff)[e->len_line][e->bpp/8]; //variably-modified type system, syntactic sugar

	// char a[2][3]

	// a[0][0] a[0][1] a[0][2] a[1][0] a[1][1] a[1][2] 

	while (i < 19) {
		

	}

	int (*magic)[WIN_Y][e->len_line] = e->pix_buff;

	(*magic)[y][x] = color;

	// buff = (void *)e->pix_buff; void ????
	// buff = (int(*)[e->len_line][1])e->pix_buff;
	// buff = (char(*)[e->len_line][e->bpp/8])e->pix_buff;
}

int 	key_hit(int keycode, t_env *e)
{
	printf("%d\n", keycode);

	if (keycode == KEY_UP)
		put_pixel(e, e->left_right, e->up_down -= 10,  0x00ff0000); 
		// update of the pixel, press up, put the pixel up
		// the int is minus because the y axis is upside down, the origin of the window is the upper left corner

	if (keycode == KEY_ESCAPE)
		exit(0);
	mlx_put_image_to_window(e->mlx_context, e->mlx_window, e->image, 0, 0);

	return (0);
}

int main(void)
{
	// int lol[97890879087];

	t_env e;

	bzero(&e, sizeof(e)); // TODO FT_BZERO


	e.up_down = 300; // is where the current pix is on the y axis ?
	e.left_right = 400; //  // is where the current pix is on the x axis ?


	e.mlx_context = mlx_init(); // init the lib + void pointer, utility of the ptr ?

	e.mlx_window = mlx_new_window(e.mlx_context,WIN_X,WIN_Y,"john"); // open window + size + name of window


	e.image = mlx_new_image(e.mlx_context, WIN_X, WIN_Y); // create image + size

	e.pix_buff = mlx_get_data_addr(e.image, &e.bpp, &e.len_line, &e.endian); 
	// get all info of a image and return the adress of the buffer where to set the pixels to display
	// warning ! the buffer is a char ptr, 
	// it's horrible but we can gain in memory allocation (all in one string, one malloc)

	put_pixel(&e, e.left_right, e.up_down,  0x00ff0000);
	//write the pixel x y on the right place/adresse in the buffer
	mlx_put_image_to_window(e.mlx_context, e.mlx_window, e.image, 0, 0);
	//draw the buffer on the window

	mlx_hook(e.mlx_window, KEYPRESS, KEYPRESS_MASK, key_hit, &e);
	// function to catch event, interrupt ? called each loop
	// catch a type of action define by a int, see x11.h on google
	// with ptr to function in where we go during the event and get info from the action catched (int keycode) ?
	// the funtion have our param as input too ?
	// syntax of the ptr on function ?

	mlx_loop(e.mlx_context); // function to loop, we cannot be inside (this sucks), how we loop ?


	return (0);
}