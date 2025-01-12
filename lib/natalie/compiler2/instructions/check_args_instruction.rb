require_relative './base_instruction'

module Natalie
  class Compiler2
    class CheckArgsInstruction < BaseInstruction
      def initialize(positional:)
        @positional = positional
      end

      def to_s
        "check_args positional: #{@positional.inspect}"
      end

      def generate(transform)
        case @positional
        when Integer
          transform.exec("env->ensure_argc_is(argc, #{@positional})")
        when Range
          if @positional.end
            transform.exec("env->ensure_argc_between(argc, #{@positional.begin}, #{@positional.end})")
          else
            transform.exec("env->ensure_argc_at_least(argc, #{@positional.begin})")
          end
        else
          raise "unknown CheckArgsInstruction @positional type: #{@positional.inspect}"
        end
      end

      def execute(vm)
        case @positional
        when Integer
          if vm.args.size != @positional
            raise ArgumentError, "wrong number of arguments (given #{vm.args.size}, expected #{@positional})"
          end
        when Range
          unless @positional.cover?(vm.args.size)
            raise ArgumentError, "wrong number of arguments (given #{vm.args.size}, expected #{@positional.inspect})"
          end
        else
          raise "unknown CheckArgsInstruction @positional type: #{@positional.inspect}"
        end
      end
    end
  end
end
