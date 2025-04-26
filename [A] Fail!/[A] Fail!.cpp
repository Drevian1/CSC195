#include <iostream>
#include <vector>
using namespace std;
class Shape {
public:
	Shape() {}
	~Shape() {}
	virtual float Area() = 0;
};
class Circle : public Shape {
public:
	Circle(float r) { m_radius = r; }
	~Circle() {}
	
	float Area() override {
		return 3.14f * m_radius * m_radius;
	}
	void SetRadius(float radius) const { radius = radius; }
	float GetRadius() { return m_radius; }
private:
	float m_radius;
};
class Rectangle : public Shape {
public:
	Rectangle(float w, float h) {
		m_width = w;
		m_height = h;
	}
	
	float Area() override {
		return m_width * m_height;
	}
private:
	float m_width;
	float m_height;
};
int main() {
	vector<Shape*> shapes;
	Circle* c = new Circle(1.0f);
	c->SetRadius(3.0f);
	Rectangle* r = new Rectangle(4.0f, 5.0f);
		
	shapes.push_back(c);
	shapes.push_back(r);
	
	for (int i = 0; i < shapes.size(); i++)
	{
		cout << "Area: " << shapes[i]->Area() << endl;
		// TODO: If shape is a circle, print radius
	}
	// FIXME: Getting memory leak! Delete all shapes.
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
