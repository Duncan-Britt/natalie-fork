#include <errno.h>
#include <unistd.h>

#include "builtin.hpp"
#include "gc.hpp"
#include "natalie.hpp"

NatObject *IO_new(NatEnv *env, NatObject *self, ssize_t argc, NatObject **args, NatBlock *block) {
    NatObject *obj = Object_new(env, self, argc, args, block);
    obj->type = NAT_VALUE_IO;
    return obj;
}

NatObject *IO_initialize(NatEnv *env, NatObject *self, ssize_t argc, NatObject **args, NatBlock *block) {
    NAT_ASSERT_ARGC(1); // TODO: ruby accepts 1..2
    NAT_ASSERT_TYPE(args[0], NAT_VALUE_INTEGER, "Integer");
    self->fileno = NAT_INT_VALUE(args[0]);
    return self;
}

NatObject *IO_fileno(NatEnv *env, NatObject *self, ssize_t argc, NatObject **args, NatBlock *block) {
    NAT_ASSERT_ARGC(0);
    return nat_integer(env, self->fileno);
}

#define NAT_READ_BYTES 1024

NatObject *IO_read(NatEnv *env, NatObject *self, ssize_t argc, NatObject **args, NatBlock *block) {
    NAT_ASSERT_ARGC(0, 1); // TODO: ruby accepts 0..2
    ssize_t bytes_read;
    if (argc == 1) {
        NAT_ASSERT_TYPE(args[0], NAT_VALUE_INTEGER, "Integer");
        int count = NAT_INT_VALUE(args[0]);
        char *buf = static_cast<char *>(malloc((count + 1) * sizeof(char)));
        bytes_read = read(self->fileno, buf, count);
        if (bytes_read == 0) {
            free(buf);
            return NAT_NIL;
        } else {
            buf[bytes_read] = 0;
            NatObject *result = nat_string(env, buf);
            free(buf);
            return result;
        }
    } else if (argc == 0) {
        char buf[NAT_READ_BYTES + 1];
        bytes_read = read(self->fileno, buf, NAT_READ_BYTES);
        if (bytes_read == 0) {
            return nat_string(env, "");
        } else {
            buf[bytes_read] = 0;
            NatObject *str = nat_string(env, buf);
            while (1) {
                bytes_read = read(self->fileno, buf, NAT_READ_BYTES);
                if (bytes_read == 0) break;
                buf[bytes_read] = 0;
                nat_string_append(env, str, buf);
            }
            return str;
        }
    } else {
        printf("TODO: 3 args passed to IO#read\n");
        abort();
    }
}

NatObject *IO_write(NatEnv *env, NatObject *self, ssize_t argc, NatObject **args, NatBlock *block) {
    NAT_ASSERT_ARGC_AT_LEAST(1);
    int bytes_written = 0;
    for (ssize_t i = 0; i < argc; i++) {
        NatObject *obj = args[i];
        if (NAT_TYPE(obj) != NAT_VALUE_STRING) {
            obj = nat_send(env, obj, "to_s", 0, NULL, NULL);
        }
        NAT_ASSERT_TYPE(obj, NAT_VALUE_STRING, "String");
        ssize_t result = write(self->fileno, obj->str, obj->str_len);
        if (result == -1) {
            NatObject *error_number = nat_integer(env, errno);
            NatObject *error = nat_send(env, nat_const_get(env, NAT_OBJECT, "SystemCallError", true), "exception", 1, &error_number, NULL);
            nat_raise_exception(env, error);
            abort();
        } else {
            bytes_written += result;
        }
    }
    return nat_integer(env, bytes_written);
}

NatObject *IO_puts(NatEnv *env, NatObject *self, ssize_t argc, NatObject **args, NatBlock *block) {
    int fd = self->fileno;
    if (argc == 0) {
        dprintf(fd, "\n");
    } else {
        for (ssize_t i = 0; i < argc; i++) {
            NatObject *str = nat_send(env, args[i], "to_s", 0, NULL, NULL);
            NAT_ASSERT_TYPE(str, NAT_VALUE_STRING, "String");
            dprintf(fd, "%s\n", str->str);
        }
    }
    return NAT_NIL;
}

NatObject *IO_print(NatEnv *env, NatObject *self, ssize_t argc, NatObject **args, NatBlock *block) {
    int fd = self->fileno;
    if (argc > 0) {
        for (ssize_t i = 0; i < argc; i++) {
            NatObject *str = nat_send(env, args[i], "to_s", 0, NULL, NULL);
            NAT_ASSERT_TYPE(str, NAT_VALUE_STRING, "String");
            dprintf(fd, "%s", str->str);
        }
    }
    return NAT_NIL;
}

NatObject *IO_close(NatEnv *env, NatObject *self, ssize_t argc, NatObject **args, NatBlock *block) {
    NAT_ASSERT_ARGC(0);
    int result = close(self->fileno);
    if (result == -1) {
        NatObject *error_number = nat_integer(env, errno);
        NatObject *error = nat_send(env, nat_const_get(env, NAT_OBJECT, "SystemCallError", true), "exception", 1, &error_number, NULL);
        nat_raise_exception(env, error);
        abort();
    } else {
        return NAT_NIL;
    }
}

NatObject *IO_seek(NatEnv *env, NatObject *self, ssize_t argc, NatObject **args, NatBlock *block) {
    NAT_ASSERT_ARGC2(1, 2);
    NatObject *amount_obj = args[0];
    NAT_ASSERT_TYPE(amount_obj, NAT_VALUE_INTEGER, "Integer");
    int amount = NAT_INT_VALUE(amount_obj);
    int whence = 0;
    if (argc > 1) {
        NatObject *whence_obj = args[1];
        switch (NAT_TYPE(whence_obj)) {
        case NAT_VALUE_INTEGER:
            whence = NAT_INT_VALUE(whence_obj);
            break;
        case NAT_VALUE_SYMBOL:
            if (strcmp(whence_obj->symbol, "SET") == 0) {
                whence = 0;
            } else if (strcmp(whence_obj->symbol, "CUR") == 0) {
                whence = 1;
            } else if (strcmp(whence_obj->symbol, "END") == 0) {
                whence = 2;
            } else {
                NAT_RAISE(env, "TypeError", "no implicit conversion of Symbol into NAT_INTEGER");
            }
            break;
        default:
            NAT_RAISE(env, "TypeError", "no implicit conversion of %s into NAT_INTEGER", NAT_OBJ_CLASS(whence_obj)->class_name);
        }
    }
    int result = lseek(self->fileno, amount, whence);
    if (result == -1) {
        NatObject *error_number = nat_integer(env, errno);
        NatObject *error = nat_send(env, nat_const_get(env, NAT_OBJECT, "SystemCallError", true), "exception", 1, &error_number, NULL);
        nat_raise_exception(env, error);
        abort();
    } else {
        return nat_integer(env, 0);
    }
}