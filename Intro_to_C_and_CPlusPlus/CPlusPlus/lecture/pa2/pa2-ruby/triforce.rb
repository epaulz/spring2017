require_relative "Color.rb"
require_relative "Point.rb"
require_relative "Triangle.rb"
require_relative "Pixel.rb"
require_relative "Image.rb"

SIZE=512

purple = Color.new(r: 150, g: 0, b: 255)
orange = Color.new(r: 255, g: 150, b: 0)
p1 = Point.new(x: (SIZE/2)-1, y: 0)
p2 = Point.new(x: 0, y: SIZE-1)
p3 = Point.new(x: SIZE-1, y: SIZE-1)
tri = Triangle.new(a: p1, b: p2, c: p3)
img = Image.new(width: SIZE, height: SIZE)

def drawTriangle(pixels, triangle, color)
  pixels_used = []
  for pixel in pixels
    if triangle.inside?(point: pixel.point)
        pixels_used.push(pixel)
        pixel.color=color
    end
  end
  return pixels_used
end

def drawGasket(pixels, triangle, color)
  return if triangle.area < (SIZE/16)
  pixels_used = drawTriangle(pixels, triangle, color)
  mid_a_b = triangle.a.midpoint(triangle.b)
  mid_a_c = triangle.a.midpoint(triangle.c)
  mid_b_c = triangle.b.midpoint(triangle.c)
  drawGasket(pixels_used, Triangle.new(a: mid_a_b, b: mid_a_c, c: mid_b_c), color.darker)
  drawGasket(pixels_used, Triangle.new(a: triangle.a, b: mid_a_b, c: mid_a_c), color)
  drawGasket(pixels_used, Triangle.new(a: mid_a_b, b: triangle.b, c: mid_b_c), color)
  drawGasket(pixels_used, Triangle.new(a: mid_a_c, b: mid_b_c, c: triangle.c), color)
end

output = File.open("out.ppm", "w")
drawGasket(img.pixels, tri, orange)
img.print(output: output)
output.close
