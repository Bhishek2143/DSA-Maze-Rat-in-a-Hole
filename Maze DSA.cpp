#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>
#define size 100
 struct stack {
  	int array[100][4];
  	char c[100];
  	int top;
  }stack1;
  void push(char c,int si,int sj,int pi,int pj){
	if( stack1.top==size-1 ){
		printf("error: stack is full ");
		return ;
	}
		stack1.top++;
		stack1.c[stack1.top]=c;
		stack1.array[stack1.top][0]=si;
		stack1.array[stack1.top][1]=sj;
		stack1.array[stack1.top][2]=pi;
		stack1.array[stack1.top][3]=pj;
	return ;
}
char pop(int *si,int *sj,int *pi,int *pj){
	if(stack1.top==-1){
		//printf("error: stack is empety \n");
		return '\0';
	}
	char c=stack1.c[stack1.top];
	    *si = stack1.array[stack1.top][0];
		*sj = stack1.array[stack1.top][1];
		*pi = stack1.array[stack1.top][2];
		*pj = stack1.array[stack1.top][3];
	stack1.top--;
	return c;
}
float dis(int si,int sj,int pi,int pj){
	return sqrt((si-pi)(si-pi) + (sj-pj)(sj-pj));
}

void movesnake(int *si,int *sj,int pi,int pj,int m,int n, char *a[]){
	float l=3.4e+038,r=3.4e+038,u=3.4e+038,d=3.4e+038;
	int i=0,j=0;float min=3.4e+038;
	if(a[*si+1][*sj]!='-'&& a[*si+1][*sj]!='O'&&a[*si+1][*sj]!='X'){
		d=dis(*si+1,*sj,pi,pj);
		min=d;i=1;j=0;
	}
	if(a[*si-1][*sj]!='-'&& a[*si-1][*sj]!='O'&&a[*si-1][*sj]!='X'){
		u=dis(*si-1,*sj,pi,pj);
		if(min>u){
			min=u;i=-1;j=0;
		}
	}
		if(a[*si][*sj-1]!='|'&& a[*si][*sj-1]!='O'&&a[*si][*sj-1]!='X'){
		l=dis(*si,*sj-1,pi,pj);
		if(min>l){
			min=l;i=0;j=-1;
		}
	}
		if(a[*si][*sj+1]!='|'&& a[*si][*sj+1]!='O'&&a[*si][*sj+1]!='X'){
		r=dis(*si,*sj+1,pi,pj);
		if(min>r){
			min=r;i=0;j=1;
		}
	}
	*si=*si+i;*sj=*sj+j;
	a[*si-i][*sj-j]=' ';
	a[*si][*sj]='~';
}
int main()
{
  FILE *fileptr;
  char  option, ch;
  int x, i=0, j=0, pi,pj,si,sj,wi,wj;
  fileptr = fopen("mazegame map.txt","r");
    stack1.top =-1;
    printf(" \n\n RULES FOR THE GAME ARE: ");
    printf(" \n  1.Press w to move the player up ");
    printf(" \n  2.Press s to move the player down ");
    printf(" \n  3.Press a to move the player left ");
    printf(" \n  4.Press d to move the player right ");
    printf("\n");
    int ar;
     
    fscanf(fileptr,"%d",&ar);
    int read[ar+1][3];
    read[0][0]=ar;fscanf(fileptr,"%d",&read[0][1]);fscanf(fileptr,"%d",&read[0][2]);
    for(i=1;i<ar+1;i++){
   	fscanf(fileptr,"%d",&read[i][0]);
   	fscanf(fileptr,"%d",&read[i][1]);
   	fscanf(fileptr,"%d",&read[i][2]);
    }
    fclose(fileptr);
    char *a =(char*)malloc(read[0][1] *sizeof(char *));
    int w;
	for( w=0;w<read[0][1];w++){
        a[w]=(char *)malloc(read[0][2]*sizeof(char));
    }
    for(i=0;i<read[0][1];i++){
    	for(j=0;j<read[0][2];j++){
    		if((i==0&&j==0)||(i==0&&j==read[0][2]-1)||(i==read[0][1]-1&&j==0)||(i==read[0][1]-1&&j==read[0][2]-1)){
    			a[i][j]='#';
			}
			else if(i==0&&(j>0&&j<read[0][2]-1)||i==read[0][1]-1&&(j>0&&j<read[0][2]-1)){
				a[i][j]='-';
			}
			else if(j==0&&(i>0&&j<read[0][1]-1)||((j==read[0][2]-1)&&(i>0&&i<read[0][1]-1))){
				a[i][j]='|';
			}
			else{
				a[i][j]=' ';
			}
		}
	}
	for(i=1;i<=read[0][0];i++){
		if(read[i][2]==0){
			a[read[i][0]][read[i][1]]='^';pi=read[i][0];pj=read[i][1];
		}
		else if(read[i][2]==1){
			a[read[i][0]][read[i][1]]='~';si=read[i][0];sj=read[i][1];
		}
		else if(read[i][2]==2){
			a[read[i][0]][read[i][1]]='X';wi=read[i][0];wj=read[i][1];
		}
		else if(read[i][2]==3){
			a[read[i][0]][read[i][1]]='O';
		}
	}
    
	for(i=0;i<read[0][1];i++){
		for(j=0;j<read[0][2];j++){
			printf("%c",a[i][j]);
		}
		printf("\n");
	}
push('^',si,sj,pi,pj);
    while(1)
    {
        
       option = getch();
	
        switch(option)
        {
            case 'w' :
            {
               if(a[pi-1][pj]!='-'&& a[pi-1][pj]!='O' )
			   {
				 a[pi][pj]=' ';
                a[--pi][pj]='^';}
                push('^',si,sj,pi,pj);
                system("cls");int i,j;
                for(  i=0; i<read[0][1]; i++)
                { for( j=0; j<read[0][2]; j++) 
                 {
                    printf("%c", a[i][j]);
                 } printf("\n");
                } break;

            } 
            case 's' :
            {
                if(a[pi+1][pj]!='-'&& a[pi+1][pj]!='O')
			    {
				a[pi][pj]=' ';
                a[++pi][pj]='v';}
                push('v',si,sj,pi,pj);
                system("cls");int i,j;
                for( i=0; i<read[0][1]; i++)
                { for( j=0; j<read[0][2]; j++) 
                 {
                    printf("%c", a[i][j]);
                 } printf("\n");
                } break;

            } 
            case 'a' :
            {
                if(a[pi][pj-1]!='|'&& a[pi][pj-1]!='O')
				{
				a[pi][pj]=' ';
                a[pi][--pj]='<';}
                push('<',si,sj,pi,pj);
                system("cls");int i,j;
                for(  i=0; i<read[0][1]; i++)
                { for( j=0; j<read[0][2]; j++) 
                 {
                    printf("%c", a[i][j]);
                 } printf("\n");
                } break;

            } 
            case 'd' :
            {
            	if(a[pi][pj+1]!='|'&& a[pi][pj+1]!='O')
                {
				a[pi][pj]=' ';
                a[pi][++pj]='>';}
                push('>',si,sj,pi,pj);
                system("cls");int i,j;
                for( i=0; i<read[0][1]; i++)
                { for(  j=0; j<read[0][2]; j++) 
                 {
                    printf("%c", a[i][j]);
                 } printf("\n");
                } break;
                 
            }
            case 'u' :
            {
            	int l=pi,m=pj,n=si,o=sj;
            	char c1 = pop(&si,&sj,&pi,&pj);
				if(c1){
				a[l][m]=' ';
            	a[n][o]=' ';
            	a[pi][pj]=c1;
            	a[si][sj]='~';
            	system("cls");int i,j;
                for( i=0; i<read[0][1]; i++)
                { for(  j=0; j<read[0][2]; j++) 
                 {
                    printf("%c", a[i][j]);
                 } printf("\n");
                } }
				else continue; break;
			}
        }
        if(pi==wi&&pj==wj){
        	printf("YOU WIN");
        	return 0;
		}
		if(si==pi&&sj==pj){
        	printf("YOU LOOSE");
        	return 0;
		}
        int l=read[0][1],r=read[0][2];
        movesnake(&si,&sj,pi,pj,l,r,a);
       if(si==pi&&sj==pj){
        	printf("YOU LOOSE");
        	return 0;
		}
    }
	 return 0;
}
