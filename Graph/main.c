#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

/*----------预定义--------*/
#define TRUE 1
#define OK 1
#define ERROR -1
#define OVERFLOW -2
#define FALSE 0
#define max 20
#define MAX 100

typedef int status; //数据元素类型定义
typedef int ElemType;
int visited[100];

typedef struct ArcNode{
    int adjvex;//该弧指向顶点的位序
    struct ArcNode *nextarc;//指向下一条弧
}ArcNode;//弧

typedef struct VNode{
    int num;
    int value;//值
	char key;//顶点信息
	ArcNode *firstarc;//指向第一条依附该顶点的弧的指针
}VNode,AdjList[MAX];

typedef struct{
    AdjList vertices;
    int vexnum,arcnum;//图的当前顶点数和弧数
}Graph;

typedef struct QNode{//队列结点结构
	ElemType data;
	struct QNode *next;
}QNode, *QueuePtr;

typedef struct{//队列结构
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;

status InitQueue(LinkQueue *Q);  //构造一个空队列
status QueueEmpty(LinkQueue Q);  //判断一个队列是否为空
status EnQueue(LinkQueue *Q, ElemType e);  //入队列
status DeQueue(LinkQueue *Q, ElemType *e); //出队列

status CreatGraph(Graph *G,char V[],char VR[][2]);//创建图
status DestroyGraph(Graph *G);//销毁
status DestroyList(ArcNode *arc);//销毁顶点的弧链表
status LocateVex(Graph G,char u);//由关键字查找查找顶点位序
status PutVex(Graph *G,char u,int value);//顶点赋值
status FirstAdjVex(Graph G,char u);//获得第一邻接点
status NextAdjVex(Graph G,char u,int w);//获得下一邻接点
status InsertVex(Graph *G,VNode vex);//插入顶点
status DeleteVex(Graph *G,char u);//删除顶点
status InsertArc(Graph *G,char u,char z);//插入弧
status DeleteArc(Graph *G,char u,char z);//删除弧
status DFSTraverse(Graph G,char u);//深度优先遍历
char Locatekey(Graph G,int v);//由位序查找关键字
status Locatekey2(Graph G,int v);//由位序查找序号
status Locatehao(Graph G,char u);//由关键字查找序号
status BFSTraverse(Graph G, LinkQueue Q);//广度优先遍历
status Write(Graph G);//写入文件
status Read(Graph *G);//读取文件

int main(void){
    Graph M[100];
    Graph G;//声明所需变量
    char V[100];
    char VR[100][2];
    int o,i,w,p;
    char u,z;
    ElemType value;
    VNode vex;
    LinkQueue Q;
    o=1;
    while(o){
        int op=1;
        printf("  请输入对哪个图进行操作（1-99），输入0退出！\n");
        scanf("%d",&o);//多个线性表的实现
        if(o==0)
            break;//0时退出
        else {
            if(o>99||o<0){
                printf("选择失败！\n");
                getchar();
            }
            else {
                G=M[o];
                while(op){
                    system("cls");	//printf("\n\n");
                    printf("  Menu for Linear Table On Sequence Structure \n");
                    printf("-----------------------------------------------\n");
                    printf("   1. CreatGraph        8. DeleteVex \n");
                    printf("   2. DestroyGraph      9. InsertArc\n");
                    printf("   3. LocateVex        10. DeleteArc\n");
                    printf("   4. PutVex           11. DFSTraverse\n");
                    printf("   5. FirstAdjVex      12. BFSTraverse\n");
                    printf("   6. NextAdjVex       13. Write\n");
                    printf("   7. InsertVex        14. Read\n");
                    printf("   0. Exit\n");
                    printf("-----------------------------------------------\n");
                    printf("   请选择你的操作[0~16]:\n");
                    scanf("%d",&op);
                    switch(op){
                       case 1:
                         printf("请输入图的顶点数和弧数：");
                         getchar();
                         scanf("%d %d",&(G.vexnum),&(G.arcnum));
                         printf("请输入顶点：");
                         getchar();
                         for(i=0;i<(G.vexnum);i++)
                            scanf("%c",&V[i]);
                         printf("请输入弧：");
                         getchar();
                         for(i=0;i<(G.arcnum);i++){
                            scanf("%c",&VR[i][0]);
                            scanf("%c",&VR[i][1]);
                            getchar();
                         }
                         if(CreatGraph(&G,V,VR)==OK)
                            printf("图创建成功！\n");
                         else
                            printf("图创建失败！\n");
                         getchar();
                         break;
                       case 2:
                         if(DestroyGraph(&G)==OK)
                            printf("图销毁成功！\n");
                         else
                            printf("图销毁失败！\n");
                         getchar();getchar();
                         break;
                       case 3:
                         if(G.vexnum!=0){
                             printf("请输入需要查找顶点的关键字：\n");
                             getchar();
                             scanf("%c",&u);
                             p=LocateVex(G,u);
                             if(p!=ERROR){
                                printf("该顶点的位序为：%d\n",p);
                             }
                             else
                                printf("该顶点不存在\n");
                         }
                         else
                            printf("图不存在！\n");
                         getchar();getchar();
                         break;
                       case 4:
                         if(G.vexnum!=0){
                             printf("请输入需要赋值顶点的关键字与所赋值：\n");
                             getchar();
                             scanf("%c %d",&u,&value);
                             if(PutVex(&G,u,value)==OK)
                                printf("赋值成功！\n");
                             else
                                printf("赋值失败！\n");
                         }
                         else
                            printf("图不存在！\n");
                         getchar();getchar();
                         break;
                      case 5:
                         if(G.vexnum!=0){
                             printf("请输入需要获得第一邻接点的顶点的关键字：\n");
                             getchar();
                             scanf("%c",&u);
                             p=FirstAdjVex(G,u);
                             if(p==ERROR)
                                 printf("顶点不存在！\n");
                             else
                                if(p==-2)
                                    printf("该顶点没有邻接顶点！\n");
                             else
                                printf("该顶点的第一邻接顶点的位序为：%d\n",p);
                         }
                         else
                            printf("图不存在！\n");
                         getchar();getchar();
                         break;
                       case 6:
                         if(G.vexnum!=0){
                             printf("请输入需要获得下一邻接点的顶点的关键字及邻接点位序：\n");
                             getchar();
                             scanf("%c %d",&u,&w);
                             p=NextAdjVex(G,u,w);
                             if(p==ERROR)
                                 printf("顶点不存在或顶点没有位序为%d的邻接点！\n",w);
                             else
                                if(p==NULL)
                                    printf("位序为%d的顶点为最后一个邻接点！\n",w);
                             else
                                printf("下一邻接顶点的位序为：%d\n",p);
                         }
                         else
                            printf("图不存在！\n");
                         getchar();getchar();
                         break;
                       case 7:
                         if(G.vexnum!=0){
                             printf("请输入需要插入顶点的关键字及所赋值：\n");
                             getchar();
                             scanf("%c %d",&(vex.key),&(vex.value));
                             p=InsertVex(&G,vex);
                             if(p==OK)
                                 printf("插入成功！\n");
                             else
                                printf("插入失败！\n");
                         }
                         else
                            printf("图不存在！\n");
                         getchar();getchar();
                         break;
                       case 8:
                         if(G.vexnum!=0){
                             printf("请输入需要删除顶点的关键字：\n");
                             getchar();
                             scanf("%c",&u);
                             p=DeleteVex(&G,u);
                             if(p==OK)
                                 printf("删除成功！\n");
                             else
                                printf("删除失败！\n");
                         }
                         else
                            printf("图不存在！\n");
                         getchar();getchar();
                         break;
                       case 9:
                         if(G.vexnum!=0){
                             printf("请输入需要插入弧的顶点的关键字：\n");
                             getchar();
                             scanf("%c%c",&u,&z);
                             p=InsertArc(&G,u,z);
                             if(p==OK)
                                 printf("插入成功！\n");
                             else
                                printf("插入失败！\n");
                         }
                         else
                            printf("图不存在！\n");
                         getchar();getchar();
                         break;
                       case 10:
                         if(G.vexnum!=0){
                             printf("请输入需要删除弧的顶点的关键字：\n");
                             getchar();
                             scanf("%c%c",&u,&z);
                             p=DeleteArc(&G,u,z);
                             if(p==OK)
                                 printf("删除成功！\n");
                             else
                                printf("删除失败！\n");
                         }
                         else
                            printf("图不存在！\n");
                         getchar();getchar();
                         break;
                       case 11:
                         if(G.vexnum!=0){
                             printf("请输入遍历第一个顶点的关键字：\n");
                             getchar();
                             scanf("%c",&u);
                             DFSTraverse(G,u);
                             for(i=0;i<G.vexnum;i++){
                                if(visited[i]==0)
                                   DFSTraverse(G,G.vertices[i].key);
                             }
                             for(i=0;i<G.vexnum;i++){
                                visited[i]=0;
                             }
                         }
                         else
                            printf("图不存在！\n");
                         getchar();getchar();
                         break;
                       case 12:
                         if(G.vexnum!=0){
                             InitQueue(&Q);
                             printf("广度遍历：\n");
                             BFSTraverse(G,Q);
                             for(i=0;i<G.vexnum;i++){
                                visited[i]=0;
                             }
                         }
                         else
                            printf("图不存在！\n");
                         getchar();getchar();
                         break;
                       case 13:
                         if(G.vexnum!=0){
                             if(Write(G)==OK)
                                printf("写入成功！\n");
                             else
                                printf("写入失败！\n");
                         }
                         else
                            printf("图不存在！\n");
                         getchar();getchar();
                         break;
                       case 14:
                         if(Read(&G)==OK)
                            printf("写入成功！\n");
                         else
                            printf("写入失败！\n");
                         getchar();getchar();
                         break;
                       case 0:
                         break;
                     }
                }//end of switch
            }
        }
    }//end of while
    printf("欢迎下次再使用本系统！\n");
}//end of main()

status CreatGraph(Graph *G,char V[],char VR[][2]){
    int i,j,k;
    ArcNode *p;
    ArcNode *q;
    char u;
    k=0;
    int a[100][2]={0};
    for(i=0;i<(G->vexnum);i++){//顶点构造
	    G->vertices[i].key=V[i];
	    G->vertices[i].num=i;
        G->vertices[i].firstarc=NULL;
    }
    for(i=0;i<(G->arcnum);i++){//关键字转换成位序
        u=VR[i][0];
        a[i][0]=LocateVex(*G,u);
        u=VR[i][1];
        a[i][1]=LocateVex(*G,u);
    }
    /*for(i=0;i<(G->vexnum);i++){//尾插法 
        q=G->vertices[i].firstarc;
        for(j=0;j<(G->arcnum);j++){
            if(a[j][0]==i){
                p=(ArcNode*)malloc(sizeof(ArcNode));
                p->adjvex=a[j][1];
                p->nextarc=q;
                q=p;
                G->vertices[i].firstarc=p;
            }
        }
    }*///邻接表创建
    for(j=0;j<(G->arcnum);j++){
        k=a[j][0];
        q=G->vertices[k].firstarc;
        if(q==NULL){
            p=(ArcNode*)malloc(sizeof(ArcNode));
            p->adjvex=a[j][1];
            p->nextarc=NULL;
            G->vertices[k].firstarc=p;
        }
        else{
            while((q->nextarc)!=NULL){
                q=q->nextarc;
            }
            p=(ArcNode*)malloc(sizeof(ArcNode));
            p->adjvex=a[j][1];
            p->nextarc=NULL;
            q->nextarc=p;
            }
        }
    return OK;
}

status DestroyGraph(Graph *G){
    int i;
    for(i=0;i<G->vexnum;i++){//对于所有的顶点
        if(G->vertices[i].firstarc){
        	if(DestoryList(G->vertices[i].firstarc)==OK);//销毁顶点的弧链表
        else
            return ERROR;
		}
    }
    free(G->vertices);
    G->vexnum=0;//顶点数为0
    G->arcnum=0;//边或者弧数为0
    return OK;
}

status DestoryList(ArcNode *arc){
    ArcNode *p=arc;
    ArcNode *q;
    if(arc){
        for(;arc!=NULL;){//遍历单链表
            q=arc;
            arc=arc->nextarc;
            free(q);//释放线性表空间
        }
        arc=NULL;
        return OK;
    }
    else
        return ERROR;
}

status LocateVex(Graph G,char u){
    int i;
    for(i=0;i<(G.vexnum);i++){//遍历查找 
        if(G.vertices[i].key==u){
            return G.vertices[i].num;
        }
    }
    return ERROR;
}

status Locatehao(Graph G,char u){//由关键字查找序号
    int i;
    for(i=0;i<(G.vexnum);i++){
        if(G.vertices[i].key==u){
            return i;
        }
    }
    return ERROR;
}

status PutVex(Graph *G,char u,int value){//顶点赋值
    int p;
    p=LocateVex(*G,u);//查找顶点位序
    if(p!=ERROR){
        G->vertices[p].value=value;
        return OK;
    }
    else
        return ERROR;
}

status FirstAdjVex(Graph G,char u){
    int p;
    p=LocateVex(G,u);
    if(p!=ERROR){//顶点v存在
        if(G.vertices[p].firstarc)//顶点有邻接点
            return G.vertices[p].firstarc->adjvex;//返回第一邻接顶点的位序
        else
            return -2;//顶点无邻接点
    }
    else
        return ERROR;//顶点v不存在
}

status NextAdjVex(Graph G,char u,int w){
    int i;
    int t;
    ArcNode *p;
    t=Locatehao(G,u);
    if(t!=ERROR){//顶点v存在
        p=G.vertices[t].firstarc;//p为第一邻接点
        for(i=0;p!=NULL;i++){//查找位序为w的邻接点
            if(p->adjvex==w){
                if(p->nextarc)//p不为最后一个邻接点
                    return p->nextarc->adjvex;
                else
                    return NULL;
            }
            p=p->nextarc;
        }
        return ERROR;//没有位序为w的邻接点
    }
    else
        return ERROR;
}

status InsertVex(Graph *G,VNode vex){//插入顶点 
    G->vertices[G->vexnum].key=vex.key;
    G->vertices[G->vexnum].value=vex.value;
    G->vertices[G->vexnum].firstarc=NULL;
    G->vertices[G->vexnum].num=G->vexnum;
    G->vexnum=G->vexnum+1;//顶点数增加 
    return OK;
}

status DeleteVex(Graph *G,char u){//删除顶点 
    int i,v;
    ArcNode *p;
    ArcNode *q;
    v=LocateVex(*G,u);
    if(v!=ERROR){
        for(i=0;i<G->vexnum;i++){//删除含有该顶点的弧 
            p=G->vertices[i].firstarc;
            if((p!=NULL)&&(p->nextarc!=NULL)){
                if(p->adjvex==v){
                    G->vertices[i].firstarc=p->nextarc;
                }
                else{
                    p=G->vertices[i].firstarc;
                    q=p->nextarc;
                    while(q!=NULL){
                        if(q->adjvex!=v){
                            p=p->nextarc;
                            q=q->nextarc;
                        }
                        else{
                            p->nextarc=q->nextarc;
                            q=NULL;
                        }
                    }
                }
            }
            else
                if((p!=NULL)&&(p->nextarc==NULL))
                    if(p->adjvex==v)
                        p=NULL;

        }
        DestoryList(G->vertices[v].firstarc);
        for(i=v;i<G->vexnum;i++){//顶点v后面的顶点前移
            G->vertices[i]=G->vertices[i+1];
        }
        G->vexnum--;
        return OK;
    }
    else
        return ERROR;
}

status InsertArc(Graph *G,char u,char z){//插入弧 
    int x,y;
    ArcNode *p;
    x=Locatehao(*G,u);
    y=LocateVex(*G,z);
    p=(ArcNode*)malloc(sizeof(ArcNode));
    if((x!=ERROR)&&(y!=ERROR)){//顶点存在 
        p->adjvex=y;
        if(G->vertices[x].firstarc){
            p->nextarc=G->vertices[x].firstarc->nextarc;
            G->vertices[x].firstarc=p;
        }
        else{
            p->nextarc=G->vertices[x].firstarc;
            G->vertices[x].firstarc=p;
        }
    }
    G->arcnum++;//弧数量增加 
    return OK;
}

status DeleteArc(Graph *G,char u,char z){//删除弧 
    int x,y;
    ArcNode *p;
    ArcNode *q;
    x=Locatehao(*G,u);
    y=LocateVex(*G,z);
    if((x!=ERROR)&&(y!=ERROR)){//判断顶点是否存在 
        p=G->vertices[x].firstarc;
        q=p->nextarc;
        if((p!=NULL)&&(p->nextarc!=NULL)){//避免空指针的使用 
            if(p->adjvex==y){
                G->vertices[x].firstarc=p->nextarc;
                p=NULL;
            }
            else{
                p=G->vertices[x].firstarc;
                q=p->nextarc;
                while(q!=NULL){
                    if(q->adjvex!=y){
                        p=p->nextarc;
                        q=q->nextarc;
                    }
                    else{
                        p->nextarc=q->nextarc;
                        q=NULL;
                    }
                }
            }
        }
        else
            if((p!=NULL)&&(p->nextarc=NULL))
                if(p->adjvex==y)
                    p=NULL;
    }
    G->arcnum--;
    return OK;
}

status DFSTraverse(Graph G,char u){//深度优先遍历 
	int v;
	char z;
	ArcNode *p;
	v=Locatehao(G,u);
	if(visited[v]==0){
		printf("%c %d\n", G.vertices[v].key,G.vertices[v].value);
		visited[v]=1;//标记已访问
		p=G.vertices[v].firstarc;
		while(p!=NULL){
			if(visited[p->adjvex]==0){
                z=Locatekey(G,p->adjvex);
				DFSTraverse(G,z);
			}
			p=p->nextarc;
		}
	}
}

char Locatekey(Graph G,int v){//由位序找关键字
    int i;
    for(i=0;i<(G.vexnum);i++){//顶点构造
        if(G.vertices[i].num==v){
            return G.vertices[i].key;
        }
    }
    return ERROR;
}

status Locatekey2(Graph G,int v){//由位序找序号
    int i;
    for(i=0;i<(G.vexnum);i++){//顶点构造
        if(G.vertices[i].num==v){
            return i;
        }
    }
    return ERROR;
}

status BFSTraverse(Graph G, LinkQueue Q){//广度优先遍历 
	int v,u,i,num;
	char k;
	ArcNode *temp;
	for(v=0;v<G.vexnum;v++)
		visited[v]=0;
	for(v=0;v<G.vexnum;v++){
		if(!visited[v]){
			visited[v]=1;
			printf("%c %d\n", G.vertices[v].key,G.vertices[v].value);
            num=LocateVex(G,G.vertices[v].key);//位序
			EnQueue(&Q,num);
			while(!QueueEmpty(Q)){
				DeQueue(&Q,&u);
				i=Locatekey2(G,u);//由位序找序号
				for(temp=G.vertices[i].firstarc;temp!=NULL;temp=temp->nextarc){
                    k=Locatekey(G,temp->adjvex);
                    num=LocateVex(G,k);
                    i=Locatehao(G,k);
					if (visited[i]!=1) {
						visited[i]=1;
						printf("%c %d\n", G.vertices[i].key,G.vertices[i].value);
						EnQueue(&Q,num);
					}
				}
			}
		}
	}
	return OK;
}

status InitQueue(LinkQueue *Q){//构造一空的队列Q
	Q->front=Q->rear=(QueuePtr)malloc(sizeof(QNode));
	if (!Q->front)
		exit(OVERFLOW);
	Q->front->next=NULL;
	return OK;
}

status QueueEmpty(LinkQueue Q){//若Q为空,返回TRUE,不空则返回FALSE
	if(Q.front==Q.rear)
		return TRUE;
	else
		return FALSE;
}

status EnQueue(LinkQueue *Q,ElemType e){//插入元素e为Q的新的队尾元素
	QueuePtr p=(QueuePtr)malloc(sizeof(QNode));
	if (!p)//存储分配失败
		exit(OVERFLOW);
	p->data=e;
	p->next=NULL;
	Q->rear->next=p;
	Q->rear=p;
	return OK;
}

status DeQueue(LinkQueue *Q,ElemType *e){//若队列不空,删除Q的队头元素,用e返回其值,并返回OK,否则返回ERROR
	QueuePtr p;
	if (Q->front==Q->rear)
		return ERROR;
	p=Q->front->next;
	*e=p->data;
	Q->front->next=p->next;
	if(Q->rear==p)
		Q->rear=Q->front;
	free(p);
	return OK;
}

status Write(Graph G){//写入文件
    FILE  *fp=NULL;
    char filename[30];
    printf("input file name: ");
    scanf("%s",filename);
    if ((fp=fopen(filename,"wb"))==NULL){
        printf("File open error\n ");
        return FALSE;
    }
    //写文件的方法
    int i;
    int j;
    ArcNode *p;
    fwrite(&G.vexnum,sizeof(int),1,fp);//写入图的信息 
    fwrite(&G.arcnum,sizeof(int),1,fp);
    for(i=0;i<G.vexnum;i++){//写入顶点信息 
        fwrite(&G.vertices[i].key,sizeof(char),1,fp);
        fwrite(&G.vertices[i].value,sizeof(int),1,fp);
        fwrite(&G.vertices[i].num,sizeof(int),1,fp);
    }
    for(i=0;i<G.vexnum;i++){
        p=G.vertices[i].firstarc;
        while(p!=NULL){
            fwrite(&G.vertices[i].num,sizeof(int),1,fp);
            j=Locatekey2(G,p->adjvex);
            fwrite(&G.vertices[j].num,sizeof(int),1,fp);
            p=p->nextarc;
        }
    }
    fclose(fp);
    return OK;
}

status Read(Graph *G){//读取文件
    FILE  *fp;
    char filename[30];
    printf("input file name: ");
    scanf("%s",filename);
    if ((fp=fopen(filename,"rb"))==NULL){
        printf("File open error\n ");
        return FALSE;
    }
    //读文件的方法
    int i=0;
    int a=-1;
    int j;
    ArcNode *p;
    ArcNode *q;
    fread(&G->vexnum,sizeof(int),1,fp);
    fread(&G->arcnum,sizeof(int),1,fp);
    for(i=0;i<G->vexnum;i++){//构造顶点 
        fread(&G->vertices[i].key,sizeof(char),1,fp);
        fread(&G->vertices[i].value,sizeof(int),1,fp);
        fread(&G->vertices[i].num,sizeof(int),1,fp);
    }
    while(fread(&a,sizeof(int),1,fp)){//将弧读取并构造邻接表，尾插法 
        j=Locatekey2(*G,a);
        q=G->vertices[j].firstarc;
        if(q==NULL){
            p=(ArcNode*)malloc(sizeof(ArcNode));
            fread(&p->adjvex,sizeof(int),1,fp);
            p->nextarc=NULL;
            G->vertices[j].firstarc=p;
        }
        else{
            while((q->nextarc)!=NULL){
                q=q->nextarc;
            }
            p=(ArcNode*)malloc(sizeof(ArcNode));
            fread(&p->adjvex,sizeof(int),1,fp);
            p->nextarc=NULL;
            q->nextarc=p;
        }
    }
	fclose(fp);
    return OK;
}

