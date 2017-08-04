
#include <stdio.h>
#include <math.h>
#include <stdlib.h> 

#define MAXSTACK    30

#define OP_QUIT      0
#define OP_PUSH_OLD  1
#define OP_PUSH_NEW  2
#define OP_ADD       3
#define OP_SUB       4
#define OP_MUL       5
#define OP_DIV       6
#define OP_ERR       7
#define OP_NOTHING   8
#define OP_clear     9
#define OP_CLEAR     10
#define OP_NOTNUM    11
#define OP_SWAP      12
#define OP_SQRT      13
#define OP_EXP       14
#define OP_POW       15
#define OP_LN        16
#define OP_LOG       17
#define OP_PUSHPI    18
#define OP_DEGREE    19
#define OP_NOTKEY    20
#define OP_SIN       21
#define OP_COS       22
#define OP_TAN       23
#define OP_STO       24
#define OP_RCL       25
#define OP_TERSE     26
#define OP_VERBOSE   27
#define OP_DISPLAY   28
#define OP_INPUT     29
#define OP_REPEAT    30
#define OP_ASIN      31
#define OP_ACOS      32
#define OP_ATAN      33
#define OP_CHS       34
#define OP_STOA      35
#define OP_STOB      36
#define OP_STOC      37
#define OP_STOD      38
#define OP_STOE      39
#define OP_STOF      40
#define OP_STOG      41
#define OP_STOH      42
#define OP_STOI      43
#define OP_STOJ      44
#define OP_STOK      45
#define OP_STOL      46
#define OP_STOM      47
#define OP_STON      48
#define OP_STOO      49
#define OP_STOP      50
#define OP_STOQ      51
#define OP_STOR      52
#define OP_STOS      53
#define OP_STOT      54
#define OP_STOU      55
#define OP_STOV      56
#define OP_STOW      57
#define OP_STOX      58
#define OP_STOY      59
#define OP_STOZ      60
#define OP_RCLA      61
#define OP_RCLB      62
#define OP_RCLC      63
#define OP_RCLD      64
#define OP_RCLE      65
#define OP_RCLF      66
#define OP_RCLG      67
#define OP_RCLH      68
#define OP_RCLI      69
#define OP_RCLJ      70
#define OP_RCLK      71
#define OP_RCLL      72
#define OP_RCLM      73
#define OP_RCLN      74
#define OP_RCLO      75
#define OP_RCLP      76
#define OP_RCLQ      77
#define OP_RCLR      78
#define OP_RCLS      79
#define OP_RCLT      80
#define OP_RCLU      81
#define OP_RCLV      82
#define OP_RCLW      83
#define OP_RCLX      84
#define OP_RCLY      85
#define OP_RCLZ      86
#define OP_PRINT     87
#define OP_COMMENT   88
#define OP_RSP       89
#define OP_MODULO    90


#define KEYLEN       10
#define POS          1
#define NEG         (-1)
#define MAXINT (double) (((unsigned) ~((unsigned) 0))>>1)
#define M_PI       ((double) 3.14159265358979323846)

static double stack[MAXSTACK];
static double *stackptr;
static int sign = POS;
static double store;
static double storea;
static double storeb;
static double storec;
static double stored;
static double storee;
static double storef;
static double storeg;
static double storeh;
static double storei;
static double storej;
static double storek;
static double storel;
static double storem;
static double storen;
static double storeo;
static double storep;
static double storeq;
static double storer;
static double stores;
static double storet;
static double storeu;
static double storev;
static double storew;
static double storex;
static double storey;
static double storez;

