#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

/*----------Ԥ����--------*/
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASTABLE -1
#define OVERFLOW -2
#define NO -1

typedef int status;
typedef int ElemType; //����Ԫ�����Ͷ���

typedef struct LNode{  //��ʽ����ʽ�ṹ���Ķ���
	ElemType data;
	struct LNode *next;
}LinkList;

/*-----page 19 on textbook ---------*/
status InitList(LinkList **L);//����
status DestroyList(LinkList **L);//����
status ClearList(LinkList *L);//���
status ListEmpty(LinkList *L);//�жϿձ�
status ListLength(LinkList *L);//���
status GetElem(LinkList *L,int i,ElemType *e);//���Ԫ��
int LocateElem(LinkList *L,ElemType e); //����Ԫ��
status PriorElem(LinkList *L,ElemType cur,ElemType *pre_e);//���ǰ��
status NextElem(LinkList *L,ElemType cur,ElemType *next_e);//��ú���
status ListInsert(LinkList *L,int i,ElemType e);//����
status ListDelete(LinkList *L,int i,ElemType *e);//ɾ��
status ListTrabverse(LinkList *L);  //����
status Wirte(LinkList *L);//д���ļ�
status Read(LinkList **L);//��ȡ�ļ�

/*--------------------------------------------*/
int main(void){
    LinkList *M[100];  LinkList *L;//�����������
    int t,i;
    ElemType p,cur;
    ElemType *pre_e,*next_e,*e;
    t=1;
    while(t){
        int op=1;
        printf("  ��������ĸ����Ա���в�����1-99��������0�˳���\n");
        scanf("%d",&t);//������Ա��ʵ��
        if(t==0)
            break;//0ʱ�˳�
        else {
            if(t>99||t<0){
                printf("ѡ��ʧ�ܣ�\n");
                getchar();
            }
            else {
                M[t]=NULL;
                L=M[t];
                while(op){
                    system("cls");	//�˵�Ŀ¼;
                    printf("  Menu for Linear Table On Sequence Structure \n");
                    printf("-----------------------------------------------\n");
                    printf("   1. InitList        8. PriorElem \n");
                    printf("   2. DestroyList     9. NextElem\n");
                    printf("   3. ClearList      10. ListInsert\n");
                    printf("   4. ListEmpty      11. ListDelete\n");
                    printf("   5. ListLength     12. ListTrabverse\n");
                    printf("   6. GetElem        13. Write\n");
                    printf("   7. LocateElem     14. Read\n");
                    printf("   0. Exit\n");
                    printf("-----------------------------------------------\n");
                    printf("   ��ѡ����Ĳ���[0~14]:\n");
                    scanf("%d",&op);
                    switch(op){//����switchѡ�� 
                       case 1:
                         if(InitList(&L)==OK)
                            printf("���Ա����ɹ���\n");
                         else
                            printf("���Ա���ʧ�ܣ�\n");
                         getchar();getchar();
                         break;
                       case 2:
                         if(DestroyList(&L)==OK)
                            printf("���Ա����ٳɹ���\n");
                         else
                            printf("���Ա�����ʧ�ܣ�\n");
                         getchar();getchar();
                         break;
                       case 3:
                         if(L!=NULL){
                            ClearList(L);
                            printf("������Ա�\n");
                         }
                         else
                            printf("���Ա����ڣ�\n");
                         getchar();getchar();
                         break;
                       case 4:
                         if(L!=NULL){
                             if(ListEmpty(L)==TRUE)
                                printf("���Ա�Ϊ�գ�\n");
                             else
                                printf("���Ա�Ϊ�գ�\n");
                         }
                         else
                            printf("���Ա����ڣ�\n");
                         getchar();getchar();
                         break;
                       case 5:
                         if(L!=NULL){
                             i=ListLength(L);
                             printf("���Ա�ĳ���Ϊ%d��\n",i);
                         }
                         else
                            printf("���Ա����ڣ�\n");
                         getchar();getchar();
                         break;
                       case 6:
                         if(L!=NULL){
                             printf("��������Ҫ���Ԫ�ص�λ�ã�\n");
                             scanf("%d",&i);
                             if(GetElem(L,i,&e)!=ERROR){
                                printf("��%d��Ԫ��Ϊ%d��\n",i,e);
                             }
                             else
                                printf("��λ�ò�����\n");
                         }
                         else
                            printf("���Ա����ڣ�\n");
                         getchar();getchar();
                         break;
                       case 7:
                         if(L!=NULL){
                             printf("��������Ҫ���ҵ�Ԫ�أ�\n");
                             scanf("%d",&p);
                             if(LocateElem(L,p))
                                printf("��%d��Ԫ�����Ԫ����ͬ\n",LocateElem(L,p));
                             else
                                printf("��������ͬ��Ԫ��\n");
                         }
                         else
                            printf("���Ա����ڣ�\n");
                         getchar();getchar();
                         break;
                       case 8:
                         if(L!=NULL){
                             printf("��������Ҫ�����ǰ����Ԫ�أ�\n");
                             scanf("%d",&cur);
                             if(PriorElem(L,cur,&pre_e))
                                printf("��Ԫ�ص�ǰ��Ϊ%d",pre_e);
                             else
                                printf("����ʧ�ܣ�\n");
                         }
                         else
                            printf("���Ա����ڣ�\n");
                         getchar();getchar();
                         break;
                       case 9:
                         if(L!=NULL){
                             printf("��������Ҫ������̵�Ԫ�أ�\n");
                             scanf("%d",&cur);
                             if(NextElem(L,cur,&next_e))
                                printf("��Ԫ�صĺ��Ϊ%d",next_e);
                             else
                                printf("����ʧ�ܣ�\n");
                         }
                         else
                            printf("���Ա����ڣ�\n");
                         getchar();getchar();
                         break;
                       case 10:
                         if(L!=NULL){
                             printf("���������룺�ڵ�_��λ��֮ǰ����Ԫ��_\n");
                             scanf("%d",&i);
                             getchar();
                             scanf("%d",&p);
                             if(ListInsert(L,i,p)==OK)
                                printf("����ɹ���\n");
                             else
                                printf("����ʧ�ܣ�\n");
                         }
                         else
                            printf("���Ա����ڣ�\n");
                         getchar();getchar();
                         break;
                       case 11:
                         if(L!=NULL){
                             printf("���������룺ɾ����_��λ�õ�Ԫ��\n");
                             scanf("%d",&i);
                             if(ListDelete(L,i,&e)==OK)
                             printf("ɾ���ɹ���\n");
                             else
                                printf("ɾ��ʧ�ܣ�\n");
                         }
                         else
                            printf("���Ա����ڣ�\n");
                         getchar();getchar();
                         break;
                       case 12:
                         if(L!=NULL){
                             if(ListTrabverse(L)==0)
                                printf("���Ա��ǿձ�\n");
                         }
                         else
                            printf("���Ա����ڣ�\n");
                         getchar();getchar();
                         break;
                       case 13:
                         if(L!=NULL){
                             if(Wirte(L)==OK)
                                printf("д��ɹ���\n");
                             else
                                printf("д��ʧ�ܣ�\n");
                         }
                         else
                            printf("���Ա����ڣ�\n");
                         getchar();getchar();
                         break;
                       case 14:
                         if(L!=NULL){
                             if(Read(&L)==OK)
                                printf("��ȡ�ɹ���\n");
                             else
                                printf("��ȡʧ�ܣ�\n");
                         }
                         else
                            printf("���Ա����ڣ�\n");
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

status InitList(LinkList **L){//����һ�����Ա�L
	*L = (LinkList*)malloc(sizeof(LinkList)); //����һ��ͷ���
    LinkList *p=*L;
    p->next=NULL;
	return OK;
}

status DestroyList(LinkList **L){//�������Ա�L
    LinkList *p=*L;
    LinkList *q;
    if(p){
        for(;p!=NULL;){//����������
            q=p;
            p=p->next;
            free(q);//�ͷ����Ա�ռ�
        }
        p=NULL;
        *L=p;
        return OK;
    }
    else
        return ERROR;
}

status ClearList(LinkList *L){//��L��Ϊ�ձ�
    LinkList *p;
    LinkList *q;
    if(L!=NULL){
        for(p=L->next;p!=NULL;){//����������
            q=p;
            p=p->next;
            free(q);//�ͷ����Ա�ռ�
        }
        L->next=NULL;//��ͷ�ڵ���Ϊ��
        return OK;
    }
    else
        printf("���Ա����ڣ�\n");
        return NO;
}

status ListEmpty(LinkList *L){//�ж�L�Ƿ�Ϊ��
    if(L->next==NULL)
        return TRUE;
    else
        return FALSE;
}

status ListLength(LinkList *L){//����L��Ԫ�ظ���
    int i;
    LinkList *p=L->next;
    for(i=0;p!=NULL;i++)//��������������
        p=p->next;
    return i;
}

status GetElem(LinkList *L,int i,ElemType *e){//��e���ص�i��Ԫ�ص�ֵ
    int j;
    if(i<1||i>ListLength(L))
        return ERROR;//��ʽ���Ա�Ϊ�ջ�i��ֵ���Ϸ�
    LinkList *p=L->next;//pָ���׽��
    for(j=1;j<i;j++)//��������iλ
        p=p->next;
    *e=p->data;
    return OK;
}

int LocateElem(LinkList *L,ElemType e){//����L����e��ȵ�Ԫ�ص�λ���޷���0
    int i;
    LinkList *p=L->next;//pָ���׽��
    for(i=1;p!=NULL;i++){//���������������Ƿ�����ͬԪ��
        if(p->data==e)
            return i;
        else
            p=p->next;
    }
    return ERROR;
}

status PriorElem(LinkList *L,ElemType cur,ElemType *pre_e){//����curԪ�ص�ǰ��
    int i;
    LinkList *p=L;//pָ��ͷ���
    LinkList *q=p->next;//qָ���׽��
    if(LocateElem(L,cur)==1||LocateElem(L,cur)==ERROR)//���������������Ƿ�����ͬԪ�ز��ж�λ�úϷ�
        return ERROR;
    else{
        for(;q!=NULL;){//��������ͬԪ�ص�ǰһ�����
            if(q->data==cur){
                *pre_e=p->data;
                return OK;
            }
            else{
                p=q;
                q=q->next;
            }
        }
        return ERROR;
    }
}

status NextElem(LinkList *L,ElemType cur,ElemType *next_e){//����curԪ�صĺ��
    int i;
    LinkList *p=L->next;//pָ���׽��
    if(LocateElem(L,cur)==ListLength(L)||LocateElem(L,cur)==ERROR)//���������������Ƿ�����ͬԪ�ز��ж�λ�úϷ�
        return ERROR;
    else{
        for(;p!=NULL;){//��������ͬԪ�ص�λ��
            if(p->data==cur){
                *next_e=p->next->data;
                return OK;
            }
            else
                p=p->next;
        }
        return ERROR;
    }
}

status ListInsert(LinkList *L,int i,ElemType e){//����ʽ���Ա��е�i��Ԫ��֮ǰ�����µ�Ԫ��e
    int j;
    LinkList *t;//�����µĽ�㲢����ռ�
    t=(LinkList*)malloc(sizeof(LinkList));
    t->data=e;//���µ�Ԫ��ֵ�����½��
    LinkList *p=L;
    LinkList *q=L->next;
    if(i>ListLength(L)+1||i<1)//�ж�i�Ƿ�Ϸ�
        return ERROR;
    else{
        for(j=1;j<i;j++){//������i-1λ
            p=q;
            q=q->next;
        }
        t->next=p->next;
        p->next=t;
    }
    return OK;
}

status ListDelete(LinkList *L,int i,ElemType *e){//����ʽ���Ա���ɾ����i��Ԫ�أ�����e������ֵ
    int j;
    LinkList *p=L;
    LinkList *q=L->next;
    if(i>ListLength(L)||i<1)//�ж�i�Ƿ�Ϸ�
        return ERROR;
    else{
        for(j=1;j<i;j++){//������i-1λ
            p=q;
            q=q->next;
        }
        p->next=q->next;
        free(q);
    }
    return OK;
}
status ListTrabverse(LinkList *L){//������
    LinkList *p=L->next;//pָ���׽��
    printf("\n-----------all elements -----------------------\n");
    for(;p!=NULL;){//����������
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n------------------ end ------------------------\n");
    return OK;
}

status Wirte(LinkList *L) {
    FILE  *fp=NULL;
    char filename[30];
    LinkList *p=L->next;
    printf("input file name: ");
    scanf("%s",filename);
    if ((fp=fopen(filename,"wb"))==NULL){
        printf("File open error\n ");
        return FALSE;
    }
    //д�ļ��ķ���
    for(;p!=NULL;){//����������,д���ļ�
        fwrite(&(p->data),sizeof(ElemType),1,fp);
        p=p->next;
    }
    fclose(fp);
    return OK;
}

status Read(LinkList **L) {
    FILE  *fp;
    char filename[30];
    printf("input file name: ");
    scanf("%s",filename);
    //���ļ��ķ���
    if ((fp=fopen(filename,"rb"))==NULL){
        printf("File open error\n ");
        return FALSE;
    }
    LinkList *t=*L;
    LinkList *p,*q;
    p=(LinkList*)malloc(sizeof(LinkList));
    q=(LinkList*)malloc(sizeof(LinkList));//Ϊָ�����ռ�
    t->next=q;//qΪ�׽��
    while(fread(&(q->data),sizeof(ElemType),1,fp)){//���ļ��ж�ȡ���ݵ���������
        p->next=q;
        q->next=NULL;
        p=p->next;
        q=(LinkList*)malloc(sizeof(LinkList));
    }//������ļ��������ȡ����Ԫ�ػָ���ʽ��
	free(q);//�ͷ�ָ��q
	fclose(fp);
    return OK;
}
