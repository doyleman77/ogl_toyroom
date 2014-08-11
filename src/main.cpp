#define GLEW_STATIC
#include <GL/glew.h>

#include <iostream>

#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>


int main(int argc, char* argv[])
{
    SDL_Init(SDL_INIT_VIDEO);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);

    SDL_Window* window = SDL_CreateWindow("OpenGL", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_OPENGL);
    SDL_GLContext context = SDL_GL_CreateContext(window);

    glewExperimental = GL_TRUE;
    glewInit();

    GLuint vertex_buffer;
    glGenBuffers(1, &vertex_buffer);

    std::cout << vertex_buffer << std::endl;

    SDL_Event game_event;

    float vertices[] =
    {
        0.0f, 0.5f,
        0.5f, -0.5f,
        -0.5f, -0.5f
    };

    GLuint vbo;
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    bool running = true;
    while(running)
    {
        if(SDL_PollEvent(&game_event))
        {
            switch(game_event.type)
            {
            case SDL_QUIT:
                running = false;
                break;
            }
        }
        SDL_GL_SwapWindow(window);
    }
    SDL_GL_DeleteContext(context);
    return 0;
}
