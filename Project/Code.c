#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_TUBES 6
#define TUBE_CAPACITY 4
#define NUM_COLORS 4
#define MAX_HISTORY 1000

enum Color { RED, BLUE, GREEN, YELLOW };

const char* colorNames[] = {"RED", "BLUE", "GREEN", "YELLOW", " "};

typedef struct
{
    int stack[TUBE_CAPACITY];
    int top;
} Tube;

typedef struct
{
    Tube tubes[MAX_TUBES];
} GameState;

void initGame(GameState *game);
void randomizeColors(GameState *game);
void printGameState(const GameState *game);
int isValidMove(const GameState *game, int from, int to);
void makeMove(GameState *game, int from, int to);
int isSolved(const GameState *game);
void pushState(GameState *history[], int *historyIndex, const GameState *game);
void popState(GameState *history[], int *historyIndex, GameState *game);
void clearHistory(GameState *history[], int *historyIndex);

void initGame(GameState *game)
{
    for (int i = 0; i < MAX_TUBES; i++)
    {
        game->tubes[i].top = -1;
        for (int j = 0; j < TUBE_CAPACITY; j++)
        {
            game->tubes[i].stack[j] = -1;
        }
    }
    randomizeColors(game);
}

void randomizeColors(GameState *game)
{
    int colors[NUM_COLORS * TUBE_CAPACITY];
    for (int i = 0; i < NUM_COLORS * TUBE_CAPACITY; i++)
    {
        colors[i] = i / TUBE_CAPACITY;
    }

    for (int i = NUM_COLORS * TUBE_CAPACITY - 1; i > 0; i--)
    {
        int j = rand() % (i + 1);
        int temp = colors[i];
        colors[i] = colors[j];
        colors[j] = temp;
    }

    int index = 0;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < TUBE_CAPACITY; j++)
        {
            game->tubes[i].stack[j] = colors[index++];
            game->tubes[i].top++;
        }
    }
}

void printGameState(const GameState *game)
{
    printf("\nCurrent Game State:\n");
    for (int level = TUBE_CAPACITY - 1; level >= 0; level--)
    {
        for (int i = 0; i < MAX_TUBES; i++)
        {
            if (game->tubes[i].top >= level)
                printf(" %6s ", colorNames[game->tubes[i].stack[level]]);
            else
                printf("        ");
        }
        printf("\n");
    }
    for (int i = 0; i < MAX_TUBES; i++)
    {
        printf(" Tube %d ", i + 1);
    }
    printf("\n\n");
}

int isValidMove(const GameState *game, int from, int to)
{
    if (from < 0 || from >= MAX_TUBES || to < 0 || to >= MAX_TUBES || from == to)
        return 0;

    int fromTop = game->tubes[from].top;
    int toTop = game->tubes[to].top;

    if (fromTop == -1)
        return 0;

    if (toTop == TUBE_CAPACITY - 1)
        return 0;

    int fromColor = game->tubes[from].stack[fromTop];

    if (toTop == -1 || game->tubes[to].stack[toTop] == fromColor)
        return 1;

    return 0;
}

void makeMove(GameState *game, int from, int to)
{
    int color = game->tubes[from].stack[game->tubes[from].top];
    game->tubes[from].stack[game->tubes[from].top--] = -1;

    game->tubes[to].stack[++game->tubes[to].top] = color;
}

int isSolved(const GameState *game)
{
    for (int i = 0; i < MAX_TUBES; i++)
    {
        int top = game->tubes[i].top;
        if (top == -1) continue;

        int color = game->tubes[i].stack[0];
        for (int j = 1; j <= top; j++)
        {
            if (game->tubes[i].stack[j] != color)
                return 0;
        }
        if (top != TUBE_CAPACITY - 1)
            return 0;
    }
    return 1;
}

void pushState(GameState *history[], int *historyIndex, const GameState *game)
{
    if (*historyIndex < MAX_HISTORY - 1)
    {
        (*historyIndex)++;
        history[*historyIndex] = (GameState *)malloc(sizeof(GameState));
        memcpy(history[*historyIndex], game, sizeof(GameState));
    }
}

void popState(GameState *history[], int *historyIndex, GameState *game)
{
    if (*historyIndex > 0)
    {
        free(history[*historyIndex]);
        (*historyIndex)--;
        memcpy(game, history[*historyIndex], sizeof(GameState));
    }
    else
    {
        printf("Cannot undo beyond initial state.\n");
    }
}

void clearHistory(GameState *history[], int *historyIndex)
{
    for (int i = 0; i <= *historyIndex; i++)
    {
        free(history[i]);
    }
    *historyIndex = -1;
}

int main()
{
    GameState game;
    GameState *history[MAX_HISTORY];
    int historyIndex = -1;
    char input[20];
    int fromTube, toTube;

    srand(time(NULL));

    initGame(&game);
    pushState(history, &historyIndex, &game);

    while (1)
    {
        printGameState(&game);

        if (isSolved(&game))
        {
            printf("Congratulations! You've solved the puzzle.\n");
            break;
        }

        printf("Enter move (from to), 'undo', or 'restart': ");
        scanf("%s", input);

        if (strcmp(input, "undo") == 0)
        {
            popState(history, &historyIndex, &game);
            continue;
        }
        else if (strcmp(input, "restart") == 0)
        {
            clearHistory(history, &historyIndex);
            initGame(&game);
            pushState(history, &historyIndex, &game);
            continue;
        }
        else
        {
            fromTube = atoi(input);
            scanf("%d", &toTube);
            fromTube--; toTube--;

            if (isValidMove(&game, fromTube, toTube))
            {
                makeMove(&game, fromTube, toTube);
                pushState(history, &historyIndex, &game);
            }
            else
            {
                printf("Invalid move. Try again.\n");
            }
        }
    }

    clearHistory(history, &historyIndex);
    return 0;
}
