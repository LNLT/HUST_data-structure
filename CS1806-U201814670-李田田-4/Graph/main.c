#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

/*----------Ԥ����--------*/
#define TRUE 1
#define OK 1
#define ERROR -1
#define OVERFLOW -2
#define FALSE 0
#define max 20
#define MAX 100

typedef int status; //����Ԫ�����Ͷ���
typedef int ElemType;
int visited[100];

typedef struct ArcNode{
    int adjvex;//�û�ָ�򶥵��λ��
    struct ArcNode *nextarc;//ָ����һ����
}ArcNode;//��

typedef struct VNode{
    int num;
    int value;//ֵ
	char key;//������Ϣ
	ArcNode *firstarc;//ָ���һ�������ö���Ļ���ָ��
}VNode,AdjList[MAX];

typedef struct{
    AdjList vertices;
    int vexnum,arcnum;//ͼ�ĵ�ǰ�������ͻ���
}Graph;

typedef struct QNode{//���н��ṹ
	ElemType data;
	struct QNode *next;
}QNode, *QueuePtr;

typedef struct{//���нṹ
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;

status InitQueue(LinkQueue *Q);  //����һ���ն���
status QueueEmpty(LinkQueue Q);  //�ж�һ�������Ƿ�Ϊ��
status EnQueue(LinkQueue *Q, ElemType e);  //�����
status DeQueue(LinkQueue *Q, ElemType *e); //������

status CreatGraph(Graph *G,char V[],char VR[][2]);//����ͼ
status DestroyGraph(Graph *G);//����
status DestroyList(ArcNode *arc);//���ٶ���Ļ�����
status LocateVex(Graph G,char u);//�ɹؼ��ֲ��Ҳ��Ҷ���λ��
status PutVex(Graph *G,char u,int value);//���㸳ֵ
status FirstAdjVex(Graph G,char u);//��õ�һ�ڽӵ�
status NextAdjVex(Graph G,char u,int w);//�����һ�ڽӵ�
status InsertVex(Graph *G,VNode vex);//���붥��
status DeleteVex(Graph *G,char u);//ɾ������
status InsertArc(Graph *G,char u,char z);//���뻡
status DeleteArc(Graph *G,char u,char z);//ɾ����
status DFSTraverse(Graph G,char u);//������ȱ���
char Locatekey(Graph G,int v);//��λ����ҹؼ���
status Locatekey2(Graph G,int v);//��λ��������
status Locatehao(Graph G,char u);//�ɹؼ��ֲ������
status BFSTraverse(Graph G, LinkQueue Q);//������ȱ���
status Write(Graph G);//д���ļ�
status Read(Graph *G);//��ȡ�ļ�

int main(void){
    Graph M[100];
    Graph G;//�����������
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
        printf("  ��������ĸ�ͼ���в�����1-99��������0�˳���\n");
        scanf("%d",&o);//������Ա��ʵ��
        if(o==0)
            break;//0ʱ�˳�
        else {
            if(o>99||o<0){
                printf("ѡ��ʧ�ܣ�\n");
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
                    printf("   ��ѡ����Ĳ���[0~16]:\n");
                    scanf("%d",&op);
                    switch(op){
                       case 1:
                         printf("������ͼ�Ķ������ͻ�����");
                         getchar();
                         scanf("%d %d",&(G.vexnum),&(G.arcnum));
                         printf("�����붥�㣺");
                         getchar();
                         for(i=0;i<(G.vexnum);i++)
                            scanf("%c",&V[i]);
                         printf("�����뻡��");
                         getchar();
                         for(i=0;i<(G.arcnum);i++){
                            scanf("%c",&VR[i][0]);
                            scanf("%c",&VR[i][1]);
                            getchar();
                         }
                         if(CreatGraph(&G,V,VR)==OK)
                            printf("ͼ�����ɹ���\n");
                         else
                            printf("ͼ����ʧ�ܣ�\n");
                         getchar();
                         break;
                       case 2:
                         if(DestroyGraph(&G)==OK)
                            printf("ͼ���ٳɹ���\n");
                         else
                            printf("ͼ����ʧ�ܣ�\n");
                         getchar();getchar();
                         break;
                       case 3:
                         if(G.vexnum!=0){
                             printf("��������Ҫ���Ҷ���Ĺؼ��֣�\n");
                             getchar();
                             scanf("%c",&u);
                             p=LocateVex(G,u);
                             if(p!=ERROR){
                                printf("�ö����λ��Ϊ��%d\n",p);
                             }
                             else
                                printf("�ö��㲻����\n");
                         }
                         else
                            printf("ͼ�����ڣ�\n");
                         getchar();getchar();
                         break;
                       case 4:
                         if(G.vexnum!=0){
                             printf("��������Ҫ��ֵ����Ĺؼ���������ֵ��\n");
                             getchar();
                             scanf("%c %d",&u,&value);
                             if(PutVex(&G,u,value)==OK)
                                printf("��ֵ�ɹ���\n");
                             else
                                printf("��ֵʧ�ܣ�\n");
                         }
                         else
                            printf("ͼ�����ڣ�\n");
                         getchar();getchar();
                         break;
                      case 5:
                         if(G.vexnum!=0){
                             printf("��������Ҫ��õ�һ�ڽӵ�Ķ���Ĺؼ��֣�\n");
                             getchar();
                             scanf("%c",&u);
                             p=FirstAdjVex(G,u);
                             if(p==ERROR)
                                 printf("���㲻���ڣ�\n");
                             else
                                if(p==-2)
                                    printf("�ö���û���ڽӶ��㣡\n");
                             else
                                printf("�ö���ĵ�һ�ڽӶ����λ��Ϊ��%d\n",p);
                         }
                         else
                            printf("ͼ�����ڣ�\n");
                         getchar();getchar();
                         break;
                       case 6:
                         if(G.vexnum!=0){
                             printf("��������Ҫ�����һ�ڽӵ�Ķ���Ĺؼ��ּ��ڽӵ�λ��\n");
                             getchar();
                             scanf("%c %d",&u,&w);
                             p=NextAdjVex(G,u,w);
                             if(p==ERROR)
                                 printf("���㲻���ڻ򶥵�û��λ��Ϊ%d���ڽӵ㣡\n",w);
                             else
                                if(p==NULL)
                                    printf("λ��Ϊ%d�Ķ���Ϊ���һ���ڽӵ㣡\n",w);
                             else
                                printf("��һ�ڽӶ����λ��Ϊ��%d\n",p);
                         }
                         else
                            printf("ͼ�����ڣ�\n");
                         getchar();getchar();
                         break;
                       case 7:
                         if(G.vexnum!=0){
                             printf("��������Ҫ���붥��Ĺؼ��ּ�����ֵ��\n");
                             getchar();
                             scanf("%c %d",&(vex.key),&(vex.value));
                             p=InsertVex(&G,vex);
                             if(p==OK)
                                 printf("����ɹ���\n");
                             else
                                printf("����ʧ�ܣ�\n");
                         }
                         else
                            printf("ͼ�����ڣ�\n");
                         getchar();getchar();
                         break;
                       case 8:
                         if(G.vexnum!=0){
                             printf("��������Ҫɾ������Ĺؼ��֣�\n");
                             getchar();
                             scanf("%c",&u);
                             p=DeleteVex(&G,u);
                             if(p==OK)
                                 printf("ɾ���ɹ���\n");
                             else
                                printf("ɾ��ʧ�ܣ�\n");
                         }
                         else
                            printf("ͼ�����ڣ�\n");
                         getchar();getchar();
                         break;
                       case 9:
                         if(G.vexnum!=0){
                             printf("��������Ҫ���뻡�Ķ���Ĺؼ��֣�\n");
                             getchar();
                             scanf("%c%c",&u,&z);
                             p=InsertArc(&G,u,z);
                             if(p==OK)
                                 printf("����ɹ���\n");
                             else
                                printf("����ʧ�ܣ�\n");
                         }
                         else
                            printf("ͼ�����ڣ�\n");
                         getchar();getchar();
                         break;
                       case 10:
                         if(G.vexnum!=0){
                             printf("��������Ҫɾ�����Ķ���Ĺؼ��֣�\n");
                             getchar();
                             scanf("%c%c",&u,&z);
                             p=DeleteArc(&G,u,z);
                             if(p==OK)
                                 printf("ɾ���ɹ���\n");
                             else
                                printf("ɾ��ʧ�ܣ�\n");
                         }
                         else
                            printf("ͼ�����ڣ�\n");
                         getchar();getchar();
                         break;
                       case 11:
                         if(G.vexnum!=0){
                             printf("�����������һ������Ĺؼ��֣�\n");
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
                            printf("ͼ�����ڣ�\n");
                         getchar();getchar();
                         break;
                       case 12:
                         if(G.vexnum!=0){
                             InitQueue(&Q);
                             printf("��ȱ�����\n");
                             BFSTraverse(G,Q);
                             for(i=0;i<G.vexnum;i++){
                                visited[i]=0;
                             }
                         }
                         else
                            printf("ͼ�����ڣ�\n");
                         getchar();getchar();
                         break;
                       case 13:
                         if(G.vexnum!=0){
                             if(Write(G)==OK)
                                printf("д��ɹ���\n");
                             else
                                printf("д��ʧ�ܣ�\n");
                         }
                         else
                            printf("ͼ�����ڣ�\n");
                         getchar();getchar();
                         break;
                       case 14:
                         if(Read(&G)==OK)
                            printf("д��ɹ���\n");
                         else
                            printf("д��ʧ�ܣ�\n");
                         getchar();getchar();
                         break;
                       case 0:
                         break;
                     }
                }//end of switch
            }
        }
    }//end of while
    printf("��ӭ�´���ʹ�ñ�ϵͳ��\n");
}//end of main()

