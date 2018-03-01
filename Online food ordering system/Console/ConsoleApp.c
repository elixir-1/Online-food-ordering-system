/* Processed by ecpg (10.1) */
/* These include files are added by the preprocessor */
#include <ecpglib.h>
#include <ecpgerrno.h>
#include <sqlca.h>
/* End of automatic include section */

#line 1 "ConsoleApp.pgc"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sqlda.h>
//EXEC SQL include sqla.h;
sqlda_t *sqlda1;
sqlda_t *sqlda2;
/* exec sql begin declare section */
  
 
  
 
   

#line 10 "ConsoleApp.pgc"
 char search [ 20000 ] , query [ 20000 ] , x [ 20000 ] , username [ 200 ] , name [ 100 ] , pass [ 200 ] ;
 
#line 11 "ConsoleApp.pgc"
 char c , * ans ;
 
#line 12 "ConsoleApp.pgc"
 const char * password ;
 
#line 13 "ConsoleApp.pgc"
 int i = 0 , intval ;
 
#line 14 "ConsoleApp.pgc"
 long long longlongval ;
/* exec sql end declare section */
#line 15 "ConsoleApp.pgc"

/* exec sql whenever sqlerror  call print_sqlca ( ) ; */
#line 16 "ConsoleApp.pgc"


void print_sqlca()
{
    fprintf(stderr, "==== sqlca ====\n");
    fprintf(stderr, "sqlcode: %ld\n", sqlca.sqlcode);
    fprintf(stderr, "sqlerrm.sqlerrml: %d\n", sqlca.sqlerrm.sqlerrml);
    fprintf(stderr, "sqlerrm.sqlerrmc: %s\n", sqlca.sqlerrm.sqlerrmc);
    fprintf(stderr, "sqlerrd: %ld %ld %ld %ld %ld %ld\n", sqlca.sqlerrd[0],sqlca.sqlerrd[1],sqlca.sqlerrd[2],
                                                          sqlca.sqlerrd[3],sqlca.sqlerrd[4],sqlca.sqlerrd[5]);
    fprintf(stderr, "sqlwarn: %d %d %d %d %d %d %d %d\n", sqlca.sqlwarn[0], sqlca.sqlwarn[1], sqlca.sqlwarn[2],
                                                          sqlca.sqlwarn[3], sqlca.sqlwarn[4], sqlca.sqlwarn[5],
                                                          sqlca.sqlwarn[6], sqlca.sqlwarn[7]);
    fprintf(stderr, "sqlstate: %5s\n", sqlca.sqlstate);
    fprintf(stderr, "===============\n");
}
void ExecuteQuerry()
{
	printf("Input Your Query :\n");
	scanf(" %[^\n]",query);
	{ ECPGprepare(__LINE__, NULL, 0, "eq", query);
#line 36 "ConsoleApp.pgc"

if (sqlca.sqlcode < 0) print_sqlca ( );}
#line 36 "ConsoleApp.pgc"

	/* declare cur1 cursor for $1 */
#line 37 "ConsoleApp.pgc"

	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "declare cur1 cursor for $1", 
	ECPGt_char_variable,(ECPGprepared_statement(NULL, "eq", __LINE__)),(long)1,(long)1,(1)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);
#line 38 "ConsoleApp.pgc"

if (sqlca.sqlcode < 0) print_sqlca ( );}
#line 38 "ConsoleApp.pgc"

	while(sqlca.sqlcode==0)
	{
		{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "fetch next from cur1", ECPGt_EOIT, 
	ECPGt_sqlda, &sqlda1, 0L, 0L, 0L, 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);
#line 41 "ConsoleApp.pgc"

if (sqlca.sqlcode < 0) print_sqlca ( );}
#line 41 "ConsoleApp.pgc"

		sqlda_t *cur_sqlda;
		for (cur_sqlda = sqlda1;cur_sqlda != NULL;cur_sqlda = cur_sqlda->desc_next)
		{
			int i;
	        char name_buf[1024];
	        char var_buf[1024];
	    	for (i = 0; i < cur_sqlda->sqld; i++)
			{
	    		sqlvar_t v = cur_sqlda->sqlvar[i];
	    		char *sqldata = v.sqldata;
	    		short sqllen  = v.sqllen;
	    		strncpy(name_buf, v.sqlname.data, v.sqlname.length);
	            name_buf[v.sqlname.length] = '\0';

	                switch (v.sqltype)
	                {
	                    case ECPGt_char:
	                        memset(&var_buf, 0, sizeof(var_buf));
	                        memcpy(&var_buf, sqldata, (sizeof(var_buf)<=sqllen ? sizeof(var_buf)-1 : sqllen) );
	                        break;

	                    case ECPGt_int: /* integer */
	                        memcpy(&intval, sqldata, sqllen);
	                        snprintf(var_buf, sizeof(var_buf), "%d", intval);
	                        break;

	                    case ECPGt_long_long: /* bigint */
	                        memcpy(&longlongval, sqldata, sqllen);
	                        snprintf(var_buf, sizeof(var_buf), "%lld", longlongval);
	                        break;

	                    default:
	                    {
	                        int i;
	                        memset(var_buf, 0, sizeof(var_buf));
	                        for (i = 0; i < sqllen; i++)
	                        {
	                            char tmpbuf[16];
	                            snprintf(tmpbuf, sizeof(tmpbuf), "%02x ", (unsigned char) sqldata[i]);
	                            strncat(var_buf, tmpbuf, sizeof(var_buf));
	                        }
	                    }
	                        break;
	                }

	                printf("%s = %s\n", name_buf, var_buf);
	        }

	            printf("\n");
	    }

	}
	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "close cur1", ECPGt_EOIT, ECPGt_EORT);