struct key {
	char *name;
	int  op;
};
static struct key keys[] = {
	"c", OP_clear,
	"C", OP_CLEAR,
	"s", OP_SWAP,
	"sto", OP_STO,
	"stoa", OP_STOA,
	"stob", OP_STOB,
	"stoc", OP_STOC,
	"stod", OP_STOD,
	"stoe", OP_STOE,
	"stof", OP_STOF,
	"stog", OP_STOG,
	"stoh", OP_STOH,
	"stoi", OP_STOI,
	"stoj", OP_STOJ,
	"stok", OP_STOK,
	"stol", OP_STOL,
	"stom", OP_STOM,
	"ston", OP_STON,
	"stoo", OP_STOO,
	"stop", OP_STOP,
	"stoq", OP_STOQ,
	"stor", OP_STOR,
	"stos", OP_STOS,
	"stot", OP_STOT,
	"stou", OP_STOU,
	"stov", OP_STOV,
	"stow", OP_STOW,
	"stox", OP_STOX,
	"stoy", OP_STOY,
	"stoz", OP_STOZ,
	"rcl", OP_RCL,
	"rcla", OP_RCLA,
	"rclb", OP_RCLB,
	"rclc", OP_RCLC,
	"rcld", OP_RCLD,
	"rcle", OP_RCLE,
	"rclf", OP_RCLF,
	"rclg", OP_RCLG,
	"rclh", OP_RCLH,
	"rcli", OP_RCLI,
	"rclj", OP_RCLJ,
	"rclk", OP_RCLK,
	"rcll", OP_RCLL,
	"rclm", OP_RCLM,
	"rcln", OP_RCLN,
	"rclo", OP_RCLO,
	"rclp", OP_RCLP,
	"rclq", OP_RCLQ,
	"rclr", OP_RCLR,
	"rcls", OP_RCLS,
	"rclt", OP_RCLT,
	"rclu", OP_RCLU,
	"rclv", OP_RCLV,
	"rclw", OP_RCLW,
	"rclx", OP_RCLX,
	"rcly", OP_RCLY,
	"rclz", OP_RCLZ,
	"sqrt", OP_SQRT,
	"exp", OP_EXP,
	"xp", OP_EXP,
	"pow", OP_POW,
	"ln", OP_LN,
	"log", OP_LOG,
	"pi", OP_PUSHPI,
	"d", OP_DEGREE,
	"sin", OP_SIN,
	"cos", OP_COS,
	"tan", OP_TAN,
	"asin", OP_ASIN,
	"acos", OP_ACOS,
	"atan", OP_ATAN,
	"q", OP_QUIT,
	"terse", OP_TERSE,
	"verbose", OP_VERBOSE,
	"display", OP_DISPLAY,
	"input", OP_INPUT,
	"repeat", OP_REPEAT,
	"chs", OP_CHS,
	"print", OP_PRINT,
	"#", OP_COMMENT,
	"rsp", OP_RSP,
	"z", OP_NOTKEY };

static char keyloc[KEYLEN];
FILE *fp, *fopen();
static int terse = 0;

int getop(double* numptr);
void initstack(void);
void push(double num);
double pop(void);
void display(int longe);
void untrail(void);
void untrailstd(void);
int isnotnumber(int c);
int ischar(int c);
double double_abs(double num);
void getkey(char* s, int c);
int keycmp(char* s, char* t);


