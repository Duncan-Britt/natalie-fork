# -*- encoding: utf-8 -*-
require_relative '../../spec_helper'
require_relative 'fixtures/classes'

describe "String#chomp" do
  describe "when passed no argument" do
    before do
      # Ensure that $/ is set to the default value
      @verbose, $VERBOSE = $VERBOSE, nil
      @dollar_slash, $/ = $/, "\n"
    end

    after do
      $/ = @dollar_slash
      $VERBOSE = @verbose
    end

    it "does not modify a String with no trailing carriage return or newline" do
      "abc".chomp.should == "abc"
    end

    it "returns a copy of the String when it is not modified" do
      str = "abc"
      str.chomp.should_not equal(str)
    end

    it "removes one trailing newline" do
      "abc\n\n".chomp.should == "abc\n"
    end

    it "removes one trailing carriage return" do
      "abc\r\r".chomp.should == "abc\r"
    end

    it "removes one trailing carriage return, newline pair" do
      "abc\r\n\r\n".chomp.should == "abc\r\n"
    end

    it "returns an empty String when self is empty" do
      "".chomp.should == ""
    end
    
    ruby_version_is ''...'3.0' do
      it "returns subclass instances when called on a subclass" do
        str = StringSpecs::MyString.new("hello\n").chomp
        str.should be_an_instance_of(StringSpecs::MyString)
      end
    end

    ruby_version_is '3.0' do
      it "returns String instances when called on a subclass" do
        str = StringSpecs::MyString.new("hello\n").chomp
        str.should be_an_instance_of(String)
      end
    end

    it "removes trailing characters that match $/ when it has been assigned a value" do
      $/ = "cdef"
      "abcdef".chomp.should == "ab"
    end

    it "removes one trailing newline for string with invalid encoding" do
      "\xa0\xa1\n".chomp.should == "\xa0\xa1"
    end
  end

  describe "when passed nil" do
    it "does not modify the String" do
      "abc\r\n".chomp(nil).should == "abc\r\n"
    end

    it "returns a copy of the String" do
      str = "abc"
      str.chomp(nil).should_not equal(str)
    end

    it "returns an empty String when self is empty" do
      "".chomp(nil).should == ""
    end
  end

  describe "when passed ''" do
    it "removes a final newline" do
      "abc\n".chomp("").should == "abc"
    end

    it "removes a final carriage return, newline" do
      "abc\r\n".chomp("").should == "abc"
    end

    it "does not remove a final carriage return" do
      "abc\r".chomp("").should == "abc\r"
    end

    it "removes more than one trailing newlines" do
      "abc\n\n\n".chomp("").should == "abc"
    end

    it "removes more than one trailing carriage return, newline pairs" do
      "abc\r\n\r\n\r\n".chomp("").should == "abc"
    end

    it "returns an empty String when self is empty" do
      "".chomp("").should == ""
    end

    it "removes one trailing newline for string with invalid encoding" do
      "\xa0\xa1\n".chomp("").should == "\xa0\xa1"
    end
  end

  describe "when passed '\\n'" do
    it "removes one trailing newline" do
      "abc\n\n".chomp("\n").should == "abc\n"
    end

    it "removes one trailing carriage return" do
      "abc\r\r".chomp("\n").should == "abc\r"
    end

    it "removes one trailing carriage return, newline pair" do
      "abc\r\n\r\n".chomp("\n").should == "abc\r\n"
    end

    it "returns an empty String when self is empty" do
      "".chomp("\n").should == ""
    end
  end

  describe "when passed an Object" do
    it "calls #to_str to convert to a String" do
      arg = mock("string chomp")
      arg.should_receive(:to_str).and_return("bc")
      "abc".chomp(arg).should == "a"
    end

    it "raises a TypeError if #to_str does not return a String" do
      arg = mock("string chomp")
      arg.should_receive(:to_str).and_return(1)
      -> { "abc".chomp(arg) }.should raise_error(TypeError)
    end
  end

  describe "when passed a String" do
    it "removes the trailing characters if they match the argument" do
      "abcabc".chomp("abc").should == "abc"
    end

    it "does not modify the String if the argument does not match the trailing characters" do
      "abc".chomp("def").should == "abc"
    end

    it "returns an empty String when self is empty" do
      "".chomp("abc").should == ""
    end

    it "returns an empty String when the argument equals self" do
      "abc".chomp("abc").should == ""
    end
  end
end

