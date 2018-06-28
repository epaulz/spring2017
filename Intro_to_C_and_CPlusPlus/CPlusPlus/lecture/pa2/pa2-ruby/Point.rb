class Point
  attr_accessor :x,:y

  def initialize(x: 0, y: 0)
    @x = x
    @y = y
  end

  @@origin = Point.new(x: 0, y: 0)
  def self.origin
    @@origin
  end

  def +(other)
    Point.new(x: @x+other.x, y: @y+other.y)
  end

  def -(other)
    Point.new(x: @x-other.x, y: @y-other.y)
  end

  def dot(other)
    @x*other.x + @y*other.y
  end

  def cross(other)
    @x*other.y - @y*other.x
  end

  def midpoint(other)
    Point.new(x: (@x+other.x)/2, y: (@y+other.y)/2)
  end

  def to_s()
    "[#{@x},#{@y}]"
  end
end