int main(int argc, char* argv[])
{
	int optype;
	double val, temp, temp2;
	/* double exp(), log(), log10(),pow(), sqrt(),sin(),cos(),tan(),asin(),acos(),atan(); */

	if (argc == 1)
		fp = stdin;
	else
		fopen_s(&fp, argv[1], "r");

	if (fp == stdin) /* do not print manual when input is a file */
		fprintf(stderr, "Reverse Polish notation calculator\n\
 q     quits\n\
 c     removes last stack location\n\
 C     clears whole stack\n\
 s     swaps the last 2 stack locations\n\
 sto   stores the last stack location\n\
 rcl   recalls it\n\
 chs   changes sign\n\
 0x    prefix for entering hex numbers\n\n\
 operators are +,-,*,/,%% (+ and - also unary; %% is modulo)\n\
 sqrt\n\
 exp\n\
 log\n\
 ln\n\
 pow    10 2pow gives 100\n\
 pi     3.14\n\
 d      considers current number as degrees and converts to radials\n\
 sin,cos,tan  arguments in radials \n\
 asin,acos,atan  results in radials \n\
 rsp R2,R1,P1,Pivot,P2,S1,S2 given H,L,C \n\n\
examples:\n\
 2 3+ <enter> gives 5\n\
 2<enter>3+<enter> gives 5\n\
 2<enter>3<enter>+<enter> gives 5\n\
 3<enter><enter>*<enter> gives 9\n\
 6.626e-34 gives Planck's constant\n\
 1s/<enter> gives the reciproke of the last number\n\
 2 sqrt<enter> gives 1.4\n\
 1exp gives e ;  2exp gives the square of e\n\n\
calc file   allows commands to be put in file\n\
 extra commands: terse,verbose turns off/on full display\n\
                 display       displays last stack location\n\
                 input         prints until end of line and waits for\n\
                 decimal number from standard input\n\
                 print         prints untill end of line\n\
                 #             ignored until end of line (comment)\n\
                 repeat        reexecutes file\n");

	initstack();

	while ((optype = getop(&val)) != EOF) {
		switch (optype) {
		case OP_QUIT:
			exit(0);

		case OP_PUSH_OLD:
			if (terse == 0)
				printf(">\n");
			val = pop();
			push(val);
			push(val);
			break;

		case OP_PUSH_NEW:
			push(val);
			sign = POS;
			break;

		case OP_PUSHPI:
			push(M_PI);
			sign = POS;
			break;

		case OP_ADD:
			temp = pop();
			val = pop() + temp;
			push(val);
			break;

		case OP_SUB:
			temp = pop();
			val = pop() - temp;
			push(val);
			break;

		case OP_MUL:
			temp = pop();
			val = pop()*temp;
			push(val);
			break;

		case OP_SQRT:
			push(sqrt(pop()));
			break;

		case OP_CHS:
			push(-(pop()));
			break;

		case OP_DEGREE:
			push(((pop())*M_PI) / 180.0);
			break;

		case OP_SIN:
			push(sin(pop()));
			break;

		case OP_COS:
			push(cos(pop()));
			break;

		case OP_TAN:
			push(tan(pop()));
			break;

		case OP_ASIN:
			push(asin(pop()));
			break;

		case OP_ACOS:
			push(acos(pop()));
			break;

		case OP_ATAN:
			push(atan(pop()));
			break;

		case OP_EXP:
			push(exp(pop()));
			break;

		case OP_LN:
			temp = pop();
			if (temp <= 0) {
				fprintf(stderr, "cannot use 0 or negative\n");
				push(temp);
			}
			else
				push(log(temp));
			break;

		case OP_LOG:
			temp = pop();
			if (temp <= 0) {
				fprintf(stderr, "cannot use 0 or negative\n");
				push(temp);
			}
			else
				push(log10(temp));
			break;

		case OP_DIV:
			temp = pop();
			if (temp == 0) {
				fprintf(stderr, "divide by 0\n");
				push(temp);
			}
			else {
				val = pop() / temp;
				push(val);
			}
			break;

		case OP_POW:
			temp = pop();
			temp2 = pop();
			if ((temp == 0) && (temp2 == 0)) {
				fprintf(stderr, "cannot use 2 zeros\n");
				push(temp2);
				push(temp);
			}
			else {
				push(pow(temp2, temp));
			}
			break;

		case OP_NOTHING:
			break;

		case OP_clear:
			pop();
			break;

		case OP_CLEAR:
			initstack();
			break;

		case OP_SWAP:
			temp = pop();
			temp2 = pop();
			push(temp);
			push(temp2);
			break;

		case OP_STO:
			push(store = pop());
			break;

		case OP_STOA:
			push(storea = pop());
			break;

		case OP_STOB:
			push(storeb = pop());
			break;

		case OP_STOC:
			push(storec = pop());
			break;

		case OP_STOD:
			push(stored = pop());
			break;

		case OP_STOE:
			push(storee = pop());
			break;

		case OP_STOF:
			push(storef = pop());
			break;

		case OP_STOG:
			push(storeg = pop());
			break;

		case OP_STOH:
			push(storeh = pop());
			break;

		case OP_STOI:
			push(storei = pop());
			break;

		case OP_STOJ:
			push(storej = pop());
			break;

		case OP_STOK:
			push(storek = pop());
			break;

		case OP_STOL:
			push(storel = pop());
			break;

		case OP_STOM:
			push(storem = pop());
			break;

		case OP_STON:
			push(storen = pop());
			break;

		case OP_STOO:
			push(storeo = pop());
			break;

		case OP_STOP:
			push(storep = pop());
			break;

		case OP_STOQ:
			push(storeq = pop());
			break;

		case OP_STOR:
			push(storer = pop());
			break;

		case OP_STOS:
			push(stores = pop());
			break;

		case OP_STOT:
			push(storet = pop());
			break;

		case OP_STOU:
			push(storeu = pop());
			break;

		case OP_STOV:
			push(storev = pop());
			break;

		case OP_STOW:
			push(storew = pop());
			break;

		case OP_STOX:
			push(storex = pop());
			break;

		case OP_STOY:
			push(storey = pop());
			break;

		case OP_STOZ:
			push(storez = pop());
			break;

		case OP_RCL:
			push(store);
			break;

		case OP_RCLA:
			push(storea);
			break;

		case OP_RCLB:
			push(storeb);
			break;

		case OP_RCLC:
			push(storec);
			break;

		case OP_RCLD:
			push(stored);
			break;

		case OP_RCLE:
			push(storee);
			break;

		case OP_RCLF:
			push(storef);
			break;

		case OP_RCLG:
			push(storeg);
			break;

		case OP_RCLH:
			push(storeh);
			break;

		case OP_RCLI:
			push(storei);
			break;

		case OP_RCLJ:
			push(storej);
			break;

		case OP_RCLK:
			push(storek);
			break;

		case OP_RCLL:
			push(storel);
			break;

		case OP_RCLM:
			push(storem);
			break;

		case OP_RCLN:
			push(storen);
			break;

		case OP_RCLO:
			push(storeo);
			break;

		case OP_RCLP:
			push(storep);
			break;

		case OP_RCLQ:
			push(storeq);
			break;

		case OP_RCLR:
			push(storer);
			break;

		case OP_RCLS:
			push(stores);
			break;

		case OP_RCLT:
			push(storet);
			break;

		case OP_RCLU:
			push(storeu);
			break;

		case OP_RCLV:
			push(storev);
			break;

		case OP_RCLW:
			push(storew);
			break;

		case OP_RCLX:
			push(storex);
			break;

		case OP_RCLY:
			push(storey);
			break;

		case OP_RCLZ:
			push(storez);
			break;

		case OP_TERSE:
			terse = 1;
			break;

		case OP_VERBOSE:
			terse = 0;
			break;

		case OP_DISPLAY:
			display(0);
			break;

		case OP_INPUT:
		{
			int d;
			while (((d = getc(fp)) != '\n') && (d != EOF))
				putchar(d);
			if (scanf_s("%lf", &val)) {
				push(val);
				untrailstd();
				break;
			}
			else exit(1);
		}

		case OP_REPEAT:
			if (fp != stdin) {
				fclose(fp);
				fopen_s(&fp, argv[1], "r");
			}
			initstack();
			break;

		case OP_NOTNUM:
			fprintf(stderr, "not a number\n");
			break;

		case OP_NOTKEY:
			fprintf(stderr, "not a keyword: %s\n", keyloc);
			break;

		case OP_PRINT:
		{
			int d;
			while (((d = getc(fp)) != '\n') && (d != EOF))
				putchar(d);
			putchar('\n');
			break;
		}

		case OP_COMMENT:
		{
			int d;
			while (((d = getc(fp)) != '\n') && (d != EOF))
				;
			break;
		}

		case OP_RSP:
		{
			double c = pop();//close
			double l = pop();//low
			double h = pop();//high
			double p = (h + l + c) / 3;//pivot
			push(p + (h - l));//R2
			push((2 * p) - l);//R1
			push((2 * p) - h + 0.68*(h - l));//P1
			push(p);                 //Pivot
			push((2 * p) - h + 0.32*(h - l));//P2
			push((2 * p) - h);//S1
			push(p - (h - l));//S2
			break;
		}

		case OP_MODULO:
			temp = pop();
			val = (unsigned int)double_abs(pop()) % (unsigned int)double_abs(temp);
			push(val);
			break;

		default:
			fprintf(stderr, "bad input\n");
			exit(1);
		}
		if ((optype != OP_NOTHING) && (optype != OP_NOTNUM) && (optype != OP_NOTKEY)
			&& (terse == 0))
			display(1);
	}
}

