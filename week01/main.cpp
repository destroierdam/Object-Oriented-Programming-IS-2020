#include <iostream>
using std::cin;
using std::cout;
void hanoi(char firstPillar, char secondPillar, char thirdPillar, int disks) {
	if (disks == 1) {
		cout << "Move from pillar " << firstPillar << " to " << thirdPillar << '\n';
		return;
	}

	hanoi(firstPillar, thirdPillar, secondPillar, disks - 1);
	cout << "Move from pillar " << firstPillar << " to " << thirdPillar << "\n";
	hanoi(secondPillar, firstPillar, thirdPillar, disks - 1);
}

const int ROWS = 6, COLS = 6;

bool hasPath(int labyrinth[ROWS][COLS], int curRow, int curCol, int goalRow, int goalCol) {
	if (curRow < 0 || curRow >= ROWS || curCol < 0 || curCol >= COLS) {
		return false;
	}
	if (labyrinth[curRow][curCol] == 0) {
		return false;
	}
	if (curRow == goalRow && curCol == goalCol) {
		return true;
	}
	labyrinth[curRow][curCol] = 0;
	bool answer = hasPath(labyrinth, curRow - 1, curCol, goalRow, goalCol) ||
		hasPath(labyrinth, curRow, curCol + 1, goalRow, goalCol) ||
		hasPath(labyrinth, curRow + 1, curCol, goalRow, goalCol) ||
		hasPath(labyrinth, curRow, curCol - 1, goalRow, goalCol);
	labyrinth[curRow][curCol] = 1;
	return answer;
}

struct Coordinates {
	int row;
	int col;
};

bool hasPath(int labyrinth[ROWS][COLS], Coordinates current, Coordinates goal) {
	if (current.row < 0 || current.row >= ROWS || current.col < 0 || current.col >= COLS) {
		return false;
	}
	if (labyrinth[current.row][current.col] == 0) {
		return false;
	}
	if (current.row == goal.row && current.col == goal.col) {
		return true;
	}
	labyrinth[current.row][current.col] = 0;
	Coordinates up, down, left, right;
	up.row = current.row - 1;
	up.col = current.col;
	down.row = current.row + 1;
	down.col = current.col;
	left.row = current.row;
	left.col = current.col - 1;
	right.row = current.row;
	right.col = current.col + 1;

	bool answer = hasPath(labyrinth, up, goal) ||
		hasPath(labyrinth, down, goal) ||
		hasPath(labyrinth, left, goal) ||
		hasPath(labyrinth, right, goal);
	labyrinth[current.row][current.col] = 1;
	return answer;
}

int main()
{
	int labyrinth[6][6] = { {0, 1, 0, 1, 0, 0},
							{0, 1, 1, 1, 0, 0},
							{0, 1, 0, 0, 0, 1},
							{1, 0, 1, 1, 1, 1},
							{0, 0, 1, 1, 0, 1},
							{1, 0, 0, 1, 0, 1} };
	int startRow = 1, startCol = 1;
	int goalRow = 5, goalCol = 5;

	Coordinates start, goal;
	start.row = startRow;
	start.col = startCol;
	goal.row = goalRow;
	goal.col = goalCol;

	cout << hasPath(labyrinth, startRow, startCol, goalRow, goalCol);

}