/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "analisis_sintactico.y"


#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "estructurasTS.h"
void yyerror(char * msg);

int linea_actual = 1;

#define MAX_TS 500

unsigned int TOPE = 0; /* Tope de la pila */
unsigned int subprog;  /* Indicador de comienzo de bloque de subprog */
dtipo tipoTmp; 

entradaTS TS[MAX_TS];  /* TABLA DE SÍMBOLOS */
entradaTS TS_aux[MAX_TS]; /* Tabla auxiliar para paramf */
int TOPE_AUX = 0;
int TOPE_ARG = 0;

entradaTS PILA_ARG[MAX_TS];

typedef struct{
  int atrib;
  char* lexema;
  dtipo tipo;
  unsigned int dimensiones;
  int TamDimen1;
  int TamDimen2;
} atributos;

#define YYSTYPE atributos /* Cada símbolo tiene una estructura de tipo atributos */

/* Funciones y procedimientos de manejo de TS */

void TS_InsertaENTRADA(entradaTS ets);
void TSAUX_InsertaENTRADA(entradaTS ets);
void TS_InsertaMARCA();
void TS_InsertaIDENT(atributos atr);
void TS_VaciarENTRADAS();
void TS_InsertaSUBPROG(atributos atr);
void TS_InsertaPARAMF(atributos atr);

void PILARG_insertaENTRADA(entradaTS ets);
void PILARG_insertaMARCA();
void PILARG_insertaARG(atributos arg);

dtipo atributoAEnum(int atr);
/* Fin de declaraciones */

/* 
  Funciones para hacer comprobaciones semánticas
*/
entradaTS buscarEntrada(char* nombre);
atributos entradaAAtributos(entradaTS ets);
atributos procesaOperacionBinariaOMixta(atributos op1, atributos op2, int opdor);
atributos procesaOperacionMixtaCuandoUnaria(atributos op1);
atributos procesaOperacionNegacion(atributos op1);
void procesaSentenciaAsignacion(atributos op1, atributos op2);
void procesaSentenciaControl(atributos exp);
void procesaSentenciaRetornar(atributos ret);
void procesaLlamadaFuncionConArgumentos(entradaTS ets);
void procesaLlamadaFuncionSinArgumentos(entradaTS ets);

/*
  Funciones para debuggear
*/

void mostrar_tabla();
char* entrada_a_string(entradaTS);
char* enumAChar(dtipo t);


#line 146 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif


/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    OPOR = 258,
    OPAND = 259,
    OPEQ = 260,
    OPNEQ = 261,
    OPLEQ = 262,
    OPGEQ = 263,
    OPLESS = 264,
    OPGR = 265,
    OPSUMA = 266,
    OPRESTA = 267,
    OPMULT = 268,
    OPMULTM = 269,
    OPDIV = 270,
    OPMOD = 271,
    OPNEG = 272,
    CONST = 273,
    CONSTENT = 274,
    IDEN = 275,
    CADENA = 276,
    ASIG = 277,
    CORIZQ = 278,
    CORDER = 279,
    PARIZQ = 280,
    PARDER = 281,
    LLAIZQ = 282,
    LLADER = 283,
    PYC = 284,
    COMA = 285,
    SI = 286,
    SINO = 287,
    MIENTRAS = 288,
    HACER = 289,
    HASTA = 290,
    INIDEC = 291,
    FINDEC = 292,
    SALIDA = 293,
    ENTRADA = 294,
    DEVOLVER = 295,
    MAIN = 296,
    TIPOEL = 297
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);





#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   419

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  43
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  47
/* YYNRULES -- Number of rules.  */
#define YYNRULES  100
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  179

#define YYUNDEFTOK  2
#define YYMAXUTOK   297


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    95,    95,    96,    96,   101,   102,   103,   103,   104,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   115,
     116,   117,   118,   119,   119,   120,   120,   121,   122,   125,
     126,   130,   136,   137,   138,   141,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     160,   161,   162,   163,   164,   165,   166,   167,   167,   168,
     169,   170,   171,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   201,
     201,   204,   205,   206,   207,   208,   209,   212,   224,   226,
     227
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "OPOR", "OPAND", "OPEQ", "OPNEQ",
  "OPLEQ", "OPGEQ", "OPLESS", "OPGR", "OPSUMA", "OPRESTA", "OPMULT",
  "OPMULTM", "OPDIV", "OPMOD", "OPNEG", "CONST", "CONSTENT", "IDEN",
  "CADENA", "ASIG", "CORIZQ", "CORDER", "PARIZQ", "PARDER", "LLAIZQ",
  "LLADER", "PYC", "COMA", "SI", "SINO", "MIENTRAS", "HACER", "HASTA",
  "INIDEC", "FINDEC", "SALIDA", "ENTRADA", "DEVOLVER", "MAIN", "TIPOEL",
  "$accept", "Programa", "bloque", "$@1", "Declar_subprogs",
  "Declar_subprog", "$@2", "Declar_de_variables_locales",
  "Marca_ini_declar_variables", "Marca_fin_declar_variables",
  "Cabecera_programa", "Inicio_de_bloque", "Fin_de_bloque",
  "Variables_locales", "Cuerpo_declar_variables", "$@3",
  "Cabecera_subprog", "argumentos", "$@4", "$@5", "variable",
  "elemento_de_array_decl", "variable_expresion", "elemento_de_array",
  "Sentencias", "Sentencia", "sentencia_asignacion", "sentencia_si",
  "sentencia_mientras", "sentencia_hacer_hasta", "sentencia_entrada",
  "sentencia_salida", "sentencia_retornar", "lista_expresiones_cadena",
  "expresion_cadena", "lista_variables", "lista_declaracion_variables",
  "lista_expresiones", "expresion", "funcion", "$@6", "tipo", "cadena",
  "identificador", "constante", "ini_elementos_array",
  "lista_expresiones_array", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297
};
# endif

