#include <SDL2/SDL.h>
#include "../SDL2_swift_extensions.h"

int SDL_X_GetSurfaceWidth(SDL_Surface *s) {
	return s->w;
}

int SDL_X_GetSurfaceHeight(SDL_Surface *s) {
	return s->h;
}

int SDL_X_GetSurfacePitch(SDL_Surface *s) {
	return s->pitch;
}