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
#line 1 "analizador_yacc.y"


#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "estructurasTS.h"
void yyerror(char * msg);

int linea_actual = 1;
int nivel_profundidad_funciones_anidadas = 0;
int funciones_anidadas = 0;

#define MAX_TS 500

unsigned int TOPE = 0; /* Tope de la pila */
unsigned int subprog;  /* Indicador de comienzo de bloque de subprog */
dtipo tipoTmp;

entradaTS TS[MAX_TS];  /* TABLA DE SÍMBOLOS */
entradaTS TS_aux[MAX_TS]; /* Tabla auxiliar para paramf */
int TOPE_AUX = 0;
int TOPE_ARG = 0;

entradaTS PILA_ARG[MAX_TS];


/* GENERACIÓN DE CÓDIGO */

char VACIO[5] = "";

FILE* intermain;
FILE* dec_fun_c;
FILE* dec_fun_h;


/*                      */
int Ntmp = 0;
int Netiqueta = 0;
int noBloqueMain = 0; // Estamos en el bloque main
char* paux;
char* textoPrintf = NULL;
char* textoScanf = NULL;


#define cod_fun codigo
typedef struct{
  int atrib;
  char* lexema;
  dtipo tipo;
  unsigned int dimensiones;
  int TamDimen1;
  int TamDimen2;

  char* nombreTmp;
  char* codigo;
  //char* cod_fun;
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

/*
  FUNCIONES PARA GENERAR CODIGO
*/
void empezarGEN();
void finalizarGEN();
char* temporal();
char* etiqueta();

char* enumAString();
char* enumATipoForm(dtipo t);


void genCodigoOperadorBin(atributos* obj, atributos* at1, atributos* at2, int opdor);
void genCodigoOperadorMix(atributos* obj, atributos* at1, atributos* at2, int opdor);
void genCodigoOperadorUn(atributos* obj, atributos* at1, int opdor);
void genCodigoOperadorUnNeg(atributos* obj, atributos* at1);

void genCodigoAsignacion(atributos*, atributos*, atributos*);
void genCodigoSino(atributos* ,atributos*,atributos*,atributos*);
void genCodigoSi(atributos* ,atributos*,atributos*);
void genCodigoMientras(atributos* obj,atributos* cond,atributos* sent);
void genCodigoHacerHasta(atributos* obj,atributos* cond,atributos* sent);

char* opdorUnAString(int opdor);
char* opdorBinAString(int opdor);

void mystrcat(char**,char**);
void mystrcpy(char**,char**);


#line 201 "y.tab.c"

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
#define YYLAST   439

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  43
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  49
/* YYNRULES -- Number of rules.  */
#define YYNRULES  102
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  181

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
static const yytype_int16 yyrline[] =
{
       0,   150,   150,   150,   157,   158,   157,   197,   198,   199,
     199,   202,   214,   225,   226,   227,   228,   229,   230,   247,
     260,   260,   281,   282,   283,   284,   284,   285,   285,   286,
     287,   304,   305,   309,   315,   318,   319,   322,   326,   343,
     355,   367,   383,   399,   415,   431,   447,   463,   474,   475,
     476,   478,   480,   482,   483,   504,   526,   527,   548,   561,
     579,   596,   621,   650,   664,   683,   684,   697,   715,   716,
     717,   718,   719,   720,   721,   722,   723,   724,   725,   726,
     727,   728,   729,   730,   731,   732,   733,   746,   759,   788,
     789,   808,   808,   831,   832,   843,   854,   866,   878,   881,
     893,   895,   896
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
  "$accept", "Programa", "$@1", "bloque", "$@2", "$@3", "Declar_subprogs",
  "Declar_subprog", "$@4", "Declar_de_variables_locales",
  "Marca_ini_declar_variables", "Marca_fin_declar_variables",
  "Cabecera_programa", "Inicio_de_bloque", "Fin_de_bloque",
  "Variables_locales", "Cuerpo_declar_variables", "$@5",
  "Cabecera_subprog", "argumentos", "$@6", "$@7", "variable",
  "elemento_de_array_decl", "variable_expresion", "elemento_de_array",
  "Sentencias", "Sentencia", "sentencia_asignacion", "sentencia_si",
  "sentencia_mientras", "sentencia_hacer_hasta", "sentencia_entrada",
  "sentencia_salida", "sentencia_retornar", "lista_expresiones_cadena",
  "expresion_cadena", "lista_variables", "lista_declaracion_variables",
  "lista_expresiones", "expresion", "funcion", "$@8", "tipo", "cadena",
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

#define YYPACT_NINF (-35)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -34,   -35,    22,   -35,   -35,   -12,   -35,   -35,   -35,    17,
     -35,   -35,    18,   -35,   -35,   -35,    15,   -35,   -35,     9,
     -35,   -35,   -35,     5,   -35,   -35,    31,    36,    49,   254,
       4,   269,   -35,   -35,   -35,    37,   -35,   138,   -35,   -35,
     -35,   -35,   -35,   -35,   -35,   -35,     4,    16,   -35,   -35,
     -35,    34,    43,   269,   269,    35,   -35,   269,   269,   269,
     -35,   -35,   -35,   269,   269,   -35,    45,   -35,   410,   -35,
     -35,    21,   -35,   -35,    63,   211,   -12,   269,   -35,   -35,
     -35,    56,   269,   -35,     4,    65,   292,   316,    61,    95,
     -35,   -35,   410,    -1,    60,   340,   -35,   254,   269,   269,
     269,   269,   269,   269,   269,   269,   269,   269,   269,   269,
     269,   269,    68,   -35,     4,   -35,   -35,   238,    12,   183,
     -35,    -4,    49,    49,   269,   -35,   269,   269,   -35,   -35,
     423,   223,   119,   119,    19,    19,    19,    19,    95,    95,
     -35,   -35,   -35,   -35,   -35,   269,   -35,   -35,   -35,   -35,
      11,   -35,   -35,   269,   -35,    78,    66,   -35,   364,    60,
     410,    32,   410,   -35,   100,     4,   388,    81,    49,    73,
     -35,   269,   -35,   -35,   -35,   -35,   -35,   -35,   410,     4,
     -35
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    15,     0,     2,     1,     0,    16,     3,     4,    12,
      13,     5,     0,     8,    22,    93,     0,    19,    20,     0,
      14,    11,    18,     0,    49,    95,     0,     0,     0,     0,
       0,     0,    40,     7,     9,     0,    35,     0,    39,    41,
      42,    43,    44,    45,    46,    47,     0,    34,    65,    63,
      31,     0,    30,     0,     0,     0,    89,     0,     0,     0,
      96,    97,    94,     0,     0,    86,     0,    58,    59,    88,
      60,    34,    87,    61,     0,     0,     0,     0,    17,     6,
      38,     0,     0,    21,     0,     0,     0,     0,     0,    70,
      71,    69,   101,     0,   100,     0,    55,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    91,    54,     0,    56,    10,     0,     0,     0,
      64,     0,     0,     0,     0,    98,     0,     0,    68,    57,
      76,    75,    77,    78,    79,    80,    81,    82,    84,    85,
      72,    74,    73,    83,    90,     0,    62,    48,    29,    24,
       0,    25,    36,     0,    32,     0,    50,    52,     0,    99,
     102,     0,    66,    23,     0,     0,     0,     0,     0,     0,
      92,     0,    27,    26,    37,    33,    51,    53,    67,     0,
      28
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -35,   -35,   -35,     3,   -35,   -35,   -35,   -35,   -35,   -35,
     -35,   -35,   -35,   -35,   -35,   -35,   121,   -35,   -35,   -35,
     -35,   -35,   -29,   -35,   -16,   -35,   -35,   -23,   -35,   -35,
     -35,   -35,   -35,   -35,   -35,   -35,    46,   -35,   -35,   -35,
      14,   -35,   -35,   -17,   -35,   -19,   -35,   -35,    25
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     5,    32,     9,    13,    19,    33,    76,    11,
      12,    21,     3,     8,    79,    16,    17,    23,    34,   150,
     165,   179,    49,    50,    65,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    66,    67,    74,    51,   161,
      68,    69,   145,    18,    70,    71,    72,    93,    94
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      47,    73,    46,    35,    52,    55,    48,     1,     7,    47,
      24,    52,    35,   148,    80,     6,    14,    81,    47,    14,
     154,    35,     4,   125,    25,    25,   155,    52,   126,    25,
     106,   107,   108,   109,   110,   111,     6,   163,   149,    82,
      26,   164,    27,    28,    82,    75,   112,    29,    30,    31,
      24,    15,    20,    10,    15,   120,    53,    15,   170,    77,
      15,    54,   171,    83,    84,    52,    85,    86,    87,    25,
      88,    89,    90,    91,    96,    97,     6,    92,    95,   116,
      26,   118,    27,    28,   121,   146,   124,    29,    30,    31,
     127,   117,   113,   114,   144,    52,   119,   167,   168,   156,
     157,   151,   177,    47,    47,   175,    35,    35,   108,   109,
     110,   111,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   173,    22,   158,    24,
      92,   160,    15,   129,     0,   176,    52,   172,     0,    47,
     180,   159,    35,     0,     0,     0,     0,     0,    25,   162,
      52,     0,     0,     0,     0,     6,    78,   166,     0,    26,
       0,    27,    28,     0,     0,     0,    29,    30,    31,     0,
       0,     0,     0,     0,     0,   178,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
       0,     0,     0,     0,     0,     0,     0,   152,     0,     0,
       0,     0,     0,   153,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     115,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,    56,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    57,    58,   147,     0,     0,
      56,    59,    60,    61,    25,    62,     0,    63,     0,    64,
      57,    58,     0,     0,     0,     0,    59,    60,    61,    25,
       0,     0,    63,     0,    64,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   122,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   123,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   128,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     169,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,     0,     0,     0,     0,     0,
       0,     0,   174,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111
};

static const yytype_int16 yycheck[] =
{
      19,    30,    19,    19,    23,    28,     1,    41,     5,    28,
       1,    30,    28,     1,    37,    27,     1,    46,    37,     1,
      24,    37,     0,    24,    20,    20,    30,    46,    29,    20,
      11,    12,    13,    14,    15,    16,    27,    26,    26,    23,
      31,    30,    33,    34,    23,    31,    25,    38,    39,    40,
       1,    42,    37,    36,    42,    84,    25,    42,    26,    22,
      42,    25,    30,    29,    30,    84,    23,    53,    54,    20,
      35,    57,    58,    59,    29,    30,    27,    63,    64,    76,
      31,    25,    33,    34,    19,   114,    25,    38,    39,    40,
      30,    77,    29,    30,    26,   114,    82,    19,    32,   122,
     123,   118,    29,   122,   123,    24,   122,   123,    13,    14,
      15,    16,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,   165,    16,   124,     1,
     126,   127,    42,    97,    -1,   168,   165,   164,    -1,   168,
     179,   126,   168,    -1,    -1,    -1,    -1,    -1,    20,   145,
     179,    -1,    -1,    -1,    -1,    27,    28,   153,    -1,    31,
      -1,    33,    34,    -1,    -1,    -1,    38,    39,    40,    -1,
      -1,    -1,    -1,    -1,    -1,   171,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    24,    -1,    -1,
      -1,    -1,    -1,    30,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      29,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,     1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    11,    12,    29,    -1,    -1,
       1,    17,    18,    19,    20,    21,    -1,    23,    -1,    25,
      11,    12,    -1,    -1,    -1,    -1,    17,    18,    19,    20,
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
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    41,    44,    55,     0,    45,    27,    46,    56,    47,
      36,    52,    53,    48,     1,    42,    58,    59,    86,    49,
      37,    54,    59,    60,     1,    20,    31,    33,    34,    38,
      39,    40,    46,    50,    61,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    86,    88,     1,    65,
      66,    81,    88,    25,    25,    70,     1,    11,    12,    17,
      18,    19,    21,    23,    25,    67,    78,    79,    83,    84,
      87,    88,    89,    65,    80,    83,    51,    22,    28,    57,
      70,    65,    23,    29,    30,    23,    83,    83,    35,    83,
      83,    83,    83,    90,    91,    83,    29,    30,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    25,    29,    30,    29,    46,    83,    25,    83,
      65,    19,    26,    26,    25,    24,    29,    30,    26,    79,
      83,    83,    83,    83,    83,    83,    83,    83,    83,    83,
      83,    83,    83,    83,    26,    85,    65,    29,     1,    26,
      62,    86,    24,    30,    24,    30,    70,    70,    83,    91,
      83,    82,    83,    26,    30,    63,    83,    19,    32,    26,
      26,    30,    86,    65,    24,    24,    70,    29,    83,    64,
      65
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    43,    45,    44,    47,    48,    46,    49,    49,    51,
      50,    52,    52,    53,    54,    55,    56,    57,    58,    58,
      60,    59,    59,    61,    61,    63,    62,    64,    62,    62,
      65,    65,    66,    66,    67,    67,    68,    68,    69,    69,
      70,    70,    70,    70,    70,    70,    70,    70,    71,    71,
      72,    72,    73,    74,    75,    76,    77,    78,    78,    79,
      79,    80,    80,    81,    81,    81,    82,    82,    83,    83,
      83,    83,    83,    83,    83,    83,    83,    83,    83,    83,
      83,    83,    83,    83,    83,    83,    83,    83,    83,    83,
      84,    85,    84,    86,    87,    88,    89,    89,    89,    90,
      90,    91,    91
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     3,     0,     0,     7,     2,     0,     0,
       3,     3,     0,     1,     1,     1,     1,     1,     2,     1,
       0,     4,     1,     5,     4,     0,     3,     0,     5,     1,
       1,     1,     4,     6,     1,     1,     4,     6,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     4,     1,
       5,     7,     5,     7,     3,     3,     3,     3,     1,     1,
       1,     1,     3,     1,     3,     1,     1,     3,     3,     2,
       2,     2,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     1,     1,     1,     1,
       3,     0,     5,     1,     1,     1,     1,     1,     3,     3,
       1,     1,     3
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
  case 2:
#line 150 "analizador_yacc.y"
                                                {empezarGEN();}
#line 1654 "y.tab.c"
    break;

  case 3:
#line 150 "analizador_yacc.y"
                                                                       {
                                                                        fputs(yyvsp[0].codigo,intermain);
                                                                        if(funciones_anidadas > 0)
                                                                        {
                                                                          fputs(yyvsp[0].cod_fun,intermain);
                                                                        }
                                                                        finalizarGEN();}
#line 1666 "y.tab.c"
    break;

  case 4:
#line 157 "analizador_yacc.y"
                                               {TS_InsertaMARCA();}
#line 1672 "y.tab.c"
    break;

  case 5:
#line 158 "analizador_yacc.y"
                                                              {
                                                                char** codigo3 = &yyvsp[0].codigo;
                                                                if (nivel_profundidad_funciones_anidadas != 0)
                                                                {
                                                                  codigo3 = &yyvsp[0].cod_fun;
                                                                }
                                                                if (noBloqueMain == 0){
                                                                  noBloqueMain = 1;
                                                                  paux = strdup("\n");
                                                                  mystrcat(codigo3,&paux);
                                                                  paux = strdup("int main(){//inicio bloque\n");
                                                                  mystrcat(codigo3,&paux);
                                                                }else{
                                                                  char* tmp = strdup("{//inicio bloque\n");
                                                                  mystrcat(&tmp,codigo3);
                                                                  paux = strdup(tmp);
                                                                  mystrcpy(codigo3,&paux);
                                                                }
                                                                }
#line 1696 "y.tab.c"
    break;

  case 6:
#line 179 "analizador_yacc.y"
                                            {
                                                                char** codigo3 = &yyvsp[-4].codigo;
                                                                char** codigo6 = &yyvsp[-1].codigo;
                                                                char** codigoS = &yyval.codigo;

                                                                if (nivel_profundidad_funciones_anidadas != 0)
                                                                {
                                                                  codigo3 = &yyvsp[-4].cod_fun;
                                                                  codigo6 = &yyvsp[-1].cod_fun;
                                                                  codigoS = &yyval.cod_fun;
                                                                }

                                                                TS_VaciarENTRADAS();
                                                                mystrcat(codigo3, codigo6);
                                                                paux = strdup("\n}//fin bloque\n");
                                                                mystrcat(codigo3, &paux);
                                                                mystrcpy(codigoS, codigo3 );
                                              }
#line 1719 "y.tab.c"
    break;

  case 9:
#line 199 "analizador_yacc.y"
                                               {subprog = 1; nivel_profundidad_funciones_anidadas++; funciones_anidadas++;}
#line 1725 "y.tab.c"
    break;

  case 10:
#line 201 "analizador_yacc.y"
                                                                {subprog = 0; nivel_profundidad_funciones_anidadas--;}
#line 1731 "y.tab.c"
    break;

  case 11:
#line 204 "analizador_yacc.y"
                                                             {
                                                                char** codigo2 = &yyvsp[-1].codigo;
                                                                char** codigoS = &yyval.codigo;
                                                                if (nivel_profundidad_funciones_anidadas != 0)
                                                                {
                                                                  codigo2 = &yyvsp[-1].cod_fun;
                                                                  codigoS = &yyval.cod_fun;
                                                                }
                                                                mystrcpy(codigoS, codigo2);
                                                                }
#line 1746 "y.tab.c"
    break;

  case 12:
#line 214 "analizador_yacc.y"
                                  {
                                                                char** lugar_donde_escribir = &yyval.codigo;

                                                                if (nivel_profundidad_funciones_anidadas != 0)
                                                                {
                                                                  lugar_donde_escribir = &yyval.cod_fun;
                                                                }

                                                                paux = strdup("");
                                                                mystrcpy(lugar_donde_escribir,&paux);
                                  }
#line 1762 "y.tab.c"
    break;

  case 18:
#line 230 "analizador_yacc.y"
                                                                        {
                                                                char** codigo1 = &yyvsp[-1].codigo;
                                                                char** codigo2 = &yyvsp[0].codigo;
                                                                char** codigoS = &yyval.codigo;

                                                                if (nivel_profundidad_funciones_anidadas != 0)
                                                                {
                                                                  codigo1 = &yyvsp[-1].cod_fun;
                                                                  codigo2 = &yyvsp[0].cod_fun;
                                                                  codigoS = &yyval.cod_fun;
                                                                }

                                                                paux = strdup("\n");
                                                                mystrcat(codigo1, &paux );
                                                                mystrcat(codigo1, codigo2 );
                                                                mystrcpy(codigoS, codigo1 );
                                                                }
#line 1784 "y.tab.c"
    break;

  case 19:
#line 247 "analizador_yacc.y"
                                                        {
                                                                char** codigo1 = &yyvsp[0].codigo;
                                                                char** codigoS = &yyval.codigo;

                                                                if (nivel_profundidad_funciones_anidadas != 0)
                                                                {
                                                                  codigo1 = &yyvsp[0].cod_fun;
                                                                  codigoS = &yyval.cod_fun;
                                                                }

                                                                paux = strdup(*codigo1);
                                                                mystrcpy(codigoS,&paux);
                                                                }
#line 1802 "y.tab.c"
    break;

  case 20:
#line 260 "analizador_yacc.y"
                                    {tipoTmp=atributoAEnum(yyvsp[0].atrib);}
#line 1808 "y.tab.c"
    break;

  case 21:
#line 260 "analizador_yacc.y"
                                                                                                       {
                                                                char** codigo1 = &yyvsp[-3].codigo;
                                                                char** codigo3 = &yyvsp[-1].codigo;
                                                                char** codigoS = &yyval.codigo;

                                                                if (nivel_profundidad_funciones_anidadas != 0)
                                                                {
                                                                  codigo1 = &yyvsp[-3].cod_fun;
                                                                  codigo3 = &yyvsp[-1].cod_fun;
                                                                  codigoS = &yyval.cod_fun;
                                                                }

                                                                paux = strdup(enumAString(tipoTmp));
                                                                mystrcpy(codigo1,&paux);
                                                                paux=strdup(" ");
                                                                mystrcat(codigo1,&paux);
                                                                mystrcat(codigo1,codigo3);
                                                                paux=strdup(";\n");
                                                                mystrcat(codigo1,&paux);
                                                                paux=strdup(*codigo1);
                                                                mystrcpy(codigoS,&paux);}
#line 1834 "y.tab.c"
    break;

  case 23:
#line 282 "analizador_yacc.y"
                                                                       {tipoTmp=atributoAEnum(yyvsp[-4].atrib);TS_InsertaSUBPROG(yyvsp[-3]);}
#line 1840 "y.tab.c"
    break;

  case 24:
#line 283 "analizador_yacc.y"
                                                            {tipoTmp=atributoAEnum(yyvsp[-3].atrib);TS_InsertaSUBPROG(yyvsp[-2]);}
#line 1846 "y.tab.c"
    break;

  case 25:
#line 284 "analizador_yacc.y"
                                   {tipoTmp=atributoAEnum(yyvsp[0].atrib);}
#line 1852 "y.tab.c"
    break;

  case 26:
#line 284 "analizador_yacc.y"
                                                                               {TS_InsertaPARAMF(yyvsp[0]);}
#line 1858 "y.tab.c"
    break;

  case 27:
#line 285 "analizador_yacc.y"
                                                       {tipoTmp=atributoAEnum(yyvsp[0].atrib);}
#line 1864 "y.tab.c"
    break;

  case 28:
#line 285 "analizador_yacc.y"
                                                                                                   {TS_InsertaPARAMF(yyvsp[0]);}
#line 1870 "y.tab.c"
    break;

  case 30:
#line 287 "analizador_yacc.y"
                                            {
                                                                char** codigoS = &yyval.codigo;

                                                                if (nivel_profundidad_funciones_anidadas != 0)
                                                                {
                                                                  codigoS = &yyval.cod_fun;
                                                                }

                                                                yyval.lexema = yyvsp[0].lexema;
                                                                yyval.dimensiones=0;
                                                                yyval.TamDimen1=0;
                                                                yyval.TamDimen2=0;
                                                                paux = strdup(yyvsp[0].lexema);

                                                                mystrcpy(codigoS,&paux);
                                             }
#line 1891 "y.tab.c"
    break;

  case 31:
#line 304 "analizador_yacc.y"
                                                         {yyval.lexema = yyvsp[0].lexema;}
#line 1897 "y.tab.c"
    break;

  case 32:
#line 305 "analizador_yacc.y"
                                                                   {yyval.lexema = yyvsp[-3].lexema;
                                                                    yyval.dimensiones=1;
                                                                    yyval.TamDimen1=atoi(yyvsp[-1].lexema);
                                                                    yyval.TamDimen2=0;}
#line 1906 "y.tab.c"
    break;

  case 33:
#line 310 "analizador_yacc.y"
                                                   {yyval.lexema = yyvsp[-5].lexema;
                                                    yyval.dimensiones=2;
                                                    yyval.TamDimen1=atoi(yyvsp[-3].lexema);
                                                    yyval.TamDimen2=atoi(yyvsp[-1].lexema);}
#line 1915 "y.tab.c"
    break;

  case 34:
#line 315 "analizador_yacc.y"
                                             {entradaTS ets = buscarEntrada(yyvsp[0].lexema); yyval = entradaAAtributos(ets);
                            paux = strdup(yyvsp[0].lexema);
                            mystrcpy(&yyval.codigo,&paux);}
#line 1923 "y.tab.c"
    break;

  case 35:
#line 318 "analizador_yacc.y"
                                                     {yyval = yyvsp[0];}
#line 1929 "y.tab.c"
    break;

  case 36:
#line 319 "analizador_yacc.y"
                                                                    {entradaTS ets = buscarEntrada(yyvsp[-3].lexema);
                                                                     ets.dimensiones = 0;
                                                                     yyval = entradaAAtributos(ets);}
#line 1937 "y.tab.c"
    break;

  case 37:
#line 323 "analizador_yacc.y"
                                                    {entradaTS ets = buscarEntrada(yyvsp[-5].lexema);
                                                     ets.dimensiones = 0;
                                                     yyval = entradaAAtributos(ets);}
#line 1945 "y.tab.c"
    break;

  case 38:
#line 326 "analizador_yacc.y"
                                                   {
                                                                char** codigo1 = &yyvsp[-1].codigo;
                                                                char** codigo2 = &yyvsp[0].codigo;
                                                                char** codigoS = &yyval.codigo;

                                                                if (nivel_profundidad_funciones_anidadas != 0)
                                                                {
                                                                  codigo1 = &yyvsp[-1].cod_fun;
                                                                  codigo2 = &yyvsp[0].cod_fun;
                                                                  codigoS = &yyval.cod_fun;
                                                                }

                                                                mystrcpy(codigoS,codigo1);
                                                                paux=strdup("\n");
                                                                mystrcat(codigoS,&paux);
                                                                mystrcat(codigoS,codigo2);
                                                                }
#line 1967 "y.tab.c"
    break;

  case 39:
#line 343 "analizador_yacc.y"
                                            {
                                                                char** codigo1 = &yyvsp[0].codigo;
                                                                char** codigoS = &yyval.codigo;

                                                                if (nivel_profundidad_funciones_anidadas != 0)
                                                                {
                                                                  codigo1 = &yyvsp[0].cod_fun;
                                                                  codigoS = &yyval.cod_fun;
                                                                }

                                                                mystrcpy(codigoS, codigo1);
                                                                }
#line 1984 "y.tab.c"
    break;

  case 40:
#line 355 "analizador_yacc.y"
                                     {
                                                                char** codigo1 = &yyvsp[0].codigo;
                                                                char** codigoS = &yyval.codigo;

                                                                if (nivel_profundidad_funciones_anidadas != 0)
                                                                {
                                                                  codigo1 = &yyvsp[0].cod_fun;
                                                                  codigoS = &yyval.cod_fun;
                                                                }

                                                                mystrcpy(codigoS,codigo1);
                                                                }
#line 2001 "y.tab.c"
    break;

  case 41:
#line 367 "analizador_yacc.y"
                                                       {
                                                                char** codigo1 = &yyvsp[0].codigo;
                                                                char** codigoS = &yyval.codigo;

                                                                if (nivel_profundidad_funciones_anidadas != 0)
                                                                {
                                                                  codigo1 = &yyvsp[0].cod_fun;
                                                                  codigoS = &yyval.cod_fun;
                                                                }

                                                                paux = strdup("{//inicio sentencia asig\n");
                                                                mystrcpy(codigoS,&paux);
                                                                mystrcat(codigoS, codigo1);
                                                                paux = strdup("}//fin sentencia asig\n");
                                                                mystrcat(codigoS,&paux);
                                                                }
#line 2022 "y.tab.c"
    break;

  case 42:
#line 383 "analizador_yacc.y"
                                                {
                                                                char** codigo1 = &yyvsp[0].codigo;
                                                                char** codigoS = &yyval.codigo;

                                                                if (nivel_profundidad_funciones_anidadas != 0)
                                                                {
                                                                  codigo1 = &yyvsp[0].cod_fun;
                                                                  codigoS = &yyval.cod_fun;
                                                                }

                                                                paux = strdup("{//inicio sentencia if\n");
                                                                mystrcpy(codigoS,&paux);
                                                                mystrcat(codigoS,codigo1);
                                                                paux=strdup("}//finsentenciaif\n");
                                                                mystrcat(codigoS,&paux);
                                                                }
#line 2043 "y.tab.c"
    break;

  case 43:
#line 399 "analizador_yacc.y"
                                                     {
                                                                char** codigo1 = &yyvsp[0].codigo;
                                                                char** codigoS = &yyval.codigo;

                                                                if (nivel_profundidad_funciones_anidadas != 0)
                                                                {
                                                                  codigo1 = &yyvsp[0].cod_fun;
                                                                  codigoS = &yyval.cod_fun;
                                                                }

                                                                paux = strdup("{//inicio sentencia while\n");
                                                                mystrcpy(codigoS,&paux);
                                                                mystrcat(codigoS,codigo1);
                                                                paux=strdup("}//finsentenciawhile\n");
                                                                mystrcat(codigoS,&paux);
                                                                }
#line 2064 "y.tab.c"
    break;

  case 44:
#line 415 "analizador_yacc.y"
                                                       {
                                                                char** codigo1 = &yyvsp[0].codigo;
                                                                char** codigoS = &yyval.codigo;

                                                                if (nivel_profundidad_funciones_anidadas != 0)
                                                                {
                                                                  codigo1 = &yyvsp[0].cod_fun;
                                                                  codigoS = &yyval.cod_fun;
                                                                }

                                                                paux=strdup("{//iniciosentenciado-until\n");
                                                                mystrcpy(codigoS,&paux);
                                                                mystrcat(codigoS,codigo1);
                                                                paux=strdup("}//finsentenciado-until\n");
                                                                mystrcat(codigoS,&paux);
                                                                }
#line 2085 "y.tab.c"
    break;

  case 45:
#line 431 "analizador_yacc.y"
                                                    {
                                                                char** codigo1 = &yyvsp[0].codigo;
                                                                char** codigoS = &yyval.codigo;

                                                                if (nivel_profundidad_funciones_anidadas != 0)
                                                                {
                                                                  codigo1 = &yyvsp[0].cod_fun;
                                                                  codigoS = &yyval.cod_fun;
                                                                }

                                                                paux = strdup("{//inicio sentencia entrada\n");
                                                                mystrcpy(codigoS,&paux);
                                                                mystrcat(codigoS,codigo1);
                                                                paux = strdup("}//fin sentencia entrada\n");
                                                                mystrcat(codigoS,&paux);
                                                                }
#line 2106 "y.tab.c"
    break;

  case 46:
#line 447 "analizador_yacc.y"
                                                   {
                                                                char** codigo1 = &yyvsp[0].codigo;
                                                                char** codigoS = &yyval.codigo;

                                                                if (nivel_profundidad_funciones_anidadas != 0)
                                                                {
                                                                  codigo1 = &yyvsp[0].cod_fun;
                                                                  codigoS = &yyval.cod_fun;
                                                                }

                                                                paux = strdup("{//inicio sentencia salida\n");
                                                                mystrcpy(codigoS,&paux);
                                                                mystrcat(codigoS,codigo1);
                                                                paux=strdup("}//finsentenciasalida\n");
                                                                mystrcat(codigoS,&paux);
                                                                }
#line 2127 "y.tab.c"
    break;

  case 47:
#line 463 "analizador_yacc.y"
                                                     {
                                                                char** codigoS = &yyval.codigo;

                                                                if (nivel_profundidad_funciones_anidadas != 0)
                                                                {
                                                                  codigoS = &yyval.cod_fun;
                                                                }

                                                                paux = strdup("SENTENCIA RETORNAR");
                                                                mystrcpy(codigoS,&paux);
                                                                }
#line 2143 "y.tab.c"
    break;

  case 48:
#line 474 "analizador_yacc.y"
                                                                    {procesaSentenciaAsignacion(yyvsp[-3],yyvsp[-1]);genCodigoAsignacion(&yyval,&yyvsp[-3],&yyvsp[-1]);}
#line 2149 "y.tab.c"
    break;

  case 50:
#line 476 "analizador_yacc.y"
                                                                   {procesaSentenciaControl(yyvsp[-2]);
                            genCodigoSi(&yyval,&yyvsp[-2],&yyvsp[0]);}
#line 2156 "y.tab.c"
    break;

  case 51:
#line 479 "analizador_yacc.y"
                                             {procesaSentenciaControl(yyvsp[-4]);genCodigoSino(&yyval,&yyvsp[-4],&yyvsp[-2],&yyvsp[0]);}
#line 2162 "y.tab.c"
    break;

  case 52:
#line 480 "analizador_yacc.y"
                                                                         {procesaSentenciaControl(yyvsp[-2]);
                            genCodigoMientras(&yyval,&yyvsp[-2],&yyvsp[0]);}
#line 2169 "y.tab.c"
    break;

  case 53:
#line 482 "analizador_yacc.y"
                                                                                {procesaSentenciaControl(yyvsp[-2]);genCodigoHacerHasta(&yyval,&yyvsp[-2],&yyvsp[-5]);}
#line 2175 "y.tab.c"
    break;

  case 54:
#line 483 "analizador_yacc.y"
                                                          {
                                                                char** codigoS = &yyval.codigo;
                                                                char** codigo2 = &yyvsp[-1].codigo;

                                                                if (nivel_profundidad_funciones_anidadas != 0)
                                                                {
                                                                  codigoS = &yyval.cod_fun;
                                                                  codigo2 = &yyvsp[-1].cod_fun;
                                                                }

                                                                paux = strdup("scanf(\"");
                                                                mystrcpy(codigoS,&paux);
                                                                mystrcat(codigoS,&textoScanf);
                                                                paux=strdup("\",");
                                                                mystrcat(codigoS,&paux);
                                                                mystrcat(codigoS,codigo2);
                                                                paux=strdup(");\n");
                                                                mystrcat(codigoS,&paux);
                                                                //Se resetea la variable global
                                                                textoScanf=NULL;
                            }
#line 2201 "y.tab.c"
    break;

  case 55:
#line 504 "analizador_yacc.y"
                                                                  {
                                                                char** codigoS = &yyval.codigo;
                                                                char** codigo2 = &yyvsp[-1].codigo;

                                                                if (nivel_profundidad_funciones_anidadas != 0)
                                                                {
                                                                  codigoS = &yyval.cod_fun;
                                                                  codigo2 = &yyvsp[-1].cod_fun;
                                                                }

                                                                mystrcpy(codigoS,codigo2);
                                                                paux=strdup("printf(\"");
                                                                mystrcat(codigoS,&paux);
                                                                mystrcat(codigoS,&textoPrintf);
                                                                paux=strdup("\",");
                                                                mystrcat(codigoS,&paux);
                                                                mystrcat(codigoS,&yyvsp[-1].nombreTmp);
                                                                paux=strdup(");\n");
                                                                mystrcat(codigoS,&paux);
                                                                //Se resetea la variable global
                                                                textoPrintf=NULL;
}
#line 2228 "y.tab.c"
    break;

  case 56:
#line 526 "analizador_yacc.y"
                                                     {procesaSentenciaRetornar(yyvsp[-1]);}
#line 2234 "y.tab.c"
    break;

  case 57:
#line 527 "analizador_yacc.y"
                                                                             {
                                                                char** codigoS = &yyval.codigo;
                                                                char** codigo1 = &yyvsp[-2].codigo;
                                                                char** codigo3 = &yyvsp[0].codigo;

                                                                if (nivel_profundidad_funciones_anidadas != 0)
                                                                {
                                                                  codigoS = &yyval.cod_fun;
                                                                  codigo1 = &yyvsp[-2].cod_fun;
                                                                  codigo3 = &yyvsp[0].cod_fun;
                                                                }

                                                                mystrcpy(&yyval.nombreTmp,&yyvsp[-2].nombreTmp);
                                                                paux=strdup(",");
                                                                mystrcat(&yyval.nombreTmp,&paux);
                                                                mystrcat(&yyval.nombreTmp,&yyvsp[0].nombreTmp);
                                                                mystrcpy(codigoS,codigo1);
                                                                paux=strdup("\n");
                                                                mystrcat(codigoS,&paux);
                                                                mystrcat(codigoS,codigo3);
                                                                }
#line 2260 "y.tab.c"
    break;

  case 58:
#line 548 "analizador_yacc.y"
                                                   {
                                                                char** codigoS = &yyval.codigo;
                                                                char** codigo1 = &yyvsp[0].codigo;

                                                                if (nivel_profundidad_funciones_anidadas != 0)
                                                                {
                                                                  codigoS = &yyval.cod_fun;
                                                                  codigo1 = &yyvsp[0].cod_fun;
                                                                }

                                                                mystrcpy(&yyval.nombreTmp,&yyvsp[0].nombreTmp);
                                                                mystrcpy(codigoS,codigo1);
                                                                }
#line 2278 "y.tab.c"
    break;

  case 59:
#line 561 "analizador_yacc.y"
                                        {
                                                                char** codigoS = &yyval.codigo;
                                                                char** codigo1 = &yyvsp[0].codigo;

                                                                if (nivel_profundidad_funciones_anidadas != 0)
                                                                {
                                                                  codigoS = &yyval.cod_fun;
                                                                  codigo1 = &yyvsp[0].cod_fun;
                                                                }

                                                                mystrcpy(&yyval.nombreTmp,&yyvsp[0].nombreTmp);
                                                                mystrcpy(codigoS,codigo1);
                                                                paux=strdup(enumATipoForm(yyvsp[0].tipo));
                                                                if(textoPrintf==NULL)mystrcpy(&textoPrintf,&paux);
                                                                else mystrcat(&textoPrintf,&paux);
                                                                paux=strdup(" ");
                                                                mystrcat(&textoPrintf,&paux);
                                                                }
#line 2301 "y.tab.c"
    break;

  case 60:
#line 579 "analizador_yacc.y"
                                     {
                                                                char** codigoS = &yyval.codigo;
                                                                char** codigo1 = &yyvsp[0].codigo;

                                                                if (nivel_profundidad_funciones_anidadas != 0)
                                                                {
                                                                  codigoS = &yyval.cod_fun;
                                                                  codigo1 = &yyvsp[0].cod_fun;
                                                                }

                                                                mystrcpy(&yyval.nombreTmp,codigo1);
                                                                paux = strdup("");
                                                                mystrcpy(codigoS,&paux);
                                                                paux = strdup("%s ");
                                                                if (textoPrintf == NULL) mystrcpy(&textoPrintf, &paux);
                                                                else mystrcat(&textoPrintf,&paux);
                                                                }
#line 2323 "y.tab.c"
    break;

  case 61:
#line 596 "analizador_yacc.y"
                                       {
                                                                char** codigoS = &yyval.codigo;
                                                                char** codigo1 = &yyvsp[0].codigo;

                                                                if (nivel_profundidad_funciones_anidadas != 0)
                                                                {
                                                                  codigoS = &yyval.cod_fun;
                                                                  codigo1 = &yyvsp[0].cod_fun;
                                                                }

                                                                entradaTS ets = buscarEntrada(yyvsp[0].lexema);
                                                                yyvsp[0].tipo = ets.tipoDato;
                                                                paux = strdup("&");
                                                                mystrcpy(codigoS,&paux);
                                                                mystrcat(codigoS,codigo1);

                                                                if (textoScanf == NULL){
                                                                  paux = strdup(enumATipoForm(yyvsp[0].tipo));
                                                                  mystrcpy(&textoScanf, &paux);
                                                                }
                                                                else {
                                                                  paux = strdup(enumATipoForm(yyvsp[0].tipo));
                                                                  mystrcat(&textoScanf,&paux);
                                                                }
                                                                }
#line 2353 "y.tab.c"
    break;

  case 62:
#line 621 "analizador_yacc.y"
                                                                {
                                                                char** codigoS = &yyval.codigo;
                                                                char** codigo1 = &yyvsp[-2].codigo;
                                                                char** codigo3 = &yyvsp[0].codigo;

                                                                if (nivel_profundidad_funciones_anidadas != 0)
                                                                {
                                                                  codigoS = &yyval.cod_fun;
                                                                  codigo1 = &yyvsp[-2].cod_fun;
                                                                  codigo3 = &yyvsp[0].cod_fun;
                                                                }

                                                                mystrcpy(codigoS,codigo1);
                                                                paux=strdup(",&");
                                                                mystrcat(codigoS,&paux);
                                                                mystrcat(codigoS,codigo3);
                                                                entradaTS ets=buscarEntrada(yyvsp[0].lexema);
                                                                yyvsp[0].tipo = ets.tipoDato;
                                                                if (textoScanf == NULL){
                                                                  paux = strdup(enumATipoForm(yyvsp[0].tipo));
                                                                  mystrcpy(&textoScanf, &paux);
                                                                }
                                                                else{
                                                                  paux = strdup("\\n");
                                                                  mystrcat(&textoScanf,&paux);
                                                                  paux = strdup(enumATipoForm(yyvsp[0].tipo));
                                                                  mystrcat(&textoScanf,&paux);
                                                                }
                                                                }
#line 2387 "y.tab.c"
    break;

  case 63:
#line 650 "analizador_yacc.y"
                                        {
                                                                char** codigoS = &yyval.codigo;
                                                                char** codigo1 = &yyvsp[0].codigo;

                                                                if (nivel_profundidad_funciones_anidadas != 0)
                                                                {
                                                                  codigoS = &yyval.cod_fun;
                                                                  codigo1 = &yyvsp[0].cod_fun;
                                                                }

                                                                TS_InsertaIDENT(yyvsp[0]);
                                                                paux = strdup(*codigo1);
                                                                mystrcpy(codigoS,&paux);
                                                                }
#line 2406 "y.tab.c"
    break;

  case 64:
#line 664 "analizador_yacc.y"
                                                                            {
                                                                char** codigoS = &yyval.codigo;
                                                                char** codigo1 = &yyvsp[-2].codigo;
                                                                char** codigo3 = &yyvsp[0].codigo;

                                                                if (nivel_profundidad_funciones_anidadas != 0)
                                                                {
                                                                  codigoS = &yyval.cod_fun;
                                                                  codigo1 = &yyvsp[-2].cod_fun;
                                                                  codigo3 = &yyvsp[0].cod_fun;
                                                                }

                                                                TS_InsertaIDENT(yyvsp[0]);
                                                                paux = strdup(",");
                                                                mystrcat(codigo1,&paux);
                                                                mystrcat(codigo1,codigo3);
                                                                paux = strdup(yyvsp[-2].codigo);
                                                                mystrcpy(codigoS,&paux);
                                                                }
#line 2430 "y.tab.c"
    break;

  case 66:
#line 684 "analizador_yacc.y"
                                        {
                                                                char** codigoS = &yyval.codigo;
                                                                char** codigo1 = &yyvsp[0].codigo;

                                                                if (nivel_profundidad_funciones_anidadas != 0)
                                                                {
                                                                  codigoS = &yyval.cod_fun;
                                                                  codigo1 = &yyvsp[0].cod_fun;
                                                                }

                                                                PILARG_insertaARG(yyvsp[0]);
                                                                mystrcpy(codigoS,codigo1);
                                                                }
#line 2448 "y.tab.c"
    break;

  case 67:
#line 697 "analizador_yacc.y"
                                                                   {
                                                                char** codigoS = &yyval.codigo;
                                                                char** codigo1 = &yyvsp[-2].codigo;
                                                                char** codigo3 = &yyvsp[0].codigo;

                                                                if (nivel_profundidad_funciones_anidadas != 0)
                                                                {
                                                                  codigoS = &yyval.cod_fun;
                                                                  codigo1 = &yyvsp[-2].cod_fun;
                                                                  codigo3 = &yyvsp[0].cod_fun;
                                                                }

                                                                PILARG_insertaARG(yyvsp[0]);
                                                                mystrcpy(codigoS,codigo1);
                                                                paux = strdup(",");
                                                                mystrcat(codigoS,&paux);
                                                                mystrcat(codigoS,codigo3);
                                                                }
#line 2471 "y.tab.c"
    break;

  case 68:
#line 715 "analizador_yacc.y"
                                                      {yyval = yyvsp[-1];}
#line 2477 "y.tab.c"
    break;

  case 69:
#line 716 "analizador_yacc.y"
                                                  {yyval = procesaOperacionNegacion(yyvsp[0]);genCodigoOperadorUnNeg(&yyval,&yyvsp[0]);}
#line 2483 "y.tab.c"
    break;

  case 70:
#line 717 "analizador_yacc.y"
                                                   {yyval = procesaOperacionMixtaCuandoUnaria(yyvsp[0]);genCodigoOperadorUn(&yyval,&yyvsp[0],yyvsp[-1].atrib);}
#line 2489 "y.tab.c"
    break;

  case 71:
#line 718 "analizador_yacc.y"
                                                                {yyval = procesaOperacionMixtaCuandoUnaria(yyvsp[0]);genCodigoOperadorUn(&yyval,&yyvsp[0],yyvsp[-1].atrib);}
#line 2495 "y.tab.c"
    break;

  case 72:
#line 719 "analizador_yacc.y"
                                                             {yyval = procesaOperacionBinariaOMixta(yyvsp[-2],yyvsp[0],yyvsp[-1].atrib);genCodigoOperadorBin(&yyval,&yyvsp[-2],&yyvsp[0],yyvsp[-1].atrib);}
#line 2501 "y.tab.c"
    break;

  case 73:
#line 720 "analizador_yacc.y"
                                                            {yyval = procesaOperacionBinariaOMixta(yyvsp[-2],yyvsp[0],yyvsp[-1].atrib);genCodigoOperadorBin(&yyval,&yyvsp[-2],&yyvsp[0],yyvsp[-1].atrib);}
#line 2507 "y.tab.c"
    break;

  case 74:
#line 721 "analizador_yacc.y"
                                                              {yyval = procesaOperacionBinariaOMixta(yyvsp[-2],yyvsp[0],yyvsp[-1].atrib);genCodigoOperadorBin(&yyval,&yyvsp[-2],&yyvsp[0],yyvsp[-1].atrib);}
#line 2513 "y.tab.c"
    break;

  case 75:
#line 722 "analizador_yacc.y"
                                                            {yyval = procesaOperacionBinariaOMixta(yyvsp[-2],yyvsp[0],yyvsp[-1].atrib);genCodigoOperadorBin(&yyval,&yyvsp[-2],&yyvsp[0],yyvsp[-1].atrib);}
#line 2519 "y.tab.c"
    break;

  case 76:
#line 723 "analizador_yacc.y"
                                                           {yyval = procesaOperacionBinariaOMixta(yyvsp[-2],yyvsp[0],yyvsp[-1].atrib);genCodigoOperadorBin(&yyval,&yyvsp[-2],&yyvsp[0],yyvsp[-1].atrib);}
#line 2525 "y.tab.c"
    break;

  case 77:
#line 724 "analizador_yacc.y"
                                                           {yyval = procesaOperacionBinariaOMixta(yyvsp[-2],yyvsp[0],yyvsp[-1].atrib);genCodigoOperadorBin(&yyval,&yyvsp[-2],&yyvsp[0],yyvsp[-1].atrib);}
#line 2531 "y.tab.c"
    break;

  case 78:
#line 725 "analizador_yacc.y"
                                                            {yyval = procesaOperacionBinariaOMixta(yyvsp[-2],yyvsp[0],yyvsp[-1].atrib);genCodigoOperadorBin(&yyval,&yyvsp[-2],&yyvsp[0],yyvsp[-1].atrib);}
#line 2537 "y.tab.c"
    break;

  case 79:
#line 726 "analizador_yacc.y"
                                                            {yyval = procesaOperacionBinariaOMixta(yyvsp[-2],yyvsp[0],yyvsp[-1].atrib);genCodigoOperadorBin(&yyval,&yyvsp[-2],&yyvsp[0],yyvsp[-1].atrib);}
#line 2543 "y.tab.c"
    break;

  case 80:
#line 727 "analizador_yacc.y"
                                                            {yyval = procesaOperacionBinariaOMixta(yyvsp[-2],yyvsp[0],yyvsp[-1].atrib);genCodigoOperadorBin(&yyval,&yyvsp[-2],&yyvsp[0],yyvsp[-1].atrib);}
#line 2549 "y.tab.c"
    break;

  case 81:
#line 728 "analizador_yacc.y"
                                                             {yyval = procesaOperacionBinariaOMixta(yyvsp[-2],yyvsp[0],yyvsp[-1].atrib);genCodigoOperadorBin(&yyval,&yyvsp[-2],&yyvsp[0],yyvsp[-1].atrib);}
#line 2555 "y.tab.c"
    break;

  case 82:
#line 729 "analizador_yacc.y"
                                                           {yyval = procesaOperacionBinariaOMixta(yyvsp[-2],yyvsp[0],yyvsp[-1].atrib);genCodigoOperadorBin(&yyval,&yyvsp[-2],&yyvsp[0],yyvsp[-1].atrib);}
#line 2561 "y.tab.c"
    break;

  case 83:
#line 730 "analizador_yacc.y"
                                                            {yyval = procesaOperacionBinariaOMixta(yyvsp[-2],yyvsp[0],yyvsp[-1].atrib);genCodigoOperadorBin(&yyval,&yyvsp[-2],&yyvsp[0],yyvsp[-1].atrib);}
#line 2567 "y.tab.c"
    break;

  case 84:
#line 731 "analizador_yacc.y"
                                                             {yyval = procesaOperacionBinariaOMixta(yyvsp[-2],yyvsp[0],yyvsp[-1].atrib);genCodigoOperadorMix(&yyval,&yyvsp[-2],&yyvsp[0],yyvsp[-1].atrib);}
#line 2573 "y.tab.c"
    break;

  case 85:
#line 732 "analizador_yacc.y"
                                                              {yyval = procesaOperacionBinariaOMixta(yyvsp[-2],yyvsp[0],yyvsp[-1].atrib);genCodigoOperadorMix(&yyval,&yyvsp[-2],&yyvsp[0],yyvsp[-1].atrib);}
#line 2579 "y.tab.c"
    break;

  case 86:
#line 733 "analizador_yacc.y"
                                                     {
                                                                char** codigoS = &yyval.codigo;

                                                                if (nivel_profundidad_funciones_anidadas != 0)
                                                                {
                                                                  codigoS = &yyval.cod_fun;
                                                                }

                                                                yyval = yyvsp[0];
                                                                mystrcpy(&yyval.nombreTmp,&yyvsp[0].lexema);
                                                                paux = strdup("");
                                                                mystrcpy(codigoS,&paux);
                              }
#line 2597 "y.tab.c"
    break;

  case 87:
#line 746 "analizador_yacc.y"
                                            {
                                                                char** codigoS = &yyval.codigo;

                                                                if (nivel_profundidad_funciones_anidadas != 0)
                                                                {
                                                                  codigoS = &yyval.cod_fun;
                                                                }

                                                                yyval = yyvsp[0];
                                                                mystrcpy(&yyval.nombreTmp,&yyvsp[0].lexema);
                                                                paux = strdup("");
                                                                mystrcpy(codigoS,&paux);
                                                                }
#line 2615 "y.tab.c"
    break;

  case 88:
#line 759 "analizador_yacc.y"
                                          {
                                                                char** codigoS = &yyval.codigo;
                                                                char** codigo1 = &yyvsp[0].codigo;

                                                                if (nivel_profundidad_funciones_anidadas != 0)
                                                                {
                                                                  codigoS = &yyval.cod_fun;
                                                                  codigo1 = &yyvsp[0].cod_fun;
                                                                }

                                                                yyval = yyvsp[0];
                                                                paux = temporal();
                                                                mystrcpy(&yyval.nombreTmp,&paux);
                                                                paux = strdup(enumAString(yyval.tipo));
                                                                mystrcpy(codigoS,&paux);
                                                                paux = strdup(" ");
                                                                mystrcat(codigoS,&paux);
                                                                paux = strdup(yyval.nombreTmp);
                                                                mystrcat(codigoS,&paux);
                                                                paux = strdup(";\n");
                                                                mystrcat(codigoS,&paux);
                                                                paux = strdup(yyval.nombreTmp);
                                                                mystrcat(codigoS,&paux);
                                                                paux = strdup("=");
                                                                mystrcat(codigoS,&paux);
                                                                mystrcat(codigoS,codigo1);
                                                                paux = strdup(";\n");
                                                                mystrcat(codigoS,&paux);
                                                                }
#line 2649 "y.tab.c"
    break;

  case 90:
#line 789 "analizador_yacc.y"
                                                          {
                                                                char** codigoS = &yyval.codigo;
                                                                char** codigo1 = &yyvsp[-2].codigo;

                                                                if (nivel_profundidad_funciones_anidadas != 0)
                                                                {
                                                                  codigoS = &yyval.cod_fun;
                                                                  codigo1 = &yyvsp[-2].cod_fun;
                                                                }

                                                                entradaTS ets = buscarEntrada(yyvsp[-2].lexema);
                                                                procesaLlamadaFuncionSinArgumentos(ets);
                                                                yyval = entradaAAtributos(ets);
                                                                mystrcpy(codigoS,codigo1);
                                                                paux = strdup("(");
                                                                mystrcat(codigoS,&paux);
                                                                paux = strdup(")");
                                                                mystrcat(codigoS,&paux);
                                                                }
#line 2673 "y.tab.c"
    break;

  case 91:
#line 808 "analizador_yacc.y"
                                                       {PILARG_insertaMARCA();}
#line 2679 "y.tab.c"
    break;

  case 92:
#line 809 "analizador_yacc.y"
                              {
                                                                char** codigoS = &yyval.codigo;
                                                                char** codigo1 = &yyvsp[-4].codigo;
                                                                char** codigo4 = &yyvsp[-1].codigo;

                                                                if (nivel_profundidad_funciones_anidadas != 0)
                                                                {
                                                                  codigoS = &yyval.cod_fun;
                                                                  codigo1 = &yyvsp[-4].cod_fun;
                                                                  codigo4 = &yyvsp[-1].cod_fun;
                                                                }

                                                                entradaTS ets = buscarEntrada(yyvsp[-4].lexema);
                                                                procesaLlamadaFuncionConArgumentos(ets);
                                                                yyval = entradaAAtributos(ets);
                                                                mystrcpy(codigoS,codigo1);
                                                                paux = strdup("(");
                                                                mystrcat(codigoS,&paux);
                                                                mystrcat(codigoS,codigo4);
                                                                paux = strdup(")");
                                                                mystrcat(codigoS,&paux);
                                                                }
#line 2706 "y.tab.c"
    break;

  case 93:
#line 831 "analizador_yacc.y"
                                     {yyval.atrib = yyvsp[0].atrib;}
#line 2712 "y.tab.c"
    break;

  case 94:
#line 832 "analizador_yacc.y"
                                     {
                                                                char** codigoS = &yyval.codigo;

                                                                if (nivel_profundidad_funciones_anidadas != 0)
                                                                {
                                                                  codigoS = &yyval.cod_fun;
                                                                }

                                                                paux = strdup(yyvsp[0].lexema);
                                                                mystrcpy(codigoS,&paux);
                                                                }
#line 2728 "y.tab.c"
    break;

  case 95:
#line 843 "analizador_yacc.y"
                                    {
                                                                char** codigoS = &yyval.codigo;

                                                                if (nivel_profundidad_funciones_anidadas != 0)
                                                                {
                                                                  codigoS = &yyval.cod_fun;
                                                                }

                                                                paux = strdup(yyvsp[0].lexema);
                                                                mystrcpy(codigoS,&paux);
                                                                }
#line 2744 "y.tab.c"
    break;

  case 96:
#line 854 "analizador_yacc.y"
                                    {
                                                                char** codigoS = &yyval.codigo;

                                                                if (nivel_profundidad_funciones_anidadas != 0)
                                                                {
                                                                  codigoS = &yyval.cod_fun;
                                                                }

                                                                yyval.tipo = atributoAEnum(yyvsp[0].atrib+1);
                                                                paux = strdup(yyvsp[0].lexema);
                                                                mystrcpy(codigoS,&paux);
                                                                }
#line 2761 "y.tab.c"
    break;

  case 97:
#line 866 "analizador_yacc.y"
                                          {
                                                                char** codigoS = &yyval.codigo;

                                                                if (nivel_profundidad_funciones_anidadas != 0)
                                                                {
                                                                  codigoS = &yyval.cod_fun;
                                                                }

                                                                yyval.tipo = entero;
                                                                paux = strdup(yyvsp[0].lexema);
                                                                mystrcpy(codigoS,&paux);
                                                                }
#line 2778 "y.tab.c"
    break;

  case 98:
#line 878 "analizador_yacc.y"
                                                                    { yyval.tipo = yyvsp[-1].tipo;
                                                                    if (yyvsp[-1].TamDimen2==1){yyval.TamDimen2 = 0; yyval.TamDimen1 = yyvsp[-1].TamDimen1; yyval.dimensiones = 1;}
                                                                    else{yyval.TamDimen2 = yyvsp[-1].TamDimen2; yyval.TamDimen1 = yyvsp[-1].TamDimen1; yyval.dimensiones = 2;}}
#line 2786 "y.tab.c"
    break;

  case 99:
#line 881 "analizador_yacc.y"
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
#line 2803 "y.tab.c"
    break;

  case 100:
#line 893 "analizador_yacc.y"
                                                          {yyval.TamDimen2 = 1;yyval.TamDimen1 = yyvsp[0].TamDimen1;yyval.tipo = yyvsp[0].tipo;}
#line 2809 "y.tab.c"
    break;

  case 101:
#line 895 "analizador_yacc.y"
                                          {yyval.TamDimen1 = 1; yyval.tipo = yyvsp[0].tipo;}
#line 2815 "y.tab.c"
    break;

  case 102:
#line 896 "analizador_yacc.y"
                                                                         {yyval.TamDimen1 = yyvsp[-2].TamDimen1 + 1;
                                                                          if (yyvsp[-2].tipo != yyvsp[0].tipo){
                                                                                printf("[Linea %d]",linea_actual);
                                                                                printf("ERROR SEMÁNTICO: Array con distintos tipos.\n");
                                                                          }}
#line 2825 "y.tab.c"
    break;


#line 2829 "y.tab.c"

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
#line 903 "analizador_yacc.y"


#ifdef DOSWINDOWS
#include "lexyy.c"
#else
#include "lex.yy.c"
#endif

void yyerror(char *msg)
{
  fprintf(stderr, "[Linea %d]: %s\n", linea_actual, msg);
}

/* ANALISIS SEMÁNTICO */


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

  if (TOPE > 0)
    TOPE--;
  else
    fprintf(stderr, "Error: No se encontró marca al vaciar tabla de símbolos\n");
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
    if (strcmp(TS_aux[tope_aux].nombre,ets.nombre) == 0) {
      printf("[Linea %d]",linea_actual);
      printf("ERROR SEMÁNTICO:se ha encontrado otro parámetro formal con el mismo identificador: '%s'\n", ets.nombre);
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

void procesaSentenciaRetornar(atributos ret){

  int i = TOPE-1;

  while (i>=1){
    if (TS[i].entrada == marca && (TS[i-1].entrada == parametro_formal || TS[i-1].entrada == funcion)) break;
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

void procesaSentenciaControl(atributos exp){
  if (exp.tipo != booleano){
    printf("[Linea %d]",linea_actual);   printf("ERROR SEMÁNTICO: La sentencia de control (si|mientras|hasta) espera una expresión booleana.\n");
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





/* GENERACIÓN DE CÓDIGO */



void empezarGEN(){

  intermain = fopen("main_inter.c","w");
  dec_fun_c = fopen("dec_fun.c","w");
  dec_fun_h = fopen("dec_fun.h","w");

  fputs("#include <stdio.h>\n",intermain);
  fputs("#include <stdlib.h>\n",intermain);
  fputs("#include <stdbool.h>\n",intermain);
  fputs("#include \"dec_fun.h\"\n",intermain);

  fputs("#include \"dec_fun.h\"\n",dec_fun_c);

  fputs("#ifndef DEC_FUN_H\n#define DEC_FUN_H\n",dec_fun_h);
}


void finalizarGEN(){
  fputs("#endif\n",dec_fun_h);

  fputs("\n",intermain);
  fputs("\n",dec_fun_c);
  fputs("\n",dec_fun_h);

  fclose(intermain);
  fclose(dec_fun_c);
  fclose(dec_fun_h);
}


char* temporal(){
  char tmp[10];
  sprintf(tmp,"tmp%d",Ntmp);
  Ntmp = Ntmp + 1;
  return strdup(tmp);
}


char* etiqueta(){
  char etiqueta[20];
  sprintf(etiqueta,"etiqueta%d",Netiqueta);
  Netiqueta = Netiqueta + 1;
  return strdup(etiqueta);
}

char* enumAString(dtipo t){

  if (t == entero)return strdup("int");
  if (t == booleano)return strdup("int");
  if (t == real)return strdup("double");
  if (t == caracter)return strdup("char");

  return strdup("Ninguno");
}

char* opdorUnAString(int opdor){
  if (opdor == 0) return strdup("+");
  if (opdor == 1) return strdup("-");
  return strdup("Ninguno");
}




char* opdorBinAString(int opdor){
  if (opdor == 0) return strdup("*");
  if (opdor == 1) return strdup("/");
  if (opdor == 2) return strdup("**");
  if (opdor == 3) return strdup("&&");
  if (opdor == 4) return strdup("||");
  if (opdor == 5) return strdup("==");
  if (opdor == 6) return strdup("!=");
  if (opdor == 7) return strdup("<=");
  if (opdor == 8) return strdup(">=");
  if (opdor == 9) return strdup("<");
  if (opdor == 10) return strdup(">");
  if (opdor == 11) return strdup("%");
  return strdup("Ninguno");
}



void genCodigoOperadorMix(atributos* obj, atributos* at1, atributos* at2, int opdor){

  char** obj_codigo = &(*obj).codigo;
  char** at1_codigo = &(*at1).codigo;
  char** at2_codigo = &(*at2).codigo;

  if( nivel_profundidad_funciones_anidadas != 0)
  {
    obj_codigo = &(*obj).cod_fun;
    at1_codigo = &(*at1).cod_fun;
    at2_codigo = &(*at2).cod_fun;
  }

  paux = temporal();
  mystrcpy(&(*obj).nombreTmp,&paux);
  mystrcpy(obj_codigo,at1_codigo);
  paux = strdup("\n");
  mystrcat(obj_codigo,&paux);
  mystrcat(obj_codigo,at2_codigo);
  paux = strdup("\n");
  mystrcat(obj_codigo,&paux);
  paux = enumAString((*obj).tipo);
  mystrcat(obj_codigo,&paux);
  paux = strdup(" ");
  mystrcat(obj_codigo,&paux);
  paux = strdup((*obj).nombreTmp);
  mystrcat(obj_codigo,&paux);
  paux = strdup(";\n");
  mystrcat(obj_codigo,&paux);
  paux = strdup((*obj).nombreTmp);
  mystrcat(obj_codigo,&paux);
  paux = strdup("=");
  mystrcat(obj_codigo,&paux);
  mystrcat(obj_codigo,&(*at1).nombreTmp);
  paux = strdup(opdorUnAString(opdor));
  mystrcat(obj_codigo,&paux);
  mystrcat(obj_codigo,&(*at2).nombreTmp);
  paux = strdup(";\n");
  mystrcat(obj_codigo,&paux);
}

void genCodigoOperadorBin(atributos* obj, atributos* at1, atributos* at2, int opdor){

  char** obj_codigo = &(*obj).codigo;
  char** at1_codigo = &(*at1).codigo;
  char** at2_codigo = &(*at2).codigo;

  if( nivel_profundidad_funciones_anidadas != 0)
  {
    obj_codigo = &(*obj).cod_fun;
    at1_codigo = &(*at1).cod_fun;
    at2_codigo = &(*at2).cod_fun;
  }

  paux = temporal();
  mystrcpy(&(*obj).nombreTmp,&paux);
  mystrcpy(obj_codigo,at1_codigo);
  paux = strdup("\n");
  mystrcat(obj_codigo,&paux);
  mystrcat(obj_codigo,at2_codigo);
  paux = strdup("\n");
  mystrcat(obj_codigo,&paux);
  paux = enumAString((*obj).tipo);
  mystrcat(obj_codigo,&paux);
  paux = strdup(" ");
  mystrcat(obj_codigo,&paux);
  paux = strdup((*obj).nombreTmp);
  mystrcat(obj_codigo,&paux);
  paux = strdup(";\n");
  mystrcat(obj_codigo,&paux);
  paux = strdup((*obj).nombreTmp);
  mystrcat(obj_codigo,&paux);
  paux = strdup("=");
  mystrcat(obj_codigo,&paux);
  mystrcat(obj_codigo,&(*at1).nombreTmp);
  paux = strdup(opdorBinAString(opdor));
  mystrcat(obj_codigo,&paux);
  mystrcat(obj_codigo,&(*at2).nombreTmp);
  paux = strdup(";\n");
  mystrcat(obj_codigo,&paux);
}

void genCodigoOperadorUn(atributos* obj, atributos* at1, int opdor){

  char** obj_codigo = &(*obj).codigo;
  char** at1_codigo = &(*at1).codigo;

  if( nivel_profundidad_funciones_anidadas != 0)
  {
    obj_codigo = &(*obj).cod_fun;
    at1_codigo = &(*at1).cod_fun;
  }

  paux = temporal();
  mystrcpy(&(*obj).nombreTmp,&paux);
  mystrcpy(obj_codigo,at1_codigo);
  paux = strdup("\n");
  mystrcat(obj_codigo,&paux);
  paux = (*obj).nombreTmp;
  mystrcat(obj_codigo,&paux);
  paux = strdup(";\n");
  mystrcat(obj_codigo,&paux);
  paux = (*obj).nombreTmp;
  mystrcat(obj_codigo,&paux);
  paux = strdup("=");
  mystrcat(obj_codigo,&paux);
  paux = strdup(opdorBinAString(opdor));
  mystrcat(obj_codigo,&paux);
  mystrcat(obj_codigo,&(*at1).nombreTmp);
  paux = strdup(";\n");
  mystrcat(obj_codigo,&paux);
}

void genCodigoOperadorUnNeg(atributos* obj, atributos* at1){

  char** obj_codigo = &(*obj).codigo;
  char** at1_codigo = &(*at1).codigo;

  if( nivel_profundidad_funciones_anidadas != 0)
  {
    obj_codigo = &(*obj).cod_fun;
    at1_codigo = &(*at1).cod_fun;
  }

  paux = temporal();
  mystrcpy(&(*obj).nombreTmp,&paux);
  mystrcpy(obj_codigo,at1_codigo);
  paux = strdup("\n");
  mystrcat(obj_codigo,&paux);
  paux = strdup(" ");
  mystrcat(obj_codigo,&paux);
  mystrcat(obj_codigo,&(*obj).nombreTmp);
  paux = strdup(";\n");
  mystrcat(obj_codigo,&paux);
  mystrcat(obj_codigo,&(*obj).nombreTmp);
  paux = strdup("=");
  mystrcat(obj_codigo,&paux);
  paux = strdup("!");
  mystrcat(obj_codigo,&paux);
  mystrcat(obj_codigo,&(*at1).nombreTmp);
  paux = strdup(";\n");
  mystrcat(obj_codigo,&paux);
}

void genCodigoAsignacion(atributos* obj, atributos* at1, atributos* at2){

  char** obj_codigo = &(*obj).codigo;
  char** at1_codigo = &(*at1).codigo;
  char** at2_codigo = &(*at2).codigo;

  if( nivel_profundidad_funciones_anidadas != 0)
  {
    obj_codigo = &(*obj).cod_fun;
    at1_codigo = &(*at1).cod_fun;
    at2_codigo = &(*at2).cod_fun;
  }

  mystrcpy(obj_codigo,at2_codigo);
  paux = strdup("\n");
  mystrcat(obj_codigo,&paux);
  mystrcat(obj_codigo,at1_codigo);
  paux = strdup(" = ");
  mystrcat(obj_codigo,&paux);
  mystrcat(obj_codigo,&(*at2).nombreTmp);
  paux = strdup(";\n");
  mystrcat(obj_codigo,&paux);
}


char* enumATipoForm(dtipo t){

  if (t == entero)return strdup("%d");
  if (t == booleano)return strdup("%d");
  if (t == real)return strdup("%f");
  if (t == caracter)return strdup("%c");

  return strdup("Ninguno");
}

void genCodigoSi(atributos* obj,atributos* cond,atributos* sent){

  char** obj_codigo = &(*obj).codigo;
  char** cond_codigo = &(*cond).codigo;
  char** sent_codigo = &(*sent).codigo;

  if( nivel_profundidad_funciones_anidadas != 0)
  {
    obj_codigo = &(*obj).cod_fun;
    cond_codigo = &(*cond).cod_fun;
    sent_codigo = &(*sent).cod_fun;
  }

  char* etfin = etiqueta();

  mystrcpy(obj_codigo,cond_codigo);
  paux=strdup("if (!");
  mystrcat(obj_codigo,&paux);
  mystrcat(obj_codigo,&(*cond).nombreTmp);
  paux=strdup(") goto ");
  mystrcat(obj_codigo,&paux);
  paux=strdup(etfin);
  mystrcat(obj_codigo,&paux);
  paux=strdup(";\n{//inicio if\n");
  mystrcat(obj_codigo,&paux);
  mystrcat(obj_codigo,sent_codigo);
  paux=strdup("}//fin if\n");
  mystrcat(obj_codigo,&paux);
  mystrcat(obj_codigo,&etfin);
  paux = strdup(": ;\n");
  mystrcat(obj_codigo,&paux);
}


void genCodigoSino(atributos* obj,atributos* cond, atributos* sent, atributos* sent2){

  char** obj_codigo = &(*obj).codigo;
  char** cond_codigo = &(*cond).codigo;
  char** sent_codigo = &(*sent).codigo;
  char** sent2_codigo = &(*sent2).codigo;

  if( nivel_profundidad_funciones_anidadas != 0)
  {
    obj_codigo = &(*obj).cod_fun;
    cond_codigo = &(*cond).cod_fun;
    sent_codigo = &(*sent).cod_fun;
    sent2_codigo = &(*sent2).cod_fun;
  }

  char* etfin = etiqueta();
  char* etelse = etiqueta();

  mystrcpy(obj_codigo,cond_codigo);
  paux=strdup("if (!");
  mystrcat(obj_codigo,&paux);
  mystrcat(obj_codigo,&(*cond).nombreTmp);
  paux=strdup(") goto ");
  mystrcat(obj_codigo,&paux);
  paux=strdup(etelse);
  mystrcat(obj_codigo,&paux);
  paux=strdup(";\n{//inicio if\n");
  mystrcat(obj_codigo,&paux);
  mystrcat(obj_codigo,sent_codigo);
  paux=strdup("}//fin if\n");
  mystrcat(obj_codigo,&paux);
  paux = strdup("goto ");
  mystrcat(obj_codigo,&paux);
  paux = strdup(etfin);
  mystrcat(obj_codigo,&paux);
  paux = strdup(";\n");
  mystrcat(obj_codigo,&paux);

  mystrcat(obj_codigo,&etelse);
  paux = strdup(": ;\n");
  mystrcat(obj_codigo,&paux);


  paux=strdup("{//inicio else\n");
  mystrcat(obj_codigo,&paux);
  mystrcat(obj_codigo,sent2_codigo);
  paux=strdup("}//fin else\n");
  mystrcat(obj_codigo,&paux);



  mystrcat(obj_codigo,&etfin);
  paux = strdup(": ;\n");
  mystrcat(obj_codigo,&paux);

}



void genCodigoMientras(atributos* obj,atributos* cond,atributos* sent){

  char** obj_codigo = &(*obj).codigo;
  char** cond_codigo = &(*cond).codigo;
  char** sent_codigo = &(*sent).codigo;

  if( nivel_profundidad_funciones_anidadas != 0)
  {
    obj_codigo = &(*obj).cod_fun;
    cond_codigo = &(*cond).cod_fun;
    sent_codigo = &(*sent).cod_fun;
  }


  char* etini = etiqueta();
  char* etfin = etiqueta();


  paux = strdup(etini);
  mystrcpy(obj_codigo,&paux);
  paux=strdup(": ;\n");
  mystrcat(obj_codigo,&paux);

  mystrcat(obj_codigo,cond_codigo);
  paux=strdup("if (!");
  mystrcat(obj_codigo,&paux);
  mystrcat(obj_codigo,&(*cond).nombreTmp);
  paux=strdup(") goto ");
  mystrcat(obj_codigo,&paux);
  paux=strdup(etfin);
  mystrcat(obj_codigo,&paux);
  paux=strdup(";\n");
  mystrcat(obj_codigo,&paux);

  mystrcat(obj_codigo, sent_codigo);

  paux = strdup("\ngoto ");
  mystrcat(obj_codigo,&paux);
  paux = strdup(etini);
  mystrcat(obj_codigo,&paux);
  paux = strdup(";\n");
  mystrcat(obj_codigo,&paux);


  paux = strdup(etfin);
  mystrcat(obj_codigo,&paux);
  paux = strdup(": ;\n");
  mystrcat(obj_codigo,&paux);
}


void genCodigoHacerHasta(atributos* obj,atributos* cond,atributos* sent){

  char** obj_codigo = &(*obj).codigo;
  char** cond_codigo = &(*cond).codigo;
  char** sent_codigo = &(*sent).codigo;

  if( nivel_profundidad_funciones_anidadas != 0)
  {
    obj_codigo = &(*obj).cod_fun;
    cond_codigo = &(*cond).cod_fun;
    sent_codigo = &(*sent).cod_fun;
  }



  char* etini = etiqueta();

  paux = strdup(etini);
  mystrcpy(obj_codigo,&paux);
  paux = strdup(": ;\n");
  mystrcat(obj_codigo,&paux);
  mystrcat(obj_codigo,sent_codigo);


  mystrcat(obj_codigo,cond_codigo);

  paux=strdup("if (!");
  mystrcat(obj_codigo,&paux);
  mystrcat(obj_codigo,&(*cond).nombreTmp);
  paux=strdup(") goto ");
  mystrcat(obj_codigo,&paux);
  mystrcat(obj_codigo,&etini);
  paux=strdup(";\n");
  mystrcat(obj_codigo,&paux);

}



void mystrcat(char** c1,char** c2){

  //printf("1:%s\n",*c1);
  //printf("2:%s\n",*c2);

  int newSize = strlen(*c1) + strlen(*c2) + 1;

  char* newC = (char*) malloc(newSize);

  strcpy(newC,*c1);
  strcat(newC,*c2);
  free(*c1);
  free(*c2);
  *c1 = newC;
}

void mystrcpy(char** c1,char** c2){

  //printf("0:%s\n",*c2);
  int newSize = strlen(*c2) + 1;

  *c1 = (char*) malloc(newSize);
  strcpy(*c1,*c2);

  free(*c2);

}
