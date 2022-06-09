#include <iostream>
#include <vector>
#include <cstddef>  // size_t
#include <cstdlib>

class Coord {
  private:
    int x, y;
  public:
    Coord (int i1, int i2) : x(i1), y(i2) {
    }
    friend Coord operator- (Coord const& c1, Coord const& c2) {
        return Coord(c1.x-c2.x, c1.y-c2.y);
    }
    Coord abs() {
        return Coord(std::abs(x),std::abs(y));
    }
};

// common abstract base class GeoObj for geometric objects
class GeoObj {
 public:
  // draw geometric object:
  virtual void draw() const = 0;
  // return center of gravity of geometric object:
  virtual Coord center_of_gravity() const = 0;
  //...
  virtual ~GeoObj() = default;
};

// concrete geometric object class Circle
// - derived from GeoObj
class Circle : public GeoObj {
 public:
  virtual void draw() const override;
  virtual Coord center_of_gravity() const override;
  //...
};

// concrete geometric object class Line
// - derived from GeoObj
class Line : public GeoObj {
 public:
  virtual void draw() const override;
  virtual Coord center_of_gravity() const override;
  //...
};
//...

// draw any GeoObj
void myDraw(GeoObj const& obj) {
  obj.draw();  // call draw() according to type of object
}

// compute distance of center of gravity between two GeoObjs
Coord distance(GeoObj const& x1, GeoObj const& x2) {
  Coord c = x1.center_of_gravity() - x2.center_of_gravity();
  return c.abs();  // return coordinates as absolute values
}

// draw heterogeneous collection of GeoObjs
void drawElems(std::vector<GeoObj*> const& elems) {
  for (std::size_type i = 0; i < elems.size(); ++i) {
    elems[i]->draw();  // call draw() according to type of element
  }
}

int main() {
  Line l;
  Circle c, c1, c2;

  myDraw(l);  // myDraw(GeoObj\&) => Line::draw()
  myDraw(c);  // myDraw(GeoObj\&) => Circle::draw()

  distance(c1, c2);  // distance(GeoObj\&,GeoObj\&)
  distance(l, c);    // distance(GeoObj\&,GeoObj\&)

  std::vector<GeoObj*> coll;  // heterogeneous collection
  coll.push_back(&l);         // insert line
  coll.push_back(&c);         // insert circle
  drawElems(coll);            // draw different kinds of GeoObjs
}