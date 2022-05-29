#include <SDL2/SDL.h>

class Game
{
public:
    Game();
    ~Game();

    void init();
    void handleEvents();
    void update();
    void render();
    void clean();
    int run();
    void DrawCircle(SDL_Renderer *renderer, int32_t centreX, int32_t centreY, int32_t radius);

    bool running() { return isRunning; }

private:
    bool isRunning;
    SDL_Window *window;
    SDL_Renderer *renderer;
};