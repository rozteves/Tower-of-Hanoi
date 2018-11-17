#pragma once
#include <string>
#include <iostream>
#include <iomanip>

class Tower
{
protected:
	int disk;
	char choice;
	char toRod;
	char fromRod;
	char grid[' '][3];
	std::string numSet;
	std::string towerA;
	std::string towerB;
	std::string towerC;
public:
	Tower();
	void initGrid();
	void stringtoGrid();
	void printGrid();
	void movDisk(char, char);
	void ldDisk(int, char, char, char); //recursion
	void displayTowers();
	void TowerofHanoi();
};
