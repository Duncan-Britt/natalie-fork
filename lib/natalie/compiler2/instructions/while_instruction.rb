require_relative './base_instruction'

module Natalie
  class Compiler2
    class WhileInstruction < BaseInstruction
      def initialize(pre:)
        @pre = pre
      end

      attr_reader :pre, :result_name

      def to_s
        s = 'while'
        s << ' (post)' unless pre
        s
      end

      def has_body?
        true
      end

      def generate(transform)
        body = transform.fetch_block_of_instructions(until_instruction: EndInstruction, expected_label: :while)
        condition = transform.pop
        @result_name = result = transform.temp('while_result')
        code = []

        # hoisted variables need to be set to nil here
        (@env[:hoisted_vars] || {}).each do |_, var|
          code << "Value #{var.fetch(:name)} = NilObject::the()"
          var[:declared] = true
        end

        code << "Value #{result}"

        transform.with_same_scope(body) do |t|
          if @pre
            code << "while (#{condition}->as_proc()->call(env)->is_truthy()) {"
            code << t.transform("#{result} =")
            code << '}'
          else
            code << 'do {'
            code << t.transform("#{result} =")
            code << "} while (#{condition}->as_proc()->call(env)->is_truthy())"
          end
        end

        transform.exec(code)
        transform.push(result)
      end

      def execute(vm)
        start_ip = vm.ip
        vm.skip_block_of_instructions(until_instruction: EndInstruction, expected_label: :while)
        end_ip = vm.ip
        condition = vm.pop
        if @pre
          while condition.()
            vm.ip = start_ip
            result = vm.run
            vm.ip = end_ip
            if result == :break_out
              result = :halt
              break
            end
          end
        else
          begin
            vm.ip = start_ip
            result = vm.run
            vm.ip = end_ip
            if result == :break_out
              p result
              result = :halt
              break
            end
          end while condition.()
        end
        unless result == :halt
          result
        end
      end
    end
  end
end
