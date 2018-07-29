#include <mlx.h>
#include <stdio.h>
int	key_thing(int keycode)
{
	fprintf(stderr, "%d\n", keycode);
	if (keycode == 80)
		exit(0);
	return (0);
}

void	sqr(void *mlx, void	*win)
{
	int i;
	int j;
	int mlty;
	int mltx;

	i = -1;
	mlty = 0;
	mltx = 0;
	while (++i <= 24)
	{
		j = -1;
		while (++j <= 800)
			mlx_pixel_put(mlx, win, j, mlty , 0x00FF0000);
		mlty += 20;
	}
	i = -1;
	while (++i <= 40)
	{
		j = -1;
		while (++j <= 480)
			mlx_pixel_put(mlx, win, mltx, j , 0x000000FF);
		mltx += 20;
	}
}
		

int		main(void)
{
	void *mlx;
	void *win;
	int x = 0;

	mlx = mlx_init(mlx);
	win =  mlx_new_window(mlx, 801, 481, "fuck it");
	sqr(mlx, win);
//	mlx_string_put(mlx, win, 0, 5, 0x00FFFFFF, "this is a string");
	mlx_key_hook(win,&key_thing,0);
	mlx_loop(mlx);
}
