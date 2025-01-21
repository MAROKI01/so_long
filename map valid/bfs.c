#include "../so_long_utils.h"

typedef struct s_vertex
{
    int x;
    int y;
} t_vertex;

int within_the_bounds(int x, int y, int width, int height)
{
    return (x >= 0 && y >= 0 && x < width && y < height);
}

void bfs(char **map, int width, int height, int p_x, int p_y, int *collectibles, int *exit_found)
{
    if (!map || !collectibles || !exit_found || 
        !within_the_bounds(p_x, p_y, width, height))
        return;

    t_vertex queue[width * height];
    int edges[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    int was_visited[height][width];
    int rear = 0, front = 0;
    t_vertex current;

    memset(was_visited, 0, sizeof(was_visited));
    memset(queue, 0, sizeof(queue));
    *collectibles = 0;
    *exit_found = 0;

    queue[front++] = (t_vertex){p_x, p_y};
    was_visited[p_y][p_x] = 1;

    while (front > rear)
    {
        current = queue[rear++];
        
        if (map[current.y][current.x] == 'C')
            (*collectibles)++;
        if (map[current.y][current.x] == 'E')
            *exit_found = 1;

        for (int i = 0; i < 4; i++)
        {
            int nx = current.x + edges[i][0];
            int ny = current.y + edges[i][1];
            
            if (within_the_bounds(nx, ny, width, height))
            {
                if (!was_visited[ny][nx] && map[ny][nx] != '1')
                {
                    was_visited[ny][nx] = 1;
                    queue[front++] = (t_vertex){nx, ny};
                }
            }
        }
    }
}

int main() {
    // Example map
    char *map[] = {
        "1111111111111111111111111111111111",
        "1P0C00000000000100C00000000000C001",
        "1000000000000010100000000000000C01",
		"100000000000001E10000C000000000C01",
        "1111111111111111111111111111111111"
    };

    int rows = 34, cols = 5;
    int collectibles = 0;
    int exit_found = 0;

    // Find the player's starting position
    int start_x = 0, start_y = 0;
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            if (map[i][j] == 'P') {
                start_x = i;
                start_y = j;
            }
        }
    }

    // Perform BFS
    bfs(map, rows, cols, start_x, start_y, &collectibles, &exit_found);

    // Results
    printf("Collectibles found: %d\n", collectibles);
    printf("Exit found: %s\n", exit_found ? "Yes" : "No");

    return 0;
}