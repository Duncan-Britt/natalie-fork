// DO NOT EDIT THIS FILE BY HAND!
// This file is generated by the lib/natalie/compiler/binding_gen.rb script.
// Run `make src/bindings.cpp` to regenerate this file.

#include "natalie.hpp"

namespace Natalie {

Value *ClassValue_new_method_singleton_binding(Env *env, Value *, ssize_t argc, Value **args, Block *block) {
    NAT_ASSERT_ARGC(0, 1);
    auto return_value = ClassValue::new_method(env, argc > 0 ? args[0] : nullptr , block);
    return return_value;
}

Value *ClassValue_superclass_binding(Env *env, Value *self_value, ssize_t argc, Value **args, Block *block) {
    NAT_ASSERT_ARGC(0);
    ClassValue *self = self_value->as_class();
    auto return_value = self->superclass(  );
    if (return_value) { return return_value; } else { return NAT_NIL; }
}

Value *EncodingValue_list_singleton_binding(Env *env, Value *, ssize_t argc, Value **args, Block *block) {
    NAT_ASSERT_ARGC(0);
    auto return_value = EncodingValue::list(env  );
    return return_value;
}

Value *EncodingValue_inspect_binding(Env *env, Value *self_value, ssize_t argc, Value **args, Block *block) {
    NAT_ASSERT_ARGC(0);
    EncodingValue *self = self_value->as_encoding();
    auto return_value = self->inspect(env  );
    return return_value;
}

Value *EncodingValue_name_binding(Env *env, Value *self_value, ssize_t argc, Value **args, Block *block) {
    NAT_ASSERT_ARGC(0);
    EncodingValue *self = self_value->as_encoding();
    auto return_value = self->name(env  );
    return return_value;
}

Value *EncodingValue_names_binding(Env *env, Value *self_value, ssize_t argc, Value **args, Block *block) {
    NAT_ASSERT_ARGC(0);
    EncodingValue *self = self_value->as_encoding();
    auto return_value = self->names(env  );
    return return_value;
}

Value *FloatValue_mod_binding(Env *env, Value *self_value, ssize_t argc, Value **args, Block *block) {
    NAT_ASSERT_ARGC(1);
    FloatValue *self = self_value->as_float();
    auto return_value = self->mod(env, argc > 0 ? args[0] : nullptr );
    return return_value;
}

Value *FloatValue_mul_binding(Env *env, Value *self_value, ssize_t argc, Value **args, Block *block) {
    NAT_ASSERT_ARGC(1);
    FloatValue *self = self_value->as_float();
    auto return_value = self->mul(env, argc > 0 ? args[0] : nullptr );
    return return_value;
}

Value *FloatValue_pow_binding(Env *env, Value *self_value, ssize_t argc, Value **args, Block *block) {
    NAT_ASSERT_ARGC(1);
    FloatValue *self = self_value->as_float();
    auto return_value = self->pow(env, argc > 0 ? args[0] : nullptr );
    return return_value;
}

Value *FloatValue_add_binding(Env *env, Value *self_value, ssize_t argc, Value **args, Block *block) {
    NAT_ASSERT_ARGC(1);
    FloatValue *self = self_value->as_float();
    auto return_value = self->add(env, argc > 0 ? args[0] : nullptr );
    return return_value;
}

Value *FloatValue_uplus_binding(Env *env, Value *self_value, ssize_t argc, Value **args, Block *block) {
    NAT_ASSERT_ARGC(0);
    FloatValue *self = self_value->as_float();
    auto return_value = self->uplus(  );
    return return_value;
}

Value *FloatValue_sub_binding(Env *env, Value *self_value, ssize_t argc, Value **args, Block *block) {
    NAT_ASSERT_ARGC(1);
    FloatValue *self = self_value->as_float();
    auto return_value = self->sub(env, argc > 0 ? args[0] : nullptr );
    return return_value;
}

Value *FloatValue_uminus_binding(Env *env, Value *self_value, ssize_t argc, Value **args, Block *block) {
    NAT_ASSERT_ARGC(0);
    FloatValue *self = self_value->as_float();
    auto return_value = self->uminus(  );
    return return_value;
}

Value *FloatValue_div_binding(Env *env, Value *self_value, ssize_t argc, Value **args, Block *block) {
    NAT_ASSERT_ARGC(1);
    FloatValue *self = self_value->as_float();
    auto return_value = self->div(env, argc > 0 ? args[0] : nullptr );
    return return_value;
}

Value *FloatValue_lt_binding(Env *env, Value *self_value, ssize_t argc, Value **args, Block *block) {
    NAT_ASSERT_ARGC(1);
    FloatValue *self = self_value->as_float();
    auto return_value = self->lt(env, argc > 0 ? args[0] : nullptr );
    if (return_value) { return NAT_TRUE; } else { return NAT_FALSE; }
}

Value *FloatValue_lte_binding(Env *env, Value *self_value, ssize_t argc, Value **args, Block *block) {
    NAT_ASSERT_ARGC(1);
    FloatValue *self = self_value->as_float();
    auto return_value = self->lte(env, argc > 0 ? args[0] : nullptr );
    if (return_value) { return NAT_TRUE; } else { return NAT_FALSE; }
}

Value *FloatValue_cmp_binding(Env *env, Value *self_value, ssize_t argc, Value **args, Block *block) {
    NAT_ASSERT_ARGC(1);
    FloatValue *self = self_value->as_float();
    auto return_value = self->cmp(env, argc > 0 ? args[0] : nullptr );
    return return_value;
}

Value *FloatValue_eq_binding(Env *env, Value *self_value, ssize_t argc, Value **args, Block *block) {
    NAT_ASSERT_ARGC(1);
    FloatValue *self = self_value->as_float();
    auto return_value = self->eq(env, argc > 0 ? args[0] : nullptr );
    if (return_value) { return NAT_TRUE; } else { return NAT_FALSE; }
}

Value *FloatValue_eq_binding1(Env *env, Value *self_value, ssize_t argc, Value **args, Block *block) {
    NAT_ASSERT_ARGC(1);
    FloatValue *self = self_value->as_float();
    auto return_value = self->eq(env, argc > 0 ? args[0] : nullptr );
    if (return_value) { return NAT_TRUE; } else { return NAT_FALSE; }
}

Value *FloatValue_gt_binding(Env *env, Value *self_value, ssize_t argc, Value **args, Block *block) {
    NAT_ASSERT_ARGC(1);
    FloatValue *self = self_value->as_float();
    auto return_value = self->gt(env, argc > 0 ? args[0] : nullptr );
    if (return_value) { return NAT_TRUE; } else { return NAT_FALSE; }
}

Value *FloatValue_gte_binding(Env *env, Value *self_value, ssize_t argc, Value **args, Block *block) {
    NAT_ASSERT_ARGC(1);
    FloatValue *self = self_value->as_float();
    auto return_value = self->gte(env, argc > 0 ? args[0] : nullptr );
    if (return_value) { return NAT_TRUE; } else { return NAT_FALSE; }
}

Value *FloatValue_abs_binding(Env *env, Value *self_value, ssize_t argc, Value **args, Block *block) {
    NAT_ASSERT_ARGC(0);
    FloatValue *self = self_value->as_float();
    auto return_value = self->abs(env  );
    return return_value;
}

Value *FloatValue_ceil_binding(Env *env, Value *self_value, ssize_t argc, Value **args, Block *block) {
    NAT_ASSERT_ARGC(0, 1);
    FloatValue *self = self_value->as_float();
    auto return_value = self->ceil(env, argc > 0 ? args[0] : nullptr );
    return return_value;
}

Value *FloatValue_coerce_binding(Env *env, Value *self_value, ssize_t argc, Value **args, Block *block) {
    NAT_ASSERT_ARGC(1);
    FloatValue *self = self_value->as_float();
    auto return_value = self->coerce(env, argc > 0 ? args[0] : nullptr );
    return return_value;
}

Value *FloatValue_divmod_binding(Env *env, Value *self_value, ssize_t argc, Value **args, Block *block) {
    NAT_ASSERT_ARGC(1);
    FloatValue *self = self_value->as_float();
    auto return_value = self->divmod(env, argc > 0 ? args[0] : nullptr );
    return return_value;
}

Value *FloatValue_eql_binding(Env *env, Value *self_value, ssize_t argc, Value **args, Block *block) {
    NAT_ASSERT_ARGC(1);
    FloatValue *self = self_value->as_float();
    auto return_value = self->eql( argc > 0 ? args[0] : nullptr );
    if (return_value) { return NAT_TRUE; } else { return NAT_FALSE; }
}

Value *FloatValue_div_binding1(Env *env, Value *self_value, ssize_t argc, Value **args, Block *block) {
    NAT_ASSERT_ARGC(1);
    FloatValue *self = self_value->as_float();
    auto return_value = self->div(env, argc > 0 ? args[0] : nullptr );
    return return_value;
}

Value *FloatValue_is_finite_binding(Env *env, Value *self_value, ssize_t argc, Value **args, Block *block) {
    NAT_ASSERT_ARGC(0);
    FloatValue *self = self_value->as_float();
    auto return_value = self->is_finite(  );
    if (return_value) { return NAT_TRUE; } else { return NAT_FALSE; }
}

Value *FloatValue_floor_binding(Env *env, Value *self_value, ssize_t argc, Value **args, Block *block) {
    NAT_ASSERT_ARGC(0, 1);
    FloatValue *self = self_value->as_float();
    auto return_value = self->floor(env, argc > 0 ? args[0] : nullptr );
    return return_value;
}

Value *FloatValue_is_infinite_binding(Env *env, Value *self_value, ssize_t argc, Value **args, Block *block) {
    NAT_ASSERT_ARGC(0);
    FloatValue *self = self_value->as_float();
    auto return_value = self->is_infinite(env  );
    return return_value;
}

Value *FloatValue_to_s_binding(Env *env, Value *self_value, ssize_t argc, Value **args, Block *block) {
    NAT_ASSERT_ARGC(0);
    FloatValue *self = self_value->as_float();
    auto return_value = self->to_s(env  );
    return return_value;
}

Value *FloatValue_is_nan_binding(Env *env, Value *self_value, ssize_t argc, Value **args, Block *block) {
    NAT_ASSERT_ARGC(0);
    FloatValue *self = self_value->as_float();
    auto return_value = self->is_nan(  );
    if (return_value) { return NAT_TRUE; } else { return NAT_FALSE; }
}

Value *FloatValue_div_binding2(Env *env, Value *self_value, ssize_t argc, Value **args, Block *block) {
    NAT_ASSERT_ARGC(1);
    FloatValue *self = self_value->as_float();
    auto return_value = self->div(env, argc > 0 ? args[0] : nullptr );
    return return_value;
}

Value *FloatValue_to_i_binding(Env *env, Value *self_value, ssize_t argc, Value **args, Block *block) {
    NAT_ASSERT_ARGC(0);
    FloatValue *self = self_value->as_float();
    auto return_value = self->to_i(env  );
    return return_value;
}

Value *FloatValue_to_s_binding1(Env *env, Value *self_value, ssize_t argc, Value **args, Block *block) {
    NAT_ASSERT_ARGC(0);
    FloatValue *self = self_value->as_float();
    auto return_value = self->to_s(env  );
    return return_value;
}

Value *FloatValue_is_zero_binding(Env *env, Value *self_value, ssize_t argc, Value **args, Block *block) {
    NAT_ASSERT_ARGC(0);
    FloatValue *self = self_value->as_float();
    auto return_value = self->is_zero(  );
    if (return_value) { return NAT_TRUE; } else { return NAT_FALSE; }
}

Value *IntegerValue_mod_binding(Env *env, Value *self_value, ssize_t argc, Value **args, Block *block) {
    NAT_ASSERT_ARGC(1);
    IntegerValue *self = self_value->as_integer();
    auto return_value = self->mod(env, argc > 0 ? args[0] : nullptr );
    return return_value;
}

Value *IntegerValue_bitwise_and_binding(Env *env, Value *self_value, ssize_t argc, Value **args, Block *block) {
    NAT_ASSERT_ARGC(1);
    IntegerValue *self = self_value->as_integer();
    auto return_value = self->bitwise_and(env, argc > 0 ? args[0] : nullptr );
    return return_value;
}

Value *IntegerValue_mul_binding(Env *env, Value *self_value, ssize_t argc, Value **args, Block *block) {
    NAT_ASSERT_ARGC(1);
    IntegerValue *self = self_value->as_integer();
    auto return_value = self->mul(env, argc > 0 ? args[0] : nullptr );
    return return_value;
}

Value *IntegerValue_pow_binding(Env *env, Value *self_value, ssize_t argc, Value **args, Block *block) {
    NAT_ASSERT_ARGC(1);
    IntegerValue *self = self_value->as_integer();
    auto return_value = self->pow(env, argc > 0 ? args[0] : nullptr );
    return return_value;
}

Value *IntegerValue_add_binding(Env *env, Value *self_value, ssize_t argc, Value **args, Block *block) {
    NAT_ASSERT_ARGC(1);
    IntegerValue *self = self_value->as_integer();
    auto return_value = self->add(env, argc > 0 ? args[0] : nullptr );
    return return_value;
}

Value *IntegerValue_sub_binding(Env *env, Value *self_value, ssize_t argc, Value **args, Block *block) {
    NAT_ASSERT_ARGC(1);
    IntegerValue *self = self_value->as_integer();
    auto return_value = self->sub(env, argc > 0 ? args[0] : nullptr );
    return return_value;
}

Value *IntegerValue_div_binding(Env *env, Value *self_value, ssize_t argc, Value **args, Block *block) {
    NAT_ASSERT_ARGC(1);
    IntegerValue *self = self_value->as_integer();
    auto return_value = self->div(env, argc > 0 ? args[0] : nullptr );
    return return_value;
}

Value *IntegerValue_cmp_binding(Env *env, Value *self_value, ssize_t argc, Value **args, Block *block) {
    NAT_ASSERT_ARGC(1);
    IntegerValue *self = self_value->as_integer();
    auto return_value = self->cmp(env, argc > 0 ? args[0] : nullptr );
    return return_value;
}

Value *IntegerValue_eqeqeq_binding(Env *env, Value *self_value, ssize_t argc, Value **args, Block *block) {
    NAT_ASSERT_ARGC(1);
    IntegerValue *self = self_value->as_integer();
    auto return_value = self->eqeqeq(env, argc > 0 ? args[0] : nullptr );
    return return_value;
}

Value *IntegerValue_abs_binding(Env *env, Value *self_value, ssize_t argc, Value **args, Block *block) {
    NAT_ASSERT_ARGC(0);
    IntegerValue *self = self_value->as_integer();
    auto return_value = self->abs(env  );
    return return_value;
}

Value *IntegerValue_chr_binding(Env *env, Value *self_value, ssize_t argc, Value **args, Block *block) {
    NAT_ASSERT_ARGC(0);
    IntegerValue *self = self_value->as_integer();
    auto return_value = self->chr(env  );
    return return_value;
}

Value *IntegerValue_coerce_binding(Env *env, Value *self_value, ssize_t argc, Value **args, Block *block) {
    NAT_ASSERT_ARGC(1);
    IntegerValue *self = self_value->as_integer();
    auto return_value = self->coerce(env, argc > 0 ? args[0] : nullptr );
    return return_value;
}

Value *IntegerValue_eql_binding(Env *env, Value *self_value, ssize_t argc, Value **args, Block *block) {
    NAT_ASSERT_ARGC(1);
    IntegerValue *self = self_value->as_integer();
    auto return_value = self->eql(env, argc > 0 ? args[0] : nullptr );
    if (return_value) { return NAT_TRUE; } else { return NAT_FALSE; }
}

Value *IntegerValue_to_s_binding(Env *env, Value *self_value, ssize_t argc, Value **args, Block *block) {
    NAT_ASSERT_ARGC(0);
    IntegerValue *self = self_value->as_integer();
    auto return_value = self->to_s(env  );
    return return_value;
}

Value *IntegerValue_succ_binding(Env *env, Value *self_value, ssize_t argc, Value **args, Block *block) {
    NAT_ASSERT_ARGC(0);
    IntegerValue *self = self_value->as_integer();
    auto return_value = self->succ(env  );
    return return_value;
}

Value *IntegerValue_times_binding(Env *env, Value *self_value, ssize_t argc, Value **args, Block *block) {
    NAT_ASSERT_ARGC(0);
    IntegerValue *self = self_value->as_integer();
    auto return_value = self->times(env  , block);
    return return_value;
}

Value *IntegerValue_to_i_binding(Env *env, Value *self_value, ssize_t argc, Value **args, Block *block) {
    NAT_ASSERT_ARGC(0);
    IntegerValue *self = self_value->as_integer();
    auto return_value = self->to_i(  );
    return return_value;
}

Value *IntegerValue_to_s_binding1(Env *env, Value *self_value, ssize_t argc, Value **args, Block *block) {
    NAT_ASSERT_ARGC(0);
    IntegerValue *self = self_value->as_integer();
    auto return_value = self->to_s(env  );
    return return_value;
}

Value *IntegerValue_bitwise_or_binding(Env *env, Value *self_value, ssize_t argc, Value **args, Block *block) {
    NAT_ASSERT_ARGC(1);
    IntegerValue *self = self_value->as_integer();
    auto return_value = self->bitwise_or(env, argc > 0 ? args[0] : nullptr );
    return return_value;
}

Value *RegexpValue_eq_binding(Env *env, Value *self_value, ssize_t argc, Value **args, Block *block) {
    NAT_ASSERT_ARGC(1);
    RegexpValue *self = self_value->as_regexp();
    auto return_value = self->eq(env, argc > 0 ? args[0] : nullptr );
    if (return_value) { return NAT_TRUE; } else { return NAT_FALSE; }
}

Value *RegexpValue_match_binding(Env *env, Value *self_value, ssize_t argc, Value **args, Block *block) {
    NAT_ASSERT_ARGC(1);
    RegexpValue *self = self_value->as_regexp();
    auto return_value = self->match(env, argc > 0 ? args[0] : nullptr );
    return return_value;
}

Value *RegexpValue_eqtilde_binding(Env *env, Value *self_value, ssize_t argc, Value **args, Block *block) {
    NAT_ASSERT_ARGC(1);
    RegexpValue *self = self_value->as_regexp();
    auto return_value = self->eqtilde(env, argc > 0 ? args[0] : nullptr );
    return return_value;
}

Value *RegexpValue_initialize_binding(Env *env, Value *self_value, ssize_t argc, Value **args, Block *block) {
    NAT_ASSERT_ARGC(0, 1);
    RegexpValue *self = self_value->as_regexp();
    auto return_value = self->initialize(env, argc > 0 ? args[0] : nullptr );
    return return_value;
}

Value *RegexpValue_inspect_binding(Env *env, Value *self_value, ssize_t argc, Value **args, Block *block) {
    NAT_ASSERT_ARGC(0);
    RegexpValue *self = self_value->as_regexp();
    auto return_value = self->inspect(env  );
    return return_value;
}

Value *RegexpValue_match_binding1(Env *env, Value *self_value, ssize_t argc, Value **args, Block *block) {
    NAT_ASSERT_ARGC(1);
    RegexpValue *self = self_value->as_regexp();
    auto return_value = self->match(env, argc > 0 ? args[0] : nullptr );
    return return_value;
}

Value *StringValue_mul_binding(Env *env, Value *self_value, ssize_t argc, Value **args, Block *block) {
    NAT_ASSERT_ARGC(1);
    StringValue *self = self_value->as_string();
    auto return_value = self->mul(env, argc > 0 ? args[0] : nullptr );
    return return_value;
}

Value *StringValue_add_binding(Env *env, Value *self_value, ssize_t argc, Value **args, Block *block) {
    NAT_ASSERT_ARGC(1);
    StringValue *self = self_value->as_string();
    auto return_value = self->add(env, argc > 0 ? args[0] : nullptr );
    return return_value;
}

Value *StringValue_ltlt_binding(Env *env, Value *self_value, ssize_t argc, Value **args, Block *block) {
    NAT_ASSERT_ARGC(1);
    StringValue *self = self_value->as_string();
    auto return_value = self->ltlt(env, argc > 0 ? args[0] : nullptr );
    return return_value;
}

Value *StringValue_cmp_binding(Env *env, Value *self_value, ssize_t argc, Value **args, Block *block) {
    NAT_ASSERT_ARGC(1);
    StringValue *self = self_value->as_string();
    auto return_value = self->cmp(env, argc > 0 ? args[0] : nullptr );
    return return_value;
}

Value *StringValue_eq_binding(Env *env, Value *self_value, ssize_t argc, Value **args, Block *block) {
    NAT_ASSERT_ARGC(1);
    StringValue *self = self_value->as_string();
    auto return_value = self->eq( argc > 0 ? args[0] : nullptr );
    if (return_value) { return NAT_TRUE; } else { return NAT_FALSE; }
}

Value *StringValue_eq_binding1(Env *env, Value *self_value, ssize_t argc, Value **args, Block *block) {
    NAT_ASSERT_ARGC(1);
    StringValue *self = self_value->as_string();
    auto return_value = self->eq( argc > 0 ? args[0] : nullptr );
    if (return_value) { return NAT_TRUE; } else { return NAT_FALSE; }
}

Value *StringValue_eqtilde_binding(Env *env, Value *self_value, ssize_t argc, Value **args, Block *block) {
    NAT_ASSERT_ARGC(1);
    StringValue *self = self_value->as_string();
    auto return_value = self->eqtilde(env, argc > 0 ? args[0] : nullptr );
    return return_value;
}

Value *StringValue_ref_binding(Env *env, Value *self_value, ssize_t argc, Value **args, Block *block) {
    NAT_ASSERT_ARGC(1);
    StringValue *self = self_value->as_string();
    auto return_value = self->ref(env, argc > 0 ? args[0] : nullptr );
    return return_value;
}

Value *StringValue_bytes_binding(Env *env, Value *self_value, ssize_t argc, Value **args, Block *block) {
    NAT_ASSERT_ARGC(0);
    StringValue *self = self_value->as_string();
    auto return_value = self->bytes(env  );
    return return_value;
}

Value *StringValue_chars_binding(Env *env, Value *self_value, ssize_t argc, Value **args, Block *block) {
    NAT_ASSERT_ARGC(0);
    StringValue *self = self_value->as_string();
    auto return_value = self->chars(env  );
    return return_value;
}

Value *StringValue_encode_binding(Env *env, Value *self_value, ssize_t argc, Value **args, Block *block) {
    NAT_ASSERT_ARGC(1);
    StringValue *self = self_value->as_string();
    auto return_value = self->encode(env, argc > 0 ? args[0] : nullptr );
    return return_value;
}

Value *StringValue_encoding_binding(Env *env, Value *self_value, ssize_t argc, Value **args, Block *block) {
    NAT_ASSERT_ARGC(0);
    StringValue *self = self_value->as_string();
    auto return_value = self->encoding(env  );
    return return_value;
}

Value *StringValue_force_encoding_binding(Env *env, Value *self_value, ssize_t argc, Value **args, Block *block) {
    NAT_ASSERT_ARGC(1);
    StringValue *self = self_value->as_string();
    auto return_value = self->force_encoding(env, argc > 0 ? args[0] : nullptr );
    return return_value;
}

Value *StringValue_index_binding(Env *env, Value *self_value, ssize_t argc, Value **args, Block *block) {
    NAT_ASSERT_ARGC(1);
    StringValue *self = self_value->as_string();
    auto return_value = self->index(env, argc > 0 ? args[0] : nullptr );
    return return_value;
}

Value *StringValue_initialize_binding(Env *env, Value *self_value, ssize_t argc, Value **args, Block *block) {
    NAT_ASSERT_ARGC(0, 1);
    StringValue *self = self_value->as_string();
    auto return_value = self->initialize(env, argc > 0 ? args[0] : nullptr );
    return return_value;
}

Value *StringValue_inspect_binding(Env *env, Value *self_value, ssize_t argc, Value **args, Block *block) {
    NAT_ASSERT_ARGC(0);
    StringValue *self = self_value->as_string();
    auto return_value = self->inspect(env  );
    return return_value;
}

Value *StringValue_length_binding(Env *env, Value *self_value, ssize_t argc, Value **args, Block *block) {
    NAT_ASSERT_ARGC(0);
    StringValue *self = self_value->as_string();
    auto return_value = self->length(  );
    return new IntegerValue { env, return_value };
}

Value *StringValue_ljust_binding(Env *env, Value *self_value, ssize_t argc, Value **args, Block *block) {
    NAT_ASSERT_ARGC(1, 2);
    StringValue *self = self_value->as_string();
    auto return_value = self->ljust(env, argc > 0 ? args[0] : nullptr, argc > 1 ? args[1] : nullptr );
    return return_value;
}

Value *StringValue_match_binding(Env *env, Value *self_value, ssize_t argc, Value **args, Block *block) {
    NAT_ASSERT_ARGC(1);
    StringValue *self = self_value->as_string();
    auto return_value = self->match(env, argc > 0 ? args[0] : nullptr );
    return return_value;
}

Value *StringValue_ord_binding(Env *env, Value *self_value, ssize_t argc, Value **args, Block *block) {
    NAT_ASSERT_ARGC(0);
    StringValue *self = self_value->as_string();
    auto return_value = self->ord(env  );
    return return_value;
}

Value *StringValue_size_binding(Env *env, Value *self_value, ssize_t argc, Value **args, Block *block) {
    NAT_ASSERT_ARGC(0);
    StringValue *self = self_value->as_string();
    auto return_value = self->size(env  );
    return return_value;
}

Value *StringValue_split_binding(Env *env, Value *self_value, ssize_t argc, Value **args, Block *block) {
    NAT_ASSERT_ARGC(0, 1);
    StringValue *self = self_value->as_string();
    auto return_value = self->split(env, argc > 0 ? args[0] : nullptr );
    return return_value;
}

Value *StringValue_sub_binding(Env *env, Value *self_value, ssize_t argc, Value **args, Block *block) {
    NAT_ASSERT_ARGC(2);
    StringValue *self = self_value->as_string();
    auto return_value = self->sub(env, argc > 0 ? args[0] : nullptr, argc > 1 ? args[1] : nullptr );
    return return_value;
}

Value *StringValue_successive_binding(Env *env, Value *self_value, ssize_t argc, Value **args, Block *block) {
    NAT_ASSERT_ARGC(0);
    StringValue *self = self_value->as_string();
    auto return_value = self->successive(env  );
    return return_value;
}

Value *StringValue_to_i_binding(Env *env, Value *self_value, ssize_t argc, Value **args, Block *block) {
    NAT_ASSERT_ARGC(0, 1);
    StringValue *self = self_value->as_string();
    auto return_value = self->to_i(env, argc > 0 ? args[0] : nullptr );
    return return_value;
}

Value *StringValue_to_s_binding(Env *env, Value *self_value, ssize_t argc, Value **args, Block *block) {
    NAT_ASSERT_ARGC(0);
    StringValue *self = self_value->as_string();
    auto return_value = self->to_s(  );
    return return_value;
}

Value *StringValue_to_str_binding(Env *env, Value *self_value, ssize_t argc, Value **args, Block *block) {
    NAT_ASSERT_ARGC(0);
    StringValue *self = self_value->as_string();
    auto return_value = self->to_str(  );
    return return_value;
}

void init_bindings(Env *env) {
    Value *Class = NAT_OBJECT->const_get(env, "Class", true);
    Class->define_singleton_method(env, "new", ClassValue_new_method_singleton_binding);
    Class->define_method(env, "superclass", ClassValue_superclass_binding);
    Value *Encoding = NAT_OBJECT->const_get(env, "Encoding", true);
    Encoding->define_singleton_method(env, "list", EncodingValue_list_singleton_binding);
    Encoding->define_method(env, "inspect", EncodingValue_inspect_binding);
    Encoding->define_method(env, "name", EncodingValue_name_binding);
    Encoding->define_method(env, "names", EncodingValue_names_binding);
    Value *Float = NAT_OBJECT->const_get(env, "Float", true);
    Float->define_method(env, "%", FloatValue_mod_binding);
    Float->define_method(env, "*", FloatValue_mul_binding);
    Float->define_method(env, "**", FloatValue_pow_binding);
    Float->define_method(env, "+", FloatValue_add_binding);
    Float->define_method(env, "+@", FloatValue_uplus_binding);
    Float->define_method(env, "-", FloatValue_sub_binding);
    Float->define_method(env, "-@", FloatValue_uminus_binding);
    Float->define_method(env, "/", FloatValue_div_binding);
    Float->define_method(env, "<", FloatValue_lt_binding);
    Float->define_method(env, "<=", FloatValue_lte_binding);
    Float->define_method(env, "<=>", FloatValue_cmp_binding);
    Float->define_method(env, "==", FloatValue_eq_binding);
    Float->define_method(env, "===", FloatValue_eq_binding1);
    Float->define_method(env, ">", FloatValue_gt_binding);
    Float->define_method(env, ">=", FloatValue_gte_binding);
    Float->define_method(env, "abs", FloatValue_abs_binding);
    Float->define_method(env, "ceil", FloatValue_ceil_binding);
    Float->define_method(env, "coerce", FloatValue_coerce_binding);
    Float->define_method(env, "divmod", FloatValue_divmod_binding);
    Float->define_method(env, "eql?", FloatValue_eql_binding);
    Float->define_method(env, "fdiv", FloatValue_div_binding1);
    Float->define_method(env, "finite?", FloatValue_is_finite_binding);
    Float->define_method(env, "floor", FloatValue_floor_binding);
    Float->define_method(env, "infinite?", FloatValue_is_infinite_binding);
    Float->define_method(env, "inspect", FloatValue_to_s_binding);
    Float->define_method(env, "nan?", FloatValue_is_nan_binding);
    Float->define_method(env, "quo", FloatValue_div_binding2);
    Float->define_method(env, "to_i", FloatValue_to_i_binding);
    Float->define_method(env, "to_s", FloatValue_to_s_binding1);
    Float->define_method(env, "zero?", FloatValue_is_zero_binding);
    Value *Integer = NAT_OBJECT->const_get(env, "Integer", true);
    Integer->define_method(env, "%", IntegerValue_mod_binding);
    Integer->define_method(env, "&", IntegerValue_bitwise_and_binding);
    Integer->define_method(env, "*", IntegerValue_mul_binding);
    Integer->define_method(env, "**", IntegerValue_pow_binding);
    Integer->define_method(env, "+", IntegerValue_add_binding);
    Integer->define_method(env, "-", IntegerValue_sub_binding);
    Integer->define_method(env, "/", IntegerValue_div_binding);
    Integer->define_method(env, "<=>", IntegerValue_cmp_binding);
    Integer->define_method(env, "===", IntegerValue_eqeqeq_binding);
    Integer->define_method(env, "abs", IntegerValue_abs_binding);
    Integer->define_method(env, "chr", IntegerValue_chr_binding);
    Integer->define_method(env, "coerce", IntegerValue_coerce_binding);
    Integer->define_method(env, "eql?", IntegerValue_eql_binding);
    Integer->define_method(env, "inspect", IntegerValue_to_s_binding);
    Integer->define_method(env, "succ", IntegerValue_succ_binding);
    Integer->define_method(env, "times", IntegerValue_times_binding);
    Integer->define_method(env, "to_i", IntegerValue_to_i_binding);
    Integer->define_method(env, "to_s", IntegerValue_to_s_binding1);
    Integer->define_method(env, "|", IntegerValue_bitwise_or_binding);
    Value *Regexp = NAT_OBJECT->const_get(env, "Regexp", true);
    Regexp->define_method(env, "==", RegexpValue_eq_binding);
    Regexp->define_method(env, "===", RegexpValue_match_binding);
    Regexp->define_method(env, "=~", RegexpValue_eqtilde_binding);
    Regexp->define_method(env, "initialize", RegexpValue_initialize_binding);
    Regexp->define_method(env, "inspect", RegexpValue_inspect_binding);
    Regexp->define_method(env, "match", RegexpValue_match_binding1);
    Value *String = NAT_OBJECT->const_get(env, "String", true);
    String->define_method(env, "*", StringValue_mul_binding);
    String->define_method(env, "+", StringValue_add_binding);
    String->define_method(env, "<<", StringValue_ltlt_binding);
    String->define_method(env, "<=>", StringValue_cmp_binding);
    String->define_method(env, "==", StringValue_eq_binding);
    String->define_method(env, "===", StringValue_eq_binding1);
    String->define_method(env, "=~", StringValue_eqtilde_binding);
    String->define_method(env, "[]", StringValue_ref_binding);
    String->define_method(env, "bytes", StringValue_bytes_binding);
    String->define_method(env, "chars", StringValue_chars_binding);
    String->define_method(env, "encode", StringValue_encode_binding);
    String->define_method(env, "encoding", StringValue_encoding_binding);
    String->define_method(env, "force_encoding", StringValue_force_encoding_binding);
    String->define_method(env, "index", StringValue_index_binding);
    String->define_method(env, "initialize", StringValue_initialize_binding);
    String->define_method(env, "inspect", StringValue_inspect_binding);
    String->define_method(env, "length", StringValue_length_binding);
    String->define_method(env, "ljust", StringValue_ljust_binding);
    String->define_method(env, "match", StringValue_match_binding);
    String->define_method(env, "ord", StringValue_ord_binding);
    String->define_method(env, "size", StringValue_size_binding);
    String->define_method(env, "split", StringValue_split_binding);
    String->define_method(env, "sub", StringValue_sub_binding);
    String->define_method(env, "succ", StringValue_successive_binding);
    String->define_method(env, "to_i", StringValue_to_i_binding);
    String->define_method(env, "to_s", StringValue_to_s_binding);
    String->define_method(env, "to_str", StringValue_to_str_binding);
}

}
