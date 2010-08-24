/*
Copyright (c) 2010, Mickaël Delahaye <mickael.delahaye@gmail.com>

Permission to use, copy, modify, and/or distribute this software for any purpose
with or without fee is hereby granted, provided that the above copyright notice
and this permission notice appear in all copies.

THE SOFTWARE IS PROVIDED “AS IS” AND THE AUTHOR DISCLAIMS ALL WARRANTIES WITH
REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND
FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT,
INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS
OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER
TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF
THIS SOFTWARE.
*/

#include <gmp.h>
#include <yices_c.h>

/* Yices_c additional functions */

// Given on yices-help by Bruno Dutertre (2009-12-16)
extern void yices_interrupt(yices_context ctx);

typedef void* yicesl_context;

// Given on yices-help by Bruno Dutertre (2010-06-01)
extern yicesl_context yices_get_lite_context(yices_context ctx);

// Guessed from nm
extern yices_expr yices_mk_function_update(yices_context ctx, yices_expr f, yices_expr args[], unsigned int n, yices_expr val);
extern yices_expr yices_mk_tuple_literal(yices_context ctx, yices_expr args[], unsigned int n);


/* Virtual types and names*/

#define error_value int
#define yices_type_ptr yices_type*

#define True l_true
#define False l_false
#define Undef l_undef

/* Unsat core and string getter */

struct unsat_core {
  int length;
  assertion_id* array;
};

struct unsat_core get_unsat_core(yices_context ctx);

char* get_rational_value_as_string(yices_model m, yices_var_decl d);
char* get_integer_value_as_string(yices_model m, yices_var_decl d);

/* Checkers */

#define check_error_value(e) if (!e) caml_failwith("error: cannot get a value")

#define CHECKNOTNULL(p,m) if (p == 0) caml_failwith("error :" m)

#define check_expr(e) CHECKNOTNULL(e,"returns null expression")
#define check_type(e) CHECKNOTNULL(e,"returns null type")
#define check_var_decl(e) CHECKNOTNULL(e,"returns null variable declaration")
#define check_context(e) CHECKNOTNULL(e,"returns null context")
#define check_model(e) CHECKNOTNULL(e,"returns null model")
#define check_var_decl_iterator(e) CHECKNOTNULL(e,"returns null iterator")


