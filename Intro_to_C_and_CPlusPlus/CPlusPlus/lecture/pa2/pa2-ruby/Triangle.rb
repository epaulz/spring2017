require_relative "Point.rb"

class Triangle
  # Points
  attr_accessor :a,:b,:c

  def initialize(a: Point.origin , b: Point.origin , c: Point.origin)
    @a = a
    @b = b
    @c = c
  end

  def area()
    vec_b_a = @b-@a
    vec_c_a = @c-@a
    area = 0.5 * (vec_b_a.cross vec_c_a)
    if area < 0 then
      -1 * area
    else
      area
    end
  end

  def inside?(point:)
    sameSide?(test: point, known: @c, a: @a, b: @b) and
    sameSide?(test: point, known: @b, a: @a, b: @c) and
    sameSide?(test: point, known: @a, a: @b, b: @c)
  end

  def sameSide?(test:, known:, a:, b:)
    b_a = b-a
    test_a = test-a
    known_a = known-a
    test_cross = b_a.cross test_a
    known_cross = b_a.cross known_a
    ((test_cross < 0) == (known_cross < 0)) or test_cross == 0
  end

  def to_s()
    "#{@a}:#{@b}:#{@c}: Area = #{self.area}"
  end

end
