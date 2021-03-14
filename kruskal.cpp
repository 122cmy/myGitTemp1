#include<iostream>
using namespace std;
#define MAX 32767//����ֵ 
//ͼ���ڽӾ��� 
typedef struct{
    char vertex[100];//���� 
	int graph[100][100];//�� 
	int verNum,graphNum;//������������ 
}Graph;
struct{
	char begin;//��� 
	char end;//�յ� 
	int value;//Ȩֵ 
}Edge[99*50];
//�������飺�Ƿ���һ��������
int Veset[100];
int SearchIndex(Graph G,char v){
	for(int i=0;i<G.verNum;++i)
	    if(G.vertex[i]==v)
	       return i;
	    return -1;
	
}

void Greate(Graph &G){
	cin>>G.verNum>>G.graphNum;
	for(int i=0;i<G.verNum;i++){
		printf("�����룺"); 
	  cin>>G.vertex[i];
    }
	for(int i=0;i<G.verNum;++i){
		for(int j=0;j<G.verNum;++j){
			G.graph[i][j]=MAX;
		}
	}
	char v1,v2;
	for(int k=0;k<G.graphNum;++k){
		int weight,i,j;
		cin>>v1>>v2>>weight;
		i=SearchIndex(G,v1);
		j=SearchIndex(G,v2);
		G.graph[i][j]=weight;
		G.graph[j][i]=G.graph[i][j];
		Edge[k].value=weight;
		Edge[k].begin=v1;
		Edge[k].end=v2;
	}
}
void sort(Graph G){
	char temp1;
	char temp2;
	char temp3;
	int kk=G.graphNum-2;
	int isFlag=1;
	while(kk>0 && isFlag==1){
		isFlag=0;
		for(int i=0;i<=kk;i++){
			if(Edge[i].value>Edge[i+1].value){
				isFlag=1;
				temp1=Edge[i].begin;
				Edge[i].begin=Edge[i+1].begin;
				Edge[i+1].begin=temp1;
				temp2=Edge[i].end;
				Edge[i].end=Edge[i+1].end;
				Edge[i+1].end=temp2;
				temp3=Edge[i].value;
				Edge[i].value=Edge[i+1].value;
				Edge[i+1].value=temp3;
			}
		}
		--kk; 
	}
}
void kruskal(Graph G){
	int a,b,a1,b1;
	sort(G);
	for(int i=0;i<G.verNum;++i){
		Veset[i]=i;
	}
	//����С�ıߣ����Ƿ���ͬһ������ 
	for(int i=0;i<G.graphNum;++i){
		a=SearchIndex(G,Edge[i].begin);
		b=SearchIndex(G,Edge[i].end);
		a1=Veset[a];
		b1=Veset[b];
		if(a1!=b1){
			cout<<Edge[i].begin<<Edge[i].end<<Edge[i].value<<endl;
			for(int j=0;j<G.verNum;++j){
				if(Veset[j]==b1)
				Veset[j]=a1;//���Ϻϲ� 
			}
		}
	}
}
int main(){
	Graph G;
	Greate(G);
	kruskal(G);
}



	