status CreatGraph(Graph *G,char V[],char VR[][2]){
    int i,j,k;
    ArcNode *p;
    ArcNode *q;
    char u;
    k=0;
    int a[100][2]={0};
    for(i=0;i<(G->vexnum);i++){//���㹹��
	    G->vertices[i].key=V[i];
	    G->vertices[i].num=i;
        G->vertices[i].firstarc=NULL;
    }
    for(i=0;i<(G->arcnum);i++){//�ؼ���ת����λ��
        u=VR[i][0];
        a[i][0]=LocateVex(*G,u);
        u=VR[i][1];
        a[i][1]=LocateVex(*G,u);
    }
    /*for(i=0;i<(G->vexnum);i++){//β�巨 
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
    }*///�ڽӱ���
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
    for(i=0;i<G->vexnum;i++){//�������еĶ���
        if(G->vertices[i].firstarc){
        	if(DestoryList(G->vertices[i].firstarc)==OK);//���ٶ���Ļ�����
        else
            return ERROR;
		}
    }
    free(G->vertices);
    G->vexnum=0;//������Ϊ0
    G->arcnum=0;//�߻��߻���Ϊ0
    return OK;
}

status DestoryList(ArcNode *arc){
    ArcNode *p=arc;
    ArcNode *q;
    if(arc){
        for(;arc!=NULL;){//����������
            q=arc;
            arc=arc->nextarc;
            free(q);//�ͷ����Ա�ռ�
        }
        arc=NULL;
        return OK;
    }
    else
        return ERROR;
}

