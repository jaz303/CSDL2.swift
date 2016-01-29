#include <SDL2/SDL.h>
#include "../SDL2_swift_extensions.h"

int SDL_X_SurfaceGetWidth(SDL_Surface *s) {
	return s->w;
}

int SDL_X_SurfaceGetHeight(SDL_Surface *s) {
	return s->h;
}