#include<stdio.h>
#include<stdlib.h>  
#define NUM 1000
int graph[NUM][NUM]; 
void prim(int graph[][NUM],int vertex);
int main()  
{    
    int vertex,sides,a,b,value;
    int max=100000000;
	scanf("%d %d",&vertex,&sides);//输入点和边数 
	for(int i=1;i<=vertex;i++){
		for(int j=1;j<=vertex;j++){
			graph[i][j]=max;//初始赋为无穷大的数 
		}
	}
	for(int i=1;i<=sides;i++){
		scanf("%d %d %d",&a,&b,&value);//输入点、权值 
		graph[a][b]=value;//给邻接矩阵赋值 
		graph[b][a]=graph[a][b];
	}
	prim(graph,vertex);	
} 
void prim(int graph[][NUM],int vertex){
	int minDistance[NUM];
	int beginID[NUM];
	int sum=0;
	for(int i=2;i<=vertex;i++){
		minDistance[i]=graph[1][i];//与1相邻的路径长度 
		beginID[i]=1;//初始化刚开始都是从1开始 
	}
	for(int i=2;i<=vertex;i++){
		int min=100000000;
		int index=0;//最小权值的下标 
		for(int j=2;j<=vertex;j++){
		    if(minDistance[j]<min && minDistance[j]!=0){
			    min=minDistance[j];
			    index=j;
		    }
	    }
	    printf("每次的最小边:");
	    printf("%d %d %d\n",beginID[index],index,min);
	    minDistance[index]=0;//将该点标明已选过 
	    sum=sum+min;
	    for(int j=2;j<=vertex;j++){
		    if(graph[index][j]<minDistance[j]){
			   minDistance[j]=graph[index][j];
			   beginID[j]=index;
		    }
	    }
    }
    printf("最小生成树边的最小值:");
	printf("%d",sum);
}
