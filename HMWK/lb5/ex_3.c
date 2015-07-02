typedef struct{
	double x;
	double y;
}Point;

typedef struct{
	Point p[3];
}Triangle;

typedef struct{
	Point p;
	double a;
	double b;
}Rectangle;

typedef struct{
	Point p;
	double l;
}Square;

typedef struct{
	Point o;
	double r;
}Circle;