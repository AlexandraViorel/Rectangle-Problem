// Problem-UMT-Software.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <set>
#include <string>

int countRectangles(std::vector<std::pair<int, int>> points)
{
	int rectangles = 0;
	// we put the points from the vector into a set for a efficient search of the points
	std::set<std::pair<int, int>> pointsSet;
	for (auto p : points) {
		pointsSet.insert(p);
	}
	// we take the points two by two
	for (int i = 0; i < points.size() - 1; i++) {
		for (int j = i + 1; j < points.size(); j++) {
			// we check if they can form a diagonal
			if (points[i].first != points[j].first && points[i].second != points[j].second) {
				// we search for the other two points of the rectangle and if they exist, we increase the result variable 
				if (pointsSet.count({ points[i].first, points[j].second }) && pointsSet.count({ points[j].first, points[i].second })) {
					rectangles++;
				}
			}
		}
	}
	// we divide the result by two, because by using this approach we find both diagonals of a rectangle and the same rectangle will
	// be stored two times in the answer
	return rectangles/2;
}

int main()
{
	std::vector<std::pair<int, int>> points1;
	points1.push_back({ 1, 1 });
	points1.push_back({ 1, 3 });
	points1.push_back({ 2, 1 });
	points1.push_back({ 2, 3 });
	points1.push_back({ 3, 1 });
	points1.push_back({ 3, 3 });
	std::cout << "From this vector of points, we can form: " + std::to_string(countRectangles(points1)) + " rectangles\n";

	std::vector<std::pair<int, int>> points2;
	points2.push_back({ 1, 1 });
	points2.push_back({ 1, 3 });
	points2.push_back({ 2, 1 });
	points2.push_back({ 3, 1 });
	points2.push_back({ 3, 3 });
	std::cout << "From this vector of points, we can form: " + std::to_string(countRectangles(points2)) + " rectangles\n";

	std::vector<std::pair<int, int>> points3;
	points3.push_back({ 1, 1 });
	points3.push_back({ 1, 2 });
	points3.push_back({ 2, 1 });
	points3.push_back({ 3, 3 });
	std::cout << "From this vector of points, we can form: " + std::to_string(countRectangles(points3)) + " rectangles\n";
	return 0;
}