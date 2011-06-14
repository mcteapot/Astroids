/*
COLLISION DETECTION CLASS
*/

#ifndef SPANK_H
#define SPANK_H

#include "Sprite.h"
#include "Ship.h"
#include "Astroid.h"

#define Maximum(a, b) ((a > b) ? a : b)
#define Minimum(a, b) ((a < b) ? a : b)

struct theVector
{
	float X;
	float Y;

	theVector()
	{
		X = 0.0f;
		Y = 0.0f;
	}
};
/* FIRST THING TO DO... Create instance, Spank damage;
    SECOND THING TO DO... CALL CheckCollision(A,B);
    NOTE: CHECK COLLISION RETURNS A BOOL.
            True == hit, False == no hit.
*/
class Spank //: public Sprite
{
    public:
        Spank();
        void setValues(Sprite *spriteA, Sprite *spriteB);
        void setValues(Ship *shipA, Astroid *astroidB);
        virtual ~Spank();

        int tilesX;
		int tilesY;
		int tileWidthA, tileWidthB;
		int tileHeightA, tileHeightB;

    public:
		theVector positionA, positionB;
		theVector originA, originB;

    public:
        void GetBounds();//SDL_Rect &boundsA, SDL_Rect &boundsB);
		SDL_Rect NormalizeBounds(const SDL_Rect& rect, bool isObjectA);

		SDL_Rect Intersection(const SDL_Rect& boundA, const SDL_Rect& boundB);

		bool CheckCollision(Sprite* spriteA, Sprite* spriteB);
		bool CheckCollision(Ship* shipA, Astroid* astroidB);
		bool CheckCollision(Astroid* astroidB, Ship* shipA);

		bool GetAlphaXY(Sprite* entity, int x, int y);
		bool GetAlphaXY(Ship* entity, int x, int y);
		bool GetAlphaXY(Astroid* entity, int x, int y);

    protected:
        //
    private:
        //SDL_Surface *screen;
        SDL_Rect boundsA, boundsB;
};

#endif // OBJECT_H
