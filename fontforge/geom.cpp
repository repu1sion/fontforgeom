//lib2geom headers
#include <2geom/d2.h>
#include <2geom/sbasis.h>
#include <2geom/sbasis-2d.h>
#include <2geom/sbasis-geometric.h>
#include <2geom/sbasis-math.h>
#include <2geom/bezier-to-sbasis.h>
#include <2geom/sbasis-to-bezier.h>
#include <2geom/path-intersection.h>
#include <2geom/bezier-curve.h>
#include <2geom/transforms.h>
#include <2geom/angle.h>

//fontforge headers
extern "C" 
{
#include <fontforge-config.h>
#include "splineorder2.h"
}

//own header
#include "geom.h"

//if we need to convert our SplineSet to CubicBezier
//SplineSet *SplineSetsConvertOrder(SplineSet *ss, int to_order2)

extern "C" 
{
//repu1sion: circlepen
SplineSet* FindStrokePointsCircleGeom(SplineSet *ss/*, StrokeContext *c*/) 
{
    Spline *s, *s_cub = NULL, *first = NULL;
    SplineSet *rs = NULL, *ss_cub = NULL;
    static int spline_num = 0;

    printf("%s() called\n", __func__);

    //convert our Splineset from quadratic to qubic Bezier
    ss_cub = SplineSetsConvertOrder(ss, false);
    if (ss_cub)
    {
        printf("%s(): converted SplineSet successfully\n", __func__);
    }

    for (s=ss->first->next, s_cub=ss_cub->first->next; s!=NULL && s!=first; s=s->to->next, s_cub=s_cub->to->next)
    {
    	printf("%s() new spline: %d\n", __func__, ++spline_num);
	printf("FROM: me.x: %f, me.y: %f , prevcp.x: %f, prevcp.y: %f, nextcp.x: %f, nextcp.y: %f\n",  
	    s->from->me.x, s->from->me.y, s->from->prevcp.x, s->from->prevcp.y, s->from->nextcp.x, s->from->nextcp.y);
	printf("TO: me.x: %f, me.y: %f , prevcp.x: %f, prevcp.y: %f, nextcp.x: %f, nextcp.y: %f\n",  
	    s->to->me.x, s->to->me.y, s->to->prevcp.x, s->to->prevcp.y, s->to->nextcp.x, s->to->nextcp.y);
	//converted spline
	printf("CUB FROM: me.x: %f, me.y: %f , prevcp.x: %f, prevcp.y: %f, nextcp.x: %f, nextcp.y: %f\n",  
	    s_cub->from->me.x, s_cub->from->me.y, s_cub->from->prevcp.x, s_cub->from->prevcp.y, 
		s_cub->from->nextcp.x, s_cub->from->nextcp.y);
	printf("CUB TO: me.x: %f, me.y: %f , prevcp.x: %f, prevcp.y: %f, nextcp.x: %f, nextcp.y: %f\n",  
	    s_cub->to->me.x, s_cub->to->me.y, s_cub->to->prevcp.x, s_cub->to->prevcp.y, 
		s_cub->to->nextcp.x, s_cub->to->nextcp.y);
	printf("------------------------------------------------------------------------\n");

        if (!first)
	   first = s;

    }

    return rs;
}

}
