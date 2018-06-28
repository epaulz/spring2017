require_relative "Point.rb"
require_relative "Color.rb"

class Pixel
  attr_accessor :color, :point

  def initialize(point: Point.origin, color: Color.white)
    @point = point
    @color = color
  end

  def to_s
    "#{@point}:#{@color}"
  end
end
