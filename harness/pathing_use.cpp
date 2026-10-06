// Emit header-inline pathing functions until their game callers are reconstructed.
#include "../src/pathing/cartographer2d.h"
#include "../src/pathing/bresenham2d.h"

void harness_pathing()
{
	Point a(1,2), b(3,4);
	Bresenham2DStepper s0;
	Bresenham2DStepper s1(1,2,3,4);
	s1.init(a,b);
	s1.next(a);
	s1.getDelta(b);
	Bresenham2DStepperSubcell s2;
	Bresenham2DStepper *s3 = new Bresenham2DStepperSubcell(a,b,a,b,4);
	delete s3;
	Bresenham2DStepper *s4 = new Bresenham2DStepper(1,2,3,4);
	delete s4;
}
