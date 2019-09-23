typedef struct { double r; double theta; } polar;
typedef struct { double x; double y; } point;

point pol_cart (point, polar);
polar cart_pol (point, polar);
