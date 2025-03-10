#include "../include/so_long_utils.h"

typedef struct s_vertex
{
    int x;
    int y;
} t_vertex;

int within_the_bounds(int x, int y, int width, int height)
{
    return (x >= 0 && y >= 0 && x < width && y < height);
}
typedef struct s_bfs
{
    t_vertex    *queue;
    int         **was_visited;
    int         rear;
    int         front;
    int         width;
    int         height;
    char        **map;
}   t_bfs;

static void init_bfs(t_bfs *data, char **map, int width, int height)
{
	int i;

	i = 0;
    data->queue = malloc(sizeof(t_vertex) * (width * height));
    data->was_visited = malloc(sizeof(int *) * height);
    while (i < height)
    {
        data->was_visited[i] = malloc(sizeof(int) * width);
        ft_memset(data->was_visited[i], 0, sizeof(int) * width);
		i++;
    }
    data->rear = 0;
    data->front = 0;
    data->width = width;
    data->height = height;
    data->map = map;
}

static void cleanup_bfs(t_bfs *data)
{
    free(data->queue);
    for (int i = 0; i < data->height; i++)
        free(data->was_visited[i]);
    free(data->was_visited);
}

static void check_current_cell(t_vertex current, char **map, int *collectibles, int *exit_found)
{
    if (map[current.y][current.x] == 'C')
        (*collectibles)++;
    if (map[current.y][current.x] == 'E')
        *exit_found = 1;
}

static void explore_neighbors(t_bfs *data, t_vertex current)
{
	int edges[4][2];
	int i;

	i = 0;
	ft_memcpy(edges, (int[4][2]){{-1, 0}, {0, -1}, {1, 0}, {0, 1}}, sizeof(edges));
    while (i < 4)
    {
        int nx = current.x + edges[i][0];
        int ny = current.y + edges[i][1];
        if (within_the_bounds(nx, ny, data->width, data->height))
    	{
        	if (!data->was_visited[ny][nx] && data->map[ny][nx] != '1')
        	{
        	    data->was_visited[ny][nx] = 1;
         		data->queue[data->front++] = (t_vertex){nx, ny};
        	}
   		}
		i++;
    }
}

void bfs(char **map, int width, int height, int p_x, int p_y, 
         int *collectibles, int *exit_found)
{
    t_bfs   data;
    t_vertex current;

    if (!map || !collectibles || !exit_found || 
        !within_the_bounds(p_x, p_y, width, height))
        return;

    init_bfs(&data, map, width, height);
    *collectibles = 0;
    *exit_found = 0;

    data.queue[data.front++] = (t_vertex){p_x, p_y};
    data.was_visited[p_y][p_x] = 1;

    while (data.front > data.rear)
    {
        current = data.queue[data.rear++];
        check_current_cell(current, map, collectibles, exit_found);
        explore_neighbors(&data, current);
    }
    cleanup_bfs(&data);
}