#define YYPACT_NINF (-36)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -35,   -36,    17,     5,   -36,   -36,   -36,   -36,   -16,   -36,
     -36,     8,     7,   -36,   -36,     6,   -36,   -36,   -36,   -36,
      12,    29,   130,    41,    37,   239,   -36,   -36,   -36,    46,
     -36,    88,   -36,   -36,   -36,   -36,   -36,   -36,   -36,   -36,
      37,    47,   -36,   -36,   -36,    43,   239,   239,    36,   -36,
     239,   239,   239,   -36,   -36,   -36,   239,   239,   -36,    64,
     -36,   380,   -36,   -36,    42,   -36,   -36,   -36,    84,    68,
     196,     5,   239,   -36,   -36,   -36,    71,   239,   -36,   -36,
      94,   262,   286,    73,   129,   -36,   -36,   380,    -8,    70,
     310,   -36,    41,   239,   239,   239,   239,   239,   239,   239,
     239,   239,   239,   239,   239,   239,   239,    77,   -36,    37,
      98,   -36,   -36,   223,    13,   168,   -36,    37,   130,   130,
     239,   -36,   239,   239,   -36,   -36,   393,   208,   403,   403,
     121,   121,   121,   121,   129,   129,   -36,   -36,   -36,   -36,
     -36,   239,   -36,   -19,   -36,   -36,   -36,    60,   -36,   -36,
     239,   -36,    86,   -36,   334,    70,   380,    62,   380,   -36,
     106,   -36,    96,    37,   358,   130,   101,   -36,   239,   115,
     -36,   -36,   -36,   -36,   -36,   380,   -36,    37,   -36
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    13,     0,     0,     1,    14,     2,     3,    10,    11,
       6,     0,     0,    20,    91,     0,    17,    18,    47,    93,
       0,     0,     0,     0,     0,     0,    38,     5,     7,     0,
      33,     0,    37,    39,    40,    41,    42,    43,    44,    45,
       0,    32,    12,     9,    16,     0,     0,     0,     0,    87,
       0,     0,     0,    94,    95,    92,     0,     0,    84,     0,
      56,    57,    86,    58,    32,    85,    59,    29,     0,    28,
       0,     0,     0,    15,     4,    36,     0,     0,    63,    61,
       0,     0,     0,     0,    68,    69,    67,    99,     0,    98,
       0,    53,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    89,    52,     0,
       0,    54,     8,     0,     0,     0,    19,     0,     0,     0,
       0,    96,     0,     0,    66,    55,    74,    73,    75,    76,
      77,    78,    79,    80,    82,    83,    70,    72,    71,    81,
      88,     0,    60,     0,    46,    27,    22,     0,    23,    34,
       0,    62,    48,    50,     0,    97,   100,     0,    64,    30,
       0,    21,     0,     0,     0,     0,     0,    90,     0,     0,
      25,    24,    35,    49,    51,    65,    31,     0,    26
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -36,   -36,    -2,   -36,   -36,   -36,   -36,   -36,   -36,   -36,
     -36,   -36,   -36,   -36,   125,   -36,   -36,   -36,   -36,   -36,
     -22,   -36,    -9,   -36,   -36,    -7,   -36,   -36,   -36,   -36,
     -36,   -36,   -36,   -36,    54,   -36,   -36,   -36,   -21,   -36,
     -36,   -10,   -36,   -12,   -36,   -36,    26
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    26,     8,    12,    27,    71,    10,    11,    43,
       3,     7,    74,    15,    16,    45,    28,   147,   163,   177,
      66,    67,    58,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    59,    60,    68,    80,   157,    61,    62,
     141,    17,    63,    64,    65,    88,    89
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      41,     6,    40,    29,    70,   159,     1,    13,    18,    13,
      41,   160,    69,    29,   145,    48,   121,     4,    76,    41,
       9,   122,    29,    79,    75,    81,    82,    19,    69,    84,
      85,    86,     5,    69,     5,    87,    90,    46,    20,   146,
      21,    22,    49,    42,    78,    23,    24,    25,    14,    14,
      14,   113,    50,    51,    47,    14,   115,    19,    52,    53,
      54,    19,    55,    19,    56,    77,    57,   107,    72,   112,
      77,    83,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   161,   142,   167,    18,
     162,   110,   168,    91,    92,   151,   114,    69,   120,   154,
     123,    87,   156,   140,   148,    69,    41,    41,    19,    29,
      29,   152,   153,   108,   109,     5,    73,   143,   165,    20,
     158,    21,    22,   116,   117,   169,    23,    24,    25,   164,
     174,    18,   101,   102,   103,   104,   105,   106,    14,   176,
      44,   171,   103,   104,   105,   106,   125,   175,   155,     0,
      19,    69,   170,    41,     0,   178,    29,     5,   173,     0,
       0,    20,     0,    21,    22,    69,     0,     0,    23,    24,
      25,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,     0,     0,     0,     0,     0,
       0,     0,   149,     0,     0,     0,     0,     0,   150,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   111,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
      49,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      50,    51,   144,     0,     0,     0,    52,    53,    54,    19,
       0,     0,    56,     0,    57,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   118,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   119,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   124,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     166,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,     0,     0,     0,     0,     0,
       0,     0,   172,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106
};

