#pragma once

class Entity
{
	int m_x, m_y;
	char m_glyph;

public:	
	Entity(int x, int y, char glyph) : m_x(x), m_y(y), m_glyph(glyph) {}
	int getX() { return m_x; }
	int getY() { return m_y; }
	char getGlyph() { return m_glyph; }

	void Move(int dx, int dy) { m_x += dx; m_y += dy; }
};

