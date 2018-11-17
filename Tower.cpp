#include "Tower.h"

Tower::Tower()
{

}

void Tower::initGrid()
{
	for (int i = 0; i < disk; i++) //rows
	{
		for (int t = 0; t < 3; t++) //columns
		{
			grid[i][t] = '.';
		}
	}
}

void Tower::stringtoGrid()
{
	int i = 0;
	for (int num = disk - 1; num >= 0; num--)
	{
		if ((towerA.size() > 0) && (i < towerA.size()))
		{
			grid[num][0] = towerA[i];
		}
		if ((towerB.size() > 0) && (i < towerB.size()))
		{
			grid[num][1] = towerB[i];
		}
		if ((towerC.size() > 0) && (i < towerC.size()))
		{
			grid[num][2] = towerC[i];
		}
		i++;
	}
}

void Tower::printGrid()
{
	for (int i = 0; i < disk; i++)
	{
		for (int t = 0; t < 3; t++)
		{
			std::cout << std::setw(7) << grid[i][t];
		}
		std::cout << "\n\n";
	}
	std::cout << "------A------B------C------\n\n\n";
}

void Tower::movDisk(char fromRod, char toRod)
{

	if ((fromRod == 'A') && (toRod == 'B'))
	{
		towerB.push_back(towerA[towerA.size() - 1]);
		towerA.pop_back();
	}
	if ((fromRod == 'A') && (toRod == 'C'))
	{
		towerC.push_back(towerA[towerA.size() - 1]);
		towerA.pop_back();
	}
	if ((fromRod == 'B') && (toRod == 'A'))
	{
		towerA.push_back(towerB[towerB.size() - 1]);
		towerB.pop_back();
	}
	if ((fromRod == 'B') && (toRod == 'C'))
	{
		towerC.push_back(towerB[towerB.size() - 1]);
		towerB.pop_back();
	}
	if ((fromRod == 'C') && (toRod == 'A'))
	{
		towerA.push_back(towerC[towerC.size() - 1]);
		towerC.pop_back();
	}
	if ((fromRod == 'C') && (toRod == 'B'))
	{
		towerB.push_back(towerC[towerC.size() - 1]);
		towerC.pop_back();
	}
}

void Tower::ldDisk(int disk, char fromRod, char toRod, char spare)
{

	if (disk == 0)
	{
		movDisk(fromRod, toRod);
		displayTowers();
	}
	else
	{
		ldDisk((disk - 1), fromRod, spare, toRod);
		if ((towerB == numSet) || (towerC == numSet))
		{
			return;
		}
		movDisk(fromRod, toRod);
		displayTowers();
		ldDisk((disk - 1), spare, toRod, fromRod);
	}
}

void Tower::displayTowers()
{
	initGrid();
	stringtoGrid();
	printGrid();
}

void Tower::TowerofHanoi()
{
	do
	{
		std::cout << "Enter the amount of disks: ";
		std::cin >> disk;

		displayTowers();

		std::cout << "Type number set from highest number to 1: ";
		std::cin >> numSet;

		towerA = numSet;

		std::cout << "\nType 'b' to move disks to Tower B." << std::endl;
		std::cout << "Type 'c' to move disks to Tower C." << std::endl;
		std::cin >> choice;

		while ((choice != 'b') && (choice != 'c'))
		{
			std::cout << "\n\nThat Tower does not exist" << std::endl;
			std::cout << "Type 'b' to move disks to Tower B." << std::endl;
			std::cout << "Type 'c' to move disks to Tower C." << std::endl;
			std::cin >> choice;
			std::cout << "\n\n";
		}

		if (choice == 'b')
		{
			ldDisk(disk, 'A', 'B', 'C');
		}
		if (choice == 'c')
		{
			ldDisk(disk, 'A', 'B', 'C');
		}

		std::cout << "Run again? y/n: ";
		std::cin >> choice;
	} while (choice != 'n');
}
