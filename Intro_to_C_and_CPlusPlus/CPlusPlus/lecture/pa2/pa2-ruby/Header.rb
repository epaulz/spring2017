class Header
  attr_accessor :magic, :width, :height, :max

  def initialize(magic:, width:, height:, max:)
    @magic = magic
    @width = width
    @height = height
    @max = max
  end

  def print(output:)
    output << self.to_s 
  end

  def to_s
    "#{@magic} #{@width} #{@height} #{@max}\n"
  end
end
