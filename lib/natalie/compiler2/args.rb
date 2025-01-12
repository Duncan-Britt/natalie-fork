require_relative './multiple_assignment'

module Natalie
  class Compiler2
    class Args < MultipleAssignment
      private

      def transform_arg(arg)
        if arg.is_a?(Sexp)
          case arg.sexp_type
          when :kwarg
            transform_keyword_arg(arg)
          when :lasgn
            clean_up_keyword_args
            transform_optional_arg(arg)
          when :masgn
            clean_up_keyword_args
            transform_destructured_arg(arg)
          else
            raise "I don't yet know how to compile #{arg.inspect}"
          end
        elsif arg.start_with?('**')
          transform_keyword_splat_arg(arg)
        elsif arg.start_with?('*')
          clean_up_keyword_args
          transform_splat_arg(arg)
        else
          clean_up_keyword_args
          transform_required_arg(arg)
        end
      end

      def transform_keyword_arg(arg)
        _, name, default = arg
        move_keyword_arg_hash_from_args_array_to_stack
        if default
          @instructions << @pass.transform_expression(default, used: true)
          @instructions << HashDeleteWithDefaultInstruction.new(name)
        else
          @instructions << HashDeleteInstruction.new(name)
        end
        @instructions << variable_set(name)
      end

      def transform_splat_arg(arg)
        name = arg[1..-1]
        if name.empty?
          :noop
        else
          @instructions << variable_set(name)
          @instructions << VariableGetInstruction.new(name) # TODO: could eliminate this if the *splat is the last arg
        end
        :reverse
      end

      def transform_keyword_splat_arg(arg)
        name = arg[2..-1]
        if name.empty?
          :noop
        else
          move_keyword_arg_hash_from_args_array_to_stack
          @instructions << variable_set(name)
          @instructions << VariableGetInstruction.new(name) # TODO: could eliminate this if the **splat is the last arg
        end
        :reverse
      end

      def variable_set(name)
        name = name[1..] if name.start_with?('&')
        raise "bad var name: #{name.inspect}" unless name =~ /^[a-z_][a-z0-9_]*/
        VariableSetInstruction.new(name, local_only: true)
      end

      def move_keyword_arg_hash_from_args_array_to_stack
        return if @keyword_arg_hash_on_stack
        @instructions << ArrayPopKeywordArgsInstruction.new
        @keyword_arg_hash_on_stack = true
      end

      def clean_up_keyword_args
        @instructions << PopInstruction.new if @keyword_arg_hash_on_stack
        @keyword_arg_hash_on_stack = false
      end

      def clean_up
        clean_up_keyword_args
        super
      end
    end
  end
end
