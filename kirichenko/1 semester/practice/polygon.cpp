#include <iostream>
#include <list>
#include <utility>
#include <iterator>
#include <cmath>

/*
*  TODO:
*    ✓ Создать пустую область
*    ✓ Создание односвязной области по заданным массивам координат вершин
*    ✓ Изменение координат отдельно взятой точки вершины
*    ✓ Добавление новой точки на ребро
*    ✓ Удаление вершины (замена двух смежных ребер на одно)
*    ✓ Положение данной точки относительно области (внутри, вне, на границе)
*    ✓ Получить количество связных компонент и количество вершин в них
*/

typedef std::pair<float, float> Point;
typedef std::pair<Point, Point> Edge;

class Component {
	std::list<Point> points;
public:
	void add_point(float x, float y);
	void add_point(Point *pts, int size);
	void remove_point(float x, float y);
	void remove_point(int num);
	void move_point(int num, float x2, float y2);
	void move_point(float x1, float y1, float x2, float y2);
	void print_points();
	int count_points();
	int point_in_component(Point &a);
	int point_in_component(float x, float y);
	void add_point_to_edge(int edge, Point &p);
	void print_edges();
};

class PolygonArea {
	std::list<Component> components;
public:
	PolygonArea();
	PolygonArea(Point *points, int size);
	void add_component();
	void add_point(int component, float x, float y);
	void add_point(int component, Point *points, int size);
	void remove_point(int component, float x, float y);
	void remove_point(int component, int num);
	void move_point(int component, float x1, float y1, float x2, float y2);
	void move_point(int component, int num, float x2, float y2);
	void print_components();
	int point_in_component(int component, Point &a);
	void print_edges(int component);
	void add_point_to_edge(int component, int edge, Point &p);
	std::pair<int, int> count_all();
};

float length(Point &p0) {
	return std::sqrt(p0.first*p0.first + p0.second*p0.second);
}

// СЛЕВА, СПРАВА, ВПЕРЕДИ, ПОЗАДИ, МЕЖДУ, НАЧАЛО, КОНЕЦ
// 0,     1,      2,       3,      4,     5,      6
int classify(Point &comp, Point &p0, Point &p1) {
	Point a(p1.first - p0.first, p1.second - p0.second);
	Point b(comp.first - p0.first, comp.second - p0.second);
	float sa = a.first * b.second - b.first * a.second;
	if (sa > 0.0)
    	return 0;
	if (sa < 0.0)
		return 1;
	if ((a.first * b.first < 0.0) || (a.second * b.second < 0.0))
		return 3;
	if (length(a) < length(b))
		return 2;
	if (p0.first == comp.first && p0.second == comp.second)
		return 5;
	if (p1.first == comp.first && p1.second == comp.second)
		return 6;
	return 4;
};

int classify(Point &comp, Edge &e) {
	return classify(comp, e.first, e.second);
}

// ПЕРЕСЕКАЕТ, КАСАЕТСЯ, БЕЗРАЗЛИЧНО
// 0,          1,        2
int edgeType(Point &a, Edge &e) {
	Point v = e.first;
	Point w = e.second;
	switch (classify(a, e)) {
		case 0:
			return ((v.second < a.second) && (a.second <= w.second)) ? 0 : 2;
		case 1:
			return ((w.second < a.second) && (a.second <= v.second)) ? 0 : 2;
		case 4:
		case 5:
		case 6:
			return 1;
		default:
			return 2;
	}
}

// ВНУТРИ, ВНЕ, НА ГРАНИЦЕ
// 0,      1,   2
int Component::point_in_component(Point &a) {
	int parity = 0;
	for (auto it = points.begin(); ; ) {
		Edge e = Edge(*it, *(++it));
		if (it == points.end())
			e = Edge(points.back(), points.front());
		switch (edgeType(a, e)) {
			case 1:
				return 2;
			case 0:
				parity = 1 - parity;
		}
		if (it == points.end())
			break;
	}
	return (parity ? 0 : 1);
}

