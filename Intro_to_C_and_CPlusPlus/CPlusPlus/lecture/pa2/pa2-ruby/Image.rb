require_relative "Header.rb"

class Image
  attr_accessor :header, :pixels

  def initialize(width:, height:)
    @pixels = []
    @header = Header.new(magic: "P6", width: width, height: height, max: 255)
    for i in 0..height-1
      for j in 0..width-1
        @pixels.push(Pixel.new(point: Point.new(x: j, y: i)))
      end
    end
  end

  def print(output:)
    @header.print(output: output)
    for pixel in @pixels
      c = pixel.color
      output << c.r.chr << c.g.chr << c.b.chr
    end
  end

  def get(x,y)
    @pixels[(y*(@header.height))+x]
  end

end