static const yytype_int16 yycheck[] =
{
      12,     3,    12,    12,    25,    24,    41,     1,     1,     1,
      22,    30,    24,    22,     1,    22,    24,     0,    40,    31,
      36,    29,    31,    45,    31,    46,    47,    20,    40,    50,
      51,    52,    27,    45,    27,    56,    57,    25,    31,    26,
      33,    34,     1,    37,     1,    38,    39,    40,    42,    42,
      42,    72,    11,    12,    25,    42,    77,    20,    17,    18,
      19,    20,    21,    20,    23,    23,    25,    25,    22,    71,
      23,    35,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,    26,   109,    26,     1,
      30,    23,    30,    29,    30,   117,    25,   109,    25,   120,
      30,   122,   123,    26,   114,   117,   118,   119,    20,   118,
     119,   118,   119,    29,    30,    27,    28,    19,    32,    31,
     141,    33,    34,    29,    30,    19,    38,    39,    40,   150,
      29,     1,    11,    12,    13,    14,    15,    16,    42,    24,
      15,   163,    13,    14,    15,    16,    92,   168,   122,    -1,
      20,   163,   162,   165,    -1,   177,   165,    27,   165,    -1,
      -1,    31,    -1,    33,    34,   177,    -1,    -1,    38,    39,
      40,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    24,    -1,    -1,    -1,    -1,    -1,    30,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    29,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
       1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      11,    12,    29,    -1,    -1,    -1,    17,    18,    19,    20,
      -1,    -1,    23,    -1,    25,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    26,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    26,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    26,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      26,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    24,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    41,    44,    53,     0,    27,    45,    54,    46,    36,
      50,    51,    47,     1,    42,    56,    57,    84,     1,    20,
      31,    33,    34,    38,    39,    40,    45,    48,    59,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      84,    86,    37,    52,    57,    58,    25,    25,    68,     1,
      11,    12,    17,    18,    19,    21,    23,    25,    65,    76,
      77,    81,    82,    85,    86,    87,    63,    64,    78,    86,
      81,    49,    22,    28,    55,    68,    63,    23,     1,    63,
      79,    81,    81,    35,    81,    81,    81,    81,    88,    89,
      81,    29,    30,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    25,    29,    30,
      23,    29,    45,    81,    25,    81,    29,    30,    26,    26,
      25,    24,    29,    30,    26,    77,    81,    81,    81,    81,
      81,    81,    81,    81,    81,    81,    81,    81,    81,    81,
      26,    83,    63,    19,    29,     1,    26,    60,    84,    24,
      30,    63,    68,    68,    81,    89,    81,    80,    81,    24,
      30,    26,    30,    61,    81,    32,    26,    26,    30,    19,
      84,    63,    24,    68,    29,    81,    24,    62,    63
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    43,    44,    46,    45,    47,    47,    49,    48,    50,
      50,    51,    52,    53,    54,    55,    56,    56,    58,    57,
      57,    59,    59,    61,    60,    62,    60,    60,    63,    63,
      64,    64,    65,    65,    66,    66,    67,    67,    68,    68,
      68,    68,    68,    68,    68,    68,    69,    69,    70,    70,
      71,    72,    73,    74,    75,    76,    76,    77,    77,    78,
      78,    79,    79,    79,    80,    80,    81,    81,    81,    81,
      81,    81,    81,    81,    81,    81,    81,    81,    81,    81,
      81,    81,    81,    81,    81,    81,    81,    81,    82,    83,
      82,    84,    85,    86,    87,    87,    87,    88,    88,    89,
      89
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     0,     6,     2,     0,     0,     3,     3,
       0,     1,     1,     1,     1,     1,     2,     1,     0,     4,
       1,     5,     4,     0,     3,     0,     5,     1,     1,     1,
       4,     6,     1,     1,     4,     6,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     4,     1,     5,     7,
       5,     7,     3,     3,     3,     3,     1,     1,     1,     1,
       3,     1,     3,     1,     1,     3,     3,     2,     2,     2,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     1,     1,     1,     1,     3,     0,
       5,     1,     1,     1,     1,     1,     3,     3,     1,     1,
       3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 3:
#line 96 "analisis_sintactico.y"
                                               {TS_InsertaMARCA();}
#line 1592 "y.tab.c"
    break;

  case 4:
#line 100 "analisis_sintactico.y"
                                            { TS_VaciarENTRADAS();}
#line 1598 "y.tab.c"
    break;

  case 7:
#line 103 "analisis_sintactico.y"
                                               {subprog = 1;}
#line 1604 "y.tab.c"
    break;

  case 8:
#line 103 "analisis_sintactico.y"
                                                                     {subprog = 0;}
#line 1610 "y.tab.c"
    break;

  case 18:
#line 115 "analisis_sintactico.y"
                                    {tipoTmp=atributoAEnum(yyvsp[0].atrib);}
#line 1616 "y.tab.c"
    break;

  case 21:
#line 117 "analisis_sintactico.y"
                                                                       {tipoTmp=atributoAEnum(yyvsp[-4].atrib);TS_InsertaSUBPROG(yyvsp[-3]);}
#line 1622 "y.tab.c"
    break;

  case 22:
#line 118 "analisis_sintactico.y"
                                                            {tipoTmp=atributoAEnum(yyvsp[-3].atrib);TS_InsertaSUBPROG(yyvsp[-2]);}
#line 1628 "y.tab.c"
    break;

  case 23:
#line 119 "analisis_sintactico.y"
                                   {tipoTmp=atributoAEnum(yyvsp[0].atrib);}
#line 1634 "y.tab.c"
    break;

  case 24:
#line 119 "analisis_sintactico.y"
                                                                               {TS_InsertaPARAMF(yyvsp[0]);}
#line 1640 "y.tab.c"
    break;

  case 25:
#line 120 "analisis_sintactico.y"
                                                       {tipoTmp=atributoAEnum(yyvsp[0].atrib);}
#line 1646 "y.tab.c"
    break;

  case 26:
#line 120 "analisis_sintactico.y"
                                                                                                   {TS_InsertaPARAMF(yyvsp[0]);}
#line 1652 "y.tab.c"
    break;

  case 28:
#line 122 "analisis_sintactico.y"
                                            {yyval.lexema = yyvsp[0].lexema;
                                             yyval.dimensiones=0; yyval.TamDimen1=0; yyval.TamDimen2=0;
                                            }
#line 1660 "y.tab.c"
    break;

  case 29:
#line 125 "analisis_sintactico.y"
                                                         {yyval.lexema = yyvsp[0].lexema;}
#line 1666 "y.tab.c"
    break;

  case 30:
#line 126 "analisis_sintactico.y"
                                                                   {yyval.lexema = yyvsp[-3].lexema; 
                                                                    yyval.dimensiones=1;
                                                                    yyval.TamDimen1=atoi(yyvsp[-1].lexema);
                                                                    yyval.TamDimen2=0;}
#line 1675 "y.tab.c"
    break;

  case 31:
#line 131 "analisis_sintactico.y"
                                                   {yyval.lexema = yyvsp[-5].lexema;
                                                    yyval.dimensiones=2;
                                                    yyval.TamDimen1=atoi(yyvsp[-3].lexema);
                                                    yyval.TamDimen2=atoi(yyvsp[-1].lexema);}
#line 1684 "y.tab.c"
    break;

  case 32:
#line 136 "analisis_sintactico.y"
                                             {entradaTS ets = buscarEntrada(yyvsp[0].lexema); yyval = entradaAAtributos(ets);}
#line 1690 "y.tab.c"
    break;

  case 33:
#line 137 "analisis_sintactico.y"
                                                     {yyval = yyvsp[0];}
#line 1696 "y.tab.c"
    break;

  case 34:
#line 138 "analisis_sintactico.y"
                                                                    {entradaTS ets = buscarEntrada(yyvsp[-3].lexema);
                                                                     ets.dimensiones = 0;
                                                                     yyval = entradaAAtributos(ets);}
#line 1704 "y.tab.c"
    break;

  case 35:
#line 142 "analisis_sintactico.y"
                                                    {entradaTS ets = buscarEntrada(yyvsp[-5].lexema);
                                                     ets.dimensiones = 0;
                                                     yyval = entradaAAtributos(ets);}
#line 1712 "y.tab.c"
    break;

  case 46:
#line 155 "analisis_sintactico.y"
                                                                    {procesaSentenciaAsignacion(yyvsp[-3],yyvsp[-1]);}
#line 1718 "y.tab.c"
    break;

  case 48:
#line 157 "analisis_sintactico.y"
                                                                   {procesaSentenciaControl(yyvsp[-2]);}
#line 1724 "y.tab.c"
    break;

  case 49:
#line 159 "analisis_sintactico.y"
                                             {procesaSentenciaControl(yyvsp[-4]);}
#line 1730 "y.tab.c"
    break;

  case 50:
#line 160 "analisis_sintactico.y"
                                                                         {procesaSentenciaControl(yyvsp[-2]);}
#line 1736 "y.tab.c"
    break;

  case 51:
#line 161 "analisis_sintactico.y"
                                                                                {procesaSentenciaControl(yyvsp[-2]);}
#line 1742 "y.tab.c"
    break;

  case 54:
#line 164 "analisis_sintactico.y"
                                                     {procesaSentenciaRetornar(yyvsp[-1]);}
#line 1748 "y.tab.c"
    break;

  case 61:
#line 170 "analisis_sintactico.y"
                                        {TS_InsertaIDENT(yyvsp[0]);}
#line 1754 "y.tab.c"
    break;

  case 62:
#line 171 "analisis_sintactico.y"
                                                                            {TS_InsertaIDENT(yyvsp[0]);}
#line 1760 "y.tab.c"
    break;

  case 64:
#line 174 "analisis_sintactico.y"
                                        {PILARG_insertaARG(yyvsp[0]);}
#line 1766 "y.tab.c"
    break;

  case 65:
#line 175 "analisis_sintactico.y"
                                                                   {PILARG_insertaARG(yyvsp[0]);}
#line 1772 "y.tab.c"
    break;

  case 66:
#line 176 "analisis_sintactico.y"
                                                      {yyval = yyvsp[-1];}
#line 1778 "y.tab.c"
    break;

  case 67:
#line 177 "analisis_sintactico.y"
                                                  {yyval = procesaOperacionNegacion(yyvsp[0]);}
#line 1784 "y.tab.c"
    break;

  case 68:
#line 178 "analisis_sintactico.y"
                                                   {yyval = procesaOperacionMixtaCuandoUnaria(yyvsp[0]);}
#line 1790 "y.tab.c"
    break;

  case 69:
#line 179 "analisis_sintactico.y"
                                                                {yyval = procesaOperacionMixtaCuandoUnaria(yyvsp[0]);}
#line 1796 "y.tab.c"
    break;

  case 70:
#line 180 "analisis_sintactico.y"
                                                             {yyval = procesaOperacionBinariaOMixta(yyvsp[-2],yyvsp[0],yyvsp[-1].atrib);}
#line 1802 "y.tab.c"
    break;

  case 71:
#line 181 "analisis_sintactico.y"
                                                            {yyval = procesaOperacionBinariaOMixta(yyvsp[-2],yyvsp[0],yyvsp[-1].atrib);}
#line 1808 "y.tab.c"
    break;

  case 72:
#line 182 "analisis_sintactico.y"
                                                              {yyval = procesaOperacionBinariaOMixta(yyvsp[-2],yyvsp[0],yyvsp[-1].atrib);}
#line 1814 "y.tab.c"
    break;

  case 73:
#line 183 "analisis_sintactico.y"
                                                            {yyval = procesaOperacionBinariaOMixta(yyvsp[-2],yyvsp[0],yyvsp[-1].atrib);}
#line 1820 "y.tab.c"
    break;

  case 74:
#line 184 "analisis_sintactico.y"
                                                           {yyval = procesaOperacionBinariaOMixta(yyvsp[-2],yyvsp[0],yyvsp[-1].atrib);}
#line 1826 "y.tab.c"
    break;

  case 75:
#line 185 "analisis_sintactico.y"
                                                           {yyval = procesaOperacionBinariaOMixta(yyvsp[-2],yyvsp[0],yyvsp[-1].atrib);}
#line 1832 "y.tab.c"
    break;

  case 76:
#line 186 "analisis_sintactico.y"
                                                            {yyval = procesaOperacionBinariaOMixta(yyvsp[-2],yyvsp[0],yyvsp[-1].atrib);}
#line 1838 "y.tab.c"
    break;

  case 77:
#line 187 "analisis_sintactico.y"
                                                            {yyval = procesaOperacionBinariaOMixta(yyvsp[-2],yyvsp[0],yyvsp[-1].atrib);}
#line 1844 "y.tab.c"
    break;

  case 78:
#line 188 "analisis_sintactico.y"
                                                            {yyval = procesaOperacionBinariaOMixta(yyvsp[-2],yyvsp[0],yyvsp[-1].atrib);}
#line 1850 "y.tab.c"
    break;

  case 79:
#line 189 "analisis_sintactico.y"
                                                             {yyval = procesaOperacionBinariaOMixta(yyvsp[-2],yyvsp[0],yyvsp[-1].atrib);}
#line 1856 "y.tab.c"
    break;

  case 80:
#line 190 "analisis_sintactico.y"
                                                           {yyval = procesaOperacionBinariaOMixta(yyvsp[-2],yyvsp[0],yyvsp[-1].atrib);}
#line 1862 "y.tab.c"
    break;

  case 81:
#line 191 "analisis_sintactico.y"
                                                            {yyval = procesaOperacionBinariaOMixta(yyvsp[-2],yyvsp[0],yyvsp[-1].atrib);}
#line 1868 "y.tab.c"
    break;

  case 82:
#line 192 "analisis_sintactico.y"
                                                             {yyval = procesaOperacionBinariaOMixta(yyvsp[-2],yyvsp[0],yyvsp[-1].atrib);}
#line 1874 "y.tab.c"
    break;

  case 83:
#line 193 "analisis_sintactico.y"
                                                              {yyval = procesaOperacionBinariaOMixta(yyvsp[-2],yyvsp[0],yyvsp[-1].atrib);}
#line 1880 "y.tab.c"
    break;

  case 84:
#line 194 "analisis_sintactico.y"
                                                     {yyval = yyvsp[0];}
#line 1886 "y.tab.c"
    break;

  case 85:
#line 195 "analisis_sintactico.y"
                                            {yyval = yyvsp[0];}
#line 1892 "y.tab.c"
    break;

  case 86:
#line 196 "analisis_sintactico.y"
                                          {yyval = yyvsp[0];}
#line 1898 "y.tab.c"
    break;

  case 88:
#line 198 "analisis_sintactico.y"
                                                          {entradaTS ets = buscarEntrada(yyvsp[-2].lexema);
                                                           procesaLlamadaFuncionSinArgumentos(ets);
                                                           yyval = entradaAAtributos(ets);}
#line 1906 "y.tab.c"
    break;

  case 89:
#line 201 "analisis_sintactico.y"
                                                       {PILARG_insertaMARCA();}
#line 1912 "y.tab.c"
    break;

  case 90:
#line 201 "analisis_sintactico.y"
                                                                                                         {entradaTS ets = buscarEntrada(yyvsp[-4].lexema);
                                                                                                          procesaLlamadaFuncionConArgumentos(ets);
                                                                                                           yyval = entradaAAtributos(ets);}
#line 1920 "y.tab.c"
    break;

  case 91:
#line 204 "analisis_sintactico.y"
                                     {yyval.atrib = yyvsp[0].atrib;}
#line 1926 "y.tab.c"
    break;

  case 94:
#line 207 "analisis_sintactico.y"
                                    {yyval.tipo = atributoAEnum(yyvsp[0].atrib+1);}
#line 1932 "y.tab.c"
    break;

  case 95:
#line 208 "analisis_sintactico.y"
                                          {yyval.tipo = entero;}
#line 1938 "y.tab.c"
    break;

  case 96:
#line 209 "analisis_sintactico.y"
                                                                    { yyval.tipo = yyvsp[-1].tipo;
                                                                    if (yyvsp[-1].TamDimen2==1){yyval.TamDimen2 = 0; yyval.TamDimen1 = yyvsp[-1].TamDimen1; yyval.dimensiones = 1;}
                                                                    else{yyval.TamDimen2 = yyvsp[-1].TamDimen2; yyval.TamDimen1 = yyvsp[-1].TamDimen1; yyval.dimensiones = 2;}}
#line 1946 "y.tab.c"
    break;

  case 97:
#line 212 "analisis_sintactico.y"
                                                                              {yyval.TamDimen2 = yyvsp[-2].TamDimen2 + 1; 

                                                                              if (yyvsp[-2].tipo != yyvsp[0].tipo){
                                                                                printf("[Linea %d]",linea_actual);  
                                                                                printf("ERROR SEMÁNTICO: Matriz con distintos tipos en distintas columnas.\n");
                                                                              }
                                                                              if (yyvsp[-2].TamDimen1 != yyvsp[0].TamDimen1){
                                                                                printf("[Linea %d]",linea_actual);  
                                                                                printf("ERROR SEMÁNTICO: La matriz tiene distinto número de filas en distintas columnas.\n");
                                                                              }else{
                                                                                yyval.TamDimen1 = yyvsp[-2].TamDimen1;
                                                                              }}
#line 1963 "y.tab.c"
    break;

  case 98:
#line 224 "analisis_sintactico.y"
                                                          {yyval.TamDimen2 = 1;yyval.TamDimen1 = yyvsp[0].TamDimen1;yyval.tipo = yyvsp[0].tipo;}
#line 1969 "y.tab.c"
    break;

  case 99:
#line 226 "analisis_sintactico.y"
                                          {yyval.TamDimen1 = 1; yyval.tipo = yyvsp[0].tipo;}
#line 1975 "y.tab.c"
    break;

  case 100:
#line 227 "analisis_sintactico.y"
                                                                         {yyval.TamDimen1 = yyvsp[-2].TamDimen1 + 1;
                                                                          if (yyvsp[-2].tipo != yyvsp[0].tipo){
                                                                                printf("[Linea %d]",linea_actual);  
                                                                                printf("ERROR SEMÁNTICO: Array con distintos tipos.\n");
                                                                          }}
#line 1985 "y.tab.c"
    break;


#line 1989 "y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 234 "analisis_sintactico.y"


#ifdef DOSWINDOWS
#include "lexyy.c"
#else
#include "lex.yy.c"
#endif

void yyerror(char *msg)
{
  fprintf(stderr, "[Linea %d]: %s\n", linea_actual, msg);
}



void PILARG_insertaENTRADA(entradaTS ets){
  
  if (TOPE_ARG == MAX_TS){
    fprintf(stderr, "Error: Se ha alcanzado el máximo tamaño de la pila argumentos. \n ABORTANDO\n");
    exit(-1);
  }else{
    /* Introduzco el valor en la pila y cambio el tope */
    PILA_ARG[TOPE_ARG] = ets;
    TOPE_ARG = TOPE_ARG + 1;
  }
}

void PILARG_insertaMARCA(){

  entradaTS ets;
  ets.entrada = marca;
  ets.nombre = "";
  ets.tipoDato = no_asignado;
  ets.parametros = 0;
  ets.dimensiones = 0;
  ets.TamDimen1 = 0;
  ets.TamDimen2 = 0;
 
  PILARG_insertaENTRADA(ets);
}

void PILARG_insertaARG(atributos arg){
  entradaTS ets;
  ets.tipoDato = arg.tipo;
  ets.dimensiones = arg.dimensiones;
  ets.TamDimen1 = arg.TamDimen1;
  ets.TamDimen2 = arg.TamDimen2;

PILARG_insertaENTRADA(ets);
}

void TS_InsertaENTRADA(entradaTS ets){
  
  if (TOPE == MAX_TS){
    fprintf(stderr, "Error: Se ha alcanzado el máximo tamaño de la tabla de símbolos.\n ABORTANDO\n");
    exit(-1);
  }else{
    /* Introduzco el valor en la pila y cambio el tope */
    TS[TOPE] = ets;
    TOPE = TOPE + 1;
  }

  //mostrar_tabla();
}

void TSAUX_InsertaENTRADA(entradaTS ets){
  if (TOPE_AUX == MAX_TS){
    fprintf(stderr, "Error: Se ha alcanzado el máximo tamaño de la tabla de símbolos.\n ABORTANDO\n");
    exit(-1);
  }else{
    /* Introduzco el valor en la pila y cambio el tope */
    TS_aux[TOPE_AUX] = ets;
    TOPE_AUX = TOPE_AUX + 1;
  }
}

void TS_InsertaMARCA(){

  entradaTS ets;
  ets.entrada = marca;
  ets.nombre = "";
  ets.tipoDato = no_asignado;
  ets.parametros = 0;
  ets.dimensiones = 0;
  ets.TamDimen1 = 0;
  ets.TamDimen2 = 0;
 
  TS_InsertaENTRADA(ets);

  entradaTS ets_aux;
  if (subprog == 1){ 
    unsigned int i = 0;
    /* INserto parametros formales */
    while (i < TOPE_AUX){
      ets_aux = TS_aux[i];
      ets_aux.entrada = variable;
      TS_InsertaENTRADA(ets_aux);
      i++;
    }
    TOPE_AUX = 0;
  }
}


void TS_InsertaIDENT(atributos atr){

  entradaTS ets;
  ets.entrada = variable;
  ets.nombre = atr.lexema;
  ets.tipoDato = tipoTmp;
  ets.parametros = 0;
  ets.dimensiones = atr.dimensiones;
  ets.TamDimen1 = atr.TamDimen1;
  ets.TamDimen2 = atr.TamDimen2;

  int tope_aux = TOPE-1;

  while (tope_aux > 0 ){
    if (strcmp(TS[tope_aux].nombre,ets.nombre) == 0){
      printf("[Linea %d]",linea_actual);   printf("ERROR SEMÁNTICO: Doble declaración de la variable '%s'\n",ets.nombre);
    }

    if (TS[tope_aux].entrada == marca) break;
    tope_aux--;
  }

  TS_InsertaENTRADA(ets);
}



void TS_VaciarENTRADAS(){

  if (TOPE == 0) fprintf(stderr, "Error: intenta vaciar tabla de símbolos vacía\n");

  while (TS[TOPE-1].entrada != marca) TOPE--;

  if (TOPE > 0){
    TOPE--;
    int iaux = TOPE-1;
    if (iaux > 0){
      while (TS[iaux].entrada != funcion){TS[iaux].valido = -1;iaux--;}
      TS[iaux].valido = -1;
    }
  }else{
    fprintf(stderr, "Error: No se encontró marca al vaciar tabla de símbolos\n");
  }
}



void TS_InsertaSUBPROG(atributos atr){

  entradaTS ets;
  ets.entrada = funcion;
  ets.nombre = atr.lexema;
  ets.tipoDato = tipoTmp;
  ets.parametros = TOPE_AUX;
  ets.dimensiones = atr.dimensiones;
  ets.TamDimen1 = atr.TamDimen1;
  ets.TamDimen2 = atr.TamDimen2;

  unsigned int i = 0;


  TS_InsertaENTRADA(ets);
  
  /* INserto parametros formales */
  while (i < TOPE_AUX){
    TS_InsertaENTRADA(TS_aux[i]);
    i++;
  }
 
}


void TS_InsertaPARAMF(atributos atr){

  entradaTS ets;
  ets.entrada = parametro_formal;
  ets.nombre = atr.lexema;
  ets.tipoDato = tipoTmp;
  ets.parametros = 0;
  ets.dimensiones = atr.dimensiones;
  ets.TamDimen1 = atr.TamDimen1;
  ets.TamDimen2 = atr.TamDimen2;
  

  int tope_aux = TOPE_AUX - 1;

  while (tope_aux >= 0){
    if (strcmp(TS_aux[tope_aux].nombre,ets.nombre) == 0){
     printf("[Linea %d]",linea_actual);   printf("ERROR SEMÁNTICO:se ha encontrado otro parámetro formal con el mismo identificador: '%s'\n", ets.nombre);
    }
    tope_aux--;
  }

  TSAUX_InsertaENTRADA(ets);
}




entradaTS buscarEntrada(char* nombre){
  entradaTS ets;

  int i = TOPE-1;
  
  while (i>=0){
    if (strcmp(TS[i].nombre,nombre) == 0) break;
    i--;
  }

  if (i == -1){
    printf("[Linea %d]",linea_actual);   printf("ERROR SEMÁNTICO: se utiliza un identificador no declarado: '%s'\n", nombre);
    ets.nombre = strdup("");
  }else{
    ets = TS[i];
  }

  return ets;
}


atributos entradaAAtributos(entradaTS ets){
  atributos atr; 
  atr.tipo = ets.tipoDato; 
  atr.dimensiones = ets.dimensiones;
  atr.TamDimen1 = ets.TamDimen1;
  atr.TamDimen2 = ets.TamDimen2;

  return atr;
}



atributos procesaOperacionBinariaOMixta(atributos op1, atributos op2, int opdor){

  atributos atr;

  //printf("[Linea %d]",linea_actual);
  //printf("OP1: tipo:%s dim:%d t1:%d t2:%d  OP2: tipo:%s dim:%d t1:%d t2:%d\n",enumAChar(op1.tipo),op1.dimensiones,op1.TamDimen1,op1.TamDimen2,enumAChar(op2.tipo),op2.dimensiones,op2.TamDimen1,op2.TamDimen2);

  // Caso (+,*)
  if (opdor == 0){
    if ((op1.tipo != entero && op1.tipo != real) || (op2.tipo != entero && op2.tipo != real)){
      printf("[Linea %d]",linea_actual);   printf("ERROR SEMÁNTICO: El operador (+|*) espera tipo entero/real\n");
    }
    
    if (op1.tipo != op2.tipo){
      printf("[Linea %d]",linea_actual);   printf("ERROR SEMÁNTICO: Se intenta operar con expresiones de distinto tipo.\n");
    }
    if( (op1.dimensiones==1 && op2.dimensiones==2) ||
              (op1.dimensiones==2 && op2.dimensiones==1)){
      printf("[Linea %d]",linea_actual);   printf("ERROR SEMÁNTICO: Se intenta operar con una array y una matriz.\n");
    }
    if (op1.dimensiones==0){
      atr = op2;
    }else if (op2.dimensiones==0){
      atr = op1;
    }
    if (op1.dimensiones==1 && op2.dimensiones==1){
      if (op1.TamDimen1 == op2.TamDimen1) atr = op1;
      else {
        printf("[Linea %d]",linea_actual);   printf("ERROR SEMÁNTICO: Se intenta operar con arrays de distintos tamaños.\n");
      }
    }else if(op1.dimensiones==2 && op2.dimensiones==2){
      if (op1.TamDimen1 == op2.TamDimen1 && op1.TamDimen2 == op2.TamDimen2) atr = op1;
      else {
        printf("[Linea %d]",linea_actual);   printf("ERROR SEMÁNTICO: Se intenta operar con matrices de distintos tamaños.\n");
      }
    }
  }
  
  // Caso (-,/)
  if (opdor == 1){
    if ((op1.tipo != entero && op1.tipo != real) || (op2.tipo != entero && op2.tipo != real)){
      printf("[Linea %d]",linea_actual);   printf("ERROR SEMÁNTICO: El operador (-|/) espera tipo entero/real\n");
    }
    
    if (op1.tipo != op2.tipo){
      printf("[Linea %d]",linea_actual);   printf("ERROR SEMÁNTICO: Se intenta operar con expresiones de distinto tipo.\n");
    }
    if( (op1.dimensiones==1 && op2.dimensiones==2) ||
              (op1.dimensiones==2 && op2.dimensiones==1)){
      printf("[Linea %d]",linea_actual);   printf("ERROR SEMÁNTICO: Se intenta operar con una array y una matriz.\n");
    }
    if (op1.dimensiones==0 && op2.dimensiones != 0){
      printf("[Linea %d]",linea_actual);   printf("ERROR SEMÁNTICO: No se puede restar/dividir un array/matriz a un valor.\n");
    }else if (op2.dimensiones==0){
      atr = op1;
    }
    if (op1.dimensiones==1 && op2.dimensiones==1){
      if (op1.TamDimen1 == op2.TamDimen1) atr = op1;
      else{
        printf("[Linea %d]",linea_actual);   printf("ERROR SEMÁNTICO: Se intenta operar con arrays de distintos tamaños.\n");
      }
    }else if(op1.dimensiones==2 && op2.dimensiones==2){
      if (op1.TamDimen1 == op2.TamDimen1 && op1.TamDimen2 == op2.TamDimen2) atr = op1;
      else {
        printf("[Linea %d]",linea_actual);   printf("ERROR SEMÁNTICO: Se intenta operar con matrices de distintos tamaños.\n");
      }
    }
  }

  // Caso **
  if (opdor == 2){
    if ((op1.tipo != entero && op1.tipo != real) || (op2.tipo != entero && op2.tipo != real)){
      printf("[Linea %d]",linea_actual);   printf("ERROR SEMÁNTICO: El operador ** espera tipo entero/real\n");
    }
    if (op1.tipo != op2.tipo){
      printf("[Linea %d]",linea_actual);   printf("ERROR SEMÁNTICO: Se intenta operar con expresiones de distinto tipo.\n");
    }
    if (op1.dimensiones == 1 || op1.dimensiones == 0){
      printf("[Linea %d]",linea_actual);   printf("ERROR SEMÁNTICO: El operador ** espera matrices\n");
    }
    if (op2.dimensiones == 1 || op2.dimensiones == 0){
      printf("[Linea %d]",linea_actual);   printf("ERROR SEMÁNTICO: El operador ** espera matrices\n");
    }
    if (op1.dimensiones == 2 && op2.dimensiones ==2){
      if (op1.TamDimen2 != op2.TamDimen1){
        printf("[Linea %d]",linea_actual);   printf("ERROR SEMÁNTICO: Multiplicación de matrices inválida. No se puede multiplicar dimensiones (%dX%d)**(%dX%d)\n",op1.TamDimen1,op1.TamDimen2,op2.TamDimen1,op2.TamDimen2);
      }else{
        atr = op1;
        atr.TamDimen2 = op2.TamDimen2;
      }
    }
  }

  // Caso (&&,||)
  if (opdor == 3  || opdor == 4){
    if (op1.dimensiones != 0 || op2.dimensiones != 0){
      printf("[Linea %d]",linea_actual);   printf("ERROR SEMÁNTICO: No se puede utilizar el operador (&&,||) con arrays/matrices.\n");
    }else if (op1.tipo != booleano || op2.tipo != booleano){
      printf("[Linea %d]",linea_actual);   printf("ERROR SEMÁNTICO: El operador (&&,||) espera tipo booleano\n");
    }else{
      atr = op1;
    }
  }

  // Caso == y !=
  if (opdor == 5 || opdor == 6){
    if (op1.dimensiones != 0 || op2.dimensiones != 0){
      printf("[Linea %d]",linea_actual);   printf("ERROR SEMÁNTICO: No se puede comparar arrays/matrices.\n");
    }else if(op1.tipo != op2.tipo){
      printf("[Linea %d]",linea_actual);   printf("ERROR SEMÁNTICO: No se puede comparar expresiones de distinto tipo\n");
    }else{
      atr = op1;
      atr.tipo = booleano;
    }
  }

  // Caso operador relacional >,<,>=,...
  if (opdor >= 7 && opdor <= 10){
    if (op1.dimensiones != 0 || op2.dimensiones != 0){
      printf("[Linea %d]",linea_actual);   printf("ERROR SEMÁNTICO: No se puede utilizar un operador relacional con arrays/matrices.\n");
    }
    if ((op1.tipo != entero && op1.tipo != real) || (op2.tipo != entero && op2.tipo != real)){
      printf("[Linea %d]",linea_actual);   printf("ERROR SEMÁNTICO: El operador ** espera tipo entero/real\n");
    }

    if (op1.tipo != op2.tipo){
      printf("[Linea %d]",linea_actual);   printf("ERROR SEMÁNTICO: Se intenta operar con expresiones de distinto tipo.\n");
    }else if(op1.dimensiones == 0 && op2.dimensiones == 0){
      atr = op1;
      atr.tipo = booleano;
    }
  }

  // Caso módulo %
  if (opdor == 11){
    if (op1.dimensiones != 0 || op2.dimensiones != 0){
      printf("[Linea %d]",linea_actual);   printf("ERROR SEMÁNTICO: No se puede hacer módulo de arrays/matrices.\n");
    }else if(op1.tipo != entero || op2.tipo != entero){
      printf("[Linea %d]",linea_actual);   printf("ERROR SEMÁNTICO: El operador módulo espera dos enteros.\n");
    }else{
      atr = op1;
    }
  }

  //printf("RES: tipo:%s dim:%d t1:%d t2:%d\n",enumAChar(atr.tipo),atr.dimensiones,atr.TamDimen1,atr.TamDimen2);
  return atr;
}

atributos procesaOperacionMixtaCuandoUnaria(atributos op1){

  atributos atr;

  if (op1.dimensiones != 0){
      printf("[Linea %d]",linea_actual);   printf("ERROR SEMÁNTICO: El operador unario (+ | -) no espera un array o matriz.\n");
  }

  if (op1.tipo != entero && op1.tipo != real){
      printf("[Linea %d]",linea_actual);   printf("ERROR SEMÁNTICO: El operador unario (+ | -) espera tipo real o entero.\n");
  }
  
  if ((op1.tipo == entero || op1.tipo == real) && op1.dimensiones == 0){
    atr = op1;
  }

  return atr;
}

atributos procesaOperacionNegacion(atributos op1){

  atributos atr;

  if (op1.tipo != booleano){
    printf("[Linea %d]",linea_actual);   printf("ERROR SEMÁNTICO: El operador de negación espera un booleano.\n");
  }

  if (op1.dimensiones != 0){ 
    printf("[Linea %d]",linea_actual);   printf("ERROR SEMÁNTICO: El operador de negación no espera un array o matriz.\n");
  }

  if (op1.dimensiones == 0 && op1.tipo == booleano){
    atr = op1;
  }

  return atr;
}




void procesaLlamadaFuncionConArgumentos(entradaTS ets){

  int i = TOPE-1;
  int indice_args;
  int n_params = 0;
  int indice_borrado;
  while (i>=0){
    if (strcmp(TS[i].nombre,ets.nombre) == 0) break;
    i--;
  }

  if (i >= 0){
    indice_args = TOPE_ARG-1;

    while (PILA_ARG[indice_args].entrada != marca){indice_args--;}
    indice_borrado = indice_args;
    indice_args++;
  
    if (indice_args == 0){
      printf("ERROR: No hay argumentos en la llamada de la función %s.\n",ets.nombre);
    }else{
      i = i + 1;
      while (TS[i].entrada == parametro_formal && i < TOPE && indice_args < TOPE_ARG){
        if (TS[i].tipoDato != PILA_ARG[indice_args].tipoDato){
          printf("[Linea %d]",linea_actual); printf("ERROR SEMÁNTICO: Argumento de la llamada a %s numero %d es de tipo distinto al esperado.\n",ets.nombre,n_params+1);
        }
        if (TS[i].dimensiones != PILA_ARG[indice_args].dimensiones){
          printf("[Linea %d]",linea_actual); printf("ERROR SEMÁNTICO: Argumento de la llamada a %s numero %d tiene dimensiones distintas a las esperadas.\n",ets.nombre,n_params+1);
        }else{
          if (TS[i].dimensiones == 1){
            if (TS[i].TamDimen1 != PILA_ARG[indice_args].TamDimen1){
              printf("[Linea %d]",linea_actual); printf("ERROR SEMÁNTICO: Argumento de la llamada a %s numero %d tiene dimension 1 distinta al esperado.\n",ets.nombre,n_params+1);
            }
          }

          if (TS[i].dimensiones == 2){
            if (TS[i].TamDimen1 != PILA_ARG[indice_args].TamDimen1){
              printf("[Linea %d]",linea_actual); printf("ERROR SEMÁNTICO: Argumento de la llamada a %s numero %d tiene dimension 1 distinta al esperado.\n",ets.nombre,n_params+1);
            }

            if (TS[i].TamDimen2 != PILA_ARG[indice_args].TamDimen2){
              printf("[Linea %d]",linea_actual); printf("ERROR SEMÁNTICO: Argumento de la llamada a %s numero %d tiene dimension 2 distinta al esperado.\n",ets.nombre,n_params+1);
            }
          }

        }
        
        i = i + 1;
        indice_args = indice_args + 1;
        n_params = n_params + 1;
      }
      if (indice_args != TOPE_ARG){
          printf("[Linea %d]",linea_actual); printf("ERROR SEMÁNTICO: Se han pasado más argumentos de los esperados a la funcion %s.\n",ets.nombre); 
      }
      if (ets.parametros > n_params){
          printf("[Linea %d]",linea_actual); printf("ERROR SEMÁNTICO: Se han pasado menos argumentos de los esperados a la funcion %s.\n",ets.nombre);  
      }
    }
  }

  TOPE_ARG = indice_borrado;
}

void procesaLlamadaFuncionSinArgumentos(entradaTS ets){
  if (ets.parametros > 0){
      printf("[Linea %d]",linea_actual); printf("ERROR SEMÁNTICO: Se han pasado 0 argmuentos a la funcion %s, se esperan más.\n",ets.nombre);  
  }
}




void procesaSentenciaAsignacion(atributos op1, atributos op2){
  if (op1.tipo != op2.tipo){
    printf("[Linea %d]",linea_actual);   printf("ERROR SEMÁNTICO: Asignacion de tipos distintos.\n");
  }
  if (op1.dimensiones != op2.dimensiones){
    printf("[Linea %d]",linea_actual);   printf("ERROR SEMÁNTICO: Asignacion variables con dimensiones distintas.\n");
  }else{
    if (op1.dimensiones == 1){
      if (op1.TamDimen1 != op2.TamDimen1){
        printf("[Linea %d]",linea_actual);   printf("ERROR SEMÁNTICO: Asignacion de arrays de distinto tamaño.\n");
      }
    }
    if (op1.dimensiones == 2){
      if ((op1.TamDimen1 != op2.TamDimen1) || (op1.TamDimen2 != op2.TamDimen2)){
        printf("[Linea %d]",linea_actual);   printf("ERROR SEMÁNTICO: Asignacion de matrices de distintos tamaños.\n");
      }
    }
  }
}

void procesaSentenciaControl(atributos exp){
  if (exp.tipo != booleano){
    printf("[Linea %d]",linea_actual);   printf("ERROR SEMÁNTICO: La sentencia de control (si|mientras|hasta) espera una expresión booleana.\n");
  }
}

void procesaSentenciaRetornar(atributos ret){

  int i = TOPE-1;
  
  while (i>=1){
    if (TS[i].entrada == marca && TS[i-1].valido != -1 && ((TS[i-1].entrada == parametro_formal || TS[i-1].entrada == funcion))) break;
    i--;
  }

  if (i == 0){
      printf("[Linea %d]",linea_actual);   printf("ERROR SEMÁNTICO: No se deben retornar valores en el programa principal.\n");
  }else{
     while (i>=0){
       if (TS[i].entrada == funcion) break;
        i--;
     }
     if (i == 0){
     	printf("[Linea %d]",linea_actual);   printf("ERROR SEMÁNTICO: no se encontró la función del devolver en el analisis semántico\n");
     	return;
     }
     if (TS[i].tipoDato != ret.tipo){
     	printf("[Linea %d]",linea_actual);   printf("ERROR SEMÁNTICO: El valor retornado no se corresponde con el que devuelve la función.\n");
     }
  }
}

dtipo atributoAEnum(int atr){

  if (atr == 0) return entero;
  if (atr == 1) return real;
  if (atr == 2) return caracter;
  if (atr == 3) return booleano;
  printf("ERROR: Atributo de tipo no válido: atributo == %d\n", atr);
}

/****************************************************************************************/
void mostrar_tabla(){

  unsigned int entrada = 0;

  printf("-------------------TABLA-------------------\n");
  printf("entrada\tnombre\ttipoDato\tparametros\tdimensiones\tTamDimen1\tTamDimen2\n");

  while (entrada < TOPE){
    printf("%s\n",entrada_a_string(TS[entrada]));
    entrada++;
  }

  printf("\n\n");

}

char* entrada_a_string(entradaTS es){

  char salida[2000];
  char formato[] = "%s \t%s \t%s \t%d \t%d \t%d \t%d";
  char* c1, *c2, *c3;
  unsigned int c4,c5,c6,c7;

  if (es.entrada == marca) c1 = "marca";
  else if (es.entrada == funcion) c1 = "funcion";
  else if (es.entrada == variable) c1 = "variable";
  else if (es.entrada == parametro_formal) c1 = "paramFormal";

  
  if (es.tipoDato == booleano) c3 = "booleano";
  else if (es.tipoDato == entero) c3 = "entero";
  else if (es.tipoDato == real) c3 = "real";
  else if (es.tipoDato == caracter) c3 = "caracter";
  else if (es.tipoDato == desconocido) c3 = "desconocido";
  else if (es.tipoDato == no_asignado) c3 = "no asignado";
  c4 = es.parametros;
  c5 = es.dimensiones;
  c6 = es.TamDimen1;
  c7 = es.TamDimen2;
  sprintf(salida,formato,c1,es.nombre,c3,c4,c5,c6,c7);
  return strdup(salida);  
}


char* enumAChar(dtipo t){

  if (t == entero)return strdup("entero");
  if (t == booleano)return strdup("booleano");
  if (t == real)return strdup("real");
  if (t == caracter)return strdup("char");

  return strdup("Ninguno");
}