# String#chomp unimplemented
describe "String#chomp!" do
  describe "when passed no argument" do
    before do
      # Ensure that $/ is set to the default value
      @verbose, $VERBOSE = $VERBOSE, nil
      @dollar_slash, $/ = $/, "\n"
    end

    after do
      $/ = @dollar_slash
      $VERBOSE = @verbose
    end

    xit "modifies self" do
      str = "abc\n"
      str.chomp!.should equal(str)
    end

    xit "returns nil if self is not modified" do
      "abc".chomp!.should be_nil
    end

    xit "removes one trailing newline" do
      "abc\n\n".chomp!.should == "abc\n"
    end

    xit "removes one trailing carriage return" do
      "abc\r\r".chomp!.should == "abc\r"
    end

    xit "removes one trailing carriage return, newline pair" do
      "abc\r\n\r\n".chomp!.should == "abc\r\n"
    end

    xit "returns nil when self is empty" do
      "".chomp!.should be_nil
    end

    xit "returns subclass instances when called on a subclass" do
      str = StringSpecs::MyString.new("hello\n").chomp!
      str.should be_an_instance_of(StringSpecs::MyString)
    end

    xit "removes trailing characters that match $/ when it has been assigned a value" do
      $/ = "cdef"
      "abcdef".chomp!.should == "ab"
    end
  end

  describe "when passed nil" do
    xit "returns nil" do
      "abc\r\n".chomp!(nil).should be_nil
    end

    xit "returns nil when self is empty" do
      "".chomp!(nil).should be_nil
    end
  end

  describe "when passed ''" do
    xit "removes a final newline" do
      "abc\n".chomp!("").should == "abc"
    end

    xit "removes a final carriage return, newline" do
      "abc\r\n".chomp!("").should == "abc"
    end

    xit "does not remove a final carriage return" do
      "abc\r".chomp!("").should be_nil
    end

    xit "removes more than one trailing newlines" do
      "abc\n\n\n".chomp!("").should == "abc"
    end

    xit "removes more than one trailing carriage return, newline pairs" do
      "abc\r\n\r\n\r\n".chomp!("").should == "abc"
    end

    xit "returns nil when self is empty" do
      "".chomp!("").should be_nil
    end
  end

  describe "when passed '\\n'" do
    xit "removes one trailing newline" do
      "abc\n\n".chomp!("\n").should == "abc\n"
    end

    xit "removes one trailing carriage return" do
      "abc\r\r".chomp!("\n").should == "abc\r"
    end

    xit "removes one trailing carriage return, newline pair" do
      "abc\r\n\r\n".chomp!("\n").should == "abc\r\n"
    end

    xit "returns nil when self is empty" do
      "".chomp!("\n").should be_nil
    end
  end

  describe "when passed an Object" do
    xit "calls #to_str to convert to a String" do
      arg = mock("string chomp")
      arg.should_receive(:to_str).and_return("bc")
      "abc".chomp!(arg).should == "a"
    end

    xit "raises a TypeError if #to_str does not return a String" do
      arg = mock("string chomp")
      arg.should_receive(:to_str).and_return(1)
      -> { "abc".chomp!(arg) }.should raise_error(TypeError)
    end
  end

  describe "when passed a String" do
    xit "removes the trailing characters if they match the argument" do
      "abcabc".chomp!("abc").should == "abc"
    end

    xit "returns nil if the argument does not match the trailing characters" do
      "abc".chomp!("def").should be_nil
    end

    xit "returns nil when self is empty" do
      "".chomp!("abc").should be_nil
    end
  end

  xit "raises a FrozenError on a frozen instance when it is modified" do
    a = "string\n\r"
    a.freeze

    -> { a.chomp! }.should raise_error(FrozenError)
  end

  # see [ruby-core:23666]
  xit "raises a FrozenError on a frozen instance when it would not be modified" do
    a = "string\n\r"
    a.freeze
    -> { a.chomp!(nil) }.should raise_error(FrozenError)
    -> { a.chomp!("x") }.should raise_error(FrozenError)
  end
end

describe "String#chomp" do
  before :each do
    @verbose, $VERBOSE = $VERBOSE, nil
    @before_separator = $/
  end

  after :each do
    $/ = @before_separator
    $VERBOSE = @verbose
  end

  it "does not modify a multi-byte character" do
    "あれ".chomp.should == "あれ"
  end

  it "removes the final carriage return, newline from a multibyte String" do
    "あれ\r\n".chomp.should == "あれ"
  end

  # String#encode throws errors when invoked with
  # "utf-32be" as of Jun 22, 2022
  xit "removes the final carriage return, newline from a non-ASCII String" do
    str = "abc\r\n".encode "utf-32be"
    str.chomp.should == "abc".encode("utf-32be")
  end

  xit "removes the final carriage return, newline from a non-ASCII String when the record separator is changed" do
    $/ = "\n".encode("utf-8")
    str = "abc\r\n".encode "utf-32be"
    str.chomp.should == "abc".encode("utf-32be")
  end
end

# String#chomp! unimplemented
describe "String#chomp!" do
  before :each do
    @verbose, $VERBOSE = $VERBOSE, nil
    @before_separator = $/
  end

  after :each do
    $/ = @before_separator
    $VERBOSE = @verbose
  end

  xit "returns nil when the String is not modified" do
    "あれ".chomp!.should be_nil
  end

  xit "removes the final carriage return, newline from a multibyte String" do
    "あれ\r\n".chomp!.should == "あれ"
  end

  xit "removes the final carriage return, newline from a non-ASCII String" do
    str = "abc\r\n".encode "utf-32be"
    str.chomp!.should == "abc".encode("utf-32be")
  end

  xit "removes the final carriage return, newline from a non-ASCII String when the record separator is changed" do
    $/ = "\n".encode("utf-8")
    str = "abc\r\n".encode "utf-32be"
    str.chomp!.should == "abc".encode("utf-32be")
  end
end
