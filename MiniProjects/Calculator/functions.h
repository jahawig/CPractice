#ifndef GEO_FUNCTIONS
#define GEO_FUNCTIONS
float AreaOfCircle(const float& radius);

float AreaOfTriangle(const float& width, const float& height);

float AreaOfRectangle(const float& width, const float& height);

float VolumeOfSphere(const float& radius);

float VolumeOfCone(const float& radius, const float& height);

float VolumeOfBox(const float& width, const float& height, const float& length);

int PrintMainMenu();

int Print2DMenu();

int Print3DMenu();
#endif
