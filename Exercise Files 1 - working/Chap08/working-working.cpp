// working.cpp by Bill Weinman <http://bw.org/>
// updated 2002-06-24
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

constexpr int maxstring = 1024;    // read buffer size

struct Item {
	char * sku;
	char * name;
	char * desc;
};

int main()
{
    const char * fn = "items.txt";   // file name
    Item arrItem[100];
    char str[1024];

    puts("reading file");
    char buf[maxstring];
    FILE * fr = fopen(fn, "r");


    int indItem=0,ind;
    while(fgets(buf, maxstring, fr)) {
    	//printf("/////\n");

        //fputs(buf, stdout);
        //printf("buf: %s\n",buf);

        for(int step=1,ind=0,indBuf=0;step!=0;indBuf++){
        	//printf("indItem: %d, indBuf: %d, ind: %d \n",indItem, indBuf,ind);
        	switch(step){
				case 1:
		        	if(buf[indBuf]=='\t'){
		        		str[ind]='\0';
		        		//printf("indBuf: %d, ind: %d, str: %s\n",indBuf,ind, str);
		        		arrItem[indItem].sku= new char[ind+1];
		        		strncpy( arrItem[indItem].sku, str, ind+1);
		        	    //printf("arrItem[%d].sku: %s\n",indItem,arrItem[indItem].sku);

		        	    str[0]='\0';
		        		step++;
		        		ind=0;
		        		break;
		        	}
					str[ind]=buf[indBuf];
					ind++;
					break;
				case 2:
		        	if(buf[indBuf]=='\t'){
		        		str[ind]='\0';
		        		//printf("indBuf: %d, ind: %d, str: %s\n",indBuf,ind, str);
		        		arrItem[indItem].name= new char[ind+1];
		        		strncpy( arrItem[indItem].name, str, ind+1);
		        	    //printf("arrItem[%d].name: %s\n",indItem,arrItem[indItem].name);

		        	    str[0]='\0';
		        		step++;
		        		ind=0;
		        		break;
		        	}
					str[ind]=buf[indBuf];
					ind++;
					break;
				case 3:
		        	if(buf[indBuf]=='\n'){
		        		str[ind]='\0';
		        		//printf("indBuf: %d, ind: %d, str: %s\n",indBuf,ind, str);
		        		arrItem[indItem].desc= new char[ind+1];
		        		strncpy( arrItem[indItem].desc, str, ind+1);
		        	    //printf("arrItem[%d].desc: %s\n",indItem,arrItem[indItem].desc);

		        	    str[0]='\0';
		        		step=0;
		        		ind=0;
		        		break;
		        	}
					str[ind]=buf[indBuf];
					ind++;
					break;
				default:

					break;
        	}//switch
        }//for
        indItem++;
        //printf("indItem: %d",indItem);
    }//while

    //printf("FIN\n");

    fclose(fr);
    //remove(fn);


    for(int i=0;i<indItem;i++){
    	printf("sku: %s, name: %s, desc: %s\n",arrItem[i].sku,arrItem[i].name,arrItem[i].desc);
    }

    return 0;
}//main



/*
//char *c_string_copy = new char[str.length() + 1];
//int lenght= sizeof(str) / sizeof(str[0]);
//printf("lenght: %d\n",lenght);
*/

/*
 * 1/3
static const char * fn1 = "file1";
FILE * fh = fopen(fn1,"w");
fclose(fh);
*/

/*
 * 2/3
static const char * fn1 = "file1";
static const char * fn2 = "file2";
rename(fn1,fn2);
 */

/*
 * 3/3
static const char * fn2 = "file2";
remove(fn2);
 */

/*
 * 1/2
fputs("Done.!",stdout); //stdout,stdin,stderr
puts("Done.!");
 */

/*
 * 2/2
fputs("Done.!\n",stdout); //stdout,stdin,stderr
puts("Done.!");
*/

/*
const int bufsize = 256;
static char buf[bufsize];
fputs("prompt:",stdout);
fgets(buf,bufsize,stdin);
puts("output:");
fputs(buf,stdout);
fflush(stdout);
*/
/*
const char *s = "Alexander is observant child.dadadadada  ada sd a da  da sda d as dasd";
printf("Pointer: %p, Size is %zd\n",s,sizeof(s));
*/

