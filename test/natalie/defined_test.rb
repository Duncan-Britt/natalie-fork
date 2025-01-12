require_relative '../spec_helper'

NUM = 1

$global = 2

class Foo
  class Bar
  end
end

def foo; end

describe 'defined?' do
  it 'recognizes constants' do
    defined?(NUM).should == 'constant'
    defined?(::NUM).should == 'constant'
    defined?(Foo).should == 'constant'
    defined?(NonExistent).should == nil
  end

  it 'recognizes namespaced constants' do
    defined?(Foo::Bar).should == 'constant'
    defined?(Food::Bar).should == nil
    defined?(Foo::NUM).should == nil
  end

  it 'recognizes variables' do
    x = 1
    defined?(x).should == 'local-variable'
    defined?(not_a_variable).should == nil
  end

  it 'recognizes instance variables' do
    @x = 1
    defined?(@x).should == 'instance-variable'
    defined?(@not_a_variable).should == nil
  end

  it 'recognizes global variables' do
    defined?($global).should == 'global-variable'
    defined?($not_a_global).should == nil
  end

  it 'recognizes methods' do
    defined?(p).should == 'method'
    defined?(foo).should == 'method'
    ary = []
    defined?(ary.any?).should == 'method'
    defined?([].any?).should == 'method'
    defined?(1 + 1).should == 'method'
    defined?(not_a_method).should == nil
    hash = {}
    defined?(hash[]).should == 'method'
    defined?(hash[1]).should == 'method'
  end

  it 'recognizes expressions' do
    defined?(1).should == 'expression'
    defined?('hi').should == 'expression'
  end

  it 'recognizes nil' do
    defined?(nil).should == 'nil'
  end

  it 'does not raise an error' do
    defined?(x.y).should == nil
    defined?(x.y.z).should == nil
  end
end
