#include <bits/stdc++.h> 
#define N 1024
using namespace std;
string key[32]={"int","return","void","if","else","var","char","break","do","while","for","double","float","short","not","true","false"};
int keynum[32]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17}; 

string symbol[32]={"=","<",">","!=",">=","<=","==",",",";","(",")","{","}","+","-","*","/","%","&"};
//char symbol[12]={'<','>','!=','>=','<=','==',',',';','(',')','{','}'};
int symbolnum[32]={18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36};

string ch[N],words[N];
int len=0,num;

int Type(string str){
    if(str>="a" && str<="z")   // 字母 
        return 1;

    if(str>="0" && str<="9")   //数字 
        return 2;

    if(str==">"||str=="="||str=="<"||str=="!"||str==","||str==";"||str=="("||str==")"||str=="{"||str=="}"
        ||str=="+"||str=="-"||str=="*"||str=="/")   //运算符和界符 
        return 3; 

}

int Key(string s){	//判断关键字 
    for(int i=0;i<17;i++){
        if(s==key[i])
            return keynum[i];
    }
    return 0;
}

int Symbol(string s){ //判断运算符和界符 
    for(int i=0;i<19;i++){
        if(s==symbol[i])
            return symbolnum[i]; 
    }
    return 0;
} 


bool Str(string s)	//判断字母 
{
    if((s>="a" && s<="z") || (s>="A" && s<="Z"))
        return true;
    return false;
}

bool Num(string s){	//判断数字 
    if(s>="0" && s<="9")
        return true;
    return false;
}

string then(string s,int n){	//接符号 
    int j=n+1;
    string str=ch[j];
    if(str==">"||str=="="||str=="<"||str=="!") {
        s=(s+ch[j]).c_str();
        j++;
    }
    num=j;						//bug2	乱接 
    return s;
}

string String(string s,int n){	//标识符 
    int j=n+1;
    int flag=1;

    while(flag){
        if(Num(ch[j]) || Str(ch[j])){
        	s=s+ch[j];
            //s=(s+letter[j]).c_str();
            j++;
            if(Key(s)){	//Bug1: inta变量问题 
                num=j;
                return s;
            }
        }
        else	flag=0;
    } 

    num=j;
    return s;
}

string Number(string s,int n){
    int j=n+1;
    int flag=1;

    while(flag){
        if(Num(ch[j])){
            s=(s+ch[j]).c_str();
            j++;
        }
        else{
            flag=0;
        }
    }

    num=j;
    return s;
}

void print(string s,int n){
	printf(" 【   %s       %d 】\n",s.c_str(),n);
  //  cout<<"【  "<<s<<"       "<<n<<" 】"<<endl;
}

void analyse(){	//词法分析 
    int k;

    for(num=0;num<len;){
        string str1,str;
        str=ch[num];
        k=Type(str);
        switch(k){
            case 1:
                {
                    str1=String(str,num);
                    if(Key(str1))
                        print(str1,Key(str1));
                    else
                        print(str1,99);
                    break;
                }

            case 2:
                {
                    str1=Number(str,num);
                    print(str1,24);
                    break;
                }

            case 3:
                {
                    str1=then(str,num);
                    print(str1,Symbol(str1));
                    break;  
                }

        }

    } 
}

int main(){
    char w;
    int i,j;
    bool flag=false,f=false;
	FILE *fp;
	
    fp=freopen("E:\input.txt","r",stdin);//绝对路径打开文本 
 //   freopen("result.txt","w",stdout);
    if (fp == NULL)
    {
        printf("Not found!\n");
        return 0;
    }
    
    while(cin>>w){	//文本输入 去空格、注释 
        if(w!=' '){
        	if(flag)
				if(w!='/' && w!='*')	flag=false;
        	if(flag && w=='/'){
        		while(w=getchar()!='\n');
				flag=false;	len--; 
				continue;
			}
			if(flag && w=='*'){
				while(cin>>w){
					if(w=='*' && getchar()=='/'){
						flag==false;	len--;
						break;
					}
				}
				continue;
			}
        	if(w=='/')	flag=true;
			
            ch[len]=w;
            len++;
        }
    }
	printf("问题较多，还不完善，抱歉\n"); 
    analyse();
//	宏定义、token 等诸多不完善 
    return 0;
} 
