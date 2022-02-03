// Name: Jacob Hawig
// WISC ID: 9078102226

# include <iostream>
using namespace std;

float AreaOfCircle(const float& radius){
	float PI = 3.1416;
	float area = PI * radius * radius;
	return area;
}

float AreaOfTriangle(const float& width, const float& height){
	float area = 0.5 * width * height;
	return area;
}

float AreaOfRectangle(const float& width, const float& height){
	float area = width * height;
	return area;
}

float VolumeOfSphere(const float& radius){
	float PI = 3.1416;
	float volume = 1.33333 * PI * radius * radius * radius;
	return volume;
}

float VolumeOfCone(const float& radius, const float& height){
	float volume = 0.3333333 * AreaOfCircle(radius) * height;
	return volume;
}

float VolumeOfBox(const float& width, const float& height, const float& length){
	float volume = width * height * length;
	return volume;
}

int PrintMainMenu(){
	// Welcome Menu
	int Menu_Choice;
	cout << "Welcome to Geometry Helper!" << endl;
	cout << "[1] Calculate a 2D Area" << endl;
	cout << "[2] Calculate a 3D Volume" << endl;
	cout << "[3] Exit program" << endl;
	cout << "Please enter a menu item: " << endl;
	cin >> Menu_Choice;
	while (Menu_Choice < 1 && Menu_Choice > 4) {
		cout << "Invalid input, please try again with one of the three options: " << endl;
		cin >> Menu_Choice;	
	}
	return Menu_Choice;
}

int Print2DMenu(){
	// 2D Menu
	int Menu_Choice;
	cout << "Choose an Area to Compute: " << endl;
	cout << "[1] Circle" << endl;
	cout << "[2] Triangle" << endl;
	cout << "[3] Rectangle" << endl;
	cout << "[4] Return to Main Menu" << endl;
	cout << "Please enter a menu item: " << endl;
	cin >> Menu_Choice;
	while (Menu_Choice < 1 && Menu_Choice > 5) {
		cout << "Invalid input, please try again with one of the four options: " << endl;
		cin >> Menu_Choice;	
	}
	return Menu_Choice;
}

 int Print3DMenu(){
	// 3D Menu
	int Menu_Choice;
	cout << "Choose a Volume to Compute: " << endl;
	cout << "[1] Sphere" << endl;
	cout << "[2] Cone" << endl;
	cout << "[3] Box" << endl;
	cout << "[4] Return to Main Menu" << endl;
	cout << "Please enter a menu item: " << endl;
	cin >> Menu_Choice;
	while (Menu_Choice < 1 && Menu_Choice > 5) {
		cout << "Invalid input, please try again with one of the four options: " << endl;
		cin >> Menu_Choice;	
	}
	return Menu_Choice;
 }