status LocateVex(Graph G,char u){
    int i;
    for(i=0;i<(G.vexnum);i++){//�������� 
        if(G.vertices[i].key==u){
            return G.vertices[i].num;
        }
    }
    return ERROR;
}

status Locatehao(Graph G,char u){//�ɹؼ��ֲ������
    int i;
    for(i=0;i<(G.vexnum);i++){
        if(G.vertices[i].key==u){
            return i;
        }
    }
    return ERROR;
}

status PutVex(Graph *G,char u,int value){//���㸳ֵ
    int p;
    p=LocateVex(*G,u);//���Ҷ���λ��
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
    if(p!=ERROR){//����v����
        if(G.vertices[p].firstarc)//�������ڽӵ�
            return G.vertices[p].firstarc->adjvex;//���ص�һ�ڽӶ����λ��
        else
            return -2;//�������ڽӵ�
    }
    else
        return ERROR;//����v������
}

status NextAdjVex(Graph G,char u,int w){
    int i;
    int t;
    ArcNode *p;
    t=Locatehao(G,u);
    if(t!=ERROR){//����v����
        p=G.vertices[t].firstarc;//pΪ��һ�ڽӵ�
        for(i=0;p!=NULL;i++){//����λ��Ϊw���ڽӵ�
            if(p->adjvex==w){
                if(p->nextarc)//p��Ϊ���һ���ڽӵ�
                    return p->nextarc->adjvex;
                else
                    return NULL;
            }
            p=p->nextarc;
        }
        return ERROR;//û��λ��Ϊw���ڽӵ�
    }
    else
        return ERROR;
}

status InsertVex(Graph *G,VNode vex){//���붥�� 
    G->vertices[G->vexnum].key=vex.key;
    G->vertices[G->vexnum].value=vex.value;
    G->vertices[G->vexnum].firstarc=NULL;
    G->vertices[G->vexnum].num=G->vexnum;
    G->vexnum=G->vexnum+1;//���������� 
    return OK;
}

