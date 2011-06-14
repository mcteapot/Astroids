#include "Spank.h"

Spank::Spank()
{
    //cstr
}

//begin SETVALUES, CALLED WITHIN CHECKCOLLISION
void Spank::setValues(Sprite *spriteA, Sprite *spriteB)
{
	this->tilesX = 1;
	this->tilesY = 1;
	this->tileWidthA = spriteA->getSpriteSurface()->w / tilesX;
	this->tileWidthB = spriteB->getSpriteSurface()->w / tilesX;
	this->tileHeightA = spriteA->getSpriteSurface()->h / tilesY;
	this->tileHeightB = spriteB->getSpriteSurface()->h / tilesY;

	positionA.X = spriteA->getX();
	positionA.Y = spriteA->getY();
	positionB.X = spriteB->getX();
	positionB.Y = spriteB->getY();

	this->originA.X = tileWidthA / 2.0f;
	this->originA.Y = tileHeightA / 2.0f;
	this->originB.Y = tileHeightB / 2.0f;
	this->originB.Y = tileHeightB / 2.0f;
}
void Spank::setValues(Ship *shipA, Astroid *astroidB)
{
	this->tilesX = 1;
	this->tilesY = 1;
	this->tileWidthA = shipA->getSpriteSurface()->w / tilesX;
	this->tileWidthB = astroidB->getSpriteSurface()->w / tilesX;
	this->tileHeightA = shipA->getSpriteSurface()->h / tilesY;
	this->tileHeightB = astroidB->getSpriteSurface()->h / tilesY;

	positionA.X = shipA->getX();
	positionA.Y = shipA->getY();
	positionB.X = astroidB->getX();
	positionB.Y = astroidB->getY();

	this->originA.X = tileWidthA / 2.0f;
	this->originA.Y = tileHeightA / 2.0f;
	this->originB.Y = tileHeightB / 2.0f;
	this->originB.Y = tileHeightB / 2.0f;
}
//END SETVALUES
Spank::~Spank()
{
    //SDL_FreeSurface(screen);
}

void Spank::GetBounds()
{
	//Bounds for spriteA
	boundsA.x = (Sint16)(positionA.X - originA.X);
	boundsA.y = (Sint16)(positionA.Y - originA.Y);
	boundsA.w = (Sint16)(tileWidthA);
	boundsA.h = (Sint16)(tileHeightA);

	//Bounds for spriteB
	boundsB.x = (Sint16)(positionB.X - originB.X);
	boundsB.y = (Sint16)(positionB.Y - originB.Y);
	boundsB.w = (Sint16)(tileWidthB);
	boundsB.h = (Sint16)(tileHeightB);
}

SDL_Rect Spank::NormalizeBounds(const SDL_Rect& rect, bool isObjectA)
{
	SDL_Rect normalized;
	if(isObjectA)
	{
	    normalized.x = rect.x - (Sint16)positionA.X + (Sint16)originA.X;// + GetFrameBounds().x;
        normalized.y = rect.y - (Sint16)positionA.Y + (Sint16)originA.Y;// + GetFrameBounds().y;
        normalized.w = rect.w;
        normalized.h = rect.h;
	}
	else
	{
	    normalized.x = rect.x - (Sint16)positionB.X + (Sint16)originB.X;// + GetFrameBounds().x;
        normalized.y = rect.y - (Sint16)positionB.Y + (Sint16)originB.Y;// + GetFrameBounds().y;
        normalized.w = rect.w;
        normalized.h = rect.h;
	}

	return normalized;
}

