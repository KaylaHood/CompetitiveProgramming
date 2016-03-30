/*
 * RustlerBustler.cpp
 *
 *  Created on: Mar 2, 2016
 *      Author: khood
 */
#include <vector>
#include <iostream>
#include <algorithm>
#include <utility>

int mag;

struct Hexagon {
	int x;
	int y;
	Hexagon(int X,int Y):x(X),y(Y) {}
	std::vector<Hexagon> getAdj() {
		std::vector<Hexagon> ret;
		if(y % 2 == 0) {
			if(y == mag) {
				if(x == mag) {
					ret.push_back(Hexagon(x-1,y));
					ret.push_back(Hexagon(x-1,y-1));
					ret.push_back(Hexagon(x,y-1));
				}
				else if(x == -mag) {
					ret.push_back(Hexagon(x,y-1));
					ret.push_back(Hexagon(x+1,y));
				}
				else {
					ret.push_back(Hexagon(x-1,y));
					ret.push_back(Hexagon(x+1,y));
					ret.push_back(Hexagon(x-1,y-1));
					ret.push_back(Hexagon(x,y-1));
				}
			}
			else if(y == -mag) {
				if(x == mag) {
					ret.push_back(Hexagon(x-1,y));
					ret.push_back(Hexagon(x-1,y+1));
					ret.push_back(Hexagon(x,y+1));
				}
				else if(x == -mag) {
					ret.push_back(Hexagon(x,y+1));
					ret.push_back(Hexagon(x+1,y));
				}
				else {
					ret.push_back(Hexagon(x-1,y));
					ret.push_back(Hexagon(x+1,y));
					ret.push_back(Hexagon(x-1,y+1));
					ret.push_back(Hexagon(x,y+1));
				}
			}
			else if(x == mag) {
				ret.push_back(Hexagon(x,y+1));
				ret.push_back(Hexagon(x-1,y));
				ret.push_back(Hexagon(x-1,y+1));
				ret.push_back(Hexagon(x-1,y-1));
				ret.push_back(Hexagon(x,y-1));
			}
			else if(x == -mag) {
				ret.push_back(Hexagon(x,y+1));
				ret.push_back(Hexagon(x+1,y));
				ret.push_back(Hexagon(x,y-1));
			}
			else {
				ret.push_back(Hexagon(x,y));
				ret.push_back(Hexagon(x,y));
				ret.push_back(Hexagon(x,y));
				ret.push_back(Hexagon(x,y));
				ret.push_back(Hexagon(x,y));
				ret.push_back(Hexagon(x,y));
			}
		} else {
			if(y == mag) {
				if(x == mag) {
					ret.push_back(Hexagon(x-1,y));
					ret.push_back(Hexagon(x,y-1));
				}
				else if(x == -mag) {
					ret.push_back(Hexagon(x,y-1));
					ret.push_back(Hexagon(x+1,y-1));
					ret.push_back(Hexagon(x+1,y));
				}
				else {
					ret.push_back(Hexagon(x-1,y));
					ret.push_back(Hexagon(x+1,y));
					ret.push_back(Hexagon(x+1,y-1));
					ret.push_back(Hexagon(x,y-1));
				}
			}
			else if(y == -mag) {
				if(x == mag) {
					ret.push_back(Hexagon(x-1,y));
					ret.push_back(Hexagon(x,y+1));
				}
				else if(x == -mag) {
					ret.push_back(Hexagon(x,y+1));
					ret.push_back(Hexagon(x+1,y+1));
					ret.push_back(Hexagon(x+1,y));
				}
				else {
					ret.push_back(Hexagon(x-1,y));
					ret.push_back(Hexagon(x+1,y));
					ret.push_back(Hexagon(x+1,y+1));
					ret.push_back(Hexagon(x,y+1));
				}
			}
			else if(x == mag) {
				ret.push_back(Hexagon(x,y+1));
				ret.push_back(Hexagon(x-1,y));
				ret.push_back(Hexagon(x-1,y+1));
				ret.push_back(Hexagon(x-1,y-1));
				ret.push_back(Hexagon(x,y-1));
			}
			else if(x == -mag) {
				ret.push_back(Hexagon(x,y+1));
				ret.push_back(Hexagon(x+1,y));
				ret.push_back(Hexagon(x,y-1));
			}
		}
		return ret;
	}
	bool isAdj(const Hexagon& other) {
		std::vector<Hexagon> adjMat = this->getAdj();
		return (std::any_of(adjMat.begin(),adjMat.end(),([other](Hexagon& h) ->bool {return ((other.x == h.x) && (other.y == h.y));})));
	}
};

int main() {
	std::string input;
	std::cin >> input;

}


