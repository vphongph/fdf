#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

typedef struct grid_iterator t_grid_iter;

typedef bool (*t_next)(t_grid_iter*, void *private);

typedef struct grid_iterator
{
	t_next next;
	void	*private;
}				t_grid_iter;


t_grid_iter iter_new(t_next next, void *private)
{
	return (t_grid_iter)
	{
		.next = next,
		.private = private
	};
}

void	print_grid(bool **grid)
{
	uint32_t y;
	uint32_t x;

	y = 0;

	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			if (grid[y][x] == 0)
				printf("#");
			else
				printf(".");
			x++;
		}
		printf("\n");
		y++;
	}
}

int main(void)
{
	(bool[][])
	{
		
	}
	bool **grid[4] = 
	{
		{0,1,1,0},
		{0,0,1,0},
		{0,0,0,0},
		{0,0,0,0},
	};

	print_grid(grid);

	return (0);
}
