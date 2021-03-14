#include<stdio.h>
#include<stdlib.h>  
#define NUM 1000
int graph[NUM][NUM]; 
void prim(int graph[][NUM],int vertex);
int main()  
{    
    int vertex,sides,a,b,value;
    int max=100000000;
	scanf("%d %d",&vertex,&sides);//�����ͱ��� 
	for(int i=1;i<=vertex;i++){
		for(int j=1;j<=vertex;j++){
			graph[i][j]=max;//��ʼ��Ϊ�������� 
		}
	}
	for(int i=1;i<=sides;i++){
		scanf("%d %d %d",&a,&b,&value);//����㡢Ȩֵ 
		graph[a][b]=value;//���ڽӾ���ֵ 
		graph[b][a]=graph[a][b];
	}
	prim(graph,vertex);	
} 
void prim(int graph[][NUM],int vertex){
	int minDistance[NUM];
	int beginID[NUM];
	int sum=0;
	for(int i=2;i<=vertex;i++){
		minDistance[i]=graph[1][i];//��1���ڵ�·������ 
		beginID[i]=1;//��ʼ���տ�ʼ���Ǵ�1��ʼ 
	}
	for(int i=2;i<=vertex;i++){
		int min=100000000;
		int index=0;//��СȨֵ���±� 
		for(int j=2;j<=vertex;j++){
		    if(minDistance[j]<min && minDistance[j]!=0){
			    min=minDistance[j];
			    index=j;
		    }
	    }
	    printf("ÿ�ε���С��:");
	    printf("%d %d %d\n",beginID[index],index,min);
	    minDistance[index]=0;//���õ������ѡ�� 
	    sum=sum+min;
	    for(int j=2;j<=vertex;j++){
		    if(graph[index][j]<minDistance[j]){
			   minDistance[j]=graph[index][j];
			   beginID[j]=index;
		    }
	    }
    }
    printf("��С�������ߵ���Сֵ:");
	printf("%d",sum);
}
