/**
 * Objects in a program should be replaceable with instances of their subtypes
 * w/o altering the correctness of the program
*/

class Rectangle
{
  public:

    Rectangle(int width, int height);

    int get_width() const {
        return m_width;
    }

    virtual void set_width(int width);

    int get_height() const {
        return m_height;
    }

    int get_area() const {
        return m_width * m_height;
    }

    virtual void set_height(int height);

  protected:

    int m_width;
    int m_height;
};

class Square : public Rectangle
{
  public:

   Square(int side);
  
  void set_width(int width) override;

  void set_height(int height) override;

};

namespace LiskovSubstitutionPrinciple {
    void run();
}


struct RectangleFactory
{
  static Rectangle create_rectangle(int w, int h);
  static Rectangle create_square(int size);
};
  