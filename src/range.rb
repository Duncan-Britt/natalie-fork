class Range
  def count(*args, &block)
    if args.empty? && block.nil?
      return Float::INFINITY if self.begin.nil?
      return Float::INFINITY if self.end.nil?
    end
    super(*args, &block)
  end

  def cover?(object)
    greater_than_begin = ->() {
      value = object.is_a?(Range) ? object.begin : object
      return false unless value

      compare_result = (self.begin <=> value)
      !!compare_result && compare_result != 1
    }

    less_than_end = ->() {
      if object.is_a?(Range)
        object_end =
          if object.exclude_end? && object.end.respond_to?(:pred)
            object.end.pred
          else
            object.end
          end

        compare_result = self.end <=> object_end
        return false unless compare_result

        if exclude_end? && !object.exclude_end?
          compare_result == 1
        else
          compare_result >= 0
        end
      else
        expected = exclude_end? ? -1 : 0
        compare_result = (object <=> self.end)
        !!compare_result && compare_result <= expected
      end
    }

    result = true

    if self.end && self.begin
      compare_result = self.begin <=> self.end
      if !compare_result || compare_result == 1 || (exclude_end? && compare_result == 0)
        return false
      end
    end

    if self.begin
      result &&= greater_than_begin.()
    end

    if self.end
      result &&= less_than_end.()
    end

    result
  end
  alias === cover?

  def size
    return Float::INFINITY if self.begin.nil?
    return unless self.begin.is_a?(Numeric)
    return Float::INFINITY if self.end.nil?
    return unless self.end.is_a?(Numeric)
    return 0 if self.end < self.begin
    return Float::INFINITY if self.begin.is_a?(Float) && self.begin.infinite?
    return Float::INFINITY if self.end.is_a?(Float) && self.end.infinite?
    size = self.end - self.begin
    size += 1 unless exclude_end?
    return size.floor if size.is_a?(Float)
    size
  end
end