void Component::add_point(float x, float y) {
	points.push_back(std::make_pair(x, y));
}

void Component::add_point(Point *pts, int size) {
	for (int i = 0; i < size; i++) {
		points.push_back(pts[i]);
	}
}

void Component::remove_point(float x, float y) {
	points.remove(std::make_pair(x, y));
}

void Component::remove_point(int num) {
	auto it = points.begin();
	std::advance(it, num);
	points.erase(it);
}

void Component::move_point(int num, float x2, float y2) {
	auto it = points.begin();
	std::advance(it, num);
	it->first = x2;
	it->second = y2;
}

void Component::move_point(float x1, float y1, float x2, float y2) {
	auto it = points.begin();
	while (!(it->first == x1 && it->second == y1) && it != points.end()) it++;
	if (it == points.end()) return;
	it->first = x2;
	it->second = y2;
}

void Component::print_points() {
	if (points.empty()) std::cout << "Component is empty" << std::endl;
	else {
		int i = 0;
		for (auto pointIterator = points.begin(); pointIterator != points.end(); pointIterator++) {
			std::cout << i << ": ("<< pointIterator->first << ":" << pointIterator->second << ")" << std::endl;
			i++;
		}
		std::cout << std::endl;
	}
}

void Component::print_edges() {
	int i = 0;
	for (auto it = points.begin(); ; ) {
		Edge e = Edge(*it, *(++it));
		if (it == points.end())
			e = Edge(points.back(), points.front());

		std::cout << "Edge " << i++ << ": ("
				  << e.first.first << ":" << e.first.second << ") ("
				  << e.second.first << ":" << e.second.second << ")"
				  << std::endl;

		if (it == points.end())
			break;
	}
}

void Component::add_point_to_edge(int edge, Point &p) {
	auto it = points.begin();
	for (int i = 0; i < edge; i++) it++;
	it++;
	points.insert(it, p);
}

int Component::count_points() {
	return points.size();
}


PolygonArea::PolygonArea() {};
PolygonArea::PolygonArea(Point *points, int size) {
	add_component();
	for (int i = 0; i < size; i++) {
		add_point(0, points[i].first, points[i].second);
	}
}
void PolygonArea::add_component() {
	components.push_back(Component());
}

void PolygonArea::add_point(int component, float x, float y) {
	if (component < 0 || components.empty() || component >= components.size()) return;

	if (component == 0) components.front().add_point(x, y);
	else if (component == components.size() - 1) components.back().add_point(x, y);
	else {
		int i = 0;
		auto it = components.begin();
		while (i < component) it++;
		it->add_point(x, y);
	}
}

void PolygonArea::add_point(int component, Point *points, int size) {
	if (component < 0 || components.empty() || component >= components.size()) return;

	if (component == 0) components.front().add_point(points, size);
	else if (component == components.size() - 1) components.back().add_point(points, size);
	else {
		int i = 0;
		auto it = components.begin();
		while (i < component) it++;
		it->add_point(points, size);
	}
}

void PolygonArea::remove_point(int component, float x, float y) {
	if (component < 0 || components.empty() || component >= components.size()) return;

	if (component == 0) components.front().remove_point(x, y);
	else if (component == components.size() - 1) components.back().remove_point(x, y);
	else {
		int i = 0;
		auto it = components.begin();
		while (i < component) it++;
		it->remove_point(x, y);
	}
}

void PolygonArea::remove_point(int component, int num) {
	if (component < 0 || components.empty() || component >= components.size()) return;

	if (component == 0) components.front().remove_point(num);
	else if (component == components.size() - 1) components.back().remove_point(num);
	else {
		int i = 0;
		auto it = components.begin();
		while (i < component) it++;
		it->remove_point(num);
	}
}

