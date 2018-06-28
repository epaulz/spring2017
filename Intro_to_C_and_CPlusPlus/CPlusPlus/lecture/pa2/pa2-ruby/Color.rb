class Color
  attr_accessor :r,:g,:b

  def initialize(r: 0, g: 0, b: 0)
    @r = r.to_i
    @g = g.to_i
    @b = b.to_i
  end

  @@white = Color.new(r: 255, g: 255, b: 255)
  def self.white
    @@white
  end

  def lighter(factor: 0.5)
    r = @r + ((255-@r)*factor).to_i
    g = @g + ((255-@g)*factor).to_i
    b = @b + ((255-@b)*factor).to_i
    Color.new(r: r, g: g, b: b)
  end

  def darker(factor: 0.5)
    r = (@r*factor).to_i
    g = (@g*factor).to_i
    b = (@b*factor).to_i
    Color.new(r: r, g: g, b: b)
  end

  def to_s()
    "[#{@r},#{@g},#{@b}]"
  end
end
