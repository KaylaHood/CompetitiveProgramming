#include <iostream>
#include <string>
#include <vector>
#include <cmath>

void split(const std::string& s,char delim,std::vector<std::string>& v) {
  auto i = 0;
  auto pos = s.find(delim);
  while (pos != std::string::npos) {
    v.push_back(s.substr(i, pos-i));
    i = ++pos;
    pos = s.find(delim, pos);

    if (pos == std::string::npos)
      v.push_back(s.substr(i, s.length()));
  }
}

int main() {
	std::string input;
	std::getline(std::cin,input);
	std::vector<std::string> inputStr;
	split(input,' ',inputStr);
	int pos = std::stoi(inputStr[1]);
	int dist = std::stoi(inputStr[2]);
	int total = std::stoi(inputStr[0]);
	if(std::abs(dist) > total) {
		dist = dist%total;
	}
	int ret = pos + dist;
	if(ret < 1) ret += total;
	else if(ret > total) ret -= total;
	std::cout << ret << "\n";
	return 0;
}