void PolygonArea::move_point(int component, float x1, float y1, float x2, float y2) {
	if (component < 0 || components.empty() || component >= components.size()) return;

	if (component == 0) components.front().move_point(x1, y1, x2, y2);
	else if (component == components.size() - 1) components.back().move_point(x1, y1, x2, y2);
	else {
		int i = 0;
		auto it = components.begin();
		while (i < component) it++;
		it->move_point(x1, y1, x2, y2);
	}
}

void PolygonArea::move_point(int component, int num, float x2, float y2) {
	if (component < 0 || components.empty() || component >= components.size()) return;

	if (component == 0) components.front().move_point(num, x2, y2);
	else if (component == components.size() - 1) components.back().move_point(num, x2, y2);
	else {
		int i = 0;
		auto it = components.begin();
		while (i < component) it++;
		it->move_point(num, x2, y2);
	}
}

void PolygonArea::print_components() {
	if (components.empty()) std::cout << "Area is empty" << std::endl;
	else {
		int i = 0;
		for (auto componentIterator = components.begin(); componentIterator != components.end(); componentIterator++) {
			std::cout << "Component " << i++ << ":\n";
			componentIterator->print_points();
		}
		std::cout << std::endl;
	}
}

int PolygonArea::point_in_component(int component, Point &a) {
	if (component < 0 || components.empty() || component >= components.size()) return -1;
	int result;
	if (component == 0) result = components.front().point_in_component(a);
	else if (component == components.size() - 1) result = components.back().point_in_component(a);
	else {
		int i = 0;
		auto it = components.begin();
		while (i < component) it++;
		result = it->point_in_component(a);
	}

	return result;
}

void PolygonArea::print_edges(int component) {
	if (component < 0 || components.empty() || component >= components.size()) return;
	if (component == 0) components.front().print_edges();
	else if (component == components.size() - 1) components.back().print_edges();
	else {
		int i = 0;
		auto it = components.begin();
		while (i < component) it++;
		it->print_edges();
	}
}

void PolygonArea::add_point_to_edge(int component, int edge, Point &p) {
	if (component < 0 || components.empty() || component >= components.size()) return;
	if (component == 0) components.front().add_point_to_edge(edge, p);
	else if (component == components.size() - 1) components.back().add_point_to_edge(edge, p);
	else {
		int i = 0;
		auto it = components.begin();
		while (i < component) it++;
		it->add_point_to_edge(edge, p);
	}
}

std::pair<int, int> PolygonArea::count_all() {
	int comp_count = components.size();
	int points_count = 0;
	for (auto componentIterator = components.begin(); componentIterator != components.end(); componentIterator++) {
		points_count += componentIterator->count_points();
	}
	return std::make_pair(comp_count, points_count);
}

// ВНУТРИ, ВНЕ, НА ГРАНИЦЕ
// 0,      1,   2
int main() {
	PolygonArea area = PolygonArea();
	area.add_component();
	area.add_point(0, 2.0, 2.0);
	area.add_point(0, 3.0, 5.0);
	area.add_point(0, 4.0, 3.0);
	area.add_point(0, 6.0, 5.0);
	area.add_point(0, 6.0, 1.0);
	area.print_components();
	Point p = Point(4.0, 1.5);
	//std::cout << area.point_in_component(0, p) << std::endl;
	area.print_edges(0);
	area.add_point_to_edge(0, 3, p);
	area.print_components();
	area.remove_point(0, p.first, p.second);
	area.print_components();
	area.add_component();
	std::cout << area.count_all().first << ":" << area.count_all().second;
	//area.move_point(0, 3.0, 5.0, 3.3, 5.5);
	//area.print_components();
	/*
	PolygonArea area = PolygonArea();
	area.add_component(); 
	area.print_components();

	int size;
	std::cin >> size;
	Point *points = new Point[size];
	for (int i = 0; i < size; i++) {
		float x, y;
		std::cin >> x >> y;
		points[i] = std::make_pair(x, y);
	}
	area.add_point(0, points, size);
	area.print_components();

	area.move_point(0, 1.0, 1.0, 2.0, 2.0);
	area.print_components();
	*/

	return 0;
}