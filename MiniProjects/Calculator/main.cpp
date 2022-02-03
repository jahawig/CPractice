// Name: Jacob Hawig
// WISC ID: 9078102226

# include <iostream>
# include "functions.h"

using namespace std;

int main(){
	int menu_choice;
	menu_choice = PrintMainMenu();
	switch(menu_choice){
		// 2D Calculations
		case 1:
			int twod_choice;
			twod_choice = Print2DMenu();
			switch(twod_choice){
				// Area of Circle
				case 1:
				{
					float radius;
					int exit_number;
					cout << "Please enter the radius of the circle: " << endl;
					cin >> radius;
					while(radius < 0){
						cout << "Radius has to be a positive value." << endl;
						cout << "Please reenter your radius value: " << endl;
						cin >> radius;
					}
					float area_circle;
					area_circle	= AreaOfCircle(radius);
					cout << "The area of the circle is: " << area_circle << endl;
					cout << "Enter any number to return to the Main Menu." << endl;
					cin >> exit_number;
					if(exit_number > -1 || exit_number < 10){
						main();
					}
					break;
				}
				// Area of Triangle
				case 2:
				{
					float width;
					float height;
					int exit_number;
					cout << "Please enter the width of the triangle: " << endl;
					cin >> width;
					while(width < 0){
						cout << "Width has to be a positive value." << endl;
						cout << "Please reenter your width value: " << endl;
						cin >> width;
					}
					cout << "Please enter the height of the triangle: " << endl;
					cin >> height;
					while(height < 0){
						cout << "Height has to be a positive value." << endl;
						cout << "Please reenter your height value: " << endl;
						cin >> height;
					}
					float area_triangle;
					area_triangle = AreaOfTriangle(width, height);
					cout << "The area of the triangle is: " << area_triangle << endl;
					cout << "Enter any number to return to the Main Menu." << endl;
					cin >> exit_number;
					if(exit_number > -1 || exit_number < 10){
						main();
					}
					break;
				}
				// Area of Rectangle
				case 3:
				{
					float width;
					float height;
					int exit_number;
					cout << "Please enter the width of the rectangle: " << endl;
					cin >> width;
					while(width < 0){
						cout << "Width has to be a positive value." << endl;
						cout << "Please reenter your width value: " << endl;
						cin >> width;
					}
					cout << "Please enter the height of the rectangle: " << endl;
					cin >> height;
					while(height < 0){
						cout << "Height has to be a positive value." << endl;
						cout << "Please reenter your height value: " << endl;
						cin >> height;
					}
					float area_rectangle;
					area_rectangle = AreaOfRectangle(width, height);
					cout << "The area of the rectangle is: " << area_rectangle << endl;
					cout << "Enter any number to return to the Main Menu." << endl;
					cin >> exit_number;
					if(exit_number > -1 || exit_number < 10){
						main();
					}
					break;
				}
				case 4:
				{
					main();
					break;
				}
			}
			break;
		// 3D Calculations
		case 2:
			int threed_choice;
			threed_choice = Print3DMenu();
			switch(threed_choice){
				// Volume of Sphere
				case 1:
				{
					float radius;
					int exit_number;
					cout << "Please enter the radius of the sphere: " << endl;
					cin >> radius;
					while(radius < 0){
						cout << "Radius has to be a positive value." << endl;
						cout << "Please reenter your radius value: " << endl;
						cin >> radius;
					}
					float vol_sphere;
					vol_sphere = VolumeOfSphere(radius);
					cout << "The volume of the sphere is: " << vol_sphere << endl;
					cout << "Enter any number to return to the Main Menu." << endl;
					cin >> exit_number;
					if(exit_number > -1 || exit_number < 10){
						main();
					}
					break;
				}
				case 2:
				{
					float radius;
					float height;
					int exit_number;
					// Volume of Cone
					cout << "Please enter the radius of the cone: " << endl;
					cin >> radius;
					while(radius < 0){
						cout << "Radius has to be a positive value." << endl;
						cout << "Please reenter your radius value: " << endl;
						cin >> radius;
					}
					cout << "Please enter the height of the cone: " << endl;
					cin >> height;
					while(height < 0){
						cout << "Height has to be a positive value." << endl;
						cout << "Please reenter your height value: " << endl;
						cin >> height;
					}
					float vol_cone;
					vol_cone = VolumeOfCone(radius, height);
					cout << "The volume of the cone is: " << vol_cone << endl;
					cout << "Enter any number to return to the Main Menu." << endl;
					cin >> exit_number;
					if(exit_number > -1 || exit_number < 10){
						main();
					}
					break;
				}
				case 3:
				{
					float width;
					float height;
					float length;
					int exit_number;
					// Volume of Box
					cout << "Please enter the width of the box: " << endl;
					cin >> width;
					while(width < 0){
						cout << "Width has to be a positive value." << endl;
						cout << "Please reenter your width value: " << endl;
						cin >> width;
					}
					cout << "Please enter the height of the box: " << endl;
					cin >> height;
					while(height < 0){
						cout << "Height has to be a positive value." << endl;
						cout << "Please reenter your height value: " << endl;
						cin >> height;
					}
					cout << "Please enter the length of the box: " << endl;
					cin >> length;
					while(length < 0){
						cout << "Length has to be a positive value." << endl;
						cout << "Please reenter your length value: " << endl;
						cin >> length;
					}
					float vol_box;
					vol_box = VolumeOfBox(width, height, length);
					cout << "The volume of the box is: " << vol_box << endl;
					cout << "Enter any number to return to the Main Menu." << endl;
					cin >> exit_number;
					if(exit_number > -1 || exit_number < 10){
						main();
					}
					break;
				}
				case 4:
				{
					// Return to Main Menu
					main();
					break;
				}
			}
			break;
		// Exiting Program
		case 3:
			break;
	}
	return 0;
}