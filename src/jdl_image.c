#include "jdl_image.h"

SDL_Texture* JDL_image_to_texture ( char* path, SDL_Renderer* renderer )
{
    SDL_Texture* dst_texture = NULL;
    SDL_Surface* src_surface = IMG_Load( path );
    if ( src_surface == NULL )
    {
        printf( "Failed to load image %s. SDL_image Error: %s\n", path, IMG_GetError() );
    }
    else {
        dst_texture = SDL_CreateTextureFromSurface( renderer, src_surface );
        if ( dst_texture == NULL )
        {
            printf( "Failed to create texture from %s. SDL Error: %s\n", path, SDL_GetError() );
        }
        SDL_FreeSurface( src_surface );
    }
	return dst_texture;
}