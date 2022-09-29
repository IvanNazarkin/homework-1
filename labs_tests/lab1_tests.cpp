#include <gtest/gtest.h>
#include "lab1/lab1_functions.h"
#include <limits>

TEST(PointTest, CreateTest) {
	Point p;
	EXPECT_EQ(0, p.X());
	EXPECT_EQ(0, p.Y());
	p = Point(2, 3);
	EXPECT_EQ(2, p.X());
	EXPECT_EQ(3, p.Y());
	Point copy{ p };
	EXPECT_EQ(2, copy.X());
	EXPECT_EQ(3, copy.Y());
}

TEST(PointTest, XYTest) {
	Point p(1, 2);
	EXPECT_EQ(1, p.X());
	EXPECT_EQ(2, p.Y());
	p.X(std::numeric_limits<double>::max());
	p.Y(std::numeric_limits<double>::min());
	EXPECT_EQ(std::numeric_limits<double>::max(), p.X());
	EXPECT_EQ(std::numeric_limits<double>::min(), p.Y());
	p.X(-1);
	p.Y(-3);
	EXPECT_EQ(-1, p.X());
	EXPECT_EQ(-3, p.Y());
}

TEST(BrokeLineTest, CreateTest) {
	BrokeLine b;
	EXPECT_EQ(nullptr, b.getPoints());
	EXPECT_EQ(0, b.Size());
	b = BrokeLine(new Point[1]{ Point(1,2) }, 1);
	EXPECT_EQ(1, b.get(0).X());
	EXPECT_EQ(2, b.get(0).Y());
	EXPECT_EQ(1, b.Size());
	EXPECT_EQ(0, b.P());
	b = BrokeLine(new Point[3]{ Point(0,0),Point(1,1),Point(2,0) }, 3);
	BrokeLine copy{ b };
	EXPECT_EQ(0, copy.get(0).X());
	EXPECT_EQ(1, copy.get(1).Y());
	EXPECT_EQ(2, copy.get(2).X());
	EXPECT_EQ(3, copy.Size());
	EXPECT_NEAR(2 * sqrt(2), copy.P(), 0.0001);
}

TEST(ClosedLineTest, CreateTest) {
	ClosedLine c;
	EXPECT_EQ(nullptr, c.getPoints());
	EXPECT_EQ(0, c.Size());
	c = ClosedLine(new Point[1]{ Point(1,2) }, 1);
	EXPECT_EQ(1, c.get(0).X());
	EXPECT_EQ(2, c.get(0).Y());
	EXPECT_EQ(1, c.Size());
	EXPECT_EQ(0, c.P());
	c = ClosedLine(new Point[3]{ Point(0,0),Point(1,1),Point(2,0) }, 3);
	ClosedLine copy{ c };
	EXPECT_EQ(0, copy.get(0).X());
	EXPECT_EQ(1, copy.get(1).Y());
	EXPECT_EQ(2, copy.get(2).X());
	EXPECT_EQ(3, copy.Size());
	EXPECT_NEAR(2 * (sqrt(2) + 1), copy.P(), 0.0001);
}

TEST(PolygonTest, CreateTest) {
	Polygon p;
	EXPECT_EQ(nullptr, p.getPoints());
	EXPECT_EQ(0, p.Size());
	p = Polygon(new Point[1]{ Point(1,2) }, 1);
	EXPECT_EQ(1, p.get(0).X());
	EXPECT_EQ(2, p.get(0).Y());
	EXPECT_EQ(1, p.Size());
	EXPECT_EQ(0, p.P());
	EXPECT_EQ(0, p.S());
	p = Polygon(new Point[4]{ Point(-1,-2),Point(10,12),Point(15,3),Point(5,-10) }, 4);
	Polygon copy{ p };
	EXPECT_EQ(-1, copy.get(0).X());
	EXPECT_EQ(12, copy.get(1).Y());
	EXPECT_EQ(15, copy.get(2).X());
	EXPECT_EQ(-10, copy.get(3).Y());
	EXPECT_EQ(4, copy.Size());
	double len = Point::dist(p.get(0), p.get(1)) +
		Point::dist(p.get(1), p.get(2)) +
		Point::dist(p.get(2), p.get(3)) +
		Point::dist(p.get(3), p.get(0));
	EXPECT_NEAR(len, copy.P(), 0.0001);
	EXPECT_NEAR(163.5, copy.S(), 0.0001);
}

