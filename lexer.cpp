#include <bits/stdc++.h> 
#define N 1024
using namespace std;
//enum Token
//{
//INT,CHAR,FLOAT,DOUBLE,VOID,UNSIGNED,SHORT,\
//RETURN,BREAK,CONTINUE,TRUE,FALSE,\
//IF,ELSE,FOR,DO,WHILE,\
//PLUS,MINUS,MUL,DIV,SEMI,TWICE,PLUS2,MINUS2,MUL2,DIV2,SEMI2,TWICE2,\
//MORE,EQUAL,LESS,MORE2,EQUAL2,LESS2,AND,OR,NOT,AND2,OR2,XOR,\
//};

string key[17]={"int","char","float","double","void","unsigned","short",\
				"return","break","continue","true","false"\
				"if","else","for","do","while",};//1-17
//int keynum[32]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17}; 
string symbol[34]= {"+","-","*","/","%",">>","<<","+=","-=","*=","/=","%=",">>=","<<="\
					">","=","<",">=","==","<=","&&","||","!","&=","|=","^=",\
					",",";","(",")","[","]","{","}"};//18-51
//int symbolnum[32]={18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36};
string patch[5] = {"scanf","printf","getchar","include","define"};//52-56





string txt[N];
int txt_length,txt_p;

void analyse()
{
	
	
	
	
	
	
}


int main()
{
	FILE *fp;
    fp=freopen("E:\\CODE\\input.txt","r",stdin);//¾ø¶ÔÂ·¾¶
//	freopen("result.txt","w",stdout);
    if (fp == NULL){
        printf("Not found!\n");
        exit(-1);
    }
    
    char w;
    bool flag=false;
	//È¥×¢ÊÍ 
    while(cin>>w)
	{	
    	if(flag){
    		if(w!='/' && w!='*')
				flag = false;
	    	else if(w=='/'){
	    		while( (w=getchar()) != '\n');
				flag = false;
				txt_length--; 
				continue;
			}
			else if(w=='*'){
				bool flag2 = 0;
				while(cin>>w){
					if(flag2){
						if(w=='/'){
							flag = 0;
							txt_length--;
							break;
						}	
					}
					else if(w=='*'){
						flag2 = 1;
					}
				}
				continue;
			}
		}
		else if(w=='/')	flag=true;
		
	    txt[txt_length++]=w;
    }
    analyse();
    return 0;
}
