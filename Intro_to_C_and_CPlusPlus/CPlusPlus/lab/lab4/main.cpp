/* Eric Paulz
 * epaulz
 * CPSC 1021-004
 * Lab #4
 * TA: Nick Glyder
 */

#include "functions.h"

int main(){
	point_t plane_dimensions, plane;
	point_t tri_points[3];
	double i, j;
	int result;

	// take input from user
	std::cout << "Enter the dimensions of the plane (width then height):\n";
	std::cin >> plane_dimensions.x >> plane_dimensions.y;

	std::cout << "Enter point 1 (x then y):\n";
	std::cin >> tri_points[0].x >> tri_points[0].y;

	std::cout << "Enter point 2 (x then y):\n";
	std::cin >> tri_points[1].x >> tri_points[1].y;

	std::cout << "Enter point 3 (x then y):\n";
	std::cin >> tri_points[2].x >> tri_points[2].y;

	// loop through plane and print each point that lies within the given triangle
	std::cout << std::endl << "HIT POINTS:\n";
	for(i = 0; i < plane_dimensions.x; i++){
		for(j = 0; j < plane_dimensions.y; j++){
			point_t *test_points = &plane;
			test_points->x = i;
			test_points->y = j;

			result = checkPoint(tri_points, test_points);
			if(result == 1){
				std::cout << std::fixed << std::setprecision(1) << i << ", " << j << std::endl;
			}
		}
	}

	return 0;
}