TEST(TriangleTest, CreateTest) {
	Triangle t;
	EXPECT_EQ(nullptr, t.getPoints());
	EXPECT_EQ(0, t.Size());
	t = Triangle(new Point[1]{ Point(1,2) }, 1);
	EXPECT_EQ(1, t.get(0).X());
	EXPECT_EQ(2, t.get(0).Y());
	EXPECT_EQ(1, t.Size());
	EXPECT_EQ(0, t.P());
	EXPECT_EQ(0, t.S());
	t = Triangle(new Point[4]{ Point(-1,-2),Point(10,12),Point(15,3),Point(5,-10) }, 4);
	Triangle copy{ t };
	EXPECT_EQ(-1, copy.get(0).X());
	EXPECT_EQ(12, copy.get(1).Y());
	EXPECT_EQ(15, copy.get(2).X());
	EXPECT_EQ(-10, copy.get(3).Y());
	EXPECT_EQ(4, copy.Size());
	double len = Point::dist(t.get(0), t.get(1)) +
		Point::dist(t.get(1), t.get(2)) +
		Point::dist(t.get(2), t.get(3)) +
		Point::dist(t.get(3), t.get(0));
	EXPECT_NEAR(len, copy.P(), 0.0001);
	EXPECT_NEAR(0, copy.S(), 0.0001);
	t = Triangle(new Point[3]{ Point(0,0),Point(2,0),Point(2,0) }, 3);
	EXPECT_NEAR(0, t.S(), 0.0001);
	t = Triangle(new Point[3]{ Point(1,3),Point(2,-5),Point(-8,4) }, 3);
	EXPECT_NEAR(35.5, t.S(), 0.0001);
}

TEST(TrapezoidTest, CreateTest) {
	Trapezoid t;
	EXPECT_EQ(nullptr, t.getPoints());
	EXPECT_EQ(0, t.Size());
	t = Trapezoid(new Point[1]{ Point(1,2) }, 1);
	EXPECT_EQ(1, t.get(0).X());
	EXPECT_EQ(2, t.get(0).Y());
	EXPECT_EQ(1, t.Size());
	EXPECT_EQ(0, t.P());
	EXPECT_EQ(0, t.S());
	t = Trapezoid(new Point[4]{ Point(-1,-2),Point(10,12),Point(15,3),Point(5,-10) }, 4);
	Trapezoid copy{ t };
	EXPECT_EQ(-1, copy.get(0).X());
	EXPECT_EQ(12, copy.get(1).Y());
	EXPECT_EQ(15, copy.get(2).X());
	EXPECT_EQ(-10, copy.get(3).Y());
	EXPECT_EQ(4, copy.Size());
	double len = Point::dist(t.get(0), t.get(1)) +
		Point::dist(t.get(1), t.get(2)) +
		Point::dist(t.get(2), t.get(3)) +
		Point::dist(t.get(3), t.get(0));
	EXPECT_NEAR(len, copy.P(), 0.0001);
	EXPECT_NEAR(0, copy.S(), 0.0001);
	t = Trapezoid(new Point[3]{ Point(1,3),Point(2,-5),Point(-8,4) }, 3);
	EXPECT_NEAR(0, t.S(), 0.0001);
	t = Trapezoid(new Point[4]{ Point(0,0),Point(2,5),Point(4,5),Point(6,0) }, 4);
	EXPECT_NEAR(20, t.S(), 0.0001);
}

TEST(CPolygonTest, CreateTest) {
	CPolygon p;
	EXPECT_EQ(nullptr, p.getPoints());
	EXPECT_EQ(0, p.Size());
	p = CPolygon(new Point[1]{ Point(1,2) }, 1);
	EXPECT_EQ(1, p.get(0).X());
	EXPECT_EQ(2, p.get(0).Y());
	EXPECT_EQ(1, p.Size());
	EXPECT_EQ(0, p.P());
	EXPECT_EQ(0, p.S());
	p = CPolygon(new Point[4]{ Point(-1,-2),Point(10,12),Point(15,3),Point(5,-10) }, 4);
	CPolygon copy{ p };
	EXPECT_EQ(-1, copy.get(0).X());
	EXPECT_EQ(12, copy.get(1).Y());
	EXPECT_EQ(15, copy.get(2).X());
	EXPECT_EQ(-10, copy.get(3).Y());
	EXPECT_EQ(4, copy.Size());
	double len = Point::dist(p.get(0), p.get(1)) +
		Point::dist(p.get(1), p.get(2)) +
		Point::dist(p.get(2), p.get(3)) +
		Point::dist(p.get(3), p.get(0));
	EXPECT_NEAR(len, copy.P(), 0.0001);
	EXPECT_NEAR(0, copy.S(), 0.0001);
	p = CPolygon(new Point[4]{ Point(0,0),Point(0,1),Point(1,1),Point(1,0) }, 4);
	EXPECT_NEAR(1, p.S(), 0.0001);
	p = CPolygon(new Point[3]{ Point(0,0),Point(0.5,sqrt(3) / 2),Point(1,0) }, 3);
	EXPECT_NEAR(0.433, p.S(), 0.0001);
}