#pragma once

#ifndef DEF_GRID
#define DEF_GRID

#include <list>
#include <iterator>

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>

#include "bloc.hpp"
#include "BlocMovable.hpp"

#include "Cell.hpp"

class Grid
{
public:
	Grid();
	~Grid();

	sf::Vector2f GetPositionByCell(int cellX, int cellY);

	void Update(sf::Clock& clock);
	void Draw(sf::RenderWindow& window);

	void AddBloc(Grid *grid, Bloc *bloc);
	bool checkHaveBloc(sf::Vector2i pos);
	bool CheckCollision(sf::Vector2i bodyCell);
	bool CheckCollisionLeft(sf::Vector2i bodyCell);
	bool CheckCollisionRight(sf::Vector2i bodyCell);
	void updateGrid(Bloc* bloc);
private:
	std::vector<int> searchLineWithFullCell();
	void destroyLine(std::vector<int> completedLine);

	std::vector<Bloc> m_blocs;
	Cell *m_grid[9][19] = { NULL };

	sf::Vector2f m_offset;
};

#endif