#line 94 "ConsoleApp.pgc"

if (sqlca.sqlcode < 0) print_sqlca ( );}
#line 94 "ConsoleApp.pgc"

	{ ECPGtrans(__LINE__, NULL, "commit");
#line 95 "ConsoleApp.pgc"

if (sqlca.sqlcode < 0) print_sqlca ( );}
#line 95 "ConsoleApp.pgc"

}

void UpdateQuerry()
{
	printf("Input Your Query : \n");

    scanf(" %[^\n]",query);

    { ECPGprepare(__LINE__, NULL, 0, "query1", query);
#line 104 "ConsoleApp.pgc"

if (sqlca.sqlcode < 0) print_sqlca ( );}
#line 104 "ConsoleApp.pgc"


    { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_execute, "query1", ECPGt_EOIT, ECPGt_EORT);
#line 106 "ConsoleApp.pgc"

if (sqlca.sqlcode < 0) print_sqlca ( );}
#line 106 "ConsoleApp.pgc"


    if(sqlca.sqlcode==0)

    {

        fprintf(stderr, "Successful Update Statement\n");

    }

    { ECPGtrans(__LINE__, NULL, "commit");
#line 116 "ConsoleApp.pgc"

if (sqlca.sqlcode < 0) print_sqlca ( );}
#line 116 "ConsoleApp.pgc"


    { ECPGdeallocate(__LINE__, 0, NULL, "query1");
#line 118 "ConsoleApp.pgc"

if (sqlca.sqlcode < 0) print_sqlca ( );}
#line 118 "ConsoleApp.pgc"

}
int main()
{
	printf("DBNAME: ");
	scanf(" %[^\n]",name);
	getchar();

	printf("USERNAME: ");
	scanf(" %[^\n]",username);
	getchar();

	printf("PASSWORD: ");
	scanf(" %[^\n]",pass);
	getchar();

	strcpy(name,"201501016@10.100.71.21:5432");
    { ECPGconnect(__LINE__, 0, name , username , pass , NULL, 0); 
#line 135 "ConsoleApp.pgc"

if (sqlca.sqlcode < 0) print_sqlca ( );}
#line 135 "ConsoleApp.pgc"


	if(sqlca.sqlcode==0)
		fprintf(stderr, "Connection Successful\n");
	else
		exit(1);

	printf("Set your search path :\n");
	scanf(" %[^\n]",search);
	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "set search_path to $0", 
	ECPGt_char,(search),(long)20000,(long)1,(20000)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);
#line 144 "ConsoleApp.pgc"

if (sqlca.sqlcode < 0) print_sqlca ( );}
#line 144 "ConsoleApp.pgc"


	if(sqlca.sqlcode==0)
		fprintf(stderr,"Search_path Successfully set\n");
	else
	{
		fprintf(stderr,"No such path available\n");
		exit(1);
	}
	while(1)
	{
		printf("Press 1 for INSERT,UPDATE and DELETE Querry.\nPress 2 for SELECT querry.\nPress anything else to exit.\n");
		scanf(" %c",&c);
		if(c=='1')
		{
			UpdateQuerry();
		}
		else if(c=='2')
		{
			ExecuteQuerry();
		}
		else
			break;
	}
    { ECPGdisconnect(__LINE__, "ALL");
#line 168 "ConsoleApp.pgc"

if (sqlca.sqlcode < 0) print_sqlca ( );}
#line 168 "ConsoleApp.pgc"

    return 0;
}