SDL_Rect Spank::Intersection(const SDL_Rect& boundA, const SDL_Rect& boundB)
{
	int x1 = Maximum(boundA.x, boundB.x);
	int y1 = Maximum(boundA.y, boundB.y);
	int x2 = Minimum(boundA.x + boundA.w, boundB.x + boundB.w);
	int y2 = Minimum(boundA.y + boundA.h, boundB.y + boundB.h);

	int width = x2 - x1;
	int height = y2 - y1;

	if(width > 0 && height > 0)
	{
		SDL_Rect intersect = {x1, y1, width, height};
		return intersect;
	}
	else
	{
		SDL_Rect intersect = {0, 0, 0, 0};
		return intersect;
	}
}
/* CHECK COLLISION FUNCTIONS... START */
//ship astroid, bullet astroid
bool Spank::CheckCollision(Sprite* spriteA, Sprite* spriteB)
{
    setValues(spriteA, spriteB);
	SDL_Rect collisionRect = Intersection(boundsA, boundsB);

	if(collisionRect.w == 0 && collisionRect.h == 0)
		return false;

	SDL_Rect normalA = NormalizeBounds(collisionRect, true);//spriteA
	SDL_Rect normalB = NormalizeBounds(collisionRect, false);//spriteB

	for(int y = 0; y < collisionRect.h; y++)
		for(int x = 0; x < collisionRect.w; x++)
			if(GetAlphaXY(spriteA, normalA.x + x, normalA.y + y) && GetAlphaXY(spriteB, normalB.x + x, normalB.y + y))
				return true;

	return false;
}
bool Spank::CheckCollision(Ship* shipA, Astroid* astroidB)
{
    setValues(shipA, astroidB);
	SDL_Rect collisionRect = Intersection(boundsA, boundsB);

	if(collisionRect.w == 0 && collisionRect.h == 0)
		return false;

	SDL_Rect normalA = NormalizeBounds(collisionRect, true);//spriteA
	SDL_Rect normalB = NormalizeBounds(collisionRect, false);//spriteB

	for(int y = 0; y < collisionRect.h; y++)
		for(int x = 0; x < collisionRect.w; x++)
			if(GetAlphaXY(shipA, normalA.x + x, normalA.y + y) && GetAlphaXY(astroidB, normalB.x + x, normalB.y + y))
				return true;

	return false;
}
bool Spank::CheckCollision(Astroid* astroidB, Ship* shipA)
{
    CheckCollision(shipA, astroidB);
}
/* CHECK COLLISION FUNCTIONS... END */

/*GETALPHAXY FUNCTIONS... CALLED WITHIN CHECKCOLLISION */
bool Spank::GetAlphaXY(Sprite* entity, int x, int y)
{
	int bpp = entity->getSpriteSurface()->format->BytesPerPixel;
	Uint8* p = (Uint8*)entity->getSpriteSurface()->pixels + y * entity->getSpriteSurface()->pitch + x * bpp;
	Uint32 pixelColor;

	switch(bpp)
	{
		case(1):
			pixelColor = *p;
			break;
		case(2):
			pixelColor = *(Uint16*)p;
			break;
		case(3):
			if(SDL_BYTEORDER == SDL_BIG_ENDIAN)
				pixelColor = p[0] << 16 | p[1] << 8 | p[2];
			else
				pixelColor = p[0] | p[1] << 8 | p[2] << 16;
			break;
		case(4):
			pixelColor = *(Uint32*)p;
			break;
	}

	Uint8 red, green, blue, alpha;
	SDL_GetRGBA(pixelColor, entity->getSpriteSurface()->format, &red, &green, &blue, &alpha);

	return alpha > 200;
}

bool Spank::GetAlphaXY(Ship* entity, int x, int y)
{
	int bpp = entity->getSpriteSurface()->format->BytesPerPixel;
	Uint8* p = (Uint8*)entity->getSpriteSurface()->pixels + y * entity->getSpriteSurface()->pitch + x * bpp;
	Uint32 pixelColor;

	switch(bpp)
	{
		case(1):
			pixelColor = *p;
			break;
		case(2):
			pixelColor = *(Uint16*)p;
			break;
		case(3):
			if(SDL_BYTEORDER == SDL_BIG_ENDIAN)
				pixelColor = p[0] << 16 | p[1] << 8 | p[2];
			else
				pixelColor = p[0] | p[1] << 8 | p[2] << 16;
			break;
		case(4):
			pixelColor = *(Uint32*)p;
			break;
	}

	Uint8 red, green, blue, alpha;
	SDL_GetRGBA(pixelColor, entity->getSpriteSurface()->format, &red, &green, &blue, &alpha);

	return alpha > 200;
}
bool Spank::GetAlphaXY(Astroid* entity, int x, int y)
{
	int bpp = entity->getSpriteSurface()->format->BytesPerPixel;
	Uint8* p = (Uint8*)entity->getSpriteSurface()->pixels + y * entity->getSpriteSurface()->pitch + x * bpp;
	Uint32 pixelColor;

	switch(bpp)
	{
		case(1):
			pixelColor = *p;
			break;
		case(2):
			pixelColor = *(Uint16*)p;
			break;
		case(3):
			if(SDL_BYTEORDER == SDL_BIG_ENDIAN)
				pixelColor = p[0] << 16 | p[1] << 8 | p[2];
			else
				pixelColor = p[0] | p[1] << 8 | p[2] << 16;
			break;
		case(4):
			pixelColor = *(Uint32*)p;
			break;
	}

	Uint8 red, green, blue, alpha;
	SDL_GetRGBA(pixelColor, entity->getSpriteSurface()->format, &red, &green, &blue, &alpha);

	return alpha > 200;
}
/*END GETALPHAXY */