int getop(double* numptr)
{
	int hex_num;
	int c;
	struct key *keyptr;

	while (((c = getc(fp)) == ' ') || (c == '\t'))
		;
	switch (c) {
	case EOF:
		return(EOF);
	case '\n':
		return(OP_PUSH_OLD);
	case '*':
		untrail();
		return(OP_MUL);

	case '/':
		untrail();
		return(OP_DIV);

	case '%':
		untrail();
		return(OP_MODULO);

	case '-':
		if (isnotnumber(c = getc(fp))) { /*subtraction*/
			ungetc(c, fp);
			untrail();
			return(OP_SUB);
		}
		else { /*negative number*/
			sign = NEG;
			ungetc(c, fp);
			return(OP_NOTHING);
		}

	case '+':
		if (isnotnumber(c = getc(fp))) { /*addition*/
			ungetc(c, fp);
			untrail();
			return(OP_ADD);
		}
		else { /*positive number*/
			ungetc(c, fp);
			return(OP_NOTHING);
		}

	default:
		if (isnotnumber(c)) {
			getkey(keyloc, c);
			for (keyptr = keys; (*(keyptr->name) != 'z') && (keycmp(keyptr->name, keyloc) == 0); keyptr++)
				;
			return(keyptr->op);
		}
		else {  /*number*/
			if (c == '0')
				if ((c = getc(fp)) == 'x') {
					if (fscanf_s(fp, "%x", &hex_num)) {
						*numptr = (hex_num*sign);
						untrail();
						return(OP_PUSH_NEW);
					}
					else {
						getc(fp);
						untrail();
						return(OP_NOTNUM);
					}
				}
				else {
					ungetc(c, fp);
					c = '0';
				}

				ungetc(c, fp);
				if (fscanf_s(fp, "%lf", numptr)) {
					untrail();
					*numptr = (*numptr * sign);
					return(OP_PUSH_NEW);
				}
				else {
					getc(fp);
					untrail();
					return(OP_NOTNUM);
				}
		} /*number*/
	}  /*switch (c) */
}

