/*
数字只能十进制 
暂未实现循环读入 
*/
#include <bits/stdc++.h> 
#define N 10000
#define keyNum 23
#define symbolNum1 22
#define symbolNum2 15
using namespace std;
	
//enum Token
//{
//INT,CHAR,FLOAT,DOUBLE,VOID,UNSIGNED,SHORT,\
//RETURN,BREAK,CONTINUE,TRUE,FALSE,\
//IF,ELSE,FOR,DO,WHILE,\
//PLUS,MINUS,MUL,DIV,SEMI,TWICE,PLUS2,MINUS2,MUL2,DIV2,SEMI2,TWICE2,\
//MORE,EQUAL,LESS,MORE2,EQUAL2,LESS2,AND,OR,AND2,OR2,XOR,\
//};
char txt[N];
int txt_length,txt_p=0;
string key[keyNum] = {
"int","char","float","double","bool","void","unsigned","short",
"return","break","continue","true","false"
"if","else","for","do","while",
"scanf","printf","getchar","include","define",
};//1-22
string symbol[symbolNum1+symbolNum2] = {
"+","-","*","/","%",">","=","<","&","|","^","~",",",";","#","(",")","[","]","{","}","\"",//23-44
"+=","-=","*=","/=","%=",">>","<<",">=","==","<=","&&","||","&=","|=","^=",//45-59
};


int Type(string str){
	if( (str>="a" && str<="z") || (str>="A" && str<="Z") )  // 字母 
        return 1;

    if(str>="0" && str<="9")   //数字 
        return 2;
	
	for(int i=0; i<symbolNum1; i++)
		if(str == symbol[i])
			return 3;
	        
	return 4; 
}

bool isFilter(char c){
	if(c == ' ' || c=='\t' || c=='\n')
		return 1;
	else
		return 0;
}


int String(string &s, int p){
	while(isalnum(txt[++p]) || txt[p] == '_'){
		s = s + txt[p];
	}
	txt_p = p;
	for(int i=0; i<keyNum; i++){
        if(s == key[i])
        	return i+1;
    }
    return 777;//variable
}

int Number(string &s, int p){
	while(isdigit(txt[++p])){
		s = s + txt[p]; 
	}
	txt_p = p;
	return 99;//number
}

int Symbol(string &s, int p){
	int i1;
	bool flag1 = 0;
	for(i1=0; i1<symbolNum1 && !flag1; i1++)
		if(s == symbol[i1])
		{
			flag1 = 1;
			txt_p++; 
		}
	
	int i2;
	bool flag2 = 0; 
	for(i2=0; i2<symbolNum2 && !flag2; i2++)
		if((s+txt[p+1]) == symbol[symbolNum1 + i2])
		{
			flag2 = 1;
			s = s + txt[p+1];
			txt_p += 2; 
		}
			
	int n = keyNum+1;
	if(flag2)
		n += symbolNum1+i2;
	else if(flag1)
		n += i1;
		
	return n;
}


void print(string s,int n){
	printf("【  %-8s%5d  】\n", s.c_str(),n);
}
void analyse()
{
	
	while(txt_p < txt_length)
	{
		string str;
//过滤空格，tab，换行 
		if(isFilter(txt[txt_p]))
		{
			txt_p++;
			continue;
		}
		str = txt[txt_p];
		int n;//种别码 
		switch(Type(str))
		{
			case 1://字母 
				n = String(str, txt_p);
				print(str, n);
				break;
			case 2://数字 
				n = Number(str, txt_p);
				print(str, n);
				break;
			case 3://符号 
				n = Symbol(str, txt_p);
				print(str, n); 
				break;
			default:
				txt_p++;
				print(str, 0);
		}
	}
}


int main()
{
	FILE *fp;
    fp=freopen("E:\\CODE\\input.txt","r",stdin);
//	freopen("result.txt","w",stdout);
    if (fp == NULL){
        printf("Not found!\n");
        exit(-1);
    }
    
    char w;
    bool flag=false;
//去注释 
    while(!feof(fp))
	{	
		w = getchar();
    	if(flag)
		{
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
							flag2 = 0;
							txt_length--;
							break;
						}	
					}
					else if(w=='*')
						flag2 = 1;
				}
				flag = false;
				txt_length--;
				continue;
			}
		}
		else if(w=='/')	flag=true;
		
	    txt[txt_length++] = w;
    }
    txt_length--;//文末空字符 
    
    analyse();
    return 0;
}
