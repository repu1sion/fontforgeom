#ifdef __cplusplus
extern "C" 
{
#endif

#include "splinefont.h"

#if 0
typedef struct basepoint {
    real x;
    real y;
} BasePointGeom;

typedef struct splinepoint {
    BasePoint me;		//x and y coords are here
    BasePoint nextcp;		/* control point */
    BasePoint prevcp;		/* control point */
    unsigned int nonextcp:1;
    unsigned int noprevcp:1;
    unsigned int nextcpdef:1;
    unsigned int prevcpdef:1;
    unsigned int selected:1;	/* for UI */
    unsigned int nextcpselected: 2; /* Is the next BCP selected */
    unsigned int prevcpselected: 2; /* Is the prev BCP selected */
    unsigned int pointtype:2;
    unsigned int isintersection: 1;
    unsigned int flexy: 1;	/* When "freetype_markup" is on in charview.c:DrawPoint */
    unsigned int flexx: 1;	/* flexy means select nextcp, and flexx means draw circle around nextcp */
    unsigned int roundx: 1;	/* For true type hinting */
    unsigned int roundy: 1;	/* For true type hinting */
    unsigned int dontinterpolate: 1;	/* in ttf, don't imply point by interpolating between cps */
    unsigned int ticked: 1;
    unsigned int watched: 1;
	/* 1 bits left... */
    uint16 ptindex;		/* Temporary value used by metafont routine */
    uint16 ttfindex;		/* Truetype point index */
	/* Special values 0xffff => point implied by averaging control points */
	/*		  0xfffe => point created with no real number yet */
	/* (or perhaps point in context where no number is possible as in a glyph with points & refs) */
    uint16 nextcpindex;		/* Truetype point index */
    struct spline *next;
    struct spline *prev;
    HintMask *hintmask;
	char* name;
} SplinePointGeom;

typedef struct splinepointlist {
    SplinePoint *first, *last;
    struct splinepointlist *next;
    spiro_cp *spiros;
    uint16 spiro_cnt, spiro_max;
	/* These could be bit fields, but bytes are easier to access and we */
	/*  don't need the space (yet) */
    uint8 ticked;
    uint8 beziers_need_optimizer;	/* If the spiros have changed in spiro mode, then reverting to bezier mode might, someday, run a simplifier */
    uint8 is_clip_path;			/* In type3/svg fonts */
    int start_offset; // This indicates which point is the canonical first for purposes of outputting to U. F. O..
    char *contour_name;
} SplinePointList, SplineSetGeom;
#endif

	SplineSet* FindStrokePointsCircleGeom(SplineSet *ss/*, StrokeContext *c*/);

#ifdef __cplusplus
}
#endif