void initstack(void)
{
	int n;
	for (n = 0; n<MAXSTACK; n++)
		stack[n] = 0;
	stackptr = stack;
}

void push(double num)
{
	if (stackptr == (stack + MAXSTACK)) {
		fprintf(stderr, "stack overflow\n");
		return;
	}

	*stackptr++ = num;
}

double pop(void)
{
	if (stackptr == stack) {
		fprintf(stderr, "stack underflow\n");
		return(0.0);
	}

	return(*--stackptr);
}

void display(int longe)
{
	double *ptr, double_abs(double);
	printf("          ********************************\n");
	if (longe == 1)
		ptr = stack;
	else
		ptr = stackptr - 1;
	for (; ptr<stackptr; ptr++) {
		if (((double_abs(*ptr)<1.0e7) && (double_abs(*ptr)>1.0e-7)) || (*ptr == 0))
			printf("%30.10f", *ptr);
		else
			printf("%30.10e", *ptr);
		if ((*ptr <= MAXINT) && (*ptr >= (-MAXINT - 1.0)))
			printf("%10x h\n", (int)*ptr);
		else
			printf("  --------\n");
	}
}

void untrail(void)
{
	int c;
	while (((c = getc(fp)) == ' ') || (c == '\t'))
		;
	if (c != '\n')
		ungetc(c, fp);
}

void untrailstd(void)
{
	int c;
	while (((c = getc(stdin)) == ' ') || (c == '\t'))
		;
	if (c != '\n')
		ungetc(c, stdin);
}

int isnotnumber(int c)
{
	return((((c >= '0') && (c <= '9')) || (c == '.')) == 0);
}

int ischar(int c)
{
	return(((c >= 'a') && (c <= 'z')) || ((c >= 'A') && (c <= 'Z')));
}

double double_abs(double num)
{
	return(num<0 ? -num : num);
}

void getkey(char* s, int c)
{
	if (c == '#')
	{
		*s = c;
		*(s + 1) = '\0';
		return;
	}
 {
	 char *t;
	 t = s;
	 do
		 *t++ = c;
	 while ((ischar(c = getc(fp))) && ((t - s)<(KEYLEN - 1)));
	 *t = '\0';
	 ungetc(c, fp);
	 if (!(keycmp(s, "print") || keycmp(s, "input")))
		 untrail();
 }
}

int keycmp(char* s, char* t)
{
	for (; *s == *t; s++, t++)
		if (*s == '\0')
			return(1);
	return(0);
}