status DeleteVex(Graph *G,char u){//ɾ������ 
    int i,v;
    ArcNode *p;
    ArcNode *q;
    v=LocateVex(*G,u);
    if(v!=ERROR){
        for(i=0;i<G->vexnum;i++){//ɾ�����иö���Ļ� 
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
        for(i=v;i<G->vexnum;i++){//����v����Ķ���ǰ��
            G->vertices[i]=G->vertices[i+1];
        }
        G->vexnum--;
        return OK;
    }
    else
        return ERROR;
}

status InsertArc(Graph *G,char u,char z){//���뻡 
    int x,y;
    ArcNode *p;
    x=Locatehao(*G,u);
    y=LocateVex(*G,z);
    p=(ArcNode*)malloc(sizeof(ArcNode));
    if((x!=ERROR)&&(y!=ERROR)){//������� 
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
    G->arcnum++;//���������� 
    return OK;
}

status DeleteArc(Graph *G,char u,char z){//ɾ���� 
    int x,y;
    ArcNode *p;
    ArcNode *q;
    x=Locatehao(*G,u);
    y=LocateVex(*G,z);
    if((x!=ERROR)&&(y!=ERROR)){//�ж϶����Ƿ���� 
        p=G->vertices[x].firstarc;
        q=p->nextarc;
        if((p!=NULL)&&(p->nextarc!=NULL)){//�����ָ���ʹ�� 
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

status DFSTraverse(Graph G,char u){//������ȱ��� 
	int v;
	char z;
	ArcNode *p;
	v=Locatehao(G,u);
	if(visited[v]==0){
		printf("%c %d\n", G.vertices[v].key,G.vertices[v].value);
		visited[v]=1;//����ѷ���
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

char Locatekey(Graph G,int v){//��λ���ҹؼ���
    int i;
    for(i=0;i<(G.vexnum);i++){//���㹹��
        if(G.vertices[i].num==v){
            return G.vertices[i].key;
        }
    }
    return ERROR;
}

status Locatekey2(Graph G,int v){//��λ�������
    int i;
    for(i=0;i<(G.vexnum);i++){//���㹹��
        if(G.vertices[i].num==v){
            return i;
        }
    }
    return ERROR;
}

status BFSTraverse(Graph G, LinkQueue Q){//������ȱ��� 
	int v,u,i,num;
	char k;
	ArcNode *temp;
	for(v=0;v<G.vexnum;v++)
		visited[v]=0;
	for(v=0;v<G.vexnum;v++){
		if(!visited[v]){
			visited[v]=1;
			printf("%c %d\n", G.vertices[v].key,G.vertices[v].value);
            num=LocateVex(G,G.vertices[v].key);//λ��
			EnQueue(&Q,num);
			while(!QueueEmpty(Q)){
				DeQueue(&Q,&u);
				i=Locatekey2(G,u);//��λ�������
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

status InitQueue(LinkQueue *Q){//����һ�յĶ���Q
	Q->front=Q->rear=(QueuePtr)malloc(sizeof(QNode));
	if (!Q->front)
		exit(OVERFLOW);
	Q->front->next=NULL;
	return OK;
}

status QueueEmpty(LinkQueue Q){//��QΪ��,����TRUE,�����򷵻�FALSE
	if(Q.front==Q.rear)
		return TRUE;
	else
		return FALSE;
}

status EnQueue(LinkQueue *Q,ElemType e){//����Ԫ��eΪQ���µĶ�βԪ��
	QueuePtr p=(QueuePtr)malloc(sizeof(QNode));
	if (!p)//�洢����ʧ��
		exit(OVERFLOW);
	p->data=e;
	p->next=NULL;
	Q->rear->next=p;
	Q->rear=p;
	return OK;
}

status DeQueue(LinkQueue *Q,ElemType *e){//�����в���,ɾ��Q�Ķ�ͷԪ��,��e������ֵ,������OK,���򷵻�ERROR
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

status Write(Graph G){//д���ļ�
    FILE  *fp=NULL;
    char filename[30];
    printf("input file name: ");
    scanf("%s",filename);
    if ((fp=fopen(filename,"wb"))==NULL){
        printf("File open error\n ");
        return FALSE;
    }
    //д�ļ��ķ���
    int i;
    int j;
    ArcNode *p;
    fwrite(&G.vexnum,sizeof(int),1,fp);//д��ͼ����Ϣ 
    fwrite(&G.arcnum,sizeof(int),1,fp);
    for(i=0;i<G.vexnum;i++){//д�붥����Ϣ 
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

status Read(Graph *G){//��ȡ�ļ�
    FILE  *fp;
    char filename[30];
    printf("input file name: ");
    scanf("%s",filename);
    if ((fp=fopen(filename,"rb"))==NULL){
        printf("File open error\n ");
        return FALSE;
    }
    //���ļ��ķ���
    int i=0;
    int a=-1;
    int j;
    ArcNode *p;
    ArcNode *q;
    fread(&G->vexnum,sizeof(int),1,fp);
    fread(&G->arcnum,sizeof(int),1,fp);
    for(i=0;i<G->vexnum;i++){//���춥�� 
        fread(&G->vertices[i].key,sizeof(char),1,fp);
        fread(&G->vertices[i].value,sizeof(int),1,fp);
        fread(&G->vertices[i].num,sizeof(int),1,fp);
    }
    while(fread(&a,sizeof(int),1,fp)){//������ȡ�������ڽӱ�β�巨 
